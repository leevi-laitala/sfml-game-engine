#include "element.hpp"
#include "scene.hpp"

Element::Element(Scene* hostScene, sf::Texture* tex, const sf::Vector2f& pos)
{
    std::cout << "Element created" << std::endl;

    m_hostScene = hostScene;
    m_tex = tex;

    m_spr.setTexture(*m_tex);
    m_spr.setPosition(pos);
    
    m_hostWindow = m_hostScene->getWindow();
}

Element::~Element()
{
    std::cout << "Element destroyed" << std::endl;
}

void Element::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_spr, states);
}

