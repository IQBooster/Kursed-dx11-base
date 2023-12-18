#pragma once
#include <vector>
#include <string>


inline int sessionTypesPos = 0;
inline std::vector<std::string> sessionTypes = {
	"Join a public session", "Start a new public session",
	"Start a closed crew session (Crew 1)", "Start a closed crew session (Crew 2)",
	"Start a closed crew session (Crew 3)", "Start a closed crew session (Crew 4)",
	"Start a closed friend session", "Find a new session",
	"Start a solo session", "Find friends in session",
	"Leave online"
};
inline std::vector<std::string> vehicleCrashModelList = {
	"bruiser", "bruiser2", "bruiser3", "brutus",
	"brutus2", "brutus3", "cerberus", "cerberus2",
	"cerberus3", "clique", "deathbike", "deathbike2",
	"deathbike3", "deveste", "deviant", "dominator4",
	"dominator5", "dominator6", "impaler", "impaler2",
	"impaler3", "impaler4",  "imperator", "imperator2",
	"imperator3", "issi4", "issi5", "issi6",
	"italigto", "monster3", "monster4", "monster5",
	"rcbandito", "zr3803", "adder", "zentorno",
	"dune2", "dinghy", "dinghy2", "dinghy3",
	"dinghy4", "jetmax", "marquis", "predator",
	"seashark", "seashark2", "seashark3", "speeder",
	"speeder2", "squalo", "submersible", "submersible2",
	"suntrap", "toro", "toro2", "tropic",
	"tropic2", "tug"
};

