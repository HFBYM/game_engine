/**
 * @file layer.h
 * @author: Clare  email: 1090535708@qq.com
 * @date 2025-03-27
 * @copyright Copyright (c) 2025 by Clare, All Rights Reserved.
 */
#pragma once

#include "engine/core.h"
#include "engine/event/event.h"
namespace engine
{
    class ENGINE_API Layer
    {
    public:
        explicit Layer(const std::string &name = "Layer");
        virtual ~Layer();

        virtual void onAttach() {}
        virtual void onDetach() {}
        virtual void onUpdate() {}
        virtual void onEvent(Event &e) {}

        inline const std::string &getName() const { return m_debugName; }
    private:
        std::string m_debugName;
    };
} // namespace engine
