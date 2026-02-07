#pragma once

#include <SurrealEditor/SurrealStudioMainWindow.h>

namespace SurrealStudio {

	class Application
	{
	public:

		bool EngineInit();
		bool EngineRun(int argc, char** argv);
		bool EngineShutdown();

		static Application* CreateApplication();

	private:

		SurrealEditor::SurrealStudioMainWindow m_Window;
		
	};
}