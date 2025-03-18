/**
 * @file log.cpp
 * @author: Clare  email: 1090535708@qq.com
 * @date 2025-03-15
 * @copyright Copyright (c) 2025 by Clare, All Rights Reserved.
 */
#include "eg_pch.h"
#include "engine/log.h"
#include<spdlog/sinks/stdout_color_sinks.h>
#include<spdlog/fmt/ostr.h>
namespace engine
{
    std::shared_ptr<spdlog::logger> Log::s_core_logger;
    std::shared_ptr<spdlog::logger> Log::s_client_logger;
    void Log::init()
    {
        // set the log pattern
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_core_logger = spdlog::stdout_color_mt("Engine");
        s_core_logger->set_level(spdlog::level::trace);
        s_client_logger = spdlog::stdout_color_mt("App");
        s_client_logger->set_level(spdlog::level::trace);
    }
} // namespace engine
