#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Subscene.h"

namespace SurrealStudio {
	
	namespace SceneSystem {

		struct SceneData
		{
			std::string sceneName;
			std::vector<std::unique_ptr<Subscene>> subscenes;
		};

		class Scene
		{
		public:
			Scene() = default;
			~Scene() = default;

			bool AddScene() noexcept;
			bool DeleteScene() noexcept;

			// In Surreal Studio, there is only 1 scene. 
			// It is essentially the root container of the project, only it does not include the actual folder structure
			// and project files, and files. It only stores objects, Subscenes, Worlds (which are a child of Subscene)
			// and nothing else. If a Scene is deleted, everything inside the Scene will be deleted as well as it is the main 
			// parent of everything in the project.

		private:

			SceneData m_SceneData;
			std::vector<std::unique_ptr<SceneData>> m_Scene; // NOTE: THERE WILL BE ONLY ONE SCENE IN A PROJECT
		};
	}
}