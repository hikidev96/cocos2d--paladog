#ifndef __INTROUI_H__
#define __INTROUI_H__

#include "cocos_framework.h"
#include "cocos2d.h"

class IntroUI
{
 public:
  IntroUI(Scene* pScene);
  void SetTitleLogo(Scene* pScene);
  Sprite* GetTitleLogo() {
    return _titleLogo;
  }
  void SetTitleBtnNewgameUp(Scene* pScene);
  Sprite* GetTitleBtnNewgameUp() {
    return _titleBtnNewgameUp;
  }
  void SetTitleBtnInfoUp(Scene* pScene);
  Sprite* GetTitleBtnInfoUp() {
    return _titleBtnInfoUp;
  }
  Sprite* GetIntroModeSelectBox();
  Sprite* GetIntroPaladogButton();
  Sprite* GetIntroDarkdogButton();
  Sprite* GetIntroCampaignButton();
  Sprite* GetIntroSurvivalButton();
  Sprite* GetIntroSelectSlot();
  Sprite* GetIntroDataSlot();
  Sprite* GetIntroDataSlotBottom();
  Sprite* GetIntroMSGBox();
 private:
  SpriteFrameCache* _cache;
  Sprite* _titleLogo;
  Sprite* _titleBtnNewgameUp;
  Sprite* _titleBtnInfoUp;
  Sprite* _introModeSelectBox;
  Sprite* _introPaladogButton;
  Sprite* _introDarkdogButton;
  Sprite* _introCampaignButton;
  Sprite* _introSurvivalButton;
  Sprite* _introSelectSlot;
  Sprite* _introDataSlot;
  Sprite* _introDataSlotBottom;
  Sprite* _introMSGBox;
};

#endif // __INTROUI_H__
