#pragma once
#include "CEst_UI.h"
class CUIPanel_Tavern : public CEst_UI
{
	
private:
	class CHeroList_button* m_HeroList_button;
	class CBuilding_PanelButton* m_room1;
	class CBuilding_PanelButton* m_room2;
	class CBuilding_PanelButton* m_room3;
	class CBuilding_PanelButton* m_room4;
	class CBuilding_PanelButton* m_room5;
	class CBuilding_PanelButton* m_room6;
	class CBuilding_PanelButton* m_room7;
	class CBuilding_PanelButton* m_room8;
	class CBuilding_PanelButton* m_room9;

public:

	class CButton* m_check;
	class CBuilding_PanelButton* panelbutton;
	vector<class CBuilding_PanelButton*> panelVec;

	CUIPanel_Tavern();
	~CUIPanel_Tavern();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	void CreateRooms();
	void Creatchecks();

	virtual void Enable();
	virtual void Unable();
};

