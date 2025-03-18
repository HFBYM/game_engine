/**
 * @file Application.cpp
 * @author: Clare  email: 1090535708@qq.com
 * @date 2025-03-15
 * @copyright Copyright (c) 2025 by Clare, All Rights Reserved.
 */
#include "eg_pch.h"
#include <GLFW/glfw3.h>
#include "engine/application.h"
#include "engine/event/applicationEvent.h"
namespace engine
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
    Application::Application()
    {
        m_window = std::unique_ptr<Window>(Window::create(WindowProps()));
        // m_window->setEventCallback(BIND_EVENT_FN(onEvent));
        auto func = [this](Event &e) { this->onEvent(e); };
        m_window->setEventCallback(func);
    }
    void Application::onEvent(Event &e)
    {
        EG_CORE_INFO("{0}", e);
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
