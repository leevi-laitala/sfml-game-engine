#pragma once

#include "../include/element.hpp"
#include "../include/scene.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>

class Scene;

class Balloon : public Element
{
public:
    Balloon(Scene* hostScene, sf::Texture* tex, const sf::Vector2f& pos = sf::Vector2f(0.f, 0.f));
    ~Balloon();

    void update(const float& deltaTime) override;
    
    void reset(const bool& popsfx);
};
