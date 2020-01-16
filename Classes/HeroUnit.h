#pragma once

#include "cocos_framework.h"

class HeroUnit
{
	vector<HeroUnit*> _unitVec;

	Sprite* _UnitSprite;

	float _Hp;
	float _Atk;
	float _Speed;

	HeroUnit* _heroUnit;

public:
	HeroUnit() {};
	void createUnitMouse(Scene* scene);
	void createUnitBear(Scene* scene);
	void createUnitKangaroo(Scene* scene);
	void MoveUnit();

	vector<HeroUnit*> getUnitVec() { return _unitVec; }
	Sprite* getSprite() { return _UnitSprite; }
	void setSprite(Sprite* pSprite) { _UnitSprite = pSprite; }
	float getHp() { return _Hp; }
	void setHp(float hp) { _Hp = hp; }
	float getAtk() { return _Atk; }
	void setAtk(float atk) { _Atk = atk; }
	float getSpeed() { return _Speed; }
	void setSpeed(float speed) { _Speed = speed; }

};