#pragma once
#include "cocos_framework.h"

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

	SpriteFrameCache* cache;

	Sprite* _monster;
	char* _monsterCode; //몬스터 키값
	STATE _state; //몬스터 상태값

	bool _moveChange;

	int _atkMaxFrame; //공격 모션 최대 프레임 수

	float _hpm, _hp; //몬스터 최대 체력, 현재 체력
	float _speed; //몬스터 이동속도
	float _delay; //몬스터 공격속도
	float _range; //몬스터 공격범위
	int _exp; //몬스터 처치 시 획득 경험치
	int _money; //몬스터 처치 시 획득 머니

	bool _isAttack; //몬스터 공격
	bool _isRemove; //몬스터 삭제

public:
	Monster(Scene* scene, Mob mob);
	
	void MonsterMove();
	void Hit(int atk); //매개 변수에 공격력 삽입
	void Walk(); //몬스터 이동
	void Attack(); //몬스터 공격	
	void Dead(); //몬스터 죽음

	Sprite* getMonster() { return _monster; }
	float getHp() { return _hp; }
	float getRange() { return _range; }
	int getExp() { return _exp; }
	int getMoney() { return _money; }
	
	bool getIsAttack() { return _isAttack; }
	bool getIsRemove() { return _isRemove; }
};