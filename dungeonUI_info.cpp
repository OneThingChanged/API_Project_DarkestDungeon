#include "framework.h"
#include "dungeonUI_info.h"
#include "CHero.h"
#include "CParty.h"

dungeonUI_info::dungeonUI_info() {}
dungeonUI_info::~dungeonUI_info() {}

HRESULT dungeonUI_info::Init()
{
    m_layer = LAYER::UI;

    selectedHeroIndex = 0; 

    setInfoImage();
    setButton();

    return S_OK;
}

void dungeonUI_info::Update(float deltaTime, float worldTime)
{
    setInfoImage();
}

void dungeonUI_info::LateUpdate()
{
}

void dungeonUI_info::BackRender(HDC _hdc)
{
}

void dungeonUI_info::Render(HDC _hdc)
{
    showHeroSkill(_hdc);
    showHeroEquip(_hdc);
    showHeroState(_hdc);
}

void dungeonUI_info::FrontRender(HDC _hdc)
{
    

}

void dungeonUI_info::Release()
{

}


//==================================


void dungeonUI_info::setInfoImage()
{
    //portrait and skill
    switch (MG_GAME->GetHero(selectedHeroIndex)->job)
    {
    case JOB::Crusader:
        portrait.m_img = MG_IMAGE->findImage("crusader_portrait");
        portrait.m_trans.m_pos = Vector2(364, 732);

        skill1.m_img = MG_IMAGE->findImage("crusader_skill1");
        skill1.m_trans.m_pos = Vector2(585, 732);

        skill2.m_img = MG_IMAGE->findImage("crusader_skill2");
        skill2.m_trans.m_pos = Vector2(655, 732);

        skill3.m_img = MG_IMAGE->findImage("crusader_skill3");
        skill3.m_trans.m_pos = Vector2(725, 732);

        skill4.m_img = MG_IMAGE->findImage("crusader_skill4");
        skill4.m_trans.m_pos = Vector2(795, 732);
        break;

    case JOB::Highwayman:
        break;

    case JOB::PlagueDoctor:
        break;

	case JOB::Vestal:
        portrait.m_img = MG_IMAGE->findImage("vestal_portrait");
        portrait.m_trans.m_pos = Vector2(364, 732);

        skill1.m_img = MG_IMAGE->findImage("vestal_skill1");
        skill1.m_trans.m_pos = Vector2(585, 732);

		skill2.m_img = MG_IMAGE->findImage("vestal_skill2");
		skill2.m_trans.m_pos = Vector2(655, 732);

		skill3.m_img = MG_IMAGE->findImage("vestal_skill3");
		skill3.m_trans.m_pos = Vector2(725, 732);

		skill4.m_img = MG_IMAGE->findImage("vestal_skill4");
		skill4.m_trans.m_pos = Vector2(795, 732);
		break;
    }

    ImageData temp;
    //move
    temp.m_img = MG_IMAGE->findImage("ability_move");
    temp.m_trans.m_pos = Vector2(865, 732);
    m_heroInfoImage.push_back(temp);

    //pass
    temp.m_img = MG_IMAGE->findImage("ability_pass");
    temp.m_trans.m_pos = Vector2(935, 732);
    m_heroInfoImage.push_back(temp);

    //equip
    switch (MG_GAME->GetHero(selectedHeroIndex)->job)
    {
    case JOB::Crusader:
        armor.m_img = MG_IMAGE->findImage("vestal_armor");
        armor.m_trans.m_pos = Vector2(575, 868);
        weapon.m_img = MG_IMAGE->findImage("vestal_weapon");
        weapon.m_trans.m_pos = Vector2(658, 868);
        break;

    case JOB::Highwayman:
        break;

    case JOB::PlagueDoctor:
        break;

    case JOB::Vestal:
        armor.m_img = MG_IMAGE->findImage("vestal_armor");
        armor.m_trans.m_pos = Vector2(575, 868);
        weapon.m_img = MG_IMAGE->findImage("vestal_weapon");
        weapon.m_trans.m_pos = Vector2(658, 868);
        break;
    }

}

void dungeonUI_info::setButton()
{
    CButton_buttonPosMove* bt_hero1 = new CButton_buttonPosMove;
    bt_hero1->setBtTarget(MG_GAME->GetHero(0));
    bt_hero1->AddColliderBox(100, 285);
    bt_hero1->AddSpriteRenderer("button");
    bt_hero1->SetTriggerWhenClick(this, &dungeonUI_info::selHero1);
    MG_GMOBJ->RegisterObj("selHero1", bt_hero1);

    CButton_buttonPosMove* bt_hero2 = new CButton_buttonPosMove;
    bt_hero2->setBtTarget(MG_GAME->GetHero(1));
    bt_hero2->AddColliderBox(100, 285);
    bt_hero2->AddSpriteRenderer("button");
    bt_hero2->SetTriggerWhenClick(this, &dungeonUI_info::selHero2);
    MG_GMOBJ->RegisterObj("selHero2", bt_hero2);

    CButton_buttonPosMove* bt_hero3 = new CButton_buttonPosMove;
    bt_hero3->setBtTarget(MG_GAME->GetHero(2)); 
    bt_hero3->AddColliderBox(100, 285);
    bt_hero3->AddSpriteRenderer("button");
    bt_hero3->SetTriggerWhenClick(this, &dungeonUI_info::selHero3);
    MG_GMOBJ->RegisterObj("selHero3", bt_hero3);

    CButton_buttonPosMove* bt_hero4 = new CButton_buttonPosMove;
    bt_hero4->setBtTarget(MG_GAME->GetHero(3));
    bt_hero4->AddColliderBox(100, 285);
    bt_hero4->AddSpriteRenderer("button");
    bt_hero4->SetTriggerWhenClick(this, &dungeonUI_info::selHero4);
    MG_GMOBJ->RegisterObj("selHero4", bt_hero4);
}

