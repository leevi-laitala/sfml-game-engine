#include "element.hpp"
#include "scene.hpp"

Element::Element(Scene* hostScene, const sf::Vector2f& pos)
{
    std::cout << "[Element    ] Element created" << std::endl;

    m_hostScene = hostScene;
}

Element::~Element()
{
    std::cout << "[Element    ] Element destroyed" << std::endl;
}

