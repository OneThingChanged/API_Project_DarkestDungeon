#include "framework.h"
#include "CObjectManager.h"
#include "GameObject.h"

CObjectManager::CObjectManager() {}
CObjectManager::~CObjectManager() {}

HRESULT CObjectManager::Init()
{

	renderOrder.push_back(LAYER::BackGround);
	renderOrder.push_back(LAYER::Enemy);
	renderOrder.push_back(LAYER::Player);
	renderOrder.push_back(LAYER::UI);


	for (size_t i = 0; i < renderOrder.size(); i++)
	{
		objectRender.insert(make_pair(renderOrder[i], vector<GameObject*>()));
	}
	return S_OK;
}

void CObjectManager::Update(float deltaTime, float worldTime)
{
	for (auto g : objectVec)
	{
		g->Update(deltaTime, worldTime);
	}
}

void CObjectManager::LateUpdate()
{
	for (auto g : objectVec)
	{
		g->LateUpdate();
	}

	for (size_t i = 0; i < objsToErase.size(); i++)
	{
		int eraseID = objsToErase[i];
		for (size_t j = 0; j < objectVec.size(); ++j)
		{
			if (objectVec[j]->GetId() == eraseID) {
				//colliderGroup���� �ش簴ü�� ����
				LAYER layer = objectVec[j]->m_layer;
				int size = objectRender[layer].size();
				for (size_t k = 0; k < size; k++)
				{
					if (objectRender[layer][k]->GetId() == eraseID)
					{
						objectRender[layer].erase(objectRender[layer].begin() + k);
						break;
					}
					
				}
				

				objectVec[j]->Release();
				delete 	objectVec[j];
				objectVec.erase(objectVec.begin() + j);

			
				break;
			}
		}


	}

	for (auto g : objsToRegister)
	{
		objectVec.push_back(g);
	}
}

void CObjectManager::BackRender(HDC _hdc)
{

	for (LAYER layer : renderOrder)
	{
		for (GameObject* go : objectRender[layer])
		{
			go->BackRender(_hdc);
		}
	}
}

void CObjectManager::Render(HDC _hdc)
{
	for (LAYER layer : renderOrder)
	{
		for (GameObject* go : objectRender[layer])
		{
			go->Render(_hdc);
		}
	}
}

void CObjectManager::FrontRender(HDC _hdc)
{
	for (LAYER layer : renderOrder)
	{
		for (GameObject* go : objectRender[layer])
		{
			go->FrontRender(_hdc);
		}
	}
}

void CObjectManager::Release()
{
	for (auto g : objectVec)
	{
		g->Release();
	}
}

void CObjectManager::RegisterObj(string name, GameObject* gameObj)
{
	gameObj->SetId(_instance_id++);
	gameObj->SetName(name);
	objectVec.push_back(gameObj);
	objectRender[gameObj->m_layer].push_back(gameObj);
}

void CObjectManager::RemoveObj(int id)
{
	objsToErase.push_back(id);
}