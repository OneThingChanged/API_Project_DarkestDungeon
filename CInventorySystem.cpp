#include "framework.h"
#include "CInventorySystem.h"
#include "CParty.h"
#include "CButton.h"
#include "CHero.h"
#include "CCollider.h"
#include "CSlotItemButton.h"
#include "CTransform.h"
#include "Info_Item.h"
#include "DummySlot.h"


CInventorySystem::CInventorySystem() {}
CInventorySystem::~CInventorySystem() {}

HRESULT CInventorySystem::Init()
{
	m_layer = LAYER::UI;

	setInvenSlot();

	nowMouseOnSlot = 0;
	dummySlot = new DummySlot();
	dummySlot->Init();
	dummySlot->Disable();
	MG_GMOBJ->RegisterObj("dummySlot", dummySlot);
	return S_OK;
}

void CInventorySystem::Update(float deltaTime, float worldTime)
{
	if (MG_INPUT->isOnceKeyDown('Z'))
	{
		int count = 1;
		AddItem(ITEM::Torch, count);
		MG_GAME->GetParty()->setTorch(MG_GAME->GetParty()->getTorch() + 1);
	}
	if (MG_INPUT->isOnceKeyDown('X'))
	{
		int count = 1;
		AddItem(ITEM::Food, count);
		MG_GAME->GetParty()->setFood(MG_GAME->GetParty()->getFood() + 1);
	}
	if (MG_INPUT->isOnceKeyDown('C'))
	{
		int count = 1;
		AddItem(ITEM::Bandage, count);
		MG_GAME->GetParty()->setBandage(MG_GAME->GetParty()->getBandage() + 1);
	}

	if (MG_INPUT->isOnceKeyDown('Y'))
	{
		int count = 1;
		decreaseItem(ITEM::Bandage, count);
		MG_GAME->GetParty()->setBandage(MG_GAME->GetParty()->getBandage() - 1);
	}


	if (MG_INPUT->IsStayLMB())
	{
		if (dummySlot->isActive)
		{
			dummySlot->m_transform->m_pos = g_ptMouse;
		}
	}

	setPartyInvenInfo();

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
	MG_GMOBJ->RemoveObj(dummySlot);
	dragSlot = nullptr;
	for (size_t i = 0; i < m_invenSlots.size(); i++)
	{
		MG_GMOBJ->RemoveObj(m_invenSlots[i]);
	}
}

void CInventorySystem::Enable()
{
	for (size_t i = 0; i < m_invenSlots.size(); i++)
	{
		m_invenSlots[i]->Enable();
	}
	GameObject::Enable();
}

void CInventorySystem::Disable()
{
	for (size_t i = 0; i < m_invenSlots.size(); i++)
	{
		m_invenSlots[i]->Disable();
	}
	GameObject::Disable();
}


//==================================


void CInventorySystem::setInvenSlot()
{
	//fill emptySlot expert already filled
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			CSlotItemButton* temp = new CSlotItemButton();
			m_invenSlots.push_back(temp);
			temp->Init();
			temp->m_transform->m_pos = (i * 8 + j, Vector2(982 + 70 * j, 725 + 140 * i));
			temp->slotID = Vector2Int(j, i);
			temp->m_invenSys = this;
			MG_GMOBJ->RegisterObj("Slot", temp);
		}
	}
	setConsumableSlot();
}

