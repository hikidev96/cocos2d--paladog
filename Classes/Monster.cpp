#include "cocos_framework.h"
#include "Monster.h"

Monster::Monster(Scene* scene, Layer* layer, vector<HeroUnit*> unit, Mob mob)
{
	_scene = scene;
	_layer = layer;
	_unit = unit;

	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Player/effect/eff_blend_02.plist");
	switch (mob) {
	case 일반좀비:
		cache->addSpriteFramesWithFile("Monster/monster/Nzombie.plist");
		_monsterCode = "e01";
		_atkMaxFrame = 10;
		_atk = 60;
		_hpm = 1300;
		_range = 70;
		_delay = 2.0f;
		_speed = 0.5f;
		_exp = 5;
		_money = 100;
		break;
	case 강화좀비:
		cache->addSpriteFramesWithFile("Monster/monster/Uzombie.plist");
		_monsterCode = "e21";
		_atkMaxFrame = 10;
		_atk =75;
		_hpm = 1900;
		_range = 70;
		_delay = 1.8f;
		_speed = 0.6f;
		_exp = 10;
		_money = 200;
		break;
	case 광부좀비:
		cache->addSpriteFramesWithFile("Monster/monster/Mzombie.plist");
		_monsterCode = "e13";
		_atkMaxFrame = 15;
		_atk = 100;
		_hpm = 2500;
		_range = 80;
		_delay = 2.5f;
		_speed = 0.4f;
		_exp = 15;
		_money = 300;
		break;
	case 일반미라:
		cache->addSpriteFramesWithFile("Monster/monster/mummy.plist");
		cache->addSpriteFramesWithFile("Monster/monster/mummymove.plist");
		_monsterCode = "e07";
		_atkMaxFrame = 15;
		_atk = 100;
		_hpm = 2900;
		_range = 120;
		_delay = 2.0f;
		_speed = 0.5f;
		_exp = 20;
		_money = 400;
		break;
	case 핑크미라:
		cache->addSpriteFramesWithFile("Monster/monster/Pmummy.plist");
		cache->addSpriteFramesWithFile("Monster/monster/Pmummymove.plist");
		_monsterCode = "e27";
		_atkMaxFrame = 15;
		_atk = 40;
		_hpm = 3500;
		_range = 120;
		_delay = 1.7f;
		_speed = 0.7f;
		_exp = 30;
		_money = 500;
		break;
	case 좀비킹:
		cache->addSpriteFramesWithFile("Monster/monster/Zomking.plist");
		_monsterCode = "b01";
		_atkMaxFrame = 30;
		_atk = 0;
		_hpm = 10000;
		_range = 300;
		_delay = 3.0f;
		_speed = 0.6f;
		_exp = 50;
		_money = 1000;
		break;
	}
	_hp = _hpm;
	_state = WALK;
	_moveChange = 1;
	_isAttackDelay = 0;//0:공격전, 1:공격중(이동불가), 2:공격후(이동가능)
	_isRemove = false;
	_isSummonX = 0;
	_time = 0;
	_unitAttack = -1;
	_isBossDead = false;
	//AudioEngine::play2d("Sound/sword_01.mp3", false, 1.0f);

	int zorder = rand() % 30;
	_monster = Sprite::createWithSpriteFrameName(StringUtils::format("%s_walk_0001.png", _monsterCode));
	_monster->setPosition(1000, zorder + Hero::getInstance()->getHero()->getPositionY() - 17);
	_layer->addChild(_monster, Hero::getInstance()->getHero()->getZOrder() + 15 - zorder);
}

void Monster::MonsterMove()
{
	if (_isAttackDelay != 0) {
		if (++_time >= _delay * 60) {
			_isAttackDelay = 0;
			_time = 0;
		};
	}
	bool _isAttackRange = false;
	_isSummonX = 0;
	for (int i = 0; i < _unit.size(); i++) {
		if (_unit[i]->getSprite()->getPositionX() < _monster->getPositionX() &&
			_unit[i]->getSprite()->getPositionX() > _monster->getPositionX() - _range) {
			if (_state != DEAD && _isAttackDelay == 0) {
				_moveChange = true;
				_state = ATTACK;
				_isAttackDelay = 1;
				break;
			}
			_isAttackRange = true;
		}
	}
	if (Hero::getInstance()->getHero()->getPositionX() < _monster->getPositionX() &&
		Hero::getInstance()->getHero()->getPositionX() > _monster->getPositionX() - _range) {
		if (_state != DEAD && _isAttackDelay == 0) {
			_moveChange = true;
			_state = ATTACK;
			_isAttackDelay = 1;
		}
		_isAttackRange = true;
	}
	
	if (_state == ATTACK && !_moveChange && !_isAttackRange && _isAttackDelay != 1) {
		_moveChange = true;
		_state = WALK;
	}
	if (_state == WALK) {
		if (_isAttackRange) {
			_monster->setSpriteFrame(StringUtils::format("%s_att_%04d.png", _monsterCode, _atkMaxFrame));
		}
		else {
			Walk();
		}
	}
	if (_moveChange) {
		_moveChange = 0;
		_monster->cleanup();
		
		Vector<SpriteFrame*> frame, frame2;
		if (_state == WALK) {
			for (int i = 1; i <= 12; i++) {
				frame.pushBack(SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(StringUtils::format("%s_walk_%04d.png", _monsterCode, i)));
			}
			auto animation = Animation::createWithSpriteFrames(frame, 0.08f);
			auto animate = Animate::create(animation);
			auto action = RepeatForever::create(animate);
			_monster->runAction(action);
		}
		else if (_state == ATTACK)
		{
			for (int i = 1; i <= _atkMaxFrame; i++) {
				frame.pushBack(SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(StringUtils::format("%s_att_%04d.png", _monsterCode, i)));
			}
			auto animation = Animation::createWithSpriteFrames(frame, 0.04f);
			auto animate = Animate::create(animation);
			if (strcmp(_monsterCode, "b01") == 0) { //좀비킹 공격모션
				for (int i = 1; i <= 12; i++) {
					frame2.pushBack(SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(StringUtils::format("b01_wait_%04d.png", i)));
				}

				auto animation2 = Animation::createWithSpriteFrames(frame2, 0.04f);
				auto animate2 = Animate::create(animation2);

				auto action = Sequence::create(
					animate,
					Spawn::create(animate2, CallFunc::create(CC_CALLBACK_0(Monster::ZomkingSummon, this)), nullptr),
					nullptr);
				_monster->runAction(action);

			}
			else {
				auto action = Sequence::create(
					animate,
					CallFunc::create(CC_CALLBACK_0(Monster::Attack, this)),
					nullptr);
				_monster->runAction(action);
			}
		}
		else if (_state == DEAD) {
			for (int i = 1; i <= 16; i++) {
				frame.pushBack(SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(StringUtils::format("%s_down_%04d.png", _monsterCode, i)));
			}
			auto animation = Animation::createWithSpriteFrames(frame, 0.04f);
			auto animate = Animate::create(animation);

			for (int i = 1; i <= 34; i++) {
				frame2.pushBack(SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(StringUtils::format("eff_die_%04d.png", i))); //eff_enemydie_%04d.png <- 몬스터
			}

			auto animation2 = Animation::createWithSpriteFrames(frame2, 0.04f);
			auto animate2 = Animate::create(animation2);

			Hero::getInstance()->setExp(Hero::getInstance()->getExp() + _exp);
			Hero::getInstance()->setGold(Hero::getInstance()->getGold() + _money);

			auto action = Sequence::create(
				Spawn::create(animate, MoveBy::create(0.48, Vec2(70, 0)), nullptr),
				animate2,
				CallFunc::create(CC_CALLBACK_0(Monster::Dead, this)),
				nullptr
			);
			_monster->runAction(action);
			if (strcmp(_monsterCode, "b01") == 0) { //좀비킹주금
				_isBossDead = true;
			}
		}
	}
}

