#pragma once

#include "enum-resources.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

// Forward declarations
namespace System { enum class Elements; }
class Scene;

class Element : public sf::Drawable
{
protected:
    Scene* m_hostScene;
    System::Elements m_type;
    uint8_t m_depth;

public:
    Element(Scene* hostScene, const sf::Vector2f& pos = sf::Vector2f(0.f, 0.f));
    ~Element();

    virtual void update(const float& deltaTime) = 0;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const = 0;

    System::Elements getType() const;
    uint8_t getDepth() const;
};