namespace Vehicles {
	inline int casinoheists_pos = 0;
	inline std::vector<const char*> casinoheists = {
		"Asbo",
		"Everon",
		"Formula",
		"Formula 2",
		"Furia",
		"Imorgon",
		"JB700 (No Weapons)",
		"Kanjo",
		"Komoda",
		"Mini Tank",
		"Outlaw",
		"Rebla",
		"Retune",
		"Stryder",
		"Sugoi",
		"Sultan Classic",
		"Vagrant",
		"VSTR",
		"Yosemite 2",
		"Zhaba"
	};
	inline int Tuners_pos = 0;
	inline std::vector<const char*> Tuners = {
	"Warrener2",
	"Comet6",
	"Cypher",
	"Euros",
	"Growler",
	"Jester4",
	"Tailgater2",
	"Vectre",
	"Zr350",
	"Calico",
	"Dominator7",
	"Dominator8",
	"Futo2",
	"Previon",
	"Remus",
	"Rt3000",
	"Sultan3"
	};
	inline int ImportExport_pos = 0;
	inline std::vector<const char*> ImportExport = {
	"Elegy",
	"Tempesta",
	"Italigtb",
	"Italigtb2",
	"Nero",
	"Nero2",
	"Specter",
	"Specter2",
	"Diablous",
	"Diablous2",
	"Blazer5",
	"Ruiner2",
	"Dune4",
	"Dune5",
	"Phantom2",
	"Voltic2",
	"Penetrato",
	"Boxville5",
	"Wastelander",
	"Technical2",
	"FCR",
	"FCR2",
	"Ruiner3"
	};
	inline int CunningStunts_pos = 0;
	inline std::vector<const char*> CunningStunts = {
	"Bf400",
	"Brioso",
	"Cliffhanger",
	"Contender",
	"Gargoyle",
	"Le7b",
	"Lynx",
	"Omnis",
	"Rallytruck",
	"Sheava",
	"Tampa2",
	"Trophytruck",
	"Trophytruck2",
	"Tropos",
	"Tyrus"
	};
	inline int Gunrunning_pos = 0;
	inline std::vector<const char*> Gunrunning = {
	"Trailers4",
	"Xa21",
	"Caddy3",
	"Vagner",
	"Phantom3",
	"Technical3",
	"Insurgent3",
	"Apc",
	"Tampa3",
	"Dune3",
	"Trailersmall2",
	"Halftrack",
	"Ardent",
	"Oppressor"
	};
	inline int SmugglersRun_pos = 0;
	inline std::vector<const char*> SmugglersRun = {
	"Visione",
	"Havok",
	"Retinue",
	"Cyclone",
	"Rapidgt3",
	"Vigilante",
	"Alphaz1",
	"Starling",
	"Tula",
	"Microlight",
	"Rogue",
	"Howard",
	"Pyro",
	"Hunter",
	"Mogul",
	"Bombushka",
	"Nokota",
	"Seabreeze"
	};
	inline int SouthernSanAndreasSuperSportSeries_pos = 0;
	inline std::vector<const char*> SouthernSanAndreasSuperSportSeries = {
	"Caracara",
	"Cheburek",
	"Dominator3",
	"Ellie",
	"Entity2",
	"Fagaloa",
	"Flashgt",
	"Gb200",
	"Hotring",
	"Issi3",
	"Jester3",
	"Michelli",
	"Seasparrow",
	"Tezeract",
	"Taipan",
	"Tyrant"
	};
	inline int TheDoomsdayHeist_pos = 0;
	inline std::vector<const char*> TheDoomsdayHeist = {
	"Akula",
	"Barrage",
	"Chernobog",
	"Raiden",
	"Yosemite",
	"Deluxo",
	"Avenger",
	"Avenger2",
	"Thruster",
	"Pariah",
	"Stromberg",
	"Comet4",
	"Riot2",
	"Khanjali",
	"SC1",
	"Riata",
	"Volatol",
	"Hermes",
	"Savestra",
	"Streiter",
	"kamacho",
	"Gt500",
	"Z190",
	"Viseris",
	"Autarch",
	"Comet5",
	"Neon",
	"Revolter",
	"Sentinel3",
	"Hustler"
	};
	inline int AfterHours_pos = 0;
	inline std::vector<const char*> AfterHours = {
	"Blimp3",
	"Freecrawler",
	"Menacer",
	"Mule4",
	"Oppressor2",
	"Patriot2",
	"Pbus2",
	"Pounder2",
	"Scramjet",
	"Speedo4",
	"Stafford",
	"Strikeforce",
	"Swinger",
	"Jester3",
	"Terbyte"
	};
	inline int ArenaWar_pos = 0;
	inline std::vector<const char*> ArenaWar = {
	"Bruiser",
	"Bruiser2",
	"Bruiser3",
	"Brutus",
	"Brutus2",
	"Brutus3",
	"Cerberus",
	"Cerberus2",
	"Cerberus3",
	"Clique",
	"Deathbike",
	"Deathbike2",
	"Deathbike3",
	"Deveste",
	"Deviant",
	"Dominator4",
	"Dominator5",
	"Dominator6",
	"Impaler",
	"Impaler2",
	"Impaler3",
	"Impaler4",
	"Imperator",
	"Imperator2",
	"Imperator3",
	"Issi4",
	"Issi5",
	"Issi6",
	"Italigto",
	"Monster3",
	"Monster4",
	"Monster5",
	"Rcbandito",
	"Scarab",
	"Scarab2",
	"Scarab3",
	"Schlagen",
	"Slamvan4",
	"Slamvan5",
	"Slamvan6",
	"Toros",
	"Tulip",
	"Vamos",
	"ZR380",
	"ZR380 2",
	"ZR380 3" };
	inline int TheDiamondCasinoResort_pos = 0;
	inline std::vector<const char*> TheDiamondCasinoResort = {
	"S80",
	"Paragon",
	"Paragon2",
	"Drafter",
	"Thrax",
	"Caracara2",
	"Issi7",
	"Neo",
	"Gauntlet3",
	"Gauntlet4",
	"Emerus",
	"Nebula",
	"Locust",
	"Dynasty",
	"Emerus",
	"Hellion",
	"Jugular",
	"Krieger",
	"Novak",
	"Peyote2",
	"Rrocket",
	"Zion3",
	"Zorrusso"
	};
	inline int SpecialVehicleCircuit_pos = 0;
	inline std::vector<const char*> SpecialVehicleCircuit = {
		"Gp1",
		 "Infernus2",
		 "Ruston",
		 "Turismo2"
	};
	inline int CayoPerico_pos = 0;
	inline std::vector<const char*> CayoPerico = {
		"Alkonost",
		 "Annihilator2",
		 "Avisa",
		 "Brioso2",
		 "Dinghy5",
		 "Italirsx",
		 "Kosatka",
		 "Longfin",
		"Manchez2",
		 "Patrolboat",
		 "Seasparrow2",
		 "Seasparrow3",
		 "Slamtruck",
		 "Squaddie",
		 "Toreador",
		"Verus",
		 "Vetir",
		 "Veto",
		 "Veto2",
		 "Weevil",
		 "Winky" };
	inline int SummerSpecial_pos = 0;
	inline std::vector<const char*> SummerSpecial = {
		"Club",
		 "Coquette4",
		 "Dukes3",
		 "Gauntlet5",
		 "Glendale2",
		 "Landstalker2",
		 "Manana2",
		 "Openwheel1",
		 "Openwheel2",
		"Penumbra2",
		 "Peyote3",
		 "Seminole2",
		 "Tigon",
		 "Yosemite3",
		 "Youga3"
	};
	inline int Bikers_pos = 0;
	inline std::vector<const char*> Bikers = {
		"Avarus",
		 "Blazer4",
		 "Chimera",
		 "Daemon2",
		 "Defiler",
		 "Esskey",
		 "Faggio",
		 "Faggio3",
		 "Hakuchou2",
		 "Manchez",
		"Nightblade",
		 "Raptor",
		 "Ratbike",
		 "Sanctus",
		 "Shotaro",
		 "Tornado6",
		 "Vortex",
		 "Wolfsbane",
		 "Youga2",
		"Zombiea",
		 "Zombieb"
	};
	inline int FinanceFelony_pos = 0;
	inline std::vector<const char*> FinanceFelony = {
		"Bestiagts",
		 "Brickade",
		 "FMJ",
		 "Nimbus",
		 "Pfister811",
		 "Prototipo",
		 "Reaper",
		 "Rumpo3",
		 "Seven70",
		"Tug",
		 "Volatus",
		 "Windsor2",
		 "XLS",
		 "XLS2"
	};
	inline int CustomClassics_pos = 0;
	inline std::vector<const char*> CustomClassics = {
		"Faction3",
		 "Minivan2",
		 "Sabregt2",
		 "Slamvan3",
		 "Tornado5",
		 "Virgo2",
		 "Virgo3"
	};
	inline int BeMyValentine_pos = 0;
	inline std::vector<const char*> BeMyValentine = {
		"Btype3"
	};
	inline int Jan2016_pos = 0;
	inline std::vector<const char*> Jan2016 = {
		"Banshee2",
		 "Sultanrs"
	};
	inline int FestiveSurprise_pos = 0;
	inline std::vector<const char*> FestiveSurprise = {
		"Jester2",
		 "Massacro2",
		 "Ratloader2",
		 "Slamvan"
	};
	inline int Executives_pos = 0;
	inline std::vector<const char*> Executives = {
		"Bestiagts",
		 "Brickade",
		 "FMJ",
		 "Nimbus",
		 "Pfister811",
		 "Prototipo",
		 "Reaper",
		 "Rumpo3",
		"Seven70",
		 "Tug",
		 "Volatus",
		 "Windsor2",
		 "XLS",
		 "xls2"
	};
	inline int Halloween_pos = 0;
	inline std::vector<const char*> Halloween = {
		"Btype2",
		 "Lurcher"
	};
	inline int Lowriders_pos = 0;
	inline std::vector<const char*> Lowriders = {
		"Buccaneer2",
		 "Chino2",
		 "Faction",
		 "Faction2",
		 "Moonbeam",
		 "Moonbeam2",
		 "Primo2",
		 "Voodoo"
	};
	inline int Ill2_pos = 0;
	inline std::vector<const char*> Ill2 = {
		"Brawler",
		 "Chino",
		 "Coquette3",
		 "T20",
		 "Toro",
		 "Vindicator"
	};
	inline int Ill1_pos = 0;
	inline std::vector<const char*> Ill1 = {
		"Feltzer3",
		 "Luxor2",
		 "Osiris",
		 "Swift2",
		 "Virgo",
		 "Windsor"
	};
	inline int Heists_pos = 0;
	inline std::vector<const char*> Heists = {
		"Barracks3",
		 "Boxville4",
		 "Casco",
		 "Dinghy3",
		 "Enduro",
		 "Gburrito2",
		 "Guardian",
		 "Hydra",
		"insurgent",
		 "insurgent2",
		 "kuruma",
		 "kuruma2",
		 "lectro",
		 "mule3",
		 "savage",
		 "slamvan2",
		"tanker2",
		 "technical",
		 "trash2",
		 "valkyrie",
		 "velum2"
	};
	inline int Festive2015_pos = 0;
	inline std::vector<const char*> Festive2015 = {
		"tampa"
	};
	inline int NextGen_pos = 0;
	inline std::vector<const char*> NextGen = {
		"blimp2",
		 "blista2",
		 "blista3",
		 "buffalo3",
		 "dodo",
		 "dominator2",
		 "dukes",
		 "dukes2",
		 "gauntlet2",

		"marshall",
		 "stalion",
		 "stalion2",
		 "submersible2"
	};
	inline int LTS_pos = 0;
	inline std::vector<const char*> LTS = {
		"furoregt",
		 "hakuchou",
		 "innovation"
	};
	inline int Flight_pos = 0;
	inline std::vector<const char*> Flight = {
		"besra",
		 "coquette2",
		 "miljet",
		 "swift"
	};
	inline int Independence_pos = 0;
	inline std::vector<const char*> Independence = {
		"monster",
		 "sovereign"
	};
	inline int Hipster_pos = 0;
	inline std::vector<const char*> Hipster = {
		"blade",
		 "dubsta3",
		 "glendale",
		 "panto",
		 "pigalle",
		 "rhapsody",
		 "warrener"
	};
	inline int High_pos = 0;
	inline std::vector<const char*> High = {
		"huntley",
		 "massacro",
		 "thrust",
		 "zentorno"
	};
	inline int Business_pos = 0;
	inline std::vector<const char*> Business = {
		"alpha",
		 "jester",
		 "turismor",
		 "vestra"
	};
	inline int Massacre_pos = 0;
	inline std::vector<const char*> Massacre = {
		"btype"
	};
	inline int Beach_pos = 0;
	inline std::vector<const char*> Beach = {
		"bifta",
		 "kalahari",
		 "paradise",
		 "speeder"
	};
	inline int boat_pos = 0;
	inline std::vector<const char*> boat = {
	"dinghy",
	 "dinghy2",
	 "dinghy3",
	 "dinghy4",
	 "jetmax",

	"marquis",
	 "predator",
	 "seashark",
	 "seashark2",
	 "seashark3",

	"speeder",
	 "speeder2",
	 "squalo",
	 "submersible",
	 "submersible2",

	"suntrap",
	 "toro",
	 "toro2",
	 "tropic",
	 "tropic2",

	"tug"
	};
	inline int commercial_pos = 0;
	inline std::vector<const char*> commercial = {
		"benson",
		 "biff",
		 "hauler",
		 "mule",
		 "mule2",

		"mule3",
		 "packer",
		 "phantom",
		 "pounder",
		 "stockade",

		"stockade3"
	};
	inline int compact_pos = 0;
	inline std::vector<const char*> compact = {
		"blista",
		 "brioso",
		 "dilettante",
		 "dilettante2",
		 "issi2",

		"panto",
		 "prairie",
		 "rhapsody"
	};
	inline int coupe_pos = 0;
	inline std::vector<const char*> coupe = {
		"cogcabrio",
		 "exemplar",
		 "f620",
		 "felon",
		 "felon2",

		"jackal",
		 "oracle",
		 "oracle2",
		 "sentinel",
		 "sentinel2",

		"windsor",
		 "windsor2",
		 "zion",
		 "zion2"
	};
	inline int cycle_pos = 0;
	inline std::vector<const char*> cycle = {
		"bmx",
		 "cruiser",
		 "fixter",
		 "scorcher",
		 "tribike",

		"tribike2",
		 "tribike3"
	};
	inline int emergency_pos = 0;
	inline std::vector<const char*> emergency = {
		"ambulance",
		 "fbi",
		 "fbi2",
		 "firetruk",
		 "lguard",

		"pbus",
		 "pranger",
		 "police",
		 "police2",
		 "police3",

		"police4",
		 "policeb",
		 "policeold1",
		 "policeold2",
		 "policet",

		"sheriff",
		 "sheriff2",
		 "riot"
	};
	inline int helicopter_pos = 0;
	inline std::vector<const char*> helicopter = {
		"annihilator",
		 "blimp",
		 "blimp2",
		 "buzzard",
		 "buzzard2",

		"cargobob",
		 "cargobob2",
		 "cargobob3",
		 "cargobob4",
		 "frogger",

		"frogger2",
		 "maverick",
		 "polmav",
		 "savage",
		 "skylift",

		"supervolito",
		 "supervolito2",
		 "swift",
		 "swift2",
		 "valkyrie",

		"valkyrie2",
		 "volatus"
	};
	inline int industrial_pos = 0;
	inline std::vector<const char*> industrial = {
		"bulldozer",
		 "cutter",
		 "dump",
		 "flatbed",
		 "guardian",

		"handler",
		 "mixer",
		 "mixer2",
		 "rubble",
		 "tiptruck",

		"tiptruck2"
	};
	inline int military_pos = 0;
	inline std::vector<const char*> military = {
		"barracks",
		 "barracks2",
		 "barracks3",
		 "crusader",
		 "rhino"
	};
	inline int motorcycles_pos = 0;
	inline std::vector<const char*> motorcycles = {
		"akuma",
		 "avarus",
		 "bagger",
		 "bati",
		 "bati2",
		"bf400",
		 "carbonrs",
		 "chimera",
		 "cliffhanger",
		 "daemon",
		"daemon2",
		 "defiler",
		 "double",
		 "enduro",
		 "esskey",
		"faggio",
		 "faggio2",
		 "faggio3",
		 "gargoyle",
		 "hakuchou",
		"hakuchou2",
		 "hexer",
		 "innovation",
		 "lectro",
		 "manchez",
		"nemesis",
		 "nightblade",
		 "pcj",
		 "ratbike",
		 "ruffian",
		"sanchez",
		 "sanchez2",
		 "sanctus",
		 "shotaro",
		 "sovereign",
		"thrust",
		 "vader",
		 "vindicator",
		 "vortex",
		 "wolfsbane",
		"zombiea",
		 "zombieb",
		 "diablous",
		 "diablous2",
		 "fcr",
		"fcr2"
	};
	inline int muscle_pos = 0;
	inline std::vector<const char*> muscle = {
		"blade",
		 "buccaneer",
		 "buccaneer2",
		 "chino",
		 "chino2",
		"coquette3",
		 "dominator",
		 "dominator2",
		 "dukes",
		 "dukes2",
		"gauntlet",
		 "gauntlet2",
		 "faction",
		 "faction2",
		 "faction3",
		"hotknife",
		 "lurcher",
		 "moonbeam",
		 "moonbeam2",
		 "nightshade",
		"phoenix",
		 "picador",
		 "ratloader",
		 "ratloader2",
		 "ruiner",
		 "ruiner2",
		 "ruiner3",
		"sabregt",
		 "sabregt2",
		 "slamvan",
		 "slamvan2",
		 "slamvan3",
		"stalion",
		 "stalion2",
		 "tampa",
		 "vigero",
		 "virgo",
		"virgo2",
		 "virgo3",
		 "voodoo",
		 "voodoo2"
	};
	inline int offroad_pos = 0;
	inline std::vector<const char*> offroad = {
		"bfinjection",
		 "bifta",
		 "blazer",
		 "blazer2",
		 "blazer3",
		"blazer4",
		 "bodhi2",
		 "brawler",
		 "dloader",
		 "dubsta3",
		"dune",
		 "dune2",
		 "insurgent",
		 "insurgent2",
		 "kalahari",
		"marshall",
		 "mesa3",
		 "monster",
		 "rancherxl",
		 "rancherxl2",
		"rebel",
		 "rebel2",
		 "sandking",
		 "sandking2",
		 "technical",
		"trophytruck",
		 "trophytruck2",
		 "technical2",
		 "dune4",
		 "dune5",
		"blazer5",
	};
	inline int plane_pos = 0;
	inline std::vector<const char*> plane = {
		"besra",
		 "cargoplane",
		 "cuban800",
		 "dodo",
		 "duster",
		"hydra",
		 "jet",
		 "lazer",
		 "luxor",
		 "luxor2",
		"mammatus",
		 "miljet",
		 "nimbus",
		 "shamal",
		 "stunt",
		"titan",
		 "velum",
		 "velum2",
		 "vestra"
	};
	inline int sedan_pos = 0;
	inline std::vector<const char*> sedan = {
		"asea",
		 "asea2",
		 "asterope",
		 "cog55",
		 "cog552",
		"cognoscenti",
		 "cognoscenti2",
		 "emperor",
		 "emperor2",
		 "emperor3",
		"fugitive",
		 "glendale",
		 "ingot",
		 "intruder",
		 "limo2",
		"premier",
		 "primo",
		 "primo2",
		 "regina",
		 "romero",
		"schafter2",
		 "schafter5",
		 "schafter6",
		 "stanier",
		 "stratum",
		"stretch",
		 "superd",
		 "surge",
		 "tailgater",
		 "warrener",
		"washington"
	};
	inline int service_pos = 0;
	inline std::vector<const char*> service = {
		"airbus",
		 "brickade",
		 "bus",
		 "coach",
		 "rallytruck",
		"rentalbus",
		 "taxi",
		 "tourbus",
		 "trash",
		 "trash2",
		"wastelander",

	};
	inline int sport_pos = 0;
	inline std::vector<const char*> sport = {
	"alpha",
	 "banshee",
	 "bestiagts",
	 "blista2",
	 "blista3",
	"buffalo",
	 "buffalo2",
	 "buffalo3",
	 "carbonizzare",
	 "comet2",
	"coquette",
	 "elegy",
	 "elegy2",
	 "feltzer2",
	 "furoregt",
	 "fusilade",
	"futo",
	 "jester",
	 "jester2",
	 "khamelion",
	 "kuruma",
	"kuruma2",
	 "lynx",
	 "massacro",
	 "massacro2",
	 "ninef",
	"ninef2",
	 "omnis",
	 "penumbra",
	 "rapidgt",
	 "rapidgt2",
	"raptor",
	 "schafter3",
	 "schafter4",
	 "schwartzer",
	 "seven70",
	"sultan",
	 "surano",
	 "specter",
	 "specter2",
	 "tampa2",
	 "tropos",
	 "verlierer2",
	"ruiner2",
	 "phantom2",
	 "ruston"
	};
	inline int sportsclassic_pos = 0;
	inline std::vector<const char*> sportsclassic = {
		"btype",
		 "btype2",
		 "btype3",
		 "casco",
		 "coquette2",
		"feltzer3",
		 "jb700",
		 "mamba",
		 "manana",
		 "monroe",
		"peyote",
		 "pigalle",
		 "stinger",
		 "stingergt",
		 "tornado",
		"tornado2",
		 "tornado3",
		 "tornado4",
		 "tornado5",
		 "tornado6",
		"ztype",
		 "infernus2",
		 "turismo2",

	};
	inline int super_pos = 0;
	inline std::vector<const char*> super = {
		"adder",
		 "banshee2",
		 "bullet",
		 "cheetah",
		 "entityxf",
		"fmj",
		 "sheava",
		 "infernus",
		 "nero",
		 "nero2",
		"osiris",
		 "le7b",
		"italigtb",
		 "italigtb2",
		 "pfister811",
		 "prototipo",
		 "reaper",
		 "sultanrs",
		 "t20",
		"tempesta",
		 "turismor",
		 "tyrus",
		 "vacca",
		 "voltic",
		 "zentorno",
		 "voltic2",
		 "penetrator",
		 "gp1"
	};
	inline int suv_pos = 0;
	inline std::vector<const char*> suv = {
		"baller",
		 "baller2",
		 "baller3",
		 "baller4",
		 "baller5",
		"baller6",
		 "bjxl",
		 "cavalcade",
		 "cavalcade2",
		 "contender",
		"dubsta",
		 "dubsta2",
		 "fq2",
		 "granger",
		 "gresley",
		"habanero",
		 "huntley",
		 "landstalker",
		 "mesa",
		 "mesa2",
		"patriot",
		 "radi",
		 "rocoto",
		 "seminole",
		 "serrano",
		"xls",
		 "xls2"
	};
	inline int trailer_pos = 0;
	inline std::vector<const char*> trailer = {
		"armytanker",
		 "armytrailer",
		 "armytrailer2",
		 "baletrailer",
		 "boattrailer",
		"docktrailer",
		 "freighttrailer",
		 "graintrailer",
		 "proptrailer",
		 "raketrailer",
		"tanker",
		 "tanker2",
		 "tr2",
		 "tr3",
		 "tr4",
		"trailerlogs",
		 "trailers",
		 "trailers2",
		 "trailers3",
		 "trailersmall",
		"trflat",
		 "tvtrailer"
	};
	inline int train2_pos = 0;
	inline std::vector<const char*> train2 = {
		"cablecar",
		 "freight",
		 "freightcar",
		 "freightcont1",
		 "freightcont2",
		"freightgrain",
		 "metrotrain",
		 "tankercar"
	};
	inline int utility_pos = 0;
	inline std::vector<const char*> utility = {
		"airtug",
		 "caddy",
		 "caddy2",
		 "docktug",
		 "forklift",
		"mower",
		 "ripley",
		 "sadler",
		 "sadler2",
		 "scrap",
		"towtruck",
		 "towtruck2",
		 "tractor",
		 "tractor2",
		 "tractor3",
		"utillitruck",
		 "utillitruck2",
		 "utillitruck3"
	};
	inline int van_pos = 0;
	inline std::vector<const char*> van = {
		"bison",
		 "bison2",
		 "bison3",
		 "bobcatxl",
		 "boxville",
		"boxville2",
		 "boxville3",
		 "boxville4",
		 "burrito",
		 "burrito2",
		"burrito3",
		 "burrito4",
		 "burrito5",
		 "camper",
		 "gburrito",
		"gburrito2",
		 "journey",
		 "minivan",
		 "minivan2",
		 "paradise",
		"pony",
		 "pony2",
		 "rumpo",
		 "rumpo2",
		 "rumpo3",
		"speedo",
		 "speedo2",
		 "surfer",
		 "surfer2",
		 "taco",
		"youga",
		 "youga2"
	};
	inline std::vector<const char*> sports = {
		"Adder",
	};
	inline static const char* Tunersbackend[]
	{
	   "warrener2",
		"comet6",
		"cypher",
		"euros",
		"growler",
		"jester4",
		"tailgater2",
		"vectre",
		"zr350",
		"calico",
		"dominator7",
		"dominator8",
		"futo2",
		"previon",
		"remus",
	   "rt3000",
		"sultan3"
	};

	inline static const char* ImportExportbackend[]
	{
   "elegy",
	"tempesta",
	"italigtb",
	"italigtb2",
	"nero",
	   "nero2",
		"specter",
		"specter2",
		"diablous",
		"diablous2",
	   "blazer5",
		"ruiner2",
		"dune4",
		"dune5",
		"phantom2",
	   "voltic2",
		"penetrato",
		"boxville5",
		"wastelander",
		"technical2",
	   "fcr",
		"fcr2",
		"ruiner3"
	};

	inline static const char* CunningStuntsbackend[]
	{
   "bf400",
	"brioso",
	"cliffhanger",
	"contender",
	"gargoyle",
	"le7b",
	"lynx",
	"omnis",
	"rallytruck",
	"sheava",
	"tampa2",
   "trophytruck",
	"trophytruck2",
	"tropos",
	"tyrus" };

	inline static const char* Gunrunningbackend[]
	{
   "trailers4",
	"xa21",
	"caddy3",
	"vagner",
   "phantom3",
	"technical3",
	"insurgent3",
	"apc",
   "tampa3",
	"dune3",
	"trailersmall2",
	"halftrack",
   "ardent",
	"oppressor" };

