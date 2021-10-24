#pragma once

#include "../include/sprite.hpp"
#include "../include/scene.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>

class Scene;

class Balloon : public Sprite
{
public:
    Balloon(Scene* hostScene, sf::Texture* tex, const sf::Vector2f& pos = sf::Vector2f(0.f, 0.f));
    ~Balloon();

    void update(const float& deltaTime) override;
    void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;
    
    void reset(const bool& popsfx);
};
