/**
 * @file layerStack.cpp
 * @author: Clare  email: 1090535708@qq.com
 * @date 2025-03-27
 * @copyright Copyright (c) 2025 by Clare, All Rights Reserved.
 */

#include "eg_pch.h"
#include "engine/layerStack.h"

namespace engine
{
    LayerStack::LayerStack()
    {
        m_layerInsert = m_layers.begin();
    }
    LayerStack::~LayerStack()
    {
        for (auto &layer : m_layers)
            delete layer;
    }
    void LayerStack::pushLayer(Layer *layer)
    {
        // emplace creates entity before the iterator and returns the iterator of the new entity
        m_layerInsert = m_layers.emplace(m_layerInsert, layer);
    }
    void LayerStack::pushOverlay(Layer *layer)
    {
        m_layers.emplace_back(layer);
    }
    void LayerStack::popLayer(Layer *layer)
    {
        auto it = std::find(m_layers.begin(), m_layers.end(), layer);
        if (it != m_layers.end())
        {
            m_layers.erase(it);
            //TODO(Clare): kind of error
            m_layerInsert--;
        }
    }
    void LayerStack::popOverlay(Layer *layer)
    {
        auto it = std::find(m_layers.begin(), m_layers.end(), layer);
        if (it != m_layers.end())
        {
            m_layers.erase(it);
        }
    }

} // namespace engine
