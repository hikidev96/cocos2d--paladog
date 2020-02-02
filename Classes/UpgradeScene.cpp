#include "UpgradeScene.h"
#include "ui/CocosGUI.h"
#include "cocos_framework.h"
#include "MapMindForestScene.h"
#include "IntroScene.h"

USING_NS_CC;
using namespace ui;

Scene* UpgradeScene::createScene() {
	return UpgradeScene::create();
}

bool UpgradeScene::init() {

	if (!Scene::init()) {
		return false;
	}

	/*if (AudioEngine::getState(_soundBs) != AudioEngine::AudioState::PLAYING && AudioEngine::getState(_soundBg1) != AudioEngine::AudioState::PLAYING && !BgSoundClear)
	{
		
	}*/

	//Hero::getInstance()->setGold(3000);

	_cache = SpriteFrameCache::getInstance();

	_cache->addSpriteFramesWithFile("UI/Upgrade/upgrade_equip_02.plist");
	_cache->addSpriteFramesWithFile("Player/UNIT_B~1/btn_unit-hd.plist"); 
	_cache->addSpriteFramesWithFile("Player/Unit/u_01_1.plist");
	_cache->addSpriteFramesWithFile("Player/Unit/u_02_1.plist");
	_cache->addSpriteFramesWithFile("Player/Unit/u_01_1.plist");
	_cache->addSpriteFramesWithFile("Player/Unit/u_02_1.plist");
	_cache->addSpriteFramesWithFile("Player/Unit/u_03_1.plist");


	listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(UpgradeScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(UpgradeScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(UpgradeScene::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	auto* _upgradeBg = Sprite::createWithSpriteFrameName("unit_upgrade_back.png");
	_upgradeBg->setAnchorPoint(Vec2(0, 0));
	this->addChild(_upgradeBg);

	_mainScene = Sprite::createWithSpriteFrameName("btn_main_up.png");
	_mainScene->setAnchorPoint(Vec2(0, 0));//-193,140
	_mainScene->setPosition(0, 280);
	this->addChild(_mainScene);

	_shopScene = Sprite::createWithSpriteFrameName("btn_shop01_up.png");
	_shopScene->setAnchorPoint(Vec2(0, 0));
	_shopScene->setPosition(380, 280);
	this->addChild(_shopScene);


	_upgrade = Sprite::createWithSpriteFrameName(Hero::getInstance()->getGold() >= 250 ? "btn_upgrade_up.png" : "btn_upgrade_disable.png");
	_upgrade->setAnchorPoint(Vec2(0, 0));
	_upgrade->setPosition(200, 130);
	this->addChild(_upgrade);
	
	
	_unit00 = Sprite::createWithSpriteFrameName("btn_unit_00_up.png");
	_unit00->setScale(0.54);
	_unit00->setPosition(33.3, 246);
	this->addChild(_unit00);

	_unit02 = Sprite::createWithSpriteFrameName(Hero::getInstance()->getUnitTwoUnlock() ? "btn_unit_02_up.png" : "btn_unit_02_down.png");
	_unit02->setScale(0.54);
	_unit02->setPosition(89.4, 246);
	this->addChild(_unit02);

	_unit03 = Sprite::createWithSpriteFrameName(Hero::getInstance()->getUnitTwoUnlock() ? Hero::getInstance()->getUnitThreeUnlock() ? "btn_unit_03_up.png" : "btn_unit_03_down.png" : "btn_unit_03_disable.png");
	_unit03->setScale(0.54);
	_unit03->setPosition(145.5, 246);
	this->addChild(_unit03);
	
	_unit01 = Sprite::createWithSpriteFrameName("btn_unit_01_disable.png");
	_unit01->setScale(0.54);
	_unit01->setPosition(198.7, 257.5);
	this->addChild(_unit01);

	_unit04 = Sprite::createWithSpriteFrameName("btn_unit_04_disable.png");
	_unit04->setScale(0.54);
	_unit04->setPosition(90.5, 257.5);
	this->addChild(_unit04);

	_unit05 = Sprite::createWithSpriteFrameName("btn_unit_05_disable.png");
	_unit05->setScale(0.54);
	_unit05->setPosition(89.5, 257.5);
	this->addChild(_unit05);

	_unit06 = Sprite::createWithSpriteFrameName("btn_unit_06_disable.png"); 
	_unit06->setScale(0.54);
	_unit06->setPosition(-76.5, 185);
	this->addChild(_unit06);

	_unit07 = Sprite::createWithSpriteFrameName("btn_unit_07_disable.png");
	_unit07->setScale(0.54);
	_unit07->setPosition(-75.75, 185);
	this->addChild(_unit07);

	_unit08 = Sprite::createWithSpriteFrameName("btn_unit_08_disable.png");
	_unit08->setScale(0.54);
	_unit08->setPosition(-75, 185);
	this->addChild(_unit08);	

	_unitSelect = Sprite::createWithSpriteFrameName("unit_selected.png");
	_unitSelect->setPosition(240, 161);
	this->addChild(_unitSelect);

	_select = 0;

	TTFConfig ttfConfig("fonts/Typo_SsangmunDongB.ttf", 10);
	ttfConfig.outlineSize = 1;

	_hp = Label::createWithTTF(ttfConfig, "300");
	_hp->setPosition(Vec2(395, 265));
	this->addChild(_hp);

	_attack = Label::createWithTTF(ttfConfig, "200");
	_attack->setPosition(Vec2(395, 235));
	this->addChild(_attack);

	_speed = Label::createWithTTF(ttfConfig, "30");
	_speed->setPosition(Vec2(395, 205));
	this->addChild(_speed);

	_delay = Label::createWithTTF(ttfConfig, "340");
	_delay->setPosition(Vec2(395, 175));
	this->addChild(_delay);

	ttfConfig.fontSize = 13;

	_gold = Label::createWithTTF(ttfConfig, "250");
	_gold->setPosition(Vec2(410, 143));
	_gold->setColor(Color3B::YELLOW);
	this->addChild(_gold);

	_myGold = Label::createWithTTF(ttfConfig, StringUtils::format("%d", (int)Hero::getInstance()->getGold()));
	_myGold->setPosition(Vec2(115, 32));
	_myGold->setColor(Color3B::YELLOW);
	this->addChild(_myGold);

	_unit = Sprite::createWithSpriteFrameName("u01_walk_0001.png");
	_unit->setPosition(260, 255);
	this->addChild(_unit, 10);

	_hpBar = Sprite::createWithSpriteFrameName("unit_status_gauge_now.png");
	_hpBar->setPosition(343, 254);
	_hpBar->setScaleX(5);
	_hpBar->setAnchorPoint(Vec2(0, 0.5));
	this->addChild(_hpBar);

	_attackBar = Sprite::createWithSpriteFrameName("unit_status_gauge_now.png");
	_attackBar->setPosition(343, 224);
	_attackBar->setScaleX(3);
	_attackBar->setAnchorPoint(Vec2(0, 0.5));
	this->addChild(_attackBar);

	_speedBar = Sprite::createWithSpriteFrameName("unit_status_gauge_now.png");
	_speedBar->setPosition(343, 194);
	_speedBar->setScaleX(58.5);
	_speedBar->setAnchorPoint(Vec2(0, 0.5));
	this->addChild(_speedBar);

	_delayBar = Sprite::createWithSpriteFrameName("unit_status_gauge_now.png");
	_delayBar->setPosition(343, 164);
	_delayBar->setScaleX(30);
	_delayBar->setAnchorPoint(Vec2(0, 0.5));
	this->addChild(_delayBar);

	Vector<SpriteFrame*> frame;
	for (int i = 1; i <= 11; i++) {
		frame.pushBack(SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(StringUtils::format("u01_walk_%04d.png", i)));
	}
	auto animation = Animation::createWithSpriteFrames(frame, 0.05f);
	auto animate = Animate::create(animation);
	auto action = RepeatForever::create(animate);
	_unit->runAction(action);

	return true;
}

bool UpgradeScene::onTouchBegan(Touch * touch, Event * event)
{
	if (_mainScene->getBoundingBox().containsPoint(touch->getLocation()))
	{
		_mainScene->setSpriteFrame("btn_main_down.png");
		AudioEngine::play2d("Sound/ok_button.mp3", false, 0.6);
		auto scene = IntroScene::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(2, scene));
	}
	if (_shopScene->getBoundingBox().containsPoint(touch->getLocation()))
	{
		_shopScene->setSpriteFrame("btn_shop01_down.png");
		AudioEngine::play2d("Sound/ok_button.mp3", false, 0.6);
		auto scene = MapMindForestScene::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(2, scene));
	}
	if (_upgrade->getBoundingBox().containsPoint(touch->getLocation()) &&
		1) {
		switch (_select) {
		case 0:
			if (Hero::getInstance()->getGold() < 250) {
				_upgrade->setSpriteFrame("btn_upgrade_disable.png");
			}
			else {
				_upgrade->setSpriteFrame("btn_upgrade_down.png");
				AudioEngine::play2d("Sound/ok_button.mp3", false, 0.6);
			}
			break;
		case 2:
			if (Hero::getInstance()->getGold() < 1000) {
				_upgrade->setSpriteFrame("btn_upgrade_disable.png");
			}
			else {
				AudioEngine::play2d("Sound/ok_button.mp3", false, 0.6);
				_upgrade->setSpriteFrame("btn_upgrade_down.png");
				if (Hero::getInstance()->getUnitTwoUnlock()) {

				}
				else {
					Hero::getInstance()->setGold(Hero::getInstance()->getGold() - 1000);
					Hero::getInstance()->setUnitTwoUnlock(true);
					_unit02->setSpriteFrame("btn_unit_02_up.png");
					_unit03->setSpriteFrame("btn_unit_03_down.png");
				}
				if (Hero::getInstance()->getGold() < 1000) {
					_upgrade->setSpriteFrame("btn_upgrade_disable.png");
				}
			}
			break;
		case 3:
			if (Hero::getInstance()->getGold() < 1500 || !Hero::getInstance()->getUnitTwoUnlock()) {
				_upgrade->setSpriteFrame("btn_upgrade_disable.png");
			}
			else {
				AudioEngine::play2d("Sound/ok_button.mp3", false, 0.6);
				_upgrade->setSpriteFrame("btn_upgrade_down.png");
				if (Hero::getInstance()->getUnitThreeUnlock()) {
					
				}
				else {
					Hero::getInstance()->setGold(Hero::getInstance()->getGold() - 1500);
					Hero::getInstance()->setUnitThreeUnlock(true);
					_unit03->setSpriteFrame("btn_unit_03_up.png");
				}
				if (Hero::getInstance()->getGold() < 1500 || !Hero::getInstance()->getUnitTwoUnlock()) {
					_upgrade->setSpriteFrame("btn_upgrade_disable.png");
				}
			}
			break;
		}
	}

	if (_unit00->getBoundingBox().containsPoint(touch->getLocation()))
	{
		if (Hero::getInstance()->getGold() < 250) {
			_upgrade->setSpriteFrame("btn_upgrade_disable.png");
		}
		else {
			_upgrade->setSpriteFrame("btn_upgrade_up.png");
		}
		_unitSelect->setPosition(240, 161);
		_select = 0;
		_unit->cleanup();
		Vector<SpriteFrame*> frame;
		for (int i = 1; i <= 11; i++) {
			frame.pushBack(SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(StringUtils::format("u01_walk_%04d.png", i)));
		}
		auto animation = Animation::createWithSpriteFrames(frame, 0.05f);
		auto animate = Animate::create(animation);
		auto action = RepeatForever::create(animate);
		_unit->runAction(action);

		_hp->setString("300");
		_attack->setString("200");
		_speed->setString("30");
		_delay->setString("340");
		_gold->setString("250");

		_hpBar->setScaleX(5);
		_attackBar->setScaleX(3);
		_speedBar->setScaleX(58.5);
		_delayBar->setScaleX(30);
		AudioEngine::play2d("Sound/ok_button.mp3", false, 0.6);
	}
	if (_unit02->getBoundingBox().containsPoint(touch->getLocation()))
	{
		if (Hero::getInstance()->getGold() < 1000) {
			_upgrade->setSpriteFrame("btn_upgrade_disable.png");
		}
		else {
			_upgrade->setSpriteFrame("btn_upgrade_up.png");
		}
	
		_unitSelect->setPosition(296, 161);
		_select = 2;
		_unit->cleanup();
		Vector<SpriteFrame*> frame;
		for (int i = 1; i <= 12; i++) {
			frame.pushBack(SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(StringUtils::format("u03_walk_%04d.png", i)));
		}
		auto animation = Animation::createWithSpriteFrames(frame, 0.05f);
		auto animate = Animate::create(animation);
		auto action = RepeatForever::create(animate);
		_unit->runAction(action);

		_hp->setString("1200");
		_attack->setString("400");
		_speed->setString("23");
		_delay->setString("226");
		_gold->setString("1000");

		_hpBar->setScaleX(20);
		_attackBar->setScaleX(6);
		_speedBar->setScaleX(45);
		_delayBar->setScaleX(20);
		AudioEngine::play2d("Sound/ok_button.mp3", false, 0.6);
	}
	if (_unit03->getBoundingBox().containsPoint(touch->getLocation()))
	{
		if (Hero::getInstance()->getGold() < 1500 || !Hero::getInstance()->getUnitTwoUnlock()) {
			_upgrade->setSpriteFrame("btn_upgrade_disable.png");
		}
		else {
			_upgrade->setSpriteFrame("btn_upgrade_up.png");
		}
		_unitSelect->setPosition(352, 161);
		_select = 3;
		_unit->cleanup();
		Vector<SpriteFrame*> frame;
		for (int i = 1; i <= 12; i++) {
			frame.pushBack(SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(StringUtils::format("u04_walk_%04d.png", i)));
		}
		auto animation = Animation::createWithSpriteFrames(frame, 0.05f);
		auto animate = Animate::create(animation);
		auto action = RepeatForever::create(animate);
		_unit->runAction(action);

		_hp->setString("1600");
		_attack->setString("200");
		_speed->setString("27");
		_delay->setString("20");
		_gold->setString("1500");

		_hpBar->setScaleX(26);
		_attackBar->setScaleX(3);
		_speedBar->setScaleX(53);
		_delayBar->setScaleX(3);
		AudioEngine::play2d("Sound/ok_button.mp3", false, 0.6);
	}
	_myGold->setString(StringUtils::format("%d", (int)Hero::getInstance()->getGold()));
	return true;
}

void UpgradeScene::onTouchMoved(Touch * touch, Event * event)
{
}

void UpgradeScene::onTouchEnded(Touch * touch, Event * event)
{
	_mainScene->setSpriteFrame("btn_main_up.png");
	_shopScene->setSpriteFrame("btn_shop01_up.png");
	switch (_select) {
	case 0:
		if (Hero::getInstance()->getGold() < 250) {
			//_upgrade->setSpriteFrame("btn_upgrade_disable.png");
		}
		else {
			_upgrade->setSpriteFrame("btn_upgrade_up.png");
		}
		break;
	case 2:
		if (Hero::getInstance()->getGold() < 1000) {
			//_upgrade->setSpriteFrame("btn_upgrade_disable.png");
		}
		else {
			_upgrade->setSpriteFrame("btn_upgrade_up.png");
		}
		break;
	case 3:
		if (Hero::getInstance()->getGold() < 1500 || !Hero::getInstance()->getUnitTwoUnlock()) {
			//_upgrade->setSpriteFrame("btn_upgrade_disable.png");
		}
		else {
			_upgrade->setSpriteFrame("btn_upgrade_up.png");
		}
		break;
	}
}
