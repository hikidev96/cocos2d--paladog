#include "HeroControl.h"

HeroControl::HeroControl(Scene* scene, Layer* layer, Dungeon* dungeon)
{
	_scene = scene; // Scene 메모리주소 받아오기
	_layer = layer; // layer 메모리주소 받아오기
	_dungeon = dungeon; // dungeon 메모리 주소 받아오기

	cache = SpriteFrameCache::getInstance(); // 캐쉬생성
	cache->addSpriteFramesWithFile("UI/ui_gameplay.plist"); // plist 추가
	cache->addSpriteFramesWithFile("Player/UNIT_B~1/btn_unit-hd.plist"); // plist 추가
	cache->addSpriteFramesWithFile("Player/Level up/eff_levelup.plist"); // plist 추가
	cache->addSpriteFramesWithFile("UI/game_info/ui_game_info.plist"); // plist 추가
	cache->addSpriteFramesWithFile("UI/game_info/btn_pause.plist"); // plist 추가
	cache->addSpriteFramesWithFile("UI/game_info/ui_game_info.plist"); // plist 추가
	cache->addSpriteFramesWithFile("Player/weapons/m01_1.plist"); // plist 추가
	cache->addSpriteFramesWithFile("UI/startMapUI/result.plist"); // plist 추가
	cache->addSpriteFramesWithFile("Player/pause button/game_option.plist"); // plist 추가

	// 리스너 등록
	listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HeroControl::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HeroControl::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HeroControl::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, _scene);

	// 히어로 조작 스프라이트
	_leftButton = Sprite::createWithSpriteFrameName("btn_left_up.png");
	_leftButton->setAnchorPoint({ 0,0 });
	_leftButton->setPosition({ 10,5 });
	_rightButton = Sprite::createWithSpriteFrameName("btn_right_up.png");
	_rightButton->setAnchorPoint({ 0,0 });
	_rightButton->setPosition({ 125,5 });
		
	// 대쉬보드 스프라이트
	_mainDashbord = Sprite::createWithSpriteFrameName("ui_game_dashboard.png");
	_mainDashbord->setAnchorPoint({ 0,0 });
	_mainDashbord->setPosition({ 0,0 });
	_mainDashbordCase = Sprite::createWithSpriteFrameName("ui_macebtn_case.png");
	_mainDashbordCase->setAnchorPoint({ 0,0 });
	_mainDashbordCase->setPosition({ 237,2 });

	// 스킬 1,2,3 버튼 스프라이트
	_skillOneButton = Sprite::create("MACEBU~1/mace1/mace1_button_black.png");
	_skillOneButton->setAnchorPoint({ 0,0 });
	_skillOneButton->setPosition({ 256,5 });
	_skillTwoButton = Sprite::createWithSpriteFrameName("btn_heal_up.png");
	_skillTwoButton->setAnchorPoint({ 0,0 });
	_skillTwoButton->setPosition({ 333,5 });
	_skillThreeButton = Sprite::createWithSpriteFrameName("btn_turnundead_up.png");
	_skillThreeButton->setAnchorPoint({ 0,0 });
	_skillThreeButton->setPosition({ 407,5 });

	// 생쉬 소환 버튼
	_mouseSummonsButton = Sprite::createWithSpriteFrameName("btn_unit_00_disable.png");
	_mouseSummonsButton->setAnchorPoint({ 0,0 });
	_mouseSummonsButton->setPosition({ 10,55 });
	_mouseSummonsButton->setScale(0.5f);
	_mouseSummonsButton->setScaleY(0.48f);
	_scene->addChild(_mouseSummonsButton, 1);

	_mouseSummonsButtonDisable = Sprite::createWithSpriteFrameName("btn_unit_00_disable.png");
	_mouseSummonsButtonDisable->setColor(Color3B::BLACK);

	// 곰 소환 버튼
	_bearSummonsButton = Sprite::createWithSpriteFrameName("btn_unit_02_disable.png");
	_bearSummonsButton->setAnchorPoint({ 0,0 });
	_bearSummonsButton->setPosition({ 61,55 });
	_bearSummonsButton->setScale(0.5f);
	_bearSummonsButton->setScaleY(0.48f);
	_scene->addChild(_bearSummonsButton, 1);

	_bearSummonsButtonDisable = Sprite::createWithSpriteFrameName("btn_unit_02_disable.png");
	_bearSummonsButtonDisable->setColor(Color3B::BLACK);

	// 캥거루 소환 버튼
	_kangarooSummonsButton = Sprite::createWithSpriteFrameName("btn_unit_03_disable.png");
	_kangarooSummonsButton->setAnchorPoint({ 0,0 });
	_kangarooSummonsButton->setPosition({ 112,55 });
	_kangarooSummonsButton->setScale(0.5f);
	_kangarooSummonsButton->setScaleY(0.48f);
	_scene->addChild(_kangarooSummonsButton, 1);

	_kangarooSummonsButtonDisable = Sprite::createWithSpriteFrameName("btn_unit_03_disable.png");
	_kangarooSummonsButtonDisable->setColor(Color3B::BLACK);

	// 소환 버튼 잠김
	_unitLock1 = Sprite::createWithSpriteFrameName("btn_unit_lock.png");
	_unitLock1->setAnchorPoint({ 0, 0 });
	_unitLock1->setPosition({ 163,55 });
	_unitLock1->setScale(0.5f);
	_unitLock1->setScaleY(0.48f);
	_scene->addChild(_unitLock1, 1);

	_unitLock2 = Sprite::createWithSpriteFrameName("btn_unit_lock.png");
	_unitLock2->setAnchorPoint({ 0, 0 });
	_unitLock2->setPosition({ 214,55 });
	_unitLock2->setScale(0.5f);
	_unitLock2->setScaleY(0.48f);
	_scene->addChild(_unitLock2, 1);

	_unitLock3 = Sprite::createWithSpriteFrameName("btn_unit_lock.png");
	_unitLock3->setAnchorPoint({ 0, 0 });
	_unitLock3->setPosition({ 265,55 });
	_unitLock3->setScale(0.5f);
	_unitLock3->setScaleY(0.48f);
	_scene->addChild(_unitLock3, 1);

	_unitLock4 = Sprite::createWithSpriteFrameName("btn_unit_lock.png");
	_unitLock4->setAnchorPoint({ 0, 0 });
	_unitLock4->setPosition({ 316,55 });
	_unitLock4->setScale(0.5f);
	_unitLock4->setScaleY(0.48f);
	_scene->addChild(_unitLock4, 1);

	_unitLock5 = Sprite::createWithSpriteFrameName("btn_unit_lock.png");
	_unitLock5->setAnchorPoint({ 0, 0 });
	_unitLock5->setPosition({ 367,55 });
	_unitLock5->setScale(0.5f);
	_unitLock5->setScaleY(0.48f);
	_scene->addChild(_unitLock5, 1);

	_unitLock6 = Sprite::createWithSpriteFrameName("btn_unit_lock.png");
	_unitLock6->setAnchorPoint({ 0, 0 });
	_unitLock6->setPosition({ 418,55 });
	_unitLock6->setScale(0.5f);
	_unitLock6->setScaleY(0.48f);
	_scene->addChild(_unitLock6, 1);
	

	//고기,마나 아이콘
	_meatIcon = Sprite::createWithSpriteFrameName("gauge_icon_food.png");
	_meatIcon->setAnchorPoint({ 0,0 });
	_meatIcon->setPosition({ 2,107 });
	_scene->addChild(_meatIcon, 1);
	_manaIcon = Sprite::createWithSpriteFrameName("gauge_icon_mana.png");
	_manaIcon->setAnchorPoint({ 0,0 });
	_manaIcon->setPosition({ 445,107 });
	_scene->addChild(_manaIcon, 1);
	_meatBackGround = Sprite::createWithSpriteFrameName("ui_gauge_back.png");
	_meatBackGround->setAnchorPoint({ 0,0 });
	_meatBackGround->setPosition(33, 105);
	_scene->addChild(_meatBackGround, -10);

	// 골드 아이콘
	_goldIcon = Sprite::createWithSpriteFrameName("gold_icon.png");
	_goldIcon->setPosition(335, 320);
	_goldIcon->setAnchorPoint({ 0,1 });
	_scene->addChild(_goldIcon, 1);

	// 정지 버튼
	_pauseButton = Sprite::createWithSpriteFrameName("btn_pause_up.png");
	_pauseButton->setAnchorPoint({ 1,1 });
	_pauseButton->setPosition(480, 320);
	_scene->addChild(_pauseButton, 1);

	// 넥스트버튼 (클리어시)
	NextButton = Sprite::createWithSpriteFrameName("lv_clear_next_btn_up.png");
	NextButton->setPosition(240, 50);
	NextButton->setVisible(false);
	_scene->addChild(NextButton, 2000);

	// 현재 고기량 폰트
	_currentMeat = Label::createWithCharMap("UI/Number/num_wht_13x14.png", 26,28,48);
	_currentMeat->setPosition(71, 113);
	_currentMeat->setAnchorPoint({ 1, 0 });
	_currentMeat->setScale(0.5f);
	_scene->addChild(_currentMeat,100);

	// 최대 고기량 폰트
	_MaxMeat = Label::createWithCharMap("UI/Number/num_wht_13x14.png", 26, 28, 48);
	_MaxMeat->setPosition(80, 113);
	_MaxMeat->setAnchorPoint({ 0, 0 });
	_MaxMeat->setScale(0.5f);
	_scene->addChild(_MaxMeat, 100);

	// 현재 마나량 폰트
	_currentMana = Label::createWithCharMap("UI/Number/num_wht_13x14.png", 26, 28, 48);
	_currentMana->setPosition(397, 113);
	_currentMana->setAnchorPoint({ 1,0 });
	_currentMana->setScale(0.5f);
	_scene->addChild(_currentMana, 100);

	// 최대 마냐량 폰트
	_MaxMana = Label::createWithCharMap("UI/Number/num_wht_13x14.png", 26, 28, 48);
	_MaxMana->setPosition(404, 113);
	_MaxMana->setAnchorPoint({ 0,0 });
	_MaxMana->setScale(0.5f);
	_scene->addChild(_MaxMana, 100);

	// 레벨 폰트
	_Level = Label::createWithCharMap("UI/Number/num_wht_13x14.png", 26, 28, 48);
	_Level->setPosition(13, 322);
	_Level->setAnchorPoint({ 0,1 });
	_Level->setScale(0.5f);
	_scene->addChild(_Level, 100);

	// 골드 폰트
	_Gold = Label::createWithCharMap("UI/Number/num_yel_12x15.png", 24, 30, 48);
	_Gold->setPosition(355, 318);
	_Gold->setAnchorPoint({ 0,1 });
	_Gold->setScale(0.5f);
	_scene->addChild(_Gold, 100);

	// 스킬 1 마나 사용량 폰트
	_SkillOneManaUse = Label::createWithCharMap("UI/Number/num_wht_13x14.png", 26, 28, 48);
	_SkillOneManaUse->setPosition(255, 25);
	_SkillOneManaUse->setAnchorPoint({ 0,1 });
	_SkillOneManaUse->setScale(0.5f);
	_scene->addChild(_SkillOneManaUse, 100);

	// 스킬 2 마나 사용량 폰트
	_SkillTwoManaUse = Label::createWithCharMap("UI/Number/num_wht_13x14.png", 26, 28, 48);
	_SkillTwoManaUse->setPosition(335, 25);
	_SkillTwoManaUse->setAnchorPoint({ 0,1 });
	_SkillTwoManaUse->setScale(0.5f);
	_scene->addChild(_SkillTwoManaUse, 100);

	// 스킬 3 마나 사용량 폰트
	_SkillThreeManaUse = Label::createWithCharMap("UI/Number/num_wht_13x14.png", 26, 28, 48);
	_SkillThreeManaUse->setPosition(405, 25);
	_SkillThreeManaUse->setAnchorPoint({ 0,1 });
	_SkillThreeManaUse->setScale(0.5f);
	_scene->addChild(_SkillThreeManaUse, 100);

	// 체력 정보(상단중앙)
	_hpInfoLayout = Sprite::createWithSpriteFrameName("ui_hp_info_layout.png");
	_hpInfoLayout->setAnchorPoint({ 0.5, 1 });
	_hpInfoLayout->setPosition(240,320);
	_scene->addChild(_hpInfoLayout);
	_hpInfoBack = Sprite::createWithSpriteFrameName("ui_hp_info_back.png");
	_hpInfoBack->setAnchorPoint({ 0.5, 1 });
	_hpInfoBack->setPosition(240, 315);
	_scene->addChild(_hpInfoBack, -10);

	// 경험치 바
	_expBar = Sprite::createWithSpriteFrameName("ui_exp.png");
	_expBar->setAnchorPoint({ 0,1 });
	_expBar->setPosition(0, 320);
	_scene->addChild(_expBar);
	_expBarBack = Sprite::createWithSpriteFrameName("ui_exp_back.png");
	_expBarBack->setAnchorPoint({ 0,1 });
	_expBarBack->setPosition(4, 308);
	_scene->addChild(_expBarBack, -15);

	// 미니맵 포인터 스프라이트
	_miniMapPointer = Sprite::createWithSpriteFrameName("pointer_0000.png");
	_hpInfoLayout->addChild(_miniMapPointer);

	// 미니맵 포인터 애니메이션
	_miniMapPointerAnimation = Animation::create();
	_miniMapPointerAnimation->setDelayPerUnit(0.03f);
	_miniMapPointerAnimation->addSpriteFrame(cache->getSpriteFrameByName("pointer_0000.png"));
	_miniMapPointerAnimation->addSpriteFrame(cache->getSpriteFrameByName("pointer_0001.png"));
	_miniMapPointerAnimation->addSpriteFrame(cache->getSpriteFrameByName("pointer_0002.png"));
	_miniMapPointerAnimation->addSpriteFrame(cache->getSpriteFrameByName("pointer_0003.png"));
	_miniMapPointerAnimation->addSpriteFrame(cache->getSpriteFrameByName("pointer_0004.png"));
	_miniMapPointerAnimation->addSpriteFrame(cache->getSpriteFrameByName("pointer_0005.png"));
	_miniMapPointerAnimation->addSpriteFrame(cache->getSpriteFrameByName("pointer_0006.png"));
	_miniMapPointerAnimation->addSpriteFrame(cache->getSpriteFrameByName("pointer_0007.png"));
	_miniMapPointerAnimation->addSpriteFrame(cache->getSpriteFrameByName("pointer_0008.png"));
	_miniMapPointerAnimation->addSpriteFrame(cache->getSpriteFrameByName("pointer_0009.png"));
	_miniMapPointerAnimation->addSpriteFrame(cache->getSpriteFrameByName("pointer_0010.png"));
	_miniMapPointerAnimation->addSpriteFrame(cache->getSpriteFrameByName("pointer_0011.png"));
	_miniMapPointerAnimation->addSpriteFrame(cache->getSpriteFrameByName("pointer_0012.png"));
	_miniMapPointerAnimation->addSpriteFrame(cache->getSpriteFrameByName("pointer_0013.png"));
	_miniMapPointerAnimation->addSpriteFrame(cache->getSpriteFrameByName("pointer_0014.png"));
	_miniMapPointerAnimation->addSpriteFrame(cache->getSpriteFrameByName("pointer_0015.png"));
	_miniMapPointerAnimation->addSpriteFrame(cache->getSpriteFrameByName("pointer_0016.png"));
	_miniMapPointerAnimation->addSpriteFrame(cache->getSpriteFrameByName("pointer_0017.png"));
	_miniMapPointerAnimation->addSpriteFrame(cache->getSpriteFrameByName("pointer_0018.png"));
	_miniMapPointerAnimation->addSpriteFrame(cache->getSpriteFrameByName("pointer_0019.png"));
	_miniMapPointerAnimation->addSpriteFrame(cache->getSpriteFrameByName("pointer_0020.png"));
	_miniMapPointerAnimate = Animate::create(_miniMapPointerAnimation);
	_miniMapPointerRepeat = RepeatForever::create(_miniMapPointerAnimate);
	_miniMapPointer->runAction(_miniMapPointerRepeat);

	// 생쥐소환쿨타임(타이머)
	_mouseSummonsTimer = ProgressTimer::create(_mouseSummonsButtonDisable);
	_mouseSummonsTimer->setType(ProgressTimer::Type::RADIAL);
	_mouseSummonsTimer->setAnchorPoint({ 0,0 });
	_mouseSummonsTimer->setPosition(10, 55);
	_mouseSummonsTimer->setScale(0.5f);
	_mouseSummonsTimer->setScaleY(0.48f);
	_scene->addChild(_mouseSummonsTimer);

	// 곰소환쿨타임(타이머)
	_bearSummonsTimer = ProgressTimer::create(_bearSummonsButtonDisable);
	_bearSummonsTimer->setType(ProgressTimer::Type::RADIAL);
	_bearSummonsTimer->setAnchorPoint({ 0,0 });
	_bearSummonsTimer->setPosition(61, 55);
	_bearSummonsTimer->setScale(0.5f);
	_bearSummonsTimer->setScaleY(0.48f);
	_scene->addChild(_bearSummonsTimer);

	// 캥거루소환쿨타임(타이머)
	_kangarooSummonsTimer = ProgressTimer::create(_kangarooSummonsButtonDisable);
	_kangarooSummonsTimer->setType(ProgressTimer::Type::RADIAL);
	_kangarooSummonsTimer->setAnchorPoint({ 0,0 });
	_kangarooSummonsTimer->setPosition(112, 55);
	_kangarooSummonsTimer->setScale(0.5f);
	_kangarooSummonsTimer->setScaleY(0.48f);
	_scene->addChild(_kangarooSummonsTimer);

	// addchild
	_scene->addChild(_leftButton, 1);
	_scene->addChild(_rightButton, 1);
	_scene->addChild(_mainDashbord, 0);
	_scene->addChild(_mainDashbordCase, 4);
	_scene->addChild(_skillOneButton, 0);
	_scene->addChild(_skillTwoButton, 0);
	_scene->addChild(_skillThreeButton, 0);

	_right = false; // 오른쪽이동
	_left = false; // 왼쪽이동
	_skillOneClick = false; // 스킬1 버튼
	_skillTwoClick = false; // 스킬2 버튼
	_skillThreeClick = false; // 스킬3 버튼

	_mouseSummonsClick = false; // 생쥐 소환 버튼
	_bearSummonsClick = false; // 곰 소환 버튼
	_kangarooSummonsClick = false; // 캥거루 소환 버튼

	_mouseSummonsButtonActivation = false; // 생쥐 소환 버튼 활성화(쿨타임)
	_bearSummonsButtonActivation = false; // 곰 소환 버튼 활성화(쿨타임)
	_kangarooSummonsButtonActivation = false; // 캥거루 소환 버튼 활성화(쿨타임)

	_PauseClick = false; // 게임 정지 버튼 클릭

	// 생쥐 쿨타임 설정
	_mouseSummonsCollTime = 0.0f;
	_mouseSummonsMaxCollTime = 2.0f;

	// 곰 쿨타임 설정
	_bearSummonsCollTime = 0.0f;
	_bearSummonsMaxCollTime = 2.0f;

	// 캥거루 쿨타임 설정
	_kangarooSummonsCollTime = 0.0f;
	_kangarooSummonsMaxCollTime = 2.0f;

	// 레벨업 텍스트
	_levelUpText = Sprite::createWithSpriteFrameName("levelup_source_txt.png");
	_levelUpText->setScale(0.5f);
	_levelUpText->setScaleX(0.01f);
	_levelUpText->setPosition(90,120);
	_levelUpText->setVisible(false);
	Hero::getInstance()->getHero()->addChild(_levelUpText);

	// 레벨업 날개 왼쪽
	_levelUpWingL = Sprite::createWithSpriteFrameName("levelup_source_wing_l.png");
	_levelUpWingL->setScale(0.5f);
	_levelUpWingL->setAnchorPoint({ 0.7,0.5 });
	_levelUpWingL->setPosition(90,120);
	_levelUpWingL->setVisible(false);
	Hero::getInstance()->getHero()->addChild(_levelUpWingL);

	// 레벨업 날개 오른쪽
	_levelUpWingR = Sprite::createWithSpriteFrameName("levelup_source_wing_r.png");
	_levelUpWingR->setScale(0.5f);
	_levelUpWingR->setAnchorPoint({ 0.3,0.5 });
	_levelUpWingR->setPosition(90,120);
	_levelUpWingR->setVisible(false);
	Hero::getInstance()->getHero()->addChild(_levelUpWingR);
}

