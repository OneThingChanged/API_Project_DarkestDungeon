#include "framework.h"
#include "DB_Skill.h"
#include "image.h"
#include "Info_Skill.h"

CDB_Skill::CDB_Skill()
{
}

CDB_Skill::~CDB_Skill()
{
}

void CDB_Skill::Init()
{
	id = 0;
	SetHeroSkill();
	SetEnemySkill();
}

void CDB_Skill::SetHeroSkill()
{
	CInfo_Skill* info = new CInfo_Skill();

#pragma region Crusader
	info = new CInfo_Skill();
	info->m_name = "Smite";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 3;
	info->allowUseSkillPos = 3;
	info->m_skillImageType = SKILLIMAGETYPE::Attack;
	info->target = SKILLTARGET::Enemy;
	info->job = JOB::Crusader;
	info->m_skill = SKILL::Crusader_Combat_Smite;
	info->m_skillIcon = IMAGE::Crusader_Skill_Smite;
	info->m_skillDeactiveIcon = IMAGE::crusader_disable_smite;
	info->m_skillMotion = IMAGE::Crusader_sword;
	info->sound = SOUND::Cru_PowerfulAttack;

	info->damage[0] = 150.f;
	info->damage[1] = 150.f;
	info->damage[2] = 150.f;
	info->damage[3] = 150.f;
	info->damage[4] = 150.f;
	info->accuracy[0] = 85;
	info->accuracy[1] = 90;
	info->accuracy[2] = 95;
	info->accuracy[3] = 100;
	info->accuracy[4] = 105;
	info->critMod[0] = 0.f;
	info->critMod[1] = 1.f;
	info->critMod[2] = 2.f;
	info->critMod[3] = 3.f;
	info->critMod[4] = 4.f;
	skillDB.insert(make_pair(SKILL::Crusader_Combat_Smite, info));
	MG_INFO->RegisterInfo(info);

	info = new CInfo_Skill();
	info->m_name = "Zealous Accusation";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 3;
	info->allowUseSkillPos = 3;
	info->m_skillImageType = SKILLIMAGETYPE::Charge;
	info->target = SKILLTARGET::Enemies;
	info->job = JOB::Crusader;
	info->m_skill = SKILL::Crusader_Combat_ZealousAccusation;
	info->m_skillIcon = IMAGE::Crusader_Skill_ZealousAccusation;
	info->m_skillDeactiveIcon = IMAGE::crusader_disable_scroll;
	info->m_skillMotion = IMAGE::Crusader_scroll;
	info->sound = SOUND::Cru_ScrollAttack;
	info->damage[0] = -40.f;
	info->damage[1] = -40.f;
	info->damage[2] = -40.f;
	info->damage[3] = -40.f;
	info->damage[4] = -40.f;
	info->accuracy[0] = 85;
	info->accuracy[1] = 90;
	info->accuracy[2] = 95;
	info->accuracy[3] = 100;
	info->accuracy[4] = 105;
	info->critMod[0] = -4.f;
	info->critMod[1] = -3.f;
	info->critMod[2] = -2.f;
	info->critMod[3] = -1.f;
	info->critMod[4] = -0.f;
	skillDB.insert(make_pair(SKILL::Crusader_Combat_ZealousAccusation, info));
	MG_INFO->RegisterInfo(info);

	info = new CInfo_Skill();
	info->m_name = "Stunning Blow";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 3;
	info->allowUseSkillPos = 3;
	info->m_skillImageType = SKILLIMAGETYPE::Attack;
	info->target = SKILLTARGET::Enemy;
	info->job = JOB::Crusader;
	info->m_skill = SKILL::Crusader_Combat_StunningBlow;
	info->m_skillIcon = IMAGE::Crusader_Skill_StunningBlow;
	info->m_skillDeactiveIcon = IMAGE::crusader_disable_stunning;
	info->m_skillMotion = IMAGE::Crusader_sword;
	info->effect = EFFECTTYPE::Stun;
	info->sound = SOUND::Cru_stunningblow;
	info->damage[0] = -50.f;
	info->damage[1] = -50.f;
	info->damage[2] = -50.f;
	info->damage[3] = -50.f;
	info->damage[4] = -50.f;
	info->accuracy[0] = 90;
	info->accuracy[1] = 95;
	info->accuracy[2] = 100;
	info->accuracy[3] = 105;
	info->accuracy[4] = 110;
	info->critMod[0] = 0.f;
	info->critMod[1] = 1.f;
	info->critMod[2] = 2.f;
	info->critMod[3] = 3.f;
	info->critMod[4] = 4.f;
	info->effectVal[0] = 100.f;
	info->effectVal[1] = 110.f;
	info->effectVal[2] = 120.f;
	info->effectVal[3] = 130.f;
	info->effectVal[4] = 140.f;
	skillDB.insert(make_pair(SKILL::Crusader_Combat_StunningBlow, info));
	MG_INFO->RegisterInfo(info);

	info = new CInfo_Skill();
	info->m_name = "BattleHeal";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 15;
	info->allowUseSkillPos = 15;
	info->m_skillImageType = SKILLIMAGETYPE::Buff;
	info->target = SKILLTARGET::Ally;
	info->job = JOB::Crusader;
	info->m_skill = SKILL::Crusader_Heal_BattleHeal;
	info->m_skillIcon = IMAGE::Crusader_Skill_BattleHeal;
	info->m_skillDeactiveIcon = IMAGE::crusader_disable_battleheal;
	info->m_skillMotion = IMAGE::Crusader_banner;
	info->sound = SOUND::Cru_Battleheal;
	info->healMin[0] = 12;
	info->healMin[1] = 3;
	info->healMin[2] = 3;
	info->healMin[3] = 4;
	info->healMin[4] = 4;
	info->healMax[0] = 13;
	info->healMax[1] = 3;
	info->healMax[2] = 4;
	info->healMax[3] = 5;
	info->healMax[4] = 5;
	skillDB.insert(make_pair(SKILL::Crusader_Heal_BattleHeal, info));
	MG_INFO->RegisterInfo(info);


#pragma endregion

#pragma region Vestal
	info = new CInfo_Skill();
	info->m_name = "Mace Bash";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 3;
	info->allowUseSkillPos = 3;
	info->m_skillImageType = SKILLIMAGETYPE::Attack;
	info->target = SKILLTARGET::Enemy;
	info->job = JOB::Vestal;
	info->m_skill = SKILL::Vestal_Combat_MaceBash;
	info->m_skillIcon = IMAGE::Vestal_Skill_MaceBash;
	info->m_skillDeactiveIcon = IMAGE::vestal_disable_mace;
	info->m_skillMotion = IMAGE::Vestal_mace;
	info->sound = SOUND::vst_macebash;
	info->damage[0] = 150.f;
	info->damage[1] = 150.f;
	info->damage[2] = 150.f;
	info->damage[3] = 150.f;
	info->damage[4] = 150.f;
	info->accuracy[0] = 85;
	info->accuracy[1] = 90;
	info->accuracy[2] = 95;
	info->accuracy[3] = 100;
	info->accuracy[4] = 105;
	info->critMod[0] = 0.f;
	info->critMod[1] = 1.f;
	info->critMod[2] = 2.f;
	info->critMod[3] = 3.f;
	info->critMod[4] = 4.f;
	skillDB.insert(make_pair(SKILL::Vestal_Combat_MaceBash, info));
	MG_INFO->RegisterInfo(info);

	info = new CInfo_Skill();
	info->m_name = "Judgement";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 15;
	info->allowUseSkillPos = 3;
	info->m_skillImageType = SKILLIMAGETYPE::Charge;
	info->target = SKILLTARGET::Enemy;
	info->job = JOB::Vestal;
	info->m_skill = SKILL::Vestal_Combat_Judgement;
	info->m_skillIcon = IMAGE::Vestal_Skill_Judgement;
	info->m_skillDeactiveIcon = IMAGE::vestal_disable_judgement;
	info->m_skillMotion = IMAGE::Vestal_lectionary;
	info->sound = SOUND::vst_judgement;
	info->damage[0] = -25.f;
	info->damage[1] = -25.f;
	info->damage[2] = -25.f;
	info->damage[3] = -25.f;
	info->damage[4] = -25.f;
	info->accuracy[0] = 85;
	info->accuracy[1] = 90;
	info->accuracy[2] = 95;
	info->accuracy[3] = 100;
	info->accuracy[4] = 105;
	info->critMod[0] = 5.f;
	info->critMod[1] = 6.f;
	info->critMod[2] = 7.f;
	info->critMod[3] = 8.f;
	info->critMod[4] = 9.f;
	skillDB.insert(make_pair(SKILL::Vestal_Combat_Judgement, info));
	MG_INFO->RegisterInfo(info);

	info = new CInfo_Skill();
	info->m_name = "Dazzling Light";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 7;
	info->allowUseSkillPos = 14;
	info->m_skillImageType = SKILLIMAGETYPE::Debuff;
	info->target = SKILLTARGET::Enemy;
	info->job = JOB::Vestal;
	info->m_skill = SKILL::Vestal_Combat_DazzlingLight;
	info->m_skillIcon = IMAGE::Vestal_Skill_DazzlingLight;
	info->m_skillDeactiveIcon = IMAGE::vestal_disable_dazzlingLight;
	info->m_skillMotion = IMAGE::Vestal_lectionary;
	info->effect = EFFECTTYPE::Stun;
	info->sound = SOUND::vst_judgement;
	info->damage[0] = -75.f;
	info->damage[1] = -75.f;
	info->damage[2] = -75.f;
	info->damage[3] = -75.f;
	info->damage[4] = -75.f;
	info->accuracy[0] = 90;
	info->accuracy[1] = 95;
	info->accuracy[2] = 100;
	info->accuracy[3] = 105;
	info->accuracy[4] = 110;
	info->critMod[0] = 5;
	info->critMod[1] = 6;
	info->critMod[2] = 7;
	info->critMod[3] = 8;
	info->critMod[4] = 9;
	info->effectVal[0] = 100.f;
	info->effectVal[1] = 110.f;
	info->effectVal[2] = 120.f;
	info->effectVal[3] = 130.f;
	info->effectVal[4] = 140.f;
	skillDB.insert(make_pair(SKILL::Vestal_Combat_DazzlingLight, info));
	MG_INFO->RegisterInfo(info);

	info = new CInfo_Skill();
	info->m_name = "Divine Comfort";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 15;
	info->allowUseSkillPos = 14;
	info->m_skillImageType = SKILLIMAGETYPE::Buff;
	info->target = SKILLTARGET::Allies;
	info->job = JOB::Vestal;
	info->m_skill = SKILL::Vestal_Heal_DivineComfort;
	info->m_skillIcon = IMAGE::Vestal_Skill_DivineComfort;
	info->m_skillDeactiveIcon = IMAGE::vestal_disable_divine;
	info->m_skillMotion = IMAGE::Vestal_heal;
	info->sound = SOUND::vst_divinegrace;
	info->healMin[0] = 11;
	info->healMin[1] = 2;
	info->healMin[2] = 3;
	info->healMin[3] = 3;
	info->healMin[4] = 4;
	info->healMax[0] = 13;
	info->healMax[1] = 3;
	info->healMax[2] = 3;
	info->healMax[3] = 4;
	info->healMax[4] = 5;
	skillDB.insert(make_pair(SKILL::Vestal_Heal_DivineComfort, info));
	MG_INFO->RegisterInfo(info);
#pragma endregion

#pragma region Plague_doctor
	info = new CInfo_Skill();
	info->m_name = "Noxious Blast";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 3;
	info->allowUseSkillPos = 14;
	info->m_skillImageType = SKILLIMAGETYPE::Debuff;
	info->target = SKILLTARGET::Enemy;
	info->job = JOB::PlagueDoctor;
	info->m_skill = SKILL::Plague_doctor_NoxiousBlast;
	info->m_skillIcon = IMAGE::Plague_doctor_Skill_NoxiousBlast;
	info->m_skillDeactiveIcon = IMAGE::plague_doctor_disable_noxious;
	info->m_skillMotion = IMAGE::Plague_doctor_blast;
	info->effect = EFFECTTYPE::Stun;
	info->sound = SOUND::plg_noxiousblast;
	info->damage[0] = -80.f;
	info->damage[1] = -80.f;
	info->damage[2] = -80.f;
	info->damage[3] = -80.f;
	info->damage[4] = -80.f;
	info->accuracy[0] = 95;
	info->accuracy[1] = 100;
	info->accuracy[2] = 105;
	info->accuracy[3] = 110;
	info->accuracy[4] = 115;
	info->critMod[0] = 5;
	info->critMod[1] = 6;
	info->critMod[2] = 7;
	info->critMod[3] = 8;
	info->critMod[4] = 9;
	info->effectVal[0] = 100.f;
	info->effectVal[1] = 110.f;
	info->effectVal[2] = 120.f;
	info->effectVal[3] = 130.f;
	info->effectVal[4] = 140.f;

	info->moveTagetPos[0] = -3;
	info->moveTagetPos[1] = -3;
	info->moveTagetPos[2] = -3;
	info->moveTagetPos[3] = -3;
	info->moveTagetPos[4] = -3;

	skillDB.insert(make_pair(SKILL::Plague_doctor_NoxiousBlast, info));
	MG_INFO->RegisterInfo(info);

	info = new CInfo_Skill();
	info->m_name = "PlagueGrenade";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 12;
	info->allowUseSkillPos = 12;
	info->m_skillImageType = SKILLIMAGETYPE::Debuff;
	info->target = SKILLTARGET::Enemy;
	info->job = JOB::PlagueDoctor;
	info->m_skill = SKILL::Plague_doctor_PlagueGrenade;
	info->m_skillIcon = IMAGE::Plague_doctor_Skill_PlagueGrenade;
	info->m_skillDeactiveIcon = IMAGE::plague_doctor_disable_grenade;
	info->m_skillMotion = IMAGE::Plague_doctor_grenade;
	info->effect = EFFECTTYPE::Poison;
	info->sound = SOUND::plg_plaguegrenade;
	info->damage[0] = -90.f;
	info->damage[1] = -90.f;
	info->damage[2] = -90.f;
	info->damage[3] = -90.f;
	info->damage[4] = -90.f;
	info->accuracy[0] = 95;
	info->accuracy[1] = 100;
	info->accuracy[2] = 105;
	info->accuracy[3] = 110;
	info->accuracy[4] = 115;
	info->critMod[0] = 0;
	info->critMod[1] = 1;
	info->critMod[2] = 2;
	info->critMod[3] = 3;
	info->critMod[4] = 4;
	info->effectVal[0] = 100.f;
	info->effectVal[1] = 110.f;
	info->effectVal[2] = 120.f;
	info->effectVal[3] = 130.f;
	info->effectVal[4] = 140.f;
	skillDB.insert(make_pair(SKILL::Plague_doctor_PlagueGrenade, info));
	MG_INFO->RegisterInfo(info);

	info = new CInfo_Skill();
	info->m_name = "Incision";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 3;
	info->allowUseSkillPos = 7;
	info->m_skillImageType = SKILLIMAGETYPE::Attack;
	info->target = SKILLTARGET::Enemy;
	info->job = JOB::PlagueDoctor;
	info->m_skill = SKILL::Plague_doctor_Incision;
	info->m_skillIcon = IMAGE::Plague_doctor_Skill_Incision;
	info->m_skillDeactiveIcon = IMAGE::plague_doctor_diable_incision;
	info->m_skillMotion = IMAGE::Plague_doctor_dagger;
	info->effect = EFFECTTYPE::Bleed;
	info->sound = SOUND::plg_knife;
	info->damage[0] = 150.f;
	info->damage[1] = 150.f;
	info->damage[2] = 150.f;
	info->damage[3] = 150.f;
	info->damage[4] = 150.f;
	info->accuracy[0] = 85;
	info->accuracy[1] = 90;
	info->accuracy[2] = 95;
	info->accuracy[3] = 100;
	info->accuracy[4] = 105;
	info->critMod[0] = 5;
	info->critMod[1] = 6;
	info->critMod[2] = 7;
	info->critMod[3] = 8;
	info->critMod[4] = 9;
	info->effectVal[0] = 100.f;
	info->effectVal[1] = 110.f;
	info->effectVal[2] = 120.f;
	info->effectVal[3] = 130.f;
	info->effectVal[4] = 140.f;
	skillDB.insert(make_pair(SKILL::Plague_doctor_Incision, info));
	MG_INFO->RegisterInfo(info);

	info = new CInfo_Skill();
	info->m_name = "BattleFiled_Medicine";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 12;
	info->allowUseSkillPos = 15;
	info->m_skillImageType = SKILLIMAGETYPE::Buff;
	info->target = SKILLTARGET::Allies;
	info->job = JOB::PlagueDoctor;
	info->m_skill = SKILL::Plague_doctor_BattleFiled_Medicine;
	info->m_skillIcon = IMAGE::Plague_doctor_Skill_BattleFiled_Medicine;
	info->m_skillDeactiveIcon = IMAGE::plague_doctor_disable_battlefiledheal;
	info->m_skillMotion = IMAGE::Plague_doctor_buff;
	info->sound = SOUND::plg_battlemed;
	info->healMin[0] = 11.f;
	info->healMax[0] = 11.f;
	info->healMin[1] = 1.f;
	info->healMax[1] = 2.f;
	info->healMin[2] = 2.f;
	info->healMax[2] = 2.f;
	info->healMin[3] = 2.f;
	info->healMax[3] = 3.f;
	info->healMin[4] = 3.f;
	info->healMax[4] = 3.f;

	skillDB.insert(make_pair(SKILL::Plague_doctor_BattleFiled_Medicine, info));
	MG_INFO->RegisterInfo(info);

#pragma endregion

#pragma region Highwayman
	info = new CInfo_Skill();
	info->m_name = "PointBlackShot";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 1;
	info->allowUseSkillPos = 1;
	info->m_skillImageType = SKILLIMAGETYPE::Attack;
	info->target = SKILLTARGET::Enemy;
	info->job = JOB::Highwayman;
	info->m_skill = SKILL::Highwayman_PointBlankShot;
	info->m_skillIcon = IMAGE::Highwayman_Skill_PointBlankShot;
	info->m_skillDeactiveIcon = IMAGE::highwayman_disable_pointshot;
	info->m_skillMotion = IMAGE::Highwayman_hipshot;
	info->effect = EFFECTTYPE::NONE;
	info->sound = SOUND::hwy_backshot;

	info->damage[0] = +50.f;
	info->damage[1] = +50.f;
	info->damage[2] = +50.f;
	info->damage[3] = +50.f;
	info->damage[4] = +50.f;
	info->accuracy[0] = 95;
	info->accuracy[1] = 100;
	info->accuracy[2] = 105;
	info->accuracy[3] = 110;
	info->accuracy[4] = 115;
	info->critMod[0] = 5;
	info->critMod[1] = 6;
	info->critMod[2] = 7;
	info->critMod[3] = 8;
	info->critMod[4] = 9;
	info->effectVal[0] = 100.f;
	info->effectVal[1] = 110.f;
	info->effectVal[2] = 120.f;
	info->effectVal[3] = 130.f;
	info->effectVal[4] = 140.f;
	info->moveSelfPos[0] = 1;
	info->moveSelfPos[1] = 1;
	info->moveSelfPos[2] = 1;
	info->moveSelfPos[3] = 1;
	info->moveSelfPos[4] = 1;


	skillDB.insert(make_pair(SKILL::Highwayman_PointBlankShot, info));
	MG_INFO->RegisterInfo(info);

	info = new CInfo_Skill();
	info->m_name = "Grapeshot_Blast";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 7;
	info->allowUseSkillPos = 6;
	info->m_skillImageType = SKILLIMAGETYPE::Attack;
	info->target = SKILLTARGET::Enemies;
	info->job = JOB::Highwayman;
	info->m_skill = SKILL::Highwayman_GrapeshotBlast;
	info->m_skillIcon = IMAGE::Highwayman_Skill_GrapeshotBlast;
	info->m_skillDeactiveIcon = IMAGE::highwayman_disable_grapeshot;
	info->m_skillMotion = IMAGE::Highwayman_pistol;
	info->effect = EFFECTTYPE::NONE;
	info->sound = SOUND::hwy_grapeshot;
	info->damage[0] = -50.f;
	info->damage[1] = -50.f;
	info->damage[2] = -50.f;
	info->damage[3] = -50.f;
	info->damage[4] = -50.f;
	info->accuracy[0] = 75;
	info->accuracy[1] = 80;
	info->accuracy[2] = 85;
	info->accuracy[3] = 90;
	info->accuracy[4] = 95;
	info->critMod[0] = -9;
	info->critMod[1] = -8;
	info->critMod[2] = -7;
	info->critMod[3] = -6;
	info->critMod[4] = -5;
	info->effectVal[0] = 100.f;
	info->effectVal[1] = 110.f;
	info->effectVal[2] = 120.f;
	info->effectVal[3] = 130.f;
	info->effectVal[4] = 140.f;

	skillDB.insert(make_pair(SKILL::Highwayman_GrapeshotBlast, info));
	MG_INFO->RegisterInfo(info);

	info = new CInfo_Skill();
	info->m_name = "Duelists_Advance";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 7;
	info->allowUseSkillPos = 14;
	info->m_skillImageType = SKILLIMAGETYPE::Attack;
	info->target = SKILLTARGET::Enemy;
	info->job = JOB::Highwayman;
	info->m_skill = SKILL::Highwayman_Duelists_Advance;
	info->m_skillIcon = IMAGE::Highwayman_Skill_Duelists_Advance;
	info->m_skillDeactiveIcon = IMAGE::highwayman_diable_duelistadvance;
	info->m_skillMotion = IMAGE::Highwayman_lunge;
	info->effect = EFFECTTYPE::NONE;
	info->sound = SOUND::hwy_duelistadvance;
	info->damage[0] = 150.f;
	info->damage[1] = 150.f;
	info->damage[2] = 150.f;
	info->damage[3] = 150.f;
	info->damage[4] = 150.f;
	info->accuracy[0] = 90;
	info->accuracy[1] = 95;
	info->accuracy[2] = 100;
	info->accuracy[3] = 105;
	info->accuracy[4] = 110;
	info->critMod[0] = 5;
	info->critMod[1] = 6;
	info->critMod[2] = 7;
	info->critMod[3] = 8;
	info->critMod[4] = 9;
	//++++++++++++++++++++Check Please++++++++++++++++++++++//
	info->moveSelfPos[0] = -1;
	info->moveSelfPos[1] = -1;
	info->moveSelfPos[2] = -1;
	info->moveSelfPos[3] = -1;
	info->moveSelfPos[4] = -1;

	skillDB.insert(make_pair(SKILL::Highwayman_Duelists_Advance, info));
	MG_INFO->RegisterInfo(info);

	info = new CInfo_Skill();
	info->m_name = "OpenVein";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 3;
	info->allowUseSkillPos = 7;
	info->m_skillImageType = SKILLIMAGETYPE::Attack;
	info->target = SKILLTARGET::Enemy;
	info->job = JOB::Highwayman;
	info->m_skill = SKILL::Highwayman_OpenVein;
	info->m_skillIcon = IMAGE::Highwayman_Skill_OpenVein;
	info->m_skillDeactiveIcon = IMAGE::highwayman_disable_slice;
	info->m_skillMotion = IMAGE::Highwayman_slice;
	info->effect = EFFECTTYPE::NONE;
	info->sound = SOUND::hwy_slice;
	info->damage[0] = -15.f;
	info->damage[1] = -15.f;
	info->damage[2] = -15.f;
	info->damage[3] = -15.f;
	info->damage[4] = -15.f;
	info->accuracy[0] = 95;
	info->accuracy[1] = 100;
	info->accuracy[2] = 105;
	info->accuracy[3] = 110;
	info->accuracy[4] = 115;
	info->critMod[0] = 0;
	info->critMod[1] = 1;
	info->critMod[2] = 2;
	info->critMod[3] = 3;
	info->critMod[4] = 4;
	info->effectVal[0] = 100.f;
	info->effectVal[1] = 110.f;
	info->effectVal[2] = 120.f;
	info->effectVal[3] = 130.f;
	info->effectVal[4] = 140.f;

	skillDB.insert(make_pair(SKILL::Highwayman_OpenVein, info));
	MG_INFO->RegisterInfo(info);
#pragma endregion
}

