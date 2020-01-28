#include "HeroUnit.h"
#include "Monster.h"

HeroUnit::HeroUnit(Scene * scene, UnitKind herokind, Layer* layer, Dungeon* dungeon)
{
	_layer = layer;
	_dungeon = dungeon;

	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Player/Unit/u_01_1.plist");
	cache->addSpriteFramesWithFile("Player/Unit/u_02_1.plist");
	cache->addSpriteFramesWithFile("Player/Unit/u_03_1.plist");
	cache->addSpriteFramesWithFile("Player/effect/eff_blend_02.plist");
	cache->addSpriteFramesWithFile("Player/effect/eff_blend_03.plist"); // plist 추가
	cache->addSpriteFramesWithFile("Player/effect/eff_blend_01.plist");

	srand((unsigned)time(NULL));

	// 죽을때 영혼나오는 애니메이션 기준 스프라이트
	_UnitDeadAnimateBox = Sprite::createWithSpriteFrameName("eff_die_0001.png");
	_UnitDeadAnimateBox->setVisible(false);
	layer->addChild(_UnitDeadAnimateBox);

	_buff = false;

	// 히트 애니메이션 기준 스프라이트
	//_hitAnimationBox = Sprite::createWithSpriteFrameName("eff_hit_01_0001.png");
	//layer->addChild(_hitAnimationBox);

	switch (herokind) 
	{
	case 생쥐:
		_UnitSprite = Sprite::createWithSpriteFrameName("u01_walk_0001.png");
		_UnitSprite->setPosition(0, 420 + rand() % 40);
		_unitAction = UnitWalk;
		_Speed = Hero::getInstance()->getMouseSpeed();
		_AtkSpeed = 1.0f;
		_MaxAtkSpeed = 1.0f;
		_Hp = Hero::getInstance()->getMouseHp();
		_maxHP = Hero::getInstance()->getMouseMaxHp();
		_Atk = Hero::getInstance()->getMouseAtk();
		_Atk2 = Hero::getInstance()->getMouseAtk2();
		_Range = 50 + rand() % 5;
		_unitKind = 생쥐;
		_Dead = false;
		_FirstAtk = false;
		layer->addChild(_UnitSprite, (_UnitSprite->getPositionY() - _UnitSprite->getContentSize().height / 2) * -1);

		_HeroUnitHpBar = ProgressTimer::create(Sprite::create("UI/HeroUnitHpBar.png"));
		_HeroUnitHpBar->setType(ProgressTimer::Type::BAR);
		_HeroUnitHpBar->setPosition({ _UnitSprite->getContentSize().width / 2, _UnitSprite->getContentSize().height - 110 });
		_HeroUnitHpBar->setMidpoint({ 0, 0 });
		_HeroUnitHpBar->setBarChangeRate({ 1,0 });
		_UnitSprite->addChild(_HeroUnitHpBar, _UnitSprite->getZOrder());

		_HeroUnitHpBarBack = Sprite::create("UI/UnitHpBarBack.png");
		_HeroUnitHpBarBack->setPosition({ _UnitSprite->getContentSize().width / 2, _UnitSprite->getContentSize().height -110 });
		_UnitSprite->addChild(_HeroUnitHpBarBack, _UnitSprite->getZOrder() - 1);

		_animation1 = Animation::create();
		_animation1->setDelayPerUnit(0.03f);
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u01_walk_0001.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u01_walk_0002.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u01_walk_0003.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u01_walk_0004.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u01_walk_0005.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u01_walk_0006.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u01_walk_0007.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u01_walk_0008.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u01_walk_0009.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u01_walk_0010.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u01_walk_0011.png"));
		_animate1 = Animate::create(_animation1);
		_walkAction = RepeatForever::create(_animate1);
		_walkAction->retain();
		_walkAction->setTag(UnitWalk);

		_animation2 = Animation::create();
		_animation2->setDelayPerUnit(0.03f);
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u01_att1_0001.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u01_att1_0002.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u01_att1_0003.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u01_att1_0004.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u01_att1_0005.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u01_att1_0006.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u01_att1_0007.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u01_att1_0008.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u01_att1_0009.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u01_att1_0010.png"));
		_animate2 = Animate::create(_animation2);
		_animate2->retain();
		_animate2->setTag(UnitAttack1);

		_animation2_1 = Animation::create();
		_animation2_1->setDelayPerUnit(0.03f);
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u01_att2_0001.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u01_att2_0002.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u01_att2_0003.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u01_att2_0004.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u01_att2_0005.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u01_att2_0006.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u01_att2_0007.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u01_att2_0008.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u01_att2_0009.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u01_att2_0010.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u01_att2_0011.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u01_att2_0012.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u01_att2_0013.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u01_att2_0014.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u01_att2_0015.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u01_att2_0016.png"));
		_animate2_1 = Animate::create(_animation2_1);
		_animate2_1->retain();
		_animate2_1->setTag(UnitAttack2);

		_animation3 = Animation::create();
		_animation3->setDelayPerUnit(0.03f);
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u01_dead_0001.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u01_dead_0002.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u01_dead_0003.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u01_dead_0004.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u01_dead_0005.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u01_dead_0006.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u01_dead_0007.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u01_dead_0008.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u01_dead_0009.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u01_dead_0010.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u01_dead_0011.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u01_dead_0012.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u01_dead_0013.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u01_dead_0014.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u01_dead_0015.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u01_dead_0016.png"));
		_animate3 = Animate::create(_animation3);
		_animate3->retain();
		_animate3->setTag(UnitDead);

		break;
	case 곰:
		_UnitSprite = Sprite::createWithSpriteFrameName("u03_walk_0001.png");
		_UnitSprite->setPosition(0, 420 + rand() % 40);
		_unitAction = UnitWalk;
		_Speed = Hero::getInstance()->getBearSpeed();
		_AtkSpeed = 1.0f;
		_MaxAtkSpeed = 1.0f;
		_Hp = Hero::getInstance()->getBearHp();
		_maxHP = Hero::getInstance()->getBearMaxHp();
		_Atk = Hero::getInstance()->getBearAtk();
		_Atk2 = Hero::getInstance()->getBearAtk2();
		_Range = 50 + rand() % 5;
		_unitKind = 곰;
		_Dead = false;
		_FirstAtk = false;
		layer->addChild(_UnitSprite, (_UnitSprite->getPositionY() - _UnitSprite->getContentSize().height / 2) * -1);

		_HeroUnitHpBar = ProgressTimer::create(Sprite::create("UI/HeroUnitHpBar.png"));
		_HeroUnitHpBar->setType(ProgressTimer::Type::BAR);
		_HeroUnitHpBar->setPosition({ _UnitSprite->getContentSize().width / 2 - 7, _UnitSprite->getContentSize().height -90 });
		_HeroUnitHpBar->setMidpoint({ 0, 0 });
		_HeroUnitHpBar->setBarChangeRate({ 1,0 });
		_UnitSprite->addChild(_HeroUnitHpBar, _UnitSprite->getZOrder());

		_HeroUnitHpBarBack = Sprite::create("UI/UnitHpBarBack.png");
		_HeroUnitHpBarBack->setPosition({ _UnitSprite->getContentSize().width / 2 - 7, _UnitSprite->getContentSize().height -90 });
		_UnitSprite->addChild(_HeroUnitHpBarBack, _UnitSprite->getZOrder() -1);

		_animation1 = Animation::create();
		_animation1->setDelayPerUnit(0.03f);
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u03_walk_0001.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u03_walk_0002.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u03_walk_0003.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u03_walk_0004.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u03_walk_0005.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u03_walk_0006.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u03_walk_0007.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u03_walk_0008.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u03_walk_0009.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u03_walk_0010.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u03_walk_0011.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u03_walk_0012.png"));
		_animate1 = Animate::create(_animation1);
		_walkAction = RepeatForever::create(_animate1);
		_walkAction->retain();
		_walkAction->setTag(UnitWalk);

		_animation2 = Animation::create();
		_animation2->setDelayPerUnit(0.03f);
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u03_att1_0001.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u03_att1_0002.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u03_att1_0003.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u03_att1_0004.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u03_att1_0005.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u03_att1_0006.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u03_att1_0007.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u03_att1_0008.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u03_att1_0009.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u03_att1_0010.png"));
		_animate2 = Animate::create(_animation2);
		_animate2->retain();
		_animate2->setTag(UnitAttack1);

		_animation2_1 = Animation::create();
		_animation2_1->setDelayPerUnit(0.03f);
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u03_att2_0001.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u03_att2_0002.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u03_att2_0003.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u03_att2_0004.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u03_att2_0005.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u03_att2_0006.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u03_att2_0007.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u03_att2_0008.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u03_att2_0009.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u03_att2_0010.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u03_att2_0011.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u03_att2_0012.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u03_att2_0013.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u03_att2_0014.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u03_att2_0015.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u03_att2_0016.png"));
		_animate2_1 = Animate::create(_animation2_1);
		_animate2_1->retain();
		_animate2_1->setTag(UnitAttack2);

		_animation3 = Animation::create();
		_animation3->setDelayPerUnit(0.03f);
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u03_dead_0001.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u03_dead_0002.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u03_dead_0003.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u03_dead_0004.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u03_dead_0005.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u03_dead_0006.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u03_dead_0007.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u03_dead_0008.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u03_dead_0009.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u03_dead_0010.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u03_dead_0011.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u03_dead_0012.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u03_dead_0013.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u03_dead_0014.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u03_dead_0015.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u03_dead_0016.png"));
		_animate3 = Animate::create(_animation3);
		_animate3->retain();
		_animate3->setTag(UnitDead);

		break;
	case 캥거루:
		_UnitSprite = Sprite::createWithSpriteFrameName("u04_walk_0001.png");
		_UnitSprite->setPosition(0, 420 + rand() % 40);
		_unitAction = UnitWalk;
		_Speed = Hero::getInstance()->getKangarooSpeed();
		_AtkSpeed = 1.0f;
		_MaxAtkSpeed = 1.0f;
		_Hp = Hero::getInstance()->getKangarooHp();
		_maxHP = Hero::getInstance()->getKangarooMaxHp();
		_Atk = Hero::getInstance()->getKangarooAtk();
		_Atk2 = Hero::getInstance()->getKangarooAtk2();
		_Range = 50 + rand() % 5;
		_unitKind = 캥거루;
		_Dead = false;
		_FirstAtk = false;
		layer->addChild(_UnitSprite, (_UnitSprite->getPositionY() - _UnitSprite->getContentSize().height / 2) * -1);

		_HeroUnitHpBar = ProgressTimer::create(Sprite::create("UI/HeroUnitHpBar.png"));
		_HeroUnitHpBar->setType(ProgressTimer::Type::BAR);
		_HeroUnitHpBar->setPosition({ _UnitSprite->getContentSize().width / 2 + 7, _UnitSprite->getContentSize().height - 90 });
		_HeroUnitHpBar->setMidpoint({ 0, 0 });
		_HeroUnitHpBar->setBarChangeRate({ 1,0 });
		_UnitSprite->addChild(_HeroUnitHpBar, _UnitSprite->getZOrder());

		_HeroUnitHpBarBack = Sprite::create("UI/UnitHpBarBack.png");
		_HeroUnitHpBarBack->setPosition({ _UnitSprite->getContentSize().width / 2 + 7, _UnitSprite->getContentSize().height - 90 });
		_UnitSprite->addChild(_HeroUnitHpBarBack, _UnitSprite->getZOrder() -1);

		_animation1 = Animation::create();
		_animation1->setDelayPerUnit(0.03f);
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u04_walk_0001.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u04_walk_0002.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u04_walk_0003.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u04_walk_0004.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u04_walk_0005.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u04_walk_0006.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u04_walk_0007.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u04_walk_0008.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u04_walk_0009.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u04_walk_0010.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u04_walk_0011.png"));
		_animation1->addSpriteFrame(cache->getSpriteFrameByName("u04_walk_0012.png"));
		_animate1 = Animate::create(_animation1);
		_walkAction = RepeatForever::create(_animate1);
		_walkAction->retain();
		_walkAction->setTag(UnitWalk);

		_animation2 = Animation::create();
		_animation2->setDelayPerUnit(0.03f);
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u04_att1_0001.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u04_att1_0002.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u04_att1_0003.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u04_att1_0004.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u04_att1_0005.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u04_att1_0006.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u04_att1_0007.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u04_att1_0008.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u04_att1_0009.png"));
		_animation2->addSpriteFrame(cache->getSpriteFrameByName("u04_att1_0010.png"));
		_animate2 = Animate::create(_animation2);
		_animate2->retain();
		_animate2->setTag(UnitAttack1);

		_animation2_1 = Animation::create();
		_animation2_1->setDelayPerUnit(0.03f);
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u04_att2_0001.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u04_att2_0002.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u04_att2_0003.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u04_att2_0004.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u04_att2_0005.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u04_att2_0006.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u04_att2_0007.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u04_att2_0008.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u04_att2_0009.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u04_att2_0010.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u04_att2_0011.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u04_att2_0012.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u04_att2_0013.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u04_att2_0014.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u04_att2_0015.png"));
		_animation2_1->addSpriteFrame(cache->getSpriteFrameByName("u04_att2_0016.png"));
		_animate2_1 = Animate::create(_animation2_1);
		_animate2_1->retain();
		_animate2_1->setTag(UnitAttack2);

		_animation3 = Animation::create();
		_animation3->setDelayPerUnit(0.03f);
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u04_dead_0001.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u04_dead_0002.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u04_dead_0003.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u04_dead_0004.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u04_dead_0005.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u04_dead_0006.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u04_dead_0007.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u04_dead_0008.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u04_dead_0009.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u04_dead_0010.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u04_dead_0011.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u04_dead_0012.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u04_dead_0013.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u04_dead_0014.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u04_dead_0015.png"));
		_animation3->addSpriteFrame(cache->getSpriteFrameByName("u04_dead_0016.png"));
		_animate3 = Animate::create(_animation3);
		_animate3->retain();
		_animate3->setTag(UnitDead);

		break;
	default:
		break;
	}

	// 영혼 나오는 애니메이션
	_animation4 = Animation::create();
	_animation4->setDelayPerUnit(0.03f);
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0001.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0002.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0003.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0004.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0005.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0006.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0007.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0008.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0009.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0010.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0011.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0012.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0013.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0014.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0015.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0016.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0017.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0018.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0019.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0020.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0021.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0022.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0023.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0024.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0025.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0026.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0027.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0028.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0029.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0030.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0031.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0032.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0033.png"));
	_animation4->addSpriteFrame(cache->getSpriteFrameByName("eff_die_0034.png"));
	_animate4 = Animate::create(_animation4);
	_animate4->retain();
	_animate4->setTag(UnitSoul);

	_animation5 = Animation::create();
	_animation5->setDelayPerUnit(0.1f);
	_animation5->addSpriteFrame(cache->getSpriteFrameByName("eff_aura2_0001.png"));
	_animation5->addSpriteFrame(cache->getSpriteFrameByName("eff_aura2_0002.png"));
	_animation5->addSpriteFrame(cache->getSpriteFrameByName("eff_aura2_0003.png"));
	_animation5->addSpriteFrame(cache->getSpriteFrameByName("eff_aura2_0004.png"));
	_animation5->addSpriteFrame(cache->getSpriteFrameByName("eff_aura2_0005.png"));
	_animation5->addSpriteFrame(cache->getSpriteFrameByName("eff_aura2_0006.png"));
	_animate5 = Animate::create(_animation5);
	_unitBuffOraRepeat = RepeatForever::create(_animate5);

	_unitBuffOra = Sprite::createWithSpriteFrameName("eff_aura2_0001.png");
	_unitBuffOra->setPosition(_UnitSprite->getContentSize().width / 2, 10);
	_unitBuffOra->setScale(0.8f);
	_UnitSprite->addChild(_unitBuffOra, _UnitSprite->getZOrder() - 1);
	_unitBuffOra->runAction(_unitBuffOraRepeat);
	_unitBuffOra->setVisible(false);

	// 히트 애니메이션
	_UnitHitAnimation1 = Animation::create();
	_UnitHitAnimation1->setDelayPerUnit(0.02f);
	_UnitHitAnimation1->addSpriteFrame(cache->getSpriteFrameByName("eff_hit_01_0001.png"));
	_UnitHitAnimation1->addSpriteFrame(cache->getSpriteFrameByName("eff_hit_01_0002.png"));
	_UnitHitAnimation1->addSpriteFrame(cache->getSpriteFrameByName("eff_hit_01_0003.png"));
	_UnitHitAnimation1->addSpriteFrame(cache->getSpriteFrameByName("eff_hit_01_0004.png"));
	_UnitHitAnimate1 = Animate::create(_UnitHitAnimation1);
	_UnitHitAnimate1->retain();

	_UnitHitAnimation2 = Animation::create();
	_UnitHitAnimation2->setDelayPerUnit(0.02f);
	_UnitHitAnimation2->addSpriteFrame(cache->getSpriteFrameByName("eff_hit_02_0001.png"));
	_UnitHitAnimation2->addSpriteFrame(cache->getSpriteFrameByName("eff_hit_02_0002.png"));
	_UnitHitAnimation2->addSpriteFrame(cache->getSpriteFrameByName("eff_hit_02_0003.png"));
	_UnitHitAnimation2->addSpriteFrame(cache->getSpriteFrameByName("eff_hit_02_0004.png"));
	_UnitHitAnimate2 = Animate::create(_UnitHitAnimation2);
	_UnitHitAnimate2->retain();

}

