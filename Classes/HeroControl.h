#pragma once

#include "cocos_framework.h"
#include "Hero.h"
#include "HeroUnit.h"

class HeroControl : Scene
{
	SpriteFrameCache* cache;
	Hero* _hero;
	HeroUnit* _heroUnit;

	EventListenerTouchOneByOne* listener;

	Scene* _scene;
	Sprite* _leftButton;
	Sprite* _rightButton;

	bool _right;
	bool _left;
public:
	HeroControl(Scene* scene, Hero* hero);
	void HeroMove();

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
};