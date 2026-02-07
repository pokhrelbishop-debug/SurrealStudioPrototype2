#include "SurrealStudioMainWindow.h"
#include <Engine/Logging.h>

#define GLFW_INCLUDE_NONE

#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace SurrealStudio {

	namespace SurrealEditor {

		bool SurrealStudioMainWindow::InitWindow()
		{
			if (!glfwInit())
			{
				glfwTerminate();
				SS_ERROR("GLFW failed to initialize.");
				return false;
			}

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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
				SS_ERROR("Failed to initialize GLAD.\n");
				glfwTerminate();
				return false;
			}

			// ----- ImGui Setup -----
			IMGUI_CHECKVERSION();
			ImGui::CreateContext();
			ImGuiIO& io = ImGui::GetIO(); (void)io;

			ImGui::StyleColorsDark();

			ImGui_ImplGlfw_InitForOpenGL(m_SurrealStudioWindow, true);
			ImGui_ImplOpenGL3_Init("#version 330 core");

			return true;
		}

		bool SurrealStudioMainWindow::MainLoop()
		{
			while (!glfwWindowShouldClose(m_SurrealStudioWindow))
			{
				glfwPollEvents();

				// ----- Start ImGui Frame -----
				ImGui_ImplOpenGL3_NewFrame();
				ImGui_ImplGlfw_NewFrame();
				ImGui::NewFrame();

				// ----- Example ImGui Window -----
				ImGui::Begin("Surreal Studio Editor");
				ImGui::Text("Hello, Surreal Studio!");
				ImGui::End();

				// ----- Rendering -----
				ImGui::Render();
				glViewport(0, 0, 1280, 720); // Optional: adapt to window size
				glClearColor(0.05f, 0.05f, 0.08f, 1.0f); // Dark bluish-gray
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				glEnable(GL_DEPTH_TEST);

				ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

				glfwSwapBuffers(m_SurrealStudioWindow);
			}
			return true;
		}

		bool SurrealStudioMainWindow::DestroyWindow()
		{
			// ----- Cleanup ImGui -----
			ImGui_ImplOpenGL3_Shutdown();
			ImGui_ImplGlfw_Shutdown();
			ImGui::DestroyContext();

			if (m_SurrealStudioWindow)
			{
				glfwDestroyWindow(m_SurrealStudioWindow);
				glfwTerminate();
			}
			return true;
		}
	}
}
