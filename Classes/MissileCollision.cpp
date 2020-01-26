#include "MissileCollision.h"

MissileCollision::MissileCollision(Layer* layer, Movement moveway, Vec2 pos, int zoder)
{
	_layer = layer;
	_movement = moveway;

	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Player/weapons/m01_1.plist"); // plist 추가

	_MissileSprite = Sprite::createWithSpriteFrameName("m01_eff_b_0001.png");

	if (moveway == LeftWay)
		_MissileSprite->setPosition(pos.x - 50, pos.y - 25);
	if (moveway == RightWay)
		_MissileSprite->setPosition(pos.x + 50, pos.y - 25);
	
	_layer->addChild(_MissileSprite, zoder);

	_firstAtk = false;
	_secondAtk = false;

	_Atk = 500.f;
	_speed = 4.f;

	_erase = false;

	_address1 = nullptr;
	_address2 = nullptr;

	_hammerSkillEffectAnimation_B1 = Animation::create();
	_hammerSkillEffectAnimation_B1->setDelayPerUnit(0.03f);
	_hammerSkillEffectAnimation_B1->addSpriteFrame(cache->getSpriteFrameByName("m01_eff_b_0001.png"));
	_hammerSkillEffectAnimation_B1->addSpriteFrame(cache->getSpriteFrameByName("m01_eff_b_0002.png"));
	_hammerSkillEffectAnimation_B1->addSpriteFrame(cache->getSpriteFrameByName("m01_eff_b_0003.png"));
	_hammerSkillEffectAnimation_B1->addSpriteFrame(cache->getSpriteFrameByName("m01_eff_b_0004.png"));
	_hammerSkillEffectAnimation_B1->addSpriteFrame(cache->getSpriteFrameByName("m01_eff_b_0005.png"));
	_hammerSkillEffectAnimate_B1 = Animate::create(_hammerSkillEffectAnimation_B1);
	_hammerSkillEffectRepeat_B1 = RepeatForever::create(_hammerSkillEffectAnimate_B1);
	_hammerSkillEffectRepeat_B1->retain();
	_hammerSkillEffectRepeat_B1->setTag(777);
}

void MissileCollision::BringMonsterVec(vector<Monster*> monster, Dungeon* dungeon)
{
	// 미사일 움직임!
	if (!_MissileSprite->getNumberOfRunningActionsByTag(777))
	{
		_MissileSprite->runAction(_hammerSkillEffectRepeat_B1);
	}
	if (_movement == RightWay)
	{
		_MissileSprite->setFlippedX(false);
		_MissileSprite->setPosition(_MissileSprite->getPositionX() + _speed, _MissileSprite->getPositionY());
	}
	if (_movement == LeftWay)
	{
		_MissileSprite->setFlippedX(true);
		_MissileSprite->setPosition(_MissileSprite->getPositionX() - _speed, _MissileSprite->getPositionY());
	}
	
	//몬스터 유닛과 충돌
	for (int i = 0; i < monster.size(); i++)
	{
		// 첫번째 유닛과 충돌
		if (_MissileSprite->getPositionX() > monster[i]->getMonster()->getPositionX() - 30 &&
			_MissileSprite->getPositionX() < monster[i]->getMonster()->getPositionX() + 10 && !_firstAtk)
		{
			monster[i]->Hit(_Atk);
			_firstAtk = true;

			if (_address1 == nullptr)
			{
				_address1 = monster[i]->getMonster();
			}
		}

		// 두번째 유닛과 충돌
		if (_MissileSprite->getPositionX() > monster[i]->getMonster()->getPositionX() - 30 &&
			_MissileSprite->getPositionX() < monster[i]->getMonster()->getPositionX() + 10 && _firstAtk && !_secondAtk)
		{
			if (_address1 == monster[i]->getMonster())
				continue;

			monster[i]->Hit(_Atk);
			_secondAtk = true;

			if (_address2 == nullptr)
			{
				_address2 = monster[i]->getMonster();
			}
		}

		// 세번째 유닛과 충돌
		if (_MissileSprite->getPositionX() > monster[i]->getMonster()->getPositionX() - 30 &&
			_MissileSprite->getPositionX() < monster[i]->getMonster()->getPositionX() + 10 && _firstAtk && _secondAtk)
		{
			if (_address2 == monster[i]->getMonster() || _address1 == monster[i]->getMonster())
				continue;

			monster[i]->Hit(_Atk);

			// 객체 삭제
			_erase = true;
			_MissileSprite->runAction(RemoveSelf::create(true));
		}
	}

	//몬스터 기지를 공격
	if (dungeon->getMonsterBase()->getPositionX() - _MissileSprite->getPositionX() + 50<= 0)
	{
		dungeon->Hit(_Atk);
		_erase = true;
		_MissileSprite->runAction(RemoveSelf::create(true));
	}
}
