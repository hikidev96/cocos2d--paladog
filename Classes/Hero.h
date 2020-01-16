#pragma once
#include "cocos_framework.h"

enum INFO
{
	Waiting = 0,
	Walking,
};

class Hero
{
	SpriteFrameCache* cache;

	Animation* _animation1;
	Animate* _animate1;

	Animation* _animation2;
	Animate* _animate2;


	RepeatForever* _heroWaitingAction;
	RepeatForever* _heroWalkingAction;

	Sprite* _hero;
	float _speed;
	float _lv;
public:
	Hero(Scene* scene);
	Sprite* getHero() { return _hero; }
	float getSpeed() { return _speed; }
	void setSpeed(float speed) { _speed = speed; }
	float getLv() { return _lv; }
	void setLv(float lv) { _lv = lv; }
	RepeatForever* getWaitingAction() { return _heroWaitingAction; }
	RepeatForever* getWalkingAction() { return _heroWalkingAction; }
};