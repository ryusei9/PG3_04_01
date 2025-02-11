#pragma once
#include "IScene.h"
#include "inputManager.h"
class SCENE_1ST : public IScene
{
public:
	void Initialize()override;

	void Update()override;

	void Draw()override;

private:
	inputManager* inputManager_;
	
};

