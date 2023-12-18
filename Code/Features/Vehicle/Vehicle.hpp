#pragma once 
#include "../../Common.hpp"

namespace Base
{
	class VehicleFeatures
	{
	public:
		void Tick()
		{
			SportMod(m_EnableSportMod, m_SportModSpeed);
			VehicleNoClip(m_EnableVehicleNoClip, m_VehicleNoClipSpeed);
			VehicleInvisible(m_EnableVehicleInvisible, m_VehicleAlpha);
			VehicleGodMode(m_EnableVehicleGodMode);
			CantFallOffVehicles(m_EnableVehicleCantFallOffVehicles);
			VehicleSmoothRainBow(m_EnableVehicleSmoothRainBow);
			VehicleInstantBrake(m_EnableVehicleInstantBrake);
			VehicleFixLoop(m_EnableVehicleFixLoop);
			AnimatedLicensePlate(m_EnableVehicleAnimatedLicensePlate);

		}


		bool m_EnableSportMod = false;
		float m_SportModSpeed = 1.f;

		bool m_EnableVehicleNoClip = false;
		float m_VehicleNoClipSpeed = 1.f;

		bool m_EnableVehicleInvisible = false;
		int m_VehicleAlpha = 1;

		bool m_EnableVehicleGodMode = false;

		bool m_EnableVehicleCantFallOffVehicles = false;

		bool m_EnableVehicleSmoothRainBow = false;

		bool m_EnableVehicleInstantBrake = false;

		bool m_EnableVehicleFixLoop = false;

		bool m_EnableVehicleAnimatedLicensePlate = false;

	private:

		void SportMod(bool enable, float speed);
		void VehicleNoClip(bool enable, float speed);
		void VehicleInvisible(bool enable, int alpha);
		void VehicleGodMode(bool enable);
		void CantFallOffVehicles(bool enable);
		void VehicleSmoothRainBow(bool enable);
		void VehicleInstantBrake(bool enable);
		void VehicleFixLoop(bool enable);
		void AnimatedLicensePlate(bool enable);
	};

	inline std::unique_ptr<VehicleFeatures> g_vehicleFeatures;
}