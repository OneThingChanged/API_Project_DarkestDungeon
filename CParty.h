#pragma once
#include "GameObject.h"

class CHero;
class Vestal;
class CParty : public GameObject
{
private:
	vector<CHero*> m_member;
	//vector<CHero*>::iterator m_imember;

	bool memberCount0;
	int maxPartyMember;

	//�Ҹ� �������� ����
	int m_Item_food;
	int m_Item_bandage;
	int m_Item_Torch;

	//ȶ���� ���
	int m_brightness;

	//walkFont 
	int WF_btwHeroes = 150;
	//wlakBack
	int WB_btwHeroes = 100;

public:
	CParty();
	~CParty();

	HRESULT Init();
	HRESULT Init(int food, int bandage, int torch);

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();

	//==================================

	void SetParty(vector<CHero*> member);
	void SetHero(CHero* member);
	void SetCamera();
	CHero* GetHero(int index);

	void SetFormation();
	void getFormation(string name);

	void FormationMove();

	//�������� ���� get/set
	void setTorch(int torch);
	int getTorch() { return m_Item_bandage; }
	void setFood(int food);
	int getFood() { return m_Item_food; }
	void setBandage(int bandage);
	int getBandage() { return m_Item_bandage; }

	void setBrightness(int brightness);
	int getBrightness() { return m_brightness; }

	void decreaseBright_movement();

	void showMemberInfo(HDC _hdc);
	void showItem(HDC _hdc);
	void showDis(HDC _hdc);
};