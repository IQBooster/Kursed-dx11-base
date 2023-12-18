#include "FeatureManager.hpp"
#include "Local/Local.hpp"
#include "Weapons/Weapons.hpp"
#include "World Control/World.hpp"
#include "Vehicle/Vehicle.hpp"
#include "../GTA/Script/ScriptManager.hpp"

namespace Base
{
	// Helpers
	static void LocalFeaturesTick()
	{
		while (true)
		{
			g_LocalFeatures->Tick();
			Script::Current()->Yield();
		}
	}

	static void WeaponFeaturesTick()
	{
		while (true)
		{
			g_WeaponsFeatures->Tick();
			Script::Current()->Yield();
		}
	}

	static void VehicleFeaturesTick()
	{
		while (true)
		{
			g_vehicleFeatures->Tick();
			Script::Current()->Yield();
		}
	}

	static void WorldFeaturesTick()
	{
		while (true)
		{
			g_WorldFeatures->Tick();
			Script::Current()->Yield();
		}
	}

	void FeatureManager::Initialize()
	{
		g_LocalFeatures = std::make_unique<LocalFeatures>();
		g_WeaponsFeatures = std::make_unique<WeaponsFeatures>();
		g_vehicleFeatures = std::make_unique<VehicleFeatures>();
		g_WorldFeatures = std::make_unique<WorldFeatures>();
		ScriptManager::Initialize(std::make_unique<Script>(&LocalFeaturesTick));
		ScriptManager::Initialize(std::make_unique<Script>(&VehicleFeaturesTick));
		ScriptManager::Initialize(std::make_unique<Script>(&WeaponFeaturesTick));
		ScriptManager::Initialize(std::make_unique<Script>(&WorldFeaturesTick));
	}

	void FeatureManager::Destroy()
	{
		g_LocalFeatures.reset();
		g_vehicleFeatures.reset();
		g_WeaponsFeatures.reset();
		g_WorldFeatures.reset();
	}
}