void CDB_Skill::SetEnemySkill()
{
	CInfo_Skill* info = new CInfo_Skill();
	info->m_name = "BoneDefender Skill 1";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 3;
	info->allowUseSkillPos = 3;
	info->target = SKILLTARGET::Enemy;
	info->m_skillImageType = SKILLIMAGETYPE::Attack;
	info->enemyType = ENEMYTYPE::BoneDefender;
	info->m_skill = SKILL::BoneDefender_Combat_1;
	info->m_skillIcon = IMAGE::Enemy_SkeletonDefender_Attack;
	info->m_skillMotion = IMAGE::Enemy_SkeletonDefender_Attack;
	info->sound = SOUND::share_imp_axe;
	info->damage[0] = 0.f;
	info->damage[1] = 0.f;
	info->damage[2] = 0.f;
	info->damage[3] = 0.f;
	info->damage[4] = 0.f;
	info->accuracy[0] = 85;
	info->accuracy[1] = 90;
	info->accuracy[2] = 95;
	info->accuracy[3] = 100;
	info->accuracy[4] = 105;
	info->critMod[0] = 0.f;
	info->critMod[1] = 1.f;
	info->critMod[2] = 2.f;
	info->critMod[3] = 3.f;
	info->critMod[4] = 4.f;
	skillDB.insert(make_pair(SKILL::BoneDefender_Combat_1, info));
	MG_INFO->RegisterInfo(info);
	//Common
	info = new CInfo_Skill();
	info->m_name = "BoneCommon Skill 1";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 7;
	info->allowUseSkillPos = 7;
	info->target = SKILLTARGET::Enemy;
	info->m_skillImageType = SKILLIMAGETYPE::Attack;
	info->enemyType = ENEMYTYPE::BoneCommon;
	info->m_skill = SKILL::BoneCommon_Combat_1;
	info->m_skillIcon = IMAGE::skeleton_common_attack;
	info->m_skillMotion = IMAGE::skeleton_common_attack;
	info->sound = SOUND::share_imp_sword;
	info->damage[0] = 3.f;
	info->damage[1] = 4.f;
	info->damage[2] = 5.f;
	info->damage[3] = 6.f;
	info->damage[4] = 7.f;
	info->accuracy[0] = 82.5;
	info->accuracy[1] = 82.5;
	info->accuracy[2] = 82.5;
	info->accuracy[3] = 82.5;
	info->accuracy[4] = 82.5;
	info->critMod[0] = 6.f;
	info->critMod[1] = 6.f;
	info->critMod[2] = 6.f;
	info->critMod[3] = 6.f;
	info->critMod[4] = 6.f;
	skillDB.insert(make_pair(SKILL::BoneCommon_Combat_1, info));
	MG_INFO->RegisterInfo(info);
	//courtier
	info = new CInfo_Skill();
	info->m_name = "BoneCourtier Skill 1";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 3;
	info->allowUseSkillPos = 3;
	info->target = SKILLTARGET::Enemy;
	info->m_skillImageType = SKILLIMAGETYPE::Attack;
	info->enemyType = ENEMYTYPE::BoneCourtier;
	info->m_skill = SKILL::BoneCourtier_Combat_1;
	info->m_skillIcon = IMAGE::skeleton_courtier_attack;
	info->m_skillMotion = IMAGE::skeleton_courtier_attack;
	info->sound = SOUND::share_imp_sword;
	info->damage[0] = 2.f;
	info->damage[1] = 2.f;
	info->damage[2] = 3.f;
	info->damage[3] = 3.f;
	info->damage[4] = 4.f;
	info->accuracy[0] = 62.5;
	info->accuracy[1] = 62.5;
	info->accuracy[2] = 62.5;
	info->accuracy[3] = 62.5;
	info->accuracy[4] = 62.5;
	info->critMod[0] = 6.f;
	info->critMod[1] = 6.f;
	info->critMod[2] = 6.f;
	info->critMod[3] = 6.f;
	info->critMod[4] = 6.f;
	skillDB.insert(make_pair(SKILL::BoneCourtier_Combat_1, info));
	MG_INFO->RegisterInfo(info);

	info = new CInfo_Skill();
	info->m_name = "BoneCourtier Skill 2_goblet";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 15;
	info->allowUseSkillPos = 14;
	info->target = SKILLTARGET::Enemy;
	info->m_skillImageType = SKILLIMAGETYPE::Charge;
	info->enemyType = ENEMYTYPE::BoneCourtier;
	info->m_skill = SKILL::BoneCourtier_Combat_2_goblet;
	info->m_skillIcon = IMAGE::skeleton_courtier_attack_goblet;
	info->m_skillMotion = IMAGE::skeleton_courtier_attack_goblet;
	info->sound = SOUND::share_imp_slime;
	info->damage[0] = 2.f;
	info->damage[1] = 2.f;
	info->damage[2] = 3.f;
	info->damage[3] = 3.f;
	info->damage[4] = 4.f;
	info->accuracy[0] = 92.5;
	info->accuracy[1] = 92.5;
	info->accuracy[2] = 92.5;
	info->accuracy[3] = 92.5;
	info->accuracy[4] = 92.5;
	info->critMod[0] = 0.f;
	info->critMod[1] = 0.f;
	info->critMod[2] = 0.f;
	info->critMod[3] = 0.f;
	info->critMod[4] = 0.f;
	skillDB.insert(make_pair(SKILL::BoneCourtier_Combat_2_goblet, info));
	MG_INFO->RegisterInfo(info);
	//Necromancer
	info = new CInfo_Skill();
	info->m_name = "Necromancer Skill1_";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 15;
	info->allowUseSkillPos = 3;
	info->target = SKILLTARGET::Enemy;
	info->m_skillImageType = SKILLIMAGETYPE::Attack;
	info->enemyType = ENEMYTYPE::Necromancer;
	info->m_skill = SKILL::Necromancer_Combat_1;
	info->m_skillIcon = IMAGE::necromancer_attack;
	info->m_skillMotion = IMAGE::necromancer_attack;
	info->sound = SOUND::status_bleed_onset;
	info->damage[0] = 4.f;
	info->damage[1] = 5.f;
	info->damage[2] = 6.f;
	info->damage[3] = 7.f;
	info->damage[4] = 8.f;
	info->accuracy[0] = 102.5;
	info->accuracy[1] = 102.5;
	info->accuracy[2] = 102.5;
	info->accuracy[3] = 102.5;
	info->accuracy[4] = 102.5;
	info->critMod[0] = 6.f;
	info->critMod[1] = 6.f;
	info->critMod[2] = 6.f;
	info->critMod[3] = 6.f;
	info->critMod[4] = 6.f;
	skillDB.insert(make_pair(SKILL::Necromancer_Combat_1, info));
	MG_INFO->RegisterInfo(info);

	info = new CInfo_Skill();
	info->m_name = "Necromancer Skill2_back";
	info->m_description = "";
	info->m_ID = id++;
	info->skillLevel = 0;
	info->targetPos = 15;
	info->allowUseSkillPos = 3;
	info->target = SKILLTARGET::Enemies;
	info->m_skillImageType = SKILLIMAGETYPE::Charge;
	info->enemyType = ENEMYTYPE::Necromancer;
	info->m_skill = SKILL::Necromancer_Combat_2_back;
	info->m_skillIcon = IMAGE::necromancer_retreat;
	info->m_skillMotion = IMAGE::necromancer_retreat;
	info->sound = SOUND::status_bleed_onset;
	info->damage[0] = 8.f;
	info->damage[1] = 3.f;
	info->damage[2] = 4.f;
	info->damage[3] = 4.f;
	info->damage[4] = 5.f;

	info->accuracy[0] = 102.5;
	info->accuracy[1] = 102.5;
	info->accuracy[2] = 102.5;
	info->accuracy[3] = 102.5;
	info->accuracy[4] = 102.5;

	info->critMod[0] = 6.f;
	info->critMod[1] = 6.f;
	info->critMod[2] = 6.f;
	info->critMod[3] = 6.f;
	info->critMod[4] = 6.f;

	info->moveSelfPos[0] = 3;
	info->moveSelfPos[1] = 3;
	info->moveSelfPos[2] = 3;
	info->moveSelfPos[3] = 3;
	info->moveSelfPos[4] = 3;


	skillDB.insert(make_pair(SKILL::Necromancer_Combat_2_back, info));
	MG_INFO->RegisterInfo(info);
}

CInfo_Skill* CDB_Skill::CallSkill(SKILL skill)
{
	return skillDB[skill];
}

Image* CDB_Skill::CallSkillImage(SKILL skill)
{
	return MG_IMAGE->findImage(skillDB[skill]->m_skillIcon);
}
Image* CDB_Skill::CallDeactiveSkillImage(SKILL skill)
{
	return MG_IMAGE->findImage(skillDB[skill]->m_skillDeactiveIcon);
}
