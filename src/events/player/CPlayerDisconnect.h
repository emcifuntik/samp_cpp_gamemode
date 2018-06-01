
namespace Event {
	class CPlayerDisconnect: public CBase {
	public:
		CPlayerDisconnect(std::function<bool(CPlayer*, int)> callback) {
			::CPlayerManager::get().OnDisconnect(callback);
		}
	};
};
