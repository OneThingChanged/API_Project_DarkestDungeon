#pragma once
#include "Info.h"

class Info_Unit : public Info
{
public:
	int m_HP;
	int m_maxHP;
	int m_SPD;
	bool isAlive;
	bool isCollipse;
	bool isAffliction;

	int m_DMG; //skill���� �� �־��ֱ�


	int m_ACRY; //���߷�
	int m_CRI;
	int m_DEF;
	int m_DODGE; //ȸ����

	//����
	int resist[5]; //stun, blight, bleed, debuff, move
	//����
	bool attribute[8] = { false }; //stun, blight, bleed, debuff, buff, move, marked, death

	UNITTYPE unitType;

	IMAGE imageIdle;
	IMAGE imageCombat;
	IMAGE imageWalk;
	IMAGE imageInvestigate;
	IMAGE imageDefend;
	IMAGE imageAttack;
	IMAGE imageCharge;
	IMAGE imageBuff;
	IMAGE imageDebuff;
	IMAGE imageCorpse;

	IMAGE portrait;

	vector<int> skillLvl;
	vector<SKILL> ownSkill;
	vector<CAMP_SKILL> ownCamp_Skill;
	
	virtual void Release();
};
