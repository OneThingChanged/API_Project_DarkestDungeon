#include "framework.h"
#include "Unit.h"

Unit::Unit() {
    m_transform->m_pivot = Vector2(0.5, 1);
}
Unit::~Unit() {}

HRESULT Unit::Init()
{

    targetPos = Vector2(0,0);
    movePosMode = false;;
    movePosSpeed = 1;
    return S_OK;
}

void Unit::Update(float deltaTime, float worldTime)
{

    if (m_collider->CheckColliderBoxWithPoint(g_ptMouse))
    {
        if (MG_INPUT->IsDownLMB())
        {
            if (canTriggerDown)
            {
                m_triggerWhenDown(m_partyIndex);
            }
        }
    }

    if (movePosMode)
    {
        m_transform->m_pos += (targetPos - m_transform->m_pos).Normalize() * movePosSpeed;
    }
}

void Unit::LateUpdate()
{
}

void Unit::BackRender(HDC _hdc)
{
}

void Unit::Render(HDC _hdc)
{
}

void Unit::FrontRender(HDC _hdc)
{
    if (isSelected)
    {
        showSelMember(_hdc);
    }

    showHpBar(_hdc);

    if (m_collider)
    {
        if (MG_INPUT->isToggleKey(VK_TAB))
        {
            RectangleMake(_hdc, m_collider->rect, m_transform->m_pos - MG_CAMERA->GetPos());
        }
    }

}

void Unit::Release()
{
    GameObject::Release();
}


void Unit::SetMemberOverlay()
{
    selectedMem.m_img = MG_IMAGE->findImage(IMAGE::Target_Selected1);

    ImageData temp;
    for (int i = 0; i < 10; i++)
    {
        temp.m_img = MG_IMAGE->findImage("HP_empty");
        HPbarBack.push_back(temp);
        temp.m_img = MG_IMAGE->findImage("HP_full");
        HPbarFront.push_back(temp);
    }
}

void Unit::showSelMember(HDC _hdc)
{
	selectedMem.m_trans.m_pos = Vector2(
		m_transform->m_pos.x - 87,
		m_transform->m_pos.y - 78);

	selectedMem.m_img->render(_hdc, &selectedMem.m_trans);
}

void Unit::showHpBar(HDC _hdc)
{
    ImageData temp;
    for (size_t i = 0; i < HPbarBack.size(); i++)
    {
        HPbarBack[i].m_trans.m_pos = Vector2(
            m_transform->m_pos.x - 50 + 10 * i,
            m_transform->m_pos.y + 15);
        HPbarBack[i].m_img->render(_hdc, &HPbarBack[i].m_trans);
    }

    float a = ((float)getMaxHP() - (float)getHP()) / (float)getMaxHP();
    int percent = 0;
    if (a >= 1.f)
    {
        percent = 0;
    }
    else if (a == 0.f) {
        percent = 10;
    }
    else {
        percent = 11 - a * 10;
    }

    for (size_t i = 0; i < percent; i++)
    {
        HPbarFront[i].m_trans.m_pos = Vector2(
            m_transform->m_pos.x - 50 + 10 * i,
            m_transform->m_pos.y + 15);

            HPbarFront[i].m_img->render(_hdc, &HPbarFront[i].m_trans);
    }
}

UNITTYPE Unit::GetUnitType()
{
    return m_unitType;
}

int Unit::GetSpeed()
{
    return 0;
}


int Unit::getHP()
{
    return 0;
}

bool Unit::reduceHP(int hp)
{
    return false;
}

void Unit::increaseHP(int hp)
{
}

int Unit::getSPD()
{
    return 0;
}

int Unit::GetPartyIndex()
{
    return m_partyIndex;
}

void Unit::SetPartyIndex(int pos)
{
    m_partyIndex = pos;
}

int Unit::GetPartyPos()
{
    return m_partyPos;
}

void Unit::SetPartyPos(int pos)
{
    m_partyPos = pos;
}


//virtual void SetPartyIndex(int index) { m_partyIndex = index; }
//inline int Unit::GetPartyPos()
//{
//	return m_partyPos;
//}
//inline void Unit::SetPartyPos(int pos)
//{
//	m_partyPos = pos;
//}
//virtual int GetPartyIndex() { return m_partyIndex; }

int Unit::getResist(int index)
{
    return 0;
}

bool Unit::getAttribute(int index)
{
    return false;
}

void Unit::setHP(int hp)
{
}

int Unit::getMaxHP()
{
    return 0;
}

bool Unit::GetAffliction()
{
    return false;
}

bool Unit::GetAlive()
{
    return false;
}

void Unit::setSPD(int spd)
{
}


void Unit::setResist(int index, bool val)
{
}

void Unit::setAttribute(int index, bool val)
{
}
