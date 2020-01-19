#include "HeroControl.h"

HeroControl::HeroControl(Scene* scene, Hero* hero)
{
	_hero = hero; // 히어로 메모리주소 받아오기
	_scene = scene; // Scene 메모리주소 받아오기

	cache = SpriteFrameCache::getInstance(); // 캐쉬생성
	cache->addSpriteFramesWithFile("UI/ui_gameplay.plist"); // plist 추가

	// 리스너 등록
	listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HeroControl::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HeroControl::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HeroControl::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, _scene);

	// 히어로 조작 스프라이트
	_leftButton = Sprite::createWithSpriteFrameName("btn_left_up.png");
	_leftButton->setAnchorPoint({ 0,0 });
	_leftButton->setPosition({ 10,5 });
	_rightButton = Sprite::createWithSpriteFrameName("btn_right_up.png");
	_rightButton->setAnchorPoint({ 0,0 });
	_rightButton->setPosition({ 125,5 });

	// 대쉬보드 스프라이트
	_mainDashbord = Sprite::createWithSpriteFrameName("ui_game_dashboard.png");
	_mainDashbord->setAnchorPoint({ 0,0 });
	_mainDashbord->setPosition({ 0,0 });
	_mainDashbordCase = Sprite::createWithSpriteFrameName("ui_macebtn_case.png");
	_mainDashbordCase->setAnchorPoint({ 0,0 });
	_mainDashbordCase->setPosition({ 237,2 });

	// 스킬 1,2,3 버튼 스프라이트
	_skillOneButton = Sprite::createWithSpriteFrameName("btn_fist_up.png");
	_skillOneButton->setAnchorPoint({ 0,0 });
	_skillOneButton->setPosition({ 256,5 });
	_skillTwoButton = Sprite::createWithSpriteFrameName("btn_heal_up.png");
	_skillTwoButton->setAnchorPoint({ 0,0 });
	_skillTwoButton->setPosition({ 333,5 });
	_skillThreeButton = Sprite::createWithSpriteFrameName("btn_turnundead_up.png");
	_skillThreeButton->setAnchorPoint({ 0,0 });
	_skillThreeButton->setPosition({ 407,5 });

	// addchild
	_scene->addChild(_leftButton,1);
	_scene->addChild(_rightButton,1);
	_scene->addChild(_mainDashbord,0);
	_scene->addChild(_mainDashbordCase,2);
	_scene->addChild(_skillOneButton, 0);
	_scene->addChild(_skillTwoButton, 0);
	_scene->addChild(_skillThreeButton, 0);

	_right = false; // 오른쪽이동
	_left = false; // 왼쪽이동
	_skillOneClick = false; // 스킬1 버튼
	_skillTwoClick = false; // 스킬2 버튼
	_skillThreeClick = false; // 스킬3 버튼
}

void HeroControl::HeroMove()
{
	// 히어로 조작부
	if (_left)
	{
		_hero->setMoveWay(LeftWay); // 왼쪽을 보는상태

		_hero->getHero()->setPosition(_hero->getHero()->getPosition() + Vec2(_hero->getSpeed() * -1, 0));

		if (!_hero->getHero()->getNumberOfRunningActionsByTag(Walking))
		{
			_hero->getHero()->runAction(_hero->getWalkingAction());
		}
	}
	if (_right)
	{
		_hero->setMoveWay(RightWay); // 오른쪽을 보는상태 

		_hero->getHero()->setPosition(_hero->getHero()->getPosition() + Vec2(_hero->getSpeed(), 0));

		if (!_hero->getHero()->getNumberOfRunningActionsByTag(Walking))
		{
			_hero->getHero()->runAction(_hero->getWalkingAction());
		}
	}
	if (/*!_left && !_right*/ !_hero->getHero()->getNumberOfRunningActions())
	{
		if (!_hero->getHero()->getNumberOfRunningActionsByTag(Waiting))
		{
			_hero->getHero()->runAction(_hero->getWaitingAction());
			
		}
	}

	// 스킬버튼 1
	if (_hero->getMana() < _hero->getSkillOneManaUse())
	{
		_skillOneButton->setSpriteFrame("btn_fist_disable.png");
	}
	else if (_hero->getMana() >= _hero->getSkillOneManaUse() && !_skillOneClick)
	{
		_skillOneButton->setSpriteFrame("btn_fist_up.png");
	}
	else if (_skillOneClick)
	{
		_skillOneButton->setSpriteFrame("btn_fist_down.png");
	}
	// 스킬버튼 2
	if (_hero->getMana() < _hero->getSkillTwoManaUse())
	{
		_skillTwoButton->setSpriteFrame("btn_fist_disable.png");
	}
	else if (_hero->getMana() >= _hero->getSkillTwoManaUse() && !_skillTwoClick)
	{
		_skillTwoButton->setSpriteFrame("btn_heal_up.png");
	}
	else if (_skillTwoClick)
	{
		_skillTwoButton->setSpriteFrame("btn_heal_down.png");
	}

	// 스킬버튼 3
	if (_hero->getMana() < _hero->getSkillThreeManaUse())
	{
		_skillThreeButton->setSpriteFrame("btn_fist_disable.png");
	}
	else if (_hero->getMana() >= _hero->getSkillThreeManaUse() && !_skillThreeClick)
	{
		_skillThreeButton->setSpriteFrame("btn_turnundead_up.png");
	}
	else if (_skillThreeClick)
	{
		_skillThreeButton->setSpriteFrame("btn_turnundead_down.png");
	}

	_hero->getManaGauge()->setPercentage((_hero->getMana() / _hero->getMaxMana()) * 100); // 마나게이지를 보여준다
}

