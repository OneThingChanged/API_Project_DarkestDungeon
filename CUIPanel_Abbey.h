#pragma once
#include "CEst_UI.h"

class CUIPanel_Abbey :public CEst_UI
{
private:
	//class CHeroList_button* m_HeroList_button;

public:
	//class CButton* m_roomcheck;
	//class CButton* m_closedroom;
	//class CBuilding_PanelButton* panelbutton;

	vector<class CBuilding_PanelButton*> panelVec;
	//vector<class CButton*>checkVec;
	//vector<class CButton*>closedVec;
	//vector<class CHero*> stressVec;

	CUIPanel_Abbey();
	~CUIPanel_Abbey();
	
	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();
	void CreateRooms();

	virtual void Enable();
    virtual void Disable();

	void CheckStress(HDC _hdc);
	void ReduceStress();
	void SetcloseRoom();
};
