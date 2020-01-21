#include "cocos_framework.h"
#include "Dungeon.h"

Dungeon::Dungeon(Scene* scene, float hp)
{
	_scene = scene;
	_hpm = _hp = hp;
	_state = 반이상;

	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Monster/effect/eff_e_base.plist");
	cache->addSpriteFramesWithFile("Monster/effect/enemybase.plist");

	_sprite1 = Sprite::createWithSpriteFrameName("enemy_base_full_back.png");
	_sprite1->setPosition(300, 120);
	_scene->addChild(_sprite1, 10);

	_sprite2 = Sprite::createWithSpriteFrameName("enemy_base_full_front.png");
	_sprite2->setPosition(300, 120);
	_scene->addChild(_sprite2, 90);

	_scene->runAction(RepeatForever::create(Sequence::create( //d
		CallFunc::create(CC_CALLBACK_0(Dungeon::test, this)),
		DelayTime::create(2),
		nullptr)));
}

void Dungeon::Hit(float atk)
{
	if (_state != 무너짐) {
		_hp -= atk;

		if (_state == 반이상 && _hp <= _hpm / 2) {
			_state = 반이하;
			_scene->removeChild(_sprite1);
			_scene->removeChild(_sprite2);
			_sprite1 = Sprite::createWithSpriteFrameName("enemy_base_damaged_back.png");
			_sprite2 = Sprite::createWithSpriteFrameName("enemy_base_damaged_front.png");
			_sprite1->setPosition(300, 120);
			_sprite2->setPosition(300, 120);
			_scene->addChild(_sprite1, 10);
			_scene->addChild(_sprite2, 90);

		}
		if (_state == 반이하 && _hp <= 0) {
			_state = 무너짐;
			_scene->removeChild(_sprite1);
			_scene->removeChild(_sprite2);
			_sprite1 = Sprite::createWithSpriteFrameName("enemy_base_broken_back.png");
			_sprite2 = Sprite::createWithSpriteFrameName("enemy_base_broken_front.png");
			_sprite1->setPosition(300, 120);
			_sprite2->setPosition(300, 120);
			_scene->addChild(_sprite1, 10);
			_scene->addChild(_sprite2, 90);

			_sprite3 = Sprite::createWithSpriteFrameName("crash_0001.png");
			_sprite3->setPosition(400, 150);
			_scene->addChild(_sprite3);
			Vector<SpriteFrame*> frame;
			for (int i = 1; i <= 20; i++) {
				frame.pushBack(SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(StringUtils::format("crash_%04d.png", i)));
			}
			auto animation = Animation::createWithSpriteFrames(frame, 0.03f);
			auto animate = Animate::create(animation);
			auto action = Sequence::create(
				animate,
				nullptr);
			_sprite3->runAction(action);
		}
		auto action = Sequence::create(
			MoveBy::create(0.08, Vec2(4, 4)),
			MoveBy::create(0.08, Vec2(-4, -4)),
			nullptr);
		auto rep = Repeat::create(action, 3);
		_sprite1->runAction(rep);
		_sprite2->runAction(rep->clone());
	}
}

void Dungeon::test()
{
	Hit(100);
}
