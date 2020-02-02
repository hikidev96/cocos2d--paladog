#include "MapMindForestBg.h"

MapMindForestBg::MapMindForestBg() {
  _cache = SpriteFrameCache::getInstance();
  _cache->addSpriteFramesWithFile(
    "MapMindForest/stageSelect/stage_select.plist");
}

void MapMindForestBg::setPapermap(Scene* pScene) {
  _papermap = Sprite::create("MapMindForest/papermap/papermap.png");
  _papermap->setAnchorPoint(Vec2(0, 0));
  _papermap->setPosition(Vec2(20, 20));
  pScene->addChild(_papermap);
}

void MapMindForestBg::setUnderPapermap(Scene* pScene) {
  _underPapermap = Sprite::create(
    "MapMindForest/papermap/underpapermap.png");
  _underPapermap->setAnchorPoint(Vec2(0, 0));
  _underPapermap->setPosition(Vec2(10, 10));
  pScene->addChild(_underPapermap);
}

void MapMindForestBg::setStSelBoardBottom(Scene * pScene) {
  _stSelBoardBottom = Sprite::createWithSpriteFrameName(
    "st_sel_board_bottom.png");
  _stSelBoardBottom->setAnchorPoint(Vec2(0, 0));
  _stSelBoardBottom->setPosition(Vec2(0, 0));
  pScene->addChild(_stSelBoardBottom);
}

void MapMindForestBg::setStSelBoardLeft(Scene * pScene) {
  _stSelBoardLeft = Sprite::createWithSpriteFrameName(
    "st_sel_board_left.png");
  _stSelBoardLeft->setAnchorPoint(Vec2(0, 0));
  _stSelBoardLeft->setPosition(Vec2(0, 19));
  pScene->addChild(_stSelBoardLeft);
}

void MapMindForestBg::setStSelBoardRight(Scene * pScene) {
  _stSelBoardRight = Sprite::createWithSpriteFrameName(
    "st_sel_board_right.png");
  _stSelBoardRight->setAnchorPoint(Vec2(0, 0));
  _stSelBoardRight->setPosition(Vec2(468, 15));
  pScene->addChild(_stSelBoardRight);
}

void MapMindForestBg::setStSelBoardTop(Scene * pScene) {
  _stSelBoardTop = Sprite::createWithSpriteFrameName(
    "st_sel_board_top.png");
  _stSelBoardTop->setAnchorPoint(Vec2(0, 0));
  _stSelBoardTop->setPosition(Vec2(0, 0));
  pScene->addChild(_stSelBoardTop);
}

void MapMindForestBg::setStSelMapNow(Scene * pScene) {
  _stSelMapNow = Sprite::createWithSpriteFrameName(
    "st_sel_map_now.png");
  _stSelMapNow->setAnchorPoint(Vec2(0, 0));
  _stSelMapNow->setPosition(Vec2(197, 5));
  pScene->addChild(_stSelMapNow);
}

void MapMindForestBg::setStage1IconSmallStar(Scene * pScene) {
  for (byte i = 0; i < 3; i++) {
    _stage1IconSmallStar[i] = Sprite::createWithSpriteFrameName(
      "icon_small_star.png");
    _stage1IconSmallStar[i]->setAnchorPoint(Vec2(0, 0));
    _stage1IconSmallStar[i]->setPosition(Vec2(90, i * 15 + 205));
    pScene->addChild(_stage1IconSmallStar[i]);
  }
}

void MapMindForestBg::setStage2IconSmallStar(Scene * pScene) {
  for (byte i = 0; i < 3; i++) {
    _stage2IconSmallStar[i] = Sprite::createWithSpriteFrameName(
      "icon_small_star.png");
    _stage2IconSmallStar[i]->setAnchorPoint(Vec2(0, 0));
    _stage2IconSmallStar[i]->setPosition(Vec2(155, i * 15 + 205));
    pScene->addChild(_stage2IconSmallStar[i]);
  }
}

void MapMindForestBg::setStage3IconSmallStar(Scene * pScene) {
  for (byte i = 0; i < 3; i++) {
    _stage3IconSmallStar[i] = Sprite::createWithSpriteFrameName(
      "icon_small_star.png");
    _stage3IconSmallStar[i]->setAnchorPoint(Vec2(0, 0));
    _stage3IconSmallStar[i]->setPosition(Vec2(220, i * 15 + 205));
    pScene->addChild(_stage3IconSmallStar[i]);
  }
}
