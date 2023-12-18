#pragma once

namespace Base
{
	class Settings
	{
	public:
		std::atomic_bool m_LockMouse = false;
	};

	inline Settings g_Settings;
}
