#include "SceneManagerPanel.h"

#include <imgui.h>

namespace SurrealStudio {

	namespace SurrealEditor {

		bool SceneManagerPanel::DrawCameraCreation()
		{
			constexpr int s_CE_uI_MAX_CAMERA_OBJECTS_PER_WORLD = 10;
			int i_selectedCameraIndex = 0;
			const char* c_CPTR_cameraOptions[] = {
				"Normal", "Orthographic"
			};
			bool b_openMaxCameraObjectsReachedPerWorld_SSERROR_DialogBox = true;

			if (ImGui::BeginCombo("Camera Options", c_CPTR_cameraOptions[i_selectedCameraIndex]))
			{
				for (int n = 0; n < IM_ARRAYSIZE(c_CPTR_cameraOptions); n++)
				{
					bool b_IsCameraOptionSelected = (n == i_selectedCameraIndex);
					if (ImGui::Selectable(c_CPTR_cameraOptions[n], b_IsCameraOptionSelected))
						i_selectedCameraIndex = n;
					
					if (b_IsCameraOptionSelected == true)
						ImGui::SetItemDefaultFocus();
				}
				ImGui::EndCombo();
			}

			return true;
		}

		bool SceneManagerPanel::DrawLightingCreation()
		{
			return true;
		}

		bool SceneManagerPanel::DrawCameraProperites(const char* cameraOptions[], int index)
		{
			return true;
		}

		bool SceneManagerPanel::DrawLightingProperties(const char* lightingOptions[], int index)
		{
			return true;
		}

		bool SceneManagerPanel::DrawSceneCreation()
		{
			return true;
		}

		bool SceneManagerPanel::DrawSceneManagerPanel()
		{
			ImGui::Begin("Scene Manager Panel");

			DrawSceneCreation();

			if (ImGui::CollapsingHeader("Camera"))
				DrawCameraCreation();
			
			if (ImGui::CollapsingHeader("Lighting"))
				DrawLightingCreation();

			ImGui::End();

			return true;
		}
	}
}