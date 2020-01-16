#include "cocos_framework.h"
#include "IntroScene.h"
#include "Background.h"
#include "UI.h"

Scene* IntroScene::createScene() {
	return IntroScene::create();
}

bool IntroScene::init() {
	if (!Scene::init()) {
		return false;
	}
	
	_bgLayer = Layer::create();
	_bgLayer->addChild(Background::GetIntroBackground()); // 배경 애니메이션 추가할 것
	this->addChild(_bgLayer);
	auto act = Sequence::create(DelayTime::create(2), nullptr);
	this->runAction(act);
	//_bgLayer->removeChild(Background::GetIntroBackground());  

	_uiLayer = Layer::create();
	_uiLayer->addChild(UI::GetIntroConfigButton());
	_uiLayer->addChild(UI::GetIntroPlayButton());
	this->addChild(_uiLayer);

	return true;
}

void IntroScene::onEnter() {
	Scene::onEnter();

	_listener = EventListenerTouchOneByOne::create();
	_listener->onTouchBegan = CC_CALLBACK_2(IntroScene::onTouchBegan, this);
	_listener->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
}

void IntroScene::onExit() {
	_eventDispatcher->removeEventListener(_listener);

	Scene::onExit();
}

bool IntroScene::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event) {
	auto touchPoint = touch->getLocation();

	bool configTouch = UI::GetIntroConfigButton()->getBoundingBox().containsPoint(touchPoint);
	if (configTouch) {
		log("check1");
	}

	bool playTouch = UI::GetIntroPlayButton()->getBoundingBox().containsPoint(touchPoint);
	if (playTouch) {
		log("check2");
	}

	return true;
}

void IntroScene::onTouchCancelled(cocos2d::Touch * touch, cocos2d::Event * event) {
}
