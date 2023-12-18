#include "Local.hpp"
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

// Features using g_LastFeatureName for example, restore only once to improve performance
// 
//VECTOR AND FLOAT FUNCTIONS
void TeleportToWaypoint() {
	Vector3 coords;
	bool blipFound = false;
	//Search for blip
	int blipIterator = HUD::GET_WAYPOINT_BLIP_ENUM_ID();
	for (Blip i = HUD::GET_FIRST_BLIP_INFO_ID(blipIterator); HUD::DOES_BLIP_EXIST(i) != 0; i = HUD::GET_NEXT_BLIP_INFO_ID(blipIterator)) {
		if (HUD::GET_BLIP_INFO_ID_TYPE(i) == 4) {
		//	coords = HUD::GET_BLIP_INFO_ID_COORD(i);
			blipFound = true;
			break;
		}
	}
}
Vector3 rot_to_direction(Vector3 rot) {
	float radiansZ = rot.z * 0.0174532924f; float radiansX = rot.x * 0.0174532924f;
	float num = abs((float)cos((double)radiansX)); Vector3 dir;
	dir.x = (float)((double)((float)(-(float)sin((double)radiansZ))) * (double)num);
	dir.y = (float)((double)((float)cos((double)radiansZ)) * (double)num);
	dir.z = (float)sin((double)radiansX);
	return dir;
}
Vector3 add(Vector3 vectorA, Vector3 vectorB) {
	Vector3 result;
	result.x = vectorA.x; result.y = vectorA.y;
	result.z = vectorA.z; result.x += vectorB.x;
	result.y += vectorB.y; result.z += vectorB.z;
	return result;
}
Vector3 multiply(Vector3 vector, float x) {
	Vector3 result;
	result.x = vector.x; result.y = vector.y;
	result.z = vector.z; result.x *= x;
	result.y *= x; result.z *= x;
	return result;
}
float get_distance(Vector3 pointA, Vector3 pointB) {
	float a_x = pointA.x; float a_y = pointA.y;
	float a_z = pointA.z; float b_x = pointB.x;
	float b_y = pointB.y; float b_z = pointB.z;
	double x_ba = (double)(b_x - a_x); double y_ba = (double)(b_y - a_y);
	double z_ba = (double)(b_z - a_z); double y_2 = y_ba * y_ba;
	double x_2 = x_ba * x_ba; double sum_2 = y_2 + x_2;
	return(float)sqrt(sum_2 + z_ba);
}
float get_vector_length(Vector3 vector) {
	double x = (double)vector.x; double y = (double)vector.y; double z = (double)vector.z;
	return(float)sqrt(x * x + y * y + z * z);
}
Vector3 GET_CAMERA_DIRECTION(float distance) {
	auto rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
	float tX = rot.x * 0.0174532924; float tZ = rot.z * 0.0174532924;
	float num = abs(cos(tX));
	Vector3 dir = { ((-sin(tZ)) * (num + distance)), (cos(tZ) * (num + distance)), (sin(tX) * 8) };
	return dir;
}
float distanceBetween(Vector3 A, Vector3 B) {
	return MISC::GET_DISTANCE_BETWEEN_COORDS(A.x, A.y, A.z, B.x, B.y, B.z, 1);
}
Vector3 wrotDirection(Vector3 rot) {
	float radianz = rot.z * 0.0174532924f; float radianx = rot.x * 0.0174532924f;
	float num = std::abs((float)std::cos((double)radianx)); Vector3 dir;
	dir.x = (float)((double)((float)(-(float)std::sin((double)radianz))) * (double)num);
	dir.y = (float)((double)((float)std::cos((double)radianz)) * (double)num);
	dir.z = (float)std::sin((double)radianx);
	return dir;
}
double wDegreeToRadian(double n) {
	return n * 0.017453292519943295;
}
Vector3 wRotationToDirection(Vector3 rot) {
	double num = wDegreeToRadian(rot.z);
	double num2 = wDegreeToRadian(rot.x);
	double val = cos(num2);
	double num3 = abs(val);
	rot.x = (float)(-(float)sin(num) * num3);
	rot.y = (float)(cos(num) * num3);
	rot.z = (float)sin(num2);
	return rot;
}
Vector3 waddVector(Vector3 vector, Vector3 vector2) {
	vector.x += vector2.x;
	vector.y += vector2.y;
	vector.z += vector2.z;
	vector.x += vector2.x;
	vector.y += vector2.y;
	vector.z += vector2.z;
	return vector;
}
Vector3 wmultiplyVector(Vector3 vector, float inc) {
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
	void LocalFeatures::SuperMan(bool enable)
	{
		if (enable)
		{
			// Disable Controls
			PAD::DISABLE_CONTROL_ACTION(0, 21, TRUE); // Sprint
			PAD::DISABLE_CONTROL_ACTION(0, 37, TRUE); // Duck

			if (!PED::IS_PED_IN_PARACHUTE_FREE_FALL(PLAYER::PLAYER_PED_ID()))
			{
				if (ENTITY::GET_ENTITY_HEIGHT_ABOVE_GROUND(PLAYER::PLAYER_PED_ID()) > 4.0f)
					TASK::TASK_SKY_DIVE(PLAYER::PLAYER_PED_ID(), TRUE);
			}

			if (ENTITY::IS_ENTITY_IN_AIR(PLAYER::PLAYER_PED_ID()) && !PED::IS_PED_RAGDOLL(PLAYER::PLAYER_PED_ID()))
			{
				if (PAD::IS_DISABLED_CONTROL_PRESSED(0, 21))
				{
					ENTITY::APPLY_FORCE_TO_ENTITY(PLAYER::PLAYER_PED_ID(), 1, 0.f, 100.0f, 100.0f, 0.f, 0.f, 0.f, TRUE, TRUE, TRUE, TRUE, FALSE, TRUE);
				}
				if (PAD::IS_DISABLED_CONTROL_PRESSED(0, 37))
				{
					ENTITY::APPLY_FORCE_TO_ENTITY(PLAYER::PLAYER_PED_ID(), 1, 0.f, -100.f, -100.0f, 0.f, 0.f, 0.f, TRUE, TRUE, TRUE, TRUE, FALSE, TRUE);
				}
			}
		}
	}

	static int g_Flip;
	int g_Speed = 6;
	void LocalFeatures::NinjaJump(bool enable)
	{
		if (enable)
		{
			if (PED::IS_PED_JUMPING(PLAYER::PLAYER_PED_ID()))
			{
				if (ENTITY::IS_ENTITY_IN_AIR(PLAYER::PLAYER_PED_ID()))
				{
					g_Flip -= g_Speed;
					if (g_Flip >= -(360 * 2))
						ENTITY::SET_ENTITY_ROTATION(PLAYER::PLAYER_PED_ID(), g_Flip, 0, ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID()), 0, 0);
				}
				else
					g_Flip = 0;
			}
		}
	}

	bool g_LastFastRun = false;
	void LocalFeatures::FastRun(bool enable)
	{
		if (enable)
			GTAUtility::GetLocalPlayerInfo()->m_run_speed = 2.5f;
		else if (enable != g_LastFastRun)
			GTAUtility::GetLocalPlayerInfo()->m_run_speed = 1.f;

		g_LastFastRun = enable;
	}

	bool g_LastFastSwim = false;
	void LocalFeatures::FastSwim(bool enable)
	{
		if (enable)
			GTAUtility::GetLocalPlayerInfo()->m_swim_speed = 2.5f;
		else if (enable != g_LastFastSwim)
			GTAUtility::GetLocalPlayerInfo()->m_swim_speed = 1.f;

		g_LastFastSwim = enable;
	}

	bool g_LastNeverWanted = false;
	void LocalFeatures::NeverWanted(bool enable)
	{
		if (enable)
		{
			GTAUtility::GetLocalPlayerInfo()->m_wanted_level = 0;
			GTAUtility::GetLocalPlayerInfo()->m_wanted_level_display = 0;
			GTAUtility::GetLocalPlayerInfo()->m_is_wanted = false;
			g_GameVariables->m_MaxWantedLevel->Apply();
			g_GameVariables->m_MaxWantedLevel2->Apply();
		}
		else if (enable != g_LastNeverWanted)
		{
			g_GameVariables->m_MaxWantedLevel->Restore();
			g_GameVariables->m_MaxWantedLevel2->Restore();
		}

		g_LastNeverWanted = enable;
	}

	bool g_LastGodMode = false;
	void LocalFeatures::GodMode(bool enable)
	{
		if (enable)
			GTAUtility::Offsets::SetValue<bool>({ 0x8, 0x189 }, true);
		else if (enable != g_LastGodMode)
			GTAUtility::Offsets::SetValue<bool>({ 0x8, 0x189 }, false);

		g_LastGodMode = enable;
	}

	void LocalFeatures::SlideRun(bool enable, float value)
	{
		if (enable)
		{
			if (PAD::IS_CONTROL_PRESSED(0, 32) && PAD::IS_CONTROL_PRESSED(0, 21) && !PED::IS_PED_RAGDOLL(PLAYER::PLAYER_PED_ID()) && PED::IS_PED_ON_FOOT(PLAYER::PLAYER_PED_ID()))
				ENTITY::APPLY_FORCE_TO_ENTITY(PLAYER::PLAYER_PED_ID(), 1, 0.f, value, 0.0f, 0.0f, 0.0f, 0.0f, FALSE, TRUE, TRUE, TRUE, FALSE, TRUE);
		}
	}

	bool g_Invisible = false;
	void LocalFeatures::Invisible(bool enable)
	{
		if (enable)
		{
			ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), false, 0);
		}
		else if (enable != g_Invisible)
		{
			ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true, 0);
		}
		g_Invisible = enable;
	}

	bool g_NoClip = false;
	void LocalFeatures::NoClip(bool enable, float speed) {
		if (enable)
		{
			Ped playerPed = PLAYER::PLAYER_PED_ID();
			auto rota = CAM::GET_GAMEPLAY_CAM_ROT(1);
			Vector3 dira = GET_CAMERA_DIRECTION(0.1);
			ENTITY::SET_ENTITY_COLLISION(playerPed, true, true);
			ENTITY::SET_ENTITY_ROTATION(playerPed, rota.x, rota.y, rota.z, 0.1, 0.1);
			auto pos1 = ENTITY::GET_ENTITY_COORDS(playerPed, false);
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos1.x, pos1.y, pos1.z, true, true, true);

			if (GetAsyncKeyState(VK_KEY_W) || PAD::IS_DISABLED_CONTROL_JUST_PRESSED(2, 269))
			{
				Vector3 pos = add({ pos1.x, pos1.y, pos1.z }, multiply(rot_to_direction({ rota.x, rota.y, rota.z }), speed));
				//Spent to much brain cell fixing this noclip PLEASE HELP ME I GET CANCER 
				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, true, true, true);
			}
		}
		g_NoClip = enable;
	}

	bool g_TinyPlayer = false;
	void LocalFeatures::Tinyplayer(bool enable)
	{
		if (enable)
		{
			PED::SET_PED_CONFIG_FLAG(PLAYER::PLAYER_PED_ID(), 223, true);
		}
		else if(enable != g_TinyPlayer)
		{
			PED::SET_PED_CONFIG_FLAG(PLAYER::PLAYER_PED_ID(), 223, false);
		}
		g_TinyPlayer = enable;
	}

}