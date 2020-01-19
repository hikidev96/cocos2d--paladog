#ifndef __UI_H__
#define __UI_H__

#include "cocos_framework.h"
#include "cocos2d.h"

class UI
{
 public:
  static SpriteFrameCache* GetCache();
  static Sprite* GetIntroPlayButton();
  static Sprite* GetIntroSelectedPlayButton();
  static Sprite* GetIntroConfigButton();
  static Sprite* GetIntroSelectedConfigButton();
  static Sprite* GetIntroModeSelectBox();
  static Sprite* GetIntroPaladogButton();
  static Sprite* GetIntroDarkdogButton();
  static Sprite* GetIntroCampaignButton();
  static Sprite* GetIntroSurvivalButton();
  static Sprite* GetIntroSelectSlot();
  static Sprite* GetIntroDataSlot();
  static Sprite* GetIntroDataSlotBottom();
  static Sprite* GetIntroMSGBox();
  static Sprite* GetIntroCancelButton();
  //static Sprite* GetIntroMSGBoxBottom();
 private:
  static SpriteFrameCache* _cache;
  static Sprite* _introPlayButton;
  static Sprite* _introSelectedPlayButton;
  static Sprite* _introConfigButton;
  static Sprite* _introSelectedConfigButton;
  static Sprite* _introModeSelectBox;
  static Sprite* _introPaladogButton;
  static Sprite* _introDarkdogButton;
  static Sprite* _introCampaignButton;
  static Sprite* _introSurvivalButton;
  static Sprite* _introSelectSlot;
  static Sprite* _introDataSlot;
  static Sprite* _introDataSlotBottom;
  static Sprite* _introMSGBox;
  static Sprite* _introCancelButton;
  //static Sprite* _introMSGBoxBottom;
};

#endif // __UI_H__
