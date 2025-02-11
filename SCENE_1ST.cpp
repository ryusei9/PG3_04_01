#include "SCENE_1ST.h"
#include <Novice.h>

void SCENE_1ST::Initialize()
{
	
}

void SCENE_1ST::Update()
{
	/// 更新処理
	if (inputManager_->GetInstance()->TriggerKey(DIK_SPACE)) {
		// スペースキーを押したら、次のシーンに切り替える
		sceneNo = SCENE_2;
	}

	
}

void SCENE_1ST::Draw()
{
	/// 描画処理
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xffccff, kFillModeSolid);
}
