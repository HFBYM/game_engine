/**
 * @file event.h
 * @author: Clare  email: 1090535708@qq.com
 * @date 2025-03-16
 * @copyright Copyright (c) 2025 by Clare, All Rights Reserved.
 */
#pragma once
#include "eg_pch.h"
#include "engine/core.h"
//TODO(Clare): optimization events
namespace engine
{
    enum class EventType
    {
        None = 0,
        WindowClose,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMoved,
        AppTick,
        AppUpdate,
        AppRender,
        KeyPressed,
        KeyReleased,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled
    };

    /// @brief using mask to multiply process event
    enum EventCategory
    {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryInput = BIT(1),
        EventCategoryKeyboard = BIT(2),
        EventCategoryMouse = BIT(3),
        EventCategoryMouseButton = BIT(4)
    };
    //TODO(Clare): depose the macro
#define EVENT_CLASS_TYPE(type)                                                  \
    static EventType getStaticType() { return EventType::##type; }                \
    EventType getEventType() const override { return getStaticType(); } \
    const char *getName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) \
    int getCategoryFlags() const override { return category; }

    class ENGINE_API Event
    {
        friend class EventDispatcher;

    public:
        virtual EventType getEventType() const = 0;
        virtual const char *getName() const = 0;
        virtual int getCategoryFlags() const = 0;
        virtual std::string toString() const { return getName(); }
        inline bool isInCategory(EventCategory category) const
        {
            return getCategoryFlags() & category;
        }
    protected:
        bool m_handled = false;
    };

    class ENGINE_API EventDispatcher
    {
        template <typename T>
        using EventFunc = std::function<bool(T &)>;
    public:
        explicit EventDispatcher(Event &event) : m_event(event) {}
        template <typename T>
        bool dispatch(EventFunc<T> func)
        {
            if (m_event.getEventType() == T::getStaticType())
            {
                m_event.m_handled = func(static_cast<T &>(m_event));
                return true;
            }
            return false;
        }
    private:
        Event &m_event;
    };

    inline std::ostream &operator<<(std::ostream &os, const Event &e)
    {
        return os << e.toString();
    }

} // namespace engine
