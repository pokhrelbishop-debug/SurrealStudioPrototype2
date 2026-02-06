#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <vector>

namespace SurrealStudio {

	namespace ECS {

		constexpr unsigned int MAX_OBJECTS = 5000;

		struct ObjectData
		{
			std::string name;
			int objectID;
			// later: component vector
		};

		class ObjectManager
		{
		public:

			bool CreateObject(const std::string& name) noexcept;
			bool DestroyObject(const std::string& name) noexcept;

			std::string GetObject(int index) const noexcept;
			std::vector<ObjectData*> GetAllObjects()
			{
				std::vector<ObjectData*> result;
				for (auto& ptr : m_Objects)
					result.push_back(ptr.get());
				return result;
			}
			
		private:

			std::vector<std::unique_ptr<ObjectData>> m_Objects;
			ObjectData object;
			
		};
	}
}