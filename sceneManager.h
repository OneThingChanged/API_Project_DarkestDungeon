#pragma once
#include"singleton.h"
//#include "Scene.h"

class Scene;
class SceneManager : public Singleton<SceneManager>
{
private:
	typedef map<string, Scene*> sceneList;
	typedef map<string, Scene*>::iterator isceneList;

	static Scene* _currentScene;
	sceneList m_sceneList;

	class Astar* m_astar;
	class TestScene* m_testScene;

public:
	SceneManager();
	~SceneManager();

	HRESULT init();
	void release();
	void update();
	void Render(HDC _hdc);

	Scene* addScene(string sceneName, Scene* scene);
	HRESULT changeScene(string sceneName);
};