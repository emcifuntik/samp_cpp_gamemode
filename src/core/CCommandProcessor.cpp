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
  uint32_t hash = jhash(command);
  auto iter = this->hashMap.find(hash);
  if (iter != this->hashMap.end()) {
    return iter->second(player, params);
  }
  else
    return false;
}

bool CCommandProcessor::Add(const std::string &cmd, std::function<bool(CPlayer*, std::vector<std::string>)> func)
{
  uint32_t hash = jhash(cmd);
  if (this->hashMap.find(hash) == this->hashMap.end()) {
    this->hashMap.insert(std::pair<uint32_t, std::function<bool(CPlayer*, std::vector<std::string>)>>(hash, func));
    return true;
  }
  return false;
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerCommandText(int playerid, const char *cmdtext) {
  return CCommandProcessor::get().EmitCommand(cmdtext, playerid);
}