void HeroUnit::BringMonsterVec(vector<Monster*> monstervec)
{
	_monsterVec = monstervec;

	UnitDeadCheck(); // 유닛 생사여부 체크
	UnitMove(); // 유닛 이동
	UnitCollisionCheck(); // 유닛충돌체크
	ShowUnitHpBar(); // 히어로 유닛의 체력바를 보여줌

}

// 유닛 이동
void HeroUnit::UnitMove()
{
	// 포지션 이동
	if (_unitAction == UnitWalk && !_UnitSprite->getNumberOfRunningActionsByTag(UnitAttack1))
	{
		_UnitSprite->setPosition(_UnitSprite->getPosition() + Vec2(_Speed, 0));
	}

	// Walk 액션(애니메이션)
	if (_unitAction == UnitWalk && !_UnitSprite->getNumberOfRunningActionsByTag(UnitWalk))
	{
		_UnitSprite->stopActionByTag(UnitAttack1);
		_UnitSprite->runAction(_walkAction);
	}
}
void HeroUnit::UnitCollisionCheck()
{
	// 유닛 공격속도 체크
	if (_FirstAtk == true)
	{
		_AtkSpeed -= 0.01f;

		if (_AtkSpeed <= 0)
		{
			_AtkSpeed = _MaxAtkSpeed;
		}
	}

	// 유닛 충돌 체크
	for (int i = 0; i < _monsterVec.size(); ++i)
	{
		if (_monsterVec[i]->getMonster()->getPositionX() - _UnitSprite->getPositionX() - _Range <= 0)
		{
			_UnitSprite->stopActionByTag(UnitWalk);


			if (_unitAction != UnitCollision && _Dead == false)
			{
				_unitAction = UnitCollision;
			}

			if (!_UnitSprite->getNumberOfRunningActionsByTag(UnitAttack1))
			{
				if (_unitKind == 생쥐)
					_UnitSprite->setSpriteFrame("u01_walk_0001.png");

				if (_unitKind == 곰)
					_UnitSprite->setSpriteFrame("u03_walk_0001.png");

				if (_unitKind == 캥거루)
					_UnitSprite->setSpriteFrame("u04_walk_0001.png");
			}

			// 최초 충돌시 공격
			if (_unitAction == UnitCollision && _FirstAtk == false)
			{
				// 버프상태가 아닐떄
				if (_buff == false)
				{


					AttackAct = Sequence::create
					(_animate2,
						CallFunc::create(CC_CALLBACK_0(HeroUnit::UnitAttack, this)),
						/*DelayTime::create(_AtkSpeed),*/
						nullptr);
					AttackAct->setTag(UnitAttack1);

					if (!_UnitSprite->getNumberOfRunningActionsByTag(UnitAttack1))
					{
						_UnitSprite->runAction(AttackAct);
					}

					_FirstAtk = true;
				}

				// 버프상태일때
				if (_buff == true)
				{
					// 코드 설명 : 랜덤값을 받아 50% 확률로 강공격을 실행
					int RandNum = rand() % 2;

					if (RandNum == 0)
					{
						
						AttackAct = Sequence::create
						(_animate2,
							CallFunc::create(CC_CALLBACK_0(HeroUnit::UnitAttack, this)),
							/*DelayTime::create(_AtkSpeed),*/
							nullptr);
						AttackAct->setTag(UnitAttack1);

						if (!_UnitSprite->getNumberOfRunningActionsByTag(UnitAttack1))
						{
							_UnitSprite->runAction(AttackAct);
						}

						_FirstAtk = true;
					}

					if (RandNum == 1)
					{
						

						AttackAct = Sequence::create
						(_animate2_1,
							CallFunc::create(CC_CALLBACK_0(HeroUnit::UnitHeavyAttack, this)),
							/*DelayTime::create(_AtkSpeed),*/
							nullptr);
						AttackAct->setTag(UnitAttack1);

						if (!_UnitSprite->getNumberOfRunningActionsByTag(UnitAttack1))
						{
							_UnitSprite->runAction(AttackAct);
						}

						_FirstAtk = true;
					}
					
				}
				
			}

			// 최초 충돌 공격 이후 공격
			if (_unitAction == UnitCollision && _AtkSpeed == 1.0f && _FirstAtk == true)
			{
				if (_buff == false)
				{
					
					AttackAct = Sequence::create
					(_animate2,
						CallFunc::create(CC_CALLBACK_0(HeroUnit::UnitAttack, this)),
						/*DelayTime::create(_AtkSpeed),*/
						nullptr);
					AttackAct->setTag(UnitAttack1);

					if (!_UnitSprite->getNumberOfRunningActionsByTag(UnitAttack1))
					{
						_UnitSprite->runAction(AttackAct);
					}
				}

				if (_buff == true)
				{
					int RandNum = rand() % 2;

					if (RandNum == 0)
					{
						
						AttackAct = Sequence::create
						(_animate2,
							CallFunc::create(CC_CALLBACK_0(HeroUnit::UnitAttack, this)),
							/*DelayTime::create(_AtkSpeed),*/
							nullptr);
						AttackAct->setTag(UnitAttack1);

						if (!_UnitSprite->getNumberOfRunningActionsByTag(UnitAttack1))
						{
							_UnitSprite->runAction(AttackAct);
						}
					}

					if (RandNum == 1)
					{
						
						AttackAct = Sequence::create
						(_animate2_1,
							CallFunc::create(CC_CALLBACK_0(HeroUnit::UnitHeavyAttack, this)),
							/*DelayTime::create(_AtkSpeed),*/
							nullptr);
						AttackAct->setTag(UnitAttack1);

						if (!_UnitSprite->getNumberOfRunningActionsByTag(UnitAttack1))
						{
							_UnitSprite->runAction(AttackAct);
						}
					}

				}

			}

			return;
		}
		else
		{
			_unitAction = UnitWalk;
		}
	}

	// 몬스터 기지 충돌 체크
	if (_dungeon->getMonsterBase()->getPositionX() - _UnitSprite->getPositionX() - _Range + 70 <= 0 && _dungeon->getHp() > 0)
	{
		_UnitSprite->stopActionByTag(UnitWalk);


		if (_unitAction != UnitCollision && _Dead == false)
		{
			_unitAction = UnitCollision;
		}

		if (!_UnitSprite->getNumberOfRunningActionsByTag(UnitAttack1))
		{
			if (_unitKind == 생쥐)
				_UnitSprite->setSpriteFrame("u01_walk_0001.png");

			if (_unitKind == 곰)
				_UnitSprite->setSpriteFrame("u03_walk_0001.png");

			if (_unitKind == 캥거루)
				_UnitSprite->setSpriteFrame("u04_walk_0001.png");
		}

		// 최초 충돌시 공격
		if (_unitAction == UnitCollision && _FirstAtk == false)
		{
			if (_buff == false)
			{


				AttackAct = Sequence::create
				(_animate2,
					CallFunc::create(CC_CALLBACK_0(HeroUnit::UnitAttack, this)),
					/*DelayTime::create(_AtkSpeed),*/
					nullptr);
				AttackAct->setTag(UnitAttack1);

				if (!_UnitSprite->getNumberOfRunningActionsByTag(UnitAttack1))
				{
					_UnitSprite->runAction(AttackAct);
				}

				_FirstAtk = true;
			}

			if (_buff == true)
			{
				int RandNum = rand() % 2;

				if (RandNum == 0)
				{
					AttackAct = Sequence::create
					(_animate2,
						CallFunc::create(CC_CALLBACK_0(HeroUnit::UnitAttack, this)),
						/*DelayTime::create(_AtkSpeed),*/
						nullptr);
					AttackAct->setTag(UnitAttack1);

					if (!_UnitSprite->getNumberOfRunningActionsByTag(UnitAttack1))
					{
						_UnitSprite->runAction(AttackAct);
					}

					_FirstAtk = true;
				}

				if (RandNum == 1)
				{
					AttackAct = Sequence::create
					(_animate2_1,
						CallFunc::create(CC_CALLBACK_0(HeroUnit::UnitHeavyAttack, this)),
						/*DelayTime::create(_AtkSpeed),*/
						nullptr);
					AttackAct->setTag(UnitAttack1);

					if (!_UnitSprite->getNumberOfRunningActionsByTag(UnitAttack1))
					{
						_UnitSprite->runAction(AttackAct);
					}

					_FirstAtk = true;
				}

			}
		}

		// 최초 충돌 공격 이후 공격
		if (_unitAction == UnitCollision && _AtkSpeed == 1.0f && _FirstAtk == true)
		{
			if (_buff == false)
			{
				AttackAct = Sequence::create
				(_animate2,
					CallFunc::create(CC_CALLBACK_0(HeroUnit::UnitAttack, this)),
					/*DelayTime::create(_AtkSpeed),*/
					nullptr);
				AttackAct->setTag(UnitAttack1);

				if (!_UnitSprite->getNumberOfRunningActionsByTag(UnitAttack1))
				{
					_UnitSprite->runAction(AttackAct);
				}
			}

			if (_buff == true)
			{
				int RandNum = rand() % 2;

				if (RandNum == 0)
				{
					AttackAct = Sequence::create
					(_animate2,
						CallFunc::create(CC_CALLBACK_0(HeroUnit::UnitAttack, this)),
						/*DelayTime::create(_AtkSpeed),*/
						nullptr);
					AttackAct->setTag(UnitAttack1);

					if (!_UnitSprite->getNumberOfRunningActionsByTag(UnitAttack1))
					{
						_UnitSprite->runAction(AttackAct);
					}
				}

				if (RandNum == 1)
				{
					AttackAct = Sequence::create
					(_animate2_1,
						CallFunc::create(CC_CALLBACK_0(HeroUnit::UnitHeavyAttack, this)),
						/*DelayTime::create(_AtkSpeed),*/
						nullptr);
					AttackAct->setTag(UnitAttack1);

					if (!_UnitSprite->getNumberOfRunningActionsByTag(UnitAttack1))
					{
						_UnitSprite->runAction(AttackAct);
					}
				}

			}

		}
	}
}

