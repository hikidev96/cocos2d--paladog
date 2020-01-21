#include "IntroScene.h"

Scene* IntroScene::createScene() {
  return IntroScene::create();
}

bool IntroScene::init() {
  if (!Scene::init()) {
    return false;
  }
  
  _introBg = new (std::nothrow) IntroBg;
  _introBg->Set15Age(this);
  
  this->scheduleOnce(schedule_selector(IntroScene::changeBg15AgeToVolcano), 3);

  return true;
}

void IntroScene::onEnter() {
  Scene::onEnter();

  _listener = EventListenerTouchOneByOne::create();
  _listener->onTouchBegan = CC_CALLBACK_2(IntroScene::onTouchBegan, this);
  _listener->onTouchEnded = CC_CALLBACK_2(IntroScene::onTouchEnded, this);
  _listener->setSwallowTouches(true);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
}

void IntroScene::onExit() {
  _eventDispatcher->removeEventListener(_listener);
  
  Scene::onExit();
}

bool IntroScene::onTouchBegan(Touch * touch, Event * event) {
  auto touchPoint = touch->getLocation();

  bool touchPlay = _introUI->GetTitleBtnNewgameUp()->
    getBoundingBox().containsPoint(touchPoint);
  bool touchPaladog = _introUI->GetHeroPaladogUp()->
    getBoundingBox().containsPoint(touchPoint);
  bool touchCampaign = _introUI->GetBtnCampaignUp()->
    getBoundingBox().containsPoint(touchPoint);


  if (touchPlay) {
    log("play");
    _introUI->GetModeSelectBox()->setVisible(true);    
    _introUI->GetHeroPaladogUp()->setVisible(true);
    _introUI->GetHeroDarkdogUp()->setVisible(true);
  }

  if (touchPaladog) {
    log("paladog");
    _introUI->GetBtnCampaignUp()->setVisible(true);
    _introUI->GetBtnSurvivalUp()->setVisible(true);
  }

  if (touchCampaign) {
    log("campaign");
  }

  return true;
}

void IntroScene::onTouchEnded(Touch * touch, Event * event) {
}

void IntroScene::changeBg15AgeToVolcano(float time) {
  this->removeChild(_introBg->Get15Age()); // 이전 화면 제거

  // 배경
  _introBg->SetTitleVolcano(this); // 화산
  _introBg->SetTitleSky(this); // 제일 위에 구름
  _introBg->SetTitleVolcanoCloud(this); // 밑에 구름 
  _introBg->SetTitleDarkCloud(this);
  _introBg->GetTitleDarkCloud()->
    runAction(_introBg->GetTitleDarkCloudAction());
  _introBg->SetTitleDarkCloud2(this);
  _introBg->GetTitleDarkCloud2()->
    runAction(_introBg->GetTitleDarkCloud2Action());
  _introBg->SetTitleMountain(this);
  _introBg->SetTitleMountain2(this);
  _introBg->SetTitleWood(this);

  // UI
  _introUI = new (std::nothrow) IntroUI(this); // UI 객체 추가
  _introUI->SetTitleLogo(this); // 팔라독 로고
  _introUI->SetTitleBtnNewgameUp(this); // PLAY 버튼
  _introUI->SetTitleBtnInfoUp(this); // 설정 버튼

  // 영웅 선택
  _introUI->SetModeSelectBox(this);
  _introUI->GetModeSelectBox()->setVisible(false);
  _introUI->SetHeroPaladogUp(this);
  _introUI->GetHeroPaladogUp()->setVisible(false);
  _introUI->SetHeroDarkdogUp(this);
  _introUI->GetHeroDarkdogUp()->setVisible(false);
  _introUI->SetBtnCampaignUp(this); // 캠페인 버튼
  _introUI->GetBtnCampaignUp()->setVisible(false);
  _introUI->SetBtnSurvivalUp(this);
  _introUI->GetBtnSurvivalUp()->setVisible(false);

  // 슬롯 선택
  _introUI->SetDataSlot(this);
  _introUI->GetDataSlot()->setVisible(false);
}