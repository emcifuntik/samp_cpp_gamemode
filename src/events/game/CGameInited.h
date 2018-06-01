
namespace Event {
	class CGameInited : public CBase {
	public:
		CGameInited(std::function<bool()> callback) {
			::CGameManager::get().OnInit(callback);
		}
	};
};
