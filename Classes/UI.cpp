#include "UI.h"

Sprite* UI::_introPlayButton = nullptr;
Sprite* UI::_introSelectedPlayButton = nullptr;
Sprite* UI::_introConfigButton = nullptr;
Sprite* UI::_introSelectedConfigButton = nullptr;

SpriteFrameCache* UI::_cache = SpriteFrameCache::getInstance();
Sprite* UI::_introModeSelectBox = nullptr;
Sprite* UI::_introPaladogButton = nullptr;
Sprite* UI::_introDarkdogButton = nullptr;
Sprite* UI::_introCampaignButton = nullptr;
Sprite* UI::_introSurvivalButton = nullptr;
Sprite* UI::_introSelectSlot = nullptr;
Sprite* UI::_introDataSlot = nullptr;
Sprite* UI::_introMSGBox = nullptr;
Sprite* UI::_introDataSlotBottom = nullptr;
Sprite* UI::_introCancelButton = nullptr;

SpriteFrameCache * UI::GetCache() {
  _cache->addSpriteFramesWithFile("UI/startMapUI/opening_ending_03.plist");
  _cache->addSpriteFramesWithFile("UI/startMapUI/option_msg_02.plist");
  _cache->addSpriteFramesWithFile("UI/startMapUI/option_msg_01.plist");
  _cache->addSpriteFramesWithFile("UI/button/btn_exit.plist");

  return _cache;
}

Sprite* UI::GetIntroPlayButton() {
  _introPlayButton = Sprite::createWithSpriteFrameName("title_btn_newgame_up.png");
  _introPlayButton->setAnchorPoint(Vec2(0, 0));
  _introPlayButton->setPosition(Vec2(0, 0));
  return _introPlayButton;
}

Sprite* UI::GetIntroSelectedPlayButton() {
  _introSelectedPlayButton =
    Sprite::createWithSpriteFrameName("title_btn_newgame_down.png");
  _introSelectedPlayButton->setAnchorPoint(Vec2(0, 0));
  _introSelectedPlayButton->setPosition(Vec2(0, 0));
  return _introSelectedPlayButton;
}

Sprite* UI::GetIntroConfigButton() {
  _introConfigButton = 
    Sprite::createWithSpriteFrameName("title_btn_info_up.png");
  _introConfigButton->setAnchorPoint(Vec2(1, 0));
  _introConfigButton->setPosition(Vec2(480, 0));
  return _introConfigButton;
}

Sprite * UI::GetIntroSelectedConfigButton() {
  _introSelectedConfigButton = 
    Sprite::createWithSpriteFrameName("title_btn_info_down.png");
  _introSelectedConfigButton->setAnchorPoint(Vec2(1, 0));
  _introSelectedConfigButton->setPosition(Vec2(480, 0));
  return _introSelectedConfigButton;
}

Sprite* UI::GetIntroModeSelectBox() {
  _introModeSelectBox =
    Sprite::createWithSpriteFrameName("modeselect_box.png");
  _introModeSelectBox->setAnchorPoint(Vec2(1, 0));
  _introModeSelectBox->setPosition(Vec2(480, 0));
  return _introModeSelectBox;
}

Sprite * UI::GetIntroPaladogButton() {
  _introPaladogButton =
    Sprite::createWithSpriteFrameName("hero_paladog_up.png");
  _introPaladogButton->setScale(0.85f);
  _introPaladogButton->setAnchorPoint(Vec2(0, 0));
  _introPaladogButton->setPosition(Vec2(24, 23));
  return _introPaladogButton;
}

Sprite * UI::GetIntroDarkdogButton() {
  _introDarkdogButton =
    Sprite::createWithSpriteFrameName("hero_darkdog_up.png");
  _introDarkdogButton->setScale(0.85f);
  _introDarkdogButton->setAnchorPoint(Vec2(0, 0));
  _introDarkdogButton->setPosition(Vec2(134, 23));
  return _introDarkdogButton;
}

Sprite * UI::GetIntroCampaignButton() {
  _introCampaignButton =
    Sprite::createWithSpriteFrameName("btn_campaign_up.png");
  _introCampaignButton->setScale(0.8f);
  _introCampaignButton->setAnchorPoint(Vec2(0, 0));
  _introCampaignButton->setPosition(Vec2(134, 85));
  return _introCampaignButton;
}

Sprite * UI::GetIntroSurvivalButton() {
  _introSurvivalButton =
    Sprite::createWithSpriteFrameName("btn_survival_up.png");
  _introSurvivalButton->setScale(0.8f);
  _introSurvivalButton->setAnchorPoint(Vec2(0, 0));
  _introSurvivalButton->setPosition(Vec2(134, 24));
  return _introSurvivalButton;
}

Sprite* UI::GetIntroSelectSlot() {
  _introSelectSlot =
    Sprite::createWithSpriteFrameName("msg_select_slot.png");
  _introSelectSlot->setScale(0.9f);
  _introSelectSlot->setAnchorPoint(Vec2(0, 0));
  _introSelectSlot->setPosition(Vec2(45, 20));
  return _introSelectSlot;
}

Sprite * UI::GetIntroDataSlot() {
  _introDataSlot =
    Sprite::createWithSpriteFrameName("data_slot.png");
  _introDataSlot->setAnchorPoint(Vec2(0, 0));
  _introDataSlot->setPosition(Vec2(-5, -35));
  return _introDataSlot;
}

Sprite * UI::GetIntroDataSlotBottom() {
  _introDataSlotBottom =
    Sprite::createWithSpriteFrameName("slot_info_empty.png");
  _introDataSlotBottom->setAnchorPoint(Vec2(0, 0));
  _introDataSlotBottom->setPosition(Vec2(-5, -130));
  return _introDataSlotBottom;
}

Sprite * UI::GetIntroMSGBox() {
  _introMSGBox =
    Sprite::createWithSpriteFrameName("msg_box_01.png");
  _introMSGBox->setFlippedY(true);
  _introMSGBox->setScaleX(1.1f);
  _introMSGBox->setAnchorPoint(Vec2(0, 0));
  _introMSGBox->setPosition(Vec2(45, 65));
  return _introMSGBox;
}

Sprite * UI::GetIntroCancelButton() {
  _introCancelButton =
    Sprite::createWithSpriteFrameName("btn_exit_up.png");
  _introCancelButton->setAnchorPoint(Vec2(0, 0));
  _introCancelButton->setPosition(Vec2(0, 0));
  return _introCancelButton;
}

//Sprite * UI::GetIntroMSGBoxBottom() {
//  _introMSGBoxBottom =
//    Sprite::createWithSpriteFrameName("msg_box_01.png");
//  _introMSGBoxBottom->setScaleX(1.1f);
//  _introMSGBoxBottom->setAnchorPoint(Vec2(0, 0));
//  _introMSGBoxBottom->setPosition(Vec2(45, 0));
//  return _introMSGBoxBottom;
//}