void HeroControl::UnitMove()
{
	// 유닛 이동
	for (int i = 0; i < _heroUnitVec.size(); ++i)
	{
		_heroUnitVec[i]->getSprite()->setPosition(_heroUnitVec[i]->getSprite()->getPosition() +
			Vec2(_heroUnitVec[i]->getSpeed(), 0));
	}
}

void HeroControl::HeroManaRegen()
{
	// 마나 리젠
	if (_hero->getMana() < _hero->getMaxMana())
	{
		_hero->setMana(_hero->getMana() + 1);
		log("%f", _hero->getMana());
	}
}

bool HeroControl::onTouchBegan(Touch * touch, Event * event)
{
	if (_leftButton->getBoundingBox().containsPoint(touch->getLocation()))
	{

		_hero->getHero()->setFlippedX(true);
		_left = true;
		_leftButton->setSpriteFrame("btn_left_down.png");
		
	}
	else if (_rightButton->getBoundingBox().containsPoint(touch->getLocation()))
	{
		_hero->getHero()->setFlippedX(false);
		_right = true;
		_rightButton->setSpriteFrame("btn_right_down.png");
	}

	if (_hero->getHero()->getNumberOfRunningActionsByTag(Waiting))
	{
		_hero->getHero()->stopActionByTag(Waiting);
	}

	// 스킬 1 클릭시 행동
	if (_skillOneButton->getBoundingBox().containsPoint(touch->getLocation()))
	{
		_skillOneClick = true;

		if (_hero->getMana() > _hero->getSkillOneManaUse())
		{
			_hero->setMana(_hero->getMana() - _hero->getSkillOneManaUse());
			_hero->getHero()->runAction(_hero->getAttackAction()->clone()); // 공격 모션 실행
		}

		_heroUnit = new HeroUnit(_scene, 생쥐);
		_heroUnitVec.push_back(_heroUnit);

	}

	// 스킬 2 클릭시 행동
	if (_skillTwoButton->getBoundingBox().containsPoint(touch->getLocation()))
	{
		_skillTwoClick = true;


		if (_hero->getMana() > _hero->getSkillTwoManaUse())
		{
			_hero->setMana(_hero->getMana() - _hero->getSkillTwoManaUse());
			_hero->getHero()->runAction(_hero->getAttackAction()->clone()); // 공격 모션 실행
		}

	}

	// 스킬 3 클릭시 행동
	if (_skillThreeButton->getBoundingBox().containsPoint(touch->getLocation()))
	{
		_skillThreeClick = true;


		if (_hero->getMana() > _hero->getSkillThreeManaUse())
		{
			_hero->setMana(_hero->getMana() - _hero->getSkillThreeManaUse());
			_hero->getHero()->runAction(_hero->getAttackAction()->clone()); // 공격 모션 실행
		}

	}

	

	/*log("터치좌표 : %f , %f", touch->getLocation().x, touch->getLocation().y);
	log("유닛백터사이즈 : %d", _heroUnitVec.size());*/

	return true;
}

void HeroControl::onTouchMoved(Touch * touch, Event * event)
{
}

void HeroControl::onTouchEnded(Touch * touch, Event * event)
{
	_left = false;
	_right = false;
	_skillOneClick = false;
	_skillTwoClick = false;
	_skillThreeClick = false;

	_leftButton->setSpriteFrame("btn_left_up.png");
	_rightButton->setSpriteFrame("btn_right_up.png");

	if (_hero->getHero()->getNumberOfRunningActionsByTag(Walking))
	{
		_hero->getHero()->stopActionByTag(Walking);
	}

}
