
namespace Event {
	class CPlayerCommand: public CBase {
	public:
		CPlayerCommand(const std::string &cmd, std::function<bool(CPlayer*, std::vector<std::string>)> func) {
			::CCommandProcessor::get().Add(cmd, func);
		}
	};
};
