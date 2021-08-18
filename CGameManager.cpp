#include "framework.h"
#include "CGameManager.h"
#include "CHero.h"
#include "CParty.h"
#include "CVestal.h"
#include "DungeonScene.h"
#include "CBTN_Skill.h"
#include "dungeonUI.h"
#include "dungeonUI_HeroInfo.h"

CGameManager::CGameManager() {}
CGameManager::~CGameManager() {}

HRESULT CGameManager::Init()
{
	
	heroID = 0;
	RegisterHeroToOwnList(CreateHero("member1", JOB::Crusader));
	RegisterHeroToOwnList(CreateHero("member2", JOB::Vestal));
	RegisterHeroToOwnList(CreateHero("member3", JOB::PlagueDoctor));
	RegisterHeroToOwnList(CreateHero("member4", JOB::Highwayman));

	//RegisterHeroToOwnList(CreateHero("member5", JOB::Crusader));
	//RegisterHeroToOwnList(CreateHero("member6", JOB::Vestal));
	/*RegisterHeroToOwnList(CreateHero("member5", JOB::Highwayman));
	RegisterHeroToOwnList(CreateHero("member6", JOB::PlagueDoctor));
	RegisterHeroToOwnList(CreateHero("member7", JOB::Crusader));
	RegisterHeroToOwnList(CreateHero("member8", JOB::Vestal));
	RegisterHeroToOwnList(CreateHero("member9", JOB::Crusader));
	RegisterHeroToOwnList(CreateHero("member10", JOB::Vestal));
	RegisterHeroToOwnList(CreateHero("member11", JOB::Highwayman));
	RegisterHeroToOwnList(CreateHero("member12", JOB::PlagueDoctor));*/
	setParty();


	//��Ƽ�� nullptr ä���
	m_partyOrigin.push_back(nullptr);
	m_partyOrigin.push_back(nullptr);
	m_partyOrigin.push_back(nullptr);
	m_partyOrigin.push_back(nullptr);





	m_dungeonScene = MG_SCENE->dungeonScene;
	m_townScene = MG_SCENE->townScene;

	return S_OK;
}

void CGameManager::Update(float deltaTime, float worldTime)
{
	if (MG_INPUT->isOnceKeyDown(VK_F1))
	{
		RegisterHeroToParty(0);
		RegisterHeroToParty(1);
		RegisterHeroToParty(2);
		RegisterHeroToParty(3);
		MG_SCENE->changeScene(SCENETYPE::Dungeon);
	}
}

void CGameManager::LateUpdate()
{
}

void CGameManager::BackRender(HDC _hdc)
{
}

void CGameManager::Render(HDC _hdc)
{
	char str[256];
	string strFrame;
	SetBkMode(_hdc, TRANSPARENT);
	SetTextColor(_hdc, RGB(255, 0, 255));
	sprintf_s(str, "mousePos : %d, %d", (int)g_ptMouse.x, (int)g_ptMouse.y);
	TextOut(_hdc, 0, 180, str, strlen(str));
}

void CGameManager::FrontRender(HDC _hdc)
{

}

void CGameManager::Release()
{
	for (size_t i = 0; i < m_partyOrigin.size(); i++)
	{
		m_partyOrigin[i] = nullptr;
	}
	m_partyOrigin.clear();

	for (size_t i = 0; i < m_ownHeroes.size(); i++)
	{
		SAFE_DELETE(m_ownHeroes[i]);
	}
	m_ownHeroes.clear();
}

bool CGameManager::RegisterHeroToParty(CHero* hero)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (m_partyOrigin[i] == nullptr)
		{
			m_partyOrigin[i] = hero;
			return true;
		}

	}
	return false;

	/*if (m_partyOrigin.size() < 4)
	{
		m_partyOrigin.push_back(hero);
		return true;
	}return false;*/
}

bool CGameManager::RegisterHeroToParty(int ownIndex)
{
	return RegisterHeroToParty(m_ownHeroes[ownIndex]);
}

void CGameManager::RegisterHeroToOwnList(CHero* hero)
{
	m_ownHeroes.push_back(hero);

}

bool CGameManager::RemoveHeroFromParty(int id)
{
	//if (m_partyOrigin[id] != nullptr)
	//{
	//	m_partyOrigin[id] = nullptr;
	//	return true;

	//}
	//return false;
	if (id < m_partyOrigin.size())
	{

		m_partyOrigin.erase(m_partyOrigin.begin() + id);
		return true;
	}
	return false;
}

bool CGameManager::RemoveHeroFromOwnList(int heroId)
{
	for (size_t i = 0; i < m_ownHeroes.size(); i++)
	{
		if (heroId == m_ownHeroes[i]->GetHeroID())
		{
			m_ownHeroes[i]->Disable();
			m_ownHeroes.erase(m_ownHeroes.begin() + i);
			return true;
		}
	}
	return false;
}

void CGameManager::setParty()
{
	m_party = new CParty;
	m_party->Init(1, 1, 1);
	m_party->Disable();
	MG_GMOBJ->RegisterObj("Party", m_party);
}

CParty* CGameManager::GetParty()
{
	return m_party;
}

vector<CHero*> CGameManager::GetHeroes()
{
	return m_partyOrigin;
}

CHero* CGameManager::GetHero(int index)
{
	return index < m_ownHeroes.size() ? m_ownHeroes[index] : nullptr;
}

CHero* CGameManager::GetHeroFromParty(int index)
{
	return index < m_partyOrigin.size() ? m_partyOrigin[index]: nullptr;
}

CHero* CGameManager::CreateHero(string name, JOB job)
{
	CHero* hero = new CHero();
	hero->SetHeroID(heroID++);
	switch (job)
	{
	case JOB::Crusader:
		hero->Init(DB_UNIT->CallHero(JOB::Crusader));
		break;
	case JOB::Vestal:
		hero->Init(DB_UNIT->CallHero(JOB::Vestal));
		break;
	case JOB::PlagueDoctor:
		hero->Init(DB_UNIT->CallHero(JOB::PlagueDoctor));
		break;
	case JOB::Highwayman:
		hero->Init(DB_UNIT->CallHero(JOB::Highwayman));
		break;
	default:
		break;
	}
	MG_GMOBJ->RegisterObj(hero);
	hero->Disable();
	return hero;
}

CHero* CGameManager::GetCurSelHero()
{
	return m_CurSelHero;
}

void CGameManager::SetCurSelHero(int index)
{
	m_CurSelHero = m_party->GetHero(index);
	if (m_CurSelHero)
	{
		for (int i = 0; i < m_party->GetPartySize(); i++)
		{
			m_party->GetHero(i)->isSelected = false;
		}
		m_party->GetHero(index)->isSelected = true;

		m_dungeonScene->m_dungeonUIinfo->SetPortrait(m_CurSelHero->GetInfo()->portrait);
		m_dungeonScene->m_dungeonUIinfo->SetWeapon(m_CurSelHero->GetInfo()->weapon[0]);
		m_dungeonScene->m_dungeonUIinfo->SetArmor(m_CurSelHero->GetInfo()->armor[0]);

		vector<SKILL> temp = m_CurSelHero->GetInfo()->ownSkill;


		for (int j = 0; j < m_dungeonScene->m_dungeonUI->skillBTNs.size(); j++)
		{
			if (temp.size() > j)
			{
				m_dungeonScene->m_dungeonUI->skillBTNs[j]->Enable();
				m_dungeonScene->m_dungeonUI->skillBTNs[j]->SetSkill(temp[j]);
			}
			else {
				m_dungeonScene->m_dungeonUI->skillBTNs[j]->Disable();
			}

		}
	}
}