void HeroControl::HeroMove(Dungeon* dungeon)
{
	_dungeon = dungeon;
	
	// 히어로 조작부
	if (_left && Hero::getInstance()->getStageStart() && !Hero::getInstance()->getStageClear())
	{
		Hero::getInstance()->setMoveWay(LeftWay); // 왼쪽을 보는상태

		if (Hero::getInstance()->getHero()->getPositionX() - Hero::getInstance()->getHero()->getContentSize().width / 2 + 30 > 0)
		{
			Hero::getInstance()->getHero()->setPosition(Hero::getInstance()->getHero()->getPosition() + Vec2(Hero::getInstance()->getSpeed() * -1, 0));
			Hero::getInstance()->getWeapon1()->setPosition(Hero::getInstance()->getWeapon1()->getPosition() + Vec2(Hero::getInstance()->getSpeed() * -1, 0));
		}
		
		if (!Hero::getInstance()->getHero()->getNumberOfRunningActionsByTag(Walking))
		{
			Hero::getInstance()->getHero()->runAction(Hero::getInstance()->getWalkingAction());
			Hero::getInstance()->getWeapon1()->runAction(Hero::getInstance()->HammerWalkingAction(Hero::getInstance()->getHammerKind()));
		}
	}
	if (_right && Hero::getInstance()->getStageStart() && !Hero::getInstance()->getStageClear())
	{
		Hero::getInstance()->setMoveWay(RightWay); // 오른쪽을 보는상태 

		if (Hero::getInstance()->getHero()->getPositionX() < 1024)
		{
			Hero::getInstance()->getHero()->setPosition(Hero::getInstance()->getHero()->getPosition() + Vec2(Hero::getInstance()->getSpeed(), 0));
			Hero::getInstance()->getWeapon1()->setPosition(Hero::getInstance()->getWeapon1()->getPosition() + Vec2(Hero::getInstance()->getSpeed(), 0));
		}

		if (!Hero::getInstance()->getHero()->getNumberOfRunningActionsByTag(Walking))
		{
			Hero::getInstance()->getHero()->runAction(Hero::getInstance()->getWalkingAction());
			Hero::getInstance()->getWeapon1()->runAction(Hero::getInstance()->HammerWalkingAction(Hero::getInstance()->getHammerKind()));
		}
	}
	if (!Hero::getInstance()->getHero()->getNumberOfRunningActions()) // 히어로 대기
	{
		if (!Hero::getInstance()->getHero()->getNumberOfRunningActionsByTag(Waiting))
		{
			Hero::getInstance()->getHero()->runAction(Hero::getInstance()->getWaitingAction());
			Hero::getInstance()->getWeapon1()->runAction(Hero::getInstance()->HammerWaitingAction(Hero::getInstance()->getHammerKind()));
		}
	}

	// 스킬버튼 1
	if (!Hero::getInstance()->getSkillOneUnlock())
	{
		_skillOneButton->setTexture("MACEBU~1/mace1/mace1_button_black.png");
	}
	else if (Hero::getInstance()->getMana() < Hero::getInstance()->getSkillOneManaUse())
	{
		_skillOneButton->setTexture("MACEBU~1/mace1/mace1_button_black.png");
	}
	else if (Hero::getInstance()->getMana() >= Hero::getInstance()->getSkillOneManaUse() && !_skillOneClick)
	{
		_skillOneButton->setTexture("MACEBU~1/mace1/mace1_button_up.png");
	}
	else if (_skillOneClick)
	{
		_skillOneButton->setTexture("MACEBU~1/mace1/mace1_button_down");
	}
	// 스킬버튼 2
	if (!Hero::getInstance()->getSkillTwoUnlock())
	{
		_skillTwoButton->setSpriteFrame("btn_fist_disable.png");
	}
	else if (Hero::getInstance()->getMana() < Hero::getInstance()->getSkillTwoManaUse())
	{
		_skillTwoButton->setTexture("MACEBU~1/mace2/mace2_button_black.png");
	}
	else if (Hero::getInstance()->getMana() >= Hero::getInstance()->getSkillTwoManaUse() && !_skillTwoClick)
	{
		_skillTwoButton->setTexture("MACEBU~1/mace2/mace2_button_up.png");
	}
	else if (_skillTwoClick)
	{
		_skillTwoButton->setTexture("MACEBU~1/mace2/mace2_button_down.png");
	}

	// 스킬버튼 3
	if (!Hero::getInstance()->getSkillThreeUnlock())
	{
		_skillThreeButton->setSpriteFrame("btn_fist_disable.png");
	}
	else if (Hero::getInstance()->getMana() < Hero::getInstance()->getSkillThreeManaUse())
	{
		_skillThreeButton->setTexture("MACEBU~1/mace3/mace3_button_black.png");
	}
	else if (Hero::getInstance()->getMana() >= Hero::getInstance()->getSkillThreeManaUse() && !_skillThreeClick)
	{
		_skillThreeButton->setTexture("MACEBU~1/mace3/mace3_button_up.png");
	}
	else if (_skillThreeClick)
	{
		_skillThreeButton->setTexture("MACEBU~1/mace3/mace3_button_down.png");
	}

	// 생쥐 소환 버튼
	if (!Hero::getInstance()->getUnitOneUnlock())
	{
		_mouseSummonsButton->setSpriteFrame("btn_unit_lock.png");
	}
	else if (Hero::getInstance()->getMeat() < 10 || _mouseSummonsButtonActivation == false)
	{
		_mouseSummonsButton->setSpriteFrame("btn_unit_00_disable.png");
	}
	else if (Hero::getInstance()->getMeat() >= 10 && !_mouseSummonsClick && _mouseSummonsButtonActivation == true)
	{
		_mouseSummonsButton->setSpriteFrame("btn_unit_00_up.png");
	}
	else if (_mouseSummonsClick)
	{
		_mouseSummonsButton->setSpriteFrame("btn_unit_00_down.png");
	}

	// 곰 소환 버튼
	if (!Hero::getInstance()->getUnitTwoUnlock())
	{
		_bearSummonsButton->setSpriteFrame("btn_unit_lock.png");
	}
	else if (Hero::getInstance()->getMeat() < 30 || _bearSummonsButtonActivation == false)
	{
		_bearSummonsButton->setSpriteFrame("btn_unit_02_disable.png");
	}
	else if (Hero::getInstance()->getMeat() >= 30 && !_bearSummonsClick)
	{
		_bearSummonsButton->setSpriteFrame("btn_unit_02_up.png");
	}
	else if (_bearSummonsClick)
	{
		_bearSummonsButton->setSpriteFrame("btn_unit_02_down.png");
	}

	// 캥거루 소환버튼
	if (!Hero::getInstance()->getUnitThreeUnlock())
	{
		_kangarooSummonsButton->setSpriteFrame("btn_unit_lock.png");
	}
	else if (Hero::getInstance()->getMeat() < 40 || _kangarooSummonsButtonActivation == false)
	{
		_kangarooSummonsButton->setSpriteFrame("btn_unit_03_disable.png");
	}
	else if (Hero::getInstance()->getMeat() >= 40 && !_kangarooSummonsClick)
	{
		_kangarooSummonsButton->setSpriteFrame("btn_unit_03_up.png");
	}
	else if (_kangarooSummonsClick)
	{
		_kangarooSummonsButton->setSpriteFrame("btn_unit_03_down.png");
	}

	if (_PauseClick)
	{
		_pauseButton->setSpriteFrame("btn_pause_down.png");
	}
	else if (!_PauseClick)
	{
		_pauseButton->setSpriteFrame("btn_pause_up.png");
	}

	Hero::getInstance()->getManaGauge()->setPercentage((Hero::getInstance()->getMana() / Hero::getInstance()->getMaxMana()) * 100); // 마나게이지를 Bar 로 보여준다
	Hero::getInstance()->getMeatGauge()->setPercentage((Hero::getInstance()->getMeat() / Hero::getInstance()->getMaxMeat()) * 100); // 고기게이지를 Bar 로 보여준다
	Hero::getInstance()->getHeroHpInfo()->setPercentage((Hero::getInstance()->getHp() / Hero::getInstance()->getMaxHp()) * 100); // 플레이어의 체력을 보여줌
	Hero::getInstance()->getMonsterBaseInfo()->setPercentage((_dungeon->getHp() / _dungeon->getHpm()) * 100); // 몬스터베이스의 체력을 보여준다


	// 마나,고기 게이지를 숫자로 보여준다
	_currentMeat->setString(String::createWithFormat("%d", (int)Hero::getInstance()->getMeat())->_string.c_str());
	_MaxMeat->setString(String::createWithFormat("%d", (int)Hero::getInstance()->getMaxMeat())->_string.c_str());
	_currentMana->setString(String::createWithFormat("%d", (int)Hero::getInstance()->getMana())->_string.c_str());
	_MaxMana->setString(String::createWithFormat("%d", (int)Hero::getInstance()->getMaxMana())->_string.c_str());
	_Level->setString(String::createWithFormat("%d", (int)Hero::getInstance()->getLv())->_string.c_str()); // 레벨
	_Gold->setString(String::createWithFormat("%d", (int)Hero::getInstance()->getGold())->_string.c_str()); // 골드

	// 경험치 게이지를 보여준다
	Hero::getInstance()->getExpGauge()->setPercentage((Hero::getInstance()->getExp() / Hero::getInstance()->getMaxExp()) * 100);

	// 스킬 마나 소비량을 보여준다
	if (Hero::getInstance()->getSkillOneUnlock())
		_SkillOneManaUse->setString(String::createWithFormat("%d", (int)Hero::getInstance()->getSkillOneManaUse())->_string.c_str()); // 스킬 1 마나소비량
	if (Hero::getInstance()->getSkillTwoUnlock())
		_SkillTwoManaUse->setString(String::createWithFormat("%d", (int)Hero::getInstance()->getSkillTwoManaUse())->_string.c_str()); // 스킬 2 마나소비량
	if (Hero::getInstance()->getSkillThreeUnlock())
		_SkillThreeManaUse->setString(String::createWithFormat("%d", (int)Hero::getInstance()->getSkillThreeManaUse())->_string.c_str()); // 스킬 3 마나소비량

	// 유닛 소환 쿨타임을 보여준다
	_mouseSummonsTimer->setPercentage((_mouseSummonsCollTime / _mouseSummonsMaxCollTime) * 100);
	_bearSummonsTimer->setPercentage((_bearSummonsCollTime / _bearSummonsMaxCollTime) * 100);
	_kangarooSummonsTimer->setPercentage((_kangarooSummonsCollTime / _kangarooSummonsMaxCollTime) * 100);

	// 스킬 이펙트 액션이 비활성화일떈 스킬이펙트를 가려준다.
	SkillEffectVisible();

	// 미니맵 포인트의 위치를 갱신
	MiniMap();

	//유닛 버프!
	UnitBuff();

	// 레벨업
	LevelUp();

	// 넥스트 버튼 활성화
	NextButtonVisible();
}

