#pragma once
#ifdef _WIN32
#include <windows.h>
#define LOG_COLOR(x, y, z)\
		inline static void x()\
		{\
			HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);\
			SetConsoleTextAttribute(hStdout, y);\
		}
#else
#define LOG_COLOR(x, y, z)\
		inline static void x()\
		{\
			wcout << z;\
		}
#endif

class Log : public CSingleton<Log>
{
	typedef void(*log_function)();
	typedef std::wostream& (*stream_function)(std::wostream&);

	std::vector<std::wostream*> streams;
	std::locale locale;
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convertor;


public:
	template<typename T>
	inline Log& Put(const T& val)
	{
		for (std::wostream* h : streams)
			(*h) << val;

		return *this;
	}

	inline Log& Put(const std::string& val)
	{
		return Put(convertor.from_bytes(val));
	}

	inline Log& Put(log_function color)
	{
		color();
		return *this;
	}

	Log& PutTime()
	{
		const time_t t = time(nullptr);
		tm _t = { 0 };
		if(!localtime_s(&_t, &t))
			Put(std::put_time<wchar_t>(&_t, L"[%H:%M:%S]"));

		return *this;
	}

	inline void AddOut(std::wostream* stream)
	{
		stream->imbue(locale);
		streams.push_back(stream);
	}

	inline void SetLocale(std::locale _locale)
	{
		locale = _locale;
	}

	// Manipulators
	LOG_COLOR(Black, 0, "\033[30m");
	LOG_COLOR(LBlack, FOREGROUND_INTENSITY, "\033[90m");

	LOG_COLOR(Red, FOREGROUND_RED, "\033[31m");
	LOG_COLOR(LRed, FOREGROUND_RED | FOREGROUND_INTENSITY, "\033[91m");
	LOG_COLOR(Green, FOREGROUND_GREEN, "\033[32m");
	LOG_COLOR(LGreen, FOREGROUND_GREEN | FOREGROUND_INTENSITY, "\033[92m");
	LOG_COLOR(Blue, FOREGROUND_BLUE, "\033[34m");
	LOG_COLOR(LBlue, FOREGROUND_BLUE | FOREGROUND_INTENSITY, "\033[94m");

	LOG_COLOR(Yellow, FOREGROUND_RED | FOREGROUND_GREEN, "\033[33m");
	LOG_COLOR(LYellow, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY, "\033[93m");
	LOG_COLOR(Magenta, FOREGROUND_RED | FOREGROUND_BLUE, "\033[35m");
	LOG_COLOR(LMagenta, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY, "\033[95m");
	LOG_COLOR(Cyan, FOREGROUND_GREEN | FOREGROUND_BLUE, "\033[36m");
	LOG_COLOR(LCyan, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY, "\033[96m");

	LOG_COLOR(White, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE, "\033[37m");
	LOG_COLOR(LWhite, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY, "\033[97m");

	inline static void Endl() {
		Instance() << std::endl << White;
	}

	// Output types
	static struct Log_Info {
		template<typename T>
		inline Log& operator<<(const T& val)
		{
			return Instance()
				.Put(Log::White)
				.Put(" ")
				.Put(val);
		}
	} Info;

	static struct Log_Error {
		template<typename T>
		inline Log& operator<<(const T& val)
		{
			return Instance()
				.Put(Log::Red)
				.Put("[Error] ")
				.Put(val);
		}
	} Error;

#ifndef NDEBUG
	static struct Log_Debug {
		template<typename T>
		inline Log& operator<<(const T& val)
		{
			return Instance()
				.Put(Log::Yellow)
				.Put("[Debug] ")
				.Put(val);
		}
	} Debug;
#else
	static struct Log_Debug {
		template<typename T>
		inline Log_Debug& operator<<(const T& val)
		{
			return *this;
		}

		inline Log_Debug& operator<<(stream_function val)
		{
			return *this;
		}
	} Debug;
#endif
	
	// Outputs
	template<typename T>
	inline Log& operator<<(const T& val)
	{
		return Put(val);
	}

	inline Log& operator<<(stream_function func)
	{
		return Put(func);
	}
};