void dungeonUI_info::showHeroState(HDC _hdc)
{
    char str[256];
    string strFrame;
    SetBkMode(_hdc, TRANSPARENT);

    for (int i = 0; i < MG_GAME->GetHeroes().size(); i++)
    {
        if (MG_GAME->GetHero(i)->isSelected == true)
        {
            selectedHeroIndex = i;
        }
    }

    SetTextColor(_hdc, RGB(202, 201, 155));
    sprintf_s(str, "%s", "Name");
    TextOut(_hdc, 450, 740, str, strlen(str));

    SetTextColor(_hdc, RGB(255, 0, 0));
    switch (MG_GAME->GetHero(selectedHeroIndex)->job)
    {
    case JOB::Crusader:
        
        sprintf_s(str, "33 / %d", MG_GAME->GetHero(selectedHeroIndex)->m_HP);
        TextOut(_hdc, 400, 835, str, strlen(str));
        SetTextColor(_hdc, RGB(48, 48, 50));
        sprintf_s(str, "Crusader");
        break;

    case JOB::Highwayman:
        sprintf_s(str, "23 / %d", MG_GAME->GetHero(selectedHeroIndex)->m_HP);
        TextOut(_hdc, 400, 835, str, strlen(str));
        SetTextColor(_hdc, RGB(48, 48, 50));
        sprintf_s(str, "Highwayman");
        break;

    case JOB::PlagueDoctor:
        sprintf_s(str, "22 / %d", MG_GAME->GetHero(selectedHeroIndex)->m_HP);
        TextOut(_hdc, 400, 835, str, strlen(str));
        SetTextColor(_hdc, RGB(48, 48, 50));
        sprintf_s(str, "PlagueDoctor");
        break;

    case JOB::Vestal:
        sprintf_s(str, "24 / %d", MG_GAME->GetHero(selectedHeroIndex)->m_HP);
        TextOut(_hdc, 400, 835, str, strlen(str));
        SetTextColor(_hdc, RGB(48, 48, 50));
        sprintf_s(str, "Vestal");
        break;
    }
    TextOut(_hdc, 450, 780, str, strlen(str));

    SetTextColor(_hdc, RGB(255, 255, 255));
    sprintf_s(str, "200 / %d", MG_GAME->GetHero(selectedHeroIndex)->m_STRS);
    TextOut(_hdc, 400, 860, str, strlen(str));

    sprintf_s(str, "ACC         %d", MG_GAME->GetHero(selectedHeroIndex)->m_ACRY);
    TextOut(_hdc, 380, 885, str, strlen(str));
    sprintf_s(str, "CRIT        %d", MG_GAME->GetHero(selectedHeroIndex)->m_CRI);
    TextOut(_hdc, 380, 905, str, strlen(str));
    sprintf_s(str, "DMG       %d", MG_GAME->GetHero(selectedHeroIndex)->m_DMG);
    TextOut(_hdc, 380, 925, str, strlen(str));
    sprintf_s(str, "DODGE   %d", MG_GAME->GetHero(selectedHeroIndex)->m_DODGE);
    TextOut(_hdc, 380, 945, str, strlen(str));
    sprintf_s(str, "PROT      %d", MG_GAME->GetHero(selectedHeroIndex)->m_DEF);
    TextOut(_hdc, 380, 965, str, strlen(str));
    sprintf_s(str, "SPD        %d", MG_GAME->GetHero(selectedHeroIndex)->m_SPD);
    TextOut(_hdc, 380, 985, str, strlen(str));
}

void dungeonUI_info::showHeroSkill(HDC _hdc)
{
    portrait.m_img->renderUI(_hdc, &portrait.m_trans);
    skill1.m_img->renderUI(_hdc, &skill1.m_trans);
    skill2.m_img->renderUI(_hdc, &skill2.m_trans);
    skill3.m_img->renderUI(_hdc, &skill3.m_trans);
    skill4.m_img->renderUI(_hdc, &skill4.m_trans);

    for (int i = 0; i < 2; i++)
    {
        m_heroInfoImage[i].m_img->renderUI(_hdc, &m_heroInfoImage[i].m_trans);
    }
}

void dungeonUI_info::showHeroEquip(HDC _hdc)
{
    armor.m_img->renderUI(_hdc, &armor.m_trans);
    weapon.m_img->renderUI(_hdc, &weapon.m_trans);
}

void dungeonUI_info::selHero1()
{
    for (int i = 0; i < MG_GAME->GetHeroes().size(); i++)
    {
        if (i == 0) MG_GAME->GetHero(i)->isSelected = true;
        else MG_GAME->GetHero(i)->isSelected = false;
    }
}

void dungeonUI_info::selHero2()
{
    for (int i = 0; i < MG_GAME->GetHeroes().size(); i++)
    {
        if (i == 1) MG_GAME->GetHero(i)->isSelected = true;
        else MG_GAME->GetHero(i)->isSelected = false;
    }
}

void dungeonUI_info::selHero3()
{
    for (int i = 0; i < MG_GAME->GetHeroes().size(); i++)
    {
        if (i == 2) MG_GAME->GetHero(i)->isSelected = true;
        else MG_GAME->GetHero(i)->isSelected = false;
    }
}

void dungeonUI_info::selHero4()
{
    for (int i = 0; i < MG_GAME->GetHeroes().size(); i++)
    {
        if (i == 3) MG_GAME->GetHero(i)->isSelected = true;
        else MG_GAME->GetHero(i)->isSelected = false;
    }
}