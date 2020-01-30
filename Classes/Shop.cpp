#include "Shop.h"
#include "ui/CocosGUI.h"
#include "cocos_framework.h"

USING_NS_CC;

using namespace ui;

Sprite* Shop::_ShopBoard = nullptr;
Sprite* Shop::_Shopbg = nullptr;
Sprite* Shop::_ShopInven = nullptr;
SpriteFrameCache* Shop::_cache = SpriteFrameCache::getInstance();

Sprite * Shop::Shopbg()
{
	_cache->addSpriteFramesWithFile("UI/Shop/upgrade_equip_01_0-hd.plist");

	_Shopbg = Sprite::createWithSpriteFrameName("shop_background.png");
	_Shopbg->setAnchorPoint(Vec2(0, 0));
	_Shopbg->setScale(0.5f);
	return _Shopbg;
}

Sprite * Shop::ShopBoard()
{
	_cache->addSpriteFramesWithFile("UI/Shop/upgrade_equip_01_0-hd.plist");

	_ShopBoard = Sprite::createWithSpriteFrameName("shop_board.png");
	_ShopBoard->setAnchorPoint(Vec2(0, 0));
	_ShopBoard->setScale(0.5f);
	return _ShopBoard;
}


Sprite * Shop::ShopInven()
{
	_cache->addSpriteFramesWithFile("UI/Shop/upgrade_equip_01_0-hd.plist");

	_ShopInven = Sprite::createWithSpriteFrameName("inven_board.png");
	_ShopInven->setAnchorPoint(Vec2(0, 0));
	_ShopInven->setScale(0.5f);
	return _ShopInven;
}

