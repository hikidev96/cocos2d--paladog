#ifndef __MAP_MINDFORESTBG_H__
#define __MAP_MINDFORESTBG_H__

#include "cocos_framework.h"

class MapMindForestBg
{
 public:
  MapMindForestBg();
  void setPapermap(Scene* pScene);
  void setUnderPapermap(Scene* pScene);
  void setStSelBoardBottom(Scene* pScene);
  void setStSelBoardLeft(Scene* pScene);
  void setStSelBoardRight(Scene* pScene);
  void setStSelBoardTop(Scene* pScene);
  void setStSelMapNow(Scene* pScene);
  void setIconSmallStar(Scene* pScene);
 private:
  SpriteFrameCache* _cache;
  Sprite* _papermap;
  Sprite* _underPapermap;
  Sprite* _stSelBoardBottom;
  Sprite* _stSelBoardLeft;
  Sprite* _stSelBoardRight;
  Sprite* _stSelBoardTop;
  Sprite* _stSelMapNow;
  Sprite* _iconSmallStar;
};

#endif // __MAP_MINDFORESTBG_H__
