#pragma once

#include "cocos_framework.h"
#include "Hero.h"
#include "HeroControl.h"
#include "HeroUnit.h"

class MindForest_Stage1 : public Scene
{
	Hero* _hero;
	HeroControl* _heroControl;
	HeroUnit* _heroUnit;
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(MindForest_Stage1);

	void tick(float delta);
	void HeroManaRegen(float delta);
	void HeroMeatRegen(float delta);
};
