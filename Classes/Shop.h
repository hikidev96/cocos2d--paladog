#include "cocos_framework.h"
#include "cocos2d.h"
#include "ui\CocosGUI.h"

class Shop : public cocos2d::Scene
{
public:
	static Sprite* ShopBoard();
	static Sprite* ShopInven();
	static Sprite* Shopbg();
private:

	static SpriteFrameCache* _cache;
	static Sprite* _ShopBoard;
	static Sprite* _ShopInven;
	static Sprite* _Shopbg;

};