#ifndef __MAP_MINDFOREST_H__
#define __MAP_MINDFOREST_H__

#include "cocos_framework.h"
#include "MapMindForestBg.h"
#include "MapMindForestUI.h"

class MapMindForestScene : public Scene
{
 public:
  static Scene* createScene();
  virtual bool init();
  CREATE_FUNC(MapMindForestScene);
  void onEnter();
  void onExit();
  bool onTouchBegan(Touch* touch, Event* event);
 private:
  EventListenerTouchOneByOne* _listener;
  MapMindForestBg* _mapMindForestBg;
  MapMindForestUI* _mapMindForestUI;
};

#endif // __MAP_MINDFOREST_H__
