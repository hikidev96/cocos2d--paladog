#pragma once

#include "cocos_framework.h"
#include "cocos2d.h"
#include "ui\CocosGUI.h"

class UpgradeScene : public Scene
{
	SpriteFrameCache* _cache;

	std::vector<Sprite*> _unit;
	Sprite *_mainScene, *_shopScene;
	Sprite *_unit00, *_unit01, *_unit02, *_unit03, *_unit04, *_unit05, *_unit06, *_unit07, *_unit08;
	Sprite *_unitSelect;

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