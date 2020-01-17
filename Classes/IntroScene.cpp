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
  _bgLayer->addChild(Background::GetIntroBackground());
  this->addChild(_bgLayer);

  this->scheduleOnce(schedule_selector(IntroScene::changeIntroBG), 3.0f);
  _bgLayer->removeChild(Background::GetIntroBackground());

  /*_uiLayer = Layer::create();
  _uiLayer->addChild(UI::GetIntroConfigButton());
  _uiLayer->addChild(UI::GetIntroPlayButton());
  this->addChild(_uiLayer);*/

  this->addChild(UI::GetIntroConfigButton());
  this->addChild(UI::GetIntroPlayButton());

  _isSelectPlay = false;
  _isSelectConfig = false;

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

  bool configTouch = UI::GetIntroConfigButton()
    ->getBoundingBox().containsPoint(touchPoint);
  if (configTouch && !_isSelectConfig) {
    /*this->removeChild(_uiLayer);
    _uiLayer = Layer::create();
    _uiLayer->addChild(UI::GetIntroSelectedConfigButton());
    this->addChild(_uiLayer);*/
    this->removeChild(UI::GetIntroConfigButton());
    this->addChild(UI::GetIntroSelectedConfigButton());
    _isSelectConfig = true;

  } else if (configTouch && _isSelectConfig) {
    this->removeChild(UI::GetIntroSelectedConfigButton());
    this->addChild(UI::GetIntroConfigButton());
    _isSelectConfig = false;
  }

  bool playTouch = UI::GetIntroPlayButton()
    ->getBoundingBox().containsPoint(touchPoint);
  if (playTouch && !_isSelectPlay) {
    /*this->removeChild(_uiLayer);
    _uiLayer = Layer::create();
    _uiLayer->addChild(UI::GetIntroSelectedPlayButton());
    this->addChild(_uiLayer);*/
    this->removeChild(UI::GetIntroPlayButton());
    this->addChild(UI::GetIntroSelectedPlayButton());
    this->addChild(UI::GetIntroModeSelectBox());
    _isSelectPlay = true;

  } else if (playTouch&& _isSelectPlay) {
    this->removeChild(UI::GetIntroSelectedPlayButton());
    this->addChild(UI::GetIntroPlayButton());
    _isSelectPlay = false;
  }

  return true;
}

void IntroScene::changeIntroBG(float f) {
  
}
