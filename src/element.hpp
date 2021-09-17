#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Scene;

class Element : public sf::Drawable
{
protected:
    sf::Texture* m_tex;
    sf::Sprite m_spr;

    Scene* m_hostScene;
    sf::RenderWindow* m_hostWindow;

public:
    Element(Scene* hostScene, sf::Texture* tex, const sf::Vector2f& pos = sf::Vector2f(0.f, 0.f));
    ~Element();

    virtual void update(const float& deltaTime) = 0;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;

    virtual void move(const sf::Vector2f& amount, const bool& relative);
};
