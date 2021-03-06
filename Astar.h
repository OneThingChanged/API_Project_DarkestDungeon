#pragma once
#include"gameNode.h"
/*
주어진 출발점에서 목표점까지 가는 최단 경로를 찾아내는 그래프 알고리즘 중 하나.
F=g+h
f = 비용(목적지까지 가는 총 비용 현재까지 이동하는 걸린 비용과 예상비용을 합침)
g = 사각형으로 부터 새로운 사각형까지의 이동비용
h = 사각형 으로부터 최종 목적지까지의 예상이동 비용
(대각선 이동이 아닌 가로세로 이동에 대한 비용으로 계산, 장애물에 대한 요소는 고려하지 않는다.)

동작원리 : 시작점에서 이동할수 있는 지점을 오픈리스트에 추가
위치를 다시 확인할 필요가 없는 지점을 클로즈 리스트에 추가
오픈 리스트에서 가장 비용이 적은 위치를 현재 위치로 지정
위 과정을 반복
F값이 동일하다면 속도상의 목적으로 오픈 리스트에 더 늦게 추가 된것을 선택하는 것이 빠르다.
*/

#define TILE_X 20	//가로타일
#define TILE_Y 20	//세로타일
#define WIDTH  35	//타일 가로길이
#define HEIGHT 35	//타일 세로길이
#define BIGNUM 5000 

//타일 속성
enum class TILE_TYPE
{
	TILE_TYPE_EMPTY,	//빈타일 (지나갈수 있는곳)
	TILE_TYPE_START,	//시작지점
	TILE_TYPE_END,		//끝지점
	TILE_TYPE_WALL		//벽
};
enum class ASTAR_STATE
{
	ASTAR_STATE_SEARCHING,//검색중
	ASTAR_STATE_FOUND,	//발견!
	ASTAR_STATE_NOWAY,	//길없음
	ASTAR_STATE_END

};
struct aStarTile
{
	RECT rc;
	COLORREF color;
	bool walkable;		//지나갈수 있냐	
	bool listOn;		//openList에 추가되었는지 여부
	int i, j;
	int F, G, H;
	char str[128];
	aStarTile* parent;	//부모 타일 주소
	TILE_TYPE type;		//타일속성
};

class Astar : public gameNode
{
private:
	
	aStarTile _tile[TILE_X][TILE_Y];
	vector<aStarTile*> _openList;
	vector<aStarTile*> _closeList;

	ASTAR_STATE _astarState;
	TILE_TYPE _selectType;
	COLORREF _selectedTypeColor;

	int _startX, _startY;
	int _endX, _endY;
	int _lastIndex;	//나중에 추가된 클로즈 리스트의 인덱스

	bool _startPointSet;
	bool _endPointSet;

	int Ci;
	int Cj;
	int Cg;


	RECT rc[6];
	HBRUSH newBrush, oldBrush;
	HFONT newFont, oldFont;


public:
	Astar();
	~Astar();

	 HRESULT init();
	 void release();
	 void update();
	 void render();

	 void tileComposition();//배치
	 void tileInitializing();//배치후 속성에 맞게 초기화
	 void addOpenList();	//오픈리스트 추가
	 void caculateH();		//오픈리스트내 타일 H값 계산
	 void caculateF();		//오픈리스트내 타일 F값 계산
	 void addCloseList();	//가장 작은 F선택후 클로즈 리스트에 추가
	 void checkArrive();	//도착했는지 여부 체크
	 void showWay(aStarTile* tile);//도착후 시작지점과 도착지점을 잇는 경로 보여주자
	 void typeColor(TILE_TYPE type);

};

