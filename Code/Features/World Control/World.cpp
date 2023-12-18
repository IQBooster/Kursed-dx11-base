#include "World.hpp"
#include "../../Common.hpp"
#include "../../GTA/Invoker/Natives.hpp"
#include "../../GTA/Script/ScriptGlobal.hpp"
#include "../../GTA/Script/ScriptManager.hpp"
#include "../../Utility/GTA.hpp"
#include "../../Utility/Util.hpp"
#include "../../Utility/Math.hpp"
#include "../../Utility/Enums.hpp"
#include "../../Utility/Hashes&Defines/Keyboard.hpp"
#include "../../Utility/Hashes&Defines/Hashes.hpp"
#include "../../GTA/Script/Script.hpp"

// Features using g_LastFeatureName for example, restore only once to improve performance
//VECTOR AND FLOAT FUNCTIONS
#define playerPedId	PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID())
#define randomint MISC::GET_RANDOM_INT_IN_RANGE(0, 255)
int WaypointHandle = HUD::GET_FIRST_BLIP_INFO_ID(8);
//really wierd
int red2 = 255, green2 = 0, blue2 = 0;
int red3 = 255, green3 = 0, blue3 = 0;
void RGBFADEONTICK2()
{
	if (red2 > 0 && blue2 == 0) {
		red2--;
		green2++;
	}
	if (green2 > 0 && red2 == 0) {
		green2--;
		blue2++;
	}
	if (blue2 > 0 && green2 == 0) {
		red2++;
		blue2--;
	}
}

void RGBFADEONTICK3()
{
	if (red3 > 0 && blue3 == 0) {
		red3--;
		green3++;
	}
	if (green3 > 0 && red3 == 0) {
		green3--;
		blue3++;
	}
	if (blue3 > 0 && green3 == 0) {
		red3++;
		blue3--;
	}
}
float world_distanceBetween(Vector3 A, Vector3 B) {
	return MISC::GET_DISTANCE_BETWEEN_COORDS(A.x, A.y, A.z, B.x, B.y, B.z, 1);
}
Vector3 world_rot_to_direction(Vector3 rot) {
	float radiansZ = rot.z * 0.0174532924f; float radiansX = rot.x * 0.0174532924f;
	float num = abs((float)cos((double)radiansX)); Vector3 dir;
	dir.x = (float)((double)((float)(-(float)sin((double)radiansZ))) * (double)num);
	dir.y = (float)((double)((float)cos((double)radiansZ)) * (double)num);
	dir.z = (float)sin((double)radiansX);
	return dir;
}
Vector3 world_add(Vector3 vectorA, Vector3 vectorB) {
	Vector3 result;
	result.x = vectorA.x; result.y = vectorA.y;
	result.z = vectorA.z; result.x += vectorB.x;
	result.y += vectorB.y; result.z += vectorB.z;
	return result;
}
Vector3 world_multiply(Vector3 vector, float x) {
	Vector3 result;
	result.x = vector.x; result.y = vector.y;
	result.z = vector.z; result.x *= x;
	result.y *= x; result.z *= x;
	return result;
}
float world_get_distance(Vector3 pointA, Vector3 pointB) {
	float a_x = pointA.x; float a_y = pointA.y;
	float a_z = pointA.z; float b_x = pointB.x;
	float b_y = pointB.y; float b_z = pointB.z;
	double x_ba = (double)(b_x - a_x); double y_ba = (double)(b_y - a_y);
	double z_ba = (double)(b_z - a_z); double y_2 = y_ba * y_ba;
	double x_2 = x_ba * x_ba; double sum_2 = y_2 + x_2;
	return(float)sqrt(sum_2 + z_ba);
}
float world_get_vector_length(Vector3 vector) {
	double x = (double)vector.x; double y = (double)vector.y; double z = (double)vector.z;
	return(float)sqrt(x * x + y * y + z * z);
}
Vector3 world_GET_CAMERA_DIRECTION(float distance) {
	auto rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
	float tX = rot.x * 0.0174532924; float tZ = rot.z * 0.0174532924;
	float num = abs(cos(tX));
	Vector3 dir = { ((-sin(tZ)) * (num + distance)), (cos(tZ) * (num + distance)), (sin(tX) * 8) };
	return dir;
}
Vector3 world_rotDirection(Vector3 rot) {
	float radianz = rot.z * 0.0174532924f; float radianx = rot.x * 0.0174532924f;
	float num = std::abs((float)std::cos((double)radianx)); Vector3 dir;
	dir.x = (float)((double)((float)(-(float)std::sin((double)radianz))) * (double)num);
	dir.y = (float)((double)((float)std::cos((double)radianz)) * (double)num);
	dir.z = (float)std::sin((double)radianx);
	return dir;
}
double world_DegreeToRadian(double n) {
	return n * 0.017453292519943295;
}
Vector3 world_RotationToDirection(Vector3 rot) {
	double num = world_DegreeToRadian(rot.z);
	double num2 = world_DegreeToRadian(rot.x);
	double val = cos(num2);
	double num3 = abs(val);
	rot.x = (float)(-(float)sin(num) * num3);
	rot.y = (float)(cos(num) * num3);
	rot.z = (float)sin(num2);
	return rot;
}
Vector3 world_addVector(Vector3 vector, Vector3 vector2) {
	vector.x += vector2.x;
	vector.y += vector2.y;
	vector.z += vector2.z;
	vector.x += vector2.x;
	vector.y += vector2.y;
	vector.z += vector2.z;
	return vector;
}
Vector3 world_multiplyVector(Vector3 vector, float inc) {
	vector.x *= inc;
	vector.y *= inc;
	vector.z *= inc;
	vector.x *= inc;
	vector.y *= inc;
	vector.z *= inc;
	return vector;
}
void RequestControlOfid(Entity netid)
{
	int tick = 0;

	while (!NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
		tick++;
	}
}

