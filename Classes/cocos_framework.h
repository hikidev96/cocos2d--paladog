/*
	프레임워크 코드 작성 : 예민수
*/

#pragma once

// include library
#include <string>
#include <map>
#include <algorithm>
#include "cocos2d.h"
#include "ui/UIEditBox/UIEditBox.h"
#include "ui/CocosGUI.h"
#include "cocos2d/extensions/cocos-ext.h" // for tableView
#include "tinyxml2/tinyxml2.h" // for xml import
#include "json/rapidjson.h"
#include "json/document.h"
#include "json/stringbuffer.h"
#include "json/prettywriter.h"
#include "network/HttpClient.h"

// using namespace
USING_NS_CC; // for cocos2d
USING_NS_CC_EXT; // the same using namespace extension
using namespace std; // for std
using namespace ui; // for ui
using namespace tinyxml2; // for xml import
using namespace cocos2d::network;
// using namespace extension; // for tableView

// is make you can print korean language on cocos2d
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

//Git Test