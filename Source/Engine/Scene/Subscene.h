#pragma once

#include <string>
#include <vector>
#include <memory>

#include "World.h"

namespace SurrealStudio {

	namespace SceneSystem {

		struct SubsceneData
		{
			std::string subsceneName;
			std::vector<std::unique_ptr<World>> worlds;
		};

		class Subscene
		{
		public:

			Subscene() = default;
			~Subscene() = default;

			bool AddSubscene(const std::string& name) noexcept;
			bool DeleteSubscene(const std::string& name) noexcept;

			std::vector<SubsceneData*> GetAllSubscenes()
			{
				std::vector<SubsceneData*> result;
				for (auto& ptr : m_Subscenes)
					result.push_back(ptr.get());
				return result;
			}

		private:

			SubsceneData m_SubsceneData;
			std::vector<std::unique_ptr<SubsceneData>> m_Subscenes;
		};
	}
}