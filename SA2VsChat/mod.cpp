#include "pch.h"
#include <cstdio>
#include <random>
#include "SA2ModLoader.h"
#include "Trampoline.h"
#include "..\SA2CharSel\SA2CharSel\Base.h"

std::random_device rd;
std::default_random_engine gen(rd());


StoryEntry HeroStorySequence[] = {
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 0, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_Sonic, LevelIDs_CityEscape, -1, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_Sonic, LevelIDs_BigFoot, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 2, 3, -1, -1 },
	{ StoryEntryType_Level, Characters_Knuckles, LevelIDs_WildCanyon, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 4, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_MechTails, LevelIDs_TailsVsEggman1, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 5, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_MechTails, LevelIDs_PrisonLane, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 6, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_Sonic, LevelIDs_MetalHarbor, -1, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_Sonic, LevelIDs_SonicVsShadow1, -1, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_Sonic, LevelIDs_GreenForest, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 409, 50, -1, -1 },
	{ StoryEntryType_Level, Characters_Knuckles, LevelIDs_PumpkinHill, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 51, 411, 11, -1 },
	{ StoryEntryType_Level, Characters_MechTails, LevelIDs_MissionStreet, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 52, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_Knuckles, LevelIDs_AquaticMine, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 14, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 15, 16, -1, -1 },
	{ StoryEntryType_Level, Characters_MechTails, LevelIDs_HiddenBase, -1, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_Sonic, LevelIDs_PyramidCave, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 17, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_Knuckles, LevelIDs_DeathChamber, -1, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_Knuckles, LevelIDs_KingBoomBoo, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 19, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_Sonic, LevelIDs_EggGolemS, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 420, 21, -1, -1 },
	{ StoryEntryType_Level, Characters_MechTails, LevelIDs_EternalEngine, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 22, 53, -1, -1 },
	{ StoryEntryType_Level, Characters_Knuckles, LevelIDs_MeteorHerd, -1, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_Knuckles, LevelIDs_KnucklesVsRouge, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 24, 54, -1, -1 },
	{ StoryEntryType_Level, Characters_Sonic, LevelIDs_CrazyGadget, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 25, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_MechTails, LevelIDs_TailsVsEggman2, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 26, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_Sonic, LevelIDs_FinalRush, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 27, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_Sonic, LevelIDs_SonicVsShadow2, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 28, -1, -1, -1 },
	{ StoryEntryType_Credits, Characters_Sonic, LevelIDs_BasicTest, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 429, -1, -1, -1 },
	{ StoryEntryType_End }
};

StoryEntry DarkStorySequence[] = {
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 100, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_MechEggman, LevelIDs_IronGate, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 101, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_Shadow, LevelIDs_HotShot, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 102, 103, -1, -1 },
	{ StoryEntryType_Level, Characters_Rouge, LevelIDs_DryLagoon, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 150, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_MechEggman, LevelIDs_SandOcean, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 105, 106, -1, -1 },
	{ StoryEntryType_Level, Characters_Shadow, LevelIDs_RadicalHighway, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 107, 151, -1, -1 },
	{ StoryEntryType_Level, Characters_Rouge, LevelIDs_EggQuarters, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 109, 152, -1, -1 },
	{ StoryEntryType_Level, Characters_MechEggman, LevelIDs_LostColony, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 111, 112, -1, -1 },
	{ StoryEntryType_Level, Characters_MechEggman, LevelIDs_WeaponsBed, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 113, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_MechEggman, LevelIDs_TailsVsEggman1, -1, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_Rouge, LevelIDs_SecurityHall, -1, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_Rouge, LevelIDs_FlyingDog, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 116, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_Shadow, LevelIDs_WhiteJungle, -1, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_Shadow, LevelIDs_SonicVsShadow1, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 118, 409, 119, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 153, 411, 120, 154 },
	{ StoryEntryType_Level, Characters_Shadow, LevelIDs_SkyRail, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 122, 123, -1, -1 },
	{ StoryEntryType_Level, Characters_MechEggman, LevelIDs_EggGolemE, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 524, 124, -1, -1 },
	{ StoryEntryType_Level, Characters_Rouge, LevelIDs_MadSpace, -1, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_Rouge, LevelIDs_KnucklesVsRouge, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 126, 127, -1, -1 },
	{ StoryEntryType_Level, Characters_MechEggman, LevelIDs_CosmicWall, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 128, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_MechEggman, LevelIDs_TailsVsEggman2, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 129, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_Shadow, LevelIDs_FinalChase, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 130, -1, -1, -1 },
	{ StoryEntryType_Level, Characters_Shadow, LevelIDs_SonicVsShadow2, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 131, -1, -1, -1 },
	{ StoryEntryType_Credits, Characters_Sonic, LevelIDs_BasicTest, -1, -1, -1, -1 },
	{ StoryEntryType_Event, Characters_Sonic, LevelIDs_BasicTest, 532, -1, -1, -1 },
	{ StoryEntryType_End }
};

