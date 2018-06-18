#include "stdafx.h"

size_t CCommandProcessor::split(const std::string & txt, std::vector<std::string>& strs, char ch)
{
	size_t pos = txt.find(ch);
	size_t initialPos = 0;
	strs.clear();

	while (pos != std::string::npos) {
		strs.push_back(txt.substr(initialPos, pos - initialPos));
		initialPos = pos + 1;

		pos = txt.find(ch, initialPos);
	}

	strs.push_back(txt.substr(initialPos, min(pos, txt.size()) - initialPos + 1));
	return strs.size();
}

bool CCommandProcessor::EmitCommand(const std::string &cmd, int playerid)
{
	std::vector<std::string> params;
	this->split(cmd, params);

	CPlayer* player = CPlayerManager::get()[playerid];

	std::string command = params.front();
	params.erase(params.begin());
	
	auto list = hashMap.equal_range(command);
	
	for (auto iter = list.first; iter != list.second; ++iter) {
		int index = iter->second.index();
		bool result = false;
		if (index == 0) {
			result = std::get<0>(iter->second)(player, params);
		}
		else if (index == 1) {
			auto spacePos = cmd.find_first_of(' ');
			if (spacePos == std::string::npos) {
				result = std::get<1>(iter->second)(player, "");
			}
			else {
				std::string paramsText = ((spacePos + 1) < cmd.size()) ? cmd.substr(spacePos + 1) : "";
				result = std::get<1>(iter->second)(player, paramsText);
			}
		}
		else if (index == 2) {
			result = std::get<2>(iter->second)(player);
		}
		if (result)
			return result;
	}
	return false;
}

bool CCommandProcessor::AddRcon(const std::string & cmd, std::function<bool(const std::string&)> func)
{
	rconMap.emplace(cmd, func);
	return true;
}

bool CCommandProcessor::EmitRconCommand(const std::string &cmd)
{
	std::vector<std::string> params;
	this->split(cmd, params);

	std::string command = params.front();
	params.erase(params.begin());

	auto list = rconMap.equal_range(command);

	for (auto iter = list.first; iter != list.second; ++iter) {
		bool result = false;
		auto spacePos = cmd.find_first_of(' ');
		if (spacePos == std::string::npos) {
			result = iter->second("");
		}
		else {
			std::string paramsText = ((spacePos + 1) < cmd.size()) ? cmd.substr(spacePos + 1) : "";
			result = iter->second( paramsText);
		}
		if (result)
			return result;
	}
	Log::Info << "RCON команда '" << command << "' не найдена" << std::endl;
	return true;
}

bool CCommandProcessor::Add(const std::string &cmd, std::function<bool(CPlayer*, const std::vector<std::string>&)> func)
{
	hashMap.emplace(cmd, func);
	return true;
}

bool CCommandProcessor::Add(const std::string &cmd, std::function<bool(CPlayer*, const std::string&)> func)
{
	hashMap.emplace(cmd, func);
	return true;
}

bool CCommandProcessor::Add(const std::string &cmd, std::function<bool(CPlayer*)> func)
{
	hashMap.emplace(cmd, func);
	return true;
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerCommandText(int playerid, const char *cmdtext) {
	return CCommandProcessor::get().EmitCommand(cmdtext, playerid);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnRconCommand(const char *cmdtext) {
	return CCommandProcessor::get().EmitRconCommand(cmdtext);
}
