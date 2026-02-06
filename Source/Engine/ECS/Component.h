#pragma once

#include "Object.h"

#include <glm/glm.hpp>
#include <memory>
#include <vector>

namespace SurrealStudio {

	namespace ECS {

		// Example Component
		struct TransformComponent
		{
			glm::vec3 position;
			glm::vec3 rotation;
			glm::vec3 scale;

			std::string objectName; // to which object does it belong to 

		private:

			int index;
		};

		class TransformComponentManager
		{
		public:

			bool AddTransformComponent(const ObjectData& objectName,glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) noexcept;
			bool DeleteTransformComponent(const ObjectData& objectName) noexcept;
			
			std::vector<TransformComponent*> GetAllTransformComponents() const noexcept
			{
				std::vector<TransformComponent*> result;
				for (auto& ptr : m_TransformComponents)
					result.push_back(ptr.get());
				return result;
			}
			
		private:

			std::vector<std::unique_ptr<TransformComponent>> m_TransformComponents;
			friend struct TransformComponent;
		};

		// Central Component Manager 'hub'
		class ComponentManager
		{
		public:

			TransformComponentManager transformComponentManager;
			// other components if needed.	
		};
	}
}