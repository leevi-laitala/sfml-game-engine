#include "sprite.hpp"

Sprite::Sprite(Scene* hostScene, sf::Texture* tex, const sf::Vector2f& pos)
    : Element::Element(hostScene, pos)
{
    m_tex = tex;
    m_spr.setTexture(*m_tex);
    m_spr.setPosition(pos);
}

Sprite::~Sprite() {}

void Sprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_spr);
}

void Sprite::move(const sf::Vector2f& amount, const bool& relative)
{
    if (relative)
    {
        m_spr.setPosition(sf::Vector2f(m_spr.getPosition().x + amount.x,
                                       m_spr.getPosition().y + amount.y));
    } else
        m_spr.setPosition(amount);
}

