#include "Logger.hpp"
#include "Util.hpp"

namespace Base
{
	Logger::Logger() {
		try {
			m_FilePath.append(std::getenv("USERPROFILE"));
			m_FilePath.append("Documents");
			m_FilePath.append(Kursed_NAME);
			if (!fs::exists(m_FilePath))
				fs::create_directory(m_FilePath);
			m_FilePath.append("Kursed.txt");
		}
		catch (fs::filesystem_error const& ex) {}
		if (!AttachConsole(GetCurrentProcessId()))
			AllocConsole();
		SetConsoleTitleA("Kursed Cheats");
		SetLayeredWindowAttributes(GetConsoleWindow(), NULL, 235, LWA_ALPHA);
		SetConsoleCP(CP_UTF8);
		SetConsoleOutputCP(CP_UTF8);
		m_Console.open("CONOUT$");
		m_Input.open("CONIN$");
		m_File.open(m_FilePath, std::ios_base::out | std::ios_base::trunc);
	}
	Logger::~Logger() {
		FreeConsole();
		m_Console.close();
		m_Input.close();
		m_File.close();
	}
}
