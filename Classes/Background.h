#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

#include "cocos_framework.h"
#include "cocos2d.h"

class Background
{
 public:
  enum eCloud
  {
    kCloud_Flowing
  };
  static SpriteFrameCache* GetCache();
  static Sprite* GetIntroBackground();
  static Sprite* GetIntroVolcanoBg();
  static Sprite* GetIntroSkyBg();
  static Sprite* GetIntroVolcanoCloudBg();
  static Sprite* GetIntroDarkCloudBg();
  static Sprite* GetIntroLogo();
  static RepeatForever* GetIntroDarkCloudBgRepeatForever() {
    return _introDarkCloudRepeatForever;
  }
  static Sprite* GetIntroWoodBg();
  static Sprite* GetIntroStoneBg();
 private:
  static SpriteFrameCache* _cache;
  static Sprite* _introBg;
  static Sprite* _introVolcanoBg;
  static Sprite* _introSkyBg;
  static Sprite* _introVolcanoCloudBg;  
  static Sprite* _introDarkCloudBg;
  static Sprite* _introFaladogLogo; // 팔라딘 로고(글자)
  // 구름 애니메이션
  static Animation* _introDarkCloudAnimation;
  static Animate* _introDarkCloudAnimate;
  static RepeatForever* _introDarkCloudRepeatForever;
  static Sprite* _introWoodBg; // 나무
  static Sprite* _introStoneBg;
};

#endif // __BACKGROUND_H__
