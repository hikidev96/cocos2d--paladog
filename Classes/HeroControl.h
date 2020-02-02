#pragma once

#include "cocos_framework.h"
#include "Hero.h"
#include "HeroUnit.h"
#include "Monster.h"
#include "Dungeon.h"
#include "MissileCollision.h"
#include "ShopScene.h"

class HeroControl : Scene
{
	SpriteFrameCache* cache; // 캐시
	HeroUnit* _heroUnit; // 히어로 유닛객체
	Dungeon* _dungeon; // 몬스터 기지체력 가지고오기위해서
	MissileCollision* _missileCollision;
	vector<HeroUnit*> _heroUnitVec; // 유닛 백터
	vector<MissileCollision*> _missileCollisionVec; // 미사일 벡터

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
	Sprite* _goldIcon; // 골드 아이콘
	Sprite* _pauseButton; // 정지버튼
	Sprite* _miniMapPointer; // 미니맵 포인터

	Sprite* NextButton; // 클리어시 보여지는 넥스트 버튼

	Sprite* _levelUpBlackDot; // 레벨업 효과
	Sprite* _levelUpText; // 레벨업 텍스트
	Sprite* _levelUpWingL;
	Sprite* _levelUpWingR;

	Sprite* _pauseBack;
	Sprite* _pauseBord;
	Sprite* _pauseText;
	Sprite* _pauseQuitButton;
	Sprite* _pauseResumeButton;

	Animation* _miniMapPointerAnimation;
	Animate* _miniMapPointerAnimate;
	RepeatForever* _miniMapPointerRepeat;

	Label* _currentMeat;
	Label* _MaxMeat;
	Label* _currentMana;
	Label* _MaxMana;
	Label* _Level;
	Label* _Gold;
	Label* _SkillOneManaUse;
	Label* _SkillTwoManaUse;
	Label* _SkillThreeManaUse;

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

	bool _PauseClick;

	bool _UnitActiveSoundBool;
	bool _UnitActiveSoundBool2;
	bool _UnitActiveSoundBool3;

	// 사운드
	int _audioId1; // 히어로 걷기
	int _audioUnitActive; // 유닛 소환버튼 활성화
	int _audioUnitSommons; // 유닛 소환버튼 누름

public:
	HeroControl(Scene* scene, Layer* layer, Dungeon* dungeon);
	void HeroMove(Dungeon* dungeon);
	void HeroManaRegen();
	void HeroMeatRegen();
	void UnitVecErase();
	void CoolTime();
	void SkillEffectVisible();
	void MiniMap();
	void LevelUp();
	void SetLevelUpImage();
	void UnitBuff();
	void NextButtonVisible();

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);

	vector<HeroUnit*> getHeroUnitVec() { return _heroUnitVec; }
	vector<MissileCollision*> getMissileCollisionVec() { return _missileCollisionVec; }
};