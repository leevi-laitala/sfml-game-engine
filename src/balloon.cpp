#include "balloon.hpp"

Balloon::Balloon(Scene* hostScene, sf::Texture* tex, const sf::Vector2f& pos)
    : Element::Element(hostScene, tex, pos)
{
    std::cout << "Balloon created" << std::endl;

    m_spr.setOrigin(m_spr.getTexture()->getSize().x / 2.f, 
                    m_spr.getTexture()->getSize().y / 2.f);

    reset(false);
}

Balloon::~Balloon()
{
    std::cout << "Balloon destroyed" << std::endl;
}

void Balloon::update(const float& deltaTime)
{
    if (m_spr.getPosition().y < (0 - m_spr.getTexture()->getSize().y / 2.f))
        reset(true);

    move(sf::Vector2f(0.f, -512.f * deltaTime), true);
}

void Balloon::reset(const bool& popsfx)
{
    if (popsfx)
        m_hostScene->getEngine()->getSoundManager()->playSound(System::Resources::Sounds::BalloonPop);

    std::cout << m_spr.getTexture()->getSize().y << std::endl;
    std::cout << m_spr.getPosition().x << ", " << m_spr.getPosition().y << std::endl;

    m_spr.setPosition(rand() % m_hostScene->getEngine()->getWindow()->getSize().x,
                      m_hostScene->getEngine()->getWindow()->getSize().y + m_spr.getTexture()->getSize().y);

    m_spr.setColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
}

