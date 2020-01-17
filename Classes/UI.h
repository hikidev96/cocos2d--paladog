#ifndef __UI_H__
#define __UI_H__

#include "cocos2d.h"

class UI
{
 public:
  static cocos2d::Sprite* GetIntroPlayButton();
  static cocos2d::Sprite* GetIntroSelectedPlayButton();
  static cocos2d::Sprite* GetIntroConfigButton();
  static cocos2d::Sprite* GetIntroSelectedConfigButton();
  static cocos2d::Sprite* GetIntroModeSelectBox();
  static cocos2d::Sprite* GetIntroPaladogButton();
  static cocos2d::Sprite* GetIntroSelectedPaladogButton();
  static cocos2d::Sprite* GetIntroDarkdogButton();
  static cocos2d::Sprite* GetIntroSelectedDarkdogButton();
 private:
  static cocos2d::SpriteFrameCache* _cache;
  static cocos2d::Sprite* _introPlayButton;
  static cocos2d::Sprite* _introSelectedPlayButton;
  static cocos2d::Sprite* _introConfigButton;
  static cocos2d::Sprite* _introSelectedConfigButton;
  static cocos2d::Sprite* _introModeSelectBox;
  static cocos2d::Sprite* _introPaladogButton;
  static cocos2d::Sprite* _introSelectedPaladogButton;
  static cocos2d::Sprite* _introDarkdogButton;
  static cocos2d::Sprite* _introSelectedDarkdogButton;
};

#endif // __UI_H__
