#include "World.h"

#include <iostream>

namespace SurrealStudio {

	namespace SceneSystem {

		bool World::AddWorld(const std::string& name) noexcept
		{
			auto newWorld = std::make_unique<WorldData>();
			newWorld->worldName = name;
			m_Worlds.push_back(std::move(newWorld));
			return true;
		}

		bool World::DeleteWorld(const std::string& name) noexcept
		{
			if (m_Worlds.empty())
				return false;

			for (auto it = m_Worlds.begin(); it != m_Worlds.end(); it++)
			{
				if ((*it)->worldName == name)
				{
					m_Worlds.erase(it);
					return true;
				}
			}
			
			std::cout << "Couldn't find World " << name << std::endl;
			return false;
		}
	}
}