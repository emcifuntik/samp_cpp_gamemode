#pragma once

namespace Game {
	class CEnExManager : public CSingleton<CEnExManager> {
		std::vector<CEnterExit*> pool;
		std::unordered_multimap<std::string, CEnterExit*> poolByName;
	public:
		void Parse(const std::string& line);

		CEnterExit* operator[](const int& index) {
			if (index >= 0 && index < pool.size())
				return pool[index];
			return nullptr;
		}

		const std::vector<CEnterExit*>& GetVector() {
			return pool;
		}

		auto GetByName(const std::string& name) {
			return poolByName.equal_range(name);
		}

		operator size_t() const {
			return pool.size();
		}
	};
}
