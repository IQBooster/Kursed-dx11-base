#include "MainScript.hpp"
#include "../GTA/Script/ScriptFiber.hpp"
#include "../GTA/Script/ScriptManager.hpp"
#include "Lists.hpp"
#include "../GTA/Invoker/Natives.hpp"
#include "../Utility/Timer.hpp"
#include "../Utility/CustomText.hpp"
#include "../UI/UIManager.hpp"
#include "../UI/BoolOption.hpp"
#include "../UI/ChooseOption.hpp"
#include "../UI/NumberOption.hpp"
#include "../UI/RegularOption.hpp"
#include "../UI/SubOption.hpp"
#include "../UI/RegularSubmenu.hpp"
#include "../UI/PlayerSubmenu.hpp"
#include "../Features/Local/Local.hpp"
#include "../Features/Weapons/Weapons.hpp"
#include "../Features/Vehicle/Vehicle.hpp"
#include "../Features/World Control/World.hpp"
#include "../Utility/Enums.hpp"
#include "../Utility/Hashes&Defines/Keyboard.hpp"
#include "../Utility/Hashes&Defines/Hashes.hpp"


Hash weaponsList[] = {
	0x92A27487, 0x958A4A8F, 0xF9E6AA4B, 0x84BD7BFD, 0xA2719263, 0x8BB05FD7, 0x440E4788, 0x4E875F73, 0xF9DCBF2D, 0xD8DF3C3C, 0x99B507EA, 0xDD5DF8D9, 0xDFE37640, 0x678B81B1, 0x19044EE0, 0xCD274149, 0x94117305, 0x3813FC08, // Melee
	0x1B06D571, 0xBFE256D4, 0x5EF9FEC4, 0x22D8FE39, 0x3656C8C1, 0x99AEEB3B, 0xBFD21232, 0x88374054, 0xD205520E, 0x83839C4, 0x47757124, 0xDC4DB296, 0xC1B3C3D1, 0xCB96392F, 0x97EA20B8, // Handguns
	0x13532244, 0x2BE6766B, 0x2BE6766B, 0xEFE7E2DF, 0x0A3D4D34, 0xDB1AA450, 0xBD248B55, // Submachine Guns
	0x1D073A89, 0x555AF99A, 0x7846A318, 0xE284C527, 0x9D61E50F, 0xA89CB99E, 0x3AABBBAA, 0xEF951FBB, 0x12E82D3D, // Shotguns
	0xBFEFFF6D, 0x394F415C, 0x83BF0278, 0xFAD1F1C9, 0xAF113F99, 0xC0A3098D, 0x969C3D67, 0x7F229F94, 0x84D6FAFD, 0x624FE830, // Assault Rifles
	0x9D07F764, 0x7FD62962, 0xDBBD7280, 0x61012683, // Light Machine Guns
	0x05FC3C11, 0x0C472FE2, 0xA914799, 0xC734385A, 0x6A6C02E0, // Sniper Rifles
	0xB1CA77B1, 0xA284510B, 0x4DD2DC56, 0x42BF8A85, 0x7F7497E5, 0x6D544C99, 0x63AB0442, 0x0781FE4A, // Heavy Weapons
	0x93E220BD, 0xA0973D5E, 0x24B17070, 0x2C3731D9, 0xAB564B93, 0x787F0BB, 0xBA45E8B8, 0x23C9F95C, 0xFDBC8A50, 0x497FACC3, // Throwables
	0x34A67B97, 0xFBAB5776, 0x060EC506, // Miscellaneous
	0xAF3696A1, 0x476BF155, 0xB62D1F67,// 1.46
	2441047180, 3126027122, 727643628, //Casino Hiest
	94989220, 1470379660, 2636060646, //Cayo Perico 
	//1.67 build
};
void wRequestControlOfid(Entity netid)
{
	int tick = 0;

	while (!NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
		tick++;
	}
}

void wRequestControlOfEnt(Entity entity)
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
		wRequestControlOfid(netID);
		NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
	}
}

void AllPedDoAnAnimation(const char* anim, const char* animid)
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;

	Ped* peds = new Ped[ArrSize];
	peds[0] = ElementAmount;

	int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, false);

	for (int i = 0; i < PedFound; i++)
	{
		int OffsetID = i * 2 + 2;
		wRequestControlOfEnt(peds[OffsetID]);
		if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
		{
			STREAMING::REQUEST_ANIM_DICT(anim);
			if (STREAMING::HAS_ANIM_DICT_LOADED((anim)))
			{
				TASK::TASK_PLAY_ANIM(peds[OffsetID], anim, animid, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
			}
		}
	}
}
void  AllPedDoAScenario(const char* Scenario)
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;

	Ped* peds = new Ped[ArrSize];
	peds[0] = ElementAmount;

	int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

	for (int i = 0; i < PedFound; i++)
	{
		int OffsetID = i * 2 + 2;
		wRequestControlOfEnt(peds[OffsetID]);
		if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
		{
			TASK::TASK_START_SCENARIO_IN_PLACE(peds[OffsetID], Scenario, 0, true);
		}
	}
}


namespace Base
{
	enum Submenu : std::uint32_t
	{
		Home,
		Self,
		Movement,
		Test,
		Network,
		PlayerList,
		Vehiclesub,
		Weaponssub,
		CustomExplosionGun,
		Settings,
		SettingsBar,
		SettingsOption,
		SettingsFooter,
		SettingsInput,
		SelectedPlayer,
		Debug,
		Miscellaneoussub,
		TaskAllPedAnimationSub,
		TaskAllPedScenariosub,
		WaypointSub,

	};

