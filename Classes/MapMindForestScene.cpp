#include "MapMindForestScene.h"
#include "IntroScene.h"
#include "MindForest_Stage1.h"
#include "MindForest_Stage2.h"
#include "MindForest_Stage3.h"

Scene* MapMindForestScene::createScene() {
  return MapMindForestScene::create();
}

bool MapMindForestScene::init() {
  if (!Scene::init()) {
    return false;
  }

  _mapMindForestBg = new (std::nothrow) MapMindForestBg;
  _mapMindForestBg->setUnderPapermap(this);
  _mapMindForestBg->setPapermap(this);
  _mapMindForestBg->setStSelBoardLeft(this);
  _mapMindForestBg->setStSelBoardRight(this);
  _mapMindForestBg->setStSelBoardBottom(this);
  _mapMindForestBg->setStSelBoardTop(this);
  _mapMindForestBg->setStSelMapNow(this);

  _mapMindForestUI = new (std::nothrow) MapMindForestUI;  
  _mapMindForestUI->setBtnExit(this);
  _mapMindForestUI->setNumBoard(this);
  _mapMindForestUI->setIconStageLocked(this);
  _mapMindForestUI->setStSelPointUp0(this);
  _mapMindForestUI->getStSelPointUp0()->setVisible(false);
  _mapMindForestUI->setStSelPointUp1(this);
  _mapMindForestUI->getStSelPointUp1()->setVisible(false);
  _mapMindForestUI->setStSelPointUp2(this);
  _mapMindForestUI->getStSelPointUp2()->setVisible(false);
  _mapMindForestUI->setUpgrade(this);

  // º° Ãß°¡
  if (MindForest_Stage1::_isComplete) {
    _mapMindForestBg->setStage1IconSmallStar(this);
  }
  if (MindForest_Stage2::_isComplete) {
    _mapMindForestBg->setStage2IconSmallStar(this);
  }
  if (MindForest_Stage3::_isComplete) {
    _mapMindForestBg->setStage3IconSmallStar(this);
  }

  return true;
}

void MapMindForestScene::onEnter() {
  Scene::onEnter();

  _listener = EventListenerTouchOneByOne::create();
  _listener->onTouchBegan = CC_CALLBACK_2(
    MapMindForestScene::onTouchBegan, this);

  _listener->setSwallowTouches(true);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(
    _listener, this);
}

void MapMindForestScene::onExit() {
  _eventDispatcher->removeEventListener(_listener);

  Scene::onExit();
}

bool MapMindForestScene::onTouchBegan(Touch * touch, Event * event) {
  auto touchPoint = touch->getLocation();

  bool touchExit = _mapMindForestUI->getBtnExit()->
    getBoundingBox().containsPoint(touchPoint);
  bool touchStage1=_mapMindForestUI->getStSelPointUp0()->
    getBoundingBox().containsPoint(touchPoint);
  bool touchStage2 = _mapMindForestUI->getStSelPointUp1()->
    getBoundingBox().containsPoint(touchPoint);
  bool touchStage3 = _mapMindForestUI->getStSelPointUp2()->
    getBoundingBox().containsPoint(touchPoint);
  bool touchUpgrade = _mapMindForestUI->getUpgrade()->
    getBoundingBox().containsPoint(touchPoint);

  if (touchExit) {
    auto pScene = IntroScene::createScene();
    Director::getInstance()->replaceScene(pScene);
  }

  if (touchStage1) {
    _mapMindForestUI->getStSelPointUp0()->setVisible(true);

    auto pScene = MindForest_Stage1::createScene();
    Director::getInstance()->replaceScene(pScene);
  }

  if (touchStage2) {
    _mapMindForestUI->getStSelPointUp1()->setVisible(true);

    auto pScene = MindForest_Stage2::createScene();
    Director::getInstance()->replaceScene(pScene);
  }

  if (touchStage3) {
    _mapMindForestUI->getStSelPointUp2()->setVisible(true);

    auto pScene = MindForest_Stage3::createScene();
    Director::getInstance()->replaceScene(pScene);
  }

  /*if (touchUpgrade) {
    auto pScene = ::createScene();
    Director::getInstance()->replaceScene(pScene);
  }*/

  return true;
}
