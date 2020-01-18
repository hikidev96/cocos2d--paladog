#include "UI.h"

cocos2d::Sprite* UI::_introPlayButton = nullptr;
cocos2d::Sprite* UI::_introSelectedPlayButton = nullptr;

cocos2d::Sprite* UI::_introConfigButton = nullptr;
cocos2d::Sprite* UI::_introSelectedConfigButton = nullptr;

cocos2d::Sprite* UI::_introPaladogButton = nullptr;
cocos2d::Sprite* UI::_introModeSelectBox = nullptr;
cocos2d::SpriteFrameCache* UI::_cache = nullptr;

cocos2d::Sprite* UI::GetIntroPlayButton() {
  _cache = SpriteFrameCache::getInstance();
  _cache->addSpriteFramesWithFile("UI/startMapUI/opening_ending_03.plist");

  _introPlayButton = Sprite::createWithSpriteFrameName("title_btn_newgame_up.png");
  _introPlayButton->setAnchorPoint(Vec2(0, 0));
  _introPlayButton->setPosition(Vec2(0, 0));
  return _introPlayButton;
}

cocos2d::Sprite* UI::GetIntroSelectedPlayButton() {
  _cache = SpriteFrameCache::getInstance();
  _cache->addSpriteFramesWithFile("UI/startMapUI/opening_ending_03.plist");

  _introSelectedPlayButton =
    Sprite::createWithSpriteFrameName("title_btn_newgame_down.png");
  _introSelectedPlayButton->setAnchorPoint(Vec2(0, 0));
  _introSelectedPlayButton->setPosition(Vec2(0, 0));
  return _introSelectedPlayButton;
}

cocos2d::Sprite* UI::GetIntroConfigButton() {
  _cache = SpriteFrameCache::getInstance();
  _cache->addSpriteFramesWithFile("UI/startMapUI/opening_ending_03.plist");

  _introConfigButton = 
    Sprite::createWithSpriteFrameName("title_btn_info_up.png");
  _introConfigButton->setAnchorPoint(Vec2(1, 0));
  _introConfigButton->setPosition(Vec2(480, 0));
  return _introConfigButton;
}

cocos2d::Sprite * UI::GetIntroSelectedConfigButton() {
  _cache = SpriteFrameCache::getInstance();
  _cache->addSpriteFramesWithFile("UI/startMapUI/opening_ending_03.plist");

  _introSelectedConfigButton = 
    Sprite::createWithSpriteFrameName("title_btn_info_down.png");
  _introSelectedConfigButton->setAnchorPoint(Vec2(1, 0));
  _introSelectedConfigButton->setPosition(Vec2(480, 0));
  return _introSelectedConfigButton;
}

cocos2d::Sprite* UI::GetIntroModeSelectBox() {
  _cache = SpriteFrameCache::getInstance();
  _cache->addSpriteFramesWithFile("UI/startMapUI/option_msg_02.plist");

  _introModeSelectBox =
    Sprite::createWithSpriteFrameName("modeselect_box.png");
  _introModeSelectBox->setAnchorPoint(Vec2(1, 0));
  _introModeSelectBox->setPosition(Vec2(480, 0));
  return _introModeSelectBox;
}
