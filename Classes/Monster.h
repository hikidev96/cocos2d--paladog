#pragma once
#include "cocos_framework.h"
#include "Hero.h"
#include "HeroUnit.h"

enum Mob {
	걷는좀비,
	분홍미라,
	좀비킹
};

class Monster : Scene
{
	enum STATE {
		WALK, //이동
		ATTACK, //공격
		DEAD //죽음
	};

	Scene* _scene;
	Hero* _hero;
	vector<HeroUnit*> _unit;

	SpriteFrameCache* cache;

	Sprite* _monster;
	Sprite* _summon;

	char* _monsterCode; //몬스터 키값
	STATE _state; //몬스터 상태값

	bool _moveChange;

	int _atkMaxFrame; //공격 모션 최대 프레임 수

	float _hpm, _hp; //몬스터 최대 체력, 현재 체력
	float _atk; //몬스터 공격력
	float _speed; //몬스터 이동속도
	float _delay; //몬스터 공격속도
	float _range; //몬스터 공격범위
	int _exp; //몬스터 처치 시 획득 경험치
	int _money; //몬스터 처치 시 획득 머니

	bool _isRemove; //몬스터 삭제
	float _isSummonX; //몬스터 소환좌표

public:
	Monster(Scene* scene, Hero* hero, vector<HeroUnit*> unit, Mob mob);

	void MonsterMove();
	void Hit(float atk); //매개 변수에 공격력 삽입
	void setSummunPositionX(float x);
	void setUnit(vector<HeroUnit*> unit) { _unit = unit; }

	Sprite* getMonster() { return _monster; }
	int getUnitSize() { return _unit.size(); }
	float getHp() { return _hp; }
	float getRange() { return _range; }
	int getExp() { return _exp; }
	int getMoney() { return _money; }

	bool getIsRemove() { return _isRemove; }
	float getIsSummon() { return _isSummonX; }

private:
	void Walk(); //몬스터 이동
	void Attack(); //몬스터 공격
	void ZomkingSummon(); //좀비킹 소환술
	void ZomkingSummonRemove(); //좀비킹 소환술 해제
	void Dead(); //몬스터 죽음
};