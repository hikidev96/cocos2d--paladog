#include "IntroUI.h"

IntroUI::IntroUI(Scene * pScene) {
  _cache = SpriteFrameCache::getInstance();

  _cache->addSpriteFramesWithFile("Intro/UI/opening_ending_03.plist");
  _cache->addSpriteFramesWithFile("Intro/UI/option_msg_02.plist");
  _cache->addSpriteFramesWithFile("Intro/UI/option_msg_01.plist");


}

void IntroUI::SetTitleLogo(Scene * pScene) {
  _titleLogo =
    Sprite::createWithSpriteFrameName("title_logo.png");
  _titleLogo->setAnchorPoint(Vec2(0, 0));
  _titleLogo->setPosition(Vec2(0, 0));
  pScene->addChild(_titleLogo);
}

void IntroUI::SetTitleBtnNewgameUp(Scene * pScene) {
  _titleBtnNewgameUp = Sprite::createWithSpriteFrameName("title_btn_newgame_up.png");
  _titleBtnNewgameUp->setAnchorPoint(Vec2(0, 0));
  _titleBtnNewgameUp->setPosition(Vec2(0, 0));
  pScene->addChild(_titleBtnNewgameUp);
}

void IntroUI::SetTitleBtnInfoUp(Scene * pScene) {
  _titleBtnInfoUp = Sprite::createWithSpriteFrameName("title_btn_info_up.png");
  _titleBtnInfoUp->setAnchorPoint(Vec2(0, 0));
  _titleBtnInfoUp->setPosition(Vec2(0, 0));
  pScene->addChild(_titleBtnInfoUp);
}

Sprite* IntroUI::GetIntroModeSelectBox() {
  _introModeSelectBox =
    Sprite::createWithSpriteFrameName("modeselect_box.png");
  _introModeSelectBox->setAnchorPoint(Vec2(1, 0));
  _introModeSelectBox->setPosition(Vec2(480, 0));
  return _introModeSelectBox;
}

Sprite * IntroUI::GetIntroPaladogButton() {
  _introPaladogButton =
    Sprite::createWithSpriteFrameName("hero_paladog_up.png");
  _introPaladogButton->setScale(0.85f);
  _introPaladogButton->setAnchorPoint(Vec2(0, 0));
  _introPaladogButton->setPosition(Vec2(24, 23));
  return _introPaladogButton;
}

Sprite * IntroUI::GetIntroDarkdogButton() {
  _introDarkdogButton =
    Sprite::createWithSpriteFrameName("hero_darkdog_up.png");
  _introDarkdogButton->setScale(0.85f);
  _introDarkdogButton->setAnchorPoint(Vec2(0, 0));
  _introDarkdogButton->setPosition(Vec2(134, 23));
  return _introDarkdogButton;
}

Sprite * IntroUI::GetIntroCampaignButton() {
  _introCampaignButton =
    Sprite::createWithSpriteFrameName("btn_campaign_up.png");
  _introCampaignButton->setScale(0.8f);
  _introCampaignButton->setAnchorPoint(Vec2(0, 0));
  _introCampaignButton->setPosition(Vec2(134, 85));
  return _introCampaignButton;
}

Sprite * IntroUI::GetIntroSurvivalButton() {
  _introSurvivalButton =
    Sprite::createWithSpriteFrameName("btn_survival_up.png");
  _introSurvivalButton->setScale(0.8f);
  _introSurvivalButton->setAnchorPoint(Vec2(0, 0));
  _introSurvivalButton->setPosition(Vec2(134, 24));
  return _introSurvivalButton;
}

Sprite* IntroUI::GetIntroSelectSlot() {
  _introSelectSlot =
    Sprite::createWithSpriteFrameName("msg_select_slot.png");
  _introSelectSlot->setScale(0.9f);
  _introSelectSlot->setAnchorPoint(Vec2(0, 0));
  _introSelectSlot->setPosition(Vec2(45, 20));
  return _introSelectSlot;
}

Sprite * IntroUI::GetIntroDataSlot() {
  _introDataSlot =
    Sprite::createWithSpriteFrameName("data_slot.png");
  _introDataSlot->setAnchorPoint(Vec2(0, 0));
  _introDataSlot->setPosition(Vec2(-5, -35));
  return _introDataSlot;
}

Sprite * IntroUI::GetIntroDataSlotBottom() {
  _introDataSlotBottom =
    Sprite::createWithSpriteFrameName("slot_info_empty.png");
  _introDataSlotBottom->setAnchorPoint(Vec2(0, 0));
  _introDataSlotBottom->setPosition(Vec2(-5, -130));
  return _introDataSlotBottom;
}

Sprite * IntroUI::GetIntroMSGBox() {
  _introMSGBox =
    Sprite::createWithSpriteFrameName("msg_box_01.png");
  _introMSGBox->setFlippedY(true);
  _introMSGBox->setScaleX(1.1f);
  _introMSGBox->setAnchorPoint(Vec2(0, 0));
  _introMSGBox->setPosition(Vec2(45, 65));
  return _introMSGBox;
}