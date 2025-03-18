/**
 * @file log.h
 * @author: Clare  email: 1090535708@qq.com
 * @date 2025-03-15
 * @copyright Copyright (c) 2025 by Clare, All Rights Reserved.
 */
#pragma once
#include <spdlog/spdlog.h>
#include "eg_pch.h"
#include "engine/core.h"
namespace engine
{
    class ENGINE_API Log
    {
    public:
        static void init();
        static inline std::shared_ptr<spdlog::logger> &get_core_logger() { return s_core_logger; }
        static inline std::shared_ptr<spdlog::logger> &get_client_logger()
        { return s_client_logger; }
    private:
        static std::shared_ptr<spdlog::logger> s_core_logger;
        static std::shared_ptr<spdlog::logger> s_client_logger;
    };
} // namespace engine

// core log
#define EG_CORE_ERROR(...) ::engine::Log::get_core_logger()->error(__VA_ARGS__)
#define EG_CORE_WARN(...) ::engine::Log::get_core_logger()->warn(__VA_ARGS__)
#define EG_CORE_INFO(...) ::engine::Log::get_core_logger()->info(__VA_ARGS__)
#define EG_CORE_TRACE(...) ::engine::Log::get_core_logger()->trace(__VA_ARGS__)
#define EG_CORE_FATAL(...) ::engine::Log::get_core_logger()->fatal(__VA_ARGS__)

// client log
#define EG_ERROR(...) ::engine::Log::get_client_logger()->error(__VA_ARGS__)
#define EG_WARN(...) ::engine::Log::get_client_logger()->warn(__VA_ARGS__)
#define EG_INFO(...) ::engine::Log::get_client_logger()->info(__VA_ARGS__)
#define EG_TRACE(...) ::engine::Log::get_client_logger()->trace(__VA_ARGS__)
#define EG_FATAL(...) ::engine::Log::get_client_logger()->fatal(__VA_ARGS__)
