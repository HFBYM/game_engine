/**
 * @file mouseEvent.h
 * @author: Clare  email: 1090535708@qq.com
 * @date 2025-03-16
 * @copyright Copyright (c) 2025 by Clare, All Rights Reserved.
 */
#pragma once
#include <sstream>
#include <string>
#include "engine/event/event.h"
namespace engine
{
    class ENGINE_API MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(float x, float y) : m_mouseX(x), m_mouseY(y) {}
        inline float getX() const { return m_mouseX; }
        inline float getY() const { return m_mouseY; }
        std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_mouseX << ", " << m_mouseY;
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float m_mouseX, m_mouseY;
    };

    class ENGINE_API MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(float xOffset, float yOffset) : m_xOffset(xOffset), m_yOffset(yOffset) {}
        inline float getXOffset() const { return m_xOffset; }
        inline float getYOffset() const { return m_yOffset; }
        std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << m_xOffset << ", " << m_yOffset;
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float m_xOffset, m_yOffset;
    };

    class ENGINE_API MouseButtonEvent : public Event
    {
    public:
        inline int getMouseButton() const { return m_button; }
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    protected:
        explicit MouseButtonEvent(int button) : m_button(button) {}
        int m_button;
    };

    class ENGINE_API MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        explicit MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}
        std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_button;
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class ENGINE_API MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        explicit MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}
        std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_button;
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
} // namespace engine
