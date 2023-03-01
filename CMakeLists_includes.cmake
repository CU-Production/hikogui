
target_sources(hikogui PUBLIC FILE_SET hikogui_include_files TYPE HEADERS BASE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/src/" FILES
    ${HIKOGUI_SOURCE_DIR}/char_maps/ascii.hpp
    ${HIKOGUI_SOURCE_DIR}/char_maps/char_converter.hpp
    ${HIKOGUI_SOURCE_DIR}/char_maps/cp_1252.hpp
    ${HIKOGUI_SOURCE_DIR}/char_maps/iso_8859_1.hpp
    ${HIKOGUI_SOURCE_DIR}/char_maps/module.hpp
    ${HIKOGUI_SOURCE_DIR}/char_maps/to_string.hpp
    ${HIKOGUI_SOURCE_DIR}/char_maps/utf_8.hpp
    ${HIKOGUI_SOURCE_DIR}/char_maps/utf_16.hpp
    ${HIKOGUI_SOURCE_DIR}/char_maps/utf_32.hpp
    ${HIKOGUI_SOURCE_DIR}/color/color.hpp
    ${HIKOGUI_SOURCE_DIR}/color/color_space.hpp
    ${HIKOGUI_SOURCE_DIR}/color/module.hpp
    ${HIKOGUI_SOURCE_DIR}/color/quad_color.hpp
    ${HIKOGUI_SOURCE_DIR}/color/Rec2020.hpp
    ${HIKOGUI_SOURCE_DIR}/color/Rec2100.hpp
    ${HIKOGUI_SOURCE_DIR}/color/semantic_color.hpp
    ${HIKOGUI_SOURCE_DIR}/color/sRGB.hpp
    ${HIKOGUI_SOURCE_DIR}/concurrency/dead_lock_detector.hpp
    ${HIKOGUI_SOURCE_DIR}/concurrency/global_state.hpp
    ${HIKOGUI_SOURCE_DIR}/concurrency/rcu.hpp
    ${HIKOGUI_SOURCE_DIR}/concurrency/module.hpp
    ${HIKOGUI_SOURCE_DIR}/concurrency/unfair_mutex.hpp
    ${HIKOGUI_SOURCE_DIR}/concurrency/unfair_recursive_mutex.hpp
    ${HIKOGUI_SOURCE_DIR}/concurrency/subsystem.hpp
    ${HIKOGUI_SOURCE_DIR}/concurrency/thread.hpp
    ${HIKOGUI_SOURCE_DIR}/concurrency/wfree_idle_count.hpp
    ${HIKOGUI_SOURCE_DIR}/font/elusive_icon.hpp
    ${HIKOGUI_SOURCE_DIR}/font/font.hpp
    ${HIKOGUI_SOURCE_DIR}/font/font_book.hpp
    ${HIKOGUI_SOURCE_DIR}/font/font_char_map.hpp
    ${HIKOGUI_SOURCE_DIR}/font/font_family_id.hpp
    ${HIKOGUI_SOURCE_DIR}/font/font_metrics.hpp
    ${HIKOGUI_SOURCE_DIR}/font/font_variant.hpp
    ${HIKOGUI_SOURCE_DIR}/font/font_weight.hpp
    ${HIKOGUI_SOURCE_DIR}/font/glyph_atlas_info.hpp
    ${HIKOGUI_SOURCE_DIR}/font/glyph_id.hpp
    ${HIKOGUI_SOURCE_DIR}/font/glyph_metrics.hpp
    ${HIKOGUI_SOURCE_DIR}/font/hikogui_icon.hpp
    ${HIKOGUI_SOURCE_DIR}/font/otype_cmap.hpp
    ${HIKOGUI_SOURCE_DIR}/font/otype_glyf.hpp
    ${HIKOGUI_SOURCE_DIR}/font/otype_head.hpp
    ${HIKOGUI_SOURCE_DIR}/font/otype_hhea.hpp
    ${HIKOGUI_SOURCE_DIR}/font/otype_hmtx.hpp
    ${HIKOGUI_SOURCE_DIR}/font/otype_kern.hpp
    ${HIKOGUI_SOURCE_DIR}/font/otype_loca.hpp
    ${HIKOGUI_SOURCE_DIR}/font/otype_maxp.hpp
    ${HIKOGUI_SOURCE_DIR}/font/otype_name.hpp
    ${HIKOGUI_SOURCE_DIR}/font/otype_os2.hpp
    ${HIKOGUI_SOURCE_DIR}/font/otype_sfnt.hpp
    ${HIKOGUI_SOURCE_DIR}/font/otype_utilities.hpp
    ${HIKOGUI_SOURCE_DIR}/font/true_type_font.hpp
    ${HIKOGUI_SOURCE_DIR}/geometry/alignment.hpp
    ${HIKOGUI_SOURCE_DIR}/geometry/axis.hpp
    ${HIKOGUI_SOURCE_DIR}/geometry/axis_aligned_rectangle.hpp
    ${HIKOGUI_SOURCE_DIR}/geometry/circle.hpp
    ${HIKOGUI_SOURCE_DIR}/geometry/corner_radii.hpp
    ${HIKOGUI_SOURCE_DIR}/geometry/extent.hpp
    ${HIKOGUI_SOURCE_DIR}/geometry/identity.hpp
    ${HIKOGUI_SOURCE_DIR}/geometry/line_end_cap.hpp
    ${HIKOGUI_SOURCE_DIR}/geometry/line_join_style.hpp
    ${HIKOGUI_SOURCE_DIR}/geometry/line_segment.hpp
    ${HIKOGUI_SOURCE_DIR}/geometry/lookat.hpp
    ${HIKOGUI_SOURCE_DIR}/geometry/margins.hpp
    ${HIKOGUI_SOURCE_DIR}/geometry/matrix.hpp
    ${HIKOGUI_SOURCE_DIR}/geometry/module.hpp
    ${HIKOGUI_SOURCE_DIR}/geometry/perspective.hpp
    ${HIKOGUI_SOURCE_DIR}/geometry/point.hpp
    ${HIKOGUI_SOURCE_DIR}/geometry/quad.hpp
    ${HIKOGUI_SOURCE_DIR}/geometry/rectangle.hpp
    ${HIKOGUI_SOURCE_DIR}/geometry/rotate.hpp
    ${HIKOGUI_SOURCE_DIR}/geometry/scale.hpp
    ${HIKOGUI_SOURCE_DIR}/geometry/transform.hpp
    ${HIKOGUI_SOURCE_DIR}/geometry/translate.hpp
    ${HIKOGUI_SOURCE_DIR}/geometry/vector.hpp
    ${HIKOGUI_SOURCE_DIR}/GUI/widget_draw_context.hpp
    ${HIKOGUI_SOURCE_DIR}/GUI/gui_event.hpp
    ${HIKOGUI_SOURCE_DIR}/GUI/gui_event_type.hpp
    ${HIKOGUI_SOURCE_DIR}/GUI/gui_event_variant.hpp
    ${HIKOGUI_SOURCE_DIR}/GUI/gui_system.hpp
    ${HIKOGUI_SOURCE_DIR}/GUI/gui_system_delegate.hpp
    $<$<PLATFORM_ID:Windows>:${HIKOGUI_SOURCE_DIR}/GUI/gui_system_win32.hpp>
    ${HIKOGUI_SOURCE_DIR}/GUI/gui_window.hpp
    ${HIKOGUI_SOURCE_DIR}/GUI/gui_window_size.hpp
    $<$<PLATFORM_ID:Windows>:${HIKOGUI_SOURCE_DIR}/GUI/gui_window_win32.hpp>
    ${HIKOGUI_SOURCE_DIR}/GUI/hitbox.hpp
    ${HIKOGUI_SOURCE_DIR}/GUI/keyboard_bindings.hpp
    ${HIKOGUI_SOURCE_DIR}/GUI/keyboard_focus_direction.hpp
    ${HIKOGUI_SOURCE_DIR}/GUI/keyboard_focus_group.hpp
    ${HIKOGUI_SOURCE_DIR}/GUI/keyboard_state.hpp
    ${HIKOGUI_SOURCE_DIR}/GUI/keyboard_virtual_key.hpp
    ${HIKOGUI_SOURCE_DIR}/GUI/module.hpp
    ${HIKOGUI_SOURCE_DIR}/GUI/mouse_buttons.hpp
    ${HIKOGUI_SOURCE_DIR}/GUI/mouse_cursor.hpp
    ${HIKOGUI_SOURCE_DIR}/GUI/widget.hpp
    ${HIKOGUI_SOURCE_DIR}/GUI/widget_id.hpp
    ${HIKOGUI_SOURCE_DIR}/GUI/widget_layout.hpp
    ${HIKOGUI_SOURCE_DIR}/GUI/widget_mode.hpp
    ${HIKOGUI_SOURCE_DIR}/image/module.hpp
    ${HIKOGUI_SOURCE_DIR}/image/pixmap.hpp
    ${HIKOGUI_SOURCE_DIR}/image/pixmap_span.hpp
    ${HIKOGUI_SOURCE_DIR}/image/sdf_r8.hpp
    ${HIKOGUI_SOURCE_DIR}/image/sfloat_rg32.hpp
    ${HIKOGUI_SOURCE_DIR}/image/sfloat_rgb32.hpp
    ${HIKOGUI_SOURCE_DIR}/image/sfloat_rgba16.hpp
    ${HIKOGUI_SOURCE_DIR}/image/sfloat_rgba32.hpp
    ${HIKOGUI_SOURCE_DIR}/image/sint_abgr8_pack.hpp
    ${HIKOGUI_SOURCE_DIR}/image/snorm_r8.hpp
    ${HIKOGUI_SOURCE_DIR}/image/srgb_abgr8_pack.hpp
    ${HIKOGUI_SOURCE_DIR}/image/uint_abgr8_pack.hpp
    ${HIKOGUI_SOURCE_DIR}/image/unorm_a2bgr10_pack.hpp
    ${HIKOGUI_SOURCE_DIR}/i18n/module.hpp
    ${HIKOGUI_SOURCE_DIR}/i18n/iso_639.hpp
    ${HIKOGUI_SOURCE_DIR}/i18n/iso_3166.hpp
    ${HIKOGUI_SOURCE_DIR}/i18n/iso_15924.hpp
    ${HIKOGUI_SOURCE_DIR}/i18n/language_tag.hpp
    ${HIKOGUI_SOURCE_DIR}/l10n/module.hpp
    ${HIKOGUI_SOURCE_DIR}/l10n/language.hpp
    ${HIKOGUI_SOURCE_DIR}/l10n/po_parser.hpp
    ${HIKOGUI_SOURCE_DIR}/l10n/translate.hpp
    ${HIKOGUI_SOURCE_DIR}/l10n/translation.hpp
    ${HIKOGUI_SOURCE_DIR}/SIMD/float16_sse4_1.hpp
    ${HIKOGUI_SOURCE_DIR}/SIMD/module.hpp
    ${HIKOGUI_SOURCE_DIR}/SIMD/native_f16x8_sse2.hpp
    ${HIKOGUI_SOURCE_DIR}/SIMD/native_f32x4_sse.hpp
    ${HIKOGUI_SOURCE_DIR}/SIMD/native_f64x4_avx.hpp
    ${HIKOGUI_SOURCE_DIR}/SIMD/native_i16x8_sse2.hpp
    ${HIKOGUI_SOURCE_DIR}/SIMD/native_i32x4_sse2.hpp
    ${HIKOGUI_SOURCE_DIR}/SIMD/native_i64x4_avx2.hpp
    ${HIKOGUI_SOURCE_DIR}/SIMD/native_i8x16_sse2.hpp
    ${HIKOGUI_SOURCE_DIR}/SIMD/native_simd_conversions_x86.hpp
    ${HIKOGUI_SOURCE_DIR}/SIMD/native_simd_utility.hpp
    ${HIKOGUI_SOURCE_DIR}/SIMD/native_u32x4_sse2.hpp
    ${HIKOGUI_SOURCE_DIR}/SIMD/simd.hpp
    ${HIKOGUI_SOURCE_DIR}/text/character.hpp
    ${HIKOGUI_SOURCE_DIR}/text/text.hpp
    ${HIKOGUI_SOURCE_DIR}/theme/theme_book.hpp
    ${HIKOGUI_SOURCE_DIR}/theme/theme_file.hpp
    ${HIKOGUI_SOURCE_DIR}/theme/theme_mode.hpp
    ${HIKOGUI_SOURCE_DIR}/theme/theme_value.hpp
    ${HIKOGUI_SOURCE_DIR}/utility/architecture.hpp
    ${HIKOGUI_SOURCE_DIR}/utility/assert.hpp
    ${HIKOGUI_SOURCE_DIR}/utility/cast.hpp
    ${HIKOGUI_SOURCE_DIR}/utility/charconv.hpp
    ${HIKOGUI_SOURCE_DIR}/utility/compare.hpp
    ${HIKOGUI_SOURCE_DIR}/utility/concepts.hpp
    ${HIKOGUI_SOURCE_DIR}/utility/debugger.hpp
    ${HIKOGUI_SOURCE_DIR}/utility/debugger.hpp
    ${HIKOGUI_SOURCE_DIR}/utility/enum_metadata.hpp
    ${HIKOGUI_SOURCE_DIR}/utility/endian.hpp
    ${HIKOGUI_SOURCE_DIR}/utility/exception.hpp
    ${HIKOGUI_SOURCE_DIR}/utility/fixed_string.hpp
    ${HIKOGUI_SOURCE_DIR}/utility/float16.hpp
    ${HIKOGUI_SOURCE_DIR}/utility/hash.hpp
    ${HIKOGUI_SOURCE_DIR}/utility/math.hpp
    ${HIKOGUI_SOURCE_DIR}/utility/memory.hpp
    ${HIKOGUI_SOURCE_DIR}/utility/module.hpp
    ${HIKOGUI_SOURCE_DIR}/utility/numbers.hpp
    ${HIKOGUI_SOURCE_DIR}/utility/test.hpp
    ${HIKOGUI_SOURCE_DIR}/utility/type_traits.hpp
    ${HIKOGUI_SOURCE_DIR}/utility/utility.hpp
    $<$<PLATFORM_ID:Windows>:${HIKOGUI_SOURCE_DIR}/utility/win32_headers.hpp>
    ${HIKOGUI_SOURCE_DIR}/widgets/abstract_button_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/audio_device_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/button_delegate.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/checkbox_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/grid_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/icon_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/label_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/menu_button_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/module.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/momentary_button_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/overlay_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/radio_button_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/row_column_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/scroll_aperture_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/scroll_bar_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/scroll_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/selection_delegate.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/selection_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/spacer_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/system_menu_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/tab_delegate.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/tab_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/text_delegate.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/text_field_delegate.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/text_field_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/text_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/toggle_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/toolbar_button_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/toolbar_tab_button_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/toolbar_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/window_traffic_lights_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/widgets/window_widget.hpp
    ${HIKOGUI_SOURCE_DIR}/module.hpp
    ${HIKOGUI_SOURCE_DIR}/terminate.hpp
)
