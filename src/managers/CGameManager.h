#pragma once

class CGameManager : public CSingleton<CGameManager>
{
	std::vector<std::function<bool()>> initHandlers;
	std::vector<std::function<bool()>> exitHandlers;
public:

	bool Init();
	bool OnInit(std::function<bool()> callback);

	bool Exit();
	bool OnExit(std::function<bool()> callback);
};