	inline static const char* SmugglersRunbackend[]
	{
"visione",
 "havok",
 "retinue",
 "cyclone",
	"rapidgt3",
	 "vigilante",
	 "alphaz1",
	 "starling",
	"tula",
	 "havok",
	 "microlight",
	 "rogue",
	 "howard",
	"pyro",
	 "hunter",
	 "mogul",
	 "bombushka",
	 "nokota",
	 "seabreeze" };

	inline static const char* SouthernSanAndreasSuperSportSeriesbackend[]
	{
"caracara",
 "cheburek",
 "dominator3",
 "ellie",
	"entity2",
	 "fagaloa",
	 "flashgt",
	 "gb200",
	 "hotring",
	"issi3",
	 "jester3",
	 "michelli",
	 "seasparrow",
	 "tezeract",
	"taipan",
	 "tyrant" };

	inline static const char* TheDoomsdayHeistbackend[]
	{
   "akula",
	"barrage",
   "chernobog",
	"raiden",
   "yosemite",
   "deluxo",
   "avenger",
	"avenger2",
	"thruster",
	"pariah",
	"stromberg",
	"comet4",
   "riot2",
	"khanjali",
	"sc1",
	"riata",
	"volatol",
	"hermes",
	"savestra",
	"streiter",
   "kamacho",
	"gt500",
	"z190",
	"viseris",
	"autarch",
	"comet5",
	"neon",
	"revolter",
	"sentinel3",
	"hustler" };

	inline static const char* AfterHoursbackend[]
	{
   "blimp3",
	"freecrawler",
	"menacer",
	"mule4",
	"oppressor2",
	   "patriot2",
		"pbus2",
		"pounder2",
		"scramjet",
		"speedo4",
	   "stafford",
		"strikeforce",
		"swinger",
		"jester3",
		"terbyte" };

	inline static const char* ArenaWarbackend[]
	{
   "bruiser",
	"bruiser2",
	"bruiser3",
	"brutus",
	"brutus2",
	"brutus3",
	"cerberus",
	"cerberus2",
	"cerberus3",
	"clique",
	"deathbike",
   "deathbike2",
	"deathbike3",
	"deveste",
	"deviant",
	"dominator4",
	"dominator5",
	"dominator6",
	"impaler",
	"impaler2",
	"impaler3",
	"impaler4",
   "imperator",
	"imperator2",
	"imperator3",
	"issi4",
	"issi5",
	"issi6",
	"italigto",
	"monster3",
	"monster4",
	"monster5",
	"rcbandito",
	"scarab",
   "scarab2",
	"scarab3",
	"schlagen",
	"slamvan4",
	"slamvan5",
	"slamvan6",
	"toros",
	"tulip",
	"vamos",
	"zr380",
	"zr3802",
	"zr3803" };

	inline static const char* TheDiamondCasinoResortbackend[]
	{
   "s80",
	"paragon",
	"paragon2",
	"drafter",
	"thrax",
	"caracara2",
	"issi7",
   "neo",
	"gauntlet3",
	"gauntlet4",
	"emerus",
	"nebula",
	"locust",
	"dynasty",
	"emerus",
   "hellion",
	"jugular",
	"krieger",
	"novak",
	"peyote2",
	"rrocket",
	"zion3",
	"zorrusso" };

	inline const char* casinoheistsbackend[]
	{
		"asbo",
		"everon",
		"formula",
		"formula2",
		"furia",
		"imorgon",
		"jb7002",
		"kanjo",
		"komoda",
		"minitank",
		"outlaw",
		"rebla",
		"retune2",
		"stryder",
		"sugoi",
		"sultan2",
		"vagrant",
		"vstr",
		"yosemite2",
		"zhaba"
	};

	inline static const char* SpecialVehicleCircuitbackend[]
	{
	   "gp1",
		"infernus2",
		"ruston",
		"turismo2"
	};

	inline static const char* CayoPericobackend[]
	{
	   "alkonost",
		"annihilator2",
		"avisa",
		"brioso2",
		"dinghy5",
		"italirsx",
		"kosatka",
		"longfin",
	   "manchez2",
		"patrolboat",
		"seasparrow2",
		"seasparrow3",
		"slamtruck",
		"squaddie",
		"toreador",
	   "verus",
		"vetir",
		"veto",
		"veto2",
		"weevil",
		"winky" };

	inline static const char* SummerSpecialbackend[]
	{
	   "club",
		"coquette4",
		"dukes3",
		"gauntlet5",
		"glendale2",
		"landstalker2",
		"manana2",
		"openwheel1",
		"openwheel2",
	   "penumbra2",
		"peyote3",
		"seminole2",
		"tigon",
		"yosemite3",
		"youga3"
	};

	inline static const char* Bikersbackend[]
	{
	   "avarus",
		"blazer4",
		"chimera",
		"daemon2",
		"defiler",
		"esskey",
		"faggio",
		"faggio3",
		"hakuchou2",
		"manchez",
	   "nightblade",
		"raptor",
		"ratbike",
		"sanctus",
		"shotaro",
		"tornado6",
		"vortex",
		"wolfsbane",
		"youga2",
	   "zombiea",
		"zombieb"
	};

	inline static const char* FinanceFelonybackend[]
	{
	   "bestiagts",
		"brickade",
		"fmj",
		"nimbus",
		"pfister811",
		"prototipo",
		"reaper",
		"rumpo3",
		"seven70",

	   "tug",
		"volatus",
		"windsor2",
		"xls",
		"xls2"
	};

	inline static const char* CustomClassicsbackend[]
	{
	   "faction3",
		"minivan2",
		"sabregt2",
		"slamvan3",
		"tornado5",
		"virgo2",
		"virgo3"
	};

	inline static const char* BeMyValentinebackend[]
	{
	   "btype3"
	};

	inline static const char* Jan2016backend[]
	{
	   "banshee2",
		"sultanrs"
	};

	inline static const char* FestiveSurprisebackend[]
	{
	   "jester2",
		"massacro2",
		"ratloader2",
		"slamvan"
	};

	inline static const char* Executivesbackend[]
	{
	   "bestiagts",
		"brickade",
		"fmj",
		"nimbus",
		"pfister811",
		"prototipo",
		"reaper",
		"rumpo3",

	   "seven70",
		"tug",
		"volatus",
		"windsor2",
		"xls",
		"xls2"
	};

	inline static const char* Halloweenbackend[]
	{
	   "btype2",
		"lurcher"
	};

	inline static const char* Lowridersbackend[]
	{
	   "buccaneer2",
		"chino2",
		"faction",
		"faction2",
		"moonbeam",
		"moonbeam2",
		"primo2",
		"voodoo"
	};

	inline static const char* Ill2backend[]
	{
	   "brawler",
		"chino",
		"coquette3",
		"t20",
		"toro",
		"vindicator"
	};

	inline static const char* Ill1backend[]
	{
	   "feltzer3",
		"luxor2",
		"osiris",
		"swift2",
		"virgo",
		"windsor"
	};

	inline static const char* Heistsbackend[]
	{
	   "barracks3",
		"boxville4",
		"casco",
		"dinghy3",
		"enduro",
		"gburrito2",
		"guardian",
		"hydra",

	   "insurgent",
		"insurgent2",
		"kuruma",
		"kuruma2",
		"lectro",
		"mule3",
		"savage",
		"slamvan2",

	   "tanker2",
		"technical",
		"trash2",
		"valkyrie",
		"velum2"
	};

	inline static const char* Festive2015backend[]
	{
	   "tampa"
	};

	inline static const char* NextGenbackend[]
	{
	   "blimp2",
		"blista2",
		"blista3",
		"buffalo3",
		"dodo",
		"dominator2",
		"dukes",
		"dukes2",
		"gauntlet2",

	   "marshall",
		"stalion",
		"stalion2",
		"submersible2"
	};

	inline static const char* LTSbackend[]
	{
	   "furoregt",
		"hakuchou",
		"innovation"
	};

	inline static const char* Flightbackend[]
	{
	   "besra",
		"coquette2",
		"miljet",
		"swift"
	};

	inline static const char* Independencebackend[]
	{
	   "monster",
		"sovereign"
	};

	inline static const char* Hipsterbackend[]
	{
	   "blade",
		"dubsta3",
		"glendale",
		"panto",
		"pigalle",
		"rhapsody",
		"warrener"
	};

	inline static const char* Highbackend[]
	{
	   "huntley",
		"massacro",
		"thrust",
		"zentorno"
	};

	inline static const char* Businessbackend[]
	{
	   "alpha",
		"jester",
		"turismor",
		"vestra"
	};

	inline static const char* Massacrebackend[]
	{
	   "btype"
	};

	inline static const char* Beachbackend[]
	{
	   "bifta",
		"kalahari",
		"paradise",
		"speeder"
	};

	inline static const char* boatbackend[]
	{
   "dinghy",
	"dinghy2",
	"dinghy3",
	"dinghy4",
	"jetmax",

   "marquis",
	"predator",
	"seashark",
	"seashark2",
	"seashark3",

   "speeder",
	"speeder2",
	"squalo",
	"submersible",
	"submersible2",

   "suntrap",
	"toro",
	"toro2",
	"tropic",
	"tropic2",

   "tug"
	};

	inline static const char* commercialbackend[]
	{
	   "benson",
		"biff",
		"hauler",
		"mule",
		"mule2",

	   "mule3",
		"packer",
		"phantom",
		"pounder",
		"stockade",

	   "stockade3"
	};

	inline static const char* compactbackend[]
	{
	   "blista",
		"brioso",
		"dilettante",
		"dilettante2",
		"issi2",

	   "panto",
		"prairie",
		"rhapsody"
	};

	inline static const char* coupebackend[]
	{
	   "cogcabrio",
		"exemplar",
		"f620",
		"felon",
		"felon2",

	   "jackal",
		"oracle",
		"oracle2",
		"sentinel",
		"sentinel2",

	   "windsor",
		"windsor2",
		"zion",
		"zion2"
	};

	inline static const char* cyclebackend[]
	{
	   "bmx",
		"cruiser",
		"fixter",
		"scorcher",
		"tribike",

	   "tribike2",
		"tribike3"
	};

	inline static const char* emergencybackend[]
	{
	   "ambulance",
		"fbi",
		"fbi2",
		"firetruk",
		"lguard",

	   "pbus",
		"pranger",
		"police",
		"police2",
		"police3",

	   "police4",
		"policeb",
		"policeold1",
		"policeold2",
		"policet",

	   "sheriff",
		"sheriff2",
		"riot"
	};

	inline static const char* helicopterbackend[]
	{
	   "annihilator",
		"blimp",
		"blimp2",
		"buzzard",
		"buzzard2",

	   "cargobob",
		"cargobob2",
		"cargobob3",
		"cargobob4",
		"frogger",

	   "frogger2",
		"maverick",
		"polmav",
		"savage",
		"skylift",

	   "supervolito",
		"supervolito2",
		"swift",
		"swift2",
		"valkyrie",

	   "valkyrie2",
		"volatus"
	};

	inline static const char* industrialbackend[]
	{
	   "bulldozer",
		"cutter",
		"dump",
		"flatbed",
		"guardian",

	   "handler",
		"mixer",
		"mixer2",
		"rubble",
		"tiptruck",

	   "tiptruck2"
	};

	inline static const char* militarybackend[]
	{
	   "barracks",
		"barracks2",
		"barracks3",
		"crusader",
		"rhino"
	};

	inline static const char* motorcyclesbackend[]
	{
	   "akuma",
		"avarus",
		"bagger",
		"bati",
		"bati2",
	   "bf400",
		"carbonrs",
		"chimera",
		"cliffhanger",
		"daemon",
	   "daemon2",
		"defiler",
		"double",
		"enduro",
		"esskey",
	   "faggio",
		"faggio2",
		"faggio3",
		"gargoyle",
		"hakuchou",
	   "hakuchou2",
		"hexer",
		"innovation",
		"lectro",
		"manchez",
	   "nemesis",
		"nightblade",
		"pcj",
		"ratbike",
		"ruffian",
	   "sanchez",
		"sanchez2",
		"sanctus",
		"shotaro",
		"sovereign",
	   "thrust",
		"vader",
		"vindicator",
		"vortex",
		"wolfsbane",
	   "zombiea",
		"zombieb",
		"diablous",
		"diablous2",
		"fcr",
	   "fcr2"
	};

	inline static const char* musclebackend[]
	{
	   "blade",
		"buccaneer",
		"buccaneer2",
		"chino",
		"chino2",
	   "coquette3",
		"dominator",
		"dominator2",
		"dukes",
		"dukes2",
	   "gauntlet",
		"gauntlet2",
		"faction",
		"faction2",
		"faction3",
	   "hotknife",
		"lurcher",
		"moonbeam",
		"moonbeam2",
		"nightshade",
	   "phoenix",
		"picador",
		"ratloader",
		"ratloader2",
		"ruiner",
		"ruiner2",
		"ruiner3",
	   "sabregt",
		"sabregt2",
		"slamvan",
		"slamvan2",
		"slamvan3",
	   "stalion",
		"stalion2",
		"tampa",
		"vigero",
		"virgo",
	   "virgo2",
		"virgo3",
		"voodoo",
		"voodoo2"
	};

	inline static const char* offroadbackend[]
	{
	   "bfinjection",
		"bifta",
		"blazer",
		"blazer2",
		"blazer3",
	   "blazer4",
		"bodhi2",
		"brawler",
		"dloader",
		"dubsta3",
	   "dune",
		"dune2",
		"insurgent",
		"insurgent2",
		"kalahari",
	   "marshall",
		"mesa3",
		"monster",
		"rancherxl",
		"rancherxl2",
	   "rebel",
		"rebel2",
		"sandking",
		"sandking2",
		"technical",
	   "trophytruck",
		"trophytruck2",
		"technical2",
		"dune4",
		"dune5",
	   "blazer5"
	};

	inline static const char* planebackend[]
	{
	   "besra",
		"cargoplane",
		"cuban800",
		"dodo",
		"duster",
	   "hydra",
		"jet",
		"lazer",
		"luxor",
		"luxor2",
	   "mammatus",
		"miljet",
		"nimbus",
		"shamal",
		"stunt",
	   "titan",
		"velum",
		"velum2",
		"vestra"
	};

