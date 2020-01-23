#include "cocos_framework.h"
#include "Monster.h"

Monster::Monster(Scene* scene, Layer* layer, Hero* hero, vector<HeroUnit*> unit, Mob mob)
{
	_scene = scene;
	_layer = layer;
	_hero = hero;
	_unit = unit;

	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Player/effect/eff_blend_02.plist");
	switch (mob) {
	case 걷는좀비:
		cache->addSpriteFramesWithFile("Monster/monster/Nzombie.plist");
		_monsterCode = "e01";
		_atkMaxFrame = 10;
		_atk = 10;
		_hpm = 50;
		_range = 50;
		_delay = 2.0f;
		_speed = 0.8f;
		_exp = 5;
		_money = 1;
		break;
	case 분홍미라:
		cache->addSpriteFramesWithFile("Monster/monster/Pmummy.plist");
		cache->addSpriteFramesWithFile("Monster/monster/Pmummymove.plist");
		_monsterCode = "e27";
		_atkMaxFrame = 15;
		_atk = 20;
		_hpm = 100;
		_range = 100;
		_delay = 2.0f;
		_speed = 1.0f;
		_exp = 10;
		_money = 2;
		break;
	case 좀비킹:
		cache->addSpriteFramesWithFile("Monster/monster/Zomking.plist");
		_monsterCode = "b01";
		_atkMaxFrame = 30;
		_atk = 0;
		_hpm = 300;
		_range = 300;
		_delay = 2.0f;
		_speed = 1.0f;
		_exp = 20;
		_money = 20;
		break;
	}
	_hp = _hpm;
	_state = WALK;
	_moveChange = 1;
	_isRemove = false;
	_isSummonX = 0;

	int zorder = rand() % 30;
	_monster = Sprite::createWithSpriteFrameName(StringUtils::format("%s_walk_0001.png", _monsterCode));
	_monster->setPosition(500, zorder + 405);
	_layer->addChild(_monster, 65 - zorder);
}

void Monster::MonsterMove()
{
	_isSummonX = 0;
	bool _isAttack = false;
	for (int i = 0; i < _unit.size(); i++) {
		if (_unit[i]->getSprite()->getPositionX() < _monster->getPositionX() &&
			_unit[i]->getSprite()->getPositionX() > _monster->getPositionX() - _range) {
			if (_state != ATTACK && _state != DEAD) {
				_moveChange = true;
				_state = ATTACK;
				break;
			}
			_isAttack = true;
		}
	}
	if (_hero->getHero()->getPositionX() < _monster->getPositionX() &&
		_hero->getHero()->getPositionX() > _monster->getPositionX() - _range) {
		if (_state != ATTACK && _state != DEAD) {
			_moveChange = true;
			_state = ATTACK;
		}
		_isAttack = true;
	}
	if (_state == ATTACK && !_moveChange && !_isAttack) {
		_moveChange = true;
		_state = WALK;
	}
	if (_state == WALK) {
		Walk();
	}
	if (_moveChange) {
		_moveChange = 0;
		_monster->cleanup();

		Vector<SpriteFrame*> frame, frame2;
		if (_state == WALK) {
			for (int i = 1; i <= 12; i++) {
				frame.pushBack(SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(StringUtils::format("%s_walk_%04d.png", _monsterCode, i)));
			}
			auto animation = Animation::createWithSpriteFrames(frame, 0.03f);
			auto animate = Animate::create(animation);
			auto action = RepeatForever::create(animate);
			_monster->runAction(action);
		}
		else if (_state == ATTACK)
		{
			for (int i = 1; i <= _atkMaxFrame; i++) {
				frame.pushBack(SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(StringUtils::format("%s_att_%04d.png", _monsterCode, i)));
			}
			auto animation = Animation::createWithSpriteFrames(frame, 0.03f);
			auto animate = Animate::create(animation);
			if (strcmp(_monsterCode, "b01") == 0) { //좀비킹 공격모션
				for (int i = 1; i <= 12; i++) {
					frame2.pushBack(SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(StringUtils::format("b01_wait_%04d.png", i)));
				}

				auto animation2 = Animation::createWithSpriteFrames(frame2, 0.03f);
				auto animate2 = Animate::create(animation2);

				auto action = RepeatForever::create(Sequence::create(
					animate,
					Spawn::create(animate2, CallFunc::create(CC_CALLBACK_0(Monster::ZomkingSummon, this)), nullptr),
					nullptr));
				_monster->runAction(action);

			}
			else {
				auto action = RepeatForever::create(Sequence::create(
					animate,
					CallFunc::create(CC_CALLBACK_0(Monster::Attack, this)),
					DelayTime::create(_delay),
					nullptr));
				_monster->runAction(action);
			}
		}
		else if (_state == DEAD) {
			for (int i = 1; i <= 16; i++) {
				frame.pushBack(SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(StringUtils::format("%s_down_%04d.png", _monsterCode, i)));
			}
			auto animation = Animation::createWithSpriteFrames(frame, 0.03f);
			auto animate = Animate::create(animation);

			for (int i = 1; i <= 34; i++) {
				frame2.pushBack(SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(StringUtils::format("eff_die_%04d.png", i))); //eff_enemydie_%04d.png <- 몬스터
			}

			auto animation2 = Animation::createWithSpriteFrames(frame2, 0.03f);
			auto animate2 = Animate::create(animation2);

			auto action = Sequence::create(
				Spawn::create(animate, MoveBy::create(0.48, Vec2(70, 0)), nullptr),
				animate2,
				CallFunc::create(CC_CALLBACK_0(Monster::Dead, this)),
				nullptr
			);
			_monster->runAction(action);
		}
	}
}

