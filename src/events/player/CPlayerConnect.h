
namespace Event {
	class CPlayerConnect: public CBase {
	public:
		CPlayerConnect(std::function<bool(CPlayer*)> callback) {
			::CPlayerManager::get().OnConnect(callback);
		}
	};
};