	inline static const char* sedanbackend[]
	{
	   "asea",
		"asea2",
		"asterope",
		"cog55",
		"cog552",
	   "cognoscenti",
		"cognoscenti2",
		"emperor",
		"emperor2",
		"emperor3",
	   "fugitive",
		"glendale",
		"ingot",
		"intruder",
		"limo2",
	   "premier",
		"primo",
		"primo2",
		"regina",
		"romero",
	   "schafter2",
		"schafter5",
		"schafter6",
		"stanier",
		"stratum",
	   "stretch",
		"superd",
		"surge",
		"tailgater",
		"warrener",
	   "washington"
	};

	inline static const char* servicebackend[]
	{
	   "airbus",
		"brickade",
		"bus",
		"coach",
		"rallytruck",
	   "rentalbus",
		"taxi",
		"tourbus",
		"trash",
		"trash2",
	   "wastelander",

	};

	inline static const char* sportbackend[]
	{
   "alpha",
	"banshee",
	"bestiagts",
	"blista2",
	"blista3",
   "buffalo",
	"buffalo2",
	"buffalo3",
	"carbonizzare",
	"comet2",
   "coquette",
	"elegy",
	"elegy2",
	"feltzer2",
	"furoregt",
	"fusilade",
   "futo",
	"jester",
	"jester2",
	"khamelion",
	"kuruma",
   "kuruma2",
	"lynx",
	"massacro",
	"massacro2",
	"ninef",
   "ninef2",
	"omnis",
	"penumbra",
	"rapidgt",
	"rapidgt2",
   "raptor",
	"schafter3",
	"schafter4",
	"schwartzer",
	"seven70",
   "sultan",
	"surano",
	"specter",
	"specter2",
	"tampa2",
	"tropos",
	"verlierer2",
   "ruiner2",
	"phantom2",
	"ruston"
	};

	inline static const char* sportsclassicbackend[]
	{
	   "btype",
		"btype2",
		"btype3",
		"casco",
		"coquette2",
	   "feltzer3",
		"jb700",
		"mamba",
		"manana",
		"monroe",
	   "peyote",
		"pigalle",
		"stinger",
		"stingergt",
		"tornado",
	   "tornado2",
		"tornado3",
		"tornado4",
		"tornado5",
		"tornado6",
	   "ztype",
		"infernus2",
		"turismo2",

	};

	inline static const char* superbackend[]
	{
	   "adder",
		"banshee2",
		"bullet",
		"cheetah",
		"entityxf",
	   "fmj",
		"sheava",
		"infernus",
		"nero",
		"nero2",
	   "osiris",
		"le7b",
	   "italigtb",
		"italigtb2",
		"pfister811",
		"prototipo",
		"reaper",
		"sultanrs",
		"t20",
	   "tempesta",
		"turismor",
		"tyrus",
		"vacca",
		"voltic",
		"zentorno",
		"voltic2",
		"penetrator",
		"gp1"
	};

	inline static const char* suvbackend[]
	{
	   "baller",
		"baller2",
		"baller3",
		"baller4",
		"baller5",
	   "baller6",
		"bjxl",
		"cavalcade",
		"cavalcade2",
		"contender",
	   "dubsta",
		"dubsta2",
		"fq2",
		"granger",
		"gresley",
	   "habanero",
		"huntley",
		"landstalker",
		"mesa",
		"mesa2",
	   "patriot",
		"radi",
		"rocoto",
		"seminole",
		"serrano",
	   "xls",
		"xls2"
	};

	inline static const char* trailerbackend[]
	{
	   "armytanker",
		"armytrailer",
		"armytrailer2",
		"baletrailer",
		"boattrailer",
	   "docktrailer",
		"freighttrailer",
		"graintrailer",
		"proptrailer",
		"raketrailer",
	   "tanker",
		"tanker2",
		"tr2",
		"tr3",
		"tr4",
	   "trailerlogs",
		"trailers",
		"trailers2",
		"trailers3",
		"trailersmall",
	   "trflat",
		"tvtrailer"
	};

	inline static const char* train2backend[]
	{
	   "cablecar",
		"freight",
		"freightcar",
		"freightcont1",
		"freightcont2",
	   "freightgrain",
		"metrotrain",
		"tankercar"
	};

	inline static const char* utilitybackend[]
	{
	   "airtug",
		"caddy",
		"caddy2",
		"docktug",
		"forklift",
	   "mower",
		"ripley",
		"sadler",
		"sadler2",
		"scrap",
	   "towtruck",
		"towtruck2",
		"tractor",
		"tractor2",
		"tractor3",
	   "utillitruck",
		"utillitruck2",
		"utillitruck3"
	};

	inline static const char* vanbackend[]
	{
	   "bison",
		"bison2",
		"bison3",
		"bobcatxl",
		"boxville",
	   "boxville2",
		"boxville3",
		"boxville4",
		"burrito",
		"burrito2",
	   "burrito3",
		"burrito4",
		"burrito5",
		"camper",
		"gburrito",
	   "gburrito2",
		"journey",
		"minivan",
		"minivan2",
		"paradise",
	   "pony",
		"pony2",
		"rumpo",
		"rumpo2",
		"rumpo3",
	   "speedo",
		"speedo2",
		"surfer",
		"surfer2",
		"taco",
	   "youga",
		"youga2"
	};

	enum eVehicleModTypes
	{
		MOD_SPOILER = 0,
		MOD_FRONTBUMPER = 1,
		MOD_REARBUMPER = 2,
		MOD_SIDESKIRT = 3,
		MOD_EXHAUST = 4,
		MOD_CHASSIS = 5, // or roll cage
		MOD_GRILLE = 6,
		MOD_HOOD = 7,
		MOD_FENDER = 8,
		MOD_RIGHTFENDER = 9,
		MOD_ROOF = 10,
		MOD_ENGINE = 11,
		MOD_BRAKES = 12,
		MOD_TRANSMISSION = 13,
		MOD_HORNS = 14,
		MOD_SUSPENSION = 15,
		MOD_ARMOR = 16,
		MOD_UNK17 = 17, // ModToggleTurbo use 18
		MOD_TURBO = 18,
		MOD_UNK19 = 19, // ModToggleTireSmoke use 20
		MOD_TIRESMOKE = 20,
		MOD_UNK21 = 21, // ModToggleXenon use 22
		MOD_XENONLIGHTS = 22,
		MOD_FRONTWHEELS = 23,
		MOD_BACKWHEELS = 24, // Bikes only

		// Benny's
		MOD_PLATEHOLDER = 25,
		MOD_VANITY_PLATES = 26,
		MOD_TRIM = 27,
		MOD_ORNAMENTS = 28,
		MOD_DASHBOARD = 29,
		MOD_DIAL = 30,
		MOD_DOOR_SPEAKER = 31,
		MOD_SEATS = 32,
		MOD_STEERINGWHEEL = 33,
		MOD_SHIFTER_LEAVERS = 34,
		MOD_PLAQUES = 35,
		MOD_SPEAKERS = 36,
		MOD_TRUNK = 37,
		MOD_HYDRAULICS = 38,
		MOD_ENGINE_BLOCK = 39,
		MOD_AIR_FILTER = 40,
		MOD_STRUTS = 41,
		MOD_ARCH_COVER = 42,
		MOD_AERIALS = 43,
		MOD_TRIM_2 = 44,
		MOD_TANK = 45,
		MOD_WINDOWS = 46,
		MOD_UNK47 = 47, // idk
		MOD_LIVERY = 48,
	};
#define VK_KEY_0	0x30      //('0')	0
#define VK_KEY_1	0x31      //('1')	1
#define VK_KEY_2	0x32      //('2')	2
#define VK_KEY_3	0x33      //('3')	3
#define VK_KEY_4	0x34      //('4')	4
#define VK_KEY_5	0x35      //('5')	5
#define VK_KEY_6	0x36      //('6')	6
#define VK_KEY_7	0x37      //('7')	7
#define VK_KEY_8	0x38      //('8')	8
#define VK_KEY_9	0x39      //('9')	9
#define VK_KEY_A	0x41      //('A')	A
#define VK_KEY_B	0x42      //('B')	B
#define VK_KEY_C	0x43      //('C')	C
#define VK_KEY_D	0x44      //('D')	D
#define VK_KEY_E	0x45      //('E')	E
#define VK_KEY_F	0x46      //('F')	F
#define VK_KEY_G	0x47      //('G')	G
#define VK_KEY_H	0x48      //('H')	H
#define VK_KEY_I	0x49      //('//I')	I
#define VK_KEY_J	0x4A      //('J')	J
#define VK_KEY_K	0x4B      //('K')	K
#define VK_KEY_L	0x4C      //('L')	L
#define VK_KEY_M	0x4D      //('M')	M
#define VK_KEY_N	0x4E      //('N')	N
#define VK_KEY_O	0x4F      //('O')	O
#define VK_KEY_P	0x50      //('P')	P
#define VK_KEY_Q	0x51      //('Q')	Q
#define VK_KEY_R	0x52      //('R')	R
#define VK_KEY_S	0x53      //('S')	S
#define VK_KEY_T	0x54      //('T')	T
#define VK_KEY_U	0x55      //('U')	U
#define VK_KEY_V	0x56      //('V')	V
#define VK_KEY_W	0x57      //('W')	W
#define VK_KEY_X	0x58      //('X')	X
#define VK_KEY_Y	0x59      //('Y')	Y
#define VK_KEY_Z	0x5A      //('Z')	Z
#define VK_KEY_ADD  0x6B      //('+')   +
}

namespace PedOptions {

	inline auto animationPos = 0;
	inline std::vector<const char*> animationHelperList;
	struct animArrHelper { std::string animLabel, animName, animId; };
	inline std::vector<animArrHelper> animationList = {
		 { "Pole Dance", "mini@strip_club@pole_dance@pole_dance1", "pd_dance_01" },
		 { "Push Ups", "amb@world_human_push_ups@male@base", "base" },
		 { "Sit Ups", "amb@world_human_sit_ups@male@base", "base" },
		 { "Meditation", "rcmcollect_paperleadinout@", "meditiate_idle" },
		 { "On Fire", "random@arrests", "kneeling_arrest_idle" },
		 { "Celebrate", "rcmfanatic1celebrate", "celebrate" },
		 { "Electrocution", "ragdoll@human", "electrocute" },
		 { "Suicide", "mp_suicide", "pistol" },
		 { "Showering", "mp_safehouseshower@male@", "male_shower_idle_b" },
		 { "Sex Receiver", "rcmpaparazzo_2", "shag_loop_poppy" },
		 { "Sex Giver", "rcmpaparazzo_2", "shag_loop_a" },
		 { "Stripper Dance", "mini@strip_club@private_dance@part1", "priv_dance_p1" },
		 { "Freak Out", "missfbi5ig_30monkeys", "monkey_b_freakout_loop" },
		 { "Poop", "missfbi3ig_0", "shit_loop_trev" },
		 { "Arm Wrestling Face A", "mini@arm_wrestling", "nuetral_idle_b_face" },
		 { "Arm Wrestling Face B", "mini@arm_wrestling", "nuetral_idle_a_face" },
		 { "Arm Wrestling Face Win B", "mini@arm_wrestling", "win_b_ped_b_face" },
		 { "Arm Wrestling Face Win A", "mini@arm_wrestling", "win_a_ped_b_face" },
		 { "Security Guard Idle", "anim@move_m@security_guard", "idle" },
		 { "Security Guard Idle 2", "anim@move_m@security_guard", "idle_var_05" },
		 { "Security Guard Idle 3", "anim@move_m@security_guard", "idle_var_01" },
		 { "Dart Throw", "anim@amb@clubhouse@mini@darts@", "throw_idle_a_down" },
		 { "Dart Outro", "anim@amb@clubhouse@mini@darts@", "outro" },
		 { "Beast Transformation", "mp_am_hold_up", "WARY_LOOP" },
		 { "Wary Loop", "ANIM@MP_FM_EVENT@INTRO", "BEAST_TRANSFORM" },
		 { "Park Attenant", "amb@world_human_car_park_attendant@male@base", "base" },
		 { "Robbery Worried", "random@robbery", "stand_worried_female" },
		 { "Robbery Flee", "random@robbery", "exit_flee" },
		 { "Robbery Distressed", "random@robbery", "f_distressed_loop" },
		 { "Robbery Kneel", "random@shop_robbery", "kneel_loop_p" },
		 { "Robbery Action P", "random@shop_robbery", "robbery_action_p" },
		 { "Monkey Dance", "missfbi5ig_30monkeys", "monkey_a_freakout_loop" },
	};
	inline std::vector<const char*> scenarios_vars_frontend = {
	"Paparazzi",
	"Drug Dealer",
	"Drinking Coffee",
	"Playing Instruments",
	"Flexing",
	"Jogging",
	"Binoculars",
	"Clipboard",
	"Bench Press",
	"Chin Ups",
	"BBQ",
	"Superhero",
	"Fishing",
	"Security",
	"Leaf Blower",
	"Film Shocking Event",
	"Idle Cop",
	"Drinking",
	"Play Golf",
	"Welding",
	"Smoking Weed",
	"Hammering",
	"Play Tennis",
	"Jack Hammer",
	"Seat Armchair",
	"Seat Bar Chair",
	"Seat Bench",
	"Seat Sun Lounger",
	"Seat Chair",
	"Fixing Vehicle",
	"Yoga",
	"Medic Time Of Death",
	"Tourist Map",
	"Police Investigate",
	"Partying",
	"Night Woman High Class",
	"Night Woman Low Class",
	"Sleeping",
	"Stupor"
	};

