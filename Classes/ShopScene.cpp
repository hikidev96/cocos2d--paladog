#include "ShopScene.h"
#include "Shop.h"
#include "ui/CocosGUI.h"
#include "cocos_framework.h"
USING_NS_CC;
using namespace ui;
Scene* ShopScene::createScene() {
	return ShopScene::create();
}

bool ShopScene::init() {

	if (!Scene::init()) {
		return false;
	}
	auto _pigie = Sprite::create("UI/Shop/ShopPig/pig_1.png");
	_pigie->setPosition(Point(80, 200));

	auto _pigmotion = Animation::create();
	_pigmotion->setDelayPerUnit(0.1f);
	//상점돼지
	_pigmotion->addSpriteFrameWithFile("UI/Shop/ShopPig/pig_1.png");
	_pigmotion->addSpriteFrameWithFile("UI/Shop/ShopPig/pig_2.png");
	_pigmotion->addSpriteFrameWithFile("UI/Shop/ShopPig/pig_3.png");
	_pigmotion->addSpriteFrameWithFile("UI/Shop/ShopPig/pig_4.png");
	_pigmotion->addSpriteFrameWithFile("UI/Shop/ShopPig/pig_5.png");
	_pigmotion->addSpriteFrameWithFile("UI/Shop/ShopPig/pig_6.png");
	_pigmotion->addSpriteFrameWithFile("UI/Shop/ShopPig/pig_7.png");
	_pigmotion->addSpriteFrameWithFile("UI/Shop/ShopPig/pig_8.png");
	_pigmotion->addSpriteFrameWithFile("UI/Shop/ShopPig/pig_9.png");
	_pigmotion->addSpriteFrameWithFile("UI/Shop/ShopPig/pig_10.png");
	_pigmotion->addSpriteFrameWithFile("UI/Shop/ShopPig/pig_11.png");
	_pigmotion->addSpriteFrameWithFile("UI/Shop/ShopPig/pig_12.png");
	_pigmotion->addSpriteFrameWithFile("UI/Shop/ShopPig/pig_13.png");
	_pigmotion->addSpriteFrameWithFile("UI/Shop/ShopPig/pig_14.png");
	_pigmotion->addSpriteFrameWithFile("UI/Shop/ShopPig/pig_15.png");
	_pigmotion->addSpriteFrameWithFile("UI/Shop/ShopPig/pig_16.png");
	_pigmotion->addSpriteFrameWithFile("UI/Shop/ShopPig/pig_17.png");
	_pigmotion->addSpriteFrameWithFile("UI/Shop/ShopPig/pig_18.png");
	_pigmotion->addSpriteFrameWithFile("UI/Shop/ShopPig/pig_19.png");
	_pigmotion->addSpriteFrameWithFile("UI/Shop/ShopPig/pig_20.png");
	_pigmotion->addSpriteFrameWithFile("UI/Shop/ShopPig/pig_21.png");

	auto animate = Animate::create(_pigmotion);
	auto repeat = RepeatForever::create(animate);
	_pigie->setScale(0.35f);
	_pigie->runAction(repeat);

	//=====================================================


	auto gold_01 = Sprite::create("UI/Shop/gold.png");
	auto mace_01 = Sprite::create("UI/Shop/mace_01.png");
	auto mace_02 = Sprite::create("UI/Shop/mace_02.png");
	auto mace_03 = Sprite::create("UI/Shop/mace_03.png");
	auto mace_04 = Sprite::create("UI/Shop/mace_04.png");
	auto mace_05 = Sprite::create("UI/Shop/mace_05.png");
	auto mace_06 = Sprite::create("UI/Shop/mace_06.png");
	auto mace_07 = Sprite::create("UI/Shop/mace_07.png");
	auto mace_08 = Sprite::create("UI/Shop/mace_08.png");

	auto ring_01 = Sprite::create("UI/Shop/ring_01.png");
	auto ring_02 = Sprite::create("UI/Shop/ring_02.png");
	auto ring_03 = Sprite::create("UI/Shop/ring_03.png");
	auto ring_04 = Sprite::create("UI/Shop/ring_04.png");
	auto ring_05 = Sprite::create("UI/Shop/ring_05.png");
	auto ring_06 = Sprite::create("UI/Shop/ring_06.png");
	auto ring_07 = Sprite::create("UI/Shop/ring_07.png");
	auto ring_08 = Sprite::create("UI/Shop/ring_08.png");
	auto ring_09 = Sprite::create("UI/Shop/ring_09.png");
	auto ring_10 = Sprite::create("UI/Shop/ring_10.png");
	



	//스프라이트 위치 설정
	gold_01->setPosition(Vec2(30, 50));
	gold_01->setScale(0.5f);


	mace_01->setPosition(Vec2(80, 50));
	mace_01->setScale(0.5f);
	mace_02->setPosition(Vec2(130, 50));
	mace_02->setScale(0.5f);
	mace_03->setPosition(Vec2(180, 50));
	mace_03->setScale(0.5f);
	mace_04->setPosition(Vec2(230, 50));
	mace_04->setScale(0.5f);
	mace_05->setPosition(Vec2(280, 50));
	mace_05->setScale(0.5f);
	mace_06->setPosition(Vec2(330, 50));
	mace_06->setScale(0.5f);
	mace_07->setPosition(Vec2(380, 50));
	mace_07->setScale(0.5f);
	mace_08->setPosition(Vec2(430, 50));
	mace_08->setScale(0.5f);

	ring_01->setPosition(Vec2(480, 50));
	ring_01->setScale(0.5f);
	ring_02->setPosition(Vec2(530, 50));
	ring_02->setScale(0.5f);
	ring_03->setPosition(Vec2(580, 50));
	ring_03->setScale(0.5f);
	ring_04->setPosition(Vec2(630, 50));
	ring_04->setScale(0.5f);
	ring_05->setPosition(Vec2(730, 50));
	ring_05->setScale(0.5f);
	ring_06->setPosition(Vec2(680, 50));
	ring_06->setScale(0.5f);
	ring_07->setPosition(Vec2(780, 50));
	ring_07->setScale(0.5f);
	ring_08->setPosition(Vec2(830, 50));
	ring_08->setScale(0.5f);
	ring_09->setPosition(Vec2(880, 50));
	ring_09->setScale(0.5f);
	ring_10->setPosition(Vec2(930, 50));
	ring_10->setScale(0.5f);

	//스크롤뷰 레이어

	auto layer = LayerColor::create();
	layer->setAnchorPoint({ 0,0 });
	layer->setPosition(0, 0);
	layer->setContentSize(Size(960, 160));
	layer->addChild(gold_01);
	layer->addChild(mace_01);
	layer->addChild(mace_02);
	layer->addChild(mace_03);
	layer->addChild(mace_04);
	layer->addChild(mace_05);
	layer->addChild(mace_06);
	layer->addChild(mace_07);
	layer->addChild(mace_08);

	layer->addChild(ring_01);
	layer->addChild(ring_02);
	layer->addChild(ring_03);
	layer->addChild(ring_04);
	layer->addChild(ring_05);
	layer->addChild(ring_06);
	layer->addChild(ring_07);
	layer->addChild(ring_08);
	layer->addChild(ring_09);
	layer->addChild(ring_10);


	auto scrolling = cocos2d::ui::ScrollView::create();
	scrolling->setSize(Size(480, 300));
	scrolling->setInnerContainerSize(layer->getContentSize());
	scrolling->setDirection(cocos2d::ui::ScrollView::Direction::HORIZONTAL);
	scrolling->addChild(layer);
	scrolling->setBounceEnabled(true);
	scrolling->setScrollBarAutoHideEnabled(true);
	scrolling->setPosition(Vec2(0, 90));
	
	this->addChild(Shop::ShopInven());
	this->addChild(Shop::Shopbg());
	this->addChild(_pigie);
	this->addChild(Shop::ShopBoard());
	this->addChild(scrolling);
	return true;
}