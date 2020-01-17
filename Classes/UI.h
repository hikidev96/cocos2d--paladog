#ifndef __UI_H__
#define __UI_H__

#include "cocos_framework.h"
#include "cocos2d.h"

class UI
{
public:
	static cocos2d::Sprite* GetIntroPlayButton();
	static cocos2d::Sprite* GetIntroConfigButton();
private:
	static cocos2d::Sprite* _introPlayButton;
	static cocos2d::Sprite* _introConfigButton;
	static cocos2d::Sprite* _introPaladogButton;
};

#endif // __UI_H__