	inline std::vector<const char*> scenarios_vars_backend = {
		"WORLD_HUMAN_PAPARAZZI",
		"WORLD_HUMAN_DRUG_DEALER_HARD",
		"WORLD_HUMAN_AA_COFFEE",
		"WORLD_HUMAN_MUSICIAN",
		"WORLD_HUMAN_MUSCLE_FLEX",
		"WORLD_HUMAN_JOG_STANDING",
		"WORLD_HUMAN_BINOCULARS",
		"WORLD_HUMAN_CLIPBOARD",
		"PROP_HUMAN_SEAT_MUSCLE_BENCH_PRESS",
		"PROP_HUMAN_MUSCLE_CHIN_UPS",
		"PROP_HUMAN_BBQ",
		"WORLD_HUMAN_SUPERHERO",
		"WORLD_HUMAN_STAND_FISHING",
		"WORLD_HUMAN_SECURITY_SHINE_TORCH",
		"WORLD_HUMAN_GARDENER_LEAF_BLOWER",
		"WORLD_HUMAN_MOBILE_FILM_SHOCKING",
		"WORLD_HUMAN_COP_IDLES",
		"WORLD_HUMAN_DRINKING",
		"WORLD_HUMAN_GOLF_PLAYER",
		"WORLD_HUMAN_WELDING",
		"WORLD_HUMAN_SMOKING_POT",
		"WORLD_HUMAN_HAMMERING",
		"WORLD_HUMAN_TENNIS_PLAYER",
		"WORLD_HUMAN_CONST_DRILL",
		"PROP_HUMAN_SEAT_ARMCHAIR",
		"PROP_HUMAN_SEAT_BAR",
		"PROP_HUMAN_SEAT_BENCH",
		"PROP_HUMAN_SEAT_SUNLOUNGER",
		"PROP_HUMAN_SEAT_CHAIR",
		"WORLD_HUMAN_VEHICLE_MECHANIC",
		"WORLD_HUMAN_YOGA",
		"CODE_HUMAN_MEDIC_TIME_OF_DEATH",
		"WORLD_HUMAN_TOURIST_MAP",
		"CODE_HUMAN_POLICE_INVESTIGATE",
		"WORLD_HUMAN_PARTYING",
		"WORLD_HUMAN_PROSTITUTE_HIGH_CLASS",
		"WORLD_HUMAN_PROSTITUTE_LOW_CLASS",
		"WORLD_HUMAN_BUM_SLUMPED",
		"WORLD_HUMAN_STUPOR",

	};


	inline std::vector<const char*> visionstyle_vars_frontend = {
		"Chop",
		"Silverlake Water",
		"Night Lighting",
		"White Out",
		"Camera BW",
		"Camera Security",
		"Camera Security Buzz",
		"Canyon Mission",
		"Police",
		"Damaged",
		"Bank HLWD",
		"Death",
		"Drugs 1",
		"Drugs 2",
		"Drugs 3",
		"Prologue",
		"Prologue Reflection",
		"Prolouge Shootout 1",
		"Prolouge Shootout 2",
		"Cinema",
		"cinema 001",
		"Pulse",
		"Race Turbo Dark",
		"Race Turbo Flash",
		"Race Turbo Light",
		"Ranch",
		"Red Mist",
		"Red Mist Blend",
		"UFO",
		"UFO Deathray",
		"Under Water",
		"Tunnel",
		"Stoned",
		"Faint",
		"Blooming Light",
		"Bag",
		"Building Top",
		"Shooting Black Out",
		"Shooting Shining Light",
	};
	inline std::vector<const char*> visiontyle_vars_backend = {
		"CHOP",
		"WATER_silverlake",
		"whitenightlighting",
		"WhiteOut",
		"CAMERA_BW",
		"CAMERA_secuirity",
		"CAMERA_secuirity_FUZZ",
		"canyon_mission",
		"Cops",
		"Damage",
		"Bank_HLWD",
		"MP_death_grade",
		"drug_drive_blend01",
		"drug_drive_blend02",
		"drug_flying_01",
		"Prologue",
		"prologue_reflection_opt",
		"prologue_shootout",
		"Prologue_shootout_opt",
		"Cinema",
		"cinema_001",
		"Pulse",
		"RaceTurboDark",
		"RaceTurboFlash",
		"RaceTurboLight",
		"Ranch",
		"REDMIST",
		"REDMIST_blend",
		"UFO",
		"ufo_deathray",
		"underwater",
		"Tunnel",
		"Barry1_Stoned",
		"BarryFadeOut",
		"BloomLight",
		"buildingTOP",
		"BulletTimeDark",
		"BulletTimeLight",

	};

	inline int walkstyle_pos = 0;
	inline int vision_pos = 0;
	inline int scenario_pos = 0;
	inline std::vector<const char*> walkstyle_vars_frontend = {
		"Generic Male",
		"Generic Female",
		"Police",
		"Gangster",
		"Hipster",
		"Hobo",
		"Fat (Imp User Moment)",
		"Lester the Molester",
		"Drunk",
		"Moderately Drunk",
		"Very Drunk",
		"Lady's of the night",
		"Alien",
		"Business",
		"Causal",
		"Clipboard",
		"Coward",
		"On fire",
		"Afraid",
		"Hiking",
		"Hurrying",
		"Injured",
		"Bully",
		"Muscle",
		"Quick",
		"Sad (Extra Depressed)",
		"Shady",
		"Shocked",
		"Arrogant",
		"Handbag",
		"Heels",
		"? (Unknown Action)",
		"Leaf Blower",
		"Tazered",
		"Tough Guy",
		"Bag",
	};
	inline std::vector<const char*> walkstyle_vars_backend = {
		"move_m@generic",
		"move_f@generic",
		"move_cop@action",
		"move_m@gangster@generic",
		"move_m@hipster@a",
		"move_m@hobo@a",
		"move_m@fat@a",
		"move_lester_CaneUp",
		"move_m@drunk@a",
		"move_m@drunk@moderatedrunk",
		"move_m@drunk@verydrunk",
		"move_f@sexy@a",
		"move_m@alien",
		"move_m@busines@a",
		"move_m@casual@a",
		"move_m@clipboard",
		"move_m@fire",
		"move_m@flee@a",
		"move_m@hiking",
		"move_m@hurry",
		"move_injured_generic",
		"move_m@intimidation@1h",
		"move_m@muscle@a",
		"move_m@quick",
		"move_m@sad",
		"move_m@shadyped@a",
		"move_m@shocked@a",
		"move_f@arrogant@a",
		"move_f@handbag",
		"move_f@heels",
		"move_p_m_one",
		"move_m@leaf_blower",
		"move_m@bail_bond_tazered",
		"move_m@tough_guy@",
		"move_m@bag",
	};
}

namespace PedModels {

