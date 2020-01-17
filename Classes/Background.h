#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

#include "cocos2d.h"

class Background
{
 public:
  static cocos2d::Sprite* GetIntroBackground();
  static cocos2d::RepeatForever* GetIntroAnimation();
  static cocos2d::Sprite* GetIntroSelectBG();
  cocos2d::Sprite* GetShopBackground();
  cocos2d::Sprite* GetHeroBackground();
  cocos2d::Sprite* GetStage1Background();
  cocos2d::Sprite* GetStage2Background();
  cocos2d::Sprite* GetStage3Background();
 private:
  static cocos2d::Sprite* _introBg;
  static cocos2d::SpriteFrameCache* _introAniCache;
  static cocos2d::Sprite* _introSelectBG;
  cocos2d::Sprite* _shopBg;
  cocos2d::Sprite* _heroBg;
  cocos2d::Sprite* _stage1Bg;
  cocos2d::Sprite* _stage2Bg;
  cocos2d::Sprite* _stage3Bg;
};

#endif // __BACKGROUND_H__
