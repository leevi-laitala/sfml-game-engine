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

void Balloon::update()
{
    apparentPos = sf::Mouse::getPosition(*m_hostWindow);

    if (sf::Mouse::getPosition(*m_hostWindow).x < m_spr.getTexture()->getSize().x / 2.f)
        apparentPos.x = m_spr.getTexture()->getSize().x / 2.f;

    if (sf::Mouse::getPosition(*m_hostWindow).x > m_hostWindow->getSize().x - m_spr.getTexture()->getSize().x / 2.f)
        apparentPos.x = m_hostWindow->getSize().x - m_spr.getTexture()->getSize().x / 2.f;

    if (sf::Mouse::getPosition(*m_hostWindow).y < m_spr.getTexture()->getSize().y / 2.f)
        apparentPos.y = m_spr.getTexture()->getSize().y / 2.f;

    if (sf::Mouse::getPosition(*m_hostWindow).y > m_hostWindow->getSize().y - m_spr.getTexture()->getSize().y / 2.f)
        apparentPos.y = m_hostWindow->getSize().y - m_spr.getTexture()->getSize().y / 2.f;
    
    m_spr.setPosition(sf::Vector2f(apparentPos.x, apparentPos.y));

    //m_spr.setPosition(sf::Vector2f(sf::Mouse::getPosition(*m_hostWindow).x,
    //                               sf::Mouse::getPosition(*m_hostWindow).y));
}

