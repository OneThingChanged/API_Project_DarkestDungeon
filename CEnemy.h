#pragma once
#include "Unit.h"


class CEnemy : public Unit
{
protected:
	RACE m_race;
<<<<<<< Updated upstream
	int HP;
	int DODGE;
	int DEF;
	int SPD;

	int pos; //(��Ƽ������ ��ġ)
	
	//����
	int resist[5]; //stun, blight, bleed, debuff, move

	//����
	int attribute[8]; //stun, blight, bleed, debuff, buff, move, marked, death

	//��ų
	//��ų Info�� accuracy, critical, DMG, changeAttribute �� ���Ե�
	int Skill[4]; //1, 2, 3, 4
	
=======
	int m_Hp;
	int m_Dodge;
	int m_DMG; //��ų���� ���� �����Ͽ� ���
	int m_DEF;
	int m_SPD;

	int resist[5]; //Stun, Blight, Move, Bleed, Debuff
	int attribute[6]; //Stun, Blight, Move, Bleed, Debuff, Buff, marked

>>>>>>> Stashed changes

public:
	CEnemy();
	~CEnemy();

	HRESULT Init();

	virtual void Update(float deltaTime, float worldTime);
	virtual void LateUpdate();

	virtual void BackRender(HDC _hdc);
	virtual void Render(HDC _hdc);
	virtual void FrontRender(HDC _hdc);

	virtual void Release();
};