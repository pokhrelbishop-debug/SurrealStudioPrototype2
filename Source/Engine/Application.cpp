#include "Application.h"
#include "Logging.h"

#include <SurrealEditor/SurrealStudioMainWindow.h>

namespace SurrealStudio {

    bool Application::EngineInit()
    {
        SS_INFO("Engine is starting!");
        return true;
    }

    bool Application::EngineRun(int argc, char** argv)
    {
        m_Window.InitWindow();
        m_Window.CreateWindow(800, 600, "Surreal Studio");
        m_Window.MainLoop();
        SS_INFO("Engine is running!");
        return true;
    }

    bool Application::EngineShutdown()
    {
        m_Window.DestroyWindow();
        SS_INFO("Engine is shutting down!");
        return true;
    }

    Application* Application::CreateApplication()
    {
        return new Application();
    }
}
