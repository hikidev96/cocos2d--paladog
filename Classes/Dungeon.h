#pragma once
#include "cocos_framework.h"

class Dungeon : Scene
{
	enum STATE {
		반이상,
		반이하,
		무너짐
	};
	Scene* _scene;

	SpriteFrameCache* cache;

	STATE _state;

	Sprite* _sprite1;
	Sprite* _sprite2;
	Sprite* _sprite3;

	float _hpm, _hp;

public:

	Dungeon(Scene* scene, float hp);

	void Hit(float atk);

	void test();
};