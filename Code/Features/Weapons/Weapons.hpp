#pragma once
#pragma once 
#include "../../Common.hpp"

namespace Base
{
	class WeaponsFeatures
	{
	public:
		void Tick()
		{
			///NoClip(m_EnableNoClip, m_NoClip);
			explosiveammo(m_Enablexplosiveammo);
			DriveItGun(m_EnableDriveItGun);
			RandomExplosionGun(m_EnableRandomExplosionGun);
			PedGun(m_EnablePedGun);
			AirstrikeGun(m_EnableAirstrikeGun);
			Explosiveammunation(m_EnableExplosiveammunation, m_Explosiveammunation_Shake, m_Explosiveammunation_damage, m_Explosiveammunation_ExplosionType, m_Explosiveammunation_Audible, m_Explosiveammunation_Visible);
			deletegun(m_EnableDeleteGun);
			unlimitedammo(m_Enableunlimitedammo);
			teleportGun(m_EnableteleportGun);
		}

		int m_Explosiveammunation_Shake = 1;
		int m_Explosiveammunation_ExplosionType = 1;
		int m_Explosiveammunation_Audible = 1;
		int m_Explosiveammunation_Visible = 1;
		float m_Explosiveammunation_damage = 1;
		bool m_Enablexplosiveammo = false;
		bool m_EnableDriveItGun = false;
		bool m_EnableRandomExplosionGun = false;
		bool m_EnablePedGun = false;
		bool m_EnableAirstrikeGun = false;
		bool m_EnableExplosiveammunation = false;
		bool m_Enableunlimitedammo = false;
		bool m_EnableteleportGun = false;
		bool m_EnableDeleteGun = false;


	private:

		//void NoClip(bool enable, float speed); 
		void explosiveammo(bool enable);
		void DriveItGun(bool enable);
		void RandomExplosionGun(bool enable);
		void PedGun(bool enable);
		void AirstrikeGun(bool enable);
		void Explosiveammunation(bool enable, int shake, float damage, int explosiontype, int audible, int invisible);
		void deletegun(bool enable);
		void unlimitedammo(bool enable);
		void teleportGun(bool enable);
	};

	inline std::unique_ptr<WeaponsFeatures> g_WeaponsFeatures;
}