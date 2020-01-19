#pragma once

#include "cocos_framework.h"
#include "Hero.h"
#include "HeroUnit.h"

class HeroControl : Scene
{
	SpriteFrameCache* cache; // 캐시
	Hero* _hero; // 히어로 객체
	HeroUnit* _heroUnit; // 히어로 유닛객체
	vector<HeroUnit*> _heroUnitVec; // 백터

	EventListenerTouchOneByOne* listener;

	Scene* _scene;
	Sprite* _leftButton; // 왼쪽Move버튼
	Sprite* _rightButton; // 오른쪽Move버튼
	Sprite* _mainDashbord; // 대쉬보드
	Sprite* _mainDashbordCase; // 대쉬보드 케이스
	Sprite* _skillOneButton;
	Sprite* _skillTwoButton;
	Sprite* _skillThreeButton;

	bool _right;
	bool _left;

	bool _skillOneClick;
	bool _skillTwoClick;
	bool _skillThreeClick;

public:
	HeroControl(Scene* scene, Hero* hero);
	void HeroMove();
	void UnitMove();
	void HeroManaRegen();

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);

	vector<HeroUnit*> getHeroUnitVec() { return _heroUnitVec; }
};