void CInventorySystem::setConsumableSlot()
{
	auto torch = DB_ITEM->CallItem(ITEM::Torch);
	torch->m_count = 2;
	MG_GAME->GetParty()->setTorch(torch->m_count);
	m_invenSlots[0]->AddItem(torch);

	auto food = DB_ITEM->CallItem(ITEM::Food);
	food->m_count = 2;
	MG_GAME->GetParty()->setFood(food->m_count);
	m_invenSlots[1]->AddItem(food);

	auto bandage = DB_ITEM->CallItem(ITEM::Bandage);
	bandage->m_count = 2;
	MG_GAME->GetParty()->setBandage(bandage->m_count);
	m_invenSlots[2]->AddItem(bandage);
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
		if (m_invenSlots[i]->m_collider->UICheckColliderBoxWithPoint(g_ptMouse))
		{
			sprintf_s(str, "nowMouseOnSlot : %d", i);
			TextOut(_hdc, 0, 300, str, strlen(str));
			if (m_invenSlots[i]->m_itemInfo !=nullptr)
			{
				sprintf_s(str, "SlotKind : %d", m_invenSlots[i]->m_itemInfo->m_item);
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
		if (m_invenSlots[i]->m_itemInfo == nullptr)
		{
			continue;
		}
		else 
		{
			if (m_invenSlots[i]->m_itemInfo->m_item == itemInfo
				&& m_invenSlots[i]->m_itemInfo->isStockable
				&& !m_invenSlots[i]->m_itemInfo->IsFull())
			{
				if (m_invenSlots[i]->m_itemInfo->maxCount > curCount + m_invenSlots[i]->m_itemInfo->m_count)
				{
					m_invenSlots[i]->m_itemInfo->m_count += curCount;
					return true;
				}
				else 
				{
					curCount -= m_invenSlots[i]->m_itemInfo->maxCount - m_invenSlots[i]->m_itemInfo->m_count;
					m_invenSlots[i]->m_itemInfo->m_count = m_invenSlots[i]->m_itemInfo->maxCount;
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
		if (m_invenSlots[i]->m_itemInfo == nullptr)
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
	for (int i = 0; i < m_invenSlots.size(); i++)
	{
		if (m_invenSlots[i]->slotID == pos)
		{
			m_invenSlots[i]->RemoveItem();
		}
	}
}

void CInventorySystem::StartDragItem(CSlotItemButton* slot)
{
	originPos = slot->slotID;
	dragSlot = slot;
	dummySlot->Enable();
	dummySlot->SetDummySlot(originPos, slot->m_itemInfo);
	isDragging = true;
}

void CInventorySystem::EndDragItem(CSlotItemButton* _slot)
{
	if (dragSlot != _slot)
	{
		dragSlot->SwapItem(_slot);
	}
	isDragging = false;
	dragSlot = nullptr;
	dummySlot->Disable();
}

bool CInventorySystem::decreaseItem(ITEM itemInfo, int& count)
{
	int curCount = count;
	int TotalCount = 0;

	for (int i = 0; i < m_invenSlots.size(); i++)
	{
		if (m_invenSlots[i]->m_itemInfo == nullptr)
		{
			continue;
		}
		else 
		{
			if (m_invenSlots[i]->m_itemInfo->m_item == itemInfo)
			{
				TotalCount += m_invenSlots[i]->m_itemInfo->m_count;
			}
		}
	}

	if (TotalCount >= curCount)
	{
		for (int i = 0; i < m_invenSlots.size(); i++)
		{
			if (curCount == 0)
			{
				return true;
			}
		
			if (m_invenSlots[i]->m_itemInfo == nullptr)
			{
				continue;
			}

			if (m_invenSlots[i]->m_itemInfo->m_item == itemInfo)
			{
				if (m_invenSlots[i]->m_itemInfo->m_count >= curCount)
				{
					m_invenSlots[i]->m_itemInfo->m_count -= curCount;
					return true;
				}
				else
				{
					curCount -= m_invenSlots[i]->m_itemInfo->m_count;
					m_invenSlots[i]->m_itemInfo->m_count = 0;
				}
			}
		}
	}
	else
	{
		return false;
	}
}

void CInventorySystem::setPartyInvenInfo()
{
	int TotalTorch = 0;
	int TotalFood = 0;
	int TotalBandage = 0;

	for (int i = 0; i < m_invenSlots.size(); i++)
	{
		if (m_invenSlots[i]->m_itemInfo != nullptr)
		{
			if (m_invenSlots[i]->m_itemInfo->m_item == ITEM::Torch)
			{
				TotalTorch += m_invenSlots[i]->m_itemInfo->m_count;
			}
			else if (m_invenSlots[i]->m_itemInfo->m_item == ITEM::Food)
			{
				TotalFood += m_invenSlots[i]->m_itemInfo->m_count;
			}
			else if (m_invenSlots[i]->m_itemInfo->m_item == ITEM::Bandage)
			{
				TotalBandage += m_invenSlots[i]->m_itemInfo->m_count;
			}
		}
	}
	MG_GAME->GetParty()->setTorch(TotalTorch);
	MG_GAME->GetParty()->setFood(TotalFood);
	MG_GAME->GetParty()->setBandage(TotalBandage);
}