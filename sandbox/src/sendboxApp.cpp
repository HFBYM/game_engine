/**
 * @file application.cpp
 * @author: Clare  email: 1090535708@qq.com
 * @date 2025-03-15
 * @copyright Copyright (c) 2025 by Clare, All Rights Reserved.
 */
#include <engine.h>
#include <memory>
class SandBox : public engine::Application
{
public:
    SandBox() {}
    virtual ~SandBox() {}
};
engine::Application *engine::createApplication()
{
    return new SandBox();
}
