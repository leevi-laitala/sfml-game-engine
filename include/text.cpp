#include "text.hpp"

Text::Text(Scene* hostScene, const sf::Text& text, const sf::Vector2f& pos)
    : Element::Element(hostScene, pos)
{
    m_text = text;
    m_text.setPosition(pos);
}

Text::~Text() {};

void Text::update(const float& deltaTime)
{
}

void Text::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_text);
}

