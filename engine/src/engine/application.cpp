/**
 * @file Application.cpp
 * @author: Clare  email: 1090535708@qq.com
 * @date 2025-03-15
 * @copyright Copyright (c) 2025 by Clare, All Rights Reserved.
 */
#include "eg_pch.h"
#include <GLFW/glfw3.h>
#include "engine/application.h"
namespace engine
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
    Application::Application()
    {
        m_window = std::unique_ptr<Window>(Window::create(WindowProps()));
        // m_window->setEventCallback(BIND_EVENT_FN(onEvent));
        auto func = [this](Event &e)
        { this->onEvent(e); };
        m_window->setEventCallback(func);
    }
    void Application::onEvent(Event &e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));

        // TODO(clare): new log
        // EG_CORE_INFO("{0}", e);

        // update layer from end to begin
        for (auto it = m_layerStack.end(); it != m_layerStack.begin();)
        {
            (*--it)->onEvent(e);
            if (e.isHandled())
                break;
        }
    }
    bool Application::onWindowClose(WindowCloseEvent &e)
    {
        m_running = false;
        return true;
    }
    void Application::pushLayer(Layer *layer) { m_layerStack.pushLayer(layer); }
    void Application::pushOverlay(Layer *layer) { m_layerStack.pushOverlay(layer); }
    Application::~Application() {}
    void Application::run()
    {
        while (m_running)
        {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_window->onUpdate();
        }
        for (auto &layer : m_layerStack)
        {
            layer->onUpdate();
        }
    }
} // namespace engine
