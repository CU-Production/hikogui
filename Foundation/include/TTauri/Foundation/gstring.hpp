// Copyright 2019 Pokitec
// All rights reserved.

#pragma once

#include "TTauri/Foundation/grapheme.hpp"
#include "TTauri/Foundation/strings.hpp"
#include <vector>

namespace TTauri {

struct gstring {
    std::vector<grapheme> graphemes;

    using const_iterator = std::vector<grapheme>::const_iterator;
    using value_type = grapheme;

    ssize_t size() const noexcept {
        return to_signed(graphemes.size());
    }

    grapheme const &at(ssize_t i) const {
        return graphemes.at(i);
    }

    grapheme &at(ssize_t i) {
        return graphemes.at(i);
    }

    auto begin() const noexcept {
        return graphemes.begin();
    }

    auto end() const noexcept {
        return graphemes.end();
    }

    gstring &operator+=(gstring const &rhs) noexcept {
        for (let &rhs_grapheme: rhs.graphemes) {
            graphemes.push_back(rhs_grapheme);
        }
        return *this;
    }

    gstring &operator+=(grapheme const &grapheme) noexcept {
        graphemes.push_back(grapheme);
        return *this;
    }
};

template<>
gstring translateString(std::u32string_view const inputString, TranslateStringOptions options) noexcept;

template<>
std::u32string translateString(const gstring& inputString, TranslateStringOptions options) noexcept;

}
