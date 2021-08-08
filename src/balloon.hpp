#pragma once

#include "element.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

class Scene;

class Balloon : public Element
{
public:
    Balloon(Scene* hostScene, sf::Texture* tex, const sf::Vector2f& pos = sf::Vector2f(0.f, 0.f));
    ~Balloon();

    void update() override;
};
