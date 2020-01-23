#pragma once

#include "cocos_framework.h"
#include "Hero.h"
#include "HeroUnit.h"
#include "Monster.h"

class HeroControl : Scene
{
	SpriteFrameCache* cache; // 캐시
	Hero* _hero; // 히어로 객체
	HeroUnit* _heroUnit; // 히어로 유닛객체
	vector<HeroUnit*> _heroUnitVec; // 백터

	EventListenerTouchOneByOne* listener;

	Layer* _layer; // 히어로,유닛,몬스터 레이어

	Scene* _scene;
	Sprite* _leftButton; // 왼쪽Move버튼
	Sprite* _rightButton; // 오른쪽Move버튼
	Sprite* _mainDashbord; // 대쉬보드
	Sprite* _mainDashbordCase; // 대쉬보드 케이스
	Sprite* _skillOneButton; // 스킬 1 버튼
	Sprite* _skillTwoButton; // 스킬 2 버튼
	Sprite* _skillThreeButton; // 스킬 3 버튼
	Sprite* _mouseSummonsButton; // 생쥐 소환 버튼
	Sprite* _mouseSummonsButtonDisable; // 생쥐 소환 버튼(타이머)
	Sprite* _bearSummonsButton; // 곰 소환 버튼
	Sprite* _bearSummonsButtonDisable; // 곰 소환 버튼(타이머)
	Sprite* _kangarooSummonsButton; // 캥거루 소환 버튼
	Sprite* _kangarooSummonsButtonDisable; // 캥거루 소환 버튼(타이머)
	Sprite* _unitLock1; // 잠긴 유닛 버튼
	Sprite* _unitLock2; // 잠긴 유닛 버튼
	Sprite* _unitLock3; // 잠긴 유닛 버튼
	Sprite* _unitLock4; // 잠긴 유닛 버튼
	Sprite* _unitLock5; // 잠긴 유닛 버튼
	Sprite* _unitLock6; // 잠긴 유닛 버튼
	Sprite* _meatIcon; // 고기아이콘
	Sprite* _manaIcon; // 마나아이콘
	Sprite* _meatBackGround; // 고기,마나 게이지 배경(검정)
	Sprite* _hpInfoLayout; // 체력정보(상단중앙)
	Sprite* _hpInfoBack; // 체력정보배경(검정)
	Sprite* _expBar; // 경험치바
	Sprite* _expBarBack; // 경험치바배경(검정)

	Label* _currentMeat;
	Label* _MaxMeat;
	Label* _currentMana;
	Label* _MaxMana;

	ProgressTimer* _mouseSummonsTimer;
	ProgressTimer* _bearSummonsTimer;
	ProgressTimer* _kangarooSummonsTimer;

	float _mouseSummonsCollTime;
	float _mouseSummonsMaxCollTime;
	float _bearSummonsCollTime;
	float _bearSummonsMaxCollTime;
	float _kangarooSummonsCollTime;
	float _kangarooSummonsMaxCollTime;

	bool _right;
	bool _left;

	bool _skillOneClick;
	bool _skillTwoClick;
	bool _skillThreeClick;

	bool _mouseSummonsClick;
	bool _bearSummonsClick;
	bool _kangarooSummonsClick;

	bool _mouseSummonsButtonActivation;
	bool _bearSummonsButtonActivation;
	bool _kangarooSummonsButtonActivation;

public:
	HeroControl(Scene* scene, Hero* hero, Layer* layer);
	//void UnitMove();
	void HeroMove();
	void HeroManaRegen();
	void HeroMeatRegen();
	void UnitVecErase();
	void UnitZorder();
	void CoolTime();

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);

	vector<HeroUnit*> getHeroUnitVec() { return _heroUnitVec; }
};