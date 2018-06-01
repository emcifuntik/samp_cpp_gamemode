#pragma once

class CCommandProcessor: public CSingleton<CCommandProcessor>
{
  size_t split(const std::string & txt, std::vector<std::string> &strs, char ch = ' ');
  std::map<uint32_t, std::function<bool(CPlayer*, std::vector<std::string>)>> hashMap;
public:
  bool Add(const std::string &cmd, std::function<bool(CPlayer*, std::vector<std::string>)> func);
  bool EmitCommand(const std::string & cmd, int playerid);
};

