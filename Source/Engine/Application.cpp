#include "Application.h"
#include "Logging.h"

namespace SurrealStudio {

    bool Application::EngineInit()
    {
        SS_INFO("Engine is starting!");
        return true;
    }

    bool Application::EngineRun(int argc, char** argv)
    {
        SS_INFO("Engine is running!");
        return true;
    }

    bool Application::EngineShutdown()
    {
        SS_INFO("Engine is shutting down!");
        return true;
    }

    Application* Application::CreateApplication()
    {
        return new Application();
    }
}
