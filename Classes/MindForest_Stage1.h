#pragma once

#include "cocos_framework.h"
#include "Hero.h"
#include "HeroControl.h"
#include "HeroUnit.h"
#include "Monster.h"
#include "Dungeon.h"

enum ZORDER { //이거 어디두는게 좋을까여?
	던전뒤 = 10,
	영웅 = 50,
	유닛 = 55,
	던전앞 = 90
};

class MindForest_Stage1 : public Scene
{
	Hero* _hero;
	HeroControl* _heroControl;
	vector<HeroUnit*> _heroUnit;
	vector<Monster*> _monster;
	Dungeon* _dungeon;

public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(MindForest_Stage1);

	void tick(float delta);
	void HeroManaRegen(float delta);
	void HeroMeatRegen(float delta);

	void MonsterTick();
};
