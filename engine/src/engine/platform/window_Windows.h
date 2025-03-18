/**
 * @file window_Windows.h
 * @author: Clare  email: 1090535708@qq.com
 * @date 2025-03-18
 * @copyright Copyright (c) 2025 by Clare, All Rights Reserved.
 */
#pragma once
#include<GLFW/glfw3.h>
#include "engine/window.h"
namespace engine
{
    class ENGINE_API WindowsWindow : public Window
    {
    public:
        explicit WindowsWindow(const WindowProps &props);
        virtual ~WindowsWindow();
        void onUpdate() override;
        unsigned int getWidth() const override { return m_Data.width; }
        unsigned int getHeight() const override { return m_Data.height; }

        void setEventCallback(const EventCallbackFn &callback) override
        { m_Data.eventCallback = callback; }
        void setVSync(bool enabled) override;
        bool isVSync() const override;

    private:
        virtual void init(const WindowProps &props);
        virtual void shutdown();
        GLFWwindow *m_Window;
        struct WindowData
        {
            std::string title;
            unsigned int width, height;
            bool isVSync;
            EventCallbackFn eventCallback;
        };
        WindowData m_Data;
    };
} // namespace engine
