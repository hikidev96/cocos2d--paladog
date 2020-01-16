#include "cocos_framework.h"
#include "MindForest_Stage1.h"


Scene* MindForest_Stage1::createScene() {
	return MindForest_Stage1::create();
}

bool MindForest_Stage1::init() {
	if (!Scene::init()) {
		return false;
	}

	_hero = new Hero(this);
	_heroControl = new HeroControl(this, _hero);

	this->schedule(schedule_selector(MindForest_Stage1::tick));


	return true;
}

void MindForest_Stage1::tick(float delta)
{
	_heroControl->HeroMove();
}