void HeroControl::HeroManaRegen()
{
	// 마나 리젠
	if (Hero::getInstance()->getMana() < Hero::getInstance()->getMaxMana())
	{
		Hero::getInstance()->setMana(Hero::getInstance()->getMana() + 1);
	}
}

void HeroControl::HeroMeatRegen()
{
	// 고기 리젠
	if (Hero::getInstance()->getMeat() < Hero::getInstance()->getMaxMeat())
	{
		Hero::getInstance()->setMeat(Hero::getInstance()->getMeat() + 1);
	}
}

void HeroControl::UnitVecErase()
{
	// 코드 설명 : bool값으로 생사여부 를 결정하여 죽음상태이면
	//	           안전하게 스프라이트의 자식(체력바)들 부터 제거한뒤
	//			   removeself 액션을 이용(HeroUnit.cpp - 350line) 해 죽는 모션이 끝나면 객체(유닛)를 삭제해준다
	for (int i = 0; i < _heroUnitVec.size(); i++)
	{
		if (_heroUnitVec[i]->getDead() == true /*&& !_heroUnitVec[i]->getSprite()->getNumberOfRunningActions()*/)
		{
			_heroUnitVec[i]->getSprite()->removeChild(_heroUnitVec[i]->getUnitHpBar(), false);
			_heroUnitVec[i]->getSprite()->removeChild(_heroUnitVec[i]->getUnitHpBarBack(), false);
			//_layer->removeChild(_heroUnitVec[i]->getSprite(), false);
			_heroUnitVec.erase(_heroUnitVec.begin() + i);
			log("d");
		}
	}

	for (int i = 0; i < _missileCollisionVec.size(); i++)
	{
		if (_missileCollisionVec[i]->getErase() == true)
		{
			_missileCollisionVec.erase(_missileCollisionVec.begin() + i);
		}
	}
}

