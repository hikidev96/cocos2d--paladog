#include "Background.h"

Sprite* Background::_introBg = nullptr;
SpriteFrameCache* Background::_introAniCache = nullptr;
Sprite* Background::_introSelectBG = nullptr;

Sprite* Background::GetIntroBackground() {
  _introBg = Sprite::create("UI/15age.png");
  _introBg->setPosition(Vec2(0, 0));
  _introBg->setAnchorPoint(Vec2(0, 0));
  return _introBg;
}

RepeatForever* Background::GetIntroAnimation() {
  _introAniCache = SpriteFrameCache::getInstance();
  _introAniCache->addSpriteFramesWithFile("opening_ending_01.plist");
  Vector<SpriteFrame*> aniFrames;

  for (int i = 1; i < 10; i++) {
    std::string _frames = StringUtils::format("", i);
    SpriteFrame* frame = _introAniCache->getSpriteFrameByName(_frames);
    aniFrames.pushBack(frame);
  }

  auto sprite = Sprite::createWithSpriteFrameName("");
  sprite->setPosition(Vec2(840, 360));

  auto animation = Animation::createWithSpriteFrames(aniFrames, 0.06f);
  auto animate = Animate::create(animation);
  auto rep = RepeatForever::create(animate);

  return rep;
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
