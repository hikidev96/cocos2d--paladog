#include "cocos_framework.h"
#include "GameDelegate.h"
#include "MainGameScene.h"
#include "MindForest_Stage1.h"
#include "IntroScene.h"

GameDelegate::GameDelegate() {
}

GameDelegate::~GameDelegate() {
#if USE_AUDIO_ENGINE
  AudioEngine::end();
#endif
}

void GameDelegate::initGLContextAttrs() {
  GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8, 0 };
  GLView::setGLContextAttrs(glContextAttrs);
}

static int register_all_packages() {
  return 0;
}

bool GameDelegate::applicationDidFinishLaunching() {
  auto director = Director::getInstance();

  auto glview = director->getOpenGLView();
  if (!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
    glview = GLViewImpl::createWithRect("Paladog", Rect(0, 0, 1280, 720));
#else
    glview = GLViewImpl::create("Paladog");
#endif
    director->setOpenGLView(glview);
  }

  director->setDisplayStats(false);

  director->setAnimationInterval(1.0f / 60);

  glview->setDesignResolutionSize(480, 320, ResolutionPolicy::EXACT_FIT);

  auto scene = MainGameScene::createScene();

  director->runWithScene(scene);

  return true;
}

void GameDelegate::applicationDidEnterBackground() {
  Director::getInstance()->stopAnimation();

#if USE_AUDIO_ENGINE
  AudioEngine::pauseAll();
#endif
}

void GameDelegate::applicationWillEnterForeground() {
  Director::getInstance()->startAnimation();

#if USE_AUDIO_ENGINE
  AudioEngine::resumeAll();
#endif
}
