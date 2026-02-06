#include "System.h"

namespace SurrealStudio {

	namespace ECS {

		bool MovementSystem::Update(ComponentManager& componentManager, float deltaTime) noexcept
		{
			for (auto* component : componentManager.transformComponentManager.GetAllTransformComponents())
			{
				if (!component) return false;

				
			}
			
			return true;
		}
	}
}