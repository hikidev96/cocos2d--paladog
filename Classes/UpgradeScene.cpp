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


	auto* _upgradeBg = Sprite::createWithSpriteFrameName("unit_upgrade_back.png");
	_upgradeBg->setAnchorPoint(Vec2(0, 0));
	this->addChild(_upgradeBg);

	auto* _mainScene = Sprite::createWithSpriteFrameName("btn_main_up.png");
	_mainScene->setAnchorPoint(Vec2(0, 0));
	this->addChild(_mainScene);

	auto* _shopScene = Sprite::createWithSpriteFrameName("btn_shop01_up.png");
	_shopScene->setAnchorPoint(Vec2(0, 0));
	this->addChild(_shopScene);
	

	auto* _unit00Up = Sprite::createWithSpriteFrameName("btn_unit_00_up.png");
	_unit00Up->setScale(0.54);
	_unit00Up->setPosition(33.3, 246);
	this->addChild(_unit00Up);

	auto* _unit01Up = Sprite::createWithSpriteFrameName("btn_unit_01_up.png");
	_unit01Up->setScale(0.54);
	_unit01Up->setPosition(198.7, 257.5);
	this->addChild(_unit01Up);

	auto* _unit02Up = Sprite::createWithSpriteFrameName("btn_unit_02_up.png");
	_unit02Up->setScale(0.54);
	_unit02Up->setPosition(89.4, 246);
	this->addChild(_unit02Up);

	auto* _unit03Up = Sprite::createWithSpriteFrameName("btn_unit_03_up.png");
	_unit03Up->setScale(0.54);
	_unit03Up->setPosition(145.5, 246);
	this->addChild(_unit03Up);

	auto* _unit04Up = Sprite::createWithSpriteFrameName("btn_unit_04_up.png");
	_unit04Up->setScale(0.54);
	_unit04Up->setPosition(90.5, 257.5);
	this->addChild(_unit04Up);

	auto* _unit05Up = Sprite::createWithSpriteFrameName("btn_unit_05_up.png");
	_unit05Up->setScale(0.54);
	_unit05Up->setPosition(89.5, 257.5);
	this->addChild(_unit05Up);

	auto* _unit06Up = Sprite::createWithSpriteFrameName("btn_unit_06_up.png");
	_unit06Up->setScale(0.54);
	_unit06Up->setPosition(-76.5, 185);
	this->addChild(_unit06Up);

	auto* _unit07Up = Sprite::createWithSpriteFrameName("btn_unit_07_up.png");
	_unit07Up->setScale(0.54);
	_unit07Up->setPosition(-75.75, 185);
	this->addChild(_unit07Up);

	auto* _unit08Up = Sprite::createWithSpriteFrameName("btn_unit_08_up.png");
	_unit08Up->setScale(0.54);
	_unit08Up->setPosition(-75, 185);
	this->addChild(_unit08Up);	

	auto* _unitSelect = Sprite::createWithSpriteFrameName("unit_selected.png");
	_unitSelect->setPosition(240, 161);
	this->addChild(_unitSelect);

	return true;
}