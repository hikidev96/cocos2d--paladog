#include "IntroBg.h"

IntroBg::IntroBg() {
  _cache = SpriteFrameCache::getInstance();
  _cache->addSpriteFramesWithFile("Intro/Bg/opening_ending_01.plist");
  _cache->addSpriteFramesWithFile("Intro/Bg/startMapUI/opening_ending_03.plist");
  _cache->addSpriteFramesWithFile("Intro/Bg/opening_ending_04.plist");
  _cache->addSpriteFramesWithFile("Intro/Bg/title_wood.plist");
  _cache->addSpriteFramesWithFile("Player/Unit/u_01_1.plist");

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

  Animation* heroAnimation = Animation::create();
  heroAnimation->setDelayPerUnit(0.03f);
  heroAnimation->addSpriteFrame(_cache->getSpriteFrameByName("hero_wait_0001.png"));
  heroAnimation->addSpriteFrame(_cache->getSpriteFrameByName("hero_wait_0002.png"));
  heroAnimation->addSpriteFrame(_cache->getSpriteFrameByName("hero_wait_0003.png"));
  heroAnimation->addSpriteFrame(_cache->getSpriteFrameByName("hero_wait_0004.png"));
  heroAnimation->addSpriteFrame(_cache->getSpriteFrameByName("hero_wait_0005.png"));
  heroAnimation->addSpriteFrame(_cache->getSpriteFrameByName("hero_wait_0006.png"));
  heroAnimation->addSpriteFrame(_cache->getSpriteFrameByName("hero_wait_0007.png"));
  heroAnimation->addSpriteFrame(_cache->getSpriteFrameByName("hero_wait_0008.png"));
  heroAnimation->addSpriteFrame(_cache->getSpriteFrameByName("hero_wait_0009.png"));
  heroAnimation->addSpriteFrame(_cache->getSpriteFrameByName("hero_wait_0010.png"));
  heroAnimation->addSpriteFrame(_cache->getSpriteFrameByName("hero_wait_0011.png"));
  heroAnimation->addSpriteFrame(_cache->getSpriteFrameByName("hero_wait_0012.png"));
  Animate* heroAnimate = Animate::create(heroAnimation);
  _heroAction = RepeatForever::create(heroAnimate);
  _heroAction->retain();
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

void IntroBg::SetTitleSkyClone(Scene * pScene) {
  _titleSkyClone =
    Sprite::createWithSpriteFrameName("title_sky_02.png");
  _titleSkyClone->setAnchorPoint(Vec2(0, 0));
  _titleSkyClone->setPosition(Vec2(480, 0));
  pScene->addChild(_titleSkyClone);
}

void IntroBg::SetTitleVolcanoCloud(Scene * pScene) {
  _titleVolcanoCloud =
    Sprite::createWithSpriteFrameName("title_volcano_cloud.png");
  _titleVolcanoCloud->setAnchorPoint(Vec2(0, 0));
  _titleVolcanoCloud->setPosition(Vec2(0, 0));
  pScene->addChild(_titleVolcanoCloud);
}

void IntroBg::SetTitleVolcanoCloudClone(Scene * pScene) {
  _titleVolcanoCloudClone =
    Sprite::createWithSpriteFrameName("title_volcano_cloud.png");
  _titleVolcanoCloudClone->setAnchorPoint(Vec2(0, 0));
  _titleVolcanoCloudClone->setPosition(Vec2(-480, 0));
  pScene->addChild(_titleVolcanoCloudClone);
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

  _treeA = Sprite::create("Intro/Bg/tree_A.png");
  _treeA->setAnchorPoint(Vec2(0, 0));
  _treeA->setPosition(Vec2(0, 0));
  pScene->addChild(_treeA);

  _treeB = Sprite::create("Intro/Bg/tree_B.png");
  _treeB->setAnchorPoint(Vec2(0, 0));
  _treeB->setPosition(Vec2(0, 0));
  pScene->addChild(_treeB);
}

void IntroBg::SetHero(Scene * pScene) {
  _hero = Sprite::createWithSpriteFrameName("hero_wait_0001.png");
  _hero->setPosition(70, 300);
  pScene->addChild(_hero);
}
