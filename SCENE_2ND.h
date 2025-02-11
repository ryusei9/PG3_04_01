#pragma once
#include "IScene.h"
#include <Vector2.h>
#include "inputManager.h"
class SCENE_2ND : public IScene
{
	void Initialize()override;

	void Update()override;

	void Draw()override;

private:

	// 背景座標の宣言
	Vector2 bgPos = { 0,0 };

	// 背景画像の読み込み
	int bgGH;

	inputManager* inputManager_;
};

