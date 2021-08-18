#include "framework.h"
#include "MonsterIndicator.h"
#include "CTransform.h"

MonsterIndicator::MonsterIndicator()
{
	m_layer = LAYER::UIIndicator;
	enemyPosIndex = 0;
}

MonsterIndicator::~MonsterIndicator()
{

}

HRESULT MonsterIndicator::Init()
{
	targetEnemyPosVec.push_back(Vector2(1160, 700));
	targetEnemyPosVec.push_back(Vector2(1360, 700));
	targetEnemyPosVec.push_back(Vector2(1560, 700));
	targetEnemyPosVec.push_back(Vector2(1760, 700));

	AddSpriteRenderer(IMAGE::panel_monster_Black);
	m_transform->m_pivot = Vector2(0.5, 0);
	m_transform->m_pos = targetEnemyPosVec[0];

    return S_OK;
}

void MonsterIndicator::Update(float deltaTime, float worldTime)
{
	float x = abs(m_transform->m_pos.x - targetEnemyPosVec[enemyPosIndex].x);
	if (x > 60)
	{
		m_transform->m_pos += (targetEnemyPosVec[enemyPosIndex] - m_transform->m_pos).Normalize() * 10;
	}
	else if (x > 20) {
		m_transform->m_pos += (targetEnemyPosVec[enemyPosIndex] - m_transform->m_pos).Normalize() * 3;
	}
	else if (x > 1) {
		m_transform->m_pos += (targetEnemyPosVec[enemyPosIndex] - m_transform->m_pos).Normalize() * 1;
	}
}

void MonsterIndicator::LateUpdate()
{
}

void MonsterIndicator::BackRender(HDC _hdc)
{
}

void MonsterIndicator::Render(HDC _hdc)
{
}

void MonsterIndicator::FrontRender(HDC _hdc)
{
	m_spriteRenderer->RenderUI(_hdc);
}

void MonsterIndicator::Release()
{
}

void MonsterIndicator::Enable()
{
	m_transform->m_pos = targetEnemyPosVec[enemyPosIndex];
	isActive = true;
}

void MonsterIndicator::Disable()
{
	isActive = false;
}

void MonsterIndicator::SetPosIndex(int _index)
{
	enemyPosIndex = _index;
}

void MonsterIndicator::MonsterIsTargetSkill(bool isTarget)
{
	if (isTarget)
	{
		m_spriteRenderer->SetImage(IMAGE::panel_monster_Red);
	}
	else {
		m_spriteRenderer->SetImage(IMAGE::panel_monster_Black);
	}
}