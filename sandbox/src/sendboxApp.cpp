/**
 * @file application.cpp
 * @author: Clare  email: 1090535708@qq.com
 * @date 2025-03-15
 * @copyright Copyright (c) 2025 by Clare, All Rights Reserved.
 */
#include <engine.h>
#include <memory>
class ExampleLayer : public engine::Layer
{
public:
    ExampleLayer() : Layer("Example") {}
    virtual ~ExampleLayer() {}
    void onUpdate() override
    {
        EG_INFO("ExampleLayer onUpdate");
    }
    void onEvent(engine::Event &event) override
    {
        EG_TRACE("{0}", event);
    }
};
class SandBox : public engine::Application
{
public:
    SandBox() { pushLayer(new ExampleLayer()); }
    virtual ~SandBox() {}
};
engine::Application *engine::createApplication()
{
    return new SandBox();
}
