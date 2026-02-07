#pragma once

#define GLFW_INCLUDE_NONE

#include "GLFW/glfw3.h"

namespace SurrealStudio {

	namespace SurrealEditor {

		class SurrealStudioMainWindow
		{
		public:

			bool InitWindow();
			bool CreateWindow(int width, int height, const char* title);
			bool MainLoop();
			bool DestroyWindow();

		private:

			GLFWwindow* m_SurrealStudioWindow = nullptr;
		};
	}
}