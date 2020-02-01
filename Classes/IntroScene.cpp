#include "IntroScene.h"
#include "MindForest_Stage1.h"

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
  bool touchSurvival = _introUI->GetBtnSurvivalUp()->
    getBoundingBox().containsPoint(touchPoint);
  bool touchExit = _introUI->GetBtnExitUp()->
    getBoundingBox().containsPoint(touchPoint);
  bool touchDataSlot = _introUI->GetDataSlot()->
    getBoundingBox().containsPoint(touchPoint);
  bool touchStart = _introUI->GetStart()->
    getBoundingBox().containsPoint(touchPoint);  

  // Play 버튼 클릭
  if (touchPlay && !_isPlay) {    
    _introUI->GetModeSelectBox()->setVisible(true);
    _introUI->GetTxtHeroSelect()->setVisible(true);
    _introUI->GetHeroPaladogUp()->setVisible(true);
    _introUI->GetHeroDarkdogUp()->setVisible(true);

    _isPlay = true;

    _startSound = AudioEngine::play2d("Sound/start.mp3", false, 0.6f);
  }

  // 팔라독 버튼 클릭
  else if (_isPlay && touchPaladog && !_isPaladog) {
    _introUI->GetHeroDarkdogUp()->setVisible(false);
    _introUI->GetBtnCampaignUp()->setVisible(true);
    _introUI->GetBtnCampaignUp()->runAction(
      Sequence::create(
        RotateBy::create(0.15f, Vec3(0, 90, 0)),
        CallFunc::create(CC_CALLBACK_0(IntroScene::flippedX, this)),
        RotateBy::create(0.15f, Vec3(0, 90, 0)),
        nullptr));
    _introUI->GetBtnSurvivalUp()->setVisible(true);
    _introUI->GetBtnSurvivalUp()->runAction(
      Sequence::create(
        RotateBy::create(0.15f, Vec3(0, 90, 0)),
        RotateBy::create(0.15f, Vec3(0, 90, 0)),
        nullptr));

    _isPaladog = true;

    _okButtonSound = AudioEngine::play2d("Sound/ok_button.mp3", false, 0.6f);
  }

  // Play 버튼 클릭 후 배경 클릭
  if (_isPlay && !touchPaladog && !_isPaladog && !touchCampaign &&
      !_isCampaign && !touchSurvival && !_isSurvival) {
    _introUI->GetModeSelectBox()->setVisible(false);
    _introUI->GetTxtHeroSelect()->setVisible(false);
    _introUI->GetHeroPaladogUp()->setVisible(false);
    _introUI->GetHeroDarkdogUp()->setVisible(false);
    _introUI->GetBtnCampaignUp()->setVisible(false);
    _introUI->GetBtnSurvivalUp()->setVisible(false);
    _introUI->GetTitleBtnNewgameUp()->setVisible(true);
    _introUI->GetTitleBtnInfoUp()->setVisible(true);    

    _isPlay = false;
    _isPaladog = false;

  } else if ((_isPaladog && !touchPaladog) && 
    ((!touchCampaign && !_isCampaign) && (!touchSurvival && !_isSurvival))) {
    _introUI->GetHeroDarkdogUp()->setVisible(true);
    _introUI->GetBtnCampaignUp()->setVisible(false);
    _introUI->GetBtnSurvivalUp()->setVisible(false);
    _introUI->GetBtnCampaignUp()->runAction(
      Sequence::create(
        RotateBy::create(0.15f, Vec3(0, 90, 0)),
        RotateBy::create(0.15f, Vec3(0, 90, 0)),
        nullptr));
    _introUI->GetBtnCampaignUp()->retain();
    _introUI->GetBtnCampaignUp()->setFlippedX(false);
    _introUI->GetBtnSurvivalUp()->runAction(
      Sequence::create(
        RotateBy::create(0.15f, Vec3(0, 90, 0)),
        RotateBy::create(0.15f, Vec3(0, 90, 0)),
        nullptr));
    _introUI->GetBtnSurvivalUp()->retain();
    _introUI->GetBtnSurvivalUp()->setFlippedX(false);

    _isPlay = true;
    _isPaladog = false;
  }

  // 캠페인 버튼 클릭
  if (_isPaladog && touchCampaign && !_isCampaign) {
    _introUI->GetModeSelectBox()->setVisible(false);
    _introUI->GetTxtHeroSelect()->setVisible(false);
    _introUI->GetHeroPaladogUp()->setVisible(false);
    _introUI->GetHeroDarkdogUp()->setVisible(false);
    _introUI->GetTitleLogo()->setVisible(false);
    _introUI->GetTitleBtnNewgameUp()->setVisible(false);
    _introUI->GetTitleBtnInfoUp()->setVisible(false);
    _introUI->GetBtnCampaignUp()->setVisible(false);
    _introUI->GetBtnSurvivalUp()->setVisible(false);
    // 슬롯
    _introUI->GetMsgBox()->setVisible(true);
    _introUI->GetMsgSelectSlot()->setVisible(true);
    _introUI->GetDataSlot()->setVisible(true);
    _introUI->GetSlotInfoEmpty()->setVisible(true);
    _introUI->GetBtnExitUp()->setVisible(true);
    
    _lvLabel = Label::createWithCharMap(
      "Intro/Number/num_wht_13x14.png", 26, 28, 48);
    _lvLabel->setScale(0.7f);
    _lvLabel->setString("0");
    _lvLabel->setPosition(Vec2(220, 202));
    this->addChild(_lvLabel);

    _goldLabel = Label::createWithCharMap(
      "Intro/Number/num_yel_12x15.png", 24, 30, 48);
    _goldLabel->setScale(0.7f);
    _goldLabel->setString("0");
    _goldLabel->setPosition(Vec2(320, 175));
    this->addChild(_goldLabel);

    _hourLabel = Label::createWithCharMap(
      "Intro/Number/num_wht_13x14.png", 26, 28, 48);
    _hourLabel->setScale(0.5f);
    _hourLabel->setString("0");
    _hourLabel->setPosition(Vec2(305, 152));
    this->addChild(_hourLabel);

    _minitueLabel = Label::createWithCharMap(
      "Intro/Number/num_wht_13x14.png", 26, 28, 48);
    _minitueLabel->setScale(0.5f);
    _minitueLabel->setString("0");
    _minitueLabel->setPosition(Vec2(350, 152));
    this->addChild(_minitueLabel);

    _secondLabel = Label::createWithCharMap(
      "Intro/Number/num_wht_13x14.png", 26, 28, 48);
    _secondLabel->setScale(0.5f);
    _secondLabel->setString("0");
    _secondLabel->setPosition(Vec2(400, 152));
    this->addChild(_secondLabel);
    
    _startLabel = Label::createWithCharMap(
      "Intro/Number/num_wht_13x14.png", 26, 28, 48);
    _startLabel->setScale(0.7f);
    _startLabel->setString("0");
    _startLabel->setPosition(Vec2(400, 202));
    this->addChild(_startLabel);

    _isCampaign = true;

    _okButtonSound = AudioEngine::play2d("Sound/ok_button.mp3", false, 0.6f);
  }

  // X 버튼 클릭
  if (_isCampaign && touchExit && !_isExit) {
    _introUI->GetMsgSelectSlot()->setVisible(false);
    _introUI->GetDataSlot()->setVisible(false);
    _introUI->GetDataSlot()->runAction(MoveBy::create(0.15f, Vec2(52, 0)));
    _introUI->GetSlotInfoEmpty()->setVisible(false);
    _introUI->GetBtnExitUp()->setVisible(false);
    _introUI->GetStart()->setVisible(false);
    _introUI->GetDelete()->setVisible(false);
    _introUI->GetMsgBox()->setVisible(false);
    _introUI->GetBtnCampaignUp()->runAction(
      Sequence::create(
        RotateBy::create(0.15f, Vec3(0, 90, 0)),
        RotateBy::create(0.15f, Vec3(0, 90, 0)),
        nullptr));
    _introUI->GetBtnCampaignUp()->retain();
    _introUI->GetBtnCampaignUp()->setFlippedX(false);
    _introUI->GetBtnSurvivalUp()->runAction(
      Sequence::create(
        RotateBy::create(0.15f, Vec3(0, 90, 0)),
        RotateBy::create(0.15f, Vec3(0, 90, 0)),
        nullptr));
    _introUI->GetBtnSurvivalUp()->retain();
    _introUI->GetBtnSurvivalUp()->setFlippedX(false);
    _lvLabel->runAction(MoveBy::create(0.15f, Vec2(52, 0)));
    _lvLabel->setVisible(false);
    _goldLabel->runAction(MoveBy::create(0.15f, Vec2(52, 0)));
    _goldLabel->setVisible(false);
    _hourLabel->runAction(MoveBy::create(0.15f, Vec2(52, 0)));
    _hourLabel->setVisible(false);
    _minitueLabel->runAction(MoveBy::create(0.15f, Vec2(52, 0)));
    _minitueLabel->setVisible(false);
    _secondLabel->runAction(MoveBy::create(0.15f, Vec2(52, 0)));
    _secondLabel->setVisible(false);
    _startLabel->runAction(MoveBy::create(0.15f, Vec2(52, 0)));
    _startLabel->setVisible(false);
    // 초기화면
    _introUI->GetTitleLogo()->setVisible(true);
    _introUI->GetTitleBtnNewgameUp()->setVisible(true);
    _introUI->GetTitleBtnInfoUp()->setVisible(true);

    _isCampaign = false;
    _isExit = false;
    _isPaladog = false;
    _isPlay = false;
    _isDataSlot = false;

    _okButtonSound = AudioEngine::play2d("Sound/ok_button.mp3", false, 0.6f);
  }

  // 슬롯 선택
  if (_isCampaign && touchDataSlot && !_isDataSlot) {
    _lvLabel->runAction(MoveBy::create(0.15f, Vec2(-52, 0)));
    _goldLabel->runAction(MoveBy::create(0.15f, Vec2(-52, 0)));
    _hourLabel->runAction(MoveBy::create(0.15f, Vec2(-52, 0)));
    _minitueLabel->runAction(MoveBy::create(0.15f, Vec2(-52, 0)));
    _secondLabel->runAction(MoveBy::create(0.15f, Vec2(-52, 0)));
    _startLabel->runAction(MoveBy::create(0.15f, Vec2(-52, 0)));
    _introUI->GetDataSlot()->runAction(Sequence::create(
      MoveBy::create(0.15f, Vec2(-52, 0)),
      CallFunc::create(CC_CALLBACK_0(IntroScene::moveBy, this)),
      nullptr));

    _isDataSlot = true;

    _unitActiveSound = AudioEngine::play2d("Sound/unit_active.mp3", false, 0.6f);
  }

  // Start 클릭
  if (_isDataSlot && touchStart && !_isStart) {
    _isStart = true;

    AudioEngine::stop(_bgStageSound);
    // 씬 전환
    auto pScene = MindForest_Stage1::createScene();
    Director::getInstance()->replaceScene(pScene);
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
  _introBg->SetTitleSkyClone(this);
  _introBg->SetTitleVolcanoCloud(this); // 밑에 구름
  _introBg->SetTitleVolcanoCloudClone(this);
  this->schedule(schedule_selector(IntroScene::titleSkyFlow));
  _introBg->SetTitleDarkCloud(this);
  _introBg->GetTitleDarkCloud()->
    runAction(_introBg->GetTitleDarkCloudAction());
  _introBg->SetTitleDarkCloud2(this);
  _introBg->GetTitleDarkCloud2()->
    runAction(_introBg->GetTitleDarkCloud2Action());
  _introBg->SetTitleMountain(this);
  _introBg->SetTitleMountain2(this);  
  _introBg->SetTitleWood(this);
  _introBg->SetHero(this);
  _introBg->GetHero()->runAction(_introBg->GetHeroAction());


  // 배경 UI
  _introUI = new (std::nothrow) IntroUI(this); // UI 객체 추가
  _introUI->SetTitleLogo(this); // 팔라독 로고
  _introUI->SetTitleLogoCrown(this); // 크라운
  _introUI->SetBtnCatUp(this); // 고양이
  _introUI->SetTitleBtnNewgameUp(this); // PLAY 버튼
  _introUI->SetTitleBtnInfoUp(this); // 설정 버튼

  // 영웅 선택
  _introUI->SetModeSelectBox(this);
  _introUI->GetModeSelectBox()->setVisible(false);
  _introUI->SetHeroPaladogUp(this);
  _introUI->GetHeroPaladogUp()->setVisible(false);
  _introUI->SetHeroDarkdogUp(this);
  _introUI->GetHeroDarkdogUp()->setVisible(false);
  _introUI->SetBtnCampaignUp(this);
  _introUI->GetBtnCampaignUp()->setVisible(false);
  _introUI->SetBtnSurvivalUp(this);
  _introUI->GetBtnSurvivalUp()->setVisible(false);
  _introUI->SetTxtHeroSelect(this);
  _introUI->GetTxtHeroSelect()->setVisible(false);

  // 슬롯 선택
  _introUI->SetMsgBox(this);
  _introUI->GetMsgBox()->setVisible(false);
  _introUI->SetMsgSelectSlot(this);
  _introUI->GetMsgSelectSlot()->setVisible(false);
  _introUI->SetStart(this);
  _introUI->GetStart()->setVisible(false);
  _introUI->SetDelete(this);
  _introUI->GetDelete()->setVisible(false);
  _introUI->SetDataSlot(this);
  _introUI->GetDataSlot()->setVisible(false);
  _introUI->SetSlotInfoEmpty(this);
  _introUI->GetSlotInfoEmpty()->setVisible(false);
  _introUI->SetBtnExitUp(this);
  _introUI->GetBtnExitUp()->setVisible(false);

  _isPlay = false;
  _isPaladog = false;
  _isCampaign = false;
  _isSurvival = false;
  _isExit = false;
  _isDataSlot = false;
  _isStart = false;

  // 사운드
  _bgStageSound = AudioEngine::play2d("Sound/bg_stage.mp3", true, 0.6f);    
}

