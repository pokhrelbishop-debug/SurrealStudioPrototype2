#include "Scene.h"

namespace SurrealStudio {

	namespace SceneSystem {

		bool Scene::AddScene() noexcept
		{
			if (!m_Scene.empty())
				return false; // Scene cannot be added as there is only one scene in a project

			auto newScene = std::make_unique<SceneData>();
			newScene->sceneName = "Main Scene";

			m_Scene.push_back(std::move(newScene));

			return true;
		}

		bool Scene::DeleteScene() noexcept
		{
			if (m_Scene.empty())
				return false;

			m_Scene.clear(); // there will be only one scene.

			return true;
		}
	}
}