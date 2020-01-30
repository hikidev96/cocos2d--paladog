#include "ServiceScene.h"

ServiceScene::ServiceScene(Scene * scene)
{
	_scene = scene;

	_cache = SpriteFrameCache::getInstance();
	_cache->addSpriteFramesWithFile("Player/stage image/get_ready.plist");
	_cache->addSpriteFramesWithFile("Player/stage image/stage_clear_texture.plist");

	// 겟 레디 부분
	_getReadyBack1 = Sprite::createWithSpriteFrameName("getready_back.png");
	_getReadyBack1->setPosition(150, 0);
	_getReadyBack1->setScaleX(2.3);
	_getReadyBack1->setOpacity(100);
	_getReadyBack1->setAnchorPoint({ 1,0 });
	scene->addChild(_getReadyBack1);

	_getReadyBack2 = Sprite::createWithSpriteFrameName("getready_back.png");
	_getReadyBack2->setPosition(110, 0);
	_getReadyBack2->setScaleX(2.3);
	_getReadyBack2->setOpacity(100);
	_getReadyBack2->setAnchorPoint({ 1,0 });
	scene->addChild(_getReadyBack2);

	_getReadyBack3 = Sprite::createWithSpriteFrameName("getready_back.png");
	_getReadyBack3->setPosition(80, 0);
	_getReadyBack3->setScaleX(2.3);
	_getReadyBack3->setOpacity(100);
	_getReadyBack3->setAnchorPoint({ 1,0 });
	scene->addChild(_getReadyBack3);

	_getReadyFont = Sprite::createWithSpriteFrameName("msg_getready.png");
	_getReadyFont->setOpacity(0);
	scene->addChild(_getReadyFont);

	// 스테이지 클리어부분

}

void ServiceScene::GetReady()
{
	if (!_getReadyBack1->getNumberOfRunningActions() && Hero::getInstance()->getStageStart() == false)
	{
		_getReadyBack1->runAction(Sequence::create(MoveBy::create(1, { 660,0 }),CallFunc::create(CC_CALLBACK_0(ServiceScene::GetReadyOpacitySet,this)),
			DelayTime::create(2), MoveBy::create(1, { 660,0 }), nullptr));
		_getReadyBack2->runAction(Sequence::create(MoveBy::create(1, { 660,0 }), DelayTime::create(2), MoveBy::create(1, { 660,0 }),
			CallFunc::create(CC_CALLBACK_0(ServiceScene::FalseStageStart, this)),nullptr));
		_getReadyBack3->runAction(Sequence::create(MoveBy::create(1, { 660,0 }), DelayTime::create(2), MoveBy::create(1, { 660,0 }), nullptr));
	}
}

void ServiceScene::GetReadyOpacitySet()
{
	_getReadyFont->setPosition(240, 180);
	_getReadyFont->runAction(Sequence::create(FadeIn::create(0.5),DelayTime::create(1),FadeOut::create(0.5),nullptr));
}

void ServiceScene::FalseStageStart()
{
	Hero::getInstance()->setStageStart(true);
}


