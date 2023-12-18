#pragma once 
#include "../../Common.hpp"

namespace Base
{
	class WorldFeatures
	{
	public:
		void Tick()
		{
			DeleteVehicles(m_EnableDeleteVehicles);
			ExplodeVehicles(m_EnableExplodeVehicles);
			MayhemVehicles(m_EnableMayhemVehicles);
			RainbowVehicles(m_EnableRainbowVehicles);
			MaxoutVehicles(m_EnableMaxoutVehicles);
			FixVehicles(m_EnableFixVehicles);
			HornVehicle(m_EnableHornVehicle);
			BoostVehicle(m_EnableBoostVehicle);
			LowGravityVehicles(m_EnableLowGravityVehicles);
			ArmedPed(m_EnableArmedPed);
			MayhemPed(m_EnableMayhemPed);
			DeletePed(m_EnableDeletePed);
			TpPedToWaypoint(m_EnableTpPedToWaypoint);
			ExplodePed(m_EnableExplodePed);
			threeDWaypoint(m_EnablethreeDWaypoint, m_EnablethreeDWaypointRGB, m_threeDWaypoint_red, m_threeDWaypoint_green, m_threeDWaypoint_blue, m_threeDWaypoint_scaleX, m_threeDWaypoint_scaleY, m_threeDWaypoint_scaleZ, m_threeDWaypoint_alpha, m_threeDWaypoint_blipstyle);

		}


		bool m_EnableDeleteVehicles = false;
		bool m_EnableExplodeVehicles = false;
		bool m_EnableRainbowVehicles = false;
		bool m_EnableMayhemVehicles = false;
		bool m_EnableMaxoutVehicles = false;
		bool m_EnableFixVehicles = false;
		bool m_EnableHornVehicle = false;
		bool m_EnableBoostVehicle = false;
		bool m_EnableLowGravityVehicles = false;
		bool m_EnableArmedPed = false;
		bool m_EnableMayhemPed = false;
		bool m_EnableDeletePed = false;
		bool m_EnableTpPedToWaypoint = false;
		bool m_EnableExplodePed = false;
		bool m_EnablethreeDWaypoint = false;
		bool m_EnablethreeDWaypointRGB = false;
		int m_threeDWaypoint_red = 1;
		int m_threeDWaypoint_green = 1;
		int m_threeDWaypoint_blue = 1;
		int m_threeDWaypoint_alpha = 1;
		int m_threeDWaypoint_blipstyle = 1;
		float m_threeDWaypoint_scaleX = 10;
		float m_threeDWaypoint_scaleY = 10;
		float m_threeDWaypoint_scaleZ = 260;



	private:

		//void SportMod(bool enable, float speed);
		void DeleteVehicles(bool enable);
		void ExplodeVehicles(bool enable);
		void MayhemVehicles(bool enable);
		void RainbowVehicles(bool enable);
		void MaxoutVehicles(bool enable);
		void FixVehicles(bool enable);
		void HornVehicle(bool enable);
		void BoostVehicle(bool enable);
		void LowGravityVehicles(bool enable);
		void ArmedPed(bool enable);
		void MayhemPed(bool enable);
		void DeletePed(bool enable);
		void TpPedToWaypoint(bool enable);
		void ExplodePed(bool enable);
		void threeDWaypoint(bool enable, bool enable2, int red, int green, int blue, float scaleX, float scaleY, float scaleZ, int alpha, int blipstyle);


	};

	inline std::unique_ptr<WorldFeatures> g_WorldFeatures;
}

