#include "framework.h"
#include "CUI_Panel_Hero.h"
#include"CEst_UI.h"
#include"CButton.h"
#include"CHeroList_button.h"
#include"TownScene.h"
#include"CHero.h"
#include"CBTN_Skill.h"
#include"CEquipButton.h"
#include"CPosition_Button.h"
#include "CBTN_CampSkill.h"
#include "CUIPanel_StageCoach.h";

CUI_Panel_Hero::CUI_Panel_Hero()
{
	m_layer = LAYER::UI;
}

CUI_Panel_Hero::~CUI_Panel_Hero()
{
}

HRESULT CUI_Panel_Hero::Init()
{
	CEst_UI::Init();
	m_windowPanelBG = new CSpriteRenderer(IMAGE::characterpanel_bg, m_transform);
	m_windowPanel = new CSpriteRenderer(IMAGE::characterpanel, m_transform);

	m_windowPanelChar = new CSpriteRenderer(IMAGE::abbey_char, m_transform);
	m_windowPanelChar->useCustomPos = true;
	m_windowPanelChar->pos = Vector2(93, 80);
	m_windowPanelChar->useCustomScale = true;
	m_windowPanelChar->scale = Vector2(1, 1);

	m_HeroImg = new CSpriteRenderer(IMAGE::Crusader_sword, m_transform);
	m_HeroImg->useCustomPos = true;
	m_HeroImg->pos = Vector2(125, 500);
	m_HeroImg->useCustomScale = true;
	m_HeroImg->scale = Vector2(0.5, 0.5);

	CreateHeroSkill();
	CreateHeroEquip();
	CreatPostionButton(); 
	CreateCampSkill();
	SetPhrases_Img();
	SetResistanceInfo();

	isShowCoachHero = false; 

	m_transform->m_pivot = Vector2(-0.095, -0.095);
	Disable();
	return S_OK; 
}

void CUI_Panel_Hero::Update(float deltaTime, float worldTime)
{
}

void CUI_Panel_Hero::LateUpdate()
{
}

void CUI_Panel_Hero::BackRender(HDC _hdc)
{
}

void CUI_Panel_Hero::Render(HDC _hdc)
{
}

void CUI_Panel_Hero::FrontRender(HDC _hdc)
{
	m_windowPanel->Render(_hdc);
	m_windowPanelBG->Render(_hdc);
	m_windowPanelChar->Render(_hdc); //characterBg Img
	m_HeroImg->Render(_hdc);

	DrawPhrases_Img(_hdc);
	DrawResistanceInfo(_hdc);
	ShowHeroInfo(_hdc);
}

void CUI_Panel_Hero::Release()
{
}

void CUI_Panel_Hero::Enable()
{
	CloseHeroSkill();
	CloseHeroEquip();
	CloseCampSkill();
	
	if (curHeroListType == HeroListBtType::ownHero)
	{
		SetHeroPanel();
		SetHeroSkill();
		SetHeroEquip();
		SetCampSkill();
		for (size_t i = 0; i < m_postion_buttonVec.size(); i++)
		{
			m_postion_buttonVec[i]->isActive = true;
		}
	}
	else
	{
		setCoachHeroPanel();
		SetCoachHeroSkill();
		SetCoachHeroEquip();
		SetCoachCampSkill();
		for (size_t i = 0; i < m_postion_buttonVec.size(); i++)
		{
			m_postion_buttonVec[i]->isActive = true;
		}
	}
	CEst_UI::Enable();
}

void CUI_Panel_Hero::Disable()
{
	CEst_UI::Disable();
	CloseHeroSkill();
	CloseHeroEquip();
	CloseCampSkill();
	for (size_t i = 0; i < m_postion_buttonVec.size(); i++)
	{
		m_postion_buttonVec[i]->isActive = false;
	}
}

void CUI_Panel_Hero::SetHeroPanel()
{
	switch (MG_GAME->GetHero(townScene->curDragHeroIndex)->GetJob())
	{
	case JOB::Crusader:
		m_windowPanelChar->SetImage(IMAGE::crusader_header);
		m_HeroImg->SetImage(IMAGE::Crusader_sword);
		break;
	case JOB::Vestal:
		m_windowPanelChar->SetImage(IMAGE::vestal_header);
		m_HeroImg->SetImage(IMAGE::Vestal_mace);
		break;
	case JOB::Highwayman:
		m_windowPanelChar->SetImage(IMAGE::highwayman_header);
		m_HeroImg->SetImage(IMAGE::Highwayman_pistol);
		break;
	case JOB::PlagueDoctor:
		m_windowPanelChar->SetImage(IMAGE::plague_doctor_header);
		m_HeroImg->SetImage(IMAGE::Plague_doctor_grenade);

		break;
	}
}

