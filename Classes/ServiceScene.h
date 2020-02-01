#pragma once

#include "cocos_framework.h"
#include "Hero.h"

class ServiceScene
{
	SpriteFrameCache* _cache;

	Sprite* _getReadyBack1;
	Sprite* _getReadyBack2;
	Sprite* _getReadyBack3;
	Sprite* _getReadyFont;

	Sprite* _stageClearBack;

	Sprite* _stageClearText1;
	Sprite* _stageClearText2;
	Sprite* _stageClearText3;
	Sprite* _stageClearText4;
	Sprite* _stageClearText5;
	Sprite* _stageClearText6;
	Sprite* _stageClearText7;
	Sprite* _stageClearText8;
	Sprite* _stageClearText9;
	Sprite* _stageClearText10;

	Sprite* _stageClearCoin;

	Sprite* _stageClearLight1;
	Sprite* _stageClearLight2;
	Sprite* _stageClearLight3;

	Sprite* _stageClearStar1;
	Sprite* _stageClearStar2;
	Sprite* _stageClearStar3;

	Sprite* _loding;

	Scene* _scene;

public:
	ServiceScene(Scene* scene);

	void GetReady();
	void GetReadyOpacitySet();
	void FalseStageStart();

	void StageClear();
	void CoinVisible();
	void LightVisible();
	void CoinSound();
	
};