// 쿨타임 계산
void HeroControl::CoolTime()
{
	// 생쥐 쿨타임
	if (_mouseSummonsCollTime <= 0.0f )
	{
		_mouseSummonsCollTime = 2.0f;
		_mouseSummonsButtonActivation = true;
	}
	if (_mouseSummonsButtonActivation == false)
	{
		_mouseSummonsCollTime -= 0.04f;
	}

	// 곰 쿨타임
	if (_bearSummonsCollTime <= 0.0f)
	{
		_bearSummonsCollTime = 2.0f;
		_bearSummonsButtonActivation = true;
	}	 
	if (_bearSummonsButtonActivation == false)
	{	 
		_bearSummonsCollTime -= 0.02f;
	}

	// 캥거루 쿨타임
	if (_kangarooSummonsCollTime <= 0.0f)
	{
		_kangarooSummonsCollTime = 2.0f;
		_kangarooSummonsButtonActivation = true;
	}
	if (_kangarooSummonsButtonActivation == false)
	{
		_kangarooSummonsCollTime -= 0.01f;
	}
	
	//생쥐 버튼 활성화
	if (_mouseSummonsButtonActivation == true)
	{
		_mouseSummonsTimer->setZOrder(-5);
	}
	else
	{
		_mouseSummonsTimer->setZOrder(5);
	}

	// 곰 버튼 활성화
	if (_bearSummonsButtonActivation == true)
	{
		_bearSummonsTimer->setZOrder(-5);
	}
	else
	{
		_bearSummonsTimer->setZOrder(5);
	}

	// 캥거루 버튼 활성화
	if (_kangarooSummonsButtonActivation == true)
	{
		_kangarooSummonsTimer->setZOrder(-5);
	}
	else
	{
		_kangarooSummonsTimer->setZOrder(5);
	}
}

