/**
 * @file window_Windows.cpp
 * @author: Clare  email: 1090535708@qq.com
 * @date 2025-03-18
 * @copyright Copyright (c) 2025 by Clare, All Rights Reserved.
 */
#include "eg_pch.h"
#include "engine/platform/window_Windows.h"
namespace engine
{
    static bool s_GLFWInitialized = false;
    Window *Window::create(const WindowProps &props)
    {
        return new WindowsWindow(props);
    }
    WindowsWindow::WindowsWindow(const WindowProps &props)
    {
        init(props);
    }
    WindowsWindow::~WindowsWindow()
    {
        shutdown();
    }
    void WindowsWindow::init(const WindowProps &props)
    {
        m_Data.title = props.title;
        m_Data.width = props.width;
        m_Data.height = props.height;
        EG_CORE_INFO("Creating window {0} ({1}, {2})", props.title, props.width, props.height);

        if (!s_GLFWInitialized)
        {
            int success = glfwInit();
            EG_CORE_ASSERT(success, "Could not intialize GLFW!");
            s_GLFWInitialized = true;
        }
        m_Window = glfwCreateWindow(static_cast<int>(props.width),
                                    static_cast<int>(props.height),
                                    m_Data.title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        setVSync(true);
    }
    void WindowsWindow::shutdown()
    {
        glfwDestroyWindow(m_Window);
    }
    void WindowsWindow::onUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }
    void WindowsWindow::setVSync(bool enabled)
    {
        if (enabled)
        {
            glfwSwapInterval(1);
        }
        else
        {
            glfwSwapInterval(0);
        }
        m_Data.isVSync = enabled;
    }
    bool WindowsWindow::isVSync() const
    {
        return m_Data.isVSync;
    }
} // namespace engine
