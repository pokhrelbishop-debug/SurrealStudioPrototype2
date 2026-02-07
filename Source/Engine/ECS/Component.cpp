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
			m_TransformComponents.push_back(std::move(newTransformComponent));
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

		bool PhysicsComponentManager::AddPhysicsComponent(const ObjectData& objectName, glm::vec3 velocity, glm::vec3 angularVelocity, glm::vec3 scaleVelocity) noexcept
		{
			auto newPhysicsComponent = std::make_unique<PhysicsComponent>();
			newPhysicsComponent->objectName = objectName.name;
			newPhysicsComponent->velocity = velocity;
			newPhysicsComponent->angularVelocity = angularVelocity;
			newPhysicsComponent->scaleVelocity = scaleVelocity;
			m_PhysicsComponents.push_back(std::move(newPhysicsComponent));
			return true;
		}

		bool PhysicsComponentManager::DeletePhysicsComponent(const ObjectData& objectName) noexcept
		{
			if (m_PhysicsComponents.empty())
				return false;

			for (auto it = m_PhysicsComponents.begin(); it != m_PhysicsComponents.end(); it++)
			{
				if ((*it)->objectName == objectName.name)
				{
					m_PhysicsComponents.erase(it);
					return true;
				}
			}

			std::cout << "Failed to delete Velocity Component in Object " << objectName.name << ".\n";
			return false;
		}


	}
}