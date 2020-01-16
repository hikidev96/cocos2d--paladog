#include "HeroUnit.h"

void HeroUnit::createUnitMouse(Scene* scene)
{
	_heroUnit = new HeroUnit;
	_heroUnit->_UnitSprite = nullptr;

	_unitVec.push_back(_heroUnit);

	for (int i = 0; i < _unitVec.size(); i++)
	{
		if (_unitVec[i]->_UnitSprite == nullptr)
		{
			_unitVec[i]->_UnitSprite = Sprite::create("HelloWorld.png");
			_unitVec[i]->_UnitSprite->setPosition(100,150);
			_unitVec[i]->_UnitSprite->setScale(0.2f);
			_unitVec[i]->_Speed = 0.6f;
			_unitVec[i]->_Hp = 1.0f;
			_unitVec[i]->_Atk = 0.6f;
			scene->addChild(_unitVec[i]->_UnitSprite);

		}
	}




	

	//for (int i = 0; i < _unitVec.size(); ++i)
	//{
	//	if ()
	//		scene->addChild(_unitVec[i]->getSprite());
	//}
}

void HeroUnit::createUnitBear(Scene* scene)
{
}

void HeroUnit::createUnitKangaroo(Scene* scene)
{
}

void HeroUnit::MoveUnit()
{
	for (int i = 0; i < _unitVec.size(); i++)
	{
		_unitVec[i]->getSprite()->setPosition(_unitVec[i]->getSprite()->getPosition() + Vec2(_unitVec[i]->getSpeed(), 0));
	}
}
