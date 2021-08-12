#pragma once
#include "CDragButtion.h"

class CDragButtonMinimapBG : public CDragButton
{
	class CMapSystem* m_pMapSystem;
	Vector2 previousMousePoint;
	float moveOriginPosCoolTime;
	float moveOriginPosCurTime;

	bool isDraged;

public:
	CDragButtonMinimapBG();
	~CDragButtonMinimapBG();
	
	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	//===================================


	template <typename T>
	void SetTriggerWhenDrag(T* pObj, void(T::* func)())
	{
		canTriggerDrag = true;
		m_triggerWhenDrag = bind(func, pObj);
	}

	void SetMapSystem(class CMapSystem* _mapSystem);
};