#include "framework.h"
#include "CPlayer.h"

CPlayer::CPlayer() {}
CPlayer::~CPlayer() {}

HRESULT CPlayer::Init()
{
	m_image = MG_IMAGE->findImage(IMAGE::Vestal_Idle);
	m_layer = LAYER::Player;

	//mini_rc = RectMakeCenter(100 + m_rockman->getX() / 10 - m_camera / 10, 50 + m_rockman->getY() / 10, 10, 10);
	return S_OK;
}

void CPlayer::Update(float deltaTime, float worldTime)
{
	if (MG_INPUT->isStayKeyDown(VK_LEFT))
	{
		if (m_transform->m_pos.x > 0) m_transform->m_pos.x -= 5;
	}
	if (MG_INPUT->isStayKeyDown(VK_RIGHT))
	{
		if (m_transform->m_pos.x < WORLDSIZEX - 100) m_transform->m_pos.x += 5;
	}
	if (MG_INPUT->isStayKeyDown(VK_UP))
	{
		if (m_transform->m_pos.y > 0 ) m_transform->m_pos.y -= 5;
	}
	if (MG_INPUT->isStayKeyDown(VK_DOWN))
	{
		if (m_transform->m_pos.y < WORLDSIZEY - 200) m_transform->m_pos.y += 5;
	}
}

void CPlayer::LateUpdate()
{
}

void CPlayer::BackRender(HDC _hdc)
{
}

void CPlayer::Render(HDC _hdc)
{
	m_image->frameRender(_hdc,m_transform);
}

void CPlayer::FrontRender(HDC _hdc)
{
}

void CPlayer::Release()
{
	Unit::Release(); 
}