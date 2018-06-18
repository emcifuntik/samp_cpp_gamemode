
namespace Event {
	class CRconCommand : public CBase {
	public:
		CRconCommand(const std::string &cmd, std::function<bool(const std::string&)> func) {
			::CCommandProcessor::get().AddRcon(cmd, func);
		}
	};
};