PointerInfo pointers[] = {
	ptrdecl(0x4586C5, &HeroStorySequence),
	ptrdecl(0x4586E6, &DarkStorySequence)
};


DataPointer(int, StageMessageCount, 0xB5D200);
ObjectMaster* LoadOmochao(NJS_VECTOR* position)
{
	ObjectMaster* obj = AllocateObjectMaster(Omochao_Main, 2, "ObjectMessenger");
	if (obj)
	{
		EntityData1* v7 = AllocateEntityData1();
		if (v7)
		{
			obj->Data1.Entity = v7;
			void* v10 = AllocateEntityData2();
			if (v10)
			{
				obj->EntityData2 = (UnknownData2*)v10;
				v7->Position = *position;
				v7->Scale.x = (float)(gen() % StageMessageCount); // select a random hint from the level's hint message file
				v7->Scale.y = 15;
				v7->Scale.z = 0;
				v7->NextAction |= 3; // force Omochao to follow the player
				v7->Action = 5; // force Omochao into the talking action
				return obj;
			}
			else
				DeleteObject_(obj);
		}
		else
			DeleteObject_(obj);
	}
	return nullptr;
}

void CheckLoadOmochao(ObjectMaster* obj)
{
	if (*(void**)0xB5838C) // make sure Omochao's textures are loaded before spawning
	{
		LoadOmochao(&MainCharObj1[0]->Position);
		DeleteObject_(obj);
	}
}

double targetSize = 1;
double currentSize = 1;
double growthAmount = 0;
void SetTargetSize(double trgt)
{
	targetSize = trgt;
	growthAmount = abs(targetSize - currentSize) / 60;
}

const char* MusicList2[157];

// void __usercall(StoryEntry *a1@<edx>)


void (__stdcall* ResetVotes)(int eventno);


double gravmult = 1;
void __fastcall sub_459910_i(CharObj2Base* co2)
{
	switch (CurrentLevel)
	{
	case LevelIDs_FinalRush:
	case LevelIDs_MeteorHerd:
	case LevelIDs_FinalChase:
	case LevelIDs_CosmicWall:
	case LevelIDs_MadSpace:
	case LevelIDs_PlanetQuest:
	case LevelIDs_CosmicWall2P:
		switch (co2->CharID)
		{
		case Characters_Sonic:
		case Characters_Shadow:
		case Characters_Knuckles:
		case Characters_Rouge:
		case Characters_MechTails:
		case Characters_MechEggman:
			co2->PhysData.Gravity = 0.07 * gravmult;
			break;
		default:
			co2->PhysData.Gravity = PhysicsArray[CurrentLevel - LevelIDs_FinalRush].Gravity * gravmult;
			break;
		}
		break;
	default:
		co2->PhysData.Gravity = PhysicsArray[co2->CharID].Gravity * gravmult;
		break;
	}
}

