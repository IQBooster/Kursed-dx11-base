#include "Vehicle.hpp"
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
//really wierd
int red = 255, green = 0, blue = 0;
void RGBFADEONTICK()
{
	if (red > 0 && blue == 0) {
		red--;
		green++;
	}
	if (green > 0 && red == 0) {
		green--;
		blue++;
	}
	if (blue > 0 && green == 0) {
		red++;
		blue--;
	}
}

float vehicle_distanceBetween(Vector3 A, Vector3 B) {
	return MISC::GET_DISTANCE_BETWEEN_COORDS(A.x, A.y, A.z, B.x, B.y, B.z, 1);
}
Vector3 vehicle_rot_to_direction(Vector3 rot) {
	float radiansZ = rot.z * 0.0174532924f; float radiansX = rot.x * 0.0174532924f;
	float num = abs((float)cos((double)radiansX)); Vector3 dir;
	dir.x = (float)((double)((float)(-(float)sin((double)radiansZ))) * (double)num);
	dir.y = (float)((double)((float)cos((double)radiansZ)) * (double)num);
	dir.z = (float)sin((double)radiansX);
	return dir;
}
Vector3 vehicle_add(Vector3 vectorA, Vector3 vectorB) {
	Vector3 result;
	result.x = vectorA.x; result.y = vectorA.y;
	result.z = vectorA.z; result.x += vectorB.x;
	result.y += vectorB.y; result.z += vectorB.z;
	return result;
}
Vector3 vehicle_multiply(Vector3 vector, float x) {
	Vector3 result;
	result.x = vector.x; result.y = vector.y;
	result.z = vector.z; result.x *= x;
	result.y *= x; result.z *= x;
	return result;
}
float vehicle_get_distance(Vector3 pointA, Vector3 pointB) {
	float a_x = pointA.x; float a_y = pointA.y;
	float a_z = pointA.z; float b_x = pointB.x;
	float b_y = pointB.y; float b_z = pointB.z;
	double x_ba = (double)(b_x - a_x); double y_ba = (double)(b_y - a_y);
	double z_ba = (double)(b_z - a_z); double y_2 = y_ba * y_ba;
	double x_2 = x_ba * x_ba; double sum_2 = y_2 + x_2;
	return(float)sqrt(sum_2 + z_ba);
}
float vehicle_get_vector_length(Vector3 vector) {
	double x = (double)vector.x; double y = (double)vector.y; double z = (double)vector.z;
	return(float)sqrt(x * x + y * y + z * z);
}
Vector3 vehicle_GET_CAMERA_DIRECTION(float distance) {
	auto rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
	float tX = rot.x * 0.0174532924; float tZ = rot.z * 0.0174532924;
	float num = abs(cos(tX));
	Vector3 dir = { ((-sin(tZ)) * (num + distance)), (cos(tZ) * (num + distance)), (sin(tX) * 8) };
	return dir;
}
Vector3 vehicle_rotDirection(Vector3 rot) {
	float radianz = rot.z * 0.0174532924f; float radianx = rot.x * 0.0174532924f;
	float num = std::abs((float)std::cos((double)radianx)); Vector3 dir;
	dir.x = (float)((double)((float)(-(float)std::sin((double)radianz))) * (double)num);
	dir.y = (float)((double)((float)std::cos((double)radianz)) * (double)num);
	dir.z = (float)std::sin((double)radianx);
	return dir;
}
double vehicle_DegreeToRadian(double n) {
	return n * 0.017453292519943295;
}
Vector3 vehicle_RotationToDirection(Vector3 rot) {
	double num = vehicle_DegreeToRadian(rot.z);
	double num2 = vehicle_DegreeToRadian(rot.x);
	double val = cos(num2);
	double num3 = abs(val);
	rot.x = (float)(-(float)sin(num) * num3);
	rot.y = (float)(cos(num) * num3);
	rot.z = (float)sin(num2);
	return rot;
}
Vector3 vehicle_addVector(Vector3 vector, Vector3 vector2) {
	vector.x += vector2.x;
	vector.y += vector2.y;
	vector.z += vector2.z;
	vector.x += vector2.x;
	vector.y += vector2.y;
	vector.z += vector2.z;
	return vector;
}
Vector3 vehicle_multiplyVector(Vector3 vector, float inc) {
	vector.x *= inc;
	vector.y *= inc;
	vector.z *= inc;
	vector.x *= inc;
	vector.y *= inc;
	vector.z *= inc;
	return vector;
}

