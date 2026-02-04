#pragma once

#include <glm/glm.hpp>
#include <string>
#include <vector>
#include <memory>

namespace SurrealStudio {
	
	namespace SceneSystem {

		struct Object
		{
			glm::vec3 position;
			glm::vec3 rotation;
			glm::vec3 scale;

			std::string objectName;
		};

		class Scene
		{
		public:
			Scene() = default;
			~Scene() = default;

			bool AddObject(const std::string& name);
			bool DeleteObject(int index);

		private:

			std::vector<std::unique_ptr<Object>> m_Objects;
		};
	}
}