void CUI_Panel_Hero::setCoachHeroPanel()
{
	switch (townScene->m_stage_coach->m_OnCoach_HeroVec[townScene->curDragHeroIndex]->GetJob())
	{
	case JOB::Crusader:
		m_windowPanelChar->SetImage(IMAGE::crusader_header);
		m_HeroImg->SetImage(IMAGE::Crusader_sword);
		break;
	case JOB::Vestal:
		m_windowPanelChar->SetImage(IMAGE::vestal_header);
		m_HeroImg->SetImage(IMAGE::Vestal_mace);
		break;
	case JOB::Highwayman:
		m_windowPanelChar->SetImage(IMAGE::highwayman_header);
		m_HeroImg->SetImage(IMAGE::Highwayman_pistol);

		break;
	case JOB::PlagueDoctor:
		m_windowPanelChar->SetImage(IMAGE::plague_doctor_header);
		m_HeroImg->SetImage(IMAGE::Plague_doctor_grenade);

		break;
	}
}

void CUI_Panel_Hero::ShowHeroInfo(HDC _hdc)
{
	char str[256];
	string strFrame;
	SetBkMode(_hdc, TRANSPARENT);

	SetTextColor(_hdc, RGB(202, 201, 155));
	sprintf_s(str, "%s", "Name");
	TextOut(_hdc, 225, 130, str, strlen(str));
	
	CHero* hero;
	if (curHeroListType == HeroListBtType::coach)
	{
		hero = townScene->m_stage_coach->m_OnCoach_HeroVec[townScene->curDragHeroIndex];
	}
	else 
	{
		hero = MG_GAME->GetHero(townScene->curDragHeroIndex);
	}

	if (townScene->curDragHeroIndex > -1)
	{
		SetTextColor(_hdc, RGB(255, 255, 255));
		sprintf_s(str, "MAX HP :  %d", hero->getHP());
		TextOut(_hdc, 460, 470, str, strlen(str));

		sprintf_s(str, "DODGE :  %d", hero->GetDodge());
		TextOut(_hdc, 460, 490, str, strlen(str));

		sprintf_s(str, "PROT :  %d", hero->GetDef());
		TextOut(_hdc, 460, 510, str, strlen(str));

		sprintf_s(str, "SPD :  %d", hero->getSPD());
		TextOut(_hdc, 460, 530, str, strlen(str));

		sprintf_s(str, "ACC :  %d", hero->GetAcry());
		TextOut(_hdc, 660, 470, str, strlen(str));

		sprintf_s(str, "CRIT :  %d", hero->GetCri());
		TextOut(_hdc, 660, 490, str, strlen(str));

		sprintf_s(str, "DMG :  %d", hero->GetDmg());
		TextOut(_hdc, 660, 510, str, strlen(str));

		//stun, blight, bleed, debuff, move

		SetTextColor(_hdc, RGB(212, 187, 120));
		sprintf_s(str, "Stun :  %d", hero->getResist(0));
		TextOut(_hdc, 1010, 570, str, strlen(str));

		SetTextColor(_hdc, RGB(162, 175, 70));
		sprintf_s(str, "Blight :  %d", hero->getResist(1));
		TextOut(_hdc, 1230, 570, str, strlen(str));

		SetTextColor(_hdc, RGB(126, 8, 4));
		sprintf_s(str, "Bleed :  %d", hero->getResist(2));
		TextOut(_hdc, 1010, 600, str, strlen(str));

		SetTextColor(_hdc, RGB(195, 122, 81));
		sprintf_s(str, "Debuff :  %d", hero->getResist(3));
		TextOut(_hdc, 1230, 600, str, strlen(str));

		SetTextColor(_hdc, RGB(118, 164, 198));
		sprintf_s(str, "Move :  %d", hero->getResist(4));
		TextOut(_hdc, 1010, 630, str, strlen(str));
	}
}

