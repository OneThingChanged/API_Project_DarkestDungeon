#pragma once
#include "CDragButtion.h"

class CBTN_Skill :public CDragButton
{
protected:
	class CInfo_Skill* skillInfo;
	class CSpriteRenderer* m_spriteSelected;
	class CSpriteRenderer* m_spriteDeactiveIcon;
	class CHero* hero;

public:
	bool selected;
	bool activateSkill;
	int index = -1;

	class DungeonScene* scene;
	class CBattleSystem* m_pBattleSystem;
	CBTN_Skill();
	~CBTN_Skill();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void SetSkill(SKILL skill);
	virtual void ActiveSkill(bool activate);
	virtual void Release();
};