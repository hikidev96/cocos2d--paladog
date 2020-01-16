#ifndef  _GAME_DELEGATE_H_
#define  _GAME_DELEGATE_H_

#include "cocos2d.h"

class  GameDelegate : private cocos2d::Application
{
 public:
  GameDelegate();
  virtual ~GameDelegate();

  virtual void initGLContextAttrs();
  virtual bool applicationDidFinishLaunching();
  virtual void applicationDidEnterBackground();
  virtual void applicationWillEnterForeground();
};

#endif // _GAME_DELEGATE_H_
