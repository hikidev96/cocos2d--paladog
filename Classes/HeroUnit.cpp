#include "HeroUnit.h"
#include "Monster.h"

HeroUnit::HeroUnit(Scene * scene, UnitKind herokind, Layer* layer)
{
	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Player/Unit/u_01.plist");
	cache->addSpriteFramesWithFile("Player/Unit/u_02.plist");
	cache->addSpriteFramesWithFile("Player/Unit/u_03.plist");

	srand((unsigned)time(NULL));

	switch (herokind) 
	{
	case »ýÁã:
		_UnitSprite = Sprite::createWithSpriteFrameName("u01_walk_0001.png");
		_UnitSprite->setPosition(0, 360 + rand() % 30);
		_unitAction = UnitWalk;
		_Speed = 0.6f;
		_Hp = 1.0f;
		_Atk = 500.f;
		_Range = 50;
		_unitKind = »ýÁã;
		_Dead = false;
		layer->addChild(_UnitSprite, 100);

		_HeroUnitHpBar = ProgressTimer::create(Sprite::create("UI/HeroUnitHpBar.png"));
		_HeroUnitHpBar->setType(ProgressTimer::Type::BAR);
		_HeroUnitHpBar->setPosition({ _UnitSprite->getContentSize().width / 2, _UnitSprite->getContentSize().height + 3 });
		_HeroUnitHpBar->setMidpoint({ 0, 0 });
		_HeroUnitHpBar->setBarChangeRate({ 1,0 });
		_HeroUnitHpBar->setPercentage(100);
		_UnitSprite->addChild(_HeroUnitHpBar);

		_HeroUnitHpBarBack = Sprite::create("UI/UnitHpBarBack.png");
		_HeroUnitHpBarBack->setPosition({ _UnitSprite->getContentSize().width / 2, _UnitSprite->getContentSize().height + 3 });
		_UnitSprite->addChild(_HeroUnitHpBarBack, -10);

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
		_UnitSprite->setPosition(0, 360 + rand() % 30);
		_unitAction = UnitWalk;
		_Speed = 0.6f;
		_Hp = 1.0f;
		_Atk = 500.f;
		_Range = 50;
		_unitKind = °õ;
		_Dead = false;
		layer->addChild(_UnitSprite);

		_HeroUnitHpBar = ProgressTimer::create(Sprite::create("UI/HeroUnitHpBar.png"));
		_HeroUnitHpBar->setType(ProgressTimer::Type::BAR);
		_HeroUnitHpBar->setPosition({ _UnitSprite->getContentSize().width / 2, _UnitSprite->getContentSize().height + 3 });
		_HeroUnitHpBar->setMidpoint({ 0, 0 });
		_HeroUnitHpBar->setBarChangeRate({ 1,0 });
		_HeroUnitHpBar->setPercentage(100);
		_UnitSprite->addChild(_HeroUnitHpBar);

		_HeroUnitHpBarBack = Sprite::create("UI/UnitHpBarBack.png");
		_HeroUnitHpBarBack->setPosition({ _UnitSprite->getContentSize().width / 2, _UnitSprite->getContentSize().height + 3 });
		_UnitSprite->addChild(_HeroUnitHpBarBack, -10);

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
		_UnitSprite->setPosition(0, 360 + rand() % 30);
		_unitAction = UnitWalk;
		_Speed = 0.6f;
		_Hp = 1.0f;
		_Atk = 500.f;
		_Range = 50;
		_unitKind = Ä»°Å·ç;
		_Dead = false;
		layer->addChild(_UnitSprite);

		_HeroUnitHpBar = ProgressTimer::create(Sprite::create("UI/HeroUnitHpBar.png"));
		_HeroUnitHpBar->setType(ProgressTimer::Type::BAR);
		_HeroUnitHpBar->setPosition({ _UnitSprite->getContentSize().width / 2, _UnitSprite->getContentSize().height + 3 });
		_HeroUnitHpBar->setMidpoint({ 0, 0 });
		_HeroUnitHpBar->setBarChangeRate({ 1,0 });
		_HeroUnitHpBar->setPercentage(100);
		_UnitSprite->addChild(_HeroUnitHpBar);

		_HeroUnitHpBarBack = Sprite::create("UI/UnitHpBarBack.png");
		_HeroUnitHpBarBack->setPosition({ _UnitSprite->getContentSize().width / 2, _UnitSprite->getContentSize().height + 3 });
		_UnitSprite->addChild(_HeroUnitHpBarBack, -10);

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

void HeroUnit::BringMonsterVec(vector<Monster*> monstervec)
{
	_monsterVec = monstervec;

	UnitDeadCheck();
	UnitMove(); // À¯´Ö ÀÌµ¿
	UnitCollisionCheck();

}

// À¯´Ö ÀÌµ¿
void HeroUnit::UnitMove()
{
	// Æ÷Áö¼Ç ÀÌµ¿
	if (_unitAction == UnitWalk)
	{
		_UnitSprite->setPosition(_UnitSprite->getPosition() + Vec2(_Speed, 0));
	}

	// Walk ¾×¼Ç(¾Ö´Ï¸ÞÀÌ¼Ç)
	if (_unitAction == UnitWalk && !_UnitSprite->getNumberOfRunningActionsByTag(UnitWalk))
	{
		_UnitSprite->stopActionByTag(UnitAttack1);
		_UnitSprite->runAction(_walkAction);
	}
}
void HeroUnit::UnitCollisionCheck()
{
	// À¯´Ö Ãæµ¹ Ã¼Å©
	for (int i = 0; i < _monsterVec.size(); ++i)
	{
		if (_monsterVec[i]->getMonster()->getPositionX() - _UnitSprite->getPositionX() - _Range <= 0)
		{
			_UnitSprite->stopActionByTag(UnitWalk);


			if (_unitAction != UnitCollision && _Dead == false)
			{
				_unitAction = UnitCollision;
			}

			if (_unitAction == UnitCollision)
			{
				AttackAct = RepeatForever::create(Sequence::create
				(_animate2,
				CallFunc::create(CC_CALLBACK_0(HeroUnit::UnitAttack, this)),
				DelayTime::create(1.f),
				nullptr));
				AttackAct->setTag(UnitAttack1);

				if (!_UnitSprite->getNumberOfRunningActionsByTag(UnitAttack1))
				{
					_UnitSprite->runAction(AttackAct);
				}
			}

			return;
		}
		else
		{
			_unitAction = UnitWalk;
		}
	}
}
void HeroUnit::UnitAttack()
{
	//for (int i = 0; i < _monsterVec.size(); ++i)
	//{
	//	if (_monsterVec[i]->getMonster()->getPositionX() - _UnitSprite->getPositionX() - _Range <= 0)
	//	{
	//		_monsterVec[i]->Hit(_Atk);
	//		return;
	//	}
	//}

	_Hp = 0;
}

void HeroUnit::UnitDeadCheck()
{
	if (_Hp <= 0 && !_UnitSprite->getNumberOfRunningActionsByTag(UnitDead) && _Dead == false)
	{
		_unitAction = UnitDead;
		_UnitSprite->stopAllActions();
		DeadAct = Sequence::create(_animate3, RemoveSelf::create(true), nullptr);
		_UnitSprite->runAction(DeadAct);
		_Dead = true;
	}
}

