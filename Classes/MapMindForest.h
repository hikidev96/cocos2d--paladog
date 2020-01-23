#ifndef __MAP_MINDFOREST_H__
#define __MAP_MINDFOREST_H__

#include "cocos_framework.h"

class MapMindForest : public Scene
{
 public:
  static Scene* createScene();
  virtual bool init();
  CREATE_FUNC(MapMindForest);
};

#endif // __MAP_MINDFOREST_H__
