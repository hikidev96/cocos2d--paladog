#include "IntroScene.h"
#include "Background.h"
#include "MainGameScene.h"

Scene* IntroScene::createScene() {
  return IntroScene::create();
}

bool IntroScene::init() {
  if (!Scene::init()) {
    return false;
  }

  this->addChild(Background::GetIntroBackground());
  this->scheduleOnce(schedule_selector(IntroScene::changeIntroBG), 3.0f);

  return true;
}

void IntroScene::changeIntroBG(float t) {
  auto scene = MainGameScene::createScene();
  Director::getInstance()->replaceScene(scene);
}