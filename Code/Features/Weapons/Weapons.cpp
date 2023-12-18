#include "Weapons.hpp"
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
//VECTOR AND FLOAT FUNCTIONS
Hash getAmmoType(std::string ammoType) {
	static Hash ammo;
	ammo = MISC::GET_HASH_KEY(ammoType.c_str());
	WEAPON::REQUEST_WEAPON_ASSET(ammo, 1, 1);
	while (!WEAPON::HAS_WEAPON_ASSET_LOADED(ammo))
		return ammo;
}
Vector3 weapon_rot_to_direction(Vector3 rot) {
	float radiansZ = rot.z * 0.0174532924f; float radiansX = rot.x * 0.0174532924f;
	float num = abs((float)cos((double)radiansX)); Vector3 dir;
	dir.x = (float)((double)((float)(-(float)sin((double)radiansZ))) * (double)num);
	dir.y = (float)((double)((float)cos((double)radiansZ)) * (double)num);
	dir.z = (float)sin((double)radiansX);
	return dir;
}
Vector3 weapon_add(Vector3 vectorA, Vector3 vectorB) {
	Vector3 result;
	result.x = vectorA.x; result.y = vectorA.y;
	result.z = vectorA.z; result.x += vectorB.x;
	result.y += vectorB.y; result.z += vectorB.z;
	return result;
}
Vector3 weapon_multiply(Vector3 vector, float x) {
	Vector3 result;
	result.x = vector.x; result.y = vector.y;
	result.z = vector.z; result.x *= x;
	result.y *= x; result.z *= x;
	return result;
}
float weapon_get_distance(Vector3 pointA, Vector3 pointB) {
	float a_x = pointA.x; float a_y = pointA.y;
	float a_z = pointA.z; float b_x = pointB.x;
	float b_y = pointB.y; float b_z = pointB.z;
	double x_ba = (double)(b_x - a_x); double y_ba = (double)(b_y - a_y);
	double z_ba = (double)(b_z - a_z); double y_2 = y_ba * y_ba;
	double x_2 = x_ba * x_ba; double sum_2 = y_2 + x_2;
	return(float)sqrt(sum_2 + z_ba);
}
float weapon_get_vector_length(Vector3 vector) {
	double x = (double)vector.x; double y = (double)vector.y; double z = (double)vector.z;
	return(float)sqrt(x * x + y * y + z * z);
}
Vector3 weapon_GET_CAMERA_DIRECTION(float distance) {
	auto rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
	float tX = rot.x * 0.0174532924; float tZ = rot.z * 0.0174532924;
	float num = abs(cos(tX));
	Vector3 dir = { ((-sin(tZ)) * (num + distance)), (cos(tZ) * (num + distance)), (sin(tX) * 8) };
	return dir;
}
float weapon_distanceBetween(Vector3 A, Vector3 B) {
	return MISC::GET_DISTANCE_BETWEEN_COORDS(A.x, A.y, A.z, B.x, B.y, B.z, 1);
}
Vector3 weapon_wrotDirection(Vector3 rot) {
	float radianz = rot.z * 0.0174532924f; float radianx = rot.x * 0.0174532924f;
	float num = std::abs((float)std::cos((double)radianx)); Vector3 dir;
	dir.x = (float)((double)((float)(-(float)std::sin((double)radianz))) * (double)num);
	dir.y = (float)((double)((float)std::cos((double)radianz)) * (double)num);
	dir.z = (float)std::sin((double)radianx);
	return dir;
}
double weapon_wDegreeToRadian(double n) {
	return n * 0.017453292519943295;
}
Vector3 weapon_wRotationToDirection(Vector3 rot) {
	double num = weapon_wDegreeToRadian(rot.z);
	double num2 = weapon_wDegreeToRadian(rot.x);
	double val = cos(num2);
	double num3 = abs(val);
	rot.x = (float)(-(float)sin(num) * num3);
	rot.y = (float)(cos(num) * num3);
	rot.z = (float)sin(num2);
	return rot;
}
Vector3 weapon_waddVector(Vector3 vector, Vector3 vector2) {
	vector.x += vector2.x;
	vector.y += vector2.y;
	vector.z += vector2.z;
	vector.x += vector2.x;
	vector.y += vector2.y;
	vector.z += vector2.z;
	return vector;
}
Vector3 weapon_wmultiplyVector(Vector3 vector, float inc) {
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
	bool g_TeleportGun = false;
	void WeaponsFeatures::teleportGun(bool enable)
	{
		if (enable)
		{
			if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()) && PED::IS_PED_SHOOTING_IN_AREA)
			{
				NativeVector3 BulletPos;
				if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &BulletPos))
				{
					ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), BulletPos.x, BulletPos.y, BulletPos.z + 1, 0, 0, 1, 1);
				}
			}
		}
		g_TeleportGun = enable;
	}

	bool g_UnlimitedAmmo = false;
	void WeaponsFeatures::unlimitedammo(bool enable)
	{
		if (enable)
		{
			WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), true);
		}
		else
		{
			WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), false);
		}
		g_UnlimitedAmmo = enable;
	}


	bool g_DeleteGun = false;
	void WeaponsFeatures::deletegun(bool enable)
	{
		if (enable)
		{
			if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()) && PED::IS_PED_SHOOTING_IN_AREA)
			{
				NativeVector3 BulletPos;
				if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &BulletPos))
				{
					MISC::CLEAR_AREA(BulletPos.x, BulletPos.y, BulletPos.z, 5.f, false, false, false, true);
				}
			}
		}
		g_DeleteGun = enable;
	}

	bool g_explosiveammunation = false;
	void WeaponsFeatures::Explosiveammunation(bool enable, int shake, float damage, int explosiontype, int audible, int invisible)
	{
		if (enable)
		{
			if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()) && PED::IS_PED_SHOOTING_IN_AREA)
			{
				NativeVector3 BulletPos;
				if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &BulletPos))
				{
					FIRE::ADD_EXPLOSION(BulletPos.x, BulletPos.y, BulletPos.z, explosiontype, damage, audible, invisible, shake, false);
				}
			}
		}
		g_explosiveammunation = enable;
	}

	bool g_RapidFire = false;
	void rapidfire(bool enable)
	{
		/*if (enable) {
			Player playerPed = playerPedId;
			if (!PED::IS_PED_IN_ANY_VEHICLE(playerPedId, 1)) {
				PLAYER::DISABLE_PLAYER_FIRING(playerPedId, 1);
				NativeVector3 gameplayCam = CAM::GET_FINAL_RENDERED_CAM_COORD();
				 NativeVector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
				 Vector3 gameplayCamDirection = weapon_wRotationToDirection(&gameplayCamRot);
				Vector3 startCoords = weapon_waddVector(&gameplayCam, (weapon_wmultiplyVector(gameplayCamDirection, 1.0f)));
				Vector3 endCoords = weapon_waddVector(startCoords, weapon_wmultiplyVector(gameplayCamDirection, 500.0f));
				Hash weaponhash;
				WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &weaponhash, 1);
				if (PAD::IS_CONTROL_PRESSED(2, 208) || (GetKeyState(VK_LBUTTON) & 0x8000)) {
					PED::SET_PED_SHOOTS_AT_COORD(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::GET_PLAYER_INDEX()), endCoords.x, endCoords.y, endCoords.z, true);
					MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(startCoords.x, startCoords.y, startCoords.z, endCoords.x, endCoords.y, endCoords.z, 50, 1, weaponhash, playerPed, 1, 1, 0xbf800000);
				}
			}
		}
		g_RapidFire = enable;*/
	}

	bool g_Airstrike = false;
	void WeaponsFeatures::AirstrikeGun(bool enable) {
		if (enable) {
			if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID())) {
				NativeVector3 BulletPos;
				if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &BulletPos)) {
					Hash airStrike = getAmmoType("WEAPON_AIRSTRIKE_ROCKET");
					MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(BulletPos.x, BulletPos.y, BulletPos.z + 50.f, BulletPos.x, BulletPos.y, BulletPos.z, 250, 1, airStrike, PLAYER::PLAYER_PED_ID(), 1, 0, .5f);
					MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(BulletPos.x, BulletPos.y + 20.f, BulletPos.z + 50.f, BulletPos.x, BulletPos.y, BulletPos.z, 250, 1, airStrike, PLAYER::PLAYER_PED_ID(), 1, 0, .5f);
					MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(BulletPos.x + 20.f, BulletPos.y, BulletPos.z + 50.f, BulletPos.x, BulletPos.y, BulletPos.z, 250, 1, airStrike, PLAYER::PLAYER_PED_ID(), 1, 0, .5f);
				}
			}
		}
		g_Airstrike = enable;
	}

	bool g_PedGun = false;
	void WeaponsFeatures::PedGun(bool enable) {
		if (enable) {
			if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID())) {
				NativeVector3 BulletPos;
				if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &BulletPos)) {
					PED::CREATE_RANDOM_PED(BulletPos.x, BulletPos.y, BulletPos.z);
				}
			}
		}
		g_PedGun = enable;
	}

	bool g_RandomExplosionGun = false;
	void WeaponsFeatures::RandomExplosionGun(bool enable) {
		if (enable) {
			Ped PedID = PLAYER::PLAYER_PED_ID();
			NativeVector3 BulletPos;
			WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PedID, &BulletPos);
			FIRE::ADD_EXPLOSION(BulletPos.x, BulletPos.y, BulletPos.z, MISC::GET_RANDOM_INT_IN_RANGE(1, 93), 200.f, true, false, 0.f, 0);
		}
		g_RandomExplosionGun = enable;
	}

	bool g_DiveItGun = false;
	void WeaponsFeatures::DriveItGun(bool enable) {
		if (enable) {
			NativeVector3 BulletPos;
			if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &BulletPos)) {
				Vehicle shootedcar = VEHICLE::GET_CLOSEST_VEHICLE(BulletPos.x, BulletPos.y, BulletPos.z, 3.0f, 0, 70);
				Ped todelete = VEHICLE::GET_PED_IN_VEHICLE_SEAT(shootedcar, -1, true);
				if (ENTITY::DOES_ENTITY_EXIST(todelete)) {
					PED::DELETE_PED(&todelete);
					PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), shootedcar, -1);
				}
				else if (!ENTITY::DOES_ENTITY_EXIST(todelete)) {
					PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), shootedcar, -1);
				}
			}
		}
		g_DiveItGun = enable;
	}

	void WeaponsFeatures::explosiveammo(bool enable)
	{
		if (enable) {
			/*NativeVector3 CamPos = CAM::GET_GAMEPLAY_CAM_COORD();
			NativeVector3 YourPos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
			auto startDistance = weapon_distanceBetween({ CamPos.x, CamPos.y, CamPos.z }, { YourPos.x, YourPos.y, YourPos.z });
			auto endDistance = weapon_distanceBetween({ CamPos.x, CamPos.y, CamPos.z }, { YourPos.x, YourPos.y, YourPos.z });
			startDistance += 0.25;
			endDistance += 1000.0;
			if (PED::IS_PED_ON_FOOT(PLAYER::PLAYER_PED_ID()) && PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
			{
				Hash weaponAssetRocket = MISC::GET_HASH_KEY("WEAPON_RAILGUN");
				if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				{
					WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, false);
				}
				MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(weapon_add({ CamPos.x, CamPos.y, CamPos.z }, weapon_multiply(weapon_wrotDirection({ CamPos.x, CamPos.y, CamPos.z }), startDistance)).x, weapon_add({ CamPos.x, CamPos.y, CamPos.z }, weapon_multiply(weapon_wrotDirection({ CamPos.x, CamPos.y, CamPos.z }), startDistance)).y, weapon_add({ CamPos.x, CamPos.y, CamPos.z }, weapon_multiply(weapon_wrotDirection({ CamPos.x, CamPos.y, CamPos.z }), startDistance)).z, weapon_add({ CamPos.x, CamPos.y, CamPos.z }, weapon_multiply(weapon_wrotDirection({ CamPos.x, CamPos.y, CamPos.z }), endDistance)).x, weapon_add({ CamPos.x, CamPos.y, CamPos.z }, weapon_multiply(weapon_wrotDirection({ CamPos.x, CamPos.y, CamPos.z }), endDistance)).y, weapon_add({ CamPos.x, CamPos.y, CamPos.z }, weapon_multiply(weapon_wrotDirection({ CamPos.x, CamPos.y, CamPos.z }), endDistance)).z, 250, 1, weaponAssetRocket, PLAYER::PLAYER_PED_ID(), 1, 0, -1.0);
			}
		}*/
		}

	}
}