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
	auto TextLayer = Layer::create();
	TextLayer->setPosition(0, 0);
	scene->addChild(TextLayer, 1000);

	auto CoinLayer = Layer::create();
	CoinLayer->setPosition(240, 160);
	scene->addChild(CoinLayer, 900);

	auto StarLayer = Layer::create();
	StarLayer->setPosition(240, 0);
	scene->addChild(StarLayer, 1000);

	_stageClearBack = Sprite::createWithSpriteFrameName("stage_clear_blackback.png");
	_stageClearBack->setPosition(-30, 320);
	_stageClearBack->setAnchorPoint({ 0, 0 });
	_stageClearBack->setOpacity(200);
	_stageClearBack->setScale(50.f);
	scene->addChild(_stageClearBack, 700);

	_stageClearText1 = Sprite::createWithSpriteFrameName("stage_clear_text_1.png");
	_stageClearText1->setPosition(115, -50);
	TextLayer->addChild(_stageClearText1);
	_stageClearText2 = Sprite::createWithSpriteFrameName("stage_clear_text_2.png");
	_stageClearText2->setPosition(140, -50);
	TextLayer->addChild(_stageClearText2);
	_stageClearText3 = Sprite::createWithSpriteFrameName("stage_clear_text_3.png");
	_stageClearText3->setPosition(165, -50);
	TextLayer->addChild(_stageClearText3);
	_stageClearText4 = Sprite::createWithSpriteFrameName("stage_clear_text_4.png");
	_stageClearText4->setPosition(190, -50);
	TextLayer->addChild(_stageClearText4);
	_stageClearText5 = Sprite::createWithSpriteFrameName("stage_clear_text_5.png");
	_stageClearText5->setPosition(215, -50);
	TextLayer->addChild(_stageClearText5);
	_stageClearText6 = Sprite::createWithSpriteFrameName("stage_clear_text_6.png");
	_stageClearText6->setPosition(270, -50);
	TextLayer->addChild(_stageClearText6);
	_stageClearText7 = Sprite::createWithSpriteFrameName("stage_clear_text_7.png");
	_stageClearText7->setPosition(295, -50);
	TextLayer->addChild(_stageClearText7);
	_stageClearText8 = Sprite::createWithSpriteFrameName("stage_clear_text_8.png");
	_stageClearText8->setPosition(320, -50);
	TextLayer->addChild(_stageClearText8);
	_stageClearText9 = Sprite::createWithSpriteFrameName("stage_clear_text_9.png");
	_stageClearText9->setPosition(345, -50);
	TextLayer->addChild(_stageClearText9);
	_stageClearText10 = Sprite::createWithSpriteFrameName("stage_clear_text_10.png");
	_stageClearText10->setPosition(370, -50);
	TextLayer->addChild(_stageClearText10);

	_stageClearCoin = Sprite::createWithSpriteFrameName("stage_clear_circle_01.png");
	_stageClearCoin->setPosition(0, 0);
	_stageClearCoin->setScale(3.f);
	_stageClearCoin->setVisible(false);
	CoinLayer->addChild(_stageClearCoin);

	_stageClearLight1 = Sprite::createWithSpriteFrameName("stage_clear_light_01.png");
	_stageClearLight1->setPosition(0, 0);
	_stageClearLight1->setVisible(false);
	_stageClearLight1->setScale(5.f);
	CoinLayer->addChild(_stageClearLight1, -10);
	_stageClearLight2 = Sprite::createWithSpriteFrameName("stage_clear_light_01.png");
	_stageClearLight2->setPosition(0, 0);
	_stageClearLight2->setScale(5.f);
	_stageClearLight2->setVisible(false);
	CoinLayer->addChild(_stageClearLight2, -10);
	_stageClearLight3 = Sprite::createWithSpriteFrameName("stage_clear_light_01.png");
	_stageClearLight3->setPosition(0, 0);
	_stageClearLight3->setScale(5.f);
	_stageClearLight3->setVisible(false);
	CoinLayer->addChild(_stageClearLight3, -11);

	_stageClearStar1 = Sprite::createWithSpriteFrameName("stage_clear_star.png");
	_stageClearStar1->setPosition(-50, -50);
	_stageClearStar1->setScale(0.5f);
	StarLayer->addChild(_stageClearStar1);

	_stageClearStar2 = Sprite::createWithSpriteFrameName("stage_clear_star.png");
	_stageClearStar2->setPosition(0, -50);
	_stageClearStar2->setScale(0.5f);
	StarLayer->addChild(_stageClearStar2);

	_stageClearStar3 = Sprite::createWithSpriteFrameName("stage_clear_star.png");
	_stageClearStar3->setPosition(50, -50);
	_stageClearStar3->setScale(0.5f);
	StarLayer->addChild(_stageClearStar3);

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

