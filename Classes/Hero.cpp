#include "Hero.h"

Hero::Hero(Scene * scene, Layer* layer)
{
	// plist 파일 추가
	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Player/Unit/u_01.plist");

	// 영웅 만들기
	_hero = Sprite::createWithSpriteFrameName("hero_wait_0001.png");
	_hero->setPosition(100, 400);
	layer->addChild(_hero);

	//마나 게이지 만들기
	_manaGauge = ProgressTimer::create(Sprite::create("UI/Mana.png"));
	_manaGauge->setType(ProgressTimer::Type::BAR);
	_manaGauge->setPosition({ 378,113 });
	_manaGauge->setMidpoint({ 1, 0 });
	_manaGauge->setBarChangeRate({ 1,0 });
	scene->addChild(_manaGauge, -1);

	//고기 게이지 만들기
	_meatGauge = ProgressTimer::create(Sprite::create("UI/Meat.png"));
	_meatGauge->setType(ProgressTimer::Type::BAR);
	_meatGauge->setPosition({ 103,113 });
	_meatGauge->setMidpoint({ 0, 0 });
	_meatGauge->setBarChangeRate({ 1,0 });
	scene->addChild(_meatGauge, -1);

	_hpInfoGauge = ProgressTimer::create(Sprite::create("UI/HeroHpBar.png"));
	_hpInfoGauge->setType(ProgressTimer::Type::BAR);
	_hpInfoGauge->setPosition(201, 310);
	_hpInfoGauge->setMidpoint({ 1,0 });
	_hpInfoGauge->setBarChangeRate({ 1,0 });
	scene->addChild(_hpInfoGauge, -1);

	_MonsterBaseHpGauge = ProgressTimer::create(Sprite::create("UI/MonsterBaseHpBar.png"));
	_MonsterBaseHpGauge->setType(ProgressTimer::Type::BAR);
	_MonsterBaseHpGauge->setPosition(280, 310);
	_MonsterBaseHpGauge->setMidpoint({ 0,0 });
	_MonsterBaseHpGauge->setBarChangeRate({ 1,0 });
	scene->addChild(_MonsterBaseHpGauge, -1);

	_movement = RightWay; // 기본 방향설정

	_lv = 1; // 레벨
	_speed = 1.0f; // 이동스피드

	_maxhp = 200; // 최대체력
	_hp = 200; // 현재체력

	_maxmana = 100; // 최대마나량
	_mana = 0; // 현재마나량
	_manaRegenSpeed = 0.2f; // 마나리젠속도

	_maxmeat = 40; // 최대고기량
	_meat = 0; // 현재고기량
	_meatRegenSpeed = 0.2f; // 고기리젠속도

	_skillOneManaUse = 10; // 스킬 1 마나 사용량
	_skillTwoManaUse = 20; // 스킬 2 마나 사용량
	_skillThreeManaUse = 30; // 스킬 3 마나 사용량

	// 대기 애니메이션 만들기
	_animation1 = Animation::create();
	_animation1->setDelayPerUnit(0.03f);
	_animation1->addSpriteFrame(cache->getSpriteFrameByName("hero_wait_0001.png"));
	_animation1->addSpriteFrame(cache->getSpriteFrameByName("hero_wait_0002.png"));
	_animation1->addSpriteFrame(cache->getSpriteFrameByName("hero_wait_0003.png"));
	_animation1->addSpriteFrame(cache->getSpriteFrameByName("hero_wait_0004.png"));
	_animation1->addSpriteFrame(cache->getSpriteFrameByName("hero_wait_0005.png"));
	_animation1->addSpriteFrame(cache->getSpriteFrameByName("hero_wait_0006.png"));
	_animation1->addSpriteFrame(cache->getSpriteFrameByName("hero_wait_0007.png"));
	_animation1->addSpriteFrame(cache->getSpriteFrameByName("hero_wait_0008.png"));
	_animation1->addSpriteFrame(cache->getSpriteFrameByName("hero_wait_0009.png"));
	_animation1->addSpriteFrame(cache->getSpriteFrameByName("hero_wait_0010.png"));
	_animation1->addSpriteFrame(cache->getSpriteFrameByName("hero_wait_0011.png"));
	_animation1->addSpriteFrame(cache->getSpriteFrameByName("hero_wait_0012.png"));
	_animate1 = Animate::create(_animation1);
	_heroWaitingAction = RepeatForever::create(_animate1);
	_heroWaitingAction->retain();
	_heroWaitingAction->setTag(Waiting);

	// 걷기 애니메이션 만들기
	_animation2 = Animation::create();
	_animation2->setDelayPerUnit(0.03f);
	_animation2->addSpriteFrame(cache->getSpriteFrameByName("hero_walk_0001.png"));
	_animation2->addSpriteFrame(cache->getSpriteFrameByName("hero_walk_0002.png"));
	_animation2->addSpriteFrame(cache->getSpriteFrameByName("hero_walk_0003.png"));
	_animation2->addSpriteFrame(cache->getSpriteFrameByName("hero_walk_0004.png"));
	_animation2->addSpriteFrame(cache->getSpriteFrameByName("hero_walk_0005.png"));
	_animation2->addSpriteFrame(cache->getSpriteFrameByName("hero_walk_0006.png"));
	_animation2->addSpriteFrame(cache->getSpriteFrameByName("hero_walk_0007.png"));
	_animation2->addSpriteFrame(cache->getSpriteFrameByName("hero_walk_0008.png"));
	_animation2->addSpriteFrame(cache->getSpriteFrameByName("hero_walk_0009.png"));
	_animation2->addSpriteFrame(cache->getSpriteFrameByName("hero_walk_0010.png"));
	_animation2->addSpriteFrame(cache->getSpriteFrameByName("hero_walk_0011.png"));
	_animation2->addSpriteFrame(cache->getSpriteFrameByName("hero_walk_0012.png"));
	_animate2 = Animate::create(_animation2);
	_heroWalkingAction = RepeatForever::create(_animate2);
	_heroWalkingAction->retain();
	_heroWalkingAction->setTag(Walking);

	// 공격 애니메이션 만들기
	_animation3 = Animation::create();
	_animation3->setDelayPerUnit(0.03f);
	_animation3->addSpriteFrame(cache->getSpriteFrameByName("hero_attack_0001.png"));
	_animation3->addSpriteFrame(cache->getSpriteFrameByName("hero_attack_0002.png"));
	_animation3->addSpriteFrame(cache->getSpriteFrameByName("hero_attack_0003.png"));
	_animation3->addSpriteFrame(cache->getSpriteFrameByName("hero_attack_0004.png"));
	_animation3->addSpriteFrame(cache->getSpriteFrameByName("hero_attack_0005.png"));
	_animation3->addSpriteFrame(cache->getSpriteFrameByName("hero_attack_0006.png"));
	_animation3->addSpriteFrame(cache->getSpriteFrameByName("hero_attack_0007.png"));
	_animation3->addSpriteFrame(cache->getSpriteFrameByName("hero_attack_0008.png"));
	_animation3->addSpriteFrame(cache->getSpriteFrameByName("hero_attack_0009.png"));
	_animation3->addSpriteFrame(cache->getSpriteFrameByName("hero_attack_0010.png"));
	_animate3 = Animate::create(_animation3);
	_animate3->retain();
	_animate3->setTag(Attack);

}
