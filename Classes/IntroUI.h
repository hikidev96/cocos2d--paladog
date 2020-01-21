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
  void SetModeSelectBox(Scene* pScene);
  Sprite* GetModeSelectBox() {
    return _modeSelectBox;
  }
  void SetHeroPaladogUp(Scene* pScene);
  Sprite* GetHeroPaladogUp() {
    return _heroPaladogUp;
  }
  void SetHeroDarkdogUp(Scene* pScene);
  Sprite* GetHeroDarkdogUp() {
    return _heroDarkdogUp;
  }
  void SetBtnCampaignUp(Scene* pScene);
  Sprite* GetBtnCampaignUp() {
    return _btnCampaignUp;
  }
  void SetBtnSurvivalUp(Scene* pScene);
  Sprite* GetBtnSurvivalUp() {
    return _btnSurvivalUp;
  }
  void SetDataSlot(Scene* pScene);
  Sprite* GetDataSlot() {
    return _dataSlot;
  }
  Sprite* GetIntroSelectSlot();
  
  Sprite* GetIntroDataSlotBottom();
  Sprite* GetIntroMSGBox();
 private:
  SpriteFrameCache* _cache;
  Sprite* _titleLogo;
  Sprite* _titleBtnNewgameUp;
  Sprite* _titleBtnInfoUp;
  Sprite* _modeSelectBox;
  Sprite* _heroPaladogUp;
  Sprite* _heroDarkdogUp;
  Sprite* _btnCampaignUp;
  Sprite* _btnSurvivalUp;
  Sprite* _dataSlot;


  Sprite* _introSelectSlot;
  Sprite* _introDataSlotBottom;
  Sprite* _introMSGBox;
};

#endif // __INTROUI_H__
