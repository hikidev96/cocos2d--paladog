#pragma once

#include "cocos_framework.h"
#include "Hero.h"
#include "HeroControl.h"
#include "HeroUnit.h"
#include "Monster.h"
#include "Dungeon.h"
#include "MindForest_Stage2.h"

class MindForest_Stage1 : public Scene
{
	HeroControl* _heroControl;
	HeroUnit* _heroUnit;
	vector<Monster*> _monster;
	Dungeon* _dungeon;

	Layer* _bgLayer;

	SpriteFrameCache* _cache;

	Sprite* _backGround1;
	Sprite* _backGround2;
	Sprite* _backGround2_1;
	Sprite* _backGround3;
	Sprite* _backGround3_1;
	Sprite* _backGround3_2;

public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(MindForest_Stage1);

	void tick(float delta);
	void HeroManaRegen(float delta);
	void HeroMeatRegen(float delta);

	void MonsterTick();

	void ClearTest();
};
