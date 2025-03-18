/**
 * @file Application.cpp
 * @author: Clare  email: 1090535708@qq.com
 * @date 2025-03-15
 * @copyright Copyright (c) 2025 by Clare, All Rights Reserved.
 */
#include "eg_pch.h"
#include<GLFW/glfw3.h>
#include "engine/application.h"
#include"engine/event/applicationEvent.h"
namespace engine
{
    Application::Application()
    {
        m_window = std::unique_ptr<Window>(Window::create(WindowProps()));
    }
    Application::~Application() {}
    void Application::run()
    {
        while (m_running)
        {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_window->onUpdate();
        }
    }
} // namespace engine
