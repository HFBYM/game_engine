/**
 * @file layer.cpp
 * @author: Clare  email: 1090535708@qq.com
 * @date 2025-03-27
 * @copyright Copyright (c) 2025 by Clare, All Rights Reserved.
 */

#include "eg_pch.h"
#include "engine/layer.h"
namespace engine
{
    Layer::Layer(const std::string& debugName) : m_debugName(debugName) {}
    Layer::~Layer() {}
} // namespace engine
