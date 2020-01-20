#ifndef __INTRO_SCENE_H__
#define __INTRO_SCENE_H__

#include "cocos_framework.h"
#include "cocos2d.h"
#include "IntroBg.h"
#include "IntroUI.h"

class IntroScene : public Scene
{
 public:
  static Scene* createScene();
  virtual bool init();
  CREATE_FUNC(IntroScene);
  void onEnter();
  void onExit();
  bool onTouchBegan(Touch* touch, Event* event);
  void onTouchEnded(Touch* touch, Event* event);
 private:
  IntroBg* _introBg;
  void changeBg15AgeToVolcano(float time);
  EventListenerTouchOneByOne* _listener;
  IntroUI* _introUI;
};

#endif // __INTRO_SCENE_H__
