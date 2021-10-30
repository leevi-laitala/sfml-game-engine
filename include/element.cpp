#include "element.hpp"
#include "scene.hpp"

Element::Element(Scene* hostScene, const sf::Vector2f& pos)
{
    std::cout << "[Element    ] Element created" << std::endl;

    m_hostScene = hostScene;
    m_type = System::Elements::Default;
    m_depth = 1;
}

Element::~Element()
{
    std::cout << "[Element    ] Element destroyed" << std::endl;
}

System::Elements Element::getType() const
{
    return m_type;
}

uint8_t Element::getDepth() const
{
    return m_depth;
}