namespace Base
{
	bool g_VehicleSportMod = false;
	void VehicleFeatures::SportMod(bool enable, float speed) {
		if (enable)
		{
			Ped playerPed = PLAYER::PLAYER_PED_ID();
			auto rota = CAM::GET_GAMEPLAY_CAM_ROT(1);
			Vector3 dira = vehicle_GET_CAMERA_DIRECTION(0.1);
			ENTITY::SET_ENTITY_COLLISION(playerPed, true, true);
			ENTITY::SET_ENTITY_ROTATION(playerPed, rota.x, rota.y, rota.z, 0.1, 0.1);
			auto pos1 = ENTITY::GET_ENTITY_COORDS(playerPed, false);
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos1.x, pos1.y, pos1.z, true, true, true);

			if (GetAsyncKeyState(VK_KEY_W) || PAD::IS_DISABLED_CONTROL_JUST_PRESSED(2, 269))
			{
				Vector3 pos = vehicle_add({ pos1.x, pos1.y, pos1.z }, vehicle_multiply(vehicle_rot_to_direction({ rota.x, rota.y, rota.z }), speed));
				//Spent to much brain cell fixing this noclip PLEASE HELP ME I GET CANCER 
				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, true, true, true);
			}
		}
		g_VehicleSportMod = enable;
	}

	float yaw, rotation, pitch, roll = 0.0f;
	bool Backwardd = false;

	bool g_VehicleNoClip = false;
	void VehicleFeatures::VehicleNoClip(bool enable, float speed) {
		if (enable)
		{
			if (PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()) != NULL)
			{
				VEHICLE::SET_VEHICLE_GRAVITY(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), false);
				pitch = ENTITY::GET_ENTITY_PITCH(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()));

				float Current = ENTITY::GET_ENTITY_SPEED(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()));

				Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
				ENTITY::SET_ENTITY_COLLISION(Veh, false, false);

				if (GetAsyncKeyState(0x57)) //W key
				{
					Backwardd = false;
					ENTITY::SET_ENTITY_ROTATION(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), pitch, 0.0f, yaw, 2, true);
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), Current += speed);
				}
				else if (GetAsyncKeyState(0x53)) //S key
				{
					Backwardd = true;
					ENTITY::SET_ENTITY_ROTATION(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), pitch, 0.0f, yaw, 2, true);
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), (Current * -1.0f) - 1.0f);
				}
				else
				{
					ENTITY::SET_ENTITY_ROTATION(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), pitch, roll, yaw, 2, true);
					if (Current > speed && Backwardd)
					{
						VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), Current - 1.0f);
					}
					else
					{
						VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 0.0f);
					}
				}

				if (GetAsyncKeyState(0x41)) //A key
				{
					ENTITY::SET_ENTITY_ROTATION(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), pitch, roll, yaw += 1.0f, 2, true);
				}

				if (GetAsyncKeyState(0x44)) //D key
				{
					ENTITY::SET_ENTITY_ROTATION(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), pitch, roll, yaw -= 1.0f, 2, true);
				}

				if (GetAsyncKeyState(VK_SHIFT)) // SHIFT 
				{
					ENTITY::SET_ENTITY_ROTATION(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), pitch -= 1.0f, roll, yaw, 2, true);
				}

				if (GetAsyncKeyState(VK_CONTROL)) // CONTROL 
				{
					ENTITY::SET_ENTITY_ROTATION(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), pitch += 1.0f, roll, yaw, 2, true);
				}
			}
		}
		g_VehicleNoClip = enable;
	}

	bool g_VehicleGodMode = false;
	void VehicleFeatures::VehicleGodMode(bool enable) {
		if (enable)
		{
			Ped playerPed = PLAYER::PLAYER_PED_ID();
			Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
			BOOL DoesPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
			if (DoesPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
			{
				ENTITY::SET_ENTITY_INVINCIBLE(veh, true);
				ENTITY::SET_ENTITY_PROOFS(veh, true, true, true, true, true, true, true, true);
				VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, false);
				VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(veh, false);
				VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(veh, false);
			}
		}
		g_VehicleGodMode = enable;
	}


	bool g_VehicleInvisible = false;
	void VehicleFeatures::VehicleInvisible(bool enable, int alpha) {
		if (enable)
		{
			Ped playerPed = PLAYER::PLAYER_PED_ID();
			Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
			ENTITY::SET_ENTITY_VISIBLE(veh, false, 0);
			ENTITY::SET_ENTITY_ALPHA(veh, alpha, false);
		}
		else {
			Ped playerPed = PLAYER::PLAYER_PED_ID();
			Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
			ENTITY::SET_ENTITY_VISIBLE(veh, true, 0);
			ENTITY::SET_ENTITY_ALPHA(veh, 255, false);
		}
		g_VehicleInvisible = enable;
	}

	bool g_CantFallOffVehicles = false;
	void VehicleFeatures::CantFallOffVehicles(bool enable) {
		if (enable)
		{
			PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER::PLAYER_PED_ID(), false);
		}
		else {
			PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER::PLAYER_PED_ID(), true);
		}
		g_CantFallOffVehicles = enable;
	}


	bool g_VehicleSmoothRainbow = false;
	void VehicleFeatures::VehicleSmoothRainBow(bool enable) {
		if (enable)
		{
			RGBFADEONTICK();
			int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(VehID, red, green, blue);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(VehID, red, green, blue);
			VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(VehID, red, green, blue);
			VEHICLE::SET_VEHICLE_NEON_COLOUR(VehID, red, green, blue);

		}
		g_VehicleSmoothRainbow = enable;
	}


	bool g_VehicleInstantBrake = false;
	void VehicleFeatures::VehicleInstantBrake(bool enable) {
		if (enable)
		{
			if (GetAsyncKeyState(VK_KEY_R) || PAD::IS_DISABLED_CONTROL_JUST_PRESSED(2, 268)) {

				Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);
				NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Veh);
				if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(Veh))
				{
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(Veh, 0);
				}
			}
		}
		g_VehicleInstantBrake = enable;
	}


	bool g_VehicleFixLoop = false;
	void VehicleFeatures::VehicleFixLoop(bool enable) {
		if (enable)
		{
			Vehicle Veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
			VEHICLE::SET_VEHICLE_FIXED(Veh);
			VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(Veh);
			VEHICLE::SET_VEHICLE_DIRT_LEVEL(Veh, 0);
		}
		g_VehicleFixLoop = enable;
	}


	bool g_VehicleAnimatedLicensePlate = false;
	void VehicleFeatures::AnimatedLicensePlate(bool enable) {
		if (enable)
		{
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), "K");
			Script::Current()->Yield(80ms);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), "KU");
			Script::Current()->Yield(80ms);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), "KUR");
			Script::Current()->Yield(80ms);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), "KURS");
			Script::Current()->Yield(80ms);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), "KURSE");
			Script::Current()->Yield(80ms);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), "KURSED");
			Script::Current()->Yield(80ms);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), "URSEDK");
			Script::Current()->Yield(80ms);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), "RSEDKU");
			Script::Current()->Yield(80ms);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), "SEDKUR");
			Script::Current()->Yield(80ms);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), "EDKURS");
			Script::Current()->Yield(80ms);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), "DKURSE");
			Script::Current()->Yield(80ms);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), "KURSED");
			Script::Current()->Yield(80ms);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), "URSED");
			Script::Current()->Yield(80ms);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), "RSED");
			Script::Current()->Yield(80ms);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), "SED");
			Script::Current()->Yield(80ms);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), "ED");
			Script::Current()->Yield(80ms);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), "D");
			Script::Current()->Yield(80ms);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), "");
			Script::Current()->Yield(80ms);
		}
		g_VehicleAnimatedLicensePlate = enable;
	}

}