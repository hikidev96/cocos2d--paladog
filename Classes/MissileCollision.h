#pragma once

#include "cocos_framework.h"
#include "Hero.h"
#include "Monster.h"
#include "Dungeon.h"

class MissileCollision
{
private:
	Layer* _layer;

	SpriteFrameCache* cache; // 캐시

	Sprite* _MissileSprite;

	Movement _movement;

	bool _firstAtk;
	bool _secondAtk;

	bool _erase;

	Sprite* _address1;
	Sprite* _address2;

	float _Atk;

	Animation* _hammerSkillEffectAnimation_B1; // 고무망치 스킬 이펙트B
	Animate* _hammerSkillEffectAnimate_B1; // 고무망치 스킬 이펙트B
	RepeatForever* _hammerSkillEffectRepeat_B1; // 고무망치 스킬 이펙트B
public:
	MissileCollision(Layer* layer, Movement moveway, Vec2 pos, int zoder);

	bool getErase() { return _erase; }
	void BringMonsterVec(vector<Monster*> monster, Dungeon* dungeon);
	
};