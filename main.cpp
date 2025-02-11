#include <Novice.h>
#include <GameManager.h>

const char kWindowTitle[] = "LE2B_13_サトウ_リュウセイ_PG3_04_01";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// シーンの宣言
	GameManager* gameManager;
	gameManager = new GameManager();
	
	gameManager->Run();

		

		

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}