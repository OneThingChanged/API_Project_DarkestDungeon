#include "framework.h"
#include "CampingTrainer.h"
#include"CButton.h"
#include"CHeroList_button.h"
CampingTrainer::CampingTrainer()
{
}

CampingTrainer::~CampingTrainer()
{
}

HRESULT CampingTrainer::Init()
{
    isActive = false;
    //나가기버튼
    m_quick = new CButton();
    m_quick->m_transform->m_pos = Vector2(WINSIZEX - 400, 100);
    m_quick->AddColliderBox(50, 50);
    m_quick->AddSpriteRenderer("quick");
    m_quick->isActive = false;
    m_quick->SetTriggerWhenDown(this, &CampingTrainer::FinishUI);
    MG_GMOBJ->RegisterObj("quick", m_quick);
  
    m_windowPanelBG = new CSpriteRenderer(IMAGE::camping_trainer_bg, m_transform);
    m_windowPanelChar = new CSpriteRenderer(IMAGE::camping_trainer_char, m_transform);
    m_transform->m_pivot = Vector2(-0.095, -0.095);
  
    m_HeroList_button = new CHeroList_button();

    return S_OK;
}

void CampingTrainer::Update(float deltaTime, float worldTime)
{
}

void CampingTrainer::LateUpdate()
{
}

void CampingTrainer::BackRender(HDC _hdc)
{
}

void CampingTrainer::Render(HDC _hdc)
{
}

void CampingTrainer::FrontRender(HDC _hdc)
{
    
        m_windowPanelBG->Render(_hdc);
        m_windowPanelChar->Render(_hdc);
        m_quick->isActive = true;
    
}

void CampingTrainer::Release()
{
}

void CampingTrainer::Setquick()
{
   
}

void CampingTrainer::FinishUI()
{
    m_quick->isActive = false;
    isActive = false;
}
