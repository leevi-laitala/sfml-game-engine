#include "balloon.hpp"

Balloon::Balloon(Scene* hostScene, sf::Texture* tex, const sf::Vector2f& pos)
    : Element::Element(hostScene, tex, pos)
{
    std::cout << "Balloon created" << std::endl;

    m_spr.setOrigin(m_spr.getTexture()->getSize().x / 2.f, 
                    m_spr.getTexture()->getSize().y / 2.f);
}

Balloon::~Balloon()
{
    std::cout << "Balloon destroyed" << std::endl;
}

void Balloon::update(const float& deltaTime)
{
    //if (m_spr.getPosition().x < sf::Mouse::getPosition(*m_hostWindow).x)
    //    m_spr.setPosition(m_spr.getPosition().x + 32.f * deltaTime, m_spr.getPosition().y);

    //if (m_spr.getPosition().x > sf::Mouse::getPosition(*m_hostWindow).x)
    //    m_spr.setPosition(m_spr.getPosition().x - 32.f * deltaTime, m_spr.getPosition().y);

    //if (m_spr.getPosition().y < sf::Mouse::getPosition(*m_hostWindow).y)
    //    m_spr.setPosition(m_spr.getPosition().x, m_spr.getPosition().y + 32.f * deltaTime);

    //if (m_spr.getPosition().y > sf::Mouse::getPosition(*m_hostWindow).y)
    //    m_spr.setPosition(m_spr.getPosition().x, m_spr.getPosition().y - 32.f * deltaTime);
    //
    if (m_spr.getPosition().x < sf::Mouse::getPosition(*m_hostWindow).x)
        move(sf::Vector2f(32.f * deltaTime, 0.f), true);

    if (m_spr.getPosition().x > sf::Mouse::getPosition(*m_hostWindow).x)
        move(sf::Vector2f(-32.f * deltaTime, 0.f), true);

    if (m_spr.getPosition().y < sf::Mouse::getPosition(*m_hostWindow).y)
        move(sf::Vector2f(0.f, 32.f * deltaTime), true);

    if (m_spr.getPosition().y > sf::Mouse::getPosition(*m_hostWindow).y)
        move(sf::Vector2f(0.f, -32.f * deltaTime), true);
    //if (m_spr.getPosition().x < *m_hostWindow.get)
    //m_spr.setPosition(sf::Vector2f(m_spr.getPosition().x + 16.f, 0.f));

    //m_spr.setPosition(sf::Vector2f(sf::Mouse::getPosition(*m_hostWindow).x,
    //                               sf::Mouse::getPosition(*m_hostWindow).y));
}

