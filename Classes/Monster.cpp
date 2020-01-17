#include "cocos_framework.h"
#include "Monster.h"

Monster::Monster(Scene* scene, Mob mob)
{
	_scene = scene;
	cache = SpriteFrameCache::getInstance();
	switch (mob) {
	case 걷는좀비:
		cache->addSpriteFramesWithFile("Monster/monster/Nzombie.plist");
		_monsterCode = "e01";
		_atkMaxFrame = 10;
		_hpm = 50;
		_range = 50;
		_delay = 2.0f;
		_speed = 0.8f;
		_exp = 5;
		_money = 1;
		break;
	case 분홍미라: //미구현
		cache->addSpriteFramesWithFile("Monster/monster/Pmummy.plist");
		_monsterCode = "e27";
		_atkMaxFrame = 15;
		_hpm = 100;
		_range = 150;
		_delay = 2.0f;
		_speed = 1.0f;
		_exp = 10;
		_money = 2;
		break;
	case 좀비킹:
		cache->addSpriteFramesWithFile("Monster/monster/Zomking.plist");
		_monsterCode = "b01";
		_atkMaxFrame = 30;
		_hpm = 500;
		_range = 50;
		_delay = 2.0f;
		_speed = 1.0f;
		_exp = 20;
		_money = 20;
		break;
	}
	_hp = _hpm;
	_state = WALK;
	_moveChange = 1;
	_isAttack = false;
	_isRemove = false;

	_monster = Sprite::createWithSpriteFrameName(StringUtils::format("%s_walk_0001.png", _monsterCode));
	_monster->setPosition(400, rand() % 10 + 195);
	_scene->addChild(_monster);
}

void Monster::MonsterMove()
{
	if (_moveChange) {
		_moveChange = 0;
		_monster->cleanup();

		Vector<SpriteFrame*> frame;
		
		if (_state == WALK) {
			for (int i = 1; i <= 12; i++) {
				frame.pushBack(SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(StringUtils::format("%s_walk_%04d.png", _monsterCode, i)));
				log(frame.at(0)->getOffset().x);
			}
			auto animation = Animation::createWithSpriteFrames(frame, 0.03f);
			auto animate = Animate::create(animation);
			auto action = RepeatForever::create(animate);
			_monster->runAction(action);
		} else if(_state == ATTACK) 
		{
			for (int i = 1; i <= _atkMaxFrame; i++) {
				frame.pushBack(SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(StringUtils::format("%s_att_%04d.png", _monsterCode, i)));
			}
			auto animation = Animation::createWithSpriteFrames(frame, 0.03f);
			auto animate = Animate::create(animation);
			auto action = RepeatForever::create(Sequence::create(animate, DelayTime::create(_delay), nullptr));
			_monster->runAction(action);
		}
		else if (_state == DEAD) {
			for (int i = 1; i <= _atkMaxFrame; i++) {
				frame.pushBack(SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(StringUtils::format("%s_att_%04d.png", _monsterCode, i)));
			}
			auto animation = Animation::createWithSpriteFrames(frame, 0.03f);
			auto animate = Animate::create(animation);
			auto action = Sequence::create(
				Spawn::create(animate, MoveBy::create(0.48,Vec2(50,0)), nullptr),
				CallFunc::create(CC_CALLBACK_0(Monster::Dead, this)),
				nullptr
			);
			_monster->runAction(action);
		}
	}
	switch (_state) {
	case WALK:
		_monster->setPosition(_monster->getPosition() + Vec2(-_speed , 0));
		if (getMonster()->getPosition().x < 0) {
			_isRemove = true;
		}
		break;
	case ATTACK:
		
		break;
	case DEAD:
		break;
	}
}

void Monster::Hit(int atk)
{
	_hp -= atk;
	if (_hp <= 0) {
		_hp = 0;
		_state = DEAD;
		_moveChange = true;
	}

}

void Monster::Walk()
{
	_moveChange = true;
	_isAttack = false;
	_state = WALK;
}

void Monster::Attack()
{
	_moveChange = true;
	_isAttack = true;
	_state = ATTACK;
}

void Monster::Dead()
{
	_isRemove = true;
}
