#include "GameManager.h"
#include <Novice.h>


GameManager::GameManager()
{
	sceneMax[TITLE] = std::make_unique<SCENE_1ST>();
	sceneMax[STAGE] = std::make_unique<SCENE_2ND>();
	sceneMax[CLEAR] = std::make_unique<SCENE_3RD>();

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
		currentScene = nowScene_->GetSceneNo();
		
		if (prevScene != currentScene)
		{
			sceneMax[currentScene]->Initialize();
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
		Novice::ScreenPrintf(10, 360,"Push SPACE to chenge scene");

		Novice::EndFrame();

		if (keys[DIK_ESCAPE] && preKeys[DIK_ESCAPE] == 0)
		{
			break;
		}
	}
	return 0;
}
