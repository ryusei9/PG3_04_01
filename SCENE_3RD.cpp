#include "SCENE_3RD.h"
#include <Novice.h>
void SCENE_3RD::Initialize()
{
}

void SCENE_3RD::Update()
{
	/// 更新処理
	if (inputManager_->GetInstance()->TriggerKey(DIK_SPACE)) {
		// スペースキーを押したら、次のシーンに切り替える
		sceneNo = SCENE_1;
	}
}

void SCENE_3RD::Draw()
{
	/// 描画処理
	Novice::DrawBox(0, 0,1280, 720,0.0f,0xaef5b6,kFillModeSolid);
}
