#pragma once

#include "cocos_framework.h"
#include "Hero.h"

class ServiceScene
{
	SpriteFrameCache* _cache;

	Sprite* _getReadyBack1;
	Sprite* _getReadyBack2;
	Sprite* _getReadyBack3;
	Sprite* _getReadyFont;

	Scene* _scene;

public:
	ServiceScene(Scene* scene);

	void GetReady();
	void GetReadyOpacitySet();
	void FalseStageStart();
};
