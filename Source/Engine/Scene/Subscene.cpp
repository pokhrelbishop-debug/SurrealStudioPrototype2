#include "Subscene.h"
#include "World.h"

#include <iostream>

namespace SurrealStudio {

	namespace SceneSystem {

		bool Subscene::AddSubscene(const std::string& name) noexcept
		{
			auto newSubscene = std::make_unique<SubsceneData>();
			newSubscene->subsceneName = name;
            m_Subscenes.push_back(std::move(newSubscene));
			return true;
		}

        bool Subscene::DeleteSubscene(const std::string& name) noexcept
        {
            if (m_Subscenes.empty())
                return false;

            for (auto it = m_Subscenes.begin(); it != m_Subscenes.end(); ++it)
            {
                if ((*it)->subsceneName == name)
                {
                    m_Subscenes.erase(it);
                    return true; // deleted successfully
                }
            }

            // If we reach here, it was not found
            std::cout << "Couldn't find Subscene " << name << ".\n";
            return false;
        }
    }
}