#include "MainGameScene.h"
#include "Background.h"
#include "UI.h"
#include "MapMindForest.h"

Scene* MainGameScene::createScene() {
  return MainGameScene::create();
}

bool MainGameScene::init() {
  if (!Scene::init()) {
    return false;
  }

  Background::GetCache();
  UI::GetCache();

  this->addChild(Background::GetIntroVolcanoBg());
  this->addChild(Background::GetIntroSkyBg());
  this->addChild(Background::GetIntroVolcanoCloudBg());
  this->addChild(Background::GetIntroDarkCloudBg());
  /*Background::GetIntroDarkCloudBg()->
    runAction(Background::GetIntroDarkCloudBgRepeatForever());*/
  this->addChild(Background::GetIntroStoneBg());
  this->addChild(Background::GetIntroLogo());
  this->addChild(UI::GetIntroConfigButton());
  this->addChild(UI::GetIntroPlayButton());
  
  //this->schedule(schedule_selector(MainGameScene::callEveryFrame));

  _isSelectPlay = false;
  _isSelectConfig = false;
  _isSelectPaladog = false;
  _isSelectDarkdog = false;
  _isSelectCampaign = false;
  _isSelectDataSlot = false;
  _isSelectCancel = false;

  return true;
}

void MainGameScene::onEnter() {
  Scene::onEnter();

  _listener = EventListenerTouchOneByOne::create();
  _listener->onTouchBegan = CC_CALLBACK_2(MainGameScene::onTouchBegan, this);
  _listener->setSwallowTouches(true);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
}

void MainGameScene::onExit() {
  _eventDispatcher->removeEventListener(_listener);

  Scene::onExit();
}

bool MainGameScene::onTouchBegan(Touch * touch, Event * event) {
  auto touchPoint = touch->getLocation();

  bool touchConfig = UI::GetIntroConfigButton()->
    getBoundingBox().containsPoint(touchPoint);
  bool touchPlay = UI::GetIntroPlayButton()->
    getBoundingBox().containsPoint(touchPoint);
  bool touchPaladog = UI::GetIntroPaladogButton()->
    getBoundingBox().containsPoint(touchPoint);
  bool touchDarkdog = UI::GetIntroDarkdogButton()->
    getBoundingBox().containsPoint(touchPoint);
  bool touchCampaign = UI::GetIntroCampaignButton()->
    getBoundingBox().containsPoint(touchPoint);
  bool touchDataSlot = UI::GetIntroDataSlot()->
    getBoundingBox().containsPoint(touchPoint);

  if (touchConfig && !_isSelectConfig) {
    this->removeChild(UI::GetIntroConfigButton());
    this->addChild(UI::GetIntroSelectedConfigButton());
    _isSelectConfig = true;
  } else if (touchConfig && _isSelectConfig) {
    this->removeChild(UI::GetIntroSelectedConfigButton());
    this->addChild(UI::GetIntroConfigButton());
    _isSelectConfig = false;
  }
  
  if (touchPlay && !_isSelectPlay) {
    this->removeAllChildren();
    this->addChild(Background::GetIntroVolcanoBg());
    this->addChild(Background::GetIntroSkyBg());
    this->addChild(Background::GetIntroVolcanoCloudBg());
    this->addChild(Background::GetIntroDarkCloudBg());
    this->addChild(Background::GetIntroStoneBg());
    this->addChild(Background::GetIntroLogo());
    this->addChild(UI::GetIntroConfigButton());
    this->addChild(UI::GetIntroModeSelectBox());
    this->addChild(UI::GetIntroPaladogButton());
    this->addChild(UI::GetIntroDarkdogButton());
    _isSelectPlay = true;

  } else if (touchPaladog && !_isSelectPaladog) {
    _isSelectPaladog = true;
    this->removeAllChildren();
    this->addChild(Background::GetIntroVolcanoBg());
    this->addChild(Background::GetIntroSkyBg());
    this->addChild(Background::GetIntroVolcanoCloudBg());
    this->addChild(Background::GetIntroDarkCloudBg());
    this->addChild(Background::GetIntroStoneBg());
    this->addChild(Background::GetIntroLogo());
    this->addChild(UI::GetIntroConfigButton());
    this->addChild(UI::GetIntroModeSelectBox());
    this->addChild(UI::GetIntroPaladogButton());
    this->addChild(UI::GetIntroCampaignButton());
    this->addChild(UI::GetIntroSurvivalButton());

  } else if (touchDarkdog && !_isSelectDarkdog) {
    _isSelectDarkdog = true;
  }

  if (touchCampaign && !_isSelectCampaign) {
    _isSelectCampaign = true;
    this->removeAllChildren();
    this->addChild(Background::GetIntroVolcanoBg());
    this->addChild(Background::GetIntroSkyBg());
    this->addChild(Background::GetIntroVolcanoCloudBg());
    this->addChild(Background::GetIntroDarkCloudBg());
    this->addChild(Background::GetIntroStoneBg());
    this->addChild(UI::GetIntroMSGBox());
    this->addChild(UI::GetIntroSelectSlot());
    this->addChild(UI::GetIntroDataSlot());
    this->addChild(UI::GetIntroDataSlotBottom());
    //this->addChild(UI::GetIntroCancelButton());

  } else if (touchDataSlot && !_isSelectDataSlot && _isSelectCampaign) {
    _isSelectDataSlot = true;
  } 
  if (_isSelectDataSlot) {
    auto scene = MapMindForest::createScene();
    Director::getInstance()->replaceScene(scene);
  }

  if (!touchPaladog && !touchDarkdog && !touchDataSlot) {
    // 왜 안되는 걸까?
    //this->removeChild(UI::GetIntroModeSelectBox());
    //this->removeChild(UI::GetIntroPaladogButton());
    //this->removeChild(UI::GetIntroDarkdogButton());
    this->removeAllChildren();
    this->addChild(Background::GetIntroVolcanoBg());
    this->addChild(Background::GetIntroSkyBg());
    this->addChild(Background::GetIntroVolcanoCloudBg());
    this->addChild(Background::GetIntroDarkCloudBg());
    this->addChild(Background::GetIntroStoneBg());
    this->addChild(Background::GetIntroLogo());
    this->addChild(UI::GetIntroConfigButton());
    this->addChild(UI::GetIntroPlayButton());
    _isSelectPlay = false;
    _isSelectPaladog = false;
    _isSelectDarkdog = false;
    _isSelectCampaign = false;
    _isSelectDataSlot = false;

  } /*else if (!touchDataSlot && _isSelectDataSlot) {
    this->removeAllChildren();
    this->addChild(Background::GetIntroVolcanoBg());
    this->addChild(Background::GetIntroSkyBg());
    this->addChild(Background::GetIntroVolcanoCloudBg());
    this->addChild(Background::GetIntroDarkCloudBg());
    this->addChild(Background::GetIntroStoneBg());
    this->addChild(Background::GetIntroLogo());
    this->addChild(UI::GetIntroConfigButton());
    this->addChild(UI::GetIntroPlayButton());
    _isSelectPlay = false;
    _isSelectPaladog = false;
    _isSelectDarkdog = false;
    _isSelectCampaign = false;
    _isSelectDataSlot = false;
  }*/

  return true;
}

//void MainGameScene::changeIntroBG(float t) {
//  log("check");
//  this->addChild(Background::GetIntroDarkCloudBg());
//  _isChangeScene = true;
//}

//void MainGameScene::callEveryFrame(float t) {
//  log("check");
//}
