#include "IntroScene.h"
#include "Background.h"
#include "MainGameScene.h"
//#include "UI.h"

Scene* IntroScene::createScene() {
  return IntroScene::create();
}

bool IntroScene::init() {
  if (!Scene::init()) {
    return false;
  }

  this->addChild(Background::GetIntroBackground());  
  //this->addChild(UI::GetIntroConfigButton());
  //this->addChild(UI::GetIntroPlayButton());

  this->scheduleOnce(schedule_selector(IntroScene::changeIntroBG), 3.0f);
  //this->schedule(schedule_selector(IntroScene::callEveryFrame));

  //_isSelectPlay = false;
  //_isSelectConfig = false;
  //_isChangeScene = false;

  /*if (_isChangeScene) {
  }*/

  return true;
}

//void IntroScene::onEnter() {
//  Scene::onEnter();
//
//  _listener = EventListenerTouchOneByOne::create();
//  _listener->onTouchBegan = CC_CALLBACK_2(IntroScene::onTouchBegan, this);
//  _listener->setSwallowTouches(true);
//  _eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
//}
//
//void IntroScene::onExit() {
//  _eventDispatcher->removeEventListener(_listener);
//
//  Scene::onExit();
//}
//
//bool IntroScene::onTouchBegan(Touch * touch, Event * event) {
//  auto touchPoint = touch->getLocation();
//
//  bool configTouch = UI::GetIntroConfigButton()
//    ->getBoundingBox().containsPoint(touchPoint);
//  if (configTouch && !_isSelectConfig) {
//    this->removeChild(UI::GetIntroConfigButton());
//    this->addChild(UI::GetIntroSelectedConfigButton());
//    _isSelectConfig = true;
//  } 
//
//  bool playTouch = UI::GetIntroPlayButton()
//    ->getBoundingBox().containsPoint(touchPoint);
//  if (playTouch && !_isSelectPlay) {
//    this->removeChild(UI::GetIntroPlayButton());
//    this->addChild(UI::GetIntroSelectedPlayButton());
//    this->addChild(UI::GetIntroModeSelectBox());
//    this->addChild(UI::GetIntroPaladogButton());
//    this->addChild(UI::GetIntroDarkdogButton());
//    _isSelectPlay = true;
//  }
//
//  return true;
//}

void IntroScene::changeIntroBG(float t) {
  auto scene = MainGameScene::createScene();
  Director::getInstance()->replaceScene(scene);
  //log("check");
  //_isChangeScene = true;
}

//void IntroScene::callEveryFrame(float t) {
//  this->addChild(Background::GetIntroDarkCloudBg());
//  log("check");
//}