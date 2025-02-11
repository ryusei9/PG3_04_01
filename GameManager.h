#pragma once
#include "memory"
#include "IScene.h"
#include "SCENE_1ST.h"
#include "SCENE_2ND.h"
#include "SCENE_3RD.h"
#include "inputManager.h"
#include "WinApp.h"
class GameManager
{
private:

	std::unique_ptr<IScene> sceneMax[3];
	int currentScene;

	int prevScene;

	inputManager* inputManager_;

	WinApp* winApp_ = WinApp::GetInstance();
public:
	GameManager();
	~GameManager();
	
	int Run();

	
};

