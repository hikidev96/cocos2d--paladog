#include "UpgradeScene.h"
#include "ui/CocosGUI.h"
#include "cocos_framework.h"
USING_NS_CC;
using namespace ui;

Scene* UpgradeScene::createScene() {
	return UpgradeScene::create();
}

bool UpgradeScene::init() {

	if (!Scene::init()) {
		return false;
	}

	_cache = SpriteFrameCache::getInstance();

	_cache->addSpriteFramesWithFile("UI/Upgrade/upgrade_equip_02.plist");
	_cache->addSpriteFramesWithFile("Player/UNIT_B~1/btn_unit-hd.plist"); 
	_cache->addSpriteFramesWithFile("Player/Unit/u_01_1.plist");
	_cache->addSpriteFramesWithFile("Player/Unit/u_02_1.plist");


	listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(UpgradeScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(UpgradeScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(UpgradeScene::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	auto* _upgradeBg = Sprite::createWithSpriteFrameName("unit_upgrade_back.png");
	_upgradeBg->setAnchorPoint(Vec2(0, 0));
	this->addChild(_upgradeBg);

	_mainScene = Sprite::createWithSpriteFrameName("btn_main_up.png");
	_mainScene->setAnchorPoint(Vec2(0, 0));
	this->addChild(_mainScene);

	_shopScene = Sprite::createWithSpriteFrameName("btn_shop01_up.png");
	_shopScene->setAnchorPoint(Vec2(0, 0));
	this->addChild(_shopScene);
	

	_unit00 = Sprite::createWithSpriteFrameName("btn_unit_00_up.png");
	_unit00->setScale(0.54);
	_unit00->setPosition(33.3, 246);
	this->addChild(_unit00);

	_unit02 = Sprite::createWithSpriteFrameName("btn_unit_02_up.png");
	_unit02->setScale(0.54);
	_unit02->setPosition(89.4, 246);
	this->addChild(_unit02);

	_unit03 = Sprite::createWithSpriteFrameName("btn_unit_03_up.png");
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

	return true;
}

bool UpgradeScene::onTouchBegan(Touch * touch, Event * event)
{
	if (_mainScene->getBoundingBox().containsPoint(touch->getLocation()))
	{
		_mainScene->setSpriteFrame("btn_main_down.png");
		log("main down");
	}
	else if (_shopScene->getBoundingBox().containsPoint(touch->getLocation()))
	{
		_shopScene->setSpriteFrame("btn_shop01_down.png");
		log("shop down");
	}
	if (_unit00->getBoundingBox().containsPoint(touch->getLocation()))
	{
		_unitSelect->setPosition(240, 161);
		_select = 0;
		log("unit0 down");
	}
	if (_unit02->getBoundingBox().containsPoint(touch->getLocation()))
	{
		_unitSelect->setPosition(296, 161);
		_select = 2;
		log("unit1 down");
	}
	if (_unit03->getBoundingBox().containsPoint(touch->getLocation()))
	{
		_unitSelect->setPosition(352, 161);
		_select = 3;
		log("unit2 down");
	}
	return true;
}

void UpgradeScene::onTouchMoved(Touch * touch, Event * event)
{
}

void UpgradeScene::onTouchEnded(Touch * touch, Event * event)
{
	_mainScene->setSpriteFrame("btn_main_up.png");
	_shopScene->setSpriteFrame("btn_shop01_up.png");
}
