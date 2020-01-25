#include "HeroUnit.h"
#include "Monster.h"

HeroUnit::HeroUnit(Scene * scene, UnitKind herokind, Layer* layer)
{
	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Player/Unit/u_01_1.plist");
	cache->addSpriteFramesWithFile("Player/Unit/u_02_1.plist");
	cache->addSpriteFramesWithFile("Player/Unit/u_03_1.plist");
	cache->addSpriteFramesWithFile("eff_blend_02.plist");

	srand((unsigned)time(NULL));

	// ������ ��ȥ������ �ִϸ��̼� ���� ��������Ʈ
	_UnitDeadAnimateBox = Sprite::createWithSpriteFrameName("eff_die_0001.png");
	_UnitDeadAnimateBox->setVisible(false);
	layer->addChild(_UnitDeadAnimateBox);

	switch (herokind) 
	{
	case ����:
		_UnitSprite = Sprite::createWithSpriteFrameName("u01_walk_0001.png");
		_UnitSprite->setPosition(0, 420 + rand() % 40);
		_unitAction = UnitWalk;
		_Speed = 0.6f;
		_AtkSpeed = 1.0f;
		_MaxAtkSpeed = 1.0f;
		_Hp = 100.0f;
		_maxHP = 100.0f;
		_Atk = 500.f;
		_Range = 50 + rand() % 5;
		_unitKind = ����;
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
	case ��:
		_UnitSprite = Sprite::createWithSpriteFrameName("u03_walk_0001.png");
		_UnitSprite->setPosition(0, 420 + rand() % 40);
		_unitAction = UnitWalk;
		_Speed = 0.6f;
		_AtkSpeed = 1.0f;
		_MaxAtkSpeed = 1.0f;
		_Hp = 200.0f;
		_maxHP = 200.0f;
		_Atk = 500.f;
		_Range = 50 + rand() % 5;
		_unitKind = ��;
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
	case Ļ�ŷ�:
		_UnitSprite = Sprite::createWithSpriteFrameName("u04_walk_0001.png");
		_UnitSprite->setPosition(0, 420 + rand() % 40);
		_unitAction = UnitWalk;
		_Speed = 0.6f;
		_AtkSpeed = 1.0f;
		_MaxAtkSpeed = 1.0f;
		_Hp = 300.0f;
		_maxHP = 300.0f;
		_Atk = 500.f;
		_Range = 50 + rand() % 5;
		_unitKind = Ļ�ŷ�;
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

	// ��ȥ ������ �ִϸ��̼�
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
}

void HeroUnit::BringMonsterVec(vector<Monster*> monstervec)
{
	_monsterVec = monstervec;

	UnitDeadCheck(); // ���� ���翩�� üũ
	UnitMove(); // ���� �̵�
	UnitCollisionCheck(); // �����浹üũ
	ShowUnitHpBar(); // ����� ������ ü�¹ٸ� ������

}

// ���� �̵�
void HeroUnit::UnitMove()
{
	// ������ �̵�
	if (_unitAction == UnitWalk && !_UnitSprite->getNumberOfRunningActionsByTag(UnitAttack1))
	{
		_UnitSprite->setPosition(_UnitSprite->getPosition() + Vec2(_Speed, 0));
	}

	// Walk �׼�(�ִϸ��̼�)
	if (_unitAction == UnitWalk && !_UnitSprite->getNumberOfRunningActionsByTag(UnitWalk))
	{
		_UnitSprite->stopActionByTag(UnitAttack1);
		_UnitSprite->runAction(_walkAction);
	}
}
void HeroUnit::UnitCollisionCheck()
{
	// ���� ���ݼӵ� üũ
	if (_FirstAtk == true)
	{
		_AtkSpeed -= 0.01f;

		if (_AtkSpeed <= 0)
		{
			_AtkSpeed = _MaxAtkSpeed;
		}
	}

	// ���� �浹 üũ
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
				if (_unitKind == ����)
					_UnitSprite->setSpriteFrame("u01_walk_0001.png");

				if (_unitKind == ��)
					_UnitSprite->setSpriteFrame("u03_walk_0001.png");

				if (_unitKind == Ļ�ŷ�)
					_UnitSprite->setSpriteFrame("u04_walk_0001.png");
			}

			// ���� �浹�� ����
			if (_unitAction == UnitCollision && _FirstAtk == false)
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

			// ���� �浹 ���� ���� ����
			if (_unitAction == UnitCollision && _AtkSpeed == 1.0f && _FirstAtk == true)
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
	/*for (int i = 0; i < _monsterVec.size(); ++i)
	{
		if (_monsterVec[i]->getMonster()->getPositionX() - _UnitSprite->getPositionX() - _Range <= 0)
		{
			_monsterVec[i]->Hit(_Atk);
			
			return;
		}
	}*/

	_Hp -= 60; // �״¸���׽�Ʈ��
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

