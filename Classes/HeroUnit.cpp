#include "HeroUnit.h"

HeroUnit::HeroUnit(Scene * scene, HeroKind herokind)
{
	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Player/Unit/u_01.plist");
	cache->addSpriteFramesWithFile("Player/Unit/u_02.plist");
	cache->addSpriteFramesWithFile("Player/Unit/u_03.plist");

	switch (herokind)
	{
	case »ýÁã:
		_UnitSprite = Sprite::createWithSpriteFrameName("u01_walk_0001.png");
		_UnitSprite->setPosition(100, 200);
		_Speed = 0.6f;
		_Hp = 1.0f;
		_Atk = 0.6f;
		_unitKind = »ýÁã;
		scene->addChild(_UnitSprite);
		break;
	case °õ:
		_UnitSprite = Sprite::createWithSpriteFrameName("u03_walk_0001.png");
		_UnitSprite->setPosition(100, 200);
		_Speed = 0.6f;
		_Hp = 1.0f;
		_Atk = 0.6f;
		_unitKind = °õ;
		scene->addChild(_UnitSprite);
		break;
	case Ä»°Å·ç:
		_UnitSprite = Sprite::createWithSpriteFrameName("u04_walk_0001.png");
		_UnitSprite->setPosition(100, 200);
		_Speed = 0.6f;
		_Hp = 1.0f;
		_Atk = 0.6f;
		_unitKind = Ä»°Å·ç;
		scene->addChild(_UnitSprite);
		break;
	default:
		break;
	}
}