#include "GameManager.h"

GameManager::GameManager() 
    : score(0), criticalFailures(0) 
{
    loadHighScore();
}

GameManager::~GameManager() 
{
    for (Element* element : elements) {
        delete element;
    }
    saveHighScore();
}

void GameManager::update(float dt) 
{
    for (auto it = elements.begin(); it != elements.end(); ) {
        Element* element = *it;
        element->updateValue(dt);

        if (element->getValue() >= 100) {
            criticalFailures++;
            delete element;
            it = elements.erase(it);
        }
        else {
            ++it;
        }
    }
}

void GameManager::spawnElement() 
{
    elements.push_back(new Element(nullptr)); // Ajoute des éléments à une position aléatoire
}

void GameManager::handlePlayerCollision(Player* player) 
{
    for (auto it = elements.begin(); it != elements.end(); ) {
        Element* element = *it;
        if (player->getSprite()->getBoundingBox().intersectsRect(element->getSprite()->getBoundingBox())) {
            score += element->getValue();
            delete element;
            it = elements.erase(it);
        }
        else {
            ++it;
        }
    }
}

bool GameManager::isGameOver() const 
{
    return criticalFailures >= 3;
}

int GameManager::getScore() const 
{
    return score;
}

int GameManager::getHighScore() const 
{
    return highScore;
}

int GameManager::getCriticalFailures() const 
{
    return criticalFailures;
}

void GameManager::loadHighScore() 
{
    auto userDefaults = cocos2d::UserDefault::getInstance();
    highScore = userDefaults->getIntegerForKey("HIGH_SCORE", 0);
}

void GameManager::saveHighScore() 
{
    if (score > highScore) {
        auto userDefaults = cocos2d::UserDefault::getInstance();
        userDefaults->setIntegerForKey("HIGH_SCORE", score);
        userDefaults->flush();
    }
}