#pragma once
#include"singleton.h"
#include<bitset>
#include "Vector2.h"

using namespace std;
#define KEYMAX 256

class CInputManager : public Singleton<CInputManager>
{
private:
	bitset<KEYMAX> _keyUp;
	bitset<KEYMAX> _keyDown;
	bitset<KEYMAX> _keyClick;

	bitset<KEYMAX> _keyDownFrame;
	bitset<KEYMAX> _keyUpFrame;

	float clickCoolTime;
	float clickCurTime;

	int curClickKeyCode;

	//vector<tKeyState>	m_vecKey;

	bool isDownLMB;
	bool wasDownLMB;


	bool isDownRMB;
	bool wasDownRMB;

	Vector2 m_OldptMouse;
	Vector2 m_Mouse;
	Vector2 m_ptDeltaMouse;

public:
	CInputManager();
	~CInputManager();

	HRESULT init();

	void release();


	void Update(float deltaTime, float worldTime);
	
	//�ѹ��� ������
	bool isOnceKeyDown(int key);
	//�����ٰ� �³�
	bool isOnceKeyUp(int key);
	//������ �ֳ�
	bool isStayKeyDown(int key);
	//���Ű��
	bool isToggleKey(int key);

	//�ѹ��� ������
	bool isOnceKeyClick(int key);


	bool IsDownLMB() { return isDownLMB && !wasDownLMB; }
	bool IsStayLMB() { return isDownLMB && wasDownLMB; }
	bool IsUpLMB() { return !isDownLMB && wasDownLMB; }

	bool IsDownRMB() { return isDownRMB && !wasDownRMB; }
	bool IsStayRMB() { return isDownRMB && wasDownRMB; }
	bool IsUpRMB() { return !isDownRMB && wasDownRMB; }



	Vector2 GetptDeltaMouse() { return m_ptDeltaMouse; }
	Vector2 GetptMouse() { return m_Mouse; }
};