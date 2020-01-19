#ifndef __MAINGAME_SCENE_H__
#define __MAINGAME_SCENE_H__

#include "cocos_framework.h"
#include "cocos2d.h"

class MainGameScene : public Scene
{
 public:
  static Scene* createScene();
  virtual bool init();
  CREATE_FUNC(MainGameScene);
  void onEnter();
  void onExit();
  bool onTouchBegan(Touch* touch, Event* event);
 private:
  EventListenerTouchOneByOne* _listener;
  bool _isSelectPlay;
  bool _isSelectConfig;
  bool _isSelectPaladog;
  bool _isSelectDarkdog;
  bool _isSelectCampaign;
  bool _isSelectDataSlot;
  bool _isSelectCancel;
  //void changeIntroBG(float t);
  //void callEveryFrame(float t);
};

#endif // __MAINGAME_SCENE_H__
