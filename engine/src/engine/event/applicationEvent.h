/**
 * @file applicationEvent.h
 * @author: Clare  email: 1090535708@qq.com
 * @date 2025-03-16
 * @copyright Copyright (c) 2025 by Clare, All Rights Reserved.
 */
#pragma once
#include <string>
#include <sstream>
#include "engine/event/event.h"
namespace engine
{
    class ENGINE_API WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height)
            : m_width(width), m_height(height) {}
        unsigned int getWidth() const { return m_width; }
        unsigned int getHeight() const { return m_height; }
        std::string toString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_width << ", " << m_height;
            return ss.str();
        }
        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    private:
        unsigned int m_width, m_height;
    };

    class ENGINE_API WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() {}
        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class ENGINE_API AppTickEvent : public Event
    {
    public:
        AppTickEvent() {}
        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class ENGINE_API AppUpdateEvent : public Event
    {
    public:
        AppUpdateEvent() {}
        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class ENGINE_API AppRenderEvent : public Event
    {
    public:
        AppRenderEvent() {}
        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.toString();
    }
} // namespace engine
