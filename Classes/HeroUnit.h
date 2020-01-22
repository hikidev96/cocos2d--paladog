#pragma once

#include "cocos_framework.h"
class Monster;


enum UnitKind
{
	생쥐 = 100,
	곰,
	캥거루,
};

enum UnitAction
{
	UnitWalk = 50,
	UnitAttack1,
	UnitAttack2,
	UnitDead,
	UnitCollision,
};

class HeroUnit
{
	SpriteFrameCache* cache;

	vector<HeroUnit*> _unitVec; // 백터

	Sprite* _UnitSprite; // 유닛스프라이트

	float _Hp; // 체력
	float _Atk; // 공격력
	float _Speed; // 스피드
	UnitKind _unitKind; // 유닛종류
	UnitAction _unitAction;
	HeroUnit* _heroUnit; // 유닛객체

	// Walk 액션
	Animation* _animation1;
	Animate* _animate1;
	RepeatForever* _walkAction;

	// Attak 액션
	Animation* _animation2;
	Animate* _animate2;

	// Dead 액션
	Animation* _animation3;
	Animate* _animate3;

	vector<Monster*> _monsterVec;

public:
	HeroUnit(Scene* scene, UnitKind herokind, Layer* layer);

	vector<HeroUnit*> getUnitVec() { return _unitVec; }
	UnitKind getHeroKind() { return _unitKind; }
	UnitAction getUnitAction() { return _unitAction; }
	void setUnitAction(UnitAction unitaction) { _unitAction = unitaction; }
	RepeatForever* getWalkAction() { return _walkAction; }
	Animate* getAttackAction() { return _animate2; }
	Animate* getDeadAction() { return _animate3; }
	Sprite* getSprite() { return _UnitSprite; }
	void setSprite(Sprite* pSprite) { _UnitSprite = pSprite; }
	float getHp() { return _Hp; }
	void setHp(float hp) { _Hp = hp; }
	float getAtk() { return _Atk; }
	void setAtk(float atk) { _Atk = atk; }
	float getSpeed() { return _Speed; }
	void setSpeed(float speed) { _Speed = speed; }

	void BringMonsterVec(vector<Monster*> monstervec);
	void UnitMove();
	void HeroUnit_VS_MonsterUnit();

};