#include "framework.h"
#include "CInventorySystem.h"
#include "CParty.h"
#include "CButton.h"
#include "CHero.h"
#include "CCollider.h"
#include "slot.h"
#include "CTransform.h"
#include "iteminfo.h"
#include "slot.h"

CInventorySystem::CInventorySystem() {}
CInventorySystem::~CInventorySystem() {}

HRESULT CInventorySystem::Init()
{
	m_layer = LAYER::UI;

	setInvenSlot();

	nowMouseOnSlot = 0;
	filledSlot = 0;
	dummySlot = new CButton_SlotItem();
	dummySlot->Init();
	dummySlot->Unable();
	MG_GMOBJ->RegisterObj("dummySlot", dummySlot);
	return S_OK;
}

void CInventorySystem::Update(float deltaTime, float worldTime)
{
	if (MG_INPUT->isOnceKeyDown('Z'))
	{
		int count = 1;
		AddItem(ITEM::Torch, count);
	}
	if (MG_INPUT->isOnceKeyDown('X'))
	{
		int count = 1;
		AddItem(ITEM::Food, count);
	}
	if (MG_INPUT->isOnceKeyDown('C'))
	{
		int count = 1;
		AddItem(ITEM::Bandage, count);
	}

	if (MG_INPUT->IsStayLMB())
	{
		if (dummySlot->isActive)
		{
			dummySlot->m_transform->m_pos = MG_INPUT->GetptMouse();
		}
	}

}

void CInventorySystem::LateUpdate()
{
}

void CInventorySystem::BackRender(HDC _hdc)
{
}

void CInventorySystem::Render(HDC _hdc)
{
}

void CInventorySystem::FrontRender(HDC _hdc)
{
	//showInvenItem(_hdc);
	//showSlotItemCount(_hdc);
	showSlotMouseOn(_hdc);
}

void CInventorySystem::Release()
{
}



void CInventorySystem::Enable()
{
	for (size_t i = 0; i < m_invenSlots.size(); i++)
	{
		m_invenSlots[i]->Enable();
	}
	GameObject::Enable();
}

void CInventorySystem::Unable()
{
	for (size_t i = 0; i < m_invenSlots.size(); i++)
	{
		m_invenSlots[i]->Unable();
	}
	GameObject::Unable();
}


//==================================


void CInventorySystem::setInvenSlot()
{
	//fill emptySlot expert already filled
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			CButton_SlotItem* temp = new CButton_SlotItem();
			m_invenSlots.push_back(temp);
			temp->Init();
			temp->m_transform->m_pos = (i * 8 + j, Vector2(982 + 70 * j, 725 + 120 * i));
			temp->slotID = Vector2Int(j,i);
			temp->m_invenSys = this;
			MG_GMOBJ->RegisterObj("Slot", temp);
		}
	}

	setConsumableSlot();
}

void CInventorySystem::setConsumableSlot()
{
	auto torch = DB_ITEM->CallItem(ITEM::Torch);
	torch->m_count = 7;
	m_invenSlots[0]->AddItem(torch);

	auto food = DB_ITEM->CallItem(ITEM::Food);
	food->m_count = 2;
	m_invenSlots[1]->AddItem(food);

	auto bandage = DB_ITEM->CallItem(ITEM::Bandage);
	bandage->m_count = 5;
	m_invenSlots[2]->AddItem(bandage);
}

void CInventorySystem::changeSlot()
{
}

void CInventorySystem::showSlotMouseOn(HDC _hdc)
{
	int k = 0;
	char str[256];
	string strFrame;
	SetBkMode(_hdc, RGB(0, 0, 0));
	SetTextColor(_hdc, RGB(255, 255, 255));

	for (int i = 0; i < m_invenSlots.size(); i++)
	{
		if (m_invenSlots[i]->m_collider->new_CheckColliderBoxWithPoint(m_ptMouse))
		{
			sprintf_s(str, "nowMouseOnSlot : %d", i);
			TextOut(_hdc, 0, 300, str, strlen(str));
			if (m_invenSlots[i]->itemInfo !=nullptr)
			{
				sprintf_s(str, "SlotKind : %d", m_invenSlots[i]->itemInfo->m_item);
				TextOut(_hdc, 0, 320, str, strlen(str));
			}
		}
	}
}

bool CInventorySystem::AddItem(ITEM itemInfo, int& count)
{
	int curCount = count;


	for (int i = 0; i < m_invenSlots.size(); i++)
	{
		if (m_invenSlots[i]->itemInfo == nullptr)
		{
			continue;
		}
		else {
			if (m_invenSlots[i]->itemInfo->m_item == itemInfo
				&& m_invenSlots[i]->itemInfo->isStockable
				&& !m_invenSlots[i]->itemInfo->IsFull())
			{
				if (m_invenSlots[i]->itemInfo->maxCount > curCount + m_invenSlots[i]->itemInfo->m_count)
				{
					m_invenSlots[i]->itemInfo->m_count += curCount;
					return true;
				}
				else {
					curCount -= m_invenSlots[i]->itemInfo->maxCount - m_invenSlots[i]->itemInfo->m_count;
					m_invenSlots[i]->itemInfo->m_count = m_invenSlots[i]->itemInfo->maxCount;
				}
			}
		}
	}
	if (curCount == 0)
	{
		return true;
	}
	for (int i = 0; i < m_invenSlots.size(); i++)
	{
		if (m_invenSlots[i]->itemInfo == nullptr)
		{
			auto item = DB_ITEM->CallItem(itemInfo);
			item->m_count = curCount;
			m_invenSlots[i]->AddItem(item);
			return true;
		}
	}
	return false;
}

void CInventorySystem::RemoveItem(Vector2Int pos)
{

}

void CInventorySystem::SwapItem(Vector2Int originPos, Vector2Int swapPos)
{

}
