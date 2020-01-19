#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

#include "cocos_framework.h"
#include "cocos2d.h"

class Background
{
 public:
  static Sprite* GetIntroBackground();
  static Sprite* GetIntroVolcanoBg();
  static Sprite* GetIntroSkyBg();
  static Sprite* GetIntroVolcanoCloudBg();
  static Sprite* GetIntroDarkCloudBg();
  static Sprite* GetIntroLogo();
  static RepeatForever* GetIntroDarkCloudBgRep();
 private:
  static SpriteFrameCache* _cache;
  static Sprite* _introBg;
  static Sprite* _introVolcanoBg;
  static Sprite* _introSkyBg;
  static Sprite* _introVolcanoCloudBg;
  static Sprite* _introDarkCloudBg;
  static Sprite* _introFaladogLogo;
};

#endif // __BACKGROUND_H__
