#pragma once

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "cocos2d.h"
#include "Player.h"
#include "Element.h"
#include <vector>

class GameManager {
public:
    GameManager();
    ~GameManager();

    void update(float dt);
    void spawnElement();
    void handlePlayerCollision(Player* player);
    bool isGameOver() const;

    int getScore() const;
    int getHighScore() const;
    int getCriticalFailures() const;

private:
    std::vector<Element*> elements;
    int score;
    int highScore;
    int criticalFailures;

    void loadHighScore();
    void saveHighScore();
};

#endif // GAMEMANAGER_H

