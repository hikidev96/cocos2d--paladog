#pragma once

#include "cocos_framework.h"
#include "cocos2d.h"
#include "ui\CocosGUI.h"

class UpgradeScene : public Scene
{
	SpriteFrameCache* _cache;

	Sprite *_mainScene, *_shopScene;
	Sprite *_upgrade;
	Sprite *_unit00, *_unit01, *_unit02, *_unit03, *_unit04, *_unit05, *_unit06, *_unit07, *_unit08;
	Sprite *_hpBar, *_attackBar, *_speedBar, *_delayBar;
	Sprite *_unitSelect;
	Sprite *_unit;

	Label *_hp, *_attack, *_speed, *_delay, *_gold;
	Label *_myGold;

	int _select;

	EventListenerTouchOneByOne* listener;

public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(UpgradeScene);
	

private:
	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
};