#pragma once

class CCommandProcessor
{
  CCommandProcessor();
  ~CCommandProcessor();
  size_t split(const std::string & txt, std::vector<std::string> &strs, char ch = ' ');


  std::map<uint32_t, std::function<bool(CPlayer*, std::vector<std::string>)>> hashMap;
public:
  static CCommandProcessor & Get() {
    static CCommandProcessor instance;
    return instance;
  }

  uint32_t jhash(const std::string & key);
  bool Add(const std::string &cmd, std::function<bool(CPlayer*, std::vector<std::string>)> func);
  bool EmitCommand(const std::string & cmd, int playerid);
};

