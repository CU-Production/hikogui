// Copyright Take Vos 2021-2022.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)

#include "hikogui/GUI/gui_system.hpp"
#include "hikogui/widgets/radio_button_widget.hpp"
#include "hikogui/crt.hpp"
#include "hikogui/loop.hpp"

using namespace hi;

int hi_main(int argc, char *argv[])
{
    auto gui = gui_system::make_unique();
    auto window = gui->make_window(tr("Radio button example"));
    window->content().make_widget<label_widget>("A1", tr("radio buttons:"));

    /// [Create three radio buttons]
    observer<int> value = 0;

    window->content().make_widget<radio_button_widget>("B1", tr("one"), value, 1);
    window->content().make_widget<radio_button_widget>("B2", tr("two"), value, 2);
    window->content().make_widget<radio_button_widget>("B3", tr("three"), value, 3);
    /// [Create three radio buttons]

    auto close_cb = window->closing.subscribe(hi::callback_flags::main, [&] {
        window.reset();
    });
    return loop::main().resume();
}
