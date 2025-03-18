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
namespace engine
{
    class ENGINE_API Application
    {
    public:
        Application();
        virtual ~Application();
        void run();

    private:
        std::unique_ptr<Window> m_window;
        bool m_running = true;
    };

    // to be defined in client
    Application *createApplication();
} // namespace engine
