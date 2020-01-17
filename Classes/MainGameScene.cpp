#include "MainGameScene.h"

Scene* MainGameScene::createScene() {
  return MainGameScene::create();
}

bool MainGameScene::init() {
  if (!Scene::init()) {
    return false;
  }
	
  return true;
}