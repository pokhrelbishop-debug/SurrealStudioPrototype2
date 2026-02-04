#pragma once

#include "EngineUI/SurrealStudioMainWindow.h"

namespace SurrealStudio {

	class Application
	{
	public:

		bool EngineInit();
		bool EngineRun(int argc, char** argv);
		bool EngineShutdown();

		static Application* CreateApplication();

	private:

		EngineUI::SurrealStudioMainWindow m_Window;
	};
}