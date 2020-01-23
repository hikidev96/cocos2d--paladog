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

	Animation* _animation1; // 대기 Action
	Animate* _animate1; // 대기 Action

	Animation* _animation2; // Walk Action
	Animate* _animate2;	// Walk Action
	RepeatForever* _heroWaitingAction; // Walk Action
	RepeatForever* _heroWalkingAction; // Walk Action

	Animation* _animation3; // 공격 Action
	Animate* _animate3; // 공격 Action

	Sprite* _hero; // 히어로 스프라이트
	ProgressTimer* _manaGauge; // 마나 게이지
	ProgressTimer* _meatGauge; // 고기 게이지

	ProgressTimer* _hpInfoGauge; // 히어로 체력바(중앙상단)
	ProgressTimer* _MonsterBaseHpGauge; // 몬스터 베이스 체력바(중앙상단)

	Movement _movement; // 현재 플레이어가 보고있는 방향

	float _speed; // 스피드
	float _lv; // 레벨
	float _hp; // 체력
	float _maxhp; // 최대체력
	float _mana; // 현재 마나량
	float _maxmana; // 최대마나
	float _manaRegenSpeed; // 마나 리젠 스피드
	float _meat; // 현재 고기량
	float _maxmeat; // 최대 고기량
	float _meatRegenSpeed; // 고기 리젠 스피드
	float _gold; // 골드
	float _exp; // 경험치
	float _maxExp; // 최대경험치

	float _skillOneManaUse; // 스킬 1 마나 소비량
	float _skillTwoManaUse; // 스킬 2 마나 소비량
	float _skillThreeManaUse; // 스킬 3 마나 소비량

public:

	Hero(Scene* scene, Layer* layer);
	Movement getMoveWay() { return _movement; }
	void setMoveWay(Movement movement) { _movement = movement; }
	Sprite* getHero() { return _hero; }
	float getSpeed() { return _speed; }
	void setSpeed(float speed) { _speed = speed; }
	float getHp() { return _hp; }
	void setHp(float hp) { _hp = hp; }
	float getMaxHp() { return _maxhp; }
	void setMaxHp(float maxhp) { _maxhp = maxhp; }
	float getMana() { return _mana; }
	void setMana(float mana) { _mana = mana; }
	float getMaxMana() { return _maxmana; }
	void setMaxMana(float maxmana) { _maxmana = maxmana; }
	float getGold() { return _gold; }
	void setGold(float gold) { _gold = gold; }
	float getExp() { return _exp; }
	void setExp(float exp) { _exp = exp; }
	float getMaxExp() { return _maxExp; }
	void setMaxExp(float maxexp) { _maxExp = maxexp; }
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
	ProgressTimer* getHeroHpInfo() { return _hpInfoGauge; }
	ProgressTimer* getMonsterBaseInfo() { return _MonsterBaseHpGauge; }
	RepeatForever* getWaitingAction() { return _heroWaitingAction; }
	RepeatForever* getWalkingAction() { return _heroWalkingAction; }
	Animate* getAttackAction() { return _animate3; }
};