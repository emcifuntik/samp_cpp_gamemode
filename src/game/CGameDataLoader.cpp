#include "stdafx.h"
namespace fs = std::experimental::filesystem;

void GetFilesInFolder(const std::string& folder, const std::string& extension, std::vector<std::string>& results) {
	for (auto & p : fs::recursive_directory_iterator(folder)) {
		std::stringstream ss;
		ss << p;
		std::string fileName = ss.str();
		if(fileName.substr(fileName.size() - 4, 4) == extension)
			results.push_back(fileName);
	}
}

void Game::CGameDataLoader::LoadIPLs(const std::string & folder)
{
	std::vector<std::string> ipls;
	GetFilesInFolder(folder, ".ipl", ipls);

	for (auto ipl : ipls) {
		CLoaderIPL loader(ipl);
		loader.Load();
	}
	//TODO: IPL Loader
}
