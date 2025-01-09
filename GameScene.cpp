#include "GameScene.h"

GameScene::~GameScene()
{
    delete player;
    delete gameManager;
}

cocos2d::Scene* GameScene::createScene() {
    return GameScene::create();
}

bool GameScene::init() {
    if (!Scene::init()) return false;

    player = new Player(this);
    gameManager = new GameManager();

    schedule(CC_SCHEDULE_SELECTOR(GameScene::spawnElement), 2.0f);
    scheduleUpdate();

    return true;
}

void GameScene::spawnElement(float dt) {
    gameManager->spawnElement();
}

void GameScene::update(float dt) {
    gameManager->update(dt);
    gameManager->handlePlayerCollision(player);

    if (gameManager->isGameOver()) {
        endGame();
    }
}

void GameScene::endGame() {
    auto label = cocos2d::Label::createWithSystemFont("Game Over", "Arial", 36);
    label->setPosition(cocos2d::Vec2(400, 300));
    this->addChild(label);

    this->runAction(cocos2d::Sequence::create(
        cocos2d::DelayTime::create(3.0f),
        cocos2d::CallFunc::create([]() {
            cocos2d::Director::getInstance()->replaceScene(GameScene::createScene());
        }),
        nullptr
    ));
}