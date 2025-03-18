/**
 * @file window.h
 * @author: Clare  email: 1090535708@qq.com
 * @date 2025-03-18
 * @copyright Copyright (c) 2025 by Clare, All Rights Reserved.
 */
#pragma once
#include "eg_pch.h"
#include "engine/event/event.h"
#include "engine/core.h"
namespace engine
{
    struct ENGINE_API WindowProps
    {
        std::string title;
        unsigned int width;
        unsigned int height;
        WindowProps(const std::string &title = "Engine",
                    unsigned int width = 1280, unsigned int height = 720)
            : title(title), width(width), height(height) {}
    };

    class ENGINE_API Window
    {
    public:
        using EventCallbackFn = std::function<void(Event &)>;
        virtual ~Window() {}
        virtual void onUpdate() = 0;
        virtual unsigned int getWidth() const = 0;
        virtual unsigned int getHeight() const = 0;

        virtual void setEventCallback(const EventCallbackFn &) = 0;
        virtual void setVSync(bool enabled) = 0;
        virtual bool isVSync() const = 0;

        static Window *create(const WindowProps &props = WindowProps());
    };
} // namespace engine