	inline int Animals_pos = 0;
	inline std::vector<const char*> Animals = {
		"A_C_Humpback","A_C_Boar","A_C_Chickenhawk","A_C_Chimp","A_C_Chop","A_C_Cormorant","A_C_Cow","A_C_Coyote","A_C_Crow","A_C_Deer","A_C_Fish","A_C_Hen","A_C_Husky","A_C_MtLion","A_C_Pig","A_C_Pigeon","A_C_Rat","A_C_Retriever",
		"A_C_Rhesus","A_C_Rottweiler", "A_C_Pug","A_C_Poodle","A_C_Westy","A_C_Seagull","A_C_SharkTiger","A_C_Shepherd", "A_C_Cat_01", "A_C_Rabbit_01", "A_C_KillerWhale", "A_C_SharkHammer", "A_C_SharkTiger", "A_C_Dolphin", "A_C_Panther",
	};
	inline int Crash_pos = 0;
	inline std::vector<const char*> Crash = {
		"A_C_Humpback","A_C_Fish","A_C_KillerWhale","A_C_SharkHammer","A_C_SharkTiger","A_C_Dolphin",
	};
	inline int Storycharacter_pos = 0;
	inline std::vector<const char*> Storycharacter = {
		"IG_TylerDix","IG_Wade","IG_Zimbor","IG_Abigail","IG_AmandaTownley","IG_Andreas","IG_Ashley","IG_BallasOG","IG_Bankman","IG_Barry","IG_BestMen","IG_Beverly","IG_Brad","IG_Bride","IG_Car3guy1","IG_Car3guy2","IG_Casey",
		"IG_Chef","IG_ChengSr","IG_ChrisFormage","IG_Clay","IG_ClayPain","IG_Cletus","IG_Dale","IG_DaveNorton","IG_Denise","IG_Devin","IG_Dom","IG_Dreyfuss","IG_DrFriedlander","IG_Fabien","IG_FBISuit_01","IG_Floyd","IG_Groom",
		"IG_Hao","IG_Hunter","IG_Janet","ig_JAY_Norris","IG_JewelAss","IG_JimmyBoston","IG_JimmyDiSanto","IG_JoeMinuteMan","ig_JohnnyKlebitz","IG_Josef","IG_Josh","IG_KerryMcIntosh","IG_LamarDavis","IG_Lazlow","IG_LesterCrest",
		"IG_LifeInvad_01","IG_LifeInvad_02","IG_Magenta","IG_Manuel","IG_Marnie","IG_MaryAnn","IG_Maude","IG_Michelle","IG_Milton","IG_Molly","IG_MRK","IG_MrsPhillips","IG_MRS_Thornhill","IG_Natalia","IG_NervousRon","IG_Nigel",
		"IG_Old_Man1A","IG_Old_Man2","IG_Omega","IG_ONeil","IG_Orleans","IG_Ortega","IG_Paper","IG_Patricia","IG_Priest","IG_ProlSec_02","IG_Ramp_Gang","IG_Ramp_Hic","IG_Ramp_Hipster","IG_Ramp_Mex","IG_RoccoPelosi","IG_RussianDrunk",
		"IG_Screen_Writer","IG_SiemonYetarian","IG_Solomon","IG_SteveHains","IG_Stretch","IG_Talina","IG_Tanisha","IG_TaoCheng","IG_TaosTranslator","ig_TennisCoach","IG_Terry","IG_TomEpsilon","IG_Tonya","IG_TracyDiSanto","IG_TrafficWarden",
		"CS_AmandaTownley","CS_Andreas", "cs_ashley","CS_Bankman","CS_Barry","CS_Beverly","CS_Brad","CS_BradCadaver","CS_Carbuyer","CS_Casey","CS_ChengSr","CS_ChrisFormage","CS_Clay","CS_Dale","CS_DaveNorton","cs_debra","cs_denise","CS_Devin","CS_Dom","CS_Dreyfuss",
		"CS_DrFriedlander","CS_Fabien","CS_FBISuit_01","CS_Floyd","CS_Guadalope","cs_gurk","CS_Hunter","CS_Janet","CS_JewelAss","CS_JimmyBoston","CS_JimmyDiSanto","CS_JoeMinuteMan","CS_JohnnyKlebitz","CS_Josef","CS_Josh","CS_LamarDavis",
		"CS_Lazlow","CS_LesterCrest","CS_LifeInvad_01","CS_Magenta","CS_Manuel","CS_Marnie","CS_MartinMadrazo","CS_MaryAnn","CS_Michelle","CS_Milton","CS_Molly","CS_MovPremF_01","CS_MovPremMale","CS_MRK","CS_MrsPhillips","CS_MRS_Thornhill",
		"CS_Natalia","CS_NervousRon","CS_Nigel","CS_Old_Man1A","CS_Old_Man2","CS_Omega","CS_Orleans","CS_Paper","CS_Patricia","CS_Priest","CS_ProlSec_02","CS_RussianDrunk","CS_SiemonYetarian","CS_Solomon","CS_SteveHains","CS_Stretch",
		"CS_Tanisha","CS_TaoCheng","CS_TaosTranslator","CS_TennisCoach","CS_Terry","CS_Tom","CS_TomEpsilon","CS_TracyDiSanto","CS_Wade","CS_Zimbor",
	};
	inline int Female_pos = 0;
	inline std::vector<const char*> Female = {
		"s_f_y_clubbar_02", "s_f_y_beachbarstaff_01", "s_f_y_casino_01","S_F_Y_Stripper_01","S_F_Y_AirHostess_01","S_F_Y_Bartender_01","S_F_Y_Baywatch_01","S_F_Y_Cop_01","S_F_Y_Factory_01","S_F_Y_Hooker_01","S_F_Y_Hooker_02","S_F_Y_Hooker_03","S_F_Y_Migrant_01","S_F_Y_MovPrem_01","S_F_Y_Ranger_01",
		"S_F_Y_Scrubs_01","S_F_Y_Sheriff_01","S_F_Y_Shop_LOW","S_F_Y_Shop_MID","S_F_Y_StripperLite","S_F_Y_Stripper_01","S_F_Y_Stripper_02","S_F_Y_SweatShop_01", "U_F_Y_BikerChic","U_F_Y_COMJane","U_F_Y_corpse_01","U_F_Y_corpse_02",
		"U_F_Y_HotPosh_01","U_F_Y_JewelAss_01","U_F_Y_Mistress","U_F_Y_PoppyMich","U_F_Y_Princess","U_F_Y_SpyActress","A_F_Y_Tennis_01","A_F_Y_Tourist_01","A_F_Y_Tourist_02","A_F_Y_Vinewood_01",
		"A_F_Y_Vinewood_02","A_F_Y_Vinewood_03","A_F_Y_Vinewood_04","A_F_Y_Yoga_01", "A_F_Y_BevHills_03","A_F_Y_BevHills_04","A_F_Y_Business_01","A_F_Y_Business_02","A_F_Y_Business_03","A_F_Y_Business_04","A_F_Y_EastSA_01","A_F_Y_EastSA_02","A_F_Y_EastSA_03","A_F_Y_Epsilon_01","A_F_Y_Fitness_01",
		"A_F_Y_Fitness_02","A_F_Y_GenHot_01","A_F_Y_Golfer_01","A_F_Y_Hiker_01","A_F_Y_Hippie_01","A_F_Y_Hipster_01","A_F_Y_Hipster_02","A_F_Y_Hipster_03","A_F_Y_Hipster_04","A_F_Y_Indian_01","A_F_Y_Juggalo_01","A_F_Y_Runner_01",
		"A_F_Y_RurMeth_01","A_F_Y_SCDressy_01","A_F_Y_Skater_01","A_F_Y_SouCent_01","A_F_Y_SouCent_02","A_F_Y_SouCent_03","A_F_Y_Beach_01","A_F_Y_BevHills_01","A_F_Y_BevHills_02", "A_F_M_Beach_01","A_F_M_BevHills_01","A_F_M_BevHills_02","A_F_M_BodyBuild_01","A_F_M_Business_02","A_F_M_Downtown_01","A_F_M_EastSA_01",
		"A_F_M_EastSA_02","A_F_M_FatBla_01","A_F_M_FatCult_01","A_F_M_FatWhite_01","A_F_M_KTown_01","A_F_M_KTown_02","A_F_M_ProlHost_01","A_F_M_Salton_01","A_F_M_SkidRow_01","A_F_M_SouCentMC_01","A_F_M_SouCent_01","A_F_M_SouCent_02",
		"A_F_M_Tourist_01","A_F_M_TrampBeac_01","A_F_M_Tramp_01","A_F_O_GenStreet_01","A_F_O_Indian_01","A_F_O_KTown_01","A_F_O_Salton_01","A_F_O_SouCent_01","A_F_O_SouCent_02","S_F_M_Fembarber","S_F_M_Maid_01","S_F_M_Shop_HIGH","G_F_Y_ballas_01","G_F_Y_Families_01","G_F_Y_Lost_01","G_F_Y_Vagos_01",
		"U_F_M_Corpse_01","U_F_M_Miranda","U_F_M_ProMourn_01","U_F_O_MovieStar","U_F_O_ProlHost_01","MP_F_Misty_01", "S_F_M_SweatShop_01", "MP_F_DeadHooker","MP_F_Freemode_01","MP_F_Misty_01","MP_F_StripperLite",
	};
	inline int Unclassed_pos = 0;
	inline std::vector<const char*> Unclassed = {
		 "U_M_Y_ImpoRage", "U_M_Y_Zombie_01", "S_M_Y_Swat_01", "S_M_Y_Pilot_01", "S_M_M_MovAlien_01", "S_M_M_HairDress_01","S_M_M_HighSec_01","S_M_M_HighSec_02","S_M_M_Janitor","S_M_M_LatHandy_01","S_M_M_LifeInvad_01","S_M_M_Linecook","S_M_M_LSMetro_01","S_M_M_Mariachi_01","S_M_M_Marine_01","S_M_M_Marine_02","S_M_M_Migrant_01",
		"S_M_M_MovAlien_01","S_M_M_MovPrem_01","S_M_M_MovSpace_01","S_M_M_Paramedic_01","S_M_M_Pilot_01","S_M_M_Pilot_02","S_M_M_Postal_01","S_M_M_Postal_02","S_M_M_PrisGuard_01","S_M_M_Scientist_01","S_M_M_Security_01","S_M_M_SnowCop_01",
		"S_M_M_StrPerf_01","S_M_M_StrPreach_01","S_M_M_StrVend_01","S_M_M_Trucker_01","S_M_M_UPS_01","S_M_M_UPS_02","S_M_O_Busker_01","S_M_Y_AirWorker","S_M_Y_AmmuCity_01","S_M_Y_ArmyMech_01","S_M_Y_Autopsy_01","S_M_Y_Barman_01","S_M_Y_BayWatch_01",
		"S_M_Y_BlackOps_01","S_M_Y_BlackOps_02","S_M_Y_BlackOps_03","S_M_Y_BusBoy_01","S_M_Y_Chef_01","S_M_Y_Clown_01","S_M_Y_Construct_01","S_M_Y_Construct_02","S_M_Y_Cop_01","S_M_Y_Dealer_01","S_M_Y_DevinSec_01","S_M_Y_DockWork_01","S_M_Y_Doorman_01",
		"S_M_Y_DWService_01","S_M_Y_DWService_02","S_M_Y_Factory_01","S_M_Y_Fireman_01","S_M_Y_Garbage","S_M_Y_Grip_01","S_M_Y_HwayCop_01","S_M_Y_Marine_01","S_M_Y_Marine_02","S_M_Y_Marine_03","S_M_Y_Mime","S_M_Y_PestCont_01",
		"S_M_Y_PrisMuscl_01","S_M_Y_Ranger_01","S_M_Y_Robber_01","S_M_Y_Sheriff_01","S_M_Y_Shop_MASK","S_M_Y_StrVend_01","S_M_Y_USCG_01","S_M_Y_Valet_01","S_M_Y_Waiter_01",
		"S_M_Y_WinClean_01","S_M_Y_XMech_01","S_M_Y_XMech_02","U_M_M_Aldinapoli","U_M_M_BankMan","U_M_M_BikeHire_01","U_M_M_FIBArchitect","U_M_M_FilmDirector","U_M_M_GlenStank_01",
		"U_M_M_Griff_01","U_M_M_Jesus_01","U_M_M_JewelSec_01","U_M_M_JewelThief","U_M_M_MarkFost","U_M_M_PartyTarget","U_M_M_ProlSec_01","U_M_M_ProMourn_01","U_M_M_RivalPap","U_M_M_SpyActor","U_M_M_WillyFist","U_M_O_FinGuru_01",
		"U_M_O_TapHillBilly","U_M_O_Tramp_01","U_M_Y_Abner","U_M_Y_AntonB",	"U_M_Y_BabyD","U_M_Y_Baygor","U_M_Y_BurgerDrug_01","U_M_Y_Chip","U_M_Y_Cyclist_01","U_M_Y_Guido_01","U_M_Y_GunVend_01","U_M_Y_Hippie_01",
		"U_M_Y_ImpoRage","U_M_Y_Justin","U_M_Y_Mani","U_M_Y_MilitaryBum","U_M_Y_Paparazzi","U_M_Y_Party_01","U_M_Y_Pogo_01","U_M_Y_Prisoner_01","U_M_Y_ProlDriver_01","U_M_Y_RSRanger_01","U_M_Y_SBike","U_M_Y_StagGrm_01","U_M_Y_Tattoo_01", "S_M_Y_Swat_01", "U_M_Y_FIBMugger_01", "U_M_M_FIBArchitect", "U_M_Y_MilitaryBum", "MP_M_FIBSec_01", "S_M_M_FIBOffice_01","S_M_M_FIBOffice_02", "U_M_Y_MilitaryBum", "S_M_M_Marine_01","S_M_M_Marine_02", "S_M_Y_Prisoner_01",
		"A_M_Y_BreakDance_01","A_M_Y_BusiCas_01","A_M_Y_Business_01","A_M_Y_Business_02","A_M_Y_Business_03", "A_M_Y_Golfer_01","A_M_Y_HasJew_01","A_M_Y_Hiker_01", "A_M_Y_Hippy_01","A_M_Y_Hipster_01","A_M_Y_Hipster_02",
		"A_M_Y_Hipster_03", "CSB_PrologueDriver","CSB_ProlSec","CSB_Ramp_gang","CSB_Ramp_hic","CSB_Ramp_hipster", "CSB_Ramp_mex","CSB_Reporter","CSB_RoccoPelosi","CSB_Screen_Writer","CSB_TrafficWarden","G_M_M_ArmBoss_01",
		"G_M_M_ArmGoon_01","G_M_M_ArmLieut_01","G_M_M_ChemWork_01","G_M_M_ChiBoss_01","G_M_M_ChiCold_01","G_M_M_ChiGoon_01","G_M_M_ChiGoon_02","G_M_M_KorBoss_01","G_M_M_MexBoss_01","G_M_M_MexBoss_02","G_M_Y_ArmGoon_02","G_M_Y_Azteca_01",
		"G_M_Y_BallaEast_01","G_M_Y_BallaOrig_01","G_M_Y_BallaSout_01","G_M_Y_FamCA_01","G_M_Y_FamDNF_01","G_M_Y_FamFor_01","G_M_Y_Korean_01","G_M_Y_Korean_02","G_M_Y_KorLieut_01","G_M_Y_Lost_01","G_M_Y_Lost_02","G_M_Y_Lost_03",
		"G_M_Y_MexGang_01","G_M_Y_MexGoon_01","G_M_Y_MexGoon_02","G_M_Y_MexGoon_03","G_M_Y_PoloGoon_01","G_M_Y_PoloGoon_02","G_M_Y_SalvaBoss_01","G_M_Y_SalvaGoon_01","G_M_Y_SalvaGoon_02","G_M_Y_SalvaGoon_03","G_M_Y_StrPunk_01","G_M_Y_StrPunk_02",
		"HC_Driver","HC_Gunman","HC_Hacker", "A_M_M_ACult_01","A_M_M_AfriAmer_01", "A_M_M_BevHills_01","A_M_M_BevHills_02","A_M_M_Business_01",
		"A_M_M_EastSA_01","A_M_M_EastSA_02","A_M_M_Farmer_01","A_M_M_FatLatin_01","A_M_M_GenFat_01","A_M_M_GenFat_02","A_M_M_Golfer_01","A_M_M_HasJew_01","A_M_M_Hillbilly_01","A_M_M_Hillbilly_02","A_M_M_Indian_01",
		"A_M_M_KTown_01","A_M_M_Malibu_01","A_M_M_MexCntry_01","A_M_M_MexLabor_01","A_M_M_OG_Boss_01","A_M_M_Paparazzi_01","A_M_M_Polynesian_01","A_M_M_ProlHost_01","A_M_M_RurMeth_01","A_M_M_Salton_01","A_M_M_Salton_02",
		"A_M_M_Salton_03","A_M_M_Salton_04","A_M_M_Skater_01","A_M_M_Skidrow_01","A_M_M_SoCenLat_01","A_M_M_SouCent_01","A_M_M_SouCent_02","A_M_M_SouCent_03","A_M_M_SouCent_04","A_M_M_StLat_02","A_M_M_Tennis_01",
		"A_M_M_Tourist_01","A_M_M_TrampBeac_01","A_M_M_Tramp_01","A_M_M_TranVest_01","A_M_M_TranVest_02","A_M_O_ACult_01","A_M_O_ACult_02","A_M_O_Beach_01","A_M_O_GenStreet_01","A_M_O_KTown_01","A_M_O_Salton_01",
		"A_M_O_SouCent_01","A_M_O_SouCent_02","A_M_O_SouCent_03","A_M_O_Tramp_01","A_M_Y_ACult_01","A_M_Y_ACult_02","A_M_Y_BeachVesp_01","A_M_Y_BeachVesp_02", "A_M_Y_BevHills_01",
		"A_M_Y_BevHills_02", "A_M_Y_Cyclist_01","A_M_Y_DHill_01","A_M_Y_Downtown_01","A_M_Y_EastSA_01","A_M_Y_EastSA_02","A_M_Y_Epsilon_01","A_M_Y_Epsilon_02","A_M_Y_Gay_01","A_M_Y_Gay_02", "A_M_Y_GenStreet_01","A_M_Y_GenStreet_02","A_M_Y_Indian_01","A_M_Y_Jetski_01","A_M_Y_Juggalo_01","A_M_Y_KTown_01","A_M_Y_KTown_02","A_M_Y_Latino_01","A_M_Y_MethHead_01","A_M_Y_MexThug_01","A_M_Y_MotoX_01","A_M_Y_MotoX_02", "CSB_Customer","CSB_Denise_friend",
		"CSB_FOS_rep","CSB_G","CSB_Groom","CSB_Grove_str_dlr","CSB_Hao","CSB_Hugh","CSB_Imran","CSB_Janitor","CSB_Maude","CSB_MWeather","CSB_Ortega","CSB_Oscar","MP_G_M_Pros_01","MP_HeadTargets","MP_M_Claude_01","MP_M_ExArmy_01","MP_M_FamDD_01","MP_M_FIBSec_01","MP_M_Freemode_01",
		"MP_M_Marston_01","MP_M_Niko_01","MP_M_ShopKeep_01","MP_S_M_Armoured_01","Player_One","Player_Two","Player_Zero",
		"S_M_M_AmmuCountry","S_M_M_Armoured_01","S_M_M_Armoured_02","S_M_M_AutoShop_01",
		"S_M_M_AutoShop_02","S_M_M_Bouncer_01","S_M_M_ChemSec_01","S_M_M_CIASec_01","S_M_M_CntryBar_01","S_M_M_DockWork_01","S_M_M_Doctor_01","S_M_M_Gaffer_01","S_M_M_Gardener_01","S_M_M_GenTransport"
	};
	inline int updatemodels_pos = 0;
	inline std::vector<const char*> updatemodels = {
		"S_M_M_RaceOrg_01", "A_M_Y_CarClub_01", "A_F_Y_CarClub_01", "S_F_M_RetailStaff_01", "G_M_M_Prisoners_01", "S_M_M_Tattoo_01", "G_M_M_Slasher_01", "IG_LilDee",
		"IG_DrugDealer", "CSB_DrugDealer", "A_M_Y_TattooCust_01", "IG_Moodyman_02", "CSB_Moodyman_02", "S_M_M_Autoshop_03", "S_F_M_Autoshop_01", "IG_Benny_02", "IG_AviSchwartzman_02",
		"CSB_AviSchwartzman_02", "IG_Sessanta", "CSB_Sessanta", "IG_Mimi", "CSB_Mimi", "IG_Hao_02", "CSB_Hao_02",
	};
}

namespace Ptfx {

	inline int PtfxName_pos = 0;
	inline std::vector<const char*> PtfxName = {
" alien disintegrate", " alien teleport", " clown appears", " clown death", " fbi dd breach smoke",  " agency3b elec box", " heist ornate banknotes", " rcpap1 camera",  " firework xmas burst rgw",
" sol1 sniper impact",  " ojdg4 boat exp",  " ojdg4 water exp", " drug grd train exp",  " drug grd plane exp", " fbi exp building", " agency3b heli expl",  " josh3 light explosion", " exp clown",
" meth pipe smoke", " ex2 car impact"," mp plane landing tyre smoke"," wheel burnout"," indep firework starburst", " indep firework fountain", " indep firework shotburst"," indep firework trailburst",
" powerplay beast appear", " ie jug mask flame"," adversary judgement ash"," adversary judgement lens dirt", " alien charging"," alien impact"," alien beam"," ch finale laser"," stunts bomb fuse",
" xs money rain"," ba club champagne spray"," ba club drink pour",
	};

