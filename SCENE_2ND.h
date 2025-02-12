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

	//　playerPosXの宣言
	float  playerPosX = 300.0f;
	//　playerPosYの宣言
	float  playerPosY = 300.0f;
	//　自機の半径の宣言
	float playerRadius = 40.0f;
	//　自機の速度の宣言
	float playerSpeed = 10.0f;

	//　弾のposXの宣言
	float bulletPosX = 0.0f;
	//　弾のposYの宣言
	float bulletPosY = 0.0f;
	//　弾の半径の宣言
	float bulletRadius = 4.0f;
	//　弾速の宣言
	float bulletSpeed = 20.0f;

	// 敵のposXの宣言
	float enemyPosX = 30.0f;
	// 敵のposYの宣言
	float enemyPosY = 20.0f;
	// 敵の半径の宣言
	float enemyRadius = 20.0f;
	// 敵の速度の宣言
	float enemySpeed = 5.0f;

	// 敵と弾の距離
	float e2bX = 0.0f;
	float e2bY = 0.0f;
	float e2bR = bulletRadius + enemyRadius;

	// 距離の宣言
	float distance = 0.0f;

	// 弾の出現フラグの宣言
	int isBulletShot = false;
	//　敵の生存フラグの宣言
	int isEnemyAlive = true;
};