void Monster::Hit(float atk)
{
	if (_hp > 0) _hp -= atk;
	if (_hp <= 0 && _state != DEAD) {
		_hp = 0;
		_state = DEAD;
		_moveChange = true;
	}
}

void Monster::Walk()
{
	_monster->setPosition(_monster->getPosition() + Vec2(-_speed, 0));
	if (getMonster()->getPosition().x < 0) {
		if (_monsterCode == "b01") {
			_monster->setPositionX(400);
		}
		else {
			_isRemove = true;
		}
	}
}

void Monster::Attack()
{
	float distance = _monster->getPositionX() - _hero->getHero()->getPositionX() < 0 ? 0 :
		_monster->getPositionX() - _hero->getHero()->getPositionX();
	int target = -1;
	float temp;
	for (int i = 0; i < _unit.size(); i++) {
		temp = _monster->getPositionX() - _unit[i]->getSprite()->getPositionX() < 0 ? 0 :
			_monster->getPositionX() - _unit[i]->getSprite()->getPositionX();
		distance = min(distance, temp);
		if (temp == distance) target = i;
	}
	switch (target) {
	case -1:
		//_hero->setHp(_hero->getHp() - _atk); 
		Hit(_atk);
		break;
	default:
		Hit(_atk);
		//유닛 공격
		break;
	}
}

void Monster::ZomkingSummon()
{
	_isSummonX = _monster->getPositionX();

	_summon = Sprite::createWithSpriteFrameName("b01_summon_0001.png");
	_summon->setPosition(_monster->getPosition());
	_layer->addChild(_summon, 65);

	Vector<SpriteFrame*> frame;

	for (int i = 1; i <= 15; i++) {
		frame.pushBack(SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(StringUtils::format("b01_summon_%04d.png", i)));
	}
	auto animation = Animation::createWithSpriteFrames(frame, 0.03f);
	auto animate = Animate::create(animation);
	_summon->runAction(Sequence::create(animate, CallFunc::create(CC_CALLBACK_0(Monster::ZomkingSummonRemove, this)), nullptr));
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
