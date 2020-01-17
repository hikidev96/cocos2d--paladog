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

	MonsterTick();
}

void MindForest_Stage1::MonsterTick()
{
	if (rand() % 150 == 0) {
		_monster.push_back(new Monster(this, Mob::걷는좀비)); //몬스터 생성
	}
	for (int i = 0; i < _monster.size(); i++) {
		_monster[i]->MonsterMove();
		
		if (_hero->getHero()->getPositionX() < _monster[i]->getMonster()->getPositionX() &&
			_hero->getHero()->getPositionX() > _monster[i]->getMonster()->getPositionX() - _monster[i]->getRange()) {
			if (!_monster[i]->getIsAttack()) {
				_monster[i]->Attack();
			}
		}
		else if(_monster[i]->getIsAttack()){
			_monster[i]->Walk();
		}
		if (_monster[i]->getIsRemove()) {
			this->removeChild(_monster[i]->getMonster());
			_monster.erase(_monster.begin() + i);
		}
	}
}
