/**
 * @file core.h
 * @author: Clare  email: 1090535708@qq.com
 * @date 2025-03-15
 * @copyright Copyright (c) 2025 by Clare, All Rights Reserved.
 */
#pragma once
#ifdef EG_PLATFORM_WINDOWS
#ifdef EG_BUILD_DLL
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif
#else
#define ENGINE_API
#endif

#ifdef EG_ENABLE_ASSERTS
#define EG_ASSERT(x, ...)                                      \
    {                                                       \
        if (!(x))                                           \
        {                                                   \
            EG_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            __debugbreak();                                 \
        }                                                   \
    }
#define EG_CORE_ASSERT(x, ...)                                 \
    {                                                       \
        if (!(x))                                           \
        {                                                   \
            EG_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            __debugbreak();                                 \
        }                                                   \
    }
#else
#define EG_ASSERT(x, ...)
#define EG_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
