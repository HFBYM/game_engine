/**
 * @file layerStack.h
 * @author: Clare  email: 1090535708@qq.com
 * @date 2025-03-27
 * @copyright Copyright (c) 2025 by Clare, All Rights Reserved.
 */

#pragma once

#include <vector>
#include "engine/core.h"
#include "engine/layer.h"
namespace engine
{
    class ENGINE_API LayerStack
    {
    public:
        LayerStack();
        ~LayerStack();

        //TODO(Clare): using smart pointer
        void pushLayer(Layer *layer);
        void pushOverlay(Layer *layer);
        void popLayer(Layer *layer);
        void popOverlay(Layer *layer);

        std::vector<Layer *>::iterator begin() { return m_layers.begin(); }
        std::vector<Layer *>::iterator end() { return m_layers.end(); }
    private:
        std::vector<Layer *> m_layers;
        std::vector<Layer *>::iterator m_layerInsert;
    };
} // namespace engine