void __fastcall sub_459910(CharObj2Base* co2)
{
	__asm { push ecx }
	sub_459910_i(co2);
	__asm { pop ecx }
}

void DoWaterThing(int a1, int* a2);
bool invwater = false;
Trampoline watertramp(0x494DF0, 0x494DFA, DoWaterThing);
void DoWaterThing(int a1, int *a2)
{
	((decltype(DoWaterThing)*)watertramp.Target())(a1, a2);
	if (invwater)
		a2[2] ^= 2;
}

void (__cdecl* CharLoadFuncs[])(int) = {
	LoadSonic,
	LoadShadow,
	LoadTails,
	LoadEggman,
	LoadKnuckles,
	LoadRouge,
	LoadMechTails,
	LoadMechEggman,
	LoadAmy,
	nullptr,
	nullptr,
	nullptr,
	LoadMetalSonic,
	LoadChaoWalker,
	LoadDarkChaoWalker,
	LoadTikal,
	LoadChaos
};

int fasttimer = 0;
int speedlevel = 0;
extern "C"
{
	bool IsFinalLevel()
	{
		if (CurrentLevel == LevelIDs_FinalHazard)
		{
			return true;
		}
		return false;
	}
	__declspec(dllexport) bool GiveItem(int item)
	{

		if (MainCharObj2[0] && !(MainCharObj2[0]->Powerups & Powerups_Dead) && CurrentLevel < LevelIDs_Route101280 )
		{
			
			
			if (IsFinalLevel())
			{
				//Invincibility... Crashes here for some reason so just refuse it.
				if (item == 10)
				{
					return false;
				}
				//Ring 1
				if (item == 1) 
				{
					RingCount[0] = RingCount[0] + 1;
					RingCount[1] = RingCount[1] + 1;
					return true;
				}
				//Ring 10
				if (item == 3)
				{
					RingCount[0] = RingCount[0] + 10;
					RingCount[1] = RingCount[1] + 10;
					return true;
				}
				//Ring 20
				if (item == 4)
				{
					RingCount[0] = RingCount[0] + 20;
					RingCount[1] = RingCount[1] + 20;
					return true;
				}
				DisplayItemBoxItem(0, ItemBox_Items[item].Texture);
				ItemBox_Items[item].Code(MainCharacter[0], 0);
				DisplayItemBoxItem(1, ItemBox_Items[item].Texture);
				ItemBox_Items[item].Code(MainCharacter[1], 1);
				return true;
			}
			else
			{
				DisplayItemBoxItem(0, ItemBox_Items[item].Texture);
				ItemBox_Items[item].Code(MainCharacter[0], 0);
			}
			return true;
		}
		return false;
	}

	__declspec(dllexport) bool SpawnOmochao()
	{
		if (GameState == GameStates_Ingame && CurrentLevel < LevelIDs_Route101280 && CurrentLevel != LevelIDs_FinalHazard)
		{
			AllocateObjectMaster(CheckLoadOmochao, 2, "CheckLoadOmochao");
			return true;
		}
		return false;
	}
	__declspec(dllexport) bool IsInGame()
	{
		if (GameState == GameStates_Ingame && PlayerPaused == 0 && ControllerEnabled && TimerFrames >= 2)
		{
			return true;
		}
		return false;
	}
	__declspec(dllexport) void PlayVoice(int id)
	{
		PlayVoice(0, id);
	}

	__declspec(dllexport) bool Stop()
	{
		if (MainCharObj2[0] && !(MainCharObj2[0]->Powerups & Powerups_Dead))
		{
			MainCharObj2[0]->Speed.x = 0;
			MainCharObj2[0]->Speed.y = 0;
			MainCharObj2[0]->Speed.z = 0;
			if (IsFinalLevel())
			{
				MainCharObj2[1]->Speed.x = 0;
				MainCharObj2[1]->Speed.y = 0;
				MainCharObj2[1]->Speed.z = 0;
			}
			return true;
		}
		return false;
	}

	__declspec(dllexport) void GottaGoFast()
	{
		fasttimer = 60;
	}

	__declspec(dllexport) void TsafOgAttog()
	{
		fasttimer = -60;
	}

	__declspec(dllexport) bool SuperJump()
	{
		if (MainCharObj2[0] && !(MainCharObj2[0]->Powerups & Powerups_Dead))
		{
			MainCharObj2[0]->Speed.y = MainCharObj2[0]->PhysData.VSpeedCap;
			if (IsFinalLevel())
			{
				MainCharObj2[1]->Speed.y = MainCharObj2[1]->PhysData.VSpeedCap;
			}
			return true;
		}
		return false;
	}

	__declspec(dllexport) bool PmujRepus()
	{
		if (MainCharObj2[0] && !(MainCharObj2[0]->Powerups & Powerups_Dead))
		{
			MainCharObj2[0]->Speed.y = -MainCharObj2[0]->PhysData.VSpeedCap;
			if (IsFinalLevel())
			{
				MainCharObj2[1]->Speed.y = -MainCharObj2[1]->PhysData.VSpeedCap;
			}
			return true;
		}
		return false;
	}
	
	int DoingTimeStopCounter = 0;
	__declspec(dllexport) bool TimeStop()
	{
		
		if (DoingTimeStopCounter == 0 && GameState == GameStates_Ingame && CurrentLevel < LevelIDs_Route101280
			&& CurrentLevel != LevelIDs_FinalHazard)
		{
		
			DoingTimeStopCounter = 900;
			TimeStopped |= 2;
			return true;
		}
		return false;
		
	}

	bool IsMechLevel()
	{

		if (CurrentLevel == LevelIDs_IronGate)
		{
			return true;
		}
		if (CurrentLevel == LevelIDs_SandOcean)
		{
			return true;
		}
		if (CurrentLevel == LevelIDs_WeaponsBed)
		{
			return true;
		}
		if (CurrentLevel == LevelIDs_LostColony)
		{
			return true;
		}
		if (CurrentLevel == LevelIDs_CannonsCoreE)
		{
			return true;
		}
		if (CurrentLevel == LevelIDs_CannonsCoreT)
		{
			return true;
		}
		if (CurrentLevel == LevelIDs_EggGolemE)
		{
			return true;
		}
		if (CurrentLevel == LevelIDs_TailsVsEggman2)
		{
			return true;
		}
		if (CurrentLevel == LevelIDs_PrisonLane)
		{
			return true;
		}
		if (CurrentLevel == LevelIDs_EternalEngine)
		{
			return true;
		}
		if (CurrentLevel == LevelIDs_TailsVsEggman1)
		{
			return true;
		}
		if (CurrentLevel == LevelIDs_MissionStreet)
		{
			return true;
		}
		return false; 
	}
	__declspec(dllexport) bool Die(const char* user)
	{
		if (IsInGame() && IsMechLevel() == false && MainCharObj2[0] && !(MainCharObj2[0]->Powerups & Powerups_Dead))
		{
			PrintDebug("Killed by %s!", user);
			KillPlayer(0);
			return true;
		}
		return false;
	}

	__declspec(dllexport) bool Win(const char* user)
	{
		if (IsInGame() && MainCharObj2[0] && !(MainCharObj2[0]->Powerups & Powerups_Dead))
		{
			PrintDebug("Level ended by %s!", user);
			AwardWin(0);
			return true;
		}
		return false;
	}

	int Sizetimer = 0;
	__declspec(dllexport) bool Grow()
	{
		
		if (Sizetimer == 0)
		{
			SetTargetSize(targetSize * 4);
			Sizetimer = 900; // 30 seconds
			return true;
		}
		
		return false;
	}
			

	__declspec(dllexport) bool Shrink()
	{
		if (Sizetimer == 0)
		{
			SetTargetSize(targetSize / 4);
			Sizetimer = 900; // 30 seconds
			return true;
		}
		return false;
	}

	__declspec(dllexport) void Bonus(int scr)
	{
		if (GameState == GameStates_Ingame)
			DispTechniqueScore_Load(scr);
	}

	__declspec(dllexport) void PlayMusic(int id)
	{
		PlayMusic(MusicList2[id]);
		ResetMusic();
	}
	int GravityTimer = 0;
	__declspec(dllexport) bool HighGravity()
	{
		if (MainCharObj1[0] && GravityTimer == 0)
		{
			GravityTimer = 900;
			gravmult *= 2;
			return true;
		}
		return false;
	}

	__declspec(dllexport) bool LowGravity()
	{
		if (MainCharObj1[0] && GravityTimer == 0)
		{
			GravityTimer = 900;
			gravmult /= 2;
			return true;
		}
		return false;
	}
	int SpeedTimer = 0;
	__declspec(dllexport) bool SpeedUp()
	{
		if (SpeedTimer == 0 && MainCharObj2[0] && speedlevel == 0)
		{
			speedlevel = 1;
			MainCharObj2[0]->PhysData.GroundAccel *= 3;
			MainCharObj2[0]->PhysData.MaxAccel *= 3;
			MainCharObj2[0]->PhysData.field_68 *= 3;
			if (IsFinalLevel())
			{
				MainCharObj2[1]->PhysData.GroundAccel *= 3;
				MainCharObj2[1]->PhysData.MaxAccel *= 3;
				MainCharObj2[1]->PhysData.field_68 *= 3;
			}
			SpeedTimer = 1800; //30sec
			return true;
		}
		return false;
	}

	__declspec(dllexport) bool SlowDown()
	{
		if (SpeedTimer == 0 && MainCharObj2[0] && speedlevel == 0)
		{
			speedlevel = 1;
			MainCharObj2[0]->PhysData.GroundAccel /= 3;
			MainCharObj2[0]->PhysData.MaxAccel /= 3;
			MainCharObj2[0]->PhysData.field_68 /= 3;
			if (IsFinalLevel())
			{
				MainCharObj2[1]->PhysData.GroundAccel /= 3;
				MainCharObj2[1]->PhysData.MaxAccel /= 3;
				MainCharObj2[1]->PhysData.field_68 /= 3;
			}
			SpeedTimer = 1800; //30sec
			return true;
		}
		return false;
	}


	/// <summary>
	/// This doesn't work. 
	/// 
	/// WHY DOESN'T IT WORK!? 
	/// </summary>
	/// <returns></returns>
	__declspec(dllexport) bool HealBoss()
	{
		return false;
		/*if (MainCharObj2[1] && MainCharObj2[1]->MechHP < 5)
		{
			++MainCharObj2[1]->MechHP;
			return true;
		}
		return false;*/

	}

	

	__declspec(dllexport) bool Confuse()
	{
		if (MainCharObj2[0] && !MainCharObj2[0]->ConfuseTime)
		{
			MainCharObj2[0]->ConfuseTime = 300;
			ConfuStar_Load(0);
			return true;
			
		}
		return false;
	}

	__declspec(dllexport) bool Earthquake()
	{
		if (MainCharacter[0])
		{
			char d2[]{ 0, 0 };
			ObjectMaster om{};
			om.Data2.Undefined = d2;
			Knuckles2PEarthquakeMan_Delete(&om);
			return true;
		}
		return false;
	}

	__declspec(dllexport) bool ToggleChaoKey()
	{
		if (MainCharacter[0])
		{
			HaveChaoKey ^= 1;
			return true;
		}
		return false;
	}

	__declspec(dllexport) void ToggleWater()
	{
		if (MainCharacter[0])
		{
			invwater = !invwater;
			if (invwater)
				switch (CurrentLevel)
				{
				case LevelIDs_SecurityHall:
				case LevelIDs_WildCanyon:
				case LevelIDs_MeteorHerd:
				case LevelIDs_KnucklesVsRouge:
				case LevelIDs_WildCanyon2P:
				case LevelIDs_MadSpace:
				case LevelIDs_PlanetQuest:
				case LevelIDs_KingBoomBoo:
				case LevelIDs_ChaoWorld:
					LoadDryLagoon2PCharAnims();
					break;
				}
		}
	}

	__declspec(dllexport) bool ChangeCharacter(char ch)
	{
		auto chfun = CharLoadFuncs[ch];
		if (!chfun) return false;
		ObjectMaster* obj = MainCharacter[0];
		if (!obj) return false;
		NJS_VECTOR pos = obj->Data1.Entity->Position;
		Rotation rot = obj->Data1.Entity->Rotation;
		NJS_VECTOR scl = obj->Data1.Entity->Scale;
		short pow = obj->Data2.Character->Powerups;
		NJS_VECTOR spd = obj->Data2.Character->Speed;
		obj->DeleteSub(obj);
		obj->DeleteSub = nullptr;
		obj->MainSub = DeleteObject_;
		chfun(0);
		obj = MainCharacter[0];
		obj->Data1.Entity->Position = pos;
		obj->Data1.Entity->Rotation = rot;
		obj->Data1.Entity->Scale = scl;
		obj->Data2.Character->Powerups = pow;
		obj->Data2.Character->Speed = spd;
		return true;
	}

	__declspec(dllexport) void SetResetVotesPtr(void(__stdcall* ptr)(int))
	{
		ResetVotes = ptr;
	}

	__declspec(dllexport) void OnFrame()
	{
		if (MainCharObj2[0])
		{
			MainCharObj2[0]->Upgrades |= ~Upgrades_SuperSonic;
		}
			
		//TimeStop Return Timer
		if (DoingTimeStopCounter > 0 && GameState == GameStates_Ingame)
		{
			if (--DoingTimeStopCounter == 0)
			{
				TimeStopped &= ~2;
			}
		}
		//Speed Timer
		if (SpeedTimer > 0)
		{
			if (--SpeedTimer == 0)
			{
				printf("Returned Phys To Normal!!!! \n");
				MainCharObj2[0]->PhysData.GroundAccel = PhysicsArray[MainCharObj2[0]->CharID2].GroundAccel;
				MainCharObj2[0]->PhysData.MaxAccel = PhysicsArray[MainCharObj2[0]->CharID2].MaxAccel;
				MainCharObj2[0]->PhysData.field_68 = PhysicsArray[MainCharObj2[0]->CharID2].field_68;
				if (IsFinalLevel())
				{
					MainCharObj2[1]->PhysData.GroundAccel = PhysicsArray[MainCharObj2[0]->CharID2].GroundAccel;
					MainCharObj2[1]->PhysData.MaxAccel = PhysicsArray[MainCharObj2[0]->CharID2].MaxAccel;
					MainCharObj2[1]->PhysData.field_68 = PhysicsArray[MainCharObj2[0]->CharID2].field_68;
				}
				//Speed level should be back to normal.
				//Speed Timer Done and reset.
				speedlevel = 0;
			}
		}
		//Gravity Return Timer
		if (GravityTimer > 0 && MainCharObj2[0])
		{
			if (--GravityTimer == 0)
			{
				printf("Returned Gravity To Normal!!!! \n");
				//Return Gravity to nomral
				MainCharObj2[0]->PhysData.Gravity = PhysicsArray[MainCharObj2[0]->CharID2].Gravity;
				if (IsFinalLevel())
				{
					MainCharObj2[1]->PhysData.Gravity = PhysicsArray[MainCharObj2[0]->CharID2].Gravity;
				}
				gravmult = 1;
			}
		}
		//Size Return Timer
		if (Sizetimer > 0 && MainCharObj2[0])
		{
			if (--Sizetimer == 0)
			{
				SetTargetSize(1);
			}
			
		}
		//Prevent a gameover.
		if (MainCharObj2[0] && Life_Count[0] < 99)
		{
			Life_Count[0] = 99;
		}
		if (MainCharObj1[0])
		{

			if (currentSize < targetSize)
			{
				currentSize += growthAmount;
				if (currentSize > targetSize)
					currentSize = targetSize;
				MainCharObj1[0]->Scale.x = (float)currentSize;
				MainCharObj1[0]->Scale.y = (float)currentSize;
				MainCharObj1[0]->Scale.z = (float)currentSize;
				if (IsFinalLevel())
				{
					MainCharObj1[1]->Scale.x = (float)currentSize;
					MainCharObj1[1]->Scale.y = (float)currentSize;
					MainCharObj1[1]->Scale.z = (float)currentSize;
				}
				
			}
			else if (currentSize > targetSize)
			{
				currentSize -= growthAmount;
				if (currentSize < targetSize)
					currentSize = targetSize;
				MainCharObj1[0]->Scale.x = (float)currentSize;
				MainCharObj1[0]->Scale.y = (float)currentSize;
				MainCharObj1[0]->Scale.z = (float)currentSize;
				if (IsFinalLevel())
				{
					MainCharObj1[1]->Scale.x = (float)currentSize;
					MainCharObj1[1]->Scale.y = (float)currentSize;
					MainCharObj1[1]->Scale.z = (float)currentSize;
				}
			}
		}
		else
		{
			targetSize = 1;
			currentSize = 1;
			growthAmount = 0;
			gravmult = 1;
			speedlevel = 0;
			invwater = false;
			for (int i = 0; i < DryLagoon2PCharAnims_Length; ++i)
			{
				short ind = DryLagoon2PCharAnims[i].Index;
				if (ind == -1) break;
				if (CharacterAnimations[ind].Animation == DryLagoon2PCharAnims[i].Animation)
				{
					CharacterAnimations[ind].Count = 0;
					CharacterAnimations[ind].Animation = nullptr;
				}
			}
		}
		if (MainCharObj2[0] && !(MainCharObj2[0]->Powerups & Powerups_Dead))
		{
			if (fasttimer > 0)
			{
				--fasttimer;
				MainCharObj2[0]->Speed.x = MainCharObj2[0]->PhysData.HSpeedCap;
				if (IsFinalLevel())
				{
					MainCharObj2[1]->Speed.x = MainCharObj2[0]->PhysData.HSpeedCap;
				}
			}
			else if (fasttimer < 0)
			{
				++fasttimer;
				MainCharObj2[0]->Speed.x = -MainCharObj2[0]->PhysData.HSpeedCap;
				if (IsFinalLevel())
				{
					MainCharObj2[1]->Speed.x = -MainCharObj2[0]->PhysData.HSpeedCap;
				}
			}
		}
	}

	__declspec(dllexport) void Init(const char* path, const HelperFunctions& helperFunctions)
	{
		char buf[MAX_PATH];
		GetCurrentDirectoryA(MAX_PATH, buf);
		SetCurrentDirectoryA(path);
		HMODULE hm = LoadLibraryA("SA2VsChatNET.dll");
		if (hm == NULL)
		{
			SetCurrentDirectoryA(buf);
			PrintDebug("SA2VsChat: Failed to load helper DLL, mod will not function!");
			return;
		}
		GetProcAddress(hm, "Main")();
		SetCurrentDirectoryA(buf);
		memcpy(MusicList2, MusicList, MusicList_Length * 4);
		MusicList2[156] = "chao_g_iede.adx";
		//WriteJump((void*)0x4586A0, GetNextStoryEvent_r);
		//NextStoryEntry.Type = -1;
		//memset(NextStoryEntry.Events, -1, 4);
		WriteJump((void*)0x459910, sub_459910);
		//InitBase();
	}
	__declspec(dllexport) PointerList Pointers = { arrayptrandlengthT(pointers, int) };
	__declspec(dllexport) ModInfo SA2ModInfo { ModLoaderVer };
}