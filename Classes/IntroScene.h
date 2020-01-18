#ifndef __INTRO_SCENE_H__
#define __INTRO_SCENE_H__

#include "cocos_framework.h"
#include "cocos2d.h"

class IntroScene : public Scene
{
 public:
  static Scene* createScene();
  virtual bool init();
  CREATE_FUNC(IntroScene);
  //void onEnter();
  //void onExit();
  //bool onTouchBegan(Touch* touch, Event* event);
 private:
  //EventListenerTouchOneByOne* _listener;
  //bool _isSelectPlay;
  //bool _isSelectConfig;
  //bool _isChangeScene;
  //short _num;
  void changeIntroBG(float t);
  //void callEveryFrame(float t);
};

#endif // __INTRO_SCENE_H__