void HeroControl::SkillEffectVisible()
{
	if (!Hero::getInstance()->getSkillEffectBox1()->getNumberOfRunningActions())
		Hero::getInstance()->getSkillEffectBox1()->setVisible(false);

	if (!Hero::getInstance()->getSkillEffectBox2()->getNumberOfRunningActions())
		Hero::getInstance()->getSkillEffectBox2()->setVisible(false);

	if (!Hero::getInstance()->getSkillEffectBox3()->getNumberOfRunningActions())
		Hero::getInstance()->getSkillEffectBox3()->setVisible(false);
}

void HeroControl::MiniMap()
{
	// 공식 : (미니맵 가로길이 / (맵전체길이 / 히어로 x좌표)) + 길이보정
	_miniMapPointer->setPosition(160 / (1024 / Hero::getInstance()->getHero()->getPositionX()) + 10, 17);
}

void HeroControl::LevelUp()
{

	auto WingActL = RotateBy::create(0.1f, Vec3(0, 0, -90));
	auto WingActR = RotateBy::create(0.1f, Vec3(0, 0, +90));
	auto WingActL_1 = Spawn::create(Sequence::createWithTwoActions(WingActL, WingActL->reverse()), MoveBy::create(0.2, Vec2(0, 200)), nullptr);
	auto WingActR_1 = Spawn::create(Sequence::createWithTwoActions(WingActR, WingActR->reverse()), MoveBy::create(0.2, Vec2(0, 200)), nullptr);

	if (Hero::getInstance()->getExp() >= Hero::getInstance()->getMaxExp())
	{
		_levelUpText->setVisible(true);
		_levelUpWingL->setVisible(true);
		_levelUpWingR->setVisible(true);

		Hero::getInstance()->setExp(0);
		Hero::getInstance()->setLv(Hero::getInstance()->getLv() + 1);

		// 레벨업 텍스트, 날개 액션
		_levelUpText->runAction(Sequence::create(ScaleTo::create(0.1f, 0.5, 0.5),DelayTime::create(2.4), MoveBy::create(0.2,Vec2(0,200)), nullptr));

		_levelUpWingL->runAction(Sequence::create(MoveBy::create(0.1f, Vec2(-55, 0)), WingActL, WingActL->reverse(), WingActL, WingActL->reverse(), WingActL, WingActL->reverse(),
			WingActL, WingActL->reverse(), WingActL, WingActL->reverse(), WingActL, WingActL->reverse(), WingActL, WingActL->reverse(), WingActL, WingActL->reverse(), WingActL, WingActL->reverse(),
			WingActL, WingActL->reverse(), WingActL, WingActL->reverse(), WingActL, WingActL->reverse(), WingActL_1, nullptr));

		_levelUpWingR->runAction(Sequence::create(MoveBy::create(0.1f, Vec2(+55, 0)), WingActR, WingActR->reverse(), WingActR, WingActR->reverse(), WingActR, WingActR->reverse(),
			WingActR, WingActR->reverse(), WingActR, WingActR->reverse(), WingActR, WingActR->reverse(), WingActR, WingActR->reverse(), WingActR, WingActR->reverse(), WingActR, WingActR->reverse(),
			WingActR, WingActR->reverse(), WingActR, WingActR->reverse(), WingActR, WingActR->reverse(), WingActR_1, CallFunc::create(CC_CALLBACK_0(HeroControl::SetLevelUpImage, this)), nullptr));
	}
}

