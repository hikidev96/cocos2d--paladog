#include "MapMindForest.h"

Scene* MapMindForest::createScene() {
  return MapMindForest::create();
}

bool MapMindForest::init() {
  if (!Scene::init()) {
    return false;
  }

  log("check");

  return true;
}