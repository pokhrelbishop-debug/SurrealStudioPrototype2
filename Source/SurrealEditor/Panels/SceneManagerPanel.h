#pragma once

namespace SurrealStudio {

	namespace SurrealEditor {

		class SceneManagerPanel
		{
		public:

			bool DrawSceneCreation();
			bool DrawLightingCreation();
			bool DrawCameraCreation();
			bool DrawLightingProperties(const char* lightingOptions[], int index);
			bool DrawCameraProperites(const char* cameraOptions[], int index);
			bool DrawSceneManagerPanel();
		};
	}
}