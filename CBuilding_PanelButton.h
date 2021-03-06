#pragma once
#include"CEst_UI.h"

class CBuilding_PanelButton : public CEst_UI
{
public:
	int buttonID;

	class TownScene* scene;
	class CHeroList_button* listbutton;

	class CHero* hero;
	class CUIPanel_Abbey* abbey;
	class CButton* checkBTN;


	CBuilding_PanelButton();
	~CBuilding_PanelButton();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	void PressCheckButton();
	virtual void Disable();
};