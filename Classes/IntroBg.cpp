#include "IntroBg.h"

IntroBg::IntroBg() {
  _cache = SpriteFrameCache::getInstance();
  _cache->addSpriteFramesWithFile("Intro/Bg/opening_ending_01.plist");
  _cache->addSpriteFramesWithFile("Intro/Bg/startMapUI/opening_ending_03.plist");
  _cache->addSpriteFramesWithFile("Intro/Bg/opening_ending_04.plist");
  _cache->addSpriteFramesWithFile("Intro/Bg/title_wood.plist");

  // 구름 애니메이션
  Animation* titleDarkCloudAnimation1 = Animation::create();
  titleDarkCloudAnimation1->setDelayPerUnit(0.1f);
  titleDarkCloudAnimation1->
    addSpriteFrame(_cache->getSpriteFrameByName("title_dark_cloud_00.png"));
  titleDarkCloudAnimation1->
    addSpriteFrame(_cache->getSpriteFrameByName("title_dark_cloud_01.png"));
  titleDarkCloudAnimation1->
    addSpriteFrame(_cache->getSpriteFrameByName("title_dark_cloud_02.png"));
  titleDarkCloudAnimation1->
    addSpriteFrame(_cache->getSpriteFrameByName("title_dark_cloud_03.png"));
  titleDarkCloudAnimation1->
    addSpriteFrame(_cache->getSpriteFrameByName("title_dark_cloud_04.png"));
  titleDarkCloudAnimation1->
    addSpriteFrame(_cache->getSpriteFrameByName("title_dark_cloud_05.png"));
  Animate* titleDarkCloudAnimate1 = Animate::create(titleDarkCloudAnimation1);
  _titleDarkCloudAction = RepeatForever::create(titleDarkCloudAnimate1);
  _titleDarkCloudAction->retain();

  // 화산 애니메이션
  Animation* titleDarkCloudAnimation2 = Animation::create();
  titleDarkCloudAnimation2->setDelayPerUnit(0.1f);
  titleDarkCloudAnimation2->
    addSpriteFrame(_cache->getSpriteFrameByName("title_dark_cloud2_00.png"));
  titleDarkCloudAnimation2->
    addSpriteFrame(_cache->getSpriteFrameByName("title_dark_cloud2_01.png"));
  titleDarkCloudAnimation2->
    addSpriteFrame(_cache->getSpriteFrameByName("title_dark_cloud2_02.png"));
  titleDarkCloudAnimation2->
    addSpriteFrame(_cache->getSpriteFrameByName("title_dark_cloud2_03.png"));
  titleDarkCloudAnimation2->
    addSpriteFrame(_cache->getSpriteFrameByName("title_dark_cloud2_04.png"));
  titleDarkCloudAnimation2->
    addSpriteFrame(_cache->getSpriteFrameByName("title_dark_cloud2_05.png"));
  Animate* titleDarkCloudAnimate2 = Animate::create(titleDarkCloudAnimation2);
  _titleDarkCloudAction2 = RepeatForever::create(titleDarkCloudAnimate2);
  _titleDarkCloudAction2->retain();
}

void IntroBg::Set15Age(Scene * pScene) {
  _15Age = Sprite::create("Intro/Bg/15age.png");
  _15Age->setPosition(Vec2(0, 0));
  _15Age->setAnchorPoint(Vec2(0, 0));
  pScene->addChild(_15Age);
}

void IntroBg::SetTitleVolcano(Scene * pScene) {
  _titleVolcano =
    Sprite::createWithSpriteFrameName("title_volcano.png");
  _titleVolcano->setAnchorPoint(Vec2(0, 0));
  _titleVolcano->setPosition(Vec2(0, 0));
  pScene->addChild(_titleVolcano);
}

void IntroBg::SetTitleSky(Scene * pScene) {
  _titleSky =
    Sprite::createWithSpriteFrameName("title_sky_02.png");
  _titleSky->setAnchorPoint(Vec2(0, 0));
  _titleSky->setPosition(Vec2(0, 0));
  pScene->addChild(_titleSky);
}

