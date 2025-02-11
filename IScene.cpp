#include "IScene.h"

int IScene::sceneNo = SCENE_1;

IScene::~IScene(){}

int IScene::GetSceneNo() {return sceneNo;}
