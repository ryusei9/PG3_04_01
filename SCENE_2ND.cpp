#include "SCENE_2ND.h"
#include <Novice.h>

void SCENE_2ND::Initialize()
{
	bgGH = Novice::LoadTexture("./bg.png");

}

void SCENE_2ND::Update()
{
	/// 更新処理
	//if (inputManager_->GetInstance()->TriggerKey(DIK_SPACE)) {
	//	// スペースキーを押したら、次のシーンに切り替える
	//	sceneNo = SCENE_3;
	//}
	// 背景のY座標を下に動かす
	bgPos.y++;
	// 背景のY座標が一番下に到達したら
	if (bgPos.y >= 720) {
		// 0に戻す
		bgPos.y = 0;
	}

	
}

void SCENE_2ND::Draw()
{
	/// 描画処理
	Novice::DrawSprite(static_cast<int>(bgPos.x), static_cast<int>(bgPos.y), bgGH, 1, 1, 0.0f, 0xFFFFFFFF);

	Novice::DrawSprite(static_cast<int>(bgPos.x), static_cast<int>(bgPos.y - 720), bgGH, 1, 1, 0.0f, 0xFFFFFFFF);

}
