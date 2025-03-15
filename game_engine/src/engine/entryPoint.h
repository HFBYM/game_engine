/**
 * @file entryPoint.h
 * @author: Clare  email: 1090535708@qq.com
 * @date 2025-03-15
 * @copyright Copyright (c) 2025 by Clare, All Rights Reserved.
 */
#pragma once
#ifdef EG_PLATFORM_WINDOWS
extern engine::Application* engine::createApplication();
int main(int argc, char** argv)
{
    auto app = engine::createApplication();
    app->run();
    delete app;
    return 0;
}
#endif
