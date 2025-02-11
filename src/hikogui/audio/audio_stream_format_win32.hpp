// Copyright Take Vos 2021.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "audio_stream_format.hpp"
#include "speaker_mapping_win32.hpp"
#include "../macros.hpp"
#include "../win32_headers.hpp"

hi_export_module(hikogui.audio.audio_stream_format_win32);

hi_export namespace hi { inline namespace v1 {

hi_export [[nodiscard]] hi_inline bool win32_use_extensible(audio_stream_format x) noexcept{
    if (to_bool(x.speaker_mapping)) {
        // If we have an non-direct speaker mapping we MUST use extensible as it requires the
        // extra dwChannelMask field.
        return true;
    }

    return false;
}

hi_export [[nodiscard]] hi_inline WAVEFORMATEXTENSIBLE audio_stream_format_to_win32(audio_stream_format stream_format, bool extensible) noexcept{
    hi_axiom(stream_format.holds_invariant());
    hi_axiom(not win32_use_extensible(stream_format) or extensible);

    auto r = WAVEFORMATEXTENSIBLE{};

    if (extensible) {
        r.Format.wFormatTag = WAVE_FORMAT_EXTENSIBLE;
        // difference between sizeof(WAVEFORMATEXT) and sizeof(WAVEFORMATEXTENSIBLE).
        // But API documentation says it must be "22".
        r.Format.cbSize = 22;
    } else {
        r.Format.wFormatTag = stream_format.format.floating_point() ? WAVE_FORMAT_IEEE_FLOAT : WAVE_FORMAT_PCM;
        r.Format.cbSize = 0;
    }

    // These are the fields of WAVEFORMATEXT.
    r.Format.nChannels = narrow_cast<WORD>(stream_format.num_channels);
    r.Format.nSamplesPerSec = narrow_cast<DWORD>(stream_format.sample_rate);
    r.Format.nAvgBytesPerSec = narrow_cast<DWORD>(stream_format.sample_rate * stream_format.num_channels * stream_format.format.num_bytes());
    r.Format.nBlockAlign = narrow_cast<WORD>(stream_format.num_channels * stream_format.format.num_bytes());
    r.Format.wBitsPerSample = narrow_cast<WORD>(stream_format.format.num_bytes() * 8);

    // These are the fields of WAVEFORMATEXTENSIBLE which are ignored for WAVEFORMATEXT.
    r.Samples.wValidBitsPerSample = narrow_cast<WORD>(stream_format.format.num_bits());
    r.dwChannelMask = speaker_mapping_to_win32(stream_format.speaker_mapping);
    r.SubFormat = stream_format.format.floating_point() ? KSDATAFORMAT_SUBTYPE_IEEE_FLOAT : KSDATAFORMAT_SUBTYPE_PCM;
    return r;
}

hi_export [[nodiscard]] hi_inline audio_stream_format audio_stream_format_from_win32(WAVEFORMATEXTENSIBLE const& wave_format){
    auto r = audio_stream_format{};

    hi_check(wave_format.Format.wBitsPerSample % 8 == 0, "wBitsPerSample is not multiple of 8");
    hi_check(wave_format.Format.wBitsPerSample > 0, "wBitsPerSample is 0");
    hi_check(wave_format.Format.wBitsPerSample <= 32, "wBitsPerSample is more than 32");
    hi_check(wave_format.Samples.wValidBitsPerSample > 0, "wValidBitsPerSample is 0");
    hi_check(
        wave_format.Samples.wValidBitsPerSample <= wave_format.Format.wBitsPerSample, "wValidBitsPerSample > wBitsPerSample");
    hi_check(wave_format.Format.nSamplesPerSec > 0, "nSamplesPerSec is zero");
    hi_check(wave_format.Format.nSamplesPerSec <= std::numeric_limits<uint32_t>::max(), "nSamplesPerSec is to high");

    if (wave_format.SubFormat == KSDATAFORMAT_SUBTYPE_IEEE_FLOAT) {
        hi_check(wave_format.Format.wBitsPerSample == 32, "wBitsPerSample is not 32");
        r.format = pcm_format{true, std::endian::native, true, 4, 8, 23};

    } else if (wave_format.SubFormat == KSDATAFORMAT_SUBTYPE_PCM) {
        hilet num_bytes = narrow_cast<uint8_t>(wave_format.Format.wBitsPerSample / 8);
        hilet num_minor_bits = narrow_cast<uint8_t>(wave_format.Samples.wValidBitsPerSample - 1);
        r.format = pcm_format{false, std::endian::native, true, num_bytes, 0, num_minor_bits};
    } else {
        throw parse_error("Unknown SubFormat");
    }

    hi_check(wave_format.Format.nChannels > 0, "nChannels is zero");
    r.num_channels = wave_format.Format.nChannels;

    r.speaker_mapping = speaker_mapping_from_win32(wave_format.dwChannelMask);
    hi_check(popcount(r.speaker_mapping) == 0 or popcount(r.speaker_mapping) == r.num_channels, "nChannels is zero");

    r.sample_rate = narrow_cast<uint32_t>(wave_format.Format.nSamplesPerSec);
    return r;
}

hi_export [[nodiscard]] hi_inline audio_stream_format audio_stream_format_from_win32(WAVEFORMATEX const& wave_format){
    auto r = audio_stream_format{};
    hi_check(wave_format.wBitsPerSample > 0, "wBitsPerSample is zero");
    hi_check(wave_format.wBitsPerSample % 8 == 0, "wBitsPerSample is not multiple of 8");
    hi_check(wave_format.wBitsPerSample <= 32, "wBitsPerSample greater than 32");
    hi_check(wave_format.nSamplesPerSec > 0, "nSamplesPerSec is zero");
    hi_check(wave_format.nSamplesPerSec <= std::numeric_limits<uint32_t>::max(), "nSamplesPerSec is to high");
    hi_check(wave_format.nChannels > 0, "nChannels is zero");

    if (wave_format.wFormatTag == WAVE_FORMAT_EXTENSIBLE) {
        if (wave_format.cbSize < (sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX))) {
            throw parse_error(std::format("WAVEFORMATEXTENSIBLE has incorrect size {}", wave_format.cbSize));
        }
        return audio_stream_format_from_win32(*std::launder(reinterpret_cast<WAVEFORMATEXTENSIBLE const *>(&wave_format)));

    } else if (wave_format.wFormatTag == WAVE_FORMAT_PCM) {
        hi_check(wave_format.wBitsPerSample == 32, "wBitsPerSample is not 32");
        r.format = pcm_format{true, std::endian::native, true, 4, 8, 23};

    } else if (wave_format.wFormatTag == WAVE_FORMAT_IEEE_FLOAT) {
        hilet num_bytes = narrow_cast<uint8_t>(wave_format.wBitsPerSample / 8);
        hilet num_minor_bits = narrow_cast<uint8_t>(wave_format.wBitsPerSample);
        r.format = pcm_format{false, std::endian::native, true, num_bytes, 0, num_minor_bits};

    } else {
        throw parse_error(std::format("Unsupported wFormatTag {}", wave_format.wFormatTag));
    }

    r.sample_rate = narrow_cast<uint32_t>(wave_format.nSamplesPerSec);

    hi_check(wave_format.nChannels > 0, "nChannels is zero");
    r.num_channels = wave_format.nChannels;

    r.speaker_mapping = speaker_mapping::none;
    return r;
}

}} // namespace hi::inline v1