void IntroBg::SetTitleVolcanoCloud(Scene * pScene) {
  _titleVolcanoCloud =
    Sprite::createWithSpriteFrameName("title_volcano_cloud.png");
  _titleVolcanoCloud->setAnchorPoint(Vec2(0, 0));
  _titleVolcanoCloud->setPosition(Vec2(0, 0));
  pScene->addChild(_titleVolcanoCloud);
}

void IntroBg::SetTitleDarkCloud(Scene* pScene) {
  _titleDarkCloud =
    Sprite::createWithSpriteFrameName("title_dark_cloud_00.png");
  _titleDarkCloud->setAnchorPoint(Vec2(0, 0));
  _titleDarkCloud->setPosition(Vec2(0, 0));
  pScene->addChild(_titleDarkCloud);
}

void IntroBg::SetTitleDarkCloud2(Scene * pScene) {
  _titleDarkCloud2 = 
    Sprite::createWithSpriteFrameName("title_dark_cloud2_00.png");
  _titleDarkCloud2->setAnchorPoint(Vec2(0, 0));
  _titleDarkCloud2->setPosition(Vec2(0, 0));
  pScene->addChild(_titleDarkCloud2);
}

void IntroBg::SetTitleMountain(Scene * pScene) {
  _titleMountain = Sprite::createWithSpriteFrameName("title_mountain_00.png");
  _titleMountain->setAnchorPoint(Vec2(0, 0));
  _titleMountain->setPosition(Vec2(-110, 0));
  pScene->addChild(_titleMountain);
}

void IntroBg::SetTitleMountain2(Scene * pScene) {
  _titleMountain2 =
    Sprite::createWithSpriteFrameName("title_mountain_01.png");
  _titleMountain2->setAnchorPoint(Vec2(0, 0));
  _titleMountain2->setPosition(Vec2(345, 0));
  pScene->addChild(_titleMountain2);
}

void IntroBg::SetTitleWood(Scene * pScene) {
  _woodL = Sprite::createWithSpriteFrameName("wood_l.png");
  _woodL->setAnchorPoint(Vec2(0, 0));
  _woodL->setPosition(Vec2(0, 0));
  pScene->addChild(_woodL);

  _woodR = Sprite::createWithSpriteFrameName("wood_r.png");
  _woodR->setAnchorPoint(Vec2(0, 0));
  _woodR->setPosition(Vec2(0, 0));
  pScene->addChild(_woodR);

  _treeA[0] = Sprite::createWithSpriteFrameName("tree_a_01.png");
  _treeA[1] = Sprite::createWithSpriteFrameName("tree_a_02.png");
  _treeA[2] = Sprite::createWithSpriteFrameName("tree_a_03.png");
  _treeA[3] = Sprite::createWithSpriteFrameName("tree_a_04.png");
  _treeB[0] = Sprite::createWithSpriteFrameName("tree_b_01.png");
  _treeB[1] = Sprite::createWithSpriteFrameName("tree_b_02.png");
  _treeB[2] = Sprite::createWithSpriteFrameName("tree_b_03.png");
  _treeB[3] = Sprite::createWithSpriteFrameName("tree_b_04.png");
  _treeC[0] = Sprite::createWithSpriteFrameName("tree_c_01.png");
  _treeC[1] = Sprite::createWithSpriteFrameName("tree_c_02.png");
  _treeC[2] = Sprite::createWithSpriteFrameName("tree_c_03.png");
  _treeC[3] = Sprite::createWithSpriteFrameName("tree_c_04.png");
  for (byte i = 0; i < 4; i++) {
    _treeA[i]->setAnchorPoint(Vec2(0, 0));
    _treeA[i]->setPosition(Vec2(0, 0));
    _treeB[i]->setAnchorPoint(Vec2(0, 0));
    _treeB[i]->setPosition(Vec2(0, 0));
    _treeC[i]->setAnchorPoint(Vec2(0, 0));
    _treeC[i]->setPosition(Vec2(0, 0));
    pScene->addChild(_treeA[i]);
    pScene->addChild(_treeB[i]);
    pScene->addChild(_treeC[i]);
  }
}