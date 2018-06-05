#pragma once

class CCommandProcessor : public CSingleton<CCommandProcessor>
{
	size_t split(const std::string & txt, std::vector<std::string> &strs, char ch = ' ');
	std::unordered_multimap<std::string, std::variant<std::function<bool(CPlayer*, const std::vector<std::string>&)>, std::function<bool(CPlayer*, const std::string&)>, std::function<bool(CPlayer*)>>> hashMap;
public:
	bool Add(const std::string &cmd, std::function<bool(CPlayer*, const std::vector<std::string>&)> func);
	bool Add(const std::string &cmd, std::function<bool(CPlayer*, const std::string&)> func);
	bool Add(const std::string &cmd, std::function<bool(CPlayer*)> func);
	bool EmitCommand(const std::string & cmd, int playerid);
};

