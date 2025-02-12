#include "SCENE_2ND.h"
#include <Novice.h>
#include <Math.h>
void SCENE_2ND::Initialize()
{
	bgGH = Novice::LoadTexture("./bg.png");
	playerPosX = 300.0f;

	 playerPosY = 300.0f;

	playerRadius = 40.0f;
	
	playerSpeed = 10.0f;

	
	bulletPosX = 0.0f;
	
	bulletPosY = 0.0f;
	bulletRadius = 4.0f;
	bulletSpeed = 20.0f;

	
	enemyPosX = 30.0f;
	
	enemyPosY = 20.0f;
	
	enemyRadius = 20.0f;
	
	enemySpeed = 5.0f;

	
	e2bX = 0.0f;
	e2bY = 0.0f;
	e2bR = bulletRadius + enemyRadius;

	distance = 0.0f;

	isBulletShot = false;
	isEnemyAlive = true;
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

	// Dキーを押している間
	if (Novice::CheckHitKey(DIK_D)) {
		// 自機が右に進む
		playerPosX = playerPosX + playerSpeed;
	}

	// Aキーを押している間
	if (Novice::CheckHitKey(DIK_A)) {
		// 自機が左に進む
		playerPosX = playerPosX - playerSpeed;
	}

	// Wキーを押している間
	if (Novice::CheckHitKey(DIK_W)) {
		// 自機が上に進む
		playerPosY = playerPosY - playerSpeed;
	}

	// Sキーを押している間
	if (Novice::CheckHitKey(DIK_S)) {
		// 自機が下に進む
		playerPosY = playerPosY + playerSpeed;
	}

	/* ===========================================
	 * 自機の処理
	* ======================================== */

	// 自機の画面端の設定
	// 自機が右端に到達したとき
	if (playerPosX > 1280 - playerRadius) {
		// 右端から自機の半径を引いた場所で止まる
		playerPosX = 1280 - playerRadius;
	}

	// 自機が左端に到達したとき
	if (playerPosX < 0) {
		// 左端から自機の半径を引いた場所で止まる
		playerPosX = 0;
	}

	// 自機が下端に到達したとき
	if (playerPosY > 720 - playerRadius) {
		// 下端から自機の半径を引いた場所で止まる
		playerPosY = 720 - playerRadius;
	}

	// 自機が上端に到達したとき
	if (playerPosY < 0) {
		// 上端から自機の半径を引いた場所で止まる
		playerPosY = 0;
	}

	/* ===========================================
	* 弾の処理
	* ======================================== */

	// スペースキーを押すと弾が自機の座標から出現する
	// 弾を撃ったフラグがfalseのとき
	if (!isBulletShot) {
		// スペースを押したとき
		if (Novice::CheckHitKey(DIK_SPACE)) {
			// 弾のフラグをtrueにする
			isBulletShot = true;
			// 弾が出る場所を自機の中心にする
			bulletPosX = playerPosX + playerRadius / 2;
			// 自機から出る弾の高さを自機の高さにする
			bulletPosY = playerPosY;
		}
	}

	// 弾道計算
	// 弾が発射されたとき
	if (isBulletShot) {
		// 上に向かって進む
		bulletPosY -= bulletSpeed;
		// 弾が画面から出たとき
		if (bulletPosY <= 0) {
			// 弾の座標を移動して
			bulletPosY = -200;
			// 弾のフラグをfalseにする
			isBulletShot = false;
		}
	}

	/* ===========================================
	* 敵の処理
	 * ======================================== */

	 // 敵が生きているときの処理
	if (isEnemyAlive) {
		// 敵が右に動く
		enemyPosX = enemyPosX + enemySpeed;

		// 敵が右端に到達したとき、左に動かす処理
		if (enemyPosX > 1280 - enemyRadius || enemyPosX < 0 + enemyRadius) {
			enemySpeed = -enemySpeed;
		}

		// 当たり判定
		// 弾が撃たれているとき
		if (isBulletShot) {
			// 弾と敵の距離の計算
			e2bX = bulletPosX - enemyPosX;
			e2bY = bulletPosY - enemyPosY;
			// 三平方の定理をつかって中心点間の距離を求める
			distance = sqrtf(e2bX * e2bX + e2bY * e2bY);

			// 弾と敵の半径の和よりも中心点間の距離のほうが短いなら
			if (distance <= e2bR) {
				// 敵の生存フラグをfalseにする
				isEnemyAlive = false;
			}
		}

	}

	// 敵のフラグ管理
	// 敵がやられたとき
	if (!isEnemyAlive) {
		sceneNo = CLEAR;
	}
}

