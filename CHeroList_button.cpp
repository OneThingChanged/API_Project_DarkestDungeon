#include "framework.h"
#include "CHeroList_button.h"
#include"CHero.h"
#include"Hero_Roster.h"
#include "TownScene.h"
#include"CUI_Panel_Hero.h"
#include"CUIPanel_StageCoach.h"

CHeroList_button::CHeroList_button()
{
	m_layer = LAYER::UIButton;
	canTriggerDrag = false;
	m_index = -1;
}
CHeroList_button::~CHeroList_button() {}

HRESULT CHeroList_button::Init()
{
	m_transform->m_pivot = Vector2(0.5, 0.5);
	m_heroBG = new CSpriteRenderer(IMAGE::rosterelement_res, m_transform);
	m_heroBG->useCustomPos = true;
	m_heroBG->pos = Vector2(130, 0);
	originPos = Vector2(0, 0);

	return S_OK;
}

void CHeroList_button::Update(float deltaTime, float worldTime)
{
	if (!townScene->isDrag)
	{
		if (m_collider->UICheckColliderBoxWithPoint(g_ptMouse))
		{
			if (MG_INPUT->IsDownLMB())
			{
				/*selDragButton = this;
				selKeyIndex = VK_LBUTTON;*/
				//originPos = m_transform->m_pos;
				if (canTriggerDownForHerolist)
				{
					townScene->isDrag = true;
					townScene->curDragHeroIndex = m_index;
					m_triggerWhenDownForHeroList(btType, m_index);
				}
			}

			if (MG_INPUT->IsDownRMB())
			{
				if (canTriggerDownRightButton)
				{
					townScene->curDragHeroIndex = m_index;
					townScene->m_hero_panel->curHeroListType = btType;
					m_triggerWhenDownRightButton();
				}
			}
		}
	}
}

void CHeroList_button::LateUpdate()
{
}

void CHeroList_button::BackRender(HDC _hdc)
{
}

void CHeroList_button::Render(HDC _hdc)
{
	m_spriteRenderer->RenderUI(_hdc);
	m_heroBG->RenderUI(_hdc);
	if (MG_INPUT->isToggleKey(VK_TAB))
	{
		RectangleMake(_hdc, m_collider->rect, m_transform->m_pos);
	}
}

void CHeroList_button::FrontRender(HDC _hdc)
{
	//for (size_t i = 0; i < MG_GAME->m_partyOrigin.size(); i++)
	//{
	//	char str[256];
	//	sprintf_s(str, "(%d , %d)",(int)originPos.x, (int)originPos.y);
	//	TextOut(_hdc, 500, 500+i*50, str, strlen(str));
	//	//OutputDebugString(TEXT(str));
	//}
}

void CHeroList_button::Release()
{
	CDragButton::Release();
	SAFE_DELETE(m_heroBG);
	SAFE_DELETE(m_characterBG);
}

void CHeroList_button::DragHeroList()
{
	m_transform->m_pos += CInputManager::getSingleton()->GetptDeltaMouse();
}