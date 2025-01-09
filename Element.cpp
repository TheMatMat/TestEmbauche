#include "Element.h"

Element::Element(cocos2d::Scene* scene) 
{
    sprite = cocos2d::Sprite::create("element.png");
    float x = cocos2d::random(50.0f, 750.0f);
    float y = cocos2d::random(50.0f, 550.0f);
    sprite->setPosition(cocos2d::Vec2(x, y));
    scene->addChild(sprite);

    value = cocos2d::random(10.0f, 50.0f);
}

void Element::updateValue(float dt) 
{
    value += dt * 10;
}

float Element::getValue() const 
{
    return value;
}

cocos2d::Sprite* Element::getSprite() const 
{
    return sprite;
}