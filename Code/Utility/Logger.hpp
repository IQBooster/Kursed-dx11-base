#pragma once
#include "../Common.hpp"

namespace Base
{
	enum class eLogColor : uint16_t {
		Black = 0,
		DarkBlue = FOREGROUND_BLUE,
		DarkGreen = FOREGROUND_GREEN,
		DarkCyan = FOREGROUND_GREEN | FOREGROUND_BLUE,
		DarkRed = FOREGROUND_RED,
		DarkMagneta = FOREGROUND_RED | FOREGROUND_BLUE,
		DarkYellow = FOREGROUND_RED | FOREGROUND_GREEN,
		DarkGray = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
		Gray = FOREGROUND_INTENSITY,
		Blue = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
		Green = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
		Cyan = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
		Red = FOREGROUND_INTENSITY | FOREGROUND_RED,
		Magneta = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
		Yellow = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
		White = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
		Grey = FOREGROUND_INTENSITY,
		LightRed = Red | FOREGROUND_INTENSITY,
		LightGreen = Green | FOREGROUND_INTENSITY,
		LightBlue = Blue | FOREGROUND_INTENSITY,
	};

	inline eLogColor operator|(eLogColor a, eLogColor b) {
		return static_cast<eLogColor>(static_cast<std::underlying_type_t<eLogColor>>(a) | static_cast<std::underlying_type_t<eLogColor>>(b));
	}

	enum class eLogType : uint8_t {
		Info,
		Warn,
		Fatal,
		Exception,
		Registers,
		Stackwalker,
		Detours,
		Success
	};

	class Logger {
	public:
		Logger();
		~Logger();

		template <typename... arguments>
		void DirectSend(eLogColor col, std::string type, std::string fmt, arguments... args) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<uint16_t>(col));
			std::string msg{ std::format("[{}] {}", type, std::vformat(fmt, std::make_format_args(args...))) };
			m_Console << msg << std::endl;
			m_File << msg << std::endl;
		}

		template <typename... arguments>
		void Send(eLogType type, std::string fmt, arguments... args) {
			switch (type) {
			case eLogType::Info: {
				this->DirectSend<arguments...>(eLogColor::Grey, "Info", fmt, args...);
			} break;
			case eLogType::Warn: {
				this->DirectSend<arguments...>(eLogColor::LightRed, "Warn", fmt, args...);
			} break;
			case eLogType::Fatal: {
				this->DirectSend<arguments...>(eLogColor::Red, "Fatal", fmt, args...);
			} break;
			case eLogType::Exception: {
				this->DirectSend<arguments...>(eLogColor::LightRed, "Exception", fmt, args...);
			} break;
			case eLogType::Registers: {
				this->DirectSend<arguments...>(eLogColor::Grey, "Registers", fmt, args...);
			} break;
			case eLogType::Stackwalker: {
				this->DirectSend<arguments...>(eLogColor::LightRed, "StackWalker", fmt, args...);
			} break;
			case eLogType::Detours: {
				this->DirectSend<arguments...>(eLogColor::Red, "Hooking", fmt, args...);
			} break;
			case eLogType::Success: {
				this->DirectSend<arguments...>(eLogColor::Green, "Success", fmt, args...);
			} break;
			default: {
			} break;
			}
		}

		std::string ReadLine() {
			std::string input;
			std::getline(m_Input, input);
			return input;
		}

	private:
		std::filesystem::path m_FilePath;
		std::ofstream m_File;
		std::ofstream m_Console;
		std::ifstream m_Input;
	};

	inline std::unique_ptr<Logger> g_Logger;
}

#define LOG(type, fmt, ...) Base::g_Logger->Send(Base::eLogType::type, fmt, __VA_ARGS__)
#define HEX_TO_UPPER(value) "0x" << std::hex << std::uppercase << (DWORD64)value << std::dec << std::nouppercase
#define logNow(type, fmt, ...) Base::g_Logger->Send(Base::eLogType::type, fmt, __VA_ARGS__)