void CUI_Panel_Hero::CreateHeroEquip()
{
	m_weapon = new CEquipButton();
	m_weapon->m_transform->m_pos = Vector2(440, 735);
	m_weapon->Init();
	m_weapon->Disable();
	MG_GMOBJ->RegisterObj(m_weapon);

	m_armor = new CEquipButton();
	m_armor->m_transform->m_pos = Vector2(530, 735);
	m_armor->Init();
	m_armor->Disable();
	MG_GMOBJ->RegisterObj(m_armor);
}

void CUI_Panel_Hero::SetHeroEquip()
{
	m_weapon->SetEquip(MG_GAME->GetHero(townScene->curDragHeroIndex)->GetWeapon());
	m_weapon->Enable();

	m_armor->SetEquip(MG_GAME->GetHero(townScene->curDragHeroIndex)->GetArmor());
	m_armor->Enable();
}

void CUI_Panel_Hero::SetCoachHeroEquip()
{
	m_weapon->SetEquip(townScene->m_stage_coach->m_OnCoach_HeroVec[townScene->curDragHeroIndex]->GetWeapon());
	m_weapon->Enable();

	m_armor->SetEquip(townScene->m_stage_coach->m_OnCoach_HeroVec[townScene->curDragHeroIndex]->GetArmor());
	m_armor->Enable();
}

void CUI_Panel_Hero::CloseHeroEquip()
{
	m_weapon->Disable();
	m_armor->Disable();
}

void CUI_Panel_Hero::CreateHeroSkill()
{
	for (size_t i = 0; i < 8; i++)
	{
		CBTN_Skill* m_skill = new CBTN_Skill();
		m_skill->Init();
		m_skill->m_transform->m_pos = Vector2(980 + 80 * i, 290);
		m_skill->Disable();
		MG_GMOBJ->RegisterObj(m_skill);
		m_skillbuttonVec.push_back(m_skill);
	}
}

void CUI_Panel_Hero::SetHeroSkill()
{
	auto tempVec = MG_GAME->GetHero(townScene->curDragHeroIndex)->GetOwnSkill();
	for (size_t i = 0; i < tempVec.size(); i++)
	{
		m_skillbuttonVec[i]->SetSkill(tempVec[i]);
		m_skillbuttonVec[i]->Enable();
	}
}

void CUI_Panel_Hero::SetCoachHeroSkill()
{
	auto tempVec = townScene->m_stage_coach->m_OnCoach_HeroVec[townScene->curDragHeroIndex]->GetOwnSkill();
	for (size_t i = 0; i < tempVec.size(); i++)
	{
		m_skillbuttonVec[i]->SetSkill(tempVec[i]);
		m_skillbuttonVec[i]->Enable();
	}
}

void CUI_Panel_Hero::CloseHeroSkill()
{
	for (size_t i = 0; i < m_skillbuttonVec.size(); i++)
	{
		m_skillbuttonVec[i]->Disable();
	}
}

void CUI_Panel_Hero::CreateCampSkill()
{
	for (size_t i = 0; i < 6; i++)
	{
		CBTN_CampSkill* m_campskill = new CBTN_CampSkill();
		m_campskill->Init();
		m_campskill->m_transform->m_pos = Vector2(980 + 80 * i, 445);
		m_campskill->Disable();
		MG_GMOBJ->RegisterObj(m_campskill);
		m_campSkillbuttonVec.push_back(m_campskill);
	}
}

void CUI_Panel_Hero::SetCampSkill()
{
	for (size_t i = 0; i < m_campSkillbuttonVec.size(); i++)
	{
		m_campSkillbuttonVec[i]->Enable();
	}
}

void CUI_Panel_Hero::SetCoachCampSkill()
{
	for (size_t i = 0; i < m_campSkillbuttonVec.size(); i++)
	{
		m_campSkillbuttonVec[i]->Enable();
	}
}

void CUI_Panel_Hero::CloseCampSkill()
{	
	for (size_t i = 0; i < m_campSkillbuttonVec.size(); i++)
	{
		m_campSkillbuttonVec[i]->Disable();
	}
}

