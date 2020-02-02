#ifndef __MAP_MINDFORESTUI_H__
#define __MAP_MINDFORESTUI_H__

#include "cocos_framework.h"

class MapMindForestUI
{
 public:
  MapMindForestUI();
  void setBtnExit(Scene* pScene);
  Sprite* getBtnExit() {
    return _btnExitUp;
  }
  void setIconStageLocked(Scene* pScene);
  void setNumBoard(Scene* pScene);
  void setStSelPointUp0(Scene* pScene);
  Sprite* getStSelPointUp0() {
    return _stSelPointUp[0];
  }
  void setStSelPointUp1(Scene* pScene);
  Sprite* getStSelPointUp1() {
    return _stSelPointUp[1];
  }
  void setStSelPointUp2(Scene* pScene);
  Sprite* getStSelPointUp2() {
    return _stSelPointUp[2];
  }
  void setUpgrade(Scene* pScene);
  Sprite* getUpgrade() {
    return _upgrade;
  }
 private:
  SpriteFrameCache* _cache;
  Sprite* _btnExitUp;
  Sprite* _iconStageLocked[24];
  Sprite* _numBoard;
  Sprite* _stSelPointUp[3];
  Sprite* _upgrade;
};

#endif // __MAP_MINDFORESTUI_H__