	inline const char* PtfxCaller[] =
	{
		"scr_rcbarry1", "scr_rcbarry1", "scr_rcbarry2", "scr_rcbarry2", "scr_agencyheist", "scr_agencyheistb", "scr_ornate_heist", "scr_rcpaparazzo1", "proj_xmas_firework", "scr_martin1", "scr_oddjobtraffickingair",
		"scr_oddjobtraffickingair", "scr_oddjobtraffickingair", "scr_oddjobtraffickingair", "scr_agencyheist", "scr_agencyheist", "scr_josh3", "scr_rcbarry2", "scr_familyscenem", "scr_exile2", "scr_mp_creator", "scr_recartheft",
		"scr_indep_fireworks","scr_indep_fireworks","scr_indep_fireworks","scr_indep_fireworks","scr_powerplay","scr_impexp_jug","scr_bike_adversary","scr_bike_adversary","scr_rcbarry1","scr_rcbarry1","scr_rcbarry1","scr_ch_finale",
		"scr_stunts","scr_xs_celebration","scr_ba_club","scr_ba_club",
	};
	inline const char* PtfxCaller2[] =
	{
		"scr_alien_disintegrate", "scr_alien_teleport", "scr_clown_appears", "scr_clown_death", "scr_fbi_dd_breach_smoke",  "scr_agency3b_elec_box", "scr_heist_ornate_banknotes", "scr_rcpap1_camera",  "scr_firework_xmas_burst_rgw",
		 "scr_sol1_sniper_impact",  "scr_ojdg4_boat_exp",  "scr_ojdg4_water_exp", "scr_drug_grd_train_exp",  "scr_drug_grd_plane_exp", "scr_fbi_exp_building", "scr_agency3b_heli_expl",  "scr_josh3_light_explosion", "scr_exp_clown",
		"scr_meth_pipe_smoke", "scr_ex2_car_impact","scr_mp_plane_landing_tyre_smoke","scr_wheel_burnout","scr_indep_firework_starburst", "scr_indep_firework_fountain", "scr_indep_firework_shotburst","scr_indep_firework_trailburst",
		 "scr_powerplay_beast_appear", "scr_ie_jug_mask_flame","scr_adversary_judgement_ash","scr_adversary_judgement_lens_dirt", "scr_alien_charging","scr_alien_impact","scr_alien_beam","scr_ch_finale_laser","scr_stunts_bomb_fuse",
		 "scr_xs_money_rain","scr_ba_club_champagne_spray","scr_ba_club_drink_pour",
	};
}

namespace Ammunation {
	inline int weaponNames_pos = 0;
	inline std::vector<const char*> weaponNames1 = {
	"dagger",
	"bat",
	"bottle",
	"crowbar",
	"unarmed",
	"flashlight",
	"golfclub",
	"hammer",
	"hatchet",
	"knuckle",
	"knife",
	"machete",
	"switchblade",
	"nightstick",
	"wrench",
	"battleaxe",
	"poolcue",
	"stone_hatchet",
	"pistol",
	"pistol_mk2",
	"combatpistol",
	"appistol",
	"stungun",
	"pistol50",
	"snspistol",
	"snspistol_mk2",
	"heavypistol",
	"vintagepistol",
	"flaregun",
	"marksmanpistol",
	"revolver",
	"revolver_mk2",
	"doubleaction",
	"raypistol",
	"ceramicpistol",
	"navyrevolver",
	"microsmg",
	"smg",
	"smg_mk2",
	"assaultsmg",
	"combatpdw",
	"machinepistol",
	"minismg",
	"raycarbine",
	"pumpshotgun",
	"pumpshotgun_mk2",
	"sawnoffshotgun",
	"assaultshotgun",
	"bullpupshotgun",
	"musket",
	"heavyshotgun",
	"dbshotgun",
	"autoshotgun",
	"assaultrifle",
	"assaultrifle_mk2",
	"carbinerifle",
	"carbinerifle_mk2",
	"advancedrifle",
	"specialcarbine",
	"specialcarbine_mk2",
	"bullpuprifle",
	"bullpuprifle_mk2",
	"compactrifle",
	"mg",
	"combatmg",
	"combatmg_mk2",
	"gusenberg",
	"sniperrifle",
	"heavysniper",
	"heavysniper_mk2",
	"marksmanrifle",
	"marksmanrifle_mk2",
	"rpg",
	"grenadelauncher",
	"grenadelauncher_smoke",
	"minigun",
	"firework",
	"railgun",
	"hominglauncher",
	"compactlauncher",
	"rayminigun",
	"grenade",
	"bzgas",
	"smokegrenade",
	"flare",
	"molotov",
	"stickybomb",
	"proxmine",
	"snowball",
	"pipebomb",
	"ball",
	"petrolcan",
	"fireextinguisher",
	"parachute",
	"hazardcan",
	"militaryrifle",
	"combatshotgun",
	"gadgetpistol"
	};


	inline const char* weaponNames[] =
	{
		"weapon_dagger", "weapon_bat", "weapon_bottle", "weapon_crowbar",
		"weapon_unarmed", "weapon_flashlight", "weapon_golfclub", "weapon_hammer",
		"weapon_hatchet", "weapon_knuckle", "weapon_knife", "weapon_machete",
		"weapon_switchblade", "weapon_nightstick", "weapon_wrench", "weapon_battleaxe",
		"weapon_poolcue", "weapon_stone_hatchet", "weapon_pistol", "weapon_pistol_mk2",
		"weapon_combatpistol", "weapon_appistol", "weapon_stungun", "weapon_pistol50",
		"weapon_snspistol", "weapon_snspistol_mk2", "weapon_heavypistol", "weapon_vintagepistol",
		"weapon_flaregun", "weapon_marksmanpistol", "weapon_revolver", "weapon_revolver_mk2",
		"weapon_doubleaction", "weapon_raypistol", "weapon_ceramicpistol", "weapon_navyrevolver",
		"weapon_microsmg", "weapon_smg", "weapon_smg_mk2", "weapon_assaultsmg",
		"weapon_combatpdw", "weapon_machinepistol", "weapon_minismg", "weapon_raycarbine",
		"weapon_pumpshotgun", "weapon_pumpshotgun_mk2", "weapon_sawnoffshotgun", "weapon_assaultshotgun",
		"weapon_bullpupshotgun", "weapon_musket", "weapon_heavyshotgun", "weapon_dbshotgun",
		"weapon_autoshotgun", "weapon_assaultrifle", "weapon_assaultrifle_mk2", "weapon_carbinerifle",
		"weapon_carbinerifle_mk2", "weapon_advancedrifle", "weapon_specialcarbine", "weapon_specialcarbine_mk2",
		"weapon_bullpuprifle", "weapon_bullpuprifle_mk2", "weapon_compactrifle", "weapon_mg",
		"weapon_combatmg", "weapon_combatmg_mk2", "weapon_gusenberg", "weapon_sniperrifle",
		"weapon_heavysniper", "weapon_heavysniper_mk2", "weapon_marksmanrifle", "weapon_marksmanrifle_mk2",
		"weapon_rpg", "weapon_grenadelauncher", "weapon_grenadelauncher_smoke", "weapon_minigun",
		"weapon_firework", "weapon_railgun", "weapon_hominglauncher", "weapon_compactlauncher",
		"weapon_rayminigun", "weapon_grenade", "weapon_bzgas", "weapon_smokegrenade",
		"weapon_flare", "weapon_molotov", "weapon_stickybomb", "weapon_proxmine",
		"weapon_snowball", "weapon_pipebomb", "weapon_ball", "weapon_petrolcan",
		"weapon_fireextinguisher", "weapon_parachute", "weapon_hazardcan", "weapon_militaryrifle",
		"weapon_combatshotgun", "weapon_gadgetpistol"
	};


	inline int assaultsmg_pos = 0;
	inline std::vector<const char*> assaultsmg = {
	"Normal Magazine",
	"Extended Magazine",
	"Scope",
	"Flash Light",
	"Suppressor",
	"Varmod Camo",

	};

	inline std::vector<const char*> assaultsmg_backend = {
	"COMPONENT_ASSAULTSMG_CLIP_01",
	"COMPONENT_ASSAULTSMG_CLIP_02",
	"component_at_scope_macro",
	"COMPONENT_AT_AR_FLSH",
	"COMPONENT_AT_AR_SUPP_02",
	"COMPONENT_ASSAULTSMG_VARMOD_LOWRIDER",
	};



	inline int SMGMKIIAmmo_pos = 0;
	inline std::vector<const char*> SMGMKIIAmmo = {
	"Normal Magazine",
	"Extended Magazine",
	"Tracer",
	"Incendiary",
	"Hollow point",
	"FMJ",

	};

	inline std::vector<const char*> SMGMKIIAmmo_backend = {
	"COMPONENT_SMG_MK2_CLIP_01",
	"COMPONENT_SMG_MK2_CLIP_02",
	"COMPONENT_SMG_MK2_CLIP_TRACER",
	"COMPONENT_SMG_MK2_CLIP_INCENDIARY",
	"COMPONENT_SMG_MK2_CLIP_HOLLOWPOINT",
	"COMPONENT_SMG_MK2_CLIP_FMJ",
	};

	inline int SMGMKIIAttach_pos = 0;
	inline std::vector<const char*> SMGMKIIAttach = {
	"Flash Light",
	"Suppressor",
	"Holographic Sight",
	"Small Scope",
	"Medium Scope",
	};



	inline std::vector<const char*> SMGMKIIAttach_backend = {
	"COMPONENT_AT_AR_FLSH",
	"COMPONENT_AT_PI_SUPP",
	"COMPONENT_AT_SIGHTS_SMG",
	"COMPONENT_AT_SCOPE_MACRO_02_SMG_MK2",
	"COMPONENT_AT_SCOPE_SMALL_SMG_MK2",
	};

	inline int SMGMKIIMuzzle_pos = 0;
	inline std::vector<const char*> SMGMKIIMuzzle = {
	"Tactical Muzzle Brake",
	"Fat-End Muzzle Brake",
	"Precision Muzzle Brake",
	"Heavy Duty Muzzle Brake",
	"Slanted Muzzle Brake",
	"Slanted Muzzle Brake",
	"Split-End Muzzle Brake",
	"Normal Barrel",
	"Heavy Barrel",
	};


	inline std::vector<const char*> SMGMKIIMuzzle_backend = {
	"COMPONENT_AT_MUZZLE_01",
	"COMPONENT_AT_MUZZLE_02",
	"COMPONENT_AT_MUZZLE_03",
	"COMPONENT_AT_MUZZLE_04",
	"COMPONENT_AT_MUZZLE_05",
	"COMPONENT_AT_MUZZLE_06",
	"COMPONENT_AT_MUZZLE_07",
	"COMPONENT_AT_SB_BARREL_01",
	"COMPONENT_AT_SB_BARREL_02",
	};

	inline int SMGMKIICamo_pos = 0;
	inline std::vector<const char*> SMGMKIICamo = {
	"Digital Camo",
	"Brushstroke Camo",
	"Woodland Camo",
	"Skull",
	"Sessanta Nove",
	"Perseus",
	"Leopard",
	"Zebra",
	"Geometric",
	"Boom",
	"Patriotic",
	};


	inline std::vector<const char*> SMGMKIICamo_backend = {
	"COMPONENT_SMG_MK2_MK2_CAMO",
	"COMPONENT_SMG_MK2_MK2_CAMO_02",
	"COMPONENT_SMG_MK2_MK2_CAMO_03",
	"COMPONENT_SMG_MK2_MK2_CAMO_04",
	"COMPONENT_SMG_MK2_MK2_CAMO_05",
	"COMPONENT_SMG_MK2_MK2_CAMO_06",
	"COMPONENT_SMG_MK2_MK2_CAMO_07",
	"COMPONENT_SMG_MK2_MK2_CAMO_08",
	"COMPONENT_SMG_MK2_MK2_CAMO_09",
	"COMPONENT_SMG_MK2_MK2_CAMO_10",
	"COMPONENT_SMG_MK2_MK2_CAMO_IND_01",
	};




	inline int smg_pos = 0;
	inline std::vector<const char*> smg = {
	"Normal Magazine",
	"Extended Magazine",
	"Drum Magazine",
	"Scope",
	"Flash Light",
	"Suppressor",
	"Varmod Camo",

	};

	inline std::vector<const char*> smg_backend = {
	"component_microsmg_clip_01",
	"component_microsmg_clip_02",
	"component_smg_clip_03",
	"component_at_scope_macro",
	"COMPONENT_AT_AR_FLSH",
	"component_at_pi_supp",
	"component_smg_varmod_luxe",
	};


	inline int microsmg_pos = 0;
	inline std::vector<const char*> microsmg = {
	"Normal Magazine",
	"Extended Magazine",
	"Scope",
	"Flash Light",
	"Suppressor",
	"Varmod Camo",

	};

	inline std::vector<const char*> microsmg_backend = {
	"component_microsmg_clip_01",
	"component_microsmg_clip_02",
	"component_at_scope_macro",
	"component_at_pi_flsh",
	"component_at_ar_supp_02",
	"COMPONENT_MICROSMG_VARMOD_LUXE",
	};


	inline int combatpw_pos = 0;
	inline std::vector<const char*> combatpw = {
	"Normal Magazine",
	"Extended Magazine",
	"Drum Magazine",
	"Scope",
	"Flash Light",
	"Hand Grip",

	};

	inline std::vector<const char*> combatpw_backend = {
	"component_combatpdw_clip_01",
	"component_combatpdw_clip_02",
	"component_combatpdw_clip_03",
	"COMPONENT_AT_SCOPE_SMALL",
	"COMPONENT_AT_AR_FLSH",
	"COMPONENT_AT_AR_AFGRIP",
	};


	inline int revolverMKIIAmmo_pos = 0;
	inline std::vector<const char*> revolverMKIIAmmo = {
	"Normal Magazine",
	"Tracer",
	"Incendiary",
	"Hollow point",
	"FMJ",

	};

	inline std::vector<const char*> revolverMKIIAmmo_backend = {
	"COMPONENT_REVOLVER_MK2_CLIP_01",
	"COMPONENT_REVOLVER_MK2_CLIP_TRACER",
	"COMPONENT_REVOLVER_MK2_CLIP_INCENDIARY",
	"COMPONENT_REVOLVER_MK2_CLIP_HOLLOWPOINT",
	"COMPONENT_REVOLVER_MK2_CLIP_FMJ",
	};




