#include "GameManager.h"
#include <Novice.h>


GameManager::GameManager()
{
	sceneMax[SCENE_1] = std::make_unique<SCENE_1ST>();
	sceneMax[SCENE_2] = std::make_unique<SCENE_2ND>();
	sceneMax[SCENE_3] = std::make_unique<SCENE_3RD>();

}

GameManager::~GameManager()
{
}

int GameManager::Run()
{
	while (Novice::ProcessMessage() == false)
	{
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		prevScene = currentScene;
		
		if (prevScene != currentScene)
		{
			sceneMax[currentScene]->Initialize();
		}
		if (keys[DIK_1] && preKeys[DIK_1] == 0)
		{
			currentScene = SCENE_1;
		} else if (keys[DIK_2] && preKeys[DIK_2] == 0)
		{
			currentScene = SCENE_2;
		} else if (keys[DIK_3] && preKeys[DIK_3] == 0)
		{
			currentScene = SCENE_3;
		}

		sceneMax[currentScene]->Update();

		sceneMax[currentScene]->Draw();

		// 画面に表示
		Novice::ScreenPrintf(
			// X.Y座標
			10, 340,
			// 表示する文字
			"sceneNo = %d",
			// 参照する変数
			currentScene);

		// 画面に表示
		Novice::ScreenPrintf(10, 360,"Push 1,2,3 to chenge scene");

		Novice::EndFrame();

		if (keys[DIK_ESCAPE] && preKeys[DIK_ESCAPE] == 0)
		{
			break;
		}
	}
	return 0;
}