// 일반공격
void HeroUnit::UnitAttack()
{
	// 몬스터 유닛을 공격
	for (int i = 0; i < _monsterVec.size(); ++i)
	{
		if (_monsterVec[i]->getMonster()->getPositionX() - _UnitSprite->getPositionX() - _Range <= 0)
		{
			// 히트시 잠시 빨간색으로 바뀌는효과
			_monsterVec[i]->getMonster()->runAction(Sequence::createWithTwoActions(TintTo::create(0, Color3B::RED), TintTo::create(0.1f, Color3B::WHITE)));

			_hitAnimationBox = Sprite::createWithSpriteFrameName("eff_hit_01_0001.png");
			_hitAnimationBox->setOpacity(255);
			_layer->addChild(_hitAnimationBox, _monsterVec[i]->getMonster()->getZOrder());
			_hitAnimationBox->setPosition(_monsterVec[i]->getMonster()->getPosition());

			// 랜덤으로 두가지 히트 이펙트중 하나를 보여준다
			int RanNum = rand() % 2;

			if (RanNum == 1)
				_hitAnimationBox->runAction(Sequence::create(_UnitHitAnimate1, RemoveSelf::create(true), nullptr));
			else
				_hitAnimationBox->runAction(Sequence::create(_UnitHitAnimate2, RemoveSelf::create(true), nullptr));


			_monsterVec[i]->Hit(_Atk);
			
			return;
		}
	}

	// 몬스터 기지를 공격
	if (_dungeon->getMonsterBase()->getPositionX() - _UnitSprite->getPositionX() - _Range + 70 <= 0 && _dungeon->getHp() > 0)
	{
		// 히트시 잠시 빨간색으로 바뀌는효과
		_dungeon->getMonsterBase()->runAction(Sequence::createWithTwoActions(TintTo::create(0, Color3B::RED), TintTo::create(0.1f, Color3B::WHITE)));

		_hitAnimationBox = Sprite::createWithSpriteFrameName("eff_hit_01_0001.png");
		_hitAnimationBox->setOpacity(255);
		_layer->addChild(_hitAnimationBox, _dungeon->getMonsterBase()->getZOrder());
		_hitAnimationBox->setPosition(_dungeon->getMonsterBase()->getPosition().x + 70, _dungeon->getMonsterBase()->getPosition().y + 60);

		// 랜덤으로 두가지 히트 이펙트중 하나를 보여준다
		int RanNum = rand() % 2;

		if (RanNum == 1)
			_hitAnimationBox->runAction(Sequence::create(_UnitHitAnimate1, RemoveSelf::create(true), nullptr));
		else
			_hitAnimationBox->runAction(Sequence::create(_UnitHitAnimate2, RemoveSelf::create(true), nullptr));

		_dungeon->Hit(_Atk);
	}

	//_Hp -= 60; // 죽는모션테스트용
}

