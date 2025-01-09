#include "Player.h"

Player::Player(cocos2d::Scene* scene) 
{
    sprite = cocos2d::Sprite::create("grossini.png");
    sprite->setPosition(cocos2d::Vec2(400, 300));
    scene->addChild(sprite);
}

void Player::move(cocos2d::EventKeyboard::KeyCode keyCode) 
{
    switch (keyCode) {
    case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
    case cocos2d::EventKeyboard::KeyCode::KEY_Q:
        sprite->setPositionX(sprite->getPositionX() - 10);
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
    case cocos2d::EventKeyboard::KeyCode::KEY_D:
        sprite->setPositionX(sprite->getPositionX() + 10);
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
    case cocos2d::EventKeyboard::KeyCode::KEY_Z:
        sprite->setPositionY(sprite->getPositionY() + 10);
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
    case cocos2d::EventKeyboard::KeyCode::KEY_S:
        sprite->setPositionY(sprite->getPositionY() - 10);
        break;
    default:
        break;
    }
}

cocos2d::Sprite* Player::getSprite() const 
{
    return sprite;
}