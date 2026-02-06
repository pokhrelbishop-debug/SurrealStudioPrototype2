#include "Component.h"
#include "Object.h"

namespace SurrealStudio {

	namespace ECS {

		bool TransformComponentManager::AddTransformComponent(const ObjectData& objectName, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) noexcept
		{
			auto newTransformComponent = std::make_unique<TransformComponent>();
			newTransformComponent->objectName = objectName.name;
			newTransformComponent->position = position;
			newTransformComponent->rotation = rotation;
			newTransformComponent->scale = scale;
			m_TransformComponents.push_back(newTransformComponent);
			return true;
		}

		bool TransformComponentManager::DeleteTransformComponent(const ObjectData& objectName) noexcept
		{
			if (m_TransformComponents.empty())
				return false;

			for (auto it = m_TransformComponents.begin(); it != m_TransformComponents.end(); it++)
			{
				if ((*it)->objectName == objectName.name)
				{
					m_TransformComponents.erase(it);
					return true;
				}
			}

			std::cout << "Failed to delete Transform Component in Object " << objectName.name << ".\n" << std::endl;
			return false; // did not find component.
		}

		bool VelocityComponentManager::AddVelocityComponent(const ObjectData& objectName, glm::vec3 velocity) noexcept
		{
			auto newVelocityComponent = std::make_unique<VelocityComponent>();
			newVelocityComponent->objectName = objectName.name;
			newVelocityComponent->velocity = velocity;
			m_VelocityComponents.push_back(std::move(newVelocityComponent));
			return true;
		}

		bool VelocityComponentManager::DeleteVelocityComponent(const ObjectData& objectName) noexcept
		{
			if (m_VelocityComponents.empty())
				return false;

			for (auto it = m_VelocityComponents.begin(); it != m_VelocityComponents.end(); it++)
			{
				if ((*it)->objectName == objectName.name)
				{
					m_VelocityComponents.erase(it);
					return true;
				}
			}

			std::cout << "Failed to delete Velocity Component in Object " << objectName.name << ".\n";
			return false;
		}
	}
}