#ifndef __INTROBG_H__
#define __INTROBG_H__

#include "cocos_framework.h"
#include "cocos2d.h"

class IntroBg
{
 public:
  IntroBg();
  void Set15Age(Scene* pScene);
  Sprite* Get15Age() {
    return _15Age;
  }
  void SetTitleVolcano(Scene* pScene);
  Sprite* GetTitleVolcano() {
    return _titleVolcano;
  }
  void SetTitleSky(Scene* pScene);
  Sprite* GetTitleSky() {
    return _titleSky;
  }
  void SetTitleVolcanoCloud(Scene* pScene);
  Sprite* GetTitleVolcanoCloud() {
    return _titleVolcanoCloud;
  }
  void SetTitleDarkCloud(Scene* pScene);
  Sprite* GetTitleDarkCloud() {
    return _titleDarkCloud;
  }
  RepeatForever* GetTitleDarkCloudAction() {
    return _titleDarkCloudAction;
  }
  void SetTitleDarkCloud2(Scene* pScene);
  Sprite* GetTitleDarkCloud2() {
    return _titleDarkCloud2;
  }
  RepeatForever* GetTitleDarkCloud2Action() {
    return _titleDarkCloudAction2;
  }
  void SetTitleMountain(Scene* pScene);
  Sprite* GetTitleMountain() {
    return _titleMountain;
  }
  void SetTitleMountain2(Scene* pScene);
  Sprite* GetTitleMountain2() {
    return _titleMountain2;
  }
  void SetTitleWood(Scene* pScene);
  Sprite* GetWoodL() {
    return _woodL;
  }
  Sprite* GetWoodR() {
    return _woodR;
  }
  Sprite* GetTreeA() {
    return _treeA;
  }
  Sprite* GetTreeB() {
    return _treeB;
  }
 private:
  SpriteFrameCache* _cache;
  Sprite* _15Age;
  Sprite* _titleVolcano;
  Sprite* _titleSky;
  Sprite* _titleVolcanoCloud;  
  Sprite* _titleDarkCloud;
  RepeatForever* _titleDarkCloudAction;
  Sprite* _titleDarkCloud2;
  RepeatForever* _titleDarkCloudAction2;
  Sprite* _titleMountain;
  Sprite* _titleMountain2;
  Sprite* _woodL;
  Sprite* _woodR;
  Sprite* _treeA;
  Sprite* _treeB;
};

#endif // __INTROBG_H__
