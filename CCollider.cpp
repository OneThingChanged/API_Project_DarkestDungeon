#include "framework.h"


CCollider::CCollider()
{
	rect.l = 0;
	rect.t = 0;
	rect.r = 0;
	rect.b = 0;
	m_pos = Vector2(0, 0);
	m_colliderType = COLLIDERTYPE::BOX;
}

CCollider::CCollider(CTransform* transform) {
	m_transform = transform;
	rect.l = 0;
	rect.t = 0;
	rect.r = 0;
	rect.b = 0;
	m_pos = Vector2(0, 0);
	m_colliderType = COLLIDERTYPE::BOX;
}

CCollider::~CCollider()
{
	
}

void CCollider::SetRect(float l, float t, float r, float b)
{
	rect.SetRect(l, t, r, b);
}



bool CCollider::CheckXCollision(int x)
{
	if (m_transform->m_pos.x + rect.l < x && m_transform->m_pos.x + rect.r > x)
	{
		return true;
	}
	else return false;
}

bool CCollider::CheckColliderBoxWithPoint(Vector2 _pos) 
{
	if (rect.l < _pos.x &&
		rect.r > _pos.x &&
		rect.t < _pos.y &&
		rect.b > _pos.y)
	{
		return true;
	}
	else return false;
}



bool CCollider::CheckColliderBoxWithPoint(POINT _pos) 
{
	if (rect.l < _pos.x &&
		rect.r > _pos.x &&
		rect.t < _pos.y &&
		rect.b > _pos.y)
	{
		return true;
	}
	else return false;
}

bool CCollider::new_CheckColliderBoxWithPoint(Vector2 pos)
{
	if (m_transform->m_pos.x + rect.l < pos.x &&
		m_transform->m_pos.x + rect.r > pos.x &&
		m_transform->m_pos.y + rect.t < pos.y &&
		m_transform->m_pos.y + rect.b > pos.y)
	{
		return true;
	}
	else return false;
}

bool CCollider::new_CheckColliderBoxWithPoint(POINT pos)
{
	if (m_transform->m_pos.x + rect.l < pos.x &&
		m_transform->m_pos.x + rect.r > pos.x &&
		m_transform->m_pos.y + rect.t < pos.y &&
		m_transform->m_pos.y + rect.b > pos.y)
	{
		return true;
	}
	else return false;
}
