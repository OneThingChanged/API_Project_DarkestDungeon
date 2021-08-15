#pragma once
#include "Unit.h"
#include "Info_Enemy.h"
class CEnemy : public Unit
{
private:

	//스킬
	//스킬 Info에 accuracy, critical, DMG, changeAttribute 가 포함됨
	Info_Enemy* info;

	bool isTargetSkill;
	ImageData targetSkillMem; //appear when some member using healSkill

public:
	CEnemy();
	~CEnemy();

	HRESULT Init();

	HRESULT Init(string img, int resist[],
		int HP, int SPD, int POS,
		int DEF, int DODGE);

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	virtual void SetMemberOverlay();
};