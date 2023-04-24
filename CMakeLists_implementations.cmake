
target_sources(hikogui PRIVATE
    ${HIKOGUI_SOURCE_DIR}/concurrency/dead_lock_detector_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/concurrency/thread_impl.cpp
    $<$<PLATFORM_ID:Darwin>:${HIKOGUI_SOURCE_DIR}/concurrency/thread_macos_impl.cpp>
    $<$<PLATFORM_ID:Windows>:${HIKOGUI_SOURCE_DIR}/concurrency/thread_win32_impl.cpp>
    ${HIKOGUI_SOURCE_DIR}/font/font_book_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/font/font_impl.cpp
    #${HIKOGUI_SOURCE_DIR}/font/true_type_font_coverage_impl.cpp
    #${HIKOGUI_SOURCE_DIR}/font/true_type_font_GSUB_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/font/true_type_font_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/geometry/axis_aligned_rectangle_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GFX/gfx_device_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GFX/gfx_device_vulkan_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GFX/gfx_surface_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GFX/gfx_surface_vulkan_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GFX/gfx_system_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GFX/gfx_system_vulkan_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GFX/gfx_system_vulkan_win32_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GFX/paged_image_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GFX/pipeline_alpha_device_shared_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GFX/pipeline_alpha_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GFX/pipeline_box_device_shared_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GFX/pipeline_box_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GFX/pipeline_image_device_shared_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GFX/pipeline_image_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GFX/pipeline_image_texture_map_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GFX/pipeline_SDF_device_shared_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GFX/pipeline_SDF_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GFX/pipeline_SDF_texture_map_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GFX/pipeline_tone_mapper_device_shared_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GFX/pipeline_tone_mapper_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GFX/pipeline_vulkan_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GFX/RenderDoc_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GFX/VulkanMemoryAllocator_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GUI/gui_system_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GUI/gui_system_win32_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/GUI/gui_window_impl.cpp
    $<$<PLATFORM_ID:Windows>:${HIKOGUI_SOURCE_DIR}/GUI/gui_window_win32_impl.cpp>
    ${HIKOGUI_SOURCE_DIR}/GUI/keyboard_bindings_impl.cpp
    $<$<PLATFORM_ID:Windows>:${HIKOGUI_SOURCE_DIR}/GUI/keyboard_virtual_key_win32_impl.cpp>
    ${HIKOGUI_SOURCE_DIR}/GUI/widget_draw_context_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/i18n/iso_3166_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/i18n/iso_15924_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/i18n/language_tag_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/l10n/po_parser_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/l10n/translation_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/text/text_shaper_char_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/text/text_shaper_impl.cpp
    ${HIKOGUI_SOURCE_DIR}/text/text_shaper_line_impl.cpp
    $<$<PLATFORM_ID:Windows>:${HIKOGUI_SOURCE_DIR}/utility/debugger_win32_impl.cpp>
    $<$<PLATFORM_ID:Windows>:${HIKOGUI_SOURCE_DIR}/utility/exception_win32_impl.cpp>
)
