#include "Scene.h"

namespace SurrealStudio {

	namespace SceneSystem {

		bool Scene::AddObject(const std::string& name)
		{
			// Create a new Object
			auto newObject = std::make_unique<Object>();
			newObject->objectName = name;
			newObject->position = { 0.0f, 0.0f, 0.0f };
			newObject->rotation = { 0.0f, 0.0f, 0.0f };
			newObject->scale = { 1.0f, 1.0f, 1.0f };

			// Move it into the vector
			m_Objects.push_back(std::move(newObject));

			return true;
		}


		bool Scene::DeleteObject(int index)
		{
			if (index < 0 || index >= static_cast<int>(m_Objects.size()))
				return false;

			m_Objects.erase(m_Objects.begin() + index);
			return true;
		}
	}
}