void HeroControl::SetLevelUpImage()
{
	_levelUpText->setVisible(false);
	_levelUpWingL->setVisible(false);
	_levelUpWingR->setVisible(false);

	_levelUpText->setPosition(90, 120);
	_levelUpWingL->setPosition(90, 120);
	_levelUpWingR->setPosition(90, 120);
}

void HeroControl::UnitBuff()
{
	Hero::getInstance()->getHeroBuffOra()->setPosition(Hero::getInstance()->getHero()->getPosition().x, Hero::getInstance()->getHero()->getPosition().y - 75);
	 
	// 히어로 버프 범위 안에있으면 버프활성화
	for (int i = 0; i < _heroUnitVec.size(); i++)
	{
		if (_heroUnitVec[i]->getDead())
		{
			_heroUnitVec[i]->getUnitBuffOra()->setVisible(false);
			_heroUnitVec[i]->setBuff(false);
		}
		else if (Hero::getInstance()->getHeroBuffOra()->getPositionX() - 100 < _heroUnitVec[i]->getSprite()->getPositionX() &&
			Hero::getInstance()->getHeroBuffOra()->getPositionX() + 100 > _heroUnitVec[i]->getSprite()->getPositionX())
		{
			_heroUnitVec[i]->getUnitBuffOra()->setVisible(true);
			_heroUnitVec[i]->setBuff(true);
		}
		else
		{
			_heroUnitVec[i]->getUnitBuffOra()->setVisible(false);
			_heroUnitVec[i]->setBuff(false);
		}
	}
	
}

