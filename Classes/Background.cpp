#include "Background.h"

Sprite* Background::_introBg = nullptr;
Sprite* Background::_introVolcanoBg = nullptr;
Sprite* Background::_introSkyBg = nullptr;
Sprite* Background::_introVolcanoCloudBg = nullptr;
Sprite* Background::_introDarkCloudBg = nullptr;
Sprite* Background::_introFaladogLogo = nullptr;
SpriteFrameCache* Background::_cache = SpriteFrameCache::getInstance();

Sprite* Background::GetIntroBackground() {
  _introBg = Sprite::create("UI/15age.png");
  _introBg->setPosition(Vec2(0, 0));
  _introBg->setAnchorPoint(Vec2(0, 0));
  return _introBg;
}

Sprite * Background::GetIntroVolcanoBg() {
  _cache->addSpriteFramesWithFile("UI/opening_ending_01.plist");

  _introVolcanoBg =
    Sprite::createWithSpriteFrameName("title_volcano.png");
  _introVolcanoBg->setAnchorPoint(Vec2(0, 0));
  _introVolcanoBg->setPosition(Vec2(0, 0));
  return _introVolcanoBg;
}

Sprite * Background::GetIntroSkyBg() {
  _cache->addSpriteFramesWithFile("UI/opening_ending_01.plist");

  _introSkyBg =
    Sprite::createWithSpriteFrameName("title_sky_02.png");
  _introSkyBg->setAnchorPoint(Vec2(0, 0));
  _introSkyBg->setPosition(Vec2(0, 0));
  return _introSkyBg;
}

Sprite * Background::GetIntroVolcanoCloudBg() {
  _cache->addSpriteFramesWithFile("UI/opening_ending_01.plist");

  _introVolcanoCloudBg =
    Sprite::createWithSpriteFrameName("title_volcano_cloud.png");
  _introVolcanoCloudBg->setAnchorPoint(Vec2(0, 0));
  _introVolcanoCloudBg->setPosition(Vec2(0, 0));
  return _introVolcanoCloudBg;
}

Sprite * Background::GetIntroDarkCloudBg() {
  _cache->addSpriteFramesWithFile("UI/opening_ending_01.plist");

  _introDarkCloudBg =
    Sprite::createWithSpriteFrameName("title_dark_cloud_00.png");
  _introDarkCloudBg->setAnchorPoint(Vec2(0, 0));
  _introDarkCloudBg->setPosition(Vec2(0, 0));
  return _introDarkCloudBg;
}

Sprite * Background::GetIntroLogo() {
  _cache->addSpriteFramesWithFile("UI/startMapUI/opening_ending_03.plist");

  _introFaladogLogo =
    Sprite::createWithSpriteFrameName("title_logo.png");
  _introFaladogLogo->setScale(0.7f);
  _introFaladogLogo->setAnchorPoint(Vec2(-0.4f, -1.7f));
  _introFaladogLogo->setPosition(Vec2(0, 0));
  return _introFaladogLogo;
}

RepeatForever* Background::GetIntroDarkCloudBgRep() {
  _cache->addSpriteFramesWithFile("UI/opening_ending_01.plist");
  Vector<SpriteFrame*> animFrames;
  string _frames = "";
  SpriteFrame* frame = nullptr;

  for (int i = 0; i < 6; i++) {
    _frames = StringUtils::format("title_dark_cloud_%02d.png", i);
    frame = _cache->getSpriteFrameByName(_frames);
    animFrames.pushBack(frame);
  }

  auto animation = Animation::createWithSpriteFrames(animFrames, 0.06f);
  auto animate = Animate::create(animation);
  auto rep = RepeatForever::create(animate);

  return rep;
}