void CUI_Panel_Hero::CreatPostionButton()
{
	for (size_t i = 0; i < 4; i++)
	{
		CPosition_Button* postion_button = new CPosition_Button();
		postion_button->m_transform->m_pos = Vector2(970 + 50 * i, 140+50);
		postion_button->Init();
		postion_button->AddSpriteRenderer(IMAGE::PositionButton_unable);
		postion_button->AddColliderBox();
		postion_button->Disable();
		MG_GMOBJ->RegisterObj(postion_button);
		m_postion_buttonVec.push_back(postion_button);
	}
	
	for (size_t i = 0; i < 4; i++)
	{
		CPosition_Button* Attackpostion_button = new CPosition_Button();
		Attackpostion_button->m_transform->m_pos = Vector2(1270 + 50 * i, 140+50);
		Attackpostion_button->Init();
		Attackpostion_button->AddSpriteRenderer(IMAGE::PositionButton_unable);
		Attackpostion_button->AddColliderBox();
		Attackpostion_button->Disable();
		MG_GMOBJ->RegisterObj(Attackpostion_button);
		m_postion_buttonVec.push_back(Attackpostion_button);
	}
}

void CUI_Panel_Hero::SetPhrases_Img()
{
	Quirk_Img = new CSpriteRenderer(IMAGE::Quirk, m_transform);
	Quirk_Img->useCustomPos = true;
	Quirk_Img->pos = Vector2(550, 190);

	OriginStatus_Img = new CSpriteRenderer(IMAGE::OriginStatus, m_transform);
	OriginStatus_Img->useCustomPos = true;
	OriginStatus_Img->pos = Vector2(510, 422);

	Equip_Img = new CSpriteRenderer(IMAGE::Equip, m_transform);
	Equip_Img->useCustomPos = true;
	Equip_Img->pos = Vector2(556, 571);

	CombatSkill_Img = new CSpriteRenderer(IMAGE::CombatSkill, m_transform);
	CombatSkill_Img->useCustomPos = true;
	CombatSkill_Img->pos = Vector2(1108, 116);

	CampingSkill_Img = new CSpriteRenderer(IMAGE::CampingSkill, m_transform);
	CampingSkill_Img->useCustomPos = true;
	CampingSkill_Img->pos = Vector2(1106, 350);

	Resistance_Img = new CSpriteRenderer(IMAGE::Resistance, m_transform);
	Resistance_Img->useCustomPos = true;
	Resistance_Img->pos = Vector2(1123, 513);

	Disease_Img = new CSpriteRenderer(IMAGE::Disease, m_transform);
	Disease_Img->useCustomPos = true;
	Disease_Img->pos = Vector2(1152, 677);
}

void CUI_Panel_Hero::DrawPhrases_Img(HDC _hdc)
{
	Quirk_Img->Render(_hdc);
	OriginStatus_Img->Render(_hdc);
	Equip_Img->Render(_hdc);
	CombatSkill_Img->Render(_hdc);
	CampingSkill_Img->Render(_hdc);
	Resistance_Img->Render(_hdc);
	Disease_Img->Render(_hdc);
}

void CUI_Panel_Hero::SetResistanceInfo()
{
	m_stunicon = new CSpriteRenderer(IMAGE::stun, m_transform);
	m_stunicon->useCustomPos = true;
	m_stunicon->pos = Vector2(980, 565);

	m_blighicon = new CSpriteRenderer(IMAGE::poison, m_transform);
	m_blighicon->useCustomPos = true;
	m_blighicon->pos = Vector2(1200, 562);

	m_bleedicon = new CSpriteRenderer(IMAGE::bleed, m_transform);
	m_bleedicon->useCustomPos = true;
	m_bleedicon->pos = Vector2(980, 595);

	m_debufficon = new CSpriteRenderer(IMAGE::debuff, m_transform);
	m_debufficon->useCustomPos = true;
	m_debufficon->pos = Vector2(1200, 595);

	m_moveicon = new CSpriteRenderer(IMAGE::move, m_transform);
	m_moveicon->useCustomPos = true;
	m_moveicon->pos = Vector2(980, 625);
}

void CUI_Panel_Hero::DrawResistanceInfo(HDC _hdc)
{
	m_stunicon->Render(_hdc);
	m_bleedicon->Render(_hdc);
	m_moveicon->Render(_hdc);
	m_blighicon->Render(_hdc);
	m_debufficon->Render(_hdc);
}