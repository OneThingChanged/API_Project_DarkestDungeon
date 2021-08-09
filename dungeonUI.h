#pragma once
#include "CButton.h"

class CParty;
class dungeonUI : public GameObject
{
public:
	vector<ImageData> vUI;
	int m_sceneSize;
	bool showMap;

	CButton* bt_inven;
	CButton* bt_map;

	//==================================

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	//==================================

	void SetUIIMG();
	void SetButton();
	void SetTorchUI();

	void TorchLightBarDecrease();
	void ShowInven() { showMap = false; }
	void ShowMap() { showMap = true; }

	void ShowUI(HDC _hdc);

};