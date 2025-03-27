/**
 * @file window_Windows.cpp
 * @author: Clare  email: 1090535708@qq.com
 * @date 2025-03-18
 * @copyright Copyright (c) 2025 by Clare, All Rights Reserved.
 */
#include "eg_pch.h"
#include "engine/platform/window_Windows.h"
#include "engine/event/applicationEvent.h"
#include "engine/event/keyEvent.h"
#include "engine/event/mouseEvent.h"
namespace engine
{
    static bool s_GLFWInitialized = false;
    static void GLFWErrorCallback(int error, const char *description)
    {
        EG_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }
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
            glfwSetErrorCallback(GLFWErrorCallback);
            s_GLFWInitialized = true;
        }
        m_Window = glfwCreateWindow(static_cast<int>(props.width),
                                    static_cast<int>(props.height),
                                    m_Data.title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        setVSync(true);

        auto sizeCallback = [](GLFWwindow *window, int width, int height)
        {
            WindowData &data = *static_cast<WindowData *>(glfwGetWindowUserPointer(window));
            data.width = width;
            data.height = height;
            WindowResizeEvent event(width, height);
            data.eventCallback(event);
        };
        glfwSetWindowSizeCallback(m_Window, sizeCallback);

        auto closeCallback = [](GLFWwindow *window)
        {
            WindowData &data = *static_cast<WindowData *>(glfwGetWindowUserPointer(window));
            WindowCloseEvent event;
            data.eventCallback(event);
        };
        glfwSetWindowCloseCallback(m_Window, closeCallback);

        auto keyCallback = [](GLFWwindow *window, int key, int scancode, int action, int mods)
        {
            WindowData &data = *static_cast<WindowData *>(glfwGetWindowUserPointer(window));
            switch (action)
            {
            case GLFW_PRESS:
            {
                KeyPressedEvent event(key, 0);
                data.eventCallback(event);
                break;
            }
            case GLFW_RELEASE:
            {
                KeyReleasedEvent event(key);
                data.eventCallback(event);
                break;
            }
            case GLFW_REPEAT:
            {
                KeyPressedEvent event2(key, 1);
                data.eventCallback(event2);
                break;
            }
            }
        };
        glfwSetKeyCallback(m_Window, keyCallback);

        auto mouseButtonCallback = [](GLFWwindow *window, int button, int action, int mods)
        {
            WindowData &data = *static_cast<WindowData *>(glfwGetWindowUserPointer(window));
            switch (action)
            {
            case GLFW_PRESS:
            {
                MouseButtonPressedEvent event(button);
                data.eventCallback(event);
                break;
            }
            case GLFW_RELEASE:
            {
                MouseButtonReleasedEvent event(button);
                data.eventCallback(event);
                break;
            }
            }
        };
        glfwSetMouseButtonCallback(m_Window, mouseButtonCallback);

        auto scrollCallback = [](GLFWwindow *window, double xOffset, double yOffset)
        {
            WindowData &data = *static_cast<WindowData *>(glfwGetWindowUserPointer(window));
            MouseScrolledEvent event(static_cast<float>(xOffset), static_cast<float>(yOffset));
            data.eventCallback(event);
        };
        glfwSetScrollCallback(m_Window, scrollCallback);

        auto mouseMoveCallback = [](GLFWwindow *window, double xpos, double ypos)
        {
            WindowData &data = *static_cast<WindowData *>(glfwGetWindowUserPointer(window));
            MouseMovedEvent event(static_cast<float>(xpos), static_cast<float>(ypos));
            data.eventCallback(event);
        };
        glfwSetCursorPosCallback(m_Window, mouseMoveCallback);
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