// 강공격(버프상태시 확률적으로 발동)
void HeroUnit::UnitHeavyAttack()
{
	// 몬스터 유닛을 공격
	for (int i = 0; i < _monsterVec.size(); ++i)
	{
		if (_monsterVec[i]->getMonster()->getPositionX() - _UnitSprite->getPositionX() - _Range <= 0)
		{
			// 히트시 잠시 빨간색으로 바뀌는효과
			_monsterVec[i]->getMonster()->runAction(Sequence::createWithTwoActions(TintTo::create(0, Color3B::RED), TintTo::create(0.1f, Color3B::WHITE)));

			_hitAnimationBox = Sprite::createWithSpriteFrameName("eff_hit_01_0001.png");
			_hitAnimationBox->setOpacity(255);
			_layer->addChild(_hitAnimationBox, _monsterVec[i]->getMonster()->getZOrder());
			_hitAnimationBox->setPosition(_monsterVec[i]->getMonster()->getPosition());

			// 랜덤으로 두가지 히트 이펙트중 하나를 보여준다
			int RanNum = rand() % 2;

			if (RanNum == 1)
				_hitAnimationBox->runAction(Sequence::create(_UnitHitAnimate1, RemoveSelf::create(true), nullptr));
			else
				_hitAnimationBox->runAction(Sequence::create(_UnitHitAnimate2, RemoveSelf::create(true), nullptr));


			_monsterVec[i]->Hit(_Atk2);

			return;
		}
	}

	// 몬스터 기지를 공격
	if (_dungeon->getMonsterBase()->getPositionX() - _UnitSprite->getPositionX() - _Range + 70 <= 0 && _dungeon->getHp() > 0)
	{
		// 히트시 잠시 빨간색으로 바뀌는효과
		_dungeon->getMonsterBase()->runAction(Sequence::createWithTwoActions(TintTo::create(0, Color3B::RED), TintTo::create(0.1f, Color3B::WHITE)));

		_hitAnimationBox = Sprite::createWithSpriteFrameName("eff_hit_01_0001.png");
		_hitAnimationBox->setOpacity(255);
		_layer->addChild(_hitAnimationBox, _dungeon->getMonsterBase()->getZOrder());
		_hitAnimationBox->setPosition(_dungeon->getMonsterBase()->getPosition().x + 70, _dungeon->getMonsterBase()->getPosition().y + 60);

		// 랜덤으로 두가지 히트 이펙트중 하나를 보여준다
		int RanNum = rand() % 2;

		if (RanNum == 1)
			_hitAnimationBox->runAction(Sequence::create(_UnitHitAnimate1, RemoveSelf::create(true), nullptr));
		else
			_hitAnimationBox->runAction(Sequence::create(_UnitHitAnimate2, RemoveSelf::create(true), nullptr));

		_dungeon->Hit(_Atk2);
	}

	//_Hp -= 60; // 죽는모션테스트용
}

