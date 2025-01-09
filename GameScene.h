#pragma once

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "cocos2d.h"
#include "GameManager.h"
#include "Player.h"

class GameScene : public cocos2d::Scene {
public:
    ~GameScene();

    static cocos2d::Scene* createScene();
    virtual bool init() override;
    void update(float dt) override;

private:
    Player* player;
    GameManager* gameManager;

    void spawnElement(float dt);
    void endGame();
};

#endif // GAMESCENE_H

