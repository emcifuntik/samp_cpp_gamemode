
namespace Event {
	class CPlayerCommand: public CBase {
	public:
		CPlayerCommand(const std::string &cmd, std::function<bool(CPlayer*, const std::vector<std::string>&)> func) {
			::CCommandProcessor::get().Add(cmd, func);
		}

		CPlayerCommand(const std::string &cmd, std::function<bool(CPlayer*, const std::string&)> func) {
			::CCommandProcessor::get().Add(cmd, func);
		}

		CPlayerCommand(const std::string &cmd, std::function<bool(CPlayer*)> func) {
			::CCommandProcessor::get().Add(cmd, func);
		}
	};
};
