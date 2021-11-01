#pragma once

#include "element.hpp"

class Text : public Element
{
private:
    sf::Text m_text;

public:
    Text(Scene* hostScene, const sf::Text& text, const sf::Vector2f& pos = sf::Vector2f(0.f, 0.f));
    ~Text();

    void update(const float& deltaTime) override;
    void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;
};
