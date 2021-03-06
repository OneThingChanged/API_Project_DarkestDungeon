#pragma once
#include"CEst_UI.h"

class CHeroList_ui : public GameObject
{
private:
	vector<ImageData> most_HeroList_UI;

public:
	CHeroList_ui();
	~CHeroList_ui();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

};