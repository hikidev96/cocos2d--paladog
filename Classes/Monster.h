#pragma once
#include "cocos_framework.h"
#include "Hero.h"
#include "HeroUnit.h"

enum Mob {
	일반미라,
	광부좀비,
	일반좀비,
	핑크미라,
	강화좀비,
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
	Layer* _layer;
	Hero* _hero;
	vector<HeroUnit*> _unit;

	SpriteFrameCache* cache;

	Sprite* _monster;
	Sprite* _summon;

	ProgressTimer* _monsterHpBar;
	Sprite* _monsterHpBarBack;

	char* _monsterCode; //몬스터 키값
	STATE _state; //몬스터 상태값

	bool _moveChange;

	int _atkMaxFrame; //공격 모션 최대 프레임 수

	float _hpm, _hp; //몬스터 최대 체력, 현재 체력
	float _atk; //몬스터 공격력
	float _speed; //몬스터 이동속도
	float _delay; //몬스터 공격속도
	float _range; //몬스터 공격범위
	int _time;
	int _exp; //몬스터 처치 시 획득 경험치
	int _money; //몬스터 처치 시 획득 머니

	int _isAttackDelay;//공격딜레이 체크
	bool _isRemove; //몬스터 삭제
	float _isSummonX; //몬스터 소환좌표
	int _unitAttack; //공격할 유닛 번호

public:
	Monster(Scene* scene, Layer* layer, Hero* hero, vector<HeroUnit*> unit, Mob mob);

	void MonsterMove();
	void Hit(float atk); //매개 변수에 공격력 삽입
	void setSummunPositionX(float x);
	void setUnit(vector<HeroUnit*> unit) { _unit = unit; }
	void setUnitAttack() { _unitAttack = -1; }
	int getUnitAttack() { return _unitAttack; }

	Sprite* getMonster() { return _monster; }
	int getUnitSize() { return _unit.size(); }
	float getHp() { return _hp; }
	float getAtk() { return _atk; }
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