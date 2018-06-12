#include "stdafx.h"
namespace fs = std::experimental::filesystem;

void GetIPLsInFolder(const std::string& folder, std::vector<std::string>& results) {
	for (auto & p : fs::recursive_directory_iterator(folder)) {
		std::stringstream ss;
		ss << p;
		std::string fileName = ss.str();
		if(fileName.substr(fileName.size() - 4, 4) == ".ipl")
			results.push_back(fileName);
	}
}

void Game::CGameDataLoader::LoadIPLs(const std::string & folder)
{
	std::vector<std::string> ipls;
	GetIPLsInFolder(folder, ipls);

	//TODO: IPL Loader
}