void Monster::Hit(float atk)
{
	if (_hp == _hpm) {
		_monsterHpBar = ProgressTimer::create(Sprite::create("UI/MonsterUnitHpBar.png"));
		_monsterHpBar->setType(ProgressTimer::Type::BAR);
		if (_monsterCode == "b01") {
			_monsterHpBar->setPosition( _monster->getContentSize().width / 2 - 3, _monster->getContentSize().height - 50 );
		}
		else {
			_monsterHpBar->setPosition( _monster->getContentSize().width / 2 - 3, _monster->getContentSize().height - 90);
		}
		_monsterHpBar->setMidpoint({ 0, 0 });
		_monsterHpBar->setBarChangeRate({ 1,0 });
		_monster->addChild(_monsterHpBar);

		_monsterHpBarBack = Sprite::create("UI/UnitHpBarBack.png");
		_monsterHpBarBack->setPosition(_monsterHpBar->getPosition());
		_monster->addChild(_monsterHpBarBack, -10);
	}
	if (_hp > 0) {
		_hp -= atk;
		_monsterHpBar->setPercentage((_hp / _hpm) * 100);
	}
	if (_hp <= 0 && _state != DEAD) {
		_hp = 0;
		_state = DEAD;
		_moveChange = true;
		_monster->removeChild(_monsterHpBar, 1);
		_monster->removeChild(_monsterHpBarBack, 1);
	}
}

void Monster::Walk()
{
	_monster->setPosition(_monster->getPosition() + Vec2(-_speed, 0));
	if (getMonster()->getPosition().x < 0) {
		_monster->setPositionX(1000);
	}
}

void Monster::Attack()
{
	float distance = _monster->getPositionX() - Hero::getInstance()->getHero()->getPositionX() < 0 ? 9999 :
		_monster->getPositionX() - Hero::getInstance()->getHero()->getPositionX();
	int target = -1;
	float temp;
	for (int i = 0; i < _unit.size(); i++) {
		temp = _monster->getPositionX() - _unit[i]->getSprite()->getPositionX() < 0 ? 9999 :
			_monster->getPositionX() - _unit[i]->getSprite()->getPositionX();
		distance = min(distance, temp);
		if (temp == distance) target = i;
	}
	switch (target) {
	case -1:
		Hero::getInstance()->setHp(Hero::getInstance()->getHp() - _atk);
		break;
	default:
		_unitAttack = target;
		break;
	}
	_isAttackDelay = 2;
}

void Monster::ZomkingSummon()
{
	_isSummonX = _monster->getPositionX();

	_summon = Sprite::createWithSpriteFrameName("b01_summon_0001.png");
	_summon->setPosition(_monster->getPosition());
	_layer->addChild(_summon, Hero::getInstance()->getHero()->getZOrder() + 15);

	Vector<SpriteFrame*> frame;

	for (int i = 1; i <= 15; i++) {
		frame.pushBack(SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(StringUtils::format("b01_summon_%04d.png", i)));
	}
	auto animation = Animation::createWithSpriteFrames(frame, 0.03f);
	auto animate = Animate::create(animation);
	_summon->runAction(Sequence::create(animate, CallFunc::create(CC_CALLBACK_0(Monster::ZomkingSummonRemove, this)), nullptr));
	_isAttackDelay = 2;
}

void Monster::ZomkingSummonRemove()
{
	_layer->removeChild(_summon);
}

void Monster::Dead()
{
	_isRemove = true;
}

void Monster::setSummunPositionX(float x)
{
	_monster->setPositionX(x - 50 + rand() % 100);
}
