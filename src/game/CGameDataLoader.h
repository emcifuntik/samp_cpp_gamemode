#pragma once

namespace Game {
	class CGameDataLoader : public CSingleton<CGameDataLoader> {
	public:
		void LoadIPLs(const std::string& folder);
	};
}