void SCENE_2ND::Draw()
{
	/// 描画処理
	Novice::DrawSprite(static_cast<int>(bgPos.x), static_cast<int>(bgPos.y), bgGH, 1, 1, 0.0f, 0xFFFFFFFF);

	Novice::DrawSprite(static_cast<int>(bgPos.x), static_cast<int>(bgPos.y - 720), bgGH, 1, 1, 0.0f, 0xFFFFFFFF);

	/* ===========================================
		* 自機の表示
		* ======================================== */

		// 自機の描画
	Novice::DrawBox(
		// X座標
		static_cast<int>(playerPosX),
		// Y座標
		static_cast<int>(playerPosY),
		// 半径
		static_cast<int>(playerRadius),
		static_cast<int>(playerRadius),
		// 回転半径
		0.0f,
		// 色
		WHITE,
		// 塗りつぶし
		kFillModeSolid);

	/* ===========================================
	* 弾の表示
	* ======================================== */

	// 弾が発射されたとき、弾を画面に表示する
	if (isBulletShot) {
		Novice::DrawTriangle(
			// 頂点1
			static_cast<int>(bulletPosX),
			static_cast<int>(bulletPosY) - static_cast<int>(bulletRadius),
			// 頂点2
			static_cast<int>(bulletPosX) - static_cast<int>(bulletRadius),
			static_cast<int>(bulletPosY) + static_cast<int>(bulletRadius),
			// 頂点3
			static_cast<int>(bulletPosX) + static_cast<int>(bulletRadius),
			static_cast<int>(bulletPosY) + static_cast<int>(bulletRadius),
			// 色
			WHITE,
			// 塗りつぶし
			kFillModeSolid);
	}

	/* ===========================================
	* 敵の表示
	* ======================================== */

	// 敵が生きているとき
	if (isEnemyAlive) {
		// 丸の表示
		Novice::DrawEllipse(
			// 座標
			static_cast<int>(enemyPosX),
			static_cast<int>(enemyPosY),
			// 半径
			static_cast<int>(enemyRadius),
			static_cast<int>(enemyRadius),
			// 回転半径
			0.0f,
			// 色
			WHITE,
			// 塗りつぶし
			kFillModeSolid);
	}

	
	/* ===========================================
	* 数値の表示
	* ======================================== */

	// 操作方法の表示
	Novice::ScreenPrintf(
		// 表示する座標
		10, 15,
		// 画面に表示
		"W:Up A:Left S:Down D:Right"
	);

	// 座標の表示
	Novice::ScreenPrintf(
		// 表示する座標
		10, 40,
		// 自機の座標を画面に表示
		"playerPosX: %d / playerPosY: %d",
		static_cast<int>(playerPosX), static_cast<int>(playerPosY)
	);

	Novice::ScreenPrintf(
		// 表示する座標
		10, 60,
		// 弾の座標と弾の発射フラグを画面に表示
		"bulletPosX: %d / bulletPosY: %d / isBulletShot: %d",
		static_cast<int>(bulletPosX), static_cast<int>(bulletPosY), static_cast<int>(isBulletShot)
	);

	Novice::ScreenPrintf(
		// 表示する座標
		10, 80,
		// 敵の座標と敵の生存フラグを画面に表示
		"enemyPosX: %d / enemyPosY: %d / isEnemyAlive: %d",
		static_cast<int>(enemyPosX), static_cast<int>(enemyPosY), static_cast<int>(isEnemyAlive)
	);

	Novice::ScreenPrintf(
		// 表示する座標
		10, 120,
		// 敵と弾の距離と半径を画面に表示
		"e2bX^2: %d / e2bY^2: %d / e2bR^2: %d",
		static_cast<int>(e2bX * e2bX), static_cast<int>(e2bY * e2bY), static_cast<int>(e2bR * e2bR)
	);
	
}
