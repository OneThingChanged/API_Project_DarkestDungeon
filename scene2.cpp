#include "framework.h"
#include "scene2.h"

scene2::scene2()
{
}

scene2::~scene2()
{
}

HRESULT scene2::init()
{


    MG_IMAGE->addImage("공유1", "images/공유.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
    return S_OK;
}

void scene2::release()
{
}

void scene2::update()
{
	if (MG_INPUT->isOnceKeyDown('1'))
	{
		//씬체인지
		//MG_SCENE->changeScene("scene1");
	}
}

void scene2::render()
{
    MG_IMAGE->render("공유1", getMemDC());
}
