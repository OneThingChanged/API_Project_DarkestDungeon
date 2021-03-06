#pragma once
#include "GameObject.h"

class DummySlot : public GameObject
{
private:
	Vector2Int originSlotID;
	CInfo_Item* itemInfo;
	bool hasItem;

	HeroListBtType btType;

public:
	DummySlot();
	~DummySlot();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	void SetDummySlot(Vector2Int originslotID, CInfo_Item* item);
	virtual void Disable();

};