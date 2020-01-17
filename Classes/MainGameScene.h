#ifndef __MAINGAME_SCENE_H__
#define __MAINGAME_SCENE_H__

#include "cocos_framework.h"
#include "cocos2d.h"

class MainGameScene : public cocos2d::Scene
{
 public:
  static cocos2d::Scene* createScene();
  virtual bool init();
  CREATE_FUNC(MainGameScene);

};

#endif // __MAINGAME_SCENE_H__