#pragma once
#include "cocos_framework.h"

enum INFO
{
	Waiting = 0,
	Walking,
	Attack,
};

enum Movement
{
	RightWay = 10,
	LeftWay,
};

class Hero
{
private:
	SpriteFrameCache* cache;

	Animation* _animation1;
	Animate* _animate1;

	Animation* _animation2;
	Animate* _animate2;

	Animation* _animation3;
	Animate* _animate3;

	RepeatForever* _heroWaitingAction;
	RepeatForever* _heroWalkingAction;

	Sprite* _hero;
	ProgressTimer* _manaGauge;
	ProgressTimer* _meatGauge;

	Movement _movement;

	float _speed;
	float _lv;
	float _mana;
	float _maxmana;
	float _manaRegenSpeed;
	float _meat;
	float _maxmeat;
	float _meatRegenSpeed;

	float _skillOneManaUse;
	float _skillTwoManaUse;
	float _skillThreeManaUse;

public:

	Hero(Scene* scene);
	Movement getMoveWay() { return _movement; }
	void setMoveWay(Movement movement) { _movement = movement; }
	Sprite* getHero() { return _hero; }
	float getSpeed() { return _speed; }
	void setSpeed(float speed) { _speed = speed; }
	float getMana() { return _mana; }
	void setMana(float mana) { _mana = mana; }
	float getMaxMana() { return _maxmana; }
	void setMaxMana(float maxmana) { _maxmana = maxmana; }
	float getManaRegenSpeed() { return _manaRegenSpeed; }
	void setManaRegenSpeed(float manaregenspeed) { _manaRegenSpeed = manaregenspeed; }
	float getMeat() { return _meat; }
	void setMeat(float meat) { _meat = meat; }
	float getMaxMeat() { return _maxmeat; }
	void setMaxMeat(float maxmeat) { _maxmeat = maxmeat; }
	float getMeatRegenSpeed() { return _meatRegenSpeed; }
	void setMeatRegenSpeed(float meatregenspeed) { _meatRegenSpeed = meatregenspeed; }
	float getSkillOneManaUse() { return _skillOneManaUse; }
	void setSkillOneManaUse(float skillonemanause) { _skillOneManaUse = skillonemanause; }
	float getSkillTwoManaUse() { return _skillTwoManaUse; }
	void setSkillTwoManaUse(float skilltwomanause) { _skillTwoManaUse = skilltwomanause; }
	float getSkillThreeManaUse() { return _skillThreeManaUse; }
	void setSkillThreeManaUse(float skillthreemanause) { _skillThreeManaUse = skillthreemanause; }
	float getLv() { return _lv; }
	void setLv(float lv) { _lv = lv; }
	ProgressTimer* getManaGauge() { return _manaGauge; }
	ProgressTimer* getMeatGauge() { return _meatGauge; }
	RepeatForever* getWaitingAction() { return _heroWaitingAction; }
	RepeatForever* getWalkingAction() { return _heroWalkingAction; }
	Animate* getAttackAction() { return _animate3; }
};