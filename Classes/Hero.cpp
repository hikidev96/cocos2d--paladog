#include "Hero.h"

Hero::Hero(Scene * scene)
{
	// plist 파일 추가
	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Player/Unit/u_01.plist");

	// 영웅 만들기
	_hero = Sprite::createWithSpriteFrameName("hero_wait_0001.png");
	_hero->setPosition(100, 200);
	scene->addChild(_hero);

	_speed = 1.0f;


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

	
}
