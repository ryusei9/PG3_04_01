#pragma once

enum SCENE {SCENE_1,SCENE_2,SCENE_3};
class IScene
{
protected:
	static int sceneNo;
public:
	virtual void Initialize() = 0;

	virtual void Update() = 0;

	virtual void Draw() = 0;

	virtual ~IScene();

	int GetSceneNo();
};

