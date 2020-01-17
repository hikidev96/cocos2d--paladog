#include "UI.h"

Sprite* UI::_introPlayButton = nullptr;
Sprite* UI::_introConfigButton = nullptr;
Sprite* UI::_introPaladogButton = nullptr;

Sprite* UI::GetIntroPlayButton() {
	_introPlayButton = Sprite::create("UI/startMapUI/opening_ending_03.png");
	_introPlayButton->setTextureRect(Rect(0, 155, 205, 140));
	_introPlayButton->setAnchorPoint(Vec2(0, 0));
	_introPlayButton->setPosition(Vec2(0, 0));
	//_introPlayButton->setPosition(Vec2(250, 130));
	//_introPlayButton->setScaleX(1.8f);
	//_introPlayButton->setScaleY(1.5f);
	return _introPlayButton;
}

Sprite* UI::GetIntroConfigButton() {
	_introConfigButton = Sprite::create("UI/startMapUI/opening_ending_03.png");
	_introConfigButton->setTextureRect(Rect(0, 340, 75, 75));
	_introConfigButton->setAnchorPoint(Vec2(1, 0));
	_introConfigButton->setPosition(Vec2(480, 0));
	//_introConfigButton->setPosition(Vec2(1180, 100));
	//_introConfigButton->setScale(1.5f);
	return _introConfigButton;
}