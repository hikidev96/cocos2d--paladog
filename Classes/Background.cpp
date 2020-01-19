#include "Background.h"

Sprite* Background::_introBg = nullptr;
Sprite* Background::_introVolcanoBg = nullptr;
Sprite* Background::_introSkyBg = nullptr;
Sprite* Background::_introVolcanoCloudBg = nullptr;
Sprite* Background::_introDarkCloudBg = nullptr;
Sprite* Background::_introFaladogLogo = nullptr;
SpriteFrameCache* Background::_cache = SpriteFrameCache::getInstance();
Animation* Background::_introDarkCloudAnimation = nullptr;
Animate* Background::_introDarkCloudAnimate = nullptr;
RepeatForever* Background::_introDarkCloudRepeatForever = nullptr;
Sprite* Background::_introWoodBg = nullptr;
Sprite* Background::_introStoneBg = nullptr;

SpriteFrameCache * Background::GetCache() {
  _cache->addSpriteFramesWithFile("UI/opening_ending_01.plist");
  _cache->addSpriteFramesWithFile("UI/startMapUI/opening_ending_03.plist");
  _cache->addSpriteFramesWithFile("UI/title_wood.plist");
  _cache->addSpriteFramesWithFile("UI/opening_ending_04.plist");

  return _cache;
}

Sprite* Background::GetIntroBackground() {
  _introBg = Sprite::create("UI/15age.png");
  _introBg->setPosition(Vec2(0, 0));
  _introBg->setAnchorPoint(Vec2(0, 0));
  return _introBg;
}

Sprite * Background::GetIntroVolcanoBg() {
  _introVolcanoBg =
    Sprite::createWithSpriteFrameName("title_volcano.png");
  _introVolcanoBg->setAnchorPoint(Vec2(0, 0));
  _introVolcanoBg->setPosition(Vec2(0, 0));
  return _introVolcanoBg;
}

Sprite * Background::GetIntroSkyBg() {
  _introSkyBg =
    Sprite::createWithSpriteFrameName("title_sky_02.png");
  _introSkyBg->setAnchorPoint(Vec2(0, 0));
  _introSkyBg->setPosition(Vec2(0, 0));
  return _introSkyBg;
}

Sprite * Background::GetIntroVolcanoCloudBg() {
  _introVolcanoCloudBg =
    Sprite::createWithSpriteFrameName("title_volcano_cloud.png");
  _introVolcanoCloudBg->setAnchorPoint(Vec2(0, 0));
  _introVolcanoCloudBg->setPosition(Vec2(0, 0));
  return _introVolcanoCloudBg;
}

Sprite * Background::GetIntroDarkCloudBg() {
  _introDarkCloudBg =
    Sprite::createWithSpriteFrameName("title_dark_cloud_00.png");
  _introDarkCloudBg->setAnchorPoint(Vec2(0, 0));
  _introDarkCloudBg->setPosition(Vec2(0, 0));
  
  _introDarkCloudAnimation = Animation::create();
  _introDarkCloudAnimation->setDelayPerUnit(0.06f);
  _introDarkCloudAnimation->
    addSpriteFrame(_cache->getSpriteFrameByName("title_dark_cloud_00.png"));
  _introDarkCloudAnimation->
    addSpriteFrame(_cache->getSpriteFrameByName("title_dark_cloud_01.png"));
  _introDarkCloudAnimation->
    addSpriteFrame(_cache->getSpriteFrameByName("title_dark_cloud_02.png"));
  _introDarkCloudAnimation->
    addSpriteFrame(_cache->getSpriteFrameByName("title_dark_cloud_03.png"));
  _introDarkCloudAnimation->
    addSpriteFrame(_cache->getSpriteFrameByName("title_dark_cloud_04.png"));
  _introDarkCloudAnimation->
    addSpriteFrame(_cache->getSpriteFrameByName("title_dark_cloud_05.png"));

  _introDarkCloudAnimate = Animate::create(_introDarkCloudAnimation);
  _introDarkCloudRepeatForever = RepeatForever::create(_introDarkCloudAnimate);
  _introDarkCloudRepeatForever->retain();

  return _introDarkCloudBg;
}

Sprite * Background::GetIntroLogo() {
  _introFaladogLogo =
    Sprite::createWithSpriteFrameName("title_logo.png");
  _introFaladogLogo->setScale(0.7f);
  _introFaladogLogo->setAnchorPoint(Vec2(-0.4f, -1.7f));
  _introFaladogLogo->setPosition(Vec2(0, 0));
  return _introFaladogLogo;
}

Sprite * Background::GetIntroWoodBg() {
  _introWoodBg =
    Sprite::createWithSpriteFrameName("tree_a_01.png");
  _introWoodBg->setAnchorPoint(Vec2(0, 0));
  _introWoodBg->setPosition(Vec2(0, 0));
  return _introWoodBg;
}

Sprite * Background::GetIntroStoneBg() {
  _introStoneBg =
    Sprite::createWithSpriteFrameName("title_mountain_00.png");
  _introStoneBg->setAnchorPoint(Vec2(0, 0));
  _introStoneBg->setPosition(Vec2(-150, 0));
  return _introStoneBg;
}

//RepeatForever * Background::GetIntroDarkCloudBgRepeatForever() {
//  _introDarkCloudAnimation = Animation::create();
//  _introDarkCloudAnimation->setDelayPerUnit(0.06f);
//  _introDarkCloudAnimation->
//    addSpriteFrame(_cache->getSpriteFrameByName("title_dark_cloud_00.png"));
//  _introDarkCloudAnimation->
//    addSpriteFrame(_cache->getSpriteFrameByName("title_dark_cloud_01.png"));
//  _introDarkCloudAnimation->
//    addSpriteFrame(_cache->getSpriteFrameByName("title_dark_cloud_02.png"));
//  _introDarkCloudAnimation->
//    addSpriteFrame(_cache->getSpriteFrameByName("title_dark_cloud_03.png"));
//  _introDarkCloudAnimation->
//    addSpriteFrame(_cache->getSpriteFrameByName("title_dark_cloud_04.png"));
//  _introDarkCloudAnimation->
//    addSpriteFrame(_cache->getSpriteFrameByName("title_dark_cloud_05.png"));
//
//  _introDarkCloudAnimate = Animate::create(_introDarkCloudAnimation);
//  _introDarkCloudRepeatForever = RepeatForever::create(_introDarkCloudAnimate);
//  _introDarkCloudRepeatForever->retain();
//
//  return _introDarkCloudRepeatForever;
//}
