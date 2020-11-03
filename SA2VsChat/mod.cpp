#include "pch.h"
#include <cstdio>
#include <random>
#include "SA2ModLoader.h"
#include "Trampoline.h"
#include "..\SA2CharSel\SA2CharSel\Base.h"

std::random_device rd;
std::default_random_engine gen(rd());

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
static const void* const LoadStoryEventPtr = (void*)0x4589D0;
static inline void LoadStoryEvent(StoryEntry* a1)
{
	__asm
	{
		mov edx, [a1]
		call LoadStoryEventPtr
	}
}

void (__stdcall* ResetVotes)(int eventno);
StoryEntry NextStoryEntry;
DataArray(StoryEntry, HeroStorySequence, 0x173A148, 46);
DataArray(StoryEntry, DarkStorySequence, 0x173A370, 44);
DataArray(StoryEntry, LastStorySequence, 0x173A580, 8);
DataArray(StoryEntry, IntroStorySequence, 0x173A5E0, 2);
DataArray(StoryEntry, HeroBossRushSequence, 0x173A628, 9);
DataArray(StoryEntry, DarkBossRushSequence, 0x173A698, 9);
DataArray(StoryEntry, AllBossRushSequence, 0x173A708, 19);
DataPointer(char, NextStoryEvent, 0x1DEB31E);
DataPointer(char, CurrentStoryEvent, 0x1DEB31F);
DataPointer(char, CurrentStorySequence, 0x1DEB320);
void __cdecl GetNextStoryEvent_r()
{
	switch (CurrentStorySequence)
	{
	case 1:
		if (NextStoryEntry.Type == -1)
			LoadStoryEvent(&HeroStorySequence[(unsigned __int8)min(NextStoryEvent, HeroStorySequence_Length - 1)]);
		else
			LoadStoryEvent(&NextStoryEntry);
		CurrentStoryEvent = NextStoryEvent;
		ResetVotes(CurrentStoryEvent);
		NextStoryEntry.Type = -1;
		break;
	case 2:
		if (NextStoryEntry.Type == -1)
			LoadStoryEvent(&DarkStorySequence[(unsigned __int8)min(NextStoryEvent, DarkStorySequence_Length - 1)]);
		else
			LoadStoryEvent(&NextStoryEntry);
		CurrentStoryEvent = NextStoryEvent;
		ResetVotes(CurrentStoryEvent);
		NextStoryEntry.Type = -1;
		break;
	case 3:
		if (NextStoryEntry.Type == -1)
			LoadStoryEvent(&LastStorySequence[(unsigned __int8)min(NextStoryEvent, LastStorySequence_Length - 1)]);
		else
			LoadStoryEvent(&NextStoryEntry);
		CurrentStoryEvent = NextStoryEvent;
		ResetVotes(CurrentStoryEvent);
		NextStoryEntry.Type = -1;
		break;
	case 4:
		LoadStoryEvent(&IntroStorySequence[(unsigned __int8)NextStoryEvent]);
		CurrentStoryEvent = NextStoryEvent;
		break;
	case 5:
		LoadStoryEvent(&((StoryEntry*)0x1730074)[(unsigned __int8)NextStoryEvent]);
		CurrentStoryEvent = NextStoryEvent;
		break;
	case 6:
		LoadStoryEvent(&((StoryEntry*)0x173089C)[(unsigned __int8)NextStoryEvent]);
		CurrentStoryEvent = NextStoryEvent;
		break;
	case 7:
		LoadStoryEvent(&((StoryEntry*)0x173A5F8)[(unsigned __int8)NextStoryEvent]);
		CurrentStoryEvent = NextStoryEvent;
		break;
	case 8:
		LoadStoryEvent(&((StoryEntry*)0x1730AC4)[(unsigned __int8)NextStoryEvent]);
		CurrentStoryEvent = NextStoryEvent;
		break;
	case 9:
		LoadStoryEvent(&((StoryEntry*)0x17312EC)[(unsigned __int8)NextStoryEvent]);
		CurrentStoryEvent = NextStoryEvent;
		break;
	case 0xA:
		LoadStoryEvent(&((StoryEntry*)0x173A610)[(unsigned __int8)NextStoryEvent]);
		CurrentStoryEvent = NextStoryEvent;
		break;
	case 0xB:
		LoadStoryEvent(&((StoryEntry*)0x17318CC)[(unsigned __int8)NextStoryEvent]);
		CurrentStoryEvent = NextStoryEvent;
		break;
	case 0xC:
		if (NextStoryEntry.Type == -1)
			LoadStoryEvent(&HeroBossRushSequence[(unsigned __int8)min(NextStoryEvent, HeroBossRushSequence_Length - 1)]);
		else
			LoadStoryEvent(&NextStoryEntry);
		CurrentStoryEvent = NextStoryEvent;
		ResetVotes(CurrentStoryEvent);
		NextStoryEntry.Type = -1;
		break;
	case 0xD:
		if (NextStoryEntry.Type == -1)
			LoadStoryEvent(&DarkBossRushSequence[(unsigned __int8)min(NextStoryEvent, DarkBossRushSequence_Length - 1)]);
		else
			LoadStoryEvent(&NextStoryEntry);
		CurrentStoryEvent = NextStoryEvent;
		ResetVotes(CurrentStoryEvent);
		NextStoryEntry.Type = -1;
		break;
	case 0xE:
		if (NextStoryEntry.Type == -1)
			LoadStoryEvent(&AllBossRushSequence[(unsigned __int8)min(NextStoryEvent, AllBossRushSequence_Length - 1)]);
		else
			LoadStoryEvent(&NextStoryEntry);
		CurrentStoryEvent = NextStoryEvent;
		ResetVotes(CurrentStoryEvent);
		NextStoryEntry.Type = -1;
		break;
	case 0xF:
		LoadStoryEvent(&((StoryEntry*)0x173A7EC)[(unsigned __int8)NextStoryEvent]);
		CurrentStoryEvent = NextStoryEvent;
		break;
	default:
		CurrentStoryEvent = NextStoryEvent;
		break;
	}
}

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
	__declspec(dllexport) void GiveItem(int item)
	{
		if (MainCharObj2[0] && !(MainCharObj2[0]->Powerups & Powerups_Dead) && CurrentLevel < LevelIDs_Route101280 && CurrentLevel != LevelIDs_FinalHazard)
		{
			DisplayItemBoxItem(0, ItemBox_Items[item].Texture);
			ItemBox_Items[item].Code(MainCharacter[0], 0);
		}
	}

	__declspec(dllexport) void SpawnOmochao()
	{
		if (GameState == GameStates_Ingame && CurrentLevel < LevelIDs_Route101280 && CurrentLevel != LevelIDs_FinalHazard)
			AllocateObjectMaster(CheckLoadOmochao, 2, "CheckLoadOmochao");
	}

	__declspec(dllexport) void PlayVoice(int id)
	{
		PlayVoice(0, id);
	}

	__declspec(dllexport) void Stop()
	{
		if (MainCharObj2[0] && !(MainCharObj2[0]->Powerups & Powerups_Dead))
		{
			MainCharObj2[0]->Speed.x = 0;
			MainCharObj2[0]->Speed.y = 0;
			MainCharObj2[0]->Speed.z = 0;
		}
	}

	__declspec(dllexport) void GottaGoFast()
	{
		fasttimer = 60;
	}

	__declspec(dllexport) void TsafOgAttog()
	{
		fasttimer = -60;
	}

	__declspec(dllexport) void SuperJump()
	{
		if (MainCharObj2[0] && !(MainCharObj2[0]->Powerups & Powerups_Dead))
			MainCharObj2[0]->Speed.y = MainCharObj2[0]->PhysData.VSpeedCap;
	}

	__declspec(dllexport) void PmujRepus()
	{
		if (MainCharObj2[0] && !(MainCharObj2[0]->Powerups & Powerups_Dead))
			MainCharObj2[0]->Speed.y = -MainCharObj2[0]->PhysData.VSpeedCap;
	}

	__declspec(dllexport) void TimeStop()
	{
		TimeStopped ^= 2;
	}

	__declspec(dllexport) bool Die(const char* user)
	{
		if (MainCharObj2[0] && !(MainCharObj2[0]->Powerups & Powerups_Dead))
		{
			PrintDebug("Killed by %s!", user);
			KillPlayer(0);
			return true;
		}
		return false;
	}

	__declspec(dllexport) bool Win(const char* user)
	{
		if (MainCharObj2[0] && !(MainCharObj2[0]->Powerups & Powerups_Dead))
		{
			PrintDebug("Level ended by %s!", user);
			AwardWin(0);
			return true;
		}
		return false;
	}

	__declspec(dllexport) void Grow()
	{
		if (targetSize < 8)
			SetTargetSize(targetSize * 2);
	}

	__declspec(dllexport) void Shrink()
	{
		if (targetSize > 0.125)
			SetTargetSize(targetSize / 2);
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

	__declspec(dllexport) void HighGravity()
	{
		if (MainCharObj1[0] && gravmult < 8)
			gravmult *= 2;
	}

	__declspec(dllexport) void LowGravity()
	{
		if (MainCharObj1[0] && gravmult > 0.125)
			gravmult /= 2;
	}

	__declspec(dllexport) void SpeedUp()
	{
		if (MainCharObj2[0] && speedlevel < 3)
		{
			++speedlevel;
			MainCharObj2[0]->PhysData.GroundAccel *= 2;
			MainCharObj2[0]->PhysData.MaxAccel *= 2;
			MainCharObj2[0]->PhysData.field_68 *= 2;
		}
	}

	__declspec(dllexport) void SlowDown()
	{
		if (MainCharObj2[0] && speedlevel > -3)
		{
			--speedlevel;
			MainCharObj2[0]->PhysData.GroundAccel /= 2;
			MainCharObj2[0]->PhysData.MaxAccel /= 2;
			MainCharObj2[0]->PhysData.field_68 /= 2;
		}
	}

	__declspec(dllexport) void HealBoss()
	{
		if (MainCharObj2[1] && MainCharObj2[1]->MechHP < 5)
			++MainCharObj2[1]->MechHP;
	}

	__declspec(dllexport) void SetNextStoryEvent(char type, short id, bool dark)
	{
		NextStoryEntry.Type = type;
		switch (type)
		{
		case StoryEntryType_Level:
			NextStoryEntry.Level = id;
			switch (id)
			{
			case LevelIDs_CityEscape:
			case LevelIDs_BigFoot:
			case LevelIDs_MetalHarbor:
			case LevelIDs_GreenForest:
			case LevelIDs_PyramidCave:
			case LevelIDs_EggGolemS:
			case LevelIDs_CrazyGadget:
			case LevelIDs_FinalRush:
			case LevelIDs_GreenHill:
				NextStoryEntry.Character = Characters_Sonic;
				break;
			case LevelIDs_HotShot:
			case LevelIDs_RadicalHighway:
			case LevelIDs_WhiteJungle:
			case LevelIDs_SkyRail:
			case LevelIDs_FinalChase:
			case LevelIDs_Biolizard:
				NextStoryEntry.Character = Characters_Shadow;
				break;
			case LevelIDs_WildCanyon:
			case LevelIDs_PumpkinHill:
			case LevelIDs_AquaticMine:
			case LevelIDs_DeathChamber:
			case LevelIDs_KingBoomBoo:
			case LevelIDs_MeteorHerd:
				NextStoryEntry.Character = Characters_Knuckles;
				break;
			case LevelIDs_DryLagoon:
			case LevelIDs_EggQuarters:
			case LevelIDs_SecurityHall:
			case LevelIDs_FlyingDog:
			case LevelIDs_MadSpace:
				NextStoryEntry.Character = Characters_Rouge;
				break;
			case LevelIDs_PrisonLane:
			case LevelIDs_MissionStreet:
			case LevelIDs_HiddenBase:
			case LevelIDs_EternalEngine:
			case LevelIDs_CannonsCoreT:
				NextStoryEntry.Character = Characters_MechTails;
				break;
			case LevelIDs_IronGate:
			case LevelIDs_SandOcean:
			case LevelIDs_LostColony:
			case LevelIDs_WeaponsBed:
			case LevelIDs_EggGolemE:
			case LevelIDs_CosmicWall:
				NextStoryEntry.Character = Characters_MechEggman;
				break;
			case LevelIDs_SonicVsShadow1:
			case LevelIDs_SonicVsShadow2:
				if (dark)
					NextStoryEntry.Character = Characters_Shadow;
				else
					NextStoryEntry.Character = Characters_Sonic;
				break;
			case LevelIDs_KnucklesVsRouge:
				if (dark)
					NextStoryEntry.Character = Characters_Rouge;
				else
					NextStoryEntry.Character = Characters_Knuckles;
				break;
			case LevelIDs_TailsVsEggman1:
			case LevelIDs_TailsVsEggman2:
				if (dark)
					NextStoryEntry.Character = Characters_MechEggman;
				else
					NextStoryEntry.Character = Characters_MechTails;
				break;
			case LevelIDs_Route101280:
				if (dark)
					NextStoryEntry.Character = Characters_Rouge;
				else
					NextStoryEntry.Character = Characters_MechTails;
				break;
			}
			break;
		case StoryEntryType_Event:
			NextStoryEntry.Events[0] = id;
			break;
		}
	}

	__declspec(dllexport) void Confuse()
	{
		if (MainCharObj2[0] && !MainCharObj2[0]->ConfuseTime)
		{
			MainCharObj2[0]->ConfuseTime = 300;
			ConfuStar_Load(0);
		}
	}

	__declspec(dllexport) void Earthquake()
	{
		if (MainCharacter[0])
		{
			char d2[]{ 0, 0 };
			ObjectMaster om{};
			om.Data2.Undefined = d2;
			Knuckles2PEarthquakeMan_Delete(&om);
		}
	}

	__declspec(dllexport) void ToggleChaoKey()
	{
		if (MainCharacter[0])
			HaveChaoKey ^= 1;
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
			}
			else if (currentSize > targetSize)
			{
				currentSize -= growthAmount;
				if (currentSize < targetSize)
					currentSize = targetSize;
				MainCharObj1[0]->Scale.x = (float)currentSize;
				MainCharObj1[0]->Scale.y = (float)currentSize;
				MainCharObj1[0]->Scale.z = (float)currentSize;
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
			}
			else if (fasttimer < 0)
			{
				++fasttimer;
				MainCharObj2[0]->Speed.x = -MainCharObj2[0]->PhysData.HSpeedCap;
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
		WriteJump((void*)0x4586A0, GetNextStoryEvent_r);
		NextStoryEntry.Type = -1;
		memset(NextStoryEntry.Events, -1, 4);
		WriteJump((void*)0x459910, sub_459910);
		//InitBase();
	}

	__declspec(dllexport) ModInfo SA2ModInfo { ModLoaderVer };
}