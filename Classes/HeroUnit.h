#pragma once

#include "cocos_framework.h"

enum HeroKind
{
	»ýÁã = 100,
	°õ,
	Ä»°Å·ç,
};

class HeroUnit
{
	SpriteFrameCache* cache;

	vector<HeroUnit*> _unitVec; // ¹éÅÍ

	Sprite* _UnitSprite; // À¯´Ö½ºÇÁ¶óÀÌÆ®

	float _Hp; // Ã¼·Â
	float _Atk; // °ø°Ý·Â
	float _Speed; // ½ºÇÇµå
	HeroKind _unitKind; // À¯´ÖÁ¾·ù
	HeroUnit* _heroUnit; // À¯´Ö°´Ã¼

public:
	HeroUnit(Scene* scene, HeroKind herokind);

	vector<HeroUnit*> getUnitVec() { return _unitVec; }
	HeroKind getHeroKind() { return _unitKind; }
	Sprite* getSprite() { return _UnitSprite; }
	void setSprite(Sprite* pSprite) { _UnitSprite = pSprite; }
	float getHp() { return _Hp; }
	void setHp(float hp) { _Hp = hp; }
	float getAtk() { return _Atk; }
	void setAtk(float atk) { _Atk = atk; }
	float getSpeed() { return _Speed; }
	void setSpeed(float speed) { _Speed = speed; }

};