void IntroScene::titleSkyFlow(float time) {
  if (_introBg->GetTitleSky()->getPositionX() <= -480) {
    _introBg->GetTitleSky()->setPositionX(480);

  } else if (_introBg->GetTitleSkyClone()->getPositionX() <= -480) {
    _introBg->GetTitleSkyClone()->setPositionX(480);

  } else {
    _introBg->GetTitleSkyClone()->
      setPositionX(-2.5f +
                   _introBg->GetTitleSkyClone()->getPositionX());
    _introBg->GetTitleSky()->
      setPositionX(-2.5f +
                   _introBg->GetTitleSky()->getPositionX());
  }

  if (_introBg->GetTitleVolcanoCloud()->getPositionX() >= 480) {
    _introBg->GetTitleVolcanoCloud()->setPositionX(-480);

  } else if (_introBg->GetTitleVolcanoCloudClone()->getPositionX() >=
             480) {
    _introBg->GetTitleVolcanoCloudClone()->setPositionX(-480);

  } else {
    _introBg->GetTitleVolcanoCloud()->
      setPositionX(2.5f +
                   _introBg->GetTitleVolcanoCloud()->getPositionX());
    _introBg->GetTitleVolcanoCloudClone()->
      setPositionX(
        2.5f +
        _introBg->GetTitleVolcanoCloudClone()->getPositionX());
  }
}

void IntroScene::flippedX() {
  _introUI->GetBtnCampaignUp()->setFlippedX(true);
  _introUI->GetBtnSurvivalUp()->setFlippedX(true);
}

void IntroScene::moveBy() {
  _introUI->GetStart()->setVisible(true);
  _introUI->GetDelete()->setVisible(true);
}