void RequestControlOfEnt(Entity entity)
{
	int tick = 0;
	while (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(entity) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(entity);
		tick++;
	}
	if (NETWORK::NETWORK_IS_SESSION_STARTED())
	{
		int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(entity);
		RequestControlOfid(netID);
		NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
	}
}




namespace Base
{



	bool g_worldDeleteVehicles = false;
	void WorldFeatures::DeleteVehicles(bool enable) {
		if (enable)
		{
			const int numElements = 10;
			const int arrSize = numElements * 2 + 2;
			int vehs[arrSize];
			vehs[0] = numElements;

			int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), vehs);
			for (int i = 0; i < count; ++i)
			{
				int offsettedID = i * 2 + 2;
				if (ENTITY::DOES_ENTITY_EXIST(vehs[offsettedID]))
				{
					if ((vehs[offsettedID]) == PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0)) continue;
					{
						if (VEHICLE::GET_VEHICLE_ENGINE_HEALTH(vehs[offsettedID]) > 1)
						{
							RequestControlOfEnt(vehs[offsettedID]);
							ENTITY::SET_ENTITY_COORDS(vehs[offsettedID], 6400.f, 6400.f, 0.f, false, false, false, false);
						}
					}
				}
			}
		}
		g_worldDeleteVehicles = enable;
	}

	bool g_worldExplodeVehicles = false;
	void WorldFeatures::ExplodeVehicles(bool enable) {
		if (enable)
		{
			const int numElements = 10;
			const int arrSize = numElements * 2 + 2;
			int vehs[arrSize];
			vehs[0] = numElements;

			int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), vehs);
			for (int i = 0; i < count; ++i)
			{
				int offsettedID = i * 2 + 2;
				if (ENTITY::DOES_ENTITY_EXIST(vehs[offsettedID]))
				{
					if ((vehs[offsettedID]) == PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0)) continue;
					{
						if (VEHICLE::GET_VEHICLE_ENGINE_HEALTH(vehs[offsettedID]) > 1)
						{
							NativeVector3 nearbyPedPos = ENTITY::GET_ENTITY_COORDS(vehs[offsettedID], 0);
							FIRE::ADD_EXPLOSION(nearbyPedPos.x, nearbyPedPos.y, nearbyPedPos.z, 2, 1000.f, true, false, true, false);
							FIRE::ADD_OWNED_EXPLOSION(count, nearbyPedPos.x, nearbyPedPos.y, nearbyPedPos.z, 2, 1000.f, true, false, true);
						}
					}
				}
			}
		}
		g_worldExplodeVehicles = enable;
	}

	bool g_worldMayhemVehicles = false;
	void WorldFeatures::MayhemVehicles(bool enable) {
		if (enable)
		{
			const int numElements = 10;
			const int arrSize = numElements * 2 + 2;
			int vehs[arrSize];
			vehs[0] = numElements;

			int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), vehs);
			for (int i = 0; i < count; ++i)
			{
				int offsettedID = i * 2 + 2;
				if ((vehs[offsettedID]) == PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0)) continue;
				{
					ENTITY::APPLY_FORCE_TO_ENTITY(vehs[offsettedID], 1, randomint, randomint, randomint, randomint, randomint, randomint, 0, 1, 1, 1, 0, 1);
				}
			}
		}
		g_worldMayhemVehicles = enable;
	}

	bool g_worldRainbowVehicles = false;
	void WorldFeatures::RainbowVehicles(bool enable) {
		if (enable)
		{
			const int numElements = 10;
			const int arrSize = numElements * 2 + 2;
			int vehs[arrSize];
			vehs[0] = numElements;

			int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), vehs);
			for (int i = 0; i < count; ++i)
			{
				int offsettedID = i * 2 + 2;
				if ((vehs[offsettedID]) == PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0)) continue;
				{
					RGBFADEONTICK2();
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehs[offsettedID], red2, green2, blue2);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehs[offsettedID], red2, green2, blue2);
					VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(vehs[offsettedID], red2, green2, blue2);
					VEHICLE::SET_VEHICLE_NEON_COLOUR(vehs[offsettedID], red2, green2, blue2);
				}
			}
		}
		g_worldRainbowVehicles = enable;
	}

	bool g_worldMaxoutVehicles = false;
	void WorldFeatures::MaxoutVehicles(bool enable) {
		if (enable)
		{
			const int numElements = 10;
			const int arrSize = numElements * 2 + 2;
			int vehs[arrSize];
			vehs[0] = numElements;

			int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), vehs);
			for (int i = 0; i < count; ++i)
			{
				int offsettedID = i * 2 + 2;
				if ((vehs[offsettedID]) == PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0)) continue;
				{
					if (VEHICLE::GET_VEHICLE_ENGINE_HEALTH(vehs[offsettedID]) > 1)
					{
						Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
						VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(vehicle, 0);
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						for (int i = 0; i < 50; i++)
						{
							VEHICLE::SET_VEHICLE_MOD(vehicle, i, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, i) - 1, false);
						}
						VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehicle, "Kursed");
						VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 10);
						VEHICLE::SET_VEHICLE_MOD(vehicle, 23, 10, 0);
					}
				}
			}
		}
		g_worldMaxoutVehicles = enable;
	}

	bool g_worldFixVehicles = false;
	void WorldFeatures::FixVehicles(bool enable) {
		if (enable)
		{
			const int numElements = 10;
			const int arrSize = numElements * 2 + 2;
			int vehs[arrSize];
			vehs[0] = numElements;

			int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), vehs);
			for (int i = 0; i < count; ++i)
			{
				int offsettedID = i * 2 + 2;
				if ((vehs[offsettedID]) == PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0)) continue;
				{
					if (VEHICLE::GET_VEHICLE_ENGINE_HEALTH(vehs[offsettedID]) > 1)
					{
						VEHICLE::SET_VEHICLE_FIXED(vehs[offsettedID]);
						VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(vehs[offsettedID]);
						VEHICLE::SET_VEHICLE_DIRT_LEVEL(vehs[offsettedID], 0);
					}
				}
			}
		}
		g_worldFixVehicles = enable;
	}


	bool g_worldHornVehicle = false;
	void WorldFeatures::HornVehicle(bool enable) {
		if (enable)
		{
			const int numElements = 10;
			const int arrSize = numElements * 2 + 2;
			int vehs[arrSize];
			vehs[0] = numElements;

			int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), vehs);
			for (int i = 0; i < count; ++i)
			{
				int offsettedID = i * 2 + 2;
				if (ENTITY::DOES_ENTITY_EXIST(vehs[offsettedID]))
				{
					if ((vehs[offsettedID]) == PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0)) continue;
					{
						if (VEHICLE::GET_VEHICLE_ENGINE_HEALTH(vehs[offsettedID]) > 1)
						{
							RequestControlOfEnt(vehs[offsettedID]);
							VEHICLE::START_VEHICLE_HORN(vehs[offsettedID], 5000, AUDIO::GET_VEHICLE_DEFAULT_HORN_IGNORE_MODS(vehs[offsettedID]), true);
						}
					}
				}
			}
		}
		g_worldHornVehicle = enable;
	}

	bool g_worldBoostVehicle = false;
	void WorldFeatures::BoostVehicle(bool enable) {
		if (enable)
		{
			const int numElements = 10;
			const int arrSize = numElements * 2 + 2;
			int vehs[arrSize];
			vehs[0] = numElements;

			int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), vehs);
			for (int i = 0; i < count; ++i)
			{
				int offsettedID = i * 2 + 2;
				if (ENTITY::DOES_ENTITY_EXIST(vehs[offsettedID]))
				{
					if ((vehs[offsettedID]) == PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0)) continue;
					{
						if (VEHICLE::GET_VEHICLE_ENGINE_HEALTH(vehs[offsettedID]) > 1)
						{
							RequestControlOfEnt(vehs[offsettedID]);
							VEHICLE::SET_VEHICLE_FORWARD_SPEED(vehs[offsettedID], 500);
						}
					}
				}
			}
		}
		g_worldBoostVehicle = enable;
	}

	bool g_worldLowGravityVehicles = false;
	void WorldFeatures::LowGravityVehicles(bool enable) {
		if (enable)
		{
			const int numElements = 10;
			const int arrSize = numElements * 2 + 2;
			int vehs[arrSize];
			vehs[0] = numElements;

			int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), vehs);
			for (int i = 0; i < count; ++i)
			{
				int offsettedID = i * 2 + 2;
				if (ENTITY::DOES_ENTITY_EXIST(vehs[offsettedID]))
				{
					if ((vehs[offsettedID]) == PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0)) continue;
					{
						if (VEHICLE::GET_VEHICLE_ENGINE_HEALTH(vehs[offsettedID]) > 1)
						{
							VEHICLE::SET_VEHICLE_GRAVITY(vehs[offsettedID], false);
						}
					}
				}
			}
		}

		g_worldLowGravityVehicles = enable;
	}

	bool g_worldArmedPed = false;
	void WorldFeatures::ArmedPed(bool enable) {
		if (enable)
		{
			const int ElementAmount = 10;
			const int ArrSize = ElementAmount * 2 + 2;

			Ped* peds = new Ped[ArrSize];
			peds[0] = ElementAmount;

			int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

			for (int i = 0; i < PedFound; i++)
			{
				int OffsetID = i * 2 + 2;
				RequestControlOfEnt(peds[OffsetID]);
				if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
				{
					WEAPON::GIVE_WEAPON_TO_PED(peds[OffsetID], 1470379660, 9000, false, true);
				}
			}
		}
		g_worldArmedPed = enable;
	}

	bool g_worldMayhemPed = false;
	void WorldFeatures::MayhemPed(bool enable) {
		if (enable)
		{
			const int ElementAmount = 10;
			const int ArrSize = ElementAmount * 2 + 2;

			Ped* peds = new Ped[ArrSize];
			peds[0] = ElementAmount;

			int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

			for (int i = 0; i < PedFound; i++)
			{
				int OffsetID = i * 2 + 2;
				RequestControlOfEnt(peds[OffsetID]);
				if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
				{
					ENTITY::APPLY_FORCE_TO_ENTITY(peds[OffsetID], 1, randomint, randomint, randomint, randomint, randomint, randomint, 0, 1, 1, 1, 0, 1);

				}
			}
		}
		g_worldMayhemPed = enable;
	}

	bool g_worldDeletePed = false;
	void WorldFeatures::DeletePed(bool enable) {
		if (enable)
		{
			const int ElementAmount = 10;
			const int ArrSize = ElementAmount * 2 + 2;

			Ped* peds = new Ped[ArrSize];
			peds[0] = ElementAmount;

			int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

			for (int i = 0; i < PedFound; i++)
			{
				int OffsetID = i * 2 + 2;
				RequestControlOfEnt(peds[OffsetID]);
				if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
				{
					ENTITY::SET_ENTITY_COORDS(peds[OffsetID], 6400.f, 6400.f, 0.f, false, false, false, false);
				}
			}
		}
		g_worldDeletePed = enable;
	}

	bool g_worldTpPedToWaypoint = false;
	void WorldFeatures::TpPedToWaypoint(bool enable) {
		if (enable)
		{
			const int ElementAmount = 10;
			const int ArrSize = ElementAmount * 2 + 2;

			Ped* peds = new Ped[ArrSize];
			peds[0] = ElementAmount;

			int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

			for (int i = 0; i < PedFound; i++)
			{
				int OffsetID = i * 2 + 2;
				RequestControlOfEnt(peds[OffsetID]);
				if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
				{
					if (HUD::DOES_BLIP_EXIST(WaypointHandle)) {
						NativeVector3 WaypointPos = HUD::GET_BLIP_COORDS(WaypointHandle);
						ENTITY::SET_ENTITY_COORDS(peds[OffsetID], WaypointPos.x, WaypointPos.y, WaypointPos.z + 1, 0, 0, 1, 1);
					}
				}
			}
		}
		g_worldTpPedToWaypoint = enable;
	}

	bool g_worldExplodePed = false;
	void WorldFeatures::ExplodePed(bool enable) {
		if (enable)
		{
			const int ElementAmount = 10;
			const int ArrSize = ElementAmount * 2 + 2;

			Ped* peds = new Ped[ArrSize];
			peds[0] = ElementAmount;

			int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

			for (int i = 0; i < PedFound; i++)
			{
				int OffsetID = i * 2 + 2;
				RequestControlOfEnt(peds[OffsetID]);
				if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
				{
					NativeVector3 nearbyPedPos = ENTITY::GET_ENTITY_COORDS(peds[OffsetID], 0);
					FIRE::ADD_EXPLOSION(nearbyPedPos.x, nearbyPedPos.y, nearbyPedPos.z, 2, 1000.f, true, false, true, false);
					FIRE::ADD_OWNED_EXPLOSION(PedFound, nearbyPedPos.x, nearbyPedPos.y, nearbyPedPos.z, 2, 1000.f, true, false, true);
				}
			}
		}
		g_worldExplodePed = enable;
	}

	// True  use  
	bool g_worldthreeDWaypoint = false;
	void WorldFeatures::threeDWaypoint(bool enable, bool enable2, int red, int green, int blue, float scaleX, float scaleY, float scaleZ, int alpha, int blipstyle) {
		if (enable)
		{
			if (HUD::DOES_BLIP_EXIST(WaypointHandle)) {
				NativeVector3 WaypointPos = HUD::GET_BLIP_COORDS(WaypointHandle);
				if (enable2) {
					GRAPHICS::DRAW_MARKER(blipstyle, WaypointPos.x, WaypointPos.y, WaypointPos.z - 1, 0, 0, 0, 0, 0, 0, scaleX, scaleY, scaleZ, red, green, blue, alpha, 0, 0, 2, 0, 0, 0, 0);
				}
				else {
					RGBFADEONTICK3();
					GRAPHICS::DRAW_MARKER(blipstyle, WaypointPos.x, WaypointPos.y, WaypointPos.z - 1, 0, 0, 0, 0, 0, 0, scaleX, scaleY, scaleZ, red3, green3, blue3, alpha, 0, 0, 2, 0, 0, 0, 0);
				}
			}
		}
		g_worldthreeDWaypoint = enable;
	}

}
