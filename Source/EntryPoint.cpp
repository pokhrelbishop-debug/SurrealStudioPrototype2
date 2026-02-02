#include "Engine/Application.h"
#include "Engine/EngineDefines.h"
#include "Engine/Logging.h"

#include <memory>
#include <stdexcept>

using namespace SurrealStudio;

#ifdef _WIN64 

int main(int argc, char** argv)
{
	try
	{
		std::unique_ptr<Application> app(Application::CreateApplication());

		if (app == nullptr)
		{
			throw std::runtime_error("Application app is a null pointer! EntryPoint.cpp");
		}

		app->EngineInit();
		app->EngineRun(argc, argv);
		app->EngineShutdown();

		return ENGINE_SUCCESS;
	}
	catch (const std::exception& e) {
		SS_ERROR(e.what());
		return ENGINE_FAILURE;
	}
	catch (...) {
		SS_ERROR("Some unknown exception occurred!");
		return ENGINE_FAILURE;
	}
}

#else
	#error "Surreal Studio only compiles on 64-bit Windows!"
#endif