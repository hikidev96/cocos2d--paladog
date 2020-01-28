#include "MissileCollision.h"

MissileCollision::MissileCollision(Layer* layer, Movement moveway, Vec2 pos, int zoder)
{
	_layer = layer;
	_movement = moveway;

	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Player/weapons/m01_1.plist"); // plist 추가
	cache->addSpriteFramesWithFile("Player/weapons/eff_normal_01.plist"); // plist 추가

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

	_hammerHitEffectAnimation = Animation::create();
	_hammerHitEffectAnimation->setDelayPerUnit(0.05f);
	_hammerHitEffectAnimation->addSpriteFrame(cache->getSpriteFrameByName("eff_explosion_a_0001.png"));
	_hammerHitEffectAnimation->addSpriteFrame(cache->getSpriteFrameByName("eff_explosion_a_0002.png"));
	_hammerHitEffectAnimation->addSpriteFrame(cache->getSpriteFrameByName("eff_explosion_a_0003.png"));
	_hammerHitEffectAnimation->addSpriteFrame(cache->getSpriteFrameByName("eff_explosion_a_0004.png"));
	_hammerHitEffectAnimation->addSpriteFrame(cache->getSpriteFrameByName("eff_explosion_a_0005.png"));
	_hammerHitEffectAnimation->addSpriteFrame(cache->getSpriteFrameByName("eff_explosion_a_0006.png"));
	_hammerHitEffectAnimation->addSpriteFrame(cache->getSpriteFrameByName("eff_explosion_a_0007.png"));
	_hammerHitEffectAnimation->addSpriteFrame(cache->getSpriteFrameByName("eff_explosion_a_0008.png"));
	_hammerHitEffectAnimation->addSpriteFrame(cache->getSpriteFrameByName("eff_explosion_a_0009.png"));
	_hammerHitEffectAnimation->addSpriteFrame(cache->getSpriteFrameByName("eff_explosion_a_0010.png"));
	_hammerHitEffectAnimation->addSpriteFrame(cache->getSpriteFrameByName("eff_explosion_a_0011.png"));
	_hammerHitEffectAnimation->addSpriteFrame(cache->getSpriteFrameByName("eff_explosion_a_0012.png"));
	_hammerHitEffectAnimation->addSpriteFrame(cache->getSpriteFrameByName("eff_explosion_a_0013.png"));
	_hammerHitEffectAnimation->addSpriteFrame(cache->getSpriteFrameByName("eff_explosion_a_0014.png"));
	_hammerHitEffectAnimation->addSpriteFrame(cache->getSpriteFrameByName("eff_explosion_a_0015.png"));
	_hammerHitEffectAnimate = Animate::create(_hammerHitEffectAnimation);
	_hammerHitEffectAnimate->retain();
	_hammerHitEffectAnimate->setTag(790);

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
			// 히트시 잠시 빨간색으로 바뀌는효과
			monster[i]->getMonster()->runAction(Sequence::createWithTwoActions(TintTo::create(0, Color3B::RED), TintTo::create(0.1f, Color3B::WHITE)));

			monster[i]->Hit(_Atk);
			_firstAtk = true;

			_hitEffect1 = Sprite::createWithSpriteFrameName("eff_explosion_a_0001.png");
			_hitEffect1->setScale(1.5f);
			_layer->addChild(_hitEffect1, monster[i]->getMonster()->getZOrder());
			_hitEffect1->setPosition(monster[i]->getMonster()->getPosition().x, monster[i]->getMonster()->getPosition().y - 30);
			_hitEffect1->runAction(Sequence::create(_hammerHitEffectAnimate, RemoveSelf::create(true), nullptr)->clone());

			if (_address1 == nullptr)
			{
				_address1 = monster[i]->getMonster();
			}
		}

		// 두번째 유닛과 충돌
		if (_MissileSprite->getPositionX() > monster[i]->getMonster()->getPositionX() - 30 &&
			_MissileSprite->getPositionX() < monster[i]->getMonster()->getPositionX() + 10 && _firstAtk && !_secondAtk)
		{
			// 히트시 잠시 빨간색으로 바뀌는효과
			monster[i]->getMonster()->runAction(Sequence::createWithTwoActions(TintTo::create(0, Color3B::RED), TintTo::create(0.1f, Color3B::WHITE)));

			if (_address1 == monster[i]->getMonster())
				continue;

			monster[i]->Hit(_Atk);
			_secondAtk = true;

			_hitEffect2 = Sprite::createWithSpriteFrameName("eff_explosion_a_0001.png");
			_hitEffect2->setScale(1.5f);
			_layer->addChild(_hitEffect2, monster[i]->getMonster()->getZOrder());
			_hitEffect2->setPosition(monster[i]->getMonster()->getPosition().x, monster[i]->getMonster()->getPosition().y - 30);
			_hitEffect2->runAction(Sequence::create(_hammerHitEffectAnimate, RemoveSelf::create(true), nullptr)->clone());

			if (_address2 == nullptr)
			{
				_address2 = monster[i]->getMonster();
			}
		}

		// 세번째 유닛과 충돌
		if (_MissileSprite->getPositionX() > monster[i]->getMonster()->getPositionX() - 30 &&
			_MissileSprite->getPositionX() < monster[i]->getMonster()->getPositionX() + 10 && _firstAtk && _secondAtk)
		{
			// 히트시 잠시 빨간색으로 바뀌는효과
			monster[i]->getMonster()->runAction(Sequence::createWithTwoActions(TintTo::create(0, Color3B::RED), TintTo::create(0.1f, Color3B::WHITE)));

			if (_address2 == monster[i]->getMonster() || _address1 == monster[i]->getMonster())
				continue;

			monster[i]->Hit(_Atk);

			_hitEffect3 = Sprite::createWithSpriteFrameName("eff_explosion_a_0001.png");
			_hitEffect3->setScale(1.5f);
			_layer->addChild(_hitEffect3, monster[i]->getMonster()->getZOrder());
			_hitEffect3->setPosition(monster[i]->getMonster()->getPosition().x, monster[i]->getMonster()->getPosition().y - 30);
			_hitEffect3->runAction(Sequence::create(_hammerHitEffectAnimate, RemoveSelf::create(true), nullptr)->clone());

			// 객체 삭제
			_erase = true;
			_MissileSprite->runAction(RemoveSelf::create(true));
		}
	}

	//몬스터 기지를 공격
	if (dungeon->getMonsterBase()->getPositionX() - _MissileSprite->getPositionX() + 50<= 0)
	{
		// 히트시 잠시 빨간색으로 바뀌는효과
		dungeon->getMonsterBase()->runAction(Sequence::createWithTwoActions(TintTo::create(0, Color3B::RED), TintTo::create(0.1f, Color3B::WHITE)));

		dungeon->Hit(_Atk);

		_hitEffect4 = Sprite::createWithSpriteFrameName("eff_explosion_a_0001.png");
		_hitEffect4->setScale(1.5f);
		_layer->addChild(_hitEffect4, dungeon->getMonsterBase()->getZOrder() + 1);
		_hitEffect4->setPosition(dungeon->getMonsterBase()->getPosition().x + 100, dungeon->getMonsterBase()->getPosition().y + 100);
		_hitEffect4->runAction(Sequence::create(_hammerHitEffectAnimate, RemoveSelf::create(true), nullptr)->clone());

		_erase = true;
		_MissileSprite->runAction(RemoveSelf::create(true));
	}
}
