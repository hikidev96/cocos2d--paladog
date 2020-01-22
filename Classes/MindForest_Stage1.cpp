#include "MindForest_Stage1.h"

Scene* MindForest_Stage1::createScene() {
	return MindForest_Stage1::create();
}

bool MindForest_Stage1::init() {
	if (!Scene::init()) {
		return false;
	}

	_bgLayer = Layer::create();
	this->addChild(_bgLayer, -100);

	_hero = new Hero(this, _bgLayer);
	_heroControl = new HeroControl(this, _hero, _bgLayer);
	_dungeon = new Dungeon(this, _bgLayer, 1000); //2번째 인자에 체력 넣음

	this->schedule(schedule_selector(MindForest_Stage1::tick));
	this->schedule(schedule_selector(MindForest_Stage1::HeroManaRegen), _hero->getManaRegenSpeed());
	this->schedule(schedule_selector(MindForest_Stage1::HeroMeatRegen), _hero->getMeatRegenSpeed());

	_monster.push_back(new Monster(this, _bgLayer, _hero, _heroControl->getHeroUnitVec(), Mob::좀비킹)); //몬스터 생성

	_hero->getHero()->setZOrder(50); //위치조절을 위한 임시 설정입니당
	
	// 배경이미지 plist
	_cache = SpriteFrameCache::getInstance();
	_cache->addSpriteFramesWithFile("UI/Background/background_00.plist");

	// 배경이미지 만들기
	_backGround1 = Sprite::createWithSpriteFrameName("background_00_a.png");
	_backGround1->setPosition({ 0,525 });
	_backGround1->setAnchorPoint({ 0,1 });

	// 이미지가 짧아서 여러장 붙힘
	_backGround2 = Sprite::createWithSpriteFrameName("background_00_b.png");
	_backGround2->setPosition({ 0,525 });
	_backGround2->setAnchorPoint({ 0,1 });
	_backGround2_1 = Sprite::createWithSpriteFrameName("background_00_b.png");
	_backGround2_1->setPosition({ 752,525 });
	_backGround2_1->setAnchorPoint({ 0,1 });

	_backGround3 = Sprite::createWithSpriteFrameName("background_00_c.png");
	_backGround3->setPosition({ 0,525 });
	_backGround3->setAnchorPoint({ 0,1 });

	// 이미지가 짧아서 여러장 붙힘
	_backGround3_1 = Sprite::createWithSpriteFrameName("background_00_c.png");
	_backGround3_1->setPosition({ 480,525 });
	_backGround3_1->setAnchorPoint({ 0,1 });
	_backGround3_2 = Sprite::createWithSpriteFrameName("background_00_c.png");
	_backGround3_2->setPosition({ 960,525 });
	_backGround3_2->setAnchorPoint({ 0,1 });

	// 이미지가 만나는 가장자리에 검은선이 생기는 현상을 방지
	_backGround1->getTexture()->setAliasTexParameters();
	_backGround2->getTexture()->setAliasTexParameters();
	_backGround2_1->getTexture()->setAliasTexParameters();
	_backGround3->getTexture()->setAliasTexParameters();
	_backGround3_1->getTexture()->setAliasTexParameters();
	_backGround3_2->getTexture()->setAliasTexParameters();

	// 배경레이어에 추가
	_bgLayer->addChild(_backGround1, -100);
	_bgLayer->addChild(_backGround2, -101);
	_bgLayer->addChild(_backGround2_1, -101);
	_bgLayer->addChild(_backGround3, -102);
	_bgLayer->addChild(_backGround3_1, -102);
	_bgLayer->addChild(_backGround3_2, -102);
	
	// Follow 액션으로 화면이동구현
	_bgLayer->runAction(Follow::create(_hero->getHero(), Rect(0, 0, 1024, 512)));

	return true;
}

void MindForest_Stage1::tick(float delta)
{
	_heroControl->HeroMove();
	//_heroControl->UnitMove();

	MonsterTick();


	for (int i = 0; i < _heroControl->getHeroUnitVec().size(); ++i)
	{
		_heroControl->getHeroUnitVec()[i]->BringMonsterVec(_monster);
	}

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
		_monster.push_back(new Monster(this, _bgLayer, _hero, _heroControl->getHeroUnitVec(), Mob::분홍미라));
	}
	for (int i = 0; i < _monster.size(); i++) {
		if (_heroControl->getHeroUnitVec().size() != _monster[i]->getUnitSize()) {
			_monster[i]->setUnit(_heroControl->getHeroUnitVec());
		}
		if (_monster[i]->getIsSummon()) { //좀비킹 소환술
			_monster.push_back(new Monster(this, _bgLayer, _hero, _heroControl->getHeroUnitVec(), Mob::걷는좀비));
			_monster.back()->setSummunPositionX(_monster[i]->getIsSummon());
			_monster.push_back(new Monster(this, _bgLayer, _hero, _heroControl->getHeroUnitVec(), Mob::걷는좀비));
			_monster.back()->setSummunPositionX(_monster[i]->getIsSummon());
		}
		_monster[i]->MonsterMove();
		if (_monster[i]->getIsRemove()) {
			_bgLayer->removeChild(_monster[i]->getMonster());
			_monster.erase(_monster.begin() + i);
		}
	}
}