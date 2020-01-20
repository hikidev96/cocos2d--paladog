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
	_dungeon = new Dungeon(this, 1000); //2번째 인자에 체력 넣음

	this->schedule(schedule_selector(MindForest_Stage1::tick));
	this->schedule(schedule_selector(MindForest_Stage1::HeroManaRegen), _hero->getManaRegenSpeed());
	this->schedule(schedule_selector(MindForest_Stage1::HeroMeatRegen), _hero->getMeatRegenSpeed());

	_monster.push_back(new Monster(this, _hero, Mob::좀비킹)); //몬스터 생성

	_hero->getHero()->setZOrder(50); //위치조절을 위한 임시 설정입니당


	return true;
}

void MindForest_Stage1::tick(float delta)
{
	_heroControl->HeroMove();
	_heroControl->UnitMove();

	MonsterTick();

}

void MindForest_Stage1::HeroManaRegen(float delta)
{
	_heroControl->HeroManaRegen();
}

void MindForest_Stage1::HeroMeatRegen(float delta)
{
	_heroControl->HeroMeatRegen();
}

void MindForest_Stage1::MonsterTick()
{
	if (rand() % 150 == 0) {
		_monster.push_back(new Monster(this, _hero, Mob::분홍미라));
	}
	for (int i = 0; i < _monster.size(); i++) {
		if (_monster[i]->getIsSummon()) { //좀비킹 소환술
			_monster.push_back(new Monster(this, _hero, Mob::걷는좀비));
			_monster.back()->setSummunPositionX(_monster[i]->getIsSummon());
			_monster.push_back(new Monster(this, _hero, Mob::걷는좀비));
			_monster.back()->setSummunPositionX(_monster[i]->getIsSummon());
		}
		_monster[i]->MonsterMove();
		if (_monster[i]->getIsRemove()) {
			this->removeChild(_monster[i]->getMonster());
			_monster.erase(_monster.begin() + i);
		}
	}
}