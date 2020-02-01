#include "MapMindForestUI.h"

MapMindForestUI::MapMindForestUI() {
  _cache = SpriteFrameCache::getInstance();
  _cache->addSpriteFramesWithFile("MapMindForest/UI/btn_exit.plist");
  _cache->addSpriteFramesWithFile(
    "MapMindForest/stageSelect/stage_select.plist");
}

void MapMindForestUI::setBtnExit(Scene * pScene) {
  _btnExitUp = Sprite::createWithSpriteFrameName("btn_exit_up.png");
  _btnExitUp->setAnchorPoint(Vec2(0, 0));
  _btnExitUp->setPosition(Vec2(430, 270));
  pScene->addChild(_btnExitUp);
}

void MapMindForestUI::setIconStageLocked(Scene * pScene) {
  for (byte i = 0; i < 24; i++) {
    if (i == 0 || i == 1 || i == 2) {
      continue;
    }
    _iconStageLocked[i] = Sprite::createWithSpriteFrameName(
      "icon_stage_locked.png");
    _iconStageLocked[i]->setAnchorPoint(Vec2(0, 0));
    if (i / 6 == 0) {
      _iconStageLocked[i]->setPosition(Vec2(i * 65 + 45, 200));
    } else if (i / 6 == 1) {
      _iconStageLocked[i]->setPosition(Vec2((i - 6) * 65 + 45, 150));
    } else if (i / 6 == 2) {
      _iconStageLocked[i]->setPosition(Vec2((i - 12) * 65 + 45, 100));
    } else {
      _iconStageLocked[i]->setPosition(Vec2((i - 18) * 65 + 45, 50));
    }
    pScene->addChild(_iconStageLocked[i]);
  }
}

void MapMindForestUI::setNumBoard(Scene * pScene) {
  _numBoard = Sprite::createWithSpriteFrameName("num_board.png");
  _numBoard->setAnchorPoint(Vec2(0, 0));
  _numBoard->setPosition(Vec2(45, 47));
  pScene->addChild(_numBoard);
}

void MapMindForestUI::setStSelPointUp0(Scene * pScene) {
  _stSelPointUp[0] = Sprite::createWithSpriteFrameName("st_sel_point_up.png");
  _stSelPointUp[0]->setScale(0.9f);
  _stSelPointUp[0]->setAnchorPoint(Vec2(0, 0));
  _stSelPointUp[0]->setPosition(Vec2(41, 200));
  pScene->addChild(_stSelPointUp[0]);
}

void MapMindForestUI::setStSelPointUp1(Scene * pScene) {
  _stSelPointUp[1] = Sprite::createWithSpriteFrameName("st_sel_point_up.png");
  _stSelPointUp[1]->setScale(0.9f);
  _stSelPointUp[1]->setAnchorPoint(Vec2(0, 0));
  _stSelPointUp[1]->setPosition(Vec2(109, 200));
  pScene->addChild(_stSelPointUp[1]);
}

void MapMindForestUI::setStSelPointUp2(Scene * pScene) {
  _stSelPointUp[2] = Sprite::createWithSpriteFrameName("st_sel_point_up.png");
  _stSelPointUp[2]->setScale(0.9f);
  _stSelPointUp[2]->setAnchorPoint(Vec2(0, 0));
  _stSelPointUp[2]->setPosition(Vec2(175, 200));
  pScene->addChild(_stSelPointUp[2]);
}

void MapMindForestUI::setUpgrade(Scene * pScene) {
  _upgrade = Sprite::create("MapMindForest/UI/upgrade.png");
  _upgrade->setAnchorPoint(Vec2(0, 0));
  _upgrade->setPosition(Vec2(0, 0));
  pScene->addChild(_upgrade);
}
