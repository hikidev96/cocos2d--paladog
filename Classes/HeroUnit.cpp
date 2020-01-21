#include "HeroUnit.h"

HeroUnit::HeroUnit(Scene * scene, UnitKind herokind, Layer* layer)
{
	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Player/Unit/u_01.plist");
	cache->addSpriteFramesWithFile("Player/Unit/u_02.plist");
	cache->addSpriteFramesWithFile("Player/Unit/u_03.plist");


	switch (herokind)
	{
	case »ıÁã:
		srand(time(NULL));
		_UnitSprite = Sprite::createWithSpriteFrameName("u01_walk_0001.png");
		_UnitSprite->setPosition(100, 400 + rand() % 80);
		_unitAction = UnitWalk;
		_Speed = 0.6f;
		_Hp = 1.0f;
		_Atk = 0.6f;
		_unitKind = »ıÁã;
		layer->addChild(_UnitSprite, 100);

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
	case °õ:
		_UnitSprite = Sprite::createWithSpriteFrameName("u03_walk_0001.png");
		_UnitSprite->setPosition(100, 420);
		_unitAction = UnitWalk;
		_Speed = 0.6f;
		_Hp = 1.0f;
		_Atk = 0.6f;
		_unitKind = °õ;
		layer->addChild(_UnitSprite);

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
	case Ä»°Å·ç:
		_UnitSprite = Sprite::createWithSpriteFrameName("u04_walk_0001.png");
		_UnitSprite->setPosition(100, 420);
		_unitAction = UnitWalk;
		_Speed = 0.6f;
		_Hp = 1.0f;
		_Atk = 0.6f;
		_unitKind = Ä»°Å·ç;
		layer->addChild(_UnitSprite);

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
}