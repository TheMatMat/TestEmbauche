#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "cocos2d.h"

class Player {
public:
    Player(cocos2d::Scene* scene);
    void move(cocos2d::EventKeyboard::KeyCode keyCode);
    cocos2d::Sprite* getSprite() const;

private:
    cocos2d::Sprite* sprite;
};

#endif // PLAYER_H

