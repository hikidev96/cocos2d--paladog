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
  void setStage1IconSmallStar(Scene* pScene);
  void setStage2IconSmallStar(Scene* pScene);
  void setStage3IconSmallStar(Scene* pScene);
 private:
  SpriteFrameCache* _cache;
  Sprite* _papermap;
  Sprite* _underPapermap;
  Sprite* _stSelBoardBottom;
  Sprite* _stSelBoardLeft;
  Sprite* _stSelBoardRight;
  Sprite* _stSelBoardTop;
  Sprite* _stSelMapNow;
  Sprite* _stage1IconSmallStar[3];
  Sprite* _stage2IconSmallStar[3];
  Sprite* _stage3IconSmallStar[3];
};

#endif // __MAP_MINDFORESTBG_H__
