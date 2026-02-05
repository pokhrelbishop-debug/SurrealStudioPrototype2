#include "SurrealStudioMainWindow.h"
#include <Engine/Logging.h>

#define GLFW_INCLUDE_NONE

#include "GLFW/glfw3.h"
#include "glad/glad.h"

namespace SurrealStudio {

	namespace EngineUI {

		bool SurrealStudioMainWindow::InitWindow()
		{
			if (!glfwInit())
			{
				glfwTerminate();
				SS_ERROR("GLFW failed to initialize.");
				return false;
			}

			glfwWindowHint(GLFW_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_CORE_PROFILE, GLFW_OPENGL_PROFILE);

			return true;
		}

		bool SurrealStudioMainWindow::CreateWindow(int width, int height, const char* title)
		{
			m_SurrealStudioWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
			if (!m_SurrealStudioWindow)
			{
				SS_ERROR("Failed to create GLFW window.\n");
				glfwTerminate();
				return false;
			}

			glfwMakeContextCurrent(m_SurrealStudioWindow);
			glfwSwapInterval(1); // Enable VSync

			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				SS_ERROR("Failed to initalize GLAD.\n");
				glfwTerminate();
				return false;
			}

			return true;
		}

		bool SurrealStudioMainWindow::MainLoop()
		{
			while (!glfwWindowShouldClose(m_SurrealStudioWindow))
			{
				glfwPollEvents();
				glClearColor(0.05f, 0.05f, 0.08f, 1.0f); // Dark bluish-gray
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				glEnable(GL_DEPTH_TEST);

				glfwSwapBuffers(m_SurrealStudioWindow);

			}
			return true;
		}

		bool SurrealStudioMainWindow::DestroyWindow()
		{
			if (!m_SurrealStudioWindow) return false;

			glfwDestroyWindow(m_SurrealStudioWindow);
			glfwTerminate();
			return true;
		}
	}
}