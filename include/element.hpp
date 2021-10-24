#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Scene;

class Element : public sf::Drawable
{
protected:
    Scene* m_hostScene;

public:
    Element(Scene* hostScene, const sf::Vector2f& pos = sf::Vector2f(0.f, 0.f));
    ~Element();

    virtual void update(const float& deltaTime) = 0;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const = 0;
};
