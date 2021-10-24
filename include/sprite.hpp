#pragma once

#include "element.hpp"

class Scene;

class Sprite : public Element
{
protected:
    sf::Sprite m_spr;
    sf::Texture* m_tex;

public:
    Sprite(Scene* hostScene, sf::Texture* tex, const sf::Vector2f& pos = sf::Vector2f(0.f, 0.f));
    ~Sprite();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;

    virtual void move(const sf::Vector2f& amount, const bool& relative);
};
