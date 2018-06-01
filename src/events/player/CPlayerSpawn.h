
namespace Event {
	class CPlayerSpawn: public CBase {
	public:
		CPlayerSpawn(std::function<bool(CPlayer*)> callback) {
			::CPlayerManager::get().OnSpawn(callback);
		}
	};
};