void HeroUnit::UnitDeadCheck()
{
	if (_Hp <= 0 && !_UnitSprite->getNumberOfRunningActionsByTag(UnitDead) && _Dead == false)
	{
		_unitAction = UnitDead;
		_UnitSprite->stopAllActions();
		_UnitSprite->runAction(MoveBy::create(0.2, Vec2(-50,0)));
		DeadAct = Sequence::create(_animate3, CallFunc::create(CC_CALLBACK_0(HeroUnit::ShowUnitDeadSoul, this)),DelayTime::create(1.f), FadeOut::create(1.f),RemoveSelf::create(true), nullptr);
		_UnitSprite->runAction(DeadAct);
	
		_Dead = true;
	}
}

void HeroUnit::ShowUnitHpBar()
{
	if (_Hp == _maxHP)
	{
		_HeroUnitHpBar->setVisible(false);
		_HeroUnitHpBarBack->setVisible(false);
	}
	else
	{
		_HeroUnitHpBar->setVisible(true);
		_HeroUnitHpBarBack->setVisible(true);
	}

	_HeroUnitHpBar->setPercentage((_Hp / _maxHP) * 100);
}

void HeroUnit::ShowUnitDeadSoul()
{
	_UnitDeadAnimateBox->setPosition(_UnitSprite->getPosition());
	_UnitDeadAnimateBox->setVisible(true);
	_UnitDeadAnimateBox->runAction(Sequence::create(_animate4, RemoveSelf::create(true), nullptr));
}

void HeroUnit::Healing()
{
	_Hp += 50;

	if (_Hp > _maxHP)
		_Hp = _maxHP;
}
