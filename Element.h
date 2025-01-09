#pragma once

#ifndef ELEMENT_H
#define ELEMENT_H

#include "cocos2d.h"

class Element {
public:
    Element(cocos2d::Scene* scene);
    void updateValue(float dt);
    float getValue() const;
    cocos2d::Sprite* getSprite() const;

private:
    cocos2d::Sprite* sprite;
    float value;
};

#endif // ELEMENT_H
