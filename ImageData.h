#pragma once
#include "CTransform.h"

struct ImageData
{
	Image* m_img;
	CTransform m_trans;

	void Render(HDC hdc) {
		m_img->render(hdc, &m_trans);
	}
};