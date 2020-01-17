#include "cocos_framework.h"
#include "Background.h"

Sprite* Background::_introBg = nullptr;
Sprite* Background::_introSelectBG = nullptr;
SpriteFrameCache* Background::_cache = nullptr;
//Animation* Background::_introDarkCloudAni = nullptr;
//Sprite* Background::_introDarkCloud = nullptr;

Sprite* Background::GetIntroBackground() {
  _introBg = Sprite::create("UI/15age.png");
  _introBg->setPosition(Vec2(0, 0));
  _introBg->setAnchorPoint(Vec2(0, 0));
  return _introBg;
}

Animation* Background::GetIntroDarkCloud() {
  _cache = SpriteFrameCache::getInstance();
  _cache->addSpriteFramesWithFile("opening_ending_01.plist");
  Vector<SpriteFrame*> aniFrames;

  for (int i = 0; i < 6; i++) {
    std::string _frames = StringUtils::format("title_dark_cloud2_%02d.png", i);
    SpriteFrame* frame = _cache->getSpriteFrameByName(_frames);
    aniFrames.pushBack(frame);
  }

  auto sprite = Sprite::createWithSpriteFrameName("title_dark_cloud2_00.png");
  sprite->setPosition(Vec2(240, 160));

  auto animation = Animation::createWithSpriteFrames(aniFrames, 0.06f);

  return animation;

  /*_introDarkCloud = Sprite::createWithSpriteFrameName("title_dark_cloud2_00.png");
  _introDarkCloud->setPosition(Vec2(240, 160));

  _introDarkCloudAni = Animation::createWithSpriteFrames(aniFrames, 0.06f);

  return _introDarkCloudAni;*/
}

Sprite* Background::GetIntroSelectBG() {
  _introSelectBG = Sprite::create("UI/startMapUI/option_msg_02.png");
  _introSelectBG->setTextureRect(Rect(0, 0, 200, 150));
  _introSelectBG->setPosition(Vec2(250, 130));
  return _introSelectBG;
}

Sprite* Background::GetShopBackground() {
  return nullptr;
}

Sprite* Background::GetHeroBackground() {
  return nullptr;
}

Sprite* Background::GetStage1Background() {
  return nullptr;
}

Sprite* Background::GetStage2Background() {
	return nullptr;
}

Sprite* Background::GetStage3Background() {
  return nullptr;
}