void HeroControl::NextButtonVisible()
{
	if (Hero::getInstance()->getStageClear())
	{
		NextButton->setVisible(true);
	}
}

bool HeroControl::onTouchBegan(Touch * touch, Event * event)
{
	// 좌우 이동
	if (_leftButton->getBoundingBox().containsPoint(touch->getLocation())
		&& Hero::getInstance()->getStageStart() && !Hero::getInstance()->getStageClear())
	{
		Hero::getInstance()->getHero()->setFlippedX(true);
		Hero::getInstance()->getWeapon1()->setFlippedX(true);
		Hero::getInstance()->getSkillEffectBox1()->setFlippedX(true);
		_left = true;
		_leftButton->setSpriteFrame("btn_left_down.png");

	}
	else if (_rightButton->getBoundingBox().containsPoint(touch->getLocation())
		&& Hero::getInstance()->getStageStart() && !Hero::getInstance()->getStageClear())
	{
		Hero::getInstance()->getHero()->setFlippedX(false);
		Hero::getInstance()->getWeapon1()->setFlippedX(false);
		Hero::getInstance()->getSkillEffectBox1()->setFlippedX(false);
		_right = true;
		_rightButton->setSpriteFrame("btn_right_down.png");
	}
	// 히어로 대기
	if (Hero::getInstance()->getHero()->getNumberOfRunningActionsByTag(Waiting))
	{
		Hero::getInstance()->getHero()->stopActionByTag(Waiting);
		Hero::getInstance()->getWeapon1()->stopActionByTag(HammerWaiting);
	}

	// 스킬 1 클릭시 행동
	if (_skillOneButton->getBoundingBox().containsPoint(touch->getLocation())
		&& Hero::getInstance()->getSkillOneUnlock() && !Hero::getInstance()->getStageClear())
	{
		_skillOneClick = true;

		if (Hero::getInstance()->getMana() >= Hero::getInstance()->getSkillOneManaUse())
		{
			Hero::getInstance()->setHammerKind(고무망치);
			Hero::getInstance()->setMana(Hero::getInstance()->getMana() - Hero::getInstance()->getSkillOneManaUse());
			Hero::getInstance()->getHero()->runAction(Hero::getInstance()->getAttackAction()->clone()); // 공격 모션 실행
			Hero::getInstance()->getWeapon1()->runAction(Hero::getInstance()->HammerAttackAction(Hero::getInstance()->getHammerKind())->clone()); // 공격 모션 실행
			Hero::getInstance()->getSkillEffectBox1()->runAction(Hero::getInstance()->HammerAttackEffectA(Hero::getInstance()->getHammerKind())->clone()); // 스킬A 이펙트 애니메이션 실행

			// 스킬 투사체 객체를 만들어 백터에 추가
			_missileCollision = new MissileCollision(_layer, Hero::getInstance()->getMoveWay(), Hero::getInstance()->getHero()->getPosition(), Hero::getInstance()->getHero()->getZOrder());
			_missileCollisionVec.push_back(_missileCollision);
		}
	}

	// 스킬 2 클릭시 행동
	if (_skillTwoButton->getBoundingBox().containsPoint(touch->getLocation()) 
		&& Hero::getInstance()->getSkillTwoUnlock() && !Hero::getInstance()->getStageClear())
	{
		_skillTwoClick = true;

		if (Hero::getInstance()->getMana() >= Hero::getInstance()->getSkillTwoManaUse())
		{
			Hero::getInstance()->setHammerKind(회복망치);
			Hero::getInstance()->setMana(Hero::getInstance()->getMana() - Hero::getInstance()->getSkillTwoManaUse());
			Hero::getInstance()->getHero()->runAction(Hero::getInstance()->getAttackAction()->clone()); // 공격 모션 실행
			Hero::getInstance()->getWeapon1()->runAction(Hero::getInstance()->HammerAttackAction(Hero::getInstance()->getHammerKind())->clone()); // 공격 모션 실행
			Hero::getInstance()->getSkillEffectBox1()->runAction(Hero::getInstance()->HammerAttackEffectA(Hero::getInstance()->getHammerKind())->clone()); // 스킬A 이펙트 애니메이션 실행
			Hero::getInstance()->getSkillEffectBox2()->runAction(Hero::getInstance()->HammerAttackEffectB(Hero::getInstance()->getHammerKind())->clone()); // 스킬B 이펙트 애니메이션 실행
			Hero::getInstance()->getSkillEffectBox3()->runAction(Hero::getInstance()->HammerAttackEffectC(Hero::getInstance()->getHammerKind())->clone()); // 스킬C 이펙트 애니메이션 실행
		}
	}

	// 스킬 3 클릭시 행동
	if (_skillThreeButton->getBoundingBox().containsPoint(touch->getLocation())
		&& Hero::getInstance()->getSkillThreeUnlock() && !Hero::getInstance()->getStageClear())
	{
		_skillThreeClick = true;

		if (Hero::getInstance()->getMana() >= Hero::getInstance()->getSkillThreeManaUse())
		{
			Hero::getInstance()->setHammerKind(식량망치);
			Hero::getInstance()->setMana(Hero::getInstance()->getMana() - Hero::getInstance()->getSkillThreeManaUse());
			Hero::getInstance()->getHero()->runAction(Hero::getInstance()->getAttackAction()->clone()); // 공격 모션 실행
			Hero::getInstance()->getWeapon1()->runAction(Hero::getInstance()->HammerAttackAction(Hero::getInstance()->getHammerKind())->clone()); // 공격 모션 실행
			Hero::getInstance()->getSkillEffectBox1()->runAction(Hero::getInstance()->HammerAttackEffectA(Hero::getInstance()->getHammerKind())->clone()); // 스킬A 이펙트 애니메이션 실행
		}
	}

	// 생쥐 소환 버튼
	if (_mouseSummonsButton->getBoundingBox().containsPoint(touch->getLocation())
		&& Hero::getInstance()->getUnitOneUnlock() && !Hero::getInstance()->getStageClear())
	{
		if (Hero::getInstance()->getMeat() >= 10 && _mouseSummonsButtonActivation == true)
		{
			_mouseSummonsClick = true;
			_mouseSummonsButtonActivation = false;

			_heroUnit = new HeroUnit(_scene, 생쥐, _layer,_dungeon);
			_heroUnitVec.push_back(_heroUnit);

			Hero::getInstance()->setMeat(Hero::getInstance()->getMeat() - 10);
		}
	}

	// 곰 소환 버튼
	if (_bearSummonsButton->getBoundingBox().containsPoint(touch->getLocation()) 
		&& Hero::getInstance()->getUnitTwoUnlock() && !Hero::getInstance()->getStageClear())
	{
		if (Hero::getInstance()->getMeat() >= 30)
		{
			_bearSummonsClick = true;
			_bearSummonsButtonActivation = false;

			_heroUnit = new HeroUnit(_scene, 곰, _layer, _dungeon);
			_heroUnitVec.push_back(_heroUnit);

			Hero::getInstance()->setMeat(Hero::getInstance()->getMeat() - 30);
		}
	}

	// 캥거루 소환 버튼
	if (_kangarooSummonsButton->getBoundingBox().containsPoint(touch->getLocation()) 
		&& Hero::getInstance()->getUnitThreeUnlock() && !Hero::getInstance()->getStageClear())
	{
		if (Hero::getInstance()->getMeat() >= 40)
		{
			_kangarooSummonsClick = true;
			_kangarooSummonsButtonActivation = false;

			_heroUnit = new HeroUnit(_scene, 캥거루, _layer, _dungeon);
			_heroUnitVec.push_back(_heroUnit);

			Hero::getInstance()->setMeat(Hero::getInstance()->getMeat() - 40);
		}
	}

	// 정지 버튼
	if (_pauseButton->getBoundingBox().containsPoint(touch->getLocation())
		&& !Hero::getInstance()->getStageClear() && !_PauseClick)
	{
		_pauseBack = Sprite::createWithSpriteFrameName("back_alpha.png");
		_pauseBack->setOpacity(200);
		_pauseBack->setPosition(-50, -50);
		_pauseBack->setAnchorPoint({ 0,0 });
		_pauseBack->setScale(20.0f);
		_scene->addChild(_pauseBack, 1500);

		_pauseBord = Sprite::createWithSpriteFrameName("gameplay_option_board.png");
		_pauseBord->setPosition(240, 160);
		_scene->addChild(_pauseBord, 1700);

		_pauseText = Sprite::createWithSpriteFrameName("msg_pause.png");
		_pauseText->setPosition(240, 240);
		_scene->addChild(_pauseText, 1700);
		_PauseClick = true;

		_pauseQuitButton = Sprite::createWithSpriteFrameName("gp_option_btn_quit_up.png");
		_pauseQuitButton->setPosition(240, 180);
		_scene->addChild(_pauseQuitButton, 1700);

		_pauseResumeButton = Sprite::createWithSpriteFrameName("gp_option_btn_resume_up.png");
		_pauseResumeButton->setPosition(240, 140);
		_scene->addChild(_pauseResumeButton, 1700);

		Director::getInstance()->pause();
	}

	// Pause 시 Resume 버튼 클릭시
	if (_PauseClick)
	{
		if (_pauseResumeButton->getBoundingBox().containsPoint(touch->getLocation()))
		{
			_PauseClick = false;
			_scene->removeChild(_pauseBack);
			_scene->removeChild(_pauseBord);
			_scene->removeChild(_pauseText);
			_scene->removeChild(_pauseQuitButton);
			_scene->removeChild(_pauseResumeButton);

			Director::getInstance()->resume();
		}
	}

	// 넥스트 버튼
	if (NextButton->getBoundingBox().containsPoint(touch->getLocation()) && Hero::getInstance()->getStageClear())
	{
		//auto secene = ShopScene::create();
		//Director::getInstance()->replaceScene(secene);
		log("Next Scene");
	}

	return true;
}

void HeroControl::onTouchMoved(Touch * touch, Event * event)
{
}

void HeroControl::onTouchEnded(Touch * touch, Event * event)
{
	_left = false;
	_right = false;
	_skillOneClick = false;
	_skillTwoClick = false;
	_skillThreeClick = false;
	_mouseSummonsClick = false;
	_bearSummonsClick = false;
	_kangarooSummonsClick = false;

	_leftButton->setSpriteFrame("btn_left_up.png");
	_rightButton->setSpriteFrame("btn_right_up.png");

	if (Hero::getInstance()->getHero()->getNumberOfRunningActionsByTag(Walking))
	{
		Hero::getInstance()->getHero()->stopActionByTag(Walking);
		Hero::getInstance()->getWeapon1()->stopActionByTag(HammerWalking);
	}

}
