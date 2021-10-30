#include "balloon.hpp"

Balloon::Balloon(Scene* hostScene, sf::Texture* tex, const sf::Vector2f& pos)
    : Sprite::Sprite(hostScene, tex, pos)
{
    m_type = System::Elements::Balloon;
    m_depth = 13;

    m_spr.setOrigin(m_spr.getTexture()->getSize().x / 2.f, 
                    m_spr.getTexture()->getSize().y / 2.f);

    reset(false);
}

Balloon::~Balloon()
{
}

void Balloon::update(const float& deltaTime)
{
    if (m_spr.getPosition().y < (0 - m_spr.getTexture()->getSize().y / 2.f))
        reset(false);

    move(sf::Vector2f(0.f, -512.f * deltaTime), true);
}

void Balloon::reset(const bool& popsfx)
{
    if (popsfx)
        m_hostScene->getEngine()->getSoundManager()->playSound(System::Resources::Sounds::BalloonPop);

    m_spr.setPosition(rand() % m_hostScene->getEngine()->getWindow()->getSize().x,
                      m_hostScene->getEngine()->getWindow()->getSize().y + m_spr.getTexture()->getSize().y);

    m_spr.setColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
}

void Balloon::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_spr);
}

