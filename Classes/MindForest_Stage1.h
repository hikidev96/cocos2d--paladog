#pragma once

#include "cocos_framework.h"
#include "Hero.h"
#include "HeroControl.h"
#include "Monster.h"

class MindForest_Stage1 : public Scene
{
	Hero* _hero;
	vector<Monster*> _monster;
	HeroControl* _heroControl;
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(MindForest_Stage1);

	void tick(float delta);
	void MonsterTick();
};
