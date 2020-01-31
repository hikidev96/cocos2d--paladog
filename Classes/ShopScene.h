#pragma once

#include "cocos_framework.h"
#include "cocos2d.h"
#include "ui\CocosGUI.h"

class ShopScene : public Scene
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(ShopScene);
private:

	Animation* _pigmotion;
	Animate* _pigmote;
	RepeatForever* _ShopPigMotion;
};