	void MainScript::Initialize()
	{
		using namespace UserInterface;
		Invoker::CacheHandlers(); 

		g_UiManager->AddSubmenu<RegularSubmenu>("Home", Home, [](RegularSubmenu* sub)
			{
				sub->AddOption<SubOption>("Self", nullptr, Self);
				sub->AddOption<SubOption>("Weapon", nullptr, Weaponssub);
				sub->AddOption<SubOption>("Vehicle", nullptr, Vehiclesub);
				sub->AddOption<SubOption>("Network", nullptr, Network);
				sub->AddOption<SubOption>("Miscellaneous", nullptr, Miscellaneoussub);
				sub->AddOption<SubOption>("Settings", nullptr, Settings);
				sub->AddOption<SubOption>("Debug", nullptr, Debug);
			});

		g_UiManager->AddSubmenu<RegularSubmenu>("Local", Self, [](RegularSubmenu* sub)
			{
				sub->AddOption<SubOption>("Movement", nullptr, Movement);
				sub->AddOption<BoolOption<bool>>("God Mode", nullptr, &g_LocalFeatures->m_GodMode);
				sub->AddOption<BoolOption<bool>>("Invisible", nullptr, &g_LocalFeatures->m_EnableInvisible);
				sub->AddOption<BoolOption<bool>>("Tiny Model", nullptr, &g_LocalFeatures->m_EnableTinyPlayer);
				sub->AddOption<BoolOption<bool>>("Walking No Clip", nullptr, &g_LocalFeatures->m_EnableNoClip);
				sub->AddOption<BoolOption<bool>>("Never Wanted", nullptr, &g_LocalFeatures->m_NeverWanted);

				//Option Not Boolean
				sub->AddOption<RegularOption>("Max Armor + Max Health", nullptr, [] { 
					ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 400, true);
					PED::ADD_ARMOUR_TO_PED(PLAYER::PLAYER_PED_ID(), 200); 
					});
				sub->AddOption<RegularOption>("Clean Player Model", nullptr, [] {  
					PED::CLEAR_PED_BLOOD_DAMAGE(PLAYER::PLAYER_PED_ID());
					});
				
				sub->AddOption<RegularOption>("Suicide", nullptr, [] { 
					ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 0, true);
					});
				sub->AddOption<RegularOption>("Random Outfit", nullptr, [] { 
					PED::SET_PED_RANDOM_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), true);
					});
				sub->AddOption<RegularOption>("Skip Cutscene", nullptr, [] { 
					CUTSCENE::STOP_CUTSCENE;
					CUTSCENE::STOP_CUTSCENE_IMMEDIATELY();  
					});

			});

		g_UiManager->AddSubmenu<RegularSubmenu>("Movement", Movement, [](RegularSubmenu* sub)
			{
				sub->AddOption<SubOption>("Slide Run", nullptr, rage::joaat("SlideRun"));
				sub->AddOption<BoolOption<bool>>("Super Man", nullptr, &g_LocalFeatures->m_SuperMan);
				sub->AddOption<BoolOption<bool>>("Super Jump", nullptr, &g_LocalFeatures->m_SuperJump);
				sub->AddOption<BoolOption<bool>>("Beast Jump", nullptr, &g_LocalFeatures->m_BeastJump);
				sub->AddOption<BoolOption<bool>>("Ninja Jump", nullptr, &g_LocalFeatures->m_NinjaJump);
				sub->AddOption<BoolOption<bool>>("Graceful Landing", nullptr, &g_LocalFeatures->m_GracefulLanding);
				sub->AddOption<BoolOption<bool>>("Fast Run", nullptr, &g_LocalFeatures->m_FastRun);
				sub->AddOption<BoolOption<bool>>("Fast Swim", nullptr, &g_LocalFeatures->m_FastSwim);
				
			});
		g_UiManager->AddSubmenu<RegularSubmenu>("Slide Run", rage::joaat("SlideRun"), [](RegularSubmenu* sub)
			{
				sub->AddOption<BoolOption<bool>>("Enabled", nullptr, &g_LocalFeatures->m_EnableSlideRun);
				sub->AddOption<NumberOption<float>>("Speed", nullptr, &g_LocalFeatures->m_SlideRun, 0.f, 100, 0.1f, 1);
			});
		



		g_UiManager->AddSubmenu<RegularSubmenu>("Ammunation", Weaponssub, [](RegularSubmenu* sub)
			{
				//Error Found Option calling 

				sub->AddOption<SubOption>("Custom Explosion Gun", nullptr, CustomExplosionGun);
				sub->AddOption<BoolOption<bool>>("Delete Gun", nullptr, &g_WeaponsFeatures->m_EnableDeleteGun);
				sub->AddOption<BoolOption<bool>>("Drive It Gun", nullptr, &g_WeaponsFeatures->m_EnableDriveItGun);
				sub->AddOption<BoolOption<bool>>("Random Explosion Gun", nullptr, &g_WeaponsFeatures->m_EnableRandomExplosionGun);
				sub->AddOption<BoolOption<bool>>("Ped Gun", nullptr, &g_WeaponsFeatures->m_EnablePedGun);
				sub->AddOption<BoolOption<bool>>("Airstrike Gun", nullptr, &g_WeaponsFeatures->m_EnableAirstrikeGun);
				sub->AddOption<BoolOption<bool>>("Unlmited Ammo", nullptr, &g_WeaponsFeatures->m_Enableunlimitedammo);
				sub->AddOption<BoolOption<bool>>("Teleport Gun", nullptr, &g_WeaponsFeatures->m_EnableteleportGun);
				sub->AddOption<BoolOption<bool>>("Shoot RailGun Bullet", nullptr, &g_WeaponsFeatures->m_Enablexplosiveammo);
				//sub->AddOption<BoolOption<bool>>("Enabled", nullptr, &g_WeaponsFeatures->m_EnableSlideRun);
				//Add Weapons stuff here 
				sub->AddOption<RegularOption>("Give All Weapons", nullptr, [] {
					Ped ped = PLAYER::PLAYER_PED_ID();
					for (auto weapongiven : weaponsList) {
						WEAPON::GIVE_WEAPON_TO_PED(ped, weapongiven, 9000, false, true);
					}
					//Fixing to much stuff give me cancer HELP ME PLS 
					});
				sub->AddOption<RegularOption>("Remove All Weapons", nullptr, [] {
					Ped ped = PLAYER::PLAYER_PED_ID();
					WEAPON::REMOVE_ALL_PED_WEAPONS(ped, false);
					//Fixing to much stuff give me cancer HELP ME PLS 
					});


			});
		g_UiManager->AddSubmenu<RegularSubmenu>("Custom Explosion Gun", CustomExplosionGun, [](RegularSubmenu* sub)
			{
				sub->AddOption<BoolOption<bool>>("Custom Explosion Gun", nullptr, &g_WeaponsFeatures->m_EnableExplosiveammunation);
				sub->AddOption<NumberOption<int>>("Shake Camera", nullptr, &g_WeaponsFeatures->m_Explosiveammunation_Shake, 0, 1, 0.1f, 1);
				sub->AddOption<NumberOption<int>>("Explosion type", nullptr, &g_WeaponsFeatures->m_Explosiveammunation_ExplosionType, 0, 93);
				sub->AddOption<NumberOption<int>>("Is The Explosion Audible", nullptr, &g_WeaponsFeatures->m_Explosiveammunation_Audible, 0, 1);
				sub->AddOption<NumberOption<int>>("Is The Explosion Visible", nullptr, &g_WeaponsFeatures->m_Explosiveammunation_Visible, 0, 1);
				sub->AddOption<NumberOption<float>>("Explosion Damage", nullptr, &g_WeaponsFeatures->m_Explosiveammunation_damage, 0.f, 10.f, 0.1f, 1);
			});




		g_UiManager->AddSubmenu<RegularSubmenu>("Vehicle", Vehiclesub, [](RegularSubmenu* sub)
			{
				sub->AddOption<BoolOption<bool>>("God Mode", nullptr, &g_vehicleFeatures->m_EnableVehicleGodMode);
				sub->AddOption<BoolOption<bool>>("Invisibility", nullptr, &g_vehicleFeatures->m_EnableVehicleInvisible);
				sub->AddOption<NumberOption<int>>("Invisibility Alpha", nullptr, &g_vehicleFeatures->m_VehicleAlpha, 0, 255, 1, 1);
				sub->AddOption<BoolOption<bool>>("Noclip", nullptr, &g_vehicleFeatures->m_EnableVehicleNoClip);
				sub->AddOption<NumberOption<float>>("Noclip Speed", nullptr, &g_vehicleFeatures->m_VehicleNoClipSpeed, 0.f, 100, 0.1f, 1);
				sub->AddOption<BoolOption<bool>>("Sport Mode", nullptr, &g_vehicleFeatures->m_EnableVehicleInvisible);
				sub->AddOption<NumberOption<float>>("Sport Mode Speed", nullptr, &g_vehicleFeatures->m_SportModSpeed, 0.f, 100, 0.1f, 1);
				sub->AddOption<BoolOption<bool>>("Seat Belt", nullptr, &g_vehicleFeatures->m_EnableVehicleCantFallOffVehicles);
				sub->AddOption<BoolOption<bool>>("RainBow", nullptr, &g_vehicleFeatures->m_EnableVehicleSmoothRainBow);
				sub->AddOption<BoolOption<bool>>("Instant Brake", nullptr, &g_vehicleFeatures->m_EnableVehicleInstantBrake);
				sub->AddOption<BoolOption<bool>>("Fix Loop", nullptr, &g_vehicleFeatures->m_EnableVehicleFixLoop);
				sub->AddOption<BoolOption<bool>>("Animated License Plate", nullptr, &g_vehicleFeatures->m_EnableVehicleAnimatedLicensePlate);
				sub->AddOption<RegularOption>("Set Vehicle Properly On The Ground", nullptr, [] {
					VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), 0.f);
					});
				sub->AddOption<RegularOption>("Open All Doors", nullptr, [] {
					VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 0, true, false);
					VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 1, true, false);
					VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 2, true, false);
					VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 3, true, false);
					VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 4, true, false);
					VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 5, true, false);
					VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 6, true, false);
					VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 7, true, false);
					});
				sub->AddOption<RegularOption>("Close All Doors", nullptr, [] {
					VEHICLE::SET_VEHICLE_DOORS_SHUT(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), true);
					});
				sub->AddOption<RegularOption>("Set License Plate To Kursed", nullptr, [] {
					Ped playerPed = PLAYER::PLAYER_PED_ID();
					auto veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
					VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, "Kursed");
					});
				sub->AddOption<RegularOption>("Repair Vehicle", nullptr, [] {
					auto veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
					VEHICLE::SET_VEHICLE_FIXED(veh);
					VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(veh);
					VEHICLE::SET_VEHICLE_DIRT_LEVEL(veh, 0);

					});
				sub->AddOption<RegularOption>("Wash Vehicle", nullptr, [] {
					Ped playerPed = PLAYER::PLAYER_PED_ID();
					GRAPHICS::WASH_DECALS_FROM_VEHICLE(PED::GET_VEHICLE_PED_IS_IN(playerPed, 0), 100.0f);
					});
				sub->AddOption<RegularOption>("Add Ramp", nullptr, [] {
					if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
					{
						NativeVector3 You = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
						int VehicleID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true);
						STREAMING::REQUEST_MODEL(3681122061);
						if (STREAMING::HAS_MODEL_LOADED(3681122061))
						{
							Entity My_Objects = OBJECT::CREATE_OBJECT(3681122061, You.x, You.y, You.z, 1, 1, 0);
							if (ENTITY::DOES_ENTITY_EXIST(My_Objects))
							{
								ENTITY::SET_ENTITY_COLLISION(My_Objects, true, true);
								ENTITY::SET_ENTITY_ALPHA(My_Objects, 120, false);
								ENTITY::ATTACH_ENTITY_TO_ENTITY(My_Objects, VehicleID, 0, 0, 6.3, -0.3, 13.5, 0, 177.5, 0, 0, true, 0, 2, 1, 0);
							}
						}
					}
					});
			});

		g_UiManager->AddSubmenu<RegularSubmenu>("Custom 3D Waypoint", WaypointSub, [](RegularSubmenu* sub)
			{
				sub->AddOption<BoolOption<bool>>("Enable 3D Waypoint", nullptr, &g_WorldFeatures->m_EnablethreeDWaypoint);
				sub->AddOption<BoolOption<bool>>("Enable RGB Waypoint", nullptr, &g_WorldFeatures->m_EnablethreeDWaypointRGB);
				sub->AddOption<NumberOption<int>>("Change The Color Red", nullptr, &g_WorldFeatures->m_threeDWaypoint_red, 0, 255);
				sub->AddOption<NumberOption<int>>("Change The Color Green", nullptr, &g_WorldFeatures->m_threeDWaypoint_green, 0, 255);
				sub->AddOption<NumberOption<int>>("Change The Color Blue", nullptr, &g_WorldFeatures->m_threeDWaypoint_blue, 0, 255);
				sub->AddOption<NumberOption<int>>("Change The Waypoint Style", nullptr, &g_WorldFeatures->m_threeDWaypoint_blipstyle, 0, 33);
				sub->AddOption<NumberOption<int>>("Change The Transparency", nullptr, &g_WorldFeatures->m_threeDWaypoint_alpha, 0, 255);
				sub->AddOption<NumberOption<float>>("Change Scalling Position X", nullptr, &g_WorldFeatures->m_threeDWaypoint_scaleX, 0.f, 20.f, 0.1f, 1);
				sub->AddOption<NumberOption<float>>("Change Scalling Position Y", nullptr, &g_WorldFeatures->m_threeDWaypoint_scaleY, 0.f, 20.f, 0.1f, 1);
				sub->AddOption<NumberOption<float>>("Change Scalling Position Z", nullptr, &g_WorldFeatures->m_threeDWaypoint_scaleZ, 0.f, 300.f, 0.1f, 1);
			});

		g_UiManager->AddSubmenu<RegularSubmenu>("Animation For All Pedestrian", TaskAllPedAnimationSub, [](RegularSubmenu* sub)
			{
				sub->AddOption<RegularOption>("Pole Dance", nullptr, [] { AllPedDoAnAnimation("mini@strip_club@pole_dance@pole_dance1", "pd_dance_01"); });
				sub->AddOption<RegularOption>("Push Ups", nullptr, [] { AllPedDoAnAnimation("amb@world_human_push_ups@male@base", "base"); });
				sub->AddOption<RegularOption>("Sit Ups", nullptr, [] { AllPedDoAnAnimation("amb@world_human_sit_ups@male@base", "base"); });
				sub->AddOption<RegularOption>("Meditation", nullptr, [] { AllPedDoAnAnimation("rcmcollect_paperleadinout@", "meditiate_idle"); });
				sub->AddOption<RegularOption>("On Fire", nullptr, [] { AllPedDoAnAnimation("random@arrests", "kneeling_arrest_idle"); });
				sub->AddOption<RegularOption>("Celebrate", nullptr, [] { AllPedDoAnAnimation("rcmfanatic1celebrate", "celebrate"); });
				sub->AddOption<RegularOption>("Electrocution", nullptr, [] { AllPedDoAnAnimation("ragdoll@human", "electrocute"); });
				sub->AddOption<RegularOption>("Suicide", nullptr, [] { AllPedDoAnAnimation("mp_suicide", "pistol"); });
				sub->AddOption<RegularOption>("Showering", nullptr, [] { AllPedDoAnAnimation("mp_safehouseshower@male@", "male_shower_idle_b"); });
				sub->AddOption<RegularOption>("Sex Receiver", nullptr, [] { AllPedDoAnAnimation("rcmpaparazzo_2", "shag_loop_poppy"); });
				sub->AddOption<RegularOption>("Sex Giver", nullptr, [] { AllPedDoAnAnimation("rcmpaparazzo_2", "shag_loop_a"); });
				sub->AddOption<RegularOption>("Stripper Dance", nullptr, [] { AllPedDoAnAnimation("mini@strip_club@private_dance@part1", "priv_dance_p1"); });
				sub->AddOption<RegularOption>("Freak Out", nullptr, [] { AllPedDoAnAnimation("missfbi5ig_30monkeys", "monkey_b_freakout_loop"); });
				sub->AddOption<RegularOption>("Poop", nullptr, [] { AllPedDoAnAnimation("missfbi3ig_0", "shit_loop_trev"); });
				sub->AddOption<RegularOption>("Arm Wrestling Face B", nullptr, [] { AllPedDoAnAnimation("mini@arm_wrestling", "nuetral_idle_b_face"); });
				sub->AddOption<RegularOption>("Arm Wrestling Face A", nullptr, [] { AllPedDoAnAnimation("mini@arm_wrestling", "nuetral_idle_a_face"); });
				sub->AddOption<RegularOption>("Arm Wrestling Face Win B", nullptr, [] { AllPedDoAnAnimation("mini@arm_wrestling", "win_b_ped_b_face"); });
				sub->AddOption<RegularOption>("Arm Wrestling Face Win A", nullptr, [] { AllPedDoAnAnimation("mini@arm_wrestling", "win_a_ped_b_face"); });
				sub->AddOption<RegularOption>("Security Guard Idle", nullptr, [] { AllPedDoAnAnimation("anim@move_m@security_guard", "idle"); });
				sub->AddOption<RegularOption>("Security Guard Idle 2", nullptr, [] { AllPedDoAnAnimation("anim@move_m@security_guard", "idle_var_05"); });
				sub->AddOption<RegularOption>("Security Guard Idle 3", nullptr, [] { AllPedDoAnAnimation("anim@move_m@security_guard", "idle_var_01"); });
				sub->AddOption<RegularOption>("Dart Throw", nullptr, [] { AllPedDoAnAnimation("anim@amb@clubhouse@mini@darts@", "throw_idle_a_down"); });
				sub->AddOption<RegularOption>("Dart Outro", nullptr, [] { AllPedDoAnAnimation("anim@amb@clubhouse@mini@darts@", "outro"); });
				sub->AddOption<RegularOption>("Wary Loop", nullptr, [] { AllPedDoAnAnimation("mp_am_hold_up", "WARY_LOOP"); });
				sub->AddOption<RegularOption>("Beast Transformation", nullptr, [] { AllPedDoAnAnimation("ANIM@MP_FM_EVENT@INTRO", "BEAST_TRANSFORM"); });
				sub->AddOption<RegularOption>("Park Attendant", nullptr, [] { AllPedDoAnAnimation("amb@world_human_car_park_attendant@male@base", "base"); });
				sub->AddOption<RegularOption>("Robbery worried", nullptr, [] { AllPedDoAnAnimation("random@robbery", "stand_worried_female"); });
				sub->AddOption<RegularOption>("Robbery Flee", nullptr, [] { AllPedDoAnAnimation("random@robbery", "exit_flee"); });
				sub->AddOption<RegularOption>("Robbery Distressed", nullptr, [] { AllPedDoAnAnimation("random@robbery", "f_distressed_loop"); });
				sub->AddOption<RegularOption>("Robbery Kneel", nullptr, [] { AllPedDoAnAnimation("random@shop_robbery", "kneel_loop_p"); });
				sub->AddOption<RegularOption>("Robbery Action P", nullptr, [] { AllPedDoAnAnimation("random@shop_robbery", "robbery_action_p"); });
				sub->AddOption<RegularOption>("Monkey Dance", nullptr, [] { AllPedDoAnAnimation("missfbi5ig_30monkeys", "monkey_a_freakout_loop"); });
			});

		g_UiManager->AddSubmenu<RegularSubmenu>("Scenario For All Pedestrian", TaskAllPedScenariosub, [](RegularSubmenu* sub)
			{
				sub->AddOption<RegularOption>("Paparizzi", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_PAPARAZZI"); });

				sub->AddOption<RegularOption>("Drug Dealer", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_DRUG_DEALER_HARD"); });

				sub->AddOption<RegularOption>("Drinking Coffee", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_AA_COFFEE"); });

				sub->AddOption<RegularOption>("Playing Instruments", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_MUSICIAN"); });

				sub->AddOption<RegularOption>("Flexing", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_MUSCLE_FLEX"); });

				sub->AddOption<RegularOption>("Jogging", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_JOG_STANDING"); });

				sub->AddOption<RegularOption>("Binoculars", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_BINOCULARS"); });

				sub->AddOption<RegularOption>("Clipboard", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_CLIPBOARD"); });

				sub->AddOption<RegularOption>("Bench Press", nullptr, [] { AllPedDoAScenario("PROP_HUMAN_SEAT_MUSCLE_BENCH_PRESS"); });

				sub->AddOption<RegularOption>("Chin Ups", nullptr, [] { AllPedDoAScenario("PROP_HUMAN_MUSCLE_CHIN_UPS"); });

				sub->AddOption<RegularOption>("BBQ", nullptr, [] { AllPedDoAScenario("PROP_HUMAN_BBQ"); });

				sub->AddOption<RegularOption>("Superhero", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_SUPERHERO"); });

				sub->AddOption<RegularOption>("Fishing", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_STAND_FISHING"); });

				sub->AddOption<RegularOption>("Security", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_SECURITY_SHINE_TORCH"); });

				sub->AddOption<RegularOption>("Leaf Blower", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_GARDENER_LEAF_BLOWER"); });

				sub->AddOption<RegularOption>("Film Shocking", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_MOBILE_FILM_SHOCKING"); });

				sub->AddOption<RegularOption>("Idle Cop", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_COP_IDLES"); });

				sub->AddOption<RegularOption>("Drinking", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_DRINKING"); });

				sub->AddOption<RegularOption>("Golf Player", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_GOLF_PLAYER"); });

				sub->AddOption<RegularOption>("Welding", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_WELDING"); });

				sub->AddOption<RegularOption>("Smoking Pot", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_SMOKING_POT"); });

				sub->AddOption<RegularOption>("Hammering", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_HAMMERING"); });

				sub->AddOption<RegularOption>("Tennis", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_TENNIS_PLAYER"); });

				sub->AddOption<RegularOption>("Drilling", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_CONST_DRILL"); });

				sub->AddOption<RegularOption>("Seat Armchair", nullptr, [] { AllPedDoAScenario("PROP_HUMAN_SEAT_ARMCHAIR"); });

				sub->AddOption<RegularOption>("Seat Bar Chair", nullptr, [] { AllPedDoAScenario("PROP_HUMAN_SEAT_BAR"); });

				sub->AddOption<RegularOption>("Seat Bench", nullptr, [] { AllPedDoAScenario("PROP_HUMAN_SEAT_BENCH"); });

				sub->AddOption<RegularOption>("Seat Sun Lounger", nullptr, [] { AllPedDoAScenario("PROP_HUMAN_SEAT_SUNLOUNGER"); });

				sub->AddOption<RegularOption>("Seat Chair", nullptr, [] { AllPedDoAScenario("PROP_HUMAN_SEAT_CHAIR"); });

				sub->AddOption<RegularOption>("Fixing Vehicle", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_VEHICLE_MECHANIC"); });

				sub->AddOption<RegularOption>("Yoga", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_YOGA"); });

				sub->AddOption<RegularOption>("Medic Time Of Death", nullptr, [] { AllPedDoAScenario("CODE_HUMAN_MEDIC_TIME_OF_DEATH"); });

				sub->AddOption<RegularOption>("Tourist Map", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_TOURIST_MAP"); });

				sub->AddOption<RegularOption>("Police Investigate", nullptr, [] { AllPedDoAScenario("CODE_HUMAN_POLICE_INVESTIGATE"); });

				sub->AddOption<RegularOption>("Partying", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_PARTYING"); });

				sub->AddOption<RegularOption>("Prostitute", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_PROSTITUTE_HIGH_CLASS"); });

				sub->AddOption<RegularOption>("Sleeping", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_BUM_SLUMPED"); });

				sub->AddOption<RegularOption>("Sleepy [Human]", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_STUPOR"); });

				sub->AddOption<RegularOption>("Stand Mobile", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_STAND_MOBILE"); });

				sub->AddOption<RegularOption>("Stand Impatient", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_STAND_IMPATIENT"); });

				sub->AddOption<RegularOption>("Hang out", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_HANG_OUT_STREET"); });

				sub->AddOption<RegularOption>("Gardening", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_GARDENER_PLANT"); });

				sub->AddOption<RegularOption>("Free Weights", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_MUSCLE_FREE_WEIGHTS"); });

				sub->AddOption<RegularOption>("Jog Standing", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_JOG_STANDING"); });

				sub->AddOption<RegularOption>("Bum Freeway", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_BUM_FREEWAY"); });

				sub->AddOption<RegularOption>("Bum Standing", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_BUM_STANDING"); });

				sub->AddOption<RegularOption>("Prostitute 2", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_PROSTITUTE_LOW_CLASS"); });

				sub->AddOption<RegularOption>("Browse shop", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_WINDOW_SHOP_BROWSE"); });

				sub->AddOption<RegularOption>("Picnic", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_PICNIC"); });

				sub->AddOption<RegularOption>("Golf", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_GOLF_PLAYER"); });

				sub->AddOption<RegularOption>("Tend To Dead", nullptr, [] { AllPedDoAScenario("CODE_HUMAN_MEDIC_TEND_TO_DEAD"); });

				sub->AddOption<RegularOption>("Cleaning", nullptr, [] { AllPedDoAScenario("WORLD_HUMAN_MAID_CLEAN"); });

				sub->AddOption<RegularOption>("Boar Grazing", nullptr, [] { AllPedDoAScenario("WORLD_BOAR_GRAZING"); });

				sub->AddOption<RegularOption>("Cow Grazin", nullptr, [] { AllPedDoAScenario("WORLD_COW_GRAZING"); });

				sub->AddOption<RegularOption>("Pig Grazing", nullptr, [] { AllPedDoAScenario("WORLD_PIG_GRAZING"); });

				sub->AddOption<RegularOption>("Deer Grazing", nullptr, [] { AllPedDoAScenario("WORLD_DEER_GRAZING"); });

				sub->AddOption<RegularOption>("Sleepy [Cat]", nullptr, [] { AllPedDoAScenario("WORLD_CAT_SLEEPING_GROUND"); });

				sub->AddOption<RegularOption>("Rottweiler Bark", nullptr, [] { AllPedDoAScenario("WORLD_DOG_BARKING_ROTTWEILER"); });

				sub->AddOption<RegularOption>("Golden Retriever Bark", nullptr, [] { AllPedDoAScenario("WORLD_DOG_BARKING_RETRIEVER"); });

				sub->AddOption<RegularOption>("German Shepherd Bark", nullptr, [] { AllPedDoAScenario("WORLD_DOG_BARKING_SHEPHERD"); });

				sub->AddOption<RegularOption>("Coyote Howl", nullptr, [] { AllPedDoAScenario("WORLD_COYOTE_HOWL"); });

				sub->AddOption<RegularOption>("Coyote Walks", nullptr, [] { AllPedDoAScenario("WORLD_COYOTE_WANDER"); });

				sub->AddOption<RegularOption>("ChickenHawk Feeding", nullptr, [] { AllPedDoAScenario("WORLD_CHICKENHAWK_FEEDING"); });

				sub->AddOption<RegularOption>("Montain Lion Rest", nullptr, [] { AllPedDoAScenario("WORLD_MOUNTAIN_LION_REST"); });

				sub->AddOption<RegularOption>("Montain Lion Walks", nullptr, [] { AllPedDoAScenario("WORLD_MOUNTAIN_LION_WANDER"); });
			});

		g_UiManager->AddSubmenu<RegularSubmenu>("Miscellaneous", Miscellaneoussub, [](RegularSubmenu* sub)
			{
				sub->AddOption<SubOption>("Custom 3D Waypoint", nullptr, WaypointSub);
				sub->AddOption<SubOption>("Animation For All Pedestrian", nullptr, TaskAllPedAnimationSub);
				sub->AddOption<SubOption>("Scenario For All Pedestrian", nullptr, TaskAllPedScenariosub);

				sub->AddOption<BoolOption<bool>>("Delete All Vehicle", nullptr, &g_WorldFeatures->m_EnableDeleteVehicles);
				sub->AddOption<BoolOption<bool>>("Explode All Vehicle", nullptr, &g_WorldFeatures->m_EnableExplodeVehicles);
				sub->AddOption<BoolOption<bool>>("Smooth Rainbow Vehicle", nullptr, &g_WorldFeatures->m_EnableRainbowVehicles);
				sub->AddOption<BoolOption<bool>>("Mayhem Vehicle", nullptr, &g_WorldFeatures->m_EnableMayhemVehicles);
				sub->AddOption<BoolOption<bool>>("Max Upgrade All Vehicle", nullptr, &g_WorldFeatures->m_EnableMaxoutVehicles);
				sub->AddOption<BoolOption<bool>>("Fix All Vehicle", nullptr, &g_WorldFeatures->m_EnableFixVehicles);
				sub->AddOption<BoolOption<bool>>("Make All Vehicle Use There Horn", nullptr, &g_WorldFeatures->m_EnableHornVehicle);
				sub->AddOption<BoolOption<bool>>("Boost All Vehicle", nullptr, &g_WorldFeatures->m_EnableBoostVehicle);
				sub->AddOption<BoolOption<bool>>("Low Gravity For All Vehicle", nullptr, &g_WorldFeatures->m_EnableLowGravityVehicles);


				sub->AddOption<BoolOption<bool>>("Give A Weapon To All Pedestrian", nullptr, &g_WorldFeatures->m_EnableArmedPed);
				sub->AddOption<BoolOption<bool>>("Mayhem All Pedestrian", nullptr, &g_WorldFeatures->m_EnableMayhemPed);
				sub->AddOption<BoolOption<bool>>("Delete All Pedestrian", nullptr, &g_WorldFeatures->m_EnableDeletePed);
				sub->AddOption<BoolOption<bool>>("Teleport All Pedestrian To Your Waypoint", nullptr, &g_WorldFeatures->m_EnableTpPedToWaypoint);
				sub->AddOption<BoolOption<bool>>("Explode All Pedestrian", nullptr, &g_WorldFeatures->m_EnableExplodePed);
				sub->AddOption<RegularOption>("Create Ped", nullptr, [] {
					NativeVector3 pos = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0.0, 3.0, 0.0);
					PED::CREATE_RANDOM_PED(pos.x, pos.y, pos.z);
					});
				sub->AddOption<RegularOption>("Jump", nullptr, [] { // PedInvincible1 TASK_GO_TO_COORD_ANY_MEANS
					{
						const int ElementAmount = 10;
						const int ArrSize = ElementAmount * 2 + 2;

						Ped* peds = new Ped[ArrSize];
						peds[0] = ElementAmount;

						int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

						for (int i = 0; i < PedFound; i++)
						{
							int OffsetID = i * 2 + 2;
							wRequestControlOfEnt(peds[OffsetID]);
							if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
							{
								TASK::TASK_JUMP(peds[OffsetID], true, true, true);
							}
						}
					}
					});
				sub->AddOption<RegularOption>("Drive To Waypoint", nullptr, [] {
					{
						int WaypointHandle = HUD::GET_FIRST_BLIP_INFO_ID(8);
						Ped Driver = PLAYER::PLAYER_PED_ID();
						NativeVector3 waypoint1 = HUD::GET_BLIP_COORDS(WaypointHandle);
						const int ElementAmount = 10;
						const int ArrSize = ElementAmount * 2 + 2;

						Ped* peds = new Ped[ArrSize];
						peds[0] = ElementAmount;

						int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

						for (int i = 0; i < PedFound; i++)
						{
							int OffsetID = i * 2 + 2;
							wRequestControlOfEnt(peds[OffsetID]);
						}
						for (int i = 0; i < PedFound; i++)
						{
							int OffsetID = i * 2 + 2;
							wRequestControlOfEnt(peds[OffsetID]);
							auto veh = PED::GET_VEHICLE_PED_IS_USING(peds[OffsetID]);
							if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
							{
								TASK::TASK_VEHICLE_DRIVE_TO_COORD(peds[OffsetID], veh, waypoint1.x, waypoint1.y, waypoint1.z, 40, 1, ENTITY::GET_ENTITY_MODEL(veh), 7, 6, -1);
							}
						}
					}
					});
				sub->AddOption<RegularOption>("Hands Up", nullptr, [] {
					{
						const int ElementAmount = 10;
						const int ArrSize = ElementAmount * 2 + 2;

						Ped* peds = new Ped[ArrSize];
						peds[0] = ElementAmount;

						int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

						for (int i = 0; i < PedFound; i++)
						{
							int OffsetID = i * 2 + 2;
							wRequestControlOfEnt(peds[OffsetID]);
							if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
							{
								TASK::TASK_HANDS_UP(peds[OffsetID], 10000, PLAYER::PLAYER_PED_ID(), true, true);
							}
						}
					}
					});
				sub->AddOption<RegularOption>("Stand Still", nullptr, [] {
					{
						const int ElementAmount = 10;
						const int ArrSize = ElementAmount * 2 + 2;

						Ped* peds = new Ped[ArrSize];
						peds[0] = ElementAmount;

						int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

						for (int i = 0; i < PedFound; i++)
						{
							int OffsetID = i * 2 + 2;
							wRequestControlOfEnt(peds[OffsetID]);
							if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
							{
								TASK::TASK_STAND_STILL(peds[OffsetID], 10000);
							}
						}
					}
					});
				sub->AddOption<RegularOption>("Exit Vehicles", nullptr, [] {
					{
						const int ElementAmount = 10;
						const int ArrSize = ElementAmount * 2 + 2;

						Ped* peds = new Ped[ArrSize];
						peds[0] = ElementAmount;

						int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

						for (int i = 0; i < PedFound; i++)
						{
							int OffsetID = i * 2 + 2;
							wRequestControlOfEnt(peds[OffsetID]);
							if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
							{
								TASK::TASK_LEAVE_ANY_VEHICLE(peds[OffsetID], true, true);
							}
						}
					}

					});
				sub->AddOption<RegularOption>("Kill", nullptr, [] {
					{
						const int ElementAmount = 10;
						const int ArrSize = ElementAmount * 2 + 2;

						Ped* peds = new Ped[ArrSize];
						peds[0] = ElementAmount;

						int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

						for (int i = 0; i < PedFound; i++)
						{
							int OffsetID = i * 2 + 2;
							wRequestControlOfEnt(peds[OffsetID]);
							if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
							{
								PED::APPLY_DAMAGE_TO_PED(peds[OffsetID], 1000, false, 0);
							}
						}
					}
					});


			});

		
		g_UiManager->AddSubmenu<RegularSubmenu>("Network", Network, [](RegularSubmenu* sub)
			{
				sub->AddOption<SubOption>("Playerlist", nullptr, PlayerList);
			});

		g_UiManager->AddSubmenu<RegularSubmenu>("Players", PlayerList, [](RegularSubmenu* sub)
			{
				if (*g_GameVariables->m_IsSessionStarted)
				{
					const auto& NetPlayerMgr = *g_GameVariables->m_NetworkPlayerMgr;

					if (NetPlayerMgr == nullptr)
						return;

					for (const auto& Player : NetPlayerMgr->m_player_list)
					{
						if (Player != nullptr)
						{
							if (Player->is_valid())
							{
								const auto ID = Player->m_player_id;
								sub->AddOption<SubOption>(g_GameFunctions->m_GetPlayerName(ID), nullptr, SelectedPlayer, [=]
									{
										g_SelectedPlayer = ID;
									});
							}
						}
					}
				}
				else
				{
					sub->AddOption<SubOption>(g_GameFunctions->m_GetPlayerName(0), nullptr, SelectedPlayer, [=]
						{
							g_SelectedPlayer = 0;
						});
				}
			});

		g_UiManager->AddSubmenu<PlayerSubmenu>(&g_SelectedPlayer, SelectedPlayer, [](PlayerSubmenu* sub)
			{
				sub;
			});

		g_UiManager->AddSubmenu<RegularSubmenu>("Demo", Test, [](RegularSubmenu* sub)
			{
				sub->AddOption<RegularOption>("Option", nullptr, []
					{
						LOG(Info, "You pressed the test option");
					});

				static bool testBool1{};
				sub->AddOption<BoolOption<bool>>("Bool", nullptr, &testBool1);

				static std::int32_t int32Test{ 69 };
				sub->AddOption<NumberOption<std::int32_t>>("Int32", nullptr, &int32Test, 0, 100);

				static std::int64_t int64Test{ 420 };
				sub->AddOption<NumberOption<std::int64_t>>("Int64", nullptr, &int64Test, 0, 1000, 10);

				static float floatTest{ 6.9f };
				sub->AddOption<NumberOption<float>>("Float", nullptr, &floatTest, 0.f, 10.f, 0.1f, 1);

				static std::vector<std::uint64_t> vector{ 1, 2, 3 };
				static std::size_t vectorPos{};

				sub->AddOption<ChooseOption<const char*, std::size_t>>("Array", nullptr, &Lists::DemoList, &Lists::DemoListPos);
				sub->AddOption<ChooseOption<std::uint64_t, std::size_t>>("Vector", nullptr, &vector, &vectorPos);
			});

		g_UiManager->AddSubmenu<RegularSubmenu>("Debug", Debug, [](RegularSubmenu* sub)
			{
				sub->AddOption<NumberOption<float>>("Footer Sprite Addition", nullptr, &g_UiManager->m_Test, 0.f, 1000.f, 1.f, 1);
				sub->AddOption<RegularOption>("Answer", nullptr, [] {  LOG(Fatal, "Answer is {} now fuck off static code is bad :mad:", 220.f - g_UiManager->m_Test); });
			});

		g_UiManager->AddSubmenu<RegularSubmenu>("Settings", Settings, [](RegularSubmenu* sub)
			{
				sub->AddOption<SubOption>("Infobar", nullptr, SettingsBar);
				sub->AddOption<SubOption>("Options", nullptr, SettingsOption);
				sub->AddOption<SubOption>("Footer", nullptr, SettingsFooter);
				sub->AddOption<SubOption>("Input", nullptr, SettingsInput);
				sub->AddOption<NumberOption<float>>("X Position", nullptr, &g_UiManager->m_PosX, 0.f, 2000.f, 25.f, 2);
				sub->AddOption<NumberOption<float>>("Y Position", nullptr, &g_UiManager->m_PosY, 0.f, 2000.f, 25.f, 2);
				sub->AddOption<NumberOption<float>>("Width", nullptr, &g_UiManager->m_Width, 0.f, 1000.f, 50.f, 2);
				sub->AddOption<BoolOption<bool>>("Sounds", nullptr, &g_UiManager->m_Sounds);
				sub->AddOption<RegularOption>("Unload", nullptr, [] { g_Running = false; });
				sub->AddOption<RegularOption>("Exit", nullptr, [] { exit(0); });
			});

		g_UiManager->AddSubmenu<RegularSubmenu>("Infobar", SettingsBar, [](RegularSubmenu* sub)
			{
				sub->AddOption<NumberOption<std::uint8_t>>("Background R", nullptr, &g_UiManager->m_SubmenuBarBackgroundColor.r, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Background G", nullptr, &g_UiManager->m_SubmenuBarBackgroundColor.g, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Background B", nullptr, &g_UiManager->m_SubmenuBarBackgroundColor.b, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Background A", nullptr, &g_UiManager->m_SubmenuBarBackgroundColor.a, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Text R", nullptr, &g_UiManager->m_SubmenuBarTextColor.r, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Text G", nullptr, &g_UiManager->m_SubmenuBarTextColor.g, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Text B", nullptr, &g_UiManager->m_SubmenuBarTextColor.b, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Text A", nullptr, &g_UiManager->m_SubmenuBarTextColor.a, '\0', static_cast<std::uint8_t>(255));
			});

		g_UiManager->AddSubmenu<RegularSubmenu>("Options", SettingsOption, [](RegularSubmenu* sub)
			{
				sub->AddOption<NumberOption<std::uint8_t>>("Selected Background R", nullptr, &g_UiManager->m_OptionSelectedBackgroundColor.r, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Selected Background G", nullptr, &g_UiManager->m_OptionSelectedBackgroundColor.g, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Selected Background B", nullptr, &g_UiManager->m_OptionSelectedBackgroundColor.b, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Selected Background A", nullptr, &g_UiManager->m_OptionSelectedBackgroundColor.a, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Unselected Background R", nullptr, &g_UiManager->m_OptionUnselectedBackgroundColor.r, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Unselected Background G", nullptr, &g_UiManager->m_OptionUnselectedBackgroundColor.g, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Unselected Background B", nullptr, &g_UiManager->m_OptionUnselectedBackgroundColor.b, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Unselected Background A", nullptr, &g_UiManager->m_OptionUnselectedBackgroundColor.a, '\0', static_cast<std::uint8_t>(255));

				sub->AddOption<NumberOption<std::uint8_t>>("Selected Text R", nullptr, &g_UiManager->m_OptionSelectedTextColor.r, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Selected Text G", nullptr, &g_UiManager->m_OptionSelectedTextColor.g, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Selected Text B", nullptr, &g_UiManager->m_OptionSelectedTextColor.b, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Selected Text A", nullptr, &g_UiManager->m_OptionSelectedTextColor.a, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Unselected Text R", nullptr, &g_UiManager->m_OptionUnselectedTextColor.r, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Unselected Text G", nullptr, &g_UiManager->m_OptionUnselectedTextColor.g, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Unselected Text B", nullptr, &g_UiManager->m_OptionUnselectedTextColor.b, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Unselected Text A", nullptr, &g_UiManager->m_OptionUnselectedTextColor.a, '\0', static_cast<std::uint8_t>(255));
			});

		g_UiManager->AddSubmenu<RegularSubmenu>("Footer", SettingsFooter, [](RegularSubmenu* sub)
			{
				sub->AddOption<NumberOption<std::uint8_t>>("Background R", nullptr, &g_UiManager->m_FooterBackgroundColor.r, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Background G", nullptr, &g_UiManager->m_FooterBackgroundColor.g, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Background B", nullptr, &g_UiManager->m_FooterBackgroundColor.b, '\0', static_cast<std::uint8_t>(255));
				sub->AddOption<NumberOption<std::uint8_t>>("Background A", nullptr, &g_UiManager->m_FooterBackgroundColor.a, '\0', static_cast<std::uint8_t>(255));
			});

		g_UiManager->AddSubmenu<RegularSubmenu>("Input", SettingsInput, [](RegularSubmenu* sub)
			{
				sub->AddOption<NumberOption<std::int32_t>>("Open Delay", nullptr, &g_UiManager->m_OpenDelay, 10, 1000, 10, 0);
				sub->AddOption<NumberOption<std::int32_t>>("Back Delay", nullptr, &g_UiManager->m_BackDelay, 10, 1000, 10, 0);
				sub->AddOption<NumberOption<std::int32_t>>("Enter Delay", nullptr, &g_UiManager->m_EnterDelay, 10, 1000, 10, 0);
				sub->AddOption<NumberOption<std::int32_t>>("Vertical Delay", nullptr, &g_UiManager->m_VerticalDelay, 10, 1000, 10, 0);
				sub->AddOption<NumberOption<std::int32_t>>("Horizontal Delay", nullptr, &g_UiManager->m_HorizontalDelay, 10, 1000, 10, 0);
			});
	}
	void MainScript::Tick()
	{
		g_MainScript->Initialize();
		while (true)
		{
			g_UiManager->GameTick();
			Script::Current()->Yield();
		}
	}
}
