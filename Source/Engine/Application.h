#pragma once

namespace SurrealStudio {

	class Application
	{
	public:

		bool EngineInit();
		bool EngineRun(int argc, char** argv);
		bool EngineShutdown();

		static Application* CreateApplication();
	};
}