/*
 * Copyright (c) 2021, Andreas Kling <kling@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "WindowStack.h"

namespace WindowServer {

WindowStack::WindowStack()
{
}

WindowStack::~WindowStack()
{
}

void WindowStack::add(Window& window)
{
    m_windows.append(window);
}

void WindowStack::remove(Window& window)
{
    m_windows.remove(window);
}

void WindowStack::move_to_front(Window& window)
{
    if (m_windows.last() != &window)
        window.invalidate();
    m_windows.remove(window);
    m_windows.append(window);
}

void WindowStack::set_highlight_window(Window* window)
{
    if (!window)
        m_highlight_window = nullptr;
    else
        m_highlight_window = window->make_weak_ptr<Window>();
}

}
