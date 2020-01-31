#pragma once

#include "cocos_framework.h"
#include "cocos2d.h"
#include "ui\CocosGUI.h"

class UpgradeScene : public Scene
{
	SpriteFrameCache* _cache;

public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(UpgradeScene);
	
};