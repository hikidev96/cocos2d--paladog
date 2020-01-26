#pragma once

#include "cocos_framework.h"
#include "Dungeon.h"
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
	UnitSoul,
};

class HeroUnit
{
	SpriteFrameCache* cache;

	Layer* _layer;

	Dungeon* _dungeon;

	vector<HeroUnit*> _unitVec; // 백터

	Sprite* _UnitSprite; // 유닛스프라이트
	Sprite* _UnitDeadAnimateBox; // 영혼 애니메이션 기준 스프라이트
	Sprite* _hitAnimationBox; // 히트 애니메이션 기준 스프라이트

	float _Hp; // 체력
	float _maxHP;
	float _Atk; // 공격력
	float _Speed; // 스피드
	float _AtkSpeed; // 현재 공격 스피드
	float _MaxAtkSpeed; // 최대 공격 스피드
	float _Range; // 사거리
	bool _Dead; // 생사여부
	bool _FirstAtk;
	int _Zorder; // 제트오더

	UnitKind _unitKind; // 유닛종류
	UnitAction _unitAction; // 현재유닛액션
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

	// 죽을시 영혼 애니메이션
	Animation* _animation4; 
	Animate* _animate4;

	// 히트애니메이션
	Animation* _UnitHitAnimation1;
	Animate* _UnitHitAnimate1;

	Animation* _UnitHitAnimation2;
	Animate* _UnitHitAnimate2;

	//RepeatForever* AttackAct;
	Sequence* AttackAct;
	Sequence* DeadAct;

	ProgressTimer* _HeroUnitHpBar;
	Sprite* _HeroUnitHpBarBack;

	vector<Monster*> _monsterVec;

public:
	HeroUnit(Scene* scene, UnitKind herokind, Layer* layer, Dungeon* dungeon);
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
	int getZorder() { return _Zorder; }
	void setZorder(int zorder) { _Zorder = zorder; }
	bool getDead() { return _Dead; }
	void setDead(bool dead) { _Dead = dead; }

	ProgressTimer* getUnitHpBar() { return _HeroUnitHpBar; }
	Sprite* getUnitHpBarBack() { return _HeroUnitHpBarBack; }

	void BringMonsterVec(vector<Monster*> monstervec);
	void UnitMove();
	void UnitCollisionCheck();
	void UnitAttack();
	void UnitDeadCheck();
	void ShowUnitHpBar();
	void ShowUnitDeadSoul();
	void Healing();

};