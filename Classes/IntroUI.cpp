#include "IntroUI.h"

IntroUI::IntroUI(Scene * pScene) {
  _cache = SpriteFrameCache::getInstance();

  _cache->addSpriteFramesWithFile("Intro/UI/opening_ending_03.plist");
  _cache->addSpriteFramesWithFile("Intro/UI/option_msg_02.plist");
  _cache->addSpriteFramesWithFile("Intro/UI/option_msg_01.plist");
  _cache->addSpriteFramesWithFile("Intro/UI/btn_exit.plist");
}

void IntroUI::SetTitleLogo(Scene * pScene) {
  _titleLogo =
    Sprite::createWithSpriteFrameName("title_logo.png");
  _titleLogo->setScale(0.65f);
  _titleLogo->setAnchorPoint(Vec2(0, 0));
  _titleLogo->setPosition(Vec2(162, 212));
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
  _titleBtnInfoUp->setPosition(Vec2(408, 0));
  pScene->addChild(_titleBtnInfoUp);
}

void IntroUI::SetModeSelectBox(Scene * pScene) {
  _modeSelectBox =
    Sprite::createWithSpriteFrameName("modeselect_box.png");
  _modeSelectBox->setAnchorPoint(Vec2(0, 0));
  _modeSelectBox->setPosition(Vec2(0, 0));
  pScene->addChild(_modeSelectBox);
}

void IntroUI::SetTxtHeroSelect(Scene * pScene) {
  _txtHeroSelect =
    Sprite::createWithSpriteFrameName("txt_heroselect.png");
  _txtHeroSelect->setScale(0.65f);
  _txtHeroSelect->setAnchorPoint(Vec2(0, 0));
  _txtHeroSelect->setPosition(Vec2(56.5f, 150));
  pScene->addChild(_txtHeroSelect);
}

void IntroUI::SetHeroPaladogUp(Scene * pScene) {
  _heroPaladogUp =
    Sprite::createWithSpriteFrameName("hero_paladog_up.png");
  _heroPaladogUp->setScale(0.85f);
  _heroPaladogUp->setAnchorPoint(Vec2(0, 0));
  _heroPaladogUp->setPosition(Vec2(18, 15));
  pScene->addChild(_heroPaladogUp);
}

void IntroUI::SetHeroDarkdogUp(Scene * pScene) {
  _heroDarkdogUp =
    Sprite::createWithSpriteFrameName("hero_darkdog_up.png");
  _heroDarkdogUp->setScale(0.85f);
  _heroDarkdogUp->setAnchorPoint(Vec2(0, 0));
  _heroDarkdogUp->setPosition(Vec2(127, 15));
  pScene->addChild(_heroDarkdogUp);
}

void IntroUI::SetBtnCampaignUp(Scene * pScene) {
  _btnCampaignUp =
    Sprite::createWithSpriteFrameName("btn_campaign_up.png");
  _btnCampaignUp->setScale(0.8f);
  _btnCampaignUp->setAnchorPoint(Vec2(0.5f, 0.5f));
  _btnCampaignUp->setPosition(Vec2(183, 110));
  pScene->addChild(_btnCampaignUp);
}

void IntroUI::SetBtnSurvivalUp(Scene * pScene) {
  _btnSurvivalUp =
    Sprite::createWithSpriteFrameName("btn_survival_up.png");
  _btnSurvivalUp->setScale(0.8f);
  _btnSurvivalUp->setAnchorPoint(Vec2(0.5f, 0.5f));
  _btnSurvivalUp->setPosition(Vec2(183, 47));
  pScene->addChild(_btnSurvivalUp);
}

void IntroUI::SetDataSlot(Scene * pScene) {
  _dataSlot =
    Sprite::createWithSpriteFrameName("data_slot.png");
  _dataSlot->setAnchorPoint(Vec2(0, 0));
  _dataSlot->setPosition(Vec2(150, 180));
  pScene->addChild(_dataSlot);
}

void IntroUI::SetSlotInfoEmpty(Scene * pScene) {
  _slotInfoEmpty =
    Sprite::createWithSpriteFrameName("slot_info_empty.png");
  _slotInfoEmpty->setAnchorPoint(Vec2(0, 0));
  _slotInfoEmpty->setPosition(Vec2(150, 80));
  pScene->addChild(_slotInfoEmpty);
}

void IntroUI::SetMsgSelectSlot(Scene * pScene) {
  _msgSelectSlot =
    Sprite::createWithSpriteFrameName("msg_select_slot.png");
  _msgSelectSlot->setScale(0.7f);
  _msgSelectSlot->setAnchorPoint(Vec2(0, 0));
  _msgSelectSlot->setPosition(Vec2(180, 280));
  pScene->addChild(_msgSelectSlot);
}

void IntroUI::SetBtnExitUp(Scene * pScene) {
  _btnExitUp =
    Sprite::createWithSpriteFrameName("btn_exit_up.png");
  _btnExitUp->setAnchorPoint(Vec2(0, 0));
  _btnExitUp->setPosition(Vec2(438, 275));
  pScene->addChild(_btnExitUp);
}

void IntroUI::SetBtnSlotStartUp(Scene * pScene) {
  _btnSlotStartUp =
    Sprite::createWithSpriteFrameName("btn_slot_start_up.png");
  _btnSlotStartUp->setAnchorPoint(Vec2(0, 0));
  _btnSlotStartUp->setPosition(Vec2(240, 180));
  pScene->addChild(_btnSlotStartUp);
}

void IntroUI::SetBtnSlotDeleteUp(Scene * pScene) {
  _btnSlotDeleteUp =
    Sprite::createWithSpriteFrameName("btn_slot_delete_up.png");
  _btnSlotDeleteUp->setAnchorPoint(Vec2(0, 0));
  _btnSlotDeleteUp->setPosition(Vec2(360, 280));
  pScene->addChild(_btnSlotDeleteUp);
}
