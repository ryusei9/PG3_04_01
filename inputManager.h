#pragma once
#include <windows.h>
#include <wrl.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include "WinApp.h"

class inputManager
{
	// namespace省略
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
public:
	// シングルトンインスタンスを取得
	static inputManager* GetInstance();

	// メンバ変数
	// 初期化
	void Initialize(WinApp* winApp);
	// 更新
	void Update();

	/// <summary>
	/// キーの押下をチェック
	/// </summary>
	/// 押されているか
	bool PushKey(BYTE keyNumber);

	/// <summary>
	/// キーのトリガーをチェック
	/// </summary>
	bool TriggerKey(BYTE keyNumber);
private:
	inputManager() = default;
	~inputManager() = default;
	inputManager(const inputManager&) = delete;
	inputManager& operator=(const inputManager&) = delete;
	// メンバ変数
	// キーボードのデバイス
	ComPtr<IDirectInputDevice8> keyboard;
	// 全キーの状態
	BYTE key[256] = {};
	// 前回の全キーの状態
	BYTE keyPre[256] = {};
	// DirectInputのインスタンス
	ComPtr<IDirectInput8> directInput = nullptr;

	// WindowsAPI
	WinApp* winApp_ = nullptr;
};

