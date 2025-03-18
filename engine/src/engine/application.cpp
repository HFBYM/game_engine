/**
 * @file Application.cpp
 * @author: Clare  email: 1090535708@qq.com
 * @date 2025-03-15
 * @copyright Copyright (c) 2025 by Clare, All Rights Reserved.
 */
#include "eg_pch.h"
#include "engine/application.h"
#include "engine/log.h"
#include"engine/event/applicationEvent.h"
namespace engine
{
    Application::Application() {}
    Application::~Application() {}
    void Application::run()
    {
        engine::WindowResizeEvent event(1280, 720);
        EG_WARN(event.toString());
        while (true)
        {
        }
    }
} // namespace engine