	inline int revolverMKIIAttach_pos = 0;
	inline std::vector<const char*> revolverMKIIAttach = {
	"Holographic Sight",
	"Flash Light",
	"Small Scope",
	"Compensator",
	};

	inline std::vector<const char*> revolverMKIIAttach_backend = {
	"COMPONENT_AT_SIGHTS",
	"COMPONENT_AT_PI_FLSH",
	"COMPONENT_AT_SCOPE_MACRO_MK2",
	"COMPONENT_AT_PI_COMP_03",
	};


	inline int revolverMKIICamo_pos = 0;
	inline std::vector<const char*> revolverMKIICamo = {
	"Digital Camo",
	"Brushstroke Camo",
	"Woodland Camo",
	"Skull",
	"Sessanta Nove",
	"Perseus",
	"Leopard",
	"Zebra",
	"Geometric",
	"Boom",
	"Patriotic",
	};

	inline std::vector<const char*> revolverMKIICamo_backend = {
	"COMPONENT_REVOLVER_MK2_MK2_CAMO",
	"COMPONENT_REVOLVER_MK2_MK2_CAMO_02",
	"COMPONENT_REVOLVER_MK2_MK2_CAMO_03",
	"COMPONENT_REVOLVER_MK2_MK2_CAMO_04",
	"COMPONENT_REVOLVER_MK2_MK2_CAMO_05",
	"COMPONENT_REVOLVER_MK2_MK2_CAMO_06",
	"COMPONENT_REVOLVER_MK2_MK2_CAMO_07",
	"COMPONENT_REVOLVER_MK2_MK2_CAMO_08",
	"COMPONENT_REVOLVER_MK2_MK2_CAMO_09",
	"COMPONENT_REVOLVER_MK2_MK2_CAMO_10",
	"COMPONENT_REVOLVER_MK2_MK2_CAMO_IND_01",
	};


	inline int revolverAttach_pos = 0;
	inline std::vector<const char*> revolverAttach = {
	"Varmod Goon",
	"Varmod Boss",
	};

	inline std::vector<const char*> revolverAttach_backend = {
	"COMPONENT_REVOLVER_VARMOD_GOON",
	"COMPONENT_REVOLVER_VARMOD_BOSS",
	};


	inline int SNSMKIIpistolAmmo_pos = 0;
	inline std::vector<const char*> SNSMKIIpistolAmmo = {
	"Normal Magazine",
	"Extended Magazine",
	"Tracer",
	"Incendiary",
	"Hollow point",
	"FMJ",

	};

	inline std::vector<const char*> SNSMKIIpistolAmmo_backend = {
	"COMPONENT_SNSPISTOL_MK2_CLIP_01",
	"COMPONENT_SNSPISTOL_MK2_CLIP_02",
	"COMPONENT_SNSPISTOL_MK2_CLIP_TRACER",
	"COMPONENT_SNSPISTOL_MK2_CLIP_INCENDIARY",
	"COMPONENT_SNSPISTOL_MK2_CLIP_HOLLOWPOINT",
	"COMPONENT_SNSPISTOL_MK2_CLIP_FMJ",
	};


	inline int SNSMKIIpistolAttach_pos = 0;
	inline std::vector<const char*> SNSMKIIpistolAttach = {
	"Scope",
	"Flashlight",
	"Suppressor",
	"Compensator",
	};

	inline std::vector<const char*> SNSMKIIpistolAttach_backend = {
	"COMPONENT_AT_PI_RAIL_02",
	"COMPONENT_AT_PI_FLSH_03",
	"COMPONENT_AT_PI_SUPP_02",
	"COMPONENT_AT_PI_COMP_02",
	};



	inline int SNSMKIIpistoCamo_pos = 0;
	inline std::vector<const char*> SNSMKIIpistoCamo = {
	"Digital Camo",
	"Brushstroke Camo",
	"Woodland Camo",
	"Skull",
	"Sessanta Nove",
	"Perseus",
	"Leopard",
	"Zebra",
	"Geometric",
	"Boom",
	"Patriotic",
	};

	inline std::vector<const char*> SNSMKIIpistoCamo_backend = {
	"COMPONENT_SNSPISTOL_MK2_CAMO",
	"COMPONENT_SNSPISTOL_MK2_CAMO_02",
	"COMPONENT_SNSPISTOL_MK2_CAMO_03",
	"COMPONENT_SNSPISTOL_MK2_CAMO_04",
	"COMPONENT_SNSPISTOL_MK2_CAMO_05",
	"COMPONENT_SNSPISTOL_MK2_CAMO_06",
	"COMPONENT_SNSPISTOL_MK2_CAMO_07",
	"COMPONENT_SNSPISTOL_MK2_CAMO_08",
	"COMPONENT_SNSPISTOL_MK2_CAMO_09",
	"COMPONENT_SNSPISTOL_MK2_CAMO_10",
	"COMPONENT_SNSPISTOL_MK2_CAMO_IND_01",
	};


	inline int Heavypistol_pos = 0;
	inline std::vector<const char*> Heavypistol = {
	"Extended Magazine",
	"Flashlight",
	"Suppressor",
	"Varmod Camo",
	};

	inline std::vector<const char*> Heavypistol_backend = {
	"COMPONENT_HEAVYPISTOL_CLIP_02",
	"COMPONENT_AT_PI_FLSH",
	"COMPONENT_AT_PI_SUPP",
	"COMPONENT_HEAVYPISTOL_VARMOD_LUXE",
	};


	inline int Callpistol_pos = 0;
	inline std::vector<const char*> Callpistol = {
	"Extended Magazine",
	"Flashlight",
	"Suppressor",
	"Varmod Camo",
	};

	inline std::vector<const char*> Callpistol_backend = {
	"COMPONENT_PISTOL50_CLIP_02",
	"COMPONENT_AT_PI_FLSH",
	"COMPONENT_AT_PI_SUPP_02",
	"COMPONENT_PISTOL50_VARMOD_LUXE",
	};



	inline int Apppistol_pos = 0;
	inline std::vector<const char*> Apppistol = {
	"Extended Magazine",
	"Flashlight",
	"Suppressor",
	"Varmod Camo",
	};

	inline std::vector<const char*> Apppistol_backend = {
	"COMPONENT_APPISTOL_CLIP_02",
	"COMPONENT_AT_PI_FLSH",
	"COMPONENT_AT_PI_SUPP_02",
	"COMPONENT_APPISTOL_VARMOD_LUXE",
	};

	inline int combatpistol_pos = 0;
	inline std::vector<const char*> combatpistol = {
	"Extended Magazine",
	"Flashlight",
	"Suppressor",
	"Varmod Camo",
	};

	inline std::vector<const char*> combatpistol_backend = {
	"COMPONENT_COMBATPISTOL_CLIP_02",
	"COMPONENT_AT_PI_FLSH",
	"COMPONENT_AT_PI_SUPP_02",
	"COMPONENT_COMBATPISTOL_VARMOD_LOWRIDER",
	};


	inline int Pistol_pos = 0;
	inline std::vector<const char*> Pistol = {
	"Extended Magazine",
	"Flashlight",
	"Suppressor",
	"Varmod Camo",
	};

	inline std::vector<const char*> Pistol_backend = {
	"COMPONENT_PISTOL_CLIP_02",
	"COMPONENT_AT_PI_FLSH",
	"COMPONENT_AT_PI_SUPP_02",
	"COMPONENT_PISTOL_VARMOD_LUXE",
	};




	inline int SwitchBlade_pos = 0;
	inline std::vector<const char*> SwitchBlade = {
	"Basic Handle",
	"VIP Handle",
	"Body Guard Handle",
	};

	inline std::vector<const char*> SwitchBlade_backend = {
	"COMPONENT_SWITCHBLADE_VARMOD_BASE",
	"COMPONENT_SWITCHBLADE_VARMOD_VAR1",
	"COMPONENT_SWITCHBLADE_VARMOD_VAR2",
	};



	inline int KnuckleDuster_pos = 0;
	inline std::vector<const char*> KnuckleDuster = {
	"Varmod Ballas",
	"Varmod Base",
	"Varmod Diamond",
	"Varmod Dollar",
	"Varmod Hate",
	"Varmod King",
	"Varmod Love",
	"Varmod Pimp",
	"Varmod Player",
	"Varmod Vagos",
	};

	inline std::vector<const char*> KnuckleDuster_backend = {
	"COMPONENT_KNUCKLE_VARMOD_BALLAS",
	"COMPONENT_KNUCKLE_VARMOD_BASE",
	"COMPONENT_KNUCKLE_VARMOD_DIAMOND",
	"COMPONENT_KNUCKLE_VARMOD_DOLLAR",
	"COMPONENT_KNUCKLE_VARMOD_HATE",
	"COMPONENT_KNUCKLE_VARMOD_KING",
	"COMPONENT_KNUCKLE_VARMOD_LOVE",
	"COMPONENT_KNUCKLE_VARMOD_PIMP",
	"COMPONENT_KNUCKLE_VARMOD_PLAYER",
	"COMPONENT_KNUCKLE_VARMOD_VAGOS",
	};




	inline int BullUpV2_Rifle_pos = 0;
	inline std::vector<const char*> BullUpV2_Rifle = {
		"Extended Magazine",
		"Varmod Camo",
		"Hand Grip",
		"Scope",
		"Flash Light",
		"Suppressor",
	};

	inline std::vector<const char*> BullUpV2_Rifle_backend = {
		"component_bullpuprifle_clip_02",
		"component_bullpuprifle_varmod_low",
		"COMPONENT_AT_AR_AFGRIP",
		"COMPONENT_AT_SCOPE_SMALL",
		"COMPONENT_AT_AR_FLSH",
		"component_at_ar_supp",
	};

	inline int Military_Rifle_pos = 0;
	inline std::vector<const char*> Military_Rifle = {
		"Extended Magazine",
		"Normal Magazine",
		"Sight",
		"Scope",
		"Suppressor",
	};

	inline std::vector<const char*> Military_Rifle_backend = {
		"COMPONENT_MILITARYRIFLE_CLIP_02",
		"COMPONENT_MILITARYRIFLE_CLIP_01",
		"COMPONENT_MILITARYRIFLE_SIGHT_01",
		"COMPONENT_AT_SCOPE_SMALL",
		"component_at_ar_supp",
	};




	inline int Special_Carbine_pos = 0;
	inline std::vector<const char*> Special_Carbine = {
		"Extended Magazine",
		"Drum Magazine",
		"Scope",
		"Varmod Camo"
		"Flash Light",
		"Suppressor",
		"Grip",
	};

	inline std::vector<const char*> Special_Carbine_backend = {
		"component_specialcarbine_clip_02",
		"component_specialcarbine_clip_03",
		"component_at_scope_medium",
		"component_specialcarbine_varmod_lowrider",
		"component_at_ar_flsh",
		"component_at_ar_supp",
		"component_at_ar_afgrip",
	};




	inline int Advanced_Rifle_pos = 0;
	inline std::vector<const char*> Advanced_Rifle = {
		"Extended Magazine",
		"Scope",
		"Varmod Camo"
		"Flash Light",
		"Suppressor",
	};

	inline std::vector<const char*> Advanced_Rifle_backend = {
		"component_advancedrifle_clip_02",
		"COMPONENT_AT_SCOPE_SMALL",
		"component_advancedrifle_varmod_luxe",
		"component_at_ar_flsh",
		"component_at_ar_supp",
	};


	inline int Carbine_Rifle_pos = 0;
	inline std::vector<const char*> Carbine_Rifle = {
		"Extended Magazine",
		"Drum Magazine",
		"Scope",
		"Varmod Camo"
		"Flash Light",
		"Hand Grip",
		"Suppressor",
	};

	inline std::vector<const char*> Carbine_Rifle_backend = {
		"component_carbinerifle_clip_02",
		"component_carbinerifle_clip_03",
		"component_at_scope_medium",
		"component_carbinerifle_varmod_luxe",
		"component_at_ar_flsh",
		"component_at_ar_afgrip",
		"component_at_ar_supp",
	};


	inline int Assault_Rifle_pos = 0;
	inline std::vector<const char*> Assault_Rifle = {
		"Extended Magazine",
		"Drum Magazine",
		"Scope",
		"Varmod Camo"
		"Flash Light",
		"Hand Grip",
		"Suppressor",
	};

	inline std::vector<const char*> Assault_Rifle_backend = {
		"component_assaultrifle_clip_02",
		"component_assaultrifle_clip_03",
		"COMPONENT_AT_SCOPE_MACRO",
		"component_assaultrifle_varmod_luxe",
		"component_at_ar_flsh",
		"component_at_ar_afgrip",
		"component_at_ar_supp",
	};

	inline int Marks_Man_pos = 0;
	inline std::vector<const char*> Marks_Man = {
		"Extended Magazine",
		"Flash Light",
		"Hand Grip",
		"Suppressor",
	};

	inline std::vector<const char*> Marks_Man_backend = {
		"component_marksmanrifle_clip_02",
		"component_at_ar_flsh",
		"component_at_ar_afgrip",
		"component_at_ar_supp",
	};



	inline int Smoke_Launcher_pos = 0;
	inline std::vector<const char*> Smoke_Launcher = {
		"Scope",
		"Flash Light",
		"Hand Grip",
	};

	inline std::vector<const char*> Smoke_Launcher_backend = {
		"COMPONENT_AT_SCOPE_SMALL",
		"component_at_ar_flsh",
		"component_at_ar_afgrip",
	};


	inline const char* AmmoNames[] =
	{
		"PICKUP_AMMO_FIREWORK", "PICKUP_AMMO_FLAREGUN", "PICKUP_AMMO_MINIGUN", "PICKUP_AMMO_RPG",
		"PICKUP_AMMO_GRENADELAUNCHER", "PICKUP_AMMO_SNIPER", "PICKUP_AMMO_SHOTGUN", "PICKUP_AMMO_MG",
		"PICKUP_AMMO_RIFLE", "PICKUP_AMMO_SMG", "PICKUP_AMMO_PISTOL",
	};

}