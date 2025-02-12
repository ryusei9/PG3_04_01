#pragma once
#include "memory"
#include "IScene.h"
#include "SCENE_1ST.h"
#include "SCENE_2ND.h"
#include "SCENE_3RD.h"
#include "inputManager.h"
#include "WinApp.h"
#include "dinput.h"
class GameManager
{
private:

	std::unique_ptr<IScene> sceneMax[3];
	int currentScene;

	int prevScene;


	WinApp* winApp_ = WinApp::GetInstance();

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
public:
	GameManager();
	~GameManager();
	
	int Run();

	
};

