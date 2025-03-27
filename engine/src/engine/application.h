/**
 * @file Application.h
 * @author: Clare  email: 1090535708@qq.com
 * @date 2025-03-15
 * @copyright Copyright (c) 2025 by Clare, All Rights Reserved.
 */
#pragma once
#include "engine/core.h"
#include "engine/event/event.h"
#include "engine/window.h"
#include "engine/event/applicationEvent.h"
#include "engine/layerStack.h"
namespace engine
{
    class ENGINE_API Application
    {
    public:
        Application();
        virtual ~Application();
        void run();
        void onEvent(Event &e);
        void pushLayer(Layer *layer);
        void pushOverlay(Layer *layer);

    private:
        bool onWindowClose(WindowCloseEvent &e);
        std::unique_ptr<Window> m_window;
        bool m_running = true;
        LayerStack m_layerStack;
    };

    // to be defined in client
    Application *createApplication();
} // namespace engine
