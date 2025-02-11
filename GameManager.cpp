#include "GameManager.h"
#include <Novice.h>


GameManager::GameManager()
{
	sceneMax[SCENE_1] = std::make_unique<SCENE_1ST>();
	sceneMax[SCENE_2] = std::make_unique<SCENE_2ND>();
	sceneMax[SCENE_3] = std::make_unique<SCENE_3RD>();

	inputManager_->GetInstance()->Initialize(winApp_->GetInstance());
}

GameManager::~GameManager()
{
}

int GameManager::Run()
{
	while (Novice::ProcessMessage() == false)
	{
		Novice::BeginFrame();


		prevScene = currentScene;
		currentScene = sceneMax[currentScene]->GetSceneNo();

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
		Novice::ScreenPrintf(
			// X.Y座標
			10, 360,
			// 表示する文字
			"Push Space to chenge scene"
		);

		Novice::EndFrame();

		if (inputManager_->GetInstance()->TriggerKey(DIK_ESCAPE))
		{
			break;
		}
	}
	return 0;
}