void ServiceScene::StageClear()
{
	if (!_stageClearLight1->getNumberOfRunningActions() && Hero::getInstance()->getStageClear() == true)
	{
		_stageClearBack->runAction(MoveBy::create(0.1, Vec2(0, -320)));

		_stageClearText1->runAction(Spawn::create(MoveBy::create(0.4, Vec2(0, 320)), ScaleBy::create(0.4, 0.5f), nullptr));
		_stageClearText2->runAction(Sequence::create(DelayTime::create(0.1), Spawn::create(MoveBy::create(0.4, Vec2(0, 320)), ScaleBy::create(0.4, 0.5f), nullptr), nullptr));
		_stageClearText3->runAction(Sequence::create(DelayTime::create(0.2), Spawn::create(MoveBy::create(0.4, Vec2(0, 320)), ScaleBy::create(0.4, 0.5f), nullptr), nullptr));
		_stageClearText4->runAction(Sequence::create(DelayTime::create(0.3), Spawn::create(MoveBy::create(0.4, Vec2(0, 320)), ScaleBy::create(0.4, 0.5f), nullptr), nullptr));
		_stageClearText5->runAction(Sequence::create(DelayTime::create(0.4), Spawn::create(MoveBy::create(0.4, Vec2(0, 320)), ScaleBy::create(0.4, 0.5f), nullptr), nullptr));
		_stageClearText6->runAction(Sequence::create(DelayTime::create(0.5), Spawn::create(MoveBy::create(0.4, Vec2(0, 320)), ScaleBy::create(0.4, 0.5f), nullptr), nullptr));
		_stageClearText7->runAction(Sequence::create(DelayTime::create(0.6), Spawn::create(MoveBy::create(0.4, Vec2(0, 320)), ScaleBy::create(0.4, 0.5f), nullptr), nullptr));
		_stageClearText8->runAction(Sequence::create(DelayTime::create(0.7), Spawn::create(MoveBy::create(0.4, Vec2(0, 320)), ScaleBy::create(0.4, 0.5f), nullptr), nullptr));
		_stageClearText9->runAction(Sequence::create(DelayTime::create(0.8), Spawn::create(MoveBy::create(0.4, Vec2(0, 320)), ScaleBy::create(0.4, 0.5f), nullptr), nullptr));
		_stageClearText10->runAction(Sequence::create(DelayTime::create(0.9), Spawn::create(MoveBy::create(0.4, Vec2(0, 320)), ScaleBy::create(0.4, 0.5f), nullptr), nullptr));

		_stageClearCoin->runAction(Sequence::create(DelayTime::create(1.5),CallFunc::create(CC_CALLBACK_0(ServiceScene::CoinVisible,this)),
			ScaleBy::create(0.1, 0.3f), CallFunc::create(CC_CALLBACK_0(ServiceScene::LightVisible, this)), nullptr));

		_stageClearLight1->runAction(RepeatForever::create(RotateBy::create(0.8, Vec3(0, 0,50))));
		_stageClearLight2->runAction(RepeatForever::create(RotateBy::create(0.8, Vec3(0, 0, -50))));
		_stageClearLight3->runAction(RepeatForever::create(RotateBy::create(2, Vec3(0, 0, 120))));

		_stageClearStar1->runAction(Sequence::create(DelayTime::create(1.8), MoveBy::create(0.2, Vec2(0, 160)), nullptr));
		_stageClearStar2->runAction(Sequence::create(DelayTime::create(2.0), MoveBy::create(0.2, Vec2(0, 160)), nullptr));
		_stageClearStar3->runAction(Sequence::create(DelayTime::create(2.2), MoveBy::create(0.2, Vec2(0, 160)), nullptr));

		Hero::getInstance()->setStageClear(false);
	}
}

void ServiceScene::CoinVisible()
{
	_stageClearCoin->setVisible(true);
}

void ServiceScene::LightVisible()
{
	_stageClearLight1->setVisible(true);
	_stageClearLight2->setVisible(true);
	_stageClearLight3->setVisible(true);
}


