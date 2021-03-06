#pragma once
#include "CComponent.h"
#include "GameObject.h"

class CCollider : public CComponent
{
private:
	CTransform* m_transform;
	friend GameObject;

protected:
	CCollider();

public:
	COLLIDERTYPE m_colliderType;
	Vector2 m_pos;
	Rect rect;
	Rect transRect;

	CCollider(CTransform* transform);
	~CCollider();

	void SetRect(float l, float t, float r, float b);
	void SetColliderBox(Vector2 pos, Vector2 size);

	bool CheckXCollision(int x);

	bool CheckColliderBoxWithPoint(Vector2 pos);
	bool CheckColliderBoxWithPoint(POINT pos);

	bool UICheckColliderBoxWithPoint(Vector2 pos);
	bool UICheckColliderBoxWithPoint(POINT pos);
};