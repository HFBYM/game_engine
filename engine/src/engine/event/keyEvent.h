/**
 * @file keyEvent.h
 * @author: Clare  email: 1090535708@qq.com
 * @date 2025-03-16
 * @copyright Copyright (c) 2025 by Clare, All Rights Reserved.
 */
#pragma once
#include "eg_pch.h"
#include "engine/event/event.h"
namespace engine
{
    class ENGINE_API KeyEvent : public Event
    {
    public:
        inline int getKeyCode() const { return m_keyCode; }
        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    protected:
        explicit KeyEvent(int keycode) : m_keyCode(keycode) {}
        int m_keyCode;
    };

    class ENGINE_API KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int keycode, int repeatCount)
        : KeyEvent(keycode), m_repeatCount(repeatCount) {}
        inline int getRepeatCount() const { return m_repeatCount; }
        std::string toString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_keyCode << " (" << m_repeatCount << " repeats)";
            return ss.str();
        }
        EVENT_CLASS_TYPE(KeyPressed)
    private:
        int m_repeatCount;
    };

    class ENGINE_API KeyReleasedEvent : public KeyEvent
    {
    public:
        explicit KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}
        std::string toString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_keyCode;
            return ss.str();
        }
        EVENT_CLASS_TYPE(KeyReleased)
    };
} // namespace engine
