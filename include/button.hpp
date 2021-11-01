#pragma once

#include "sprite.hpp"
#include "scene.hpp"
#include "event-manager.hpp"

#include <iostream>
#include <string>
#include <functional>

class Button : public Sprite
{
private:
    bool m_hovering = false;
    bool m_wasHovering = false;
    bool m_pressed  = false;
    uint8_t alphaOnHover = 200;

    std::function<void()> pressFunction;
    std::function<void()> enterFunction;
    std::function<void()> leaveFunction;

    std::string m_buttonText;
    sf::Font* m_fnt;
    sf::Text m_text;

    EventManager m_eventManager;

public:
    Button(Scene* hostScene, sf::Texture* tex, const sf::Text& text, const std::function<void()>& pressfunc, const std::function<void()>& enterfunc, const std::function<void()>& leavefunc, const sf::Vector2f& pos = sf::Vector2f(0.f, 0.f));
    ~Button();
    
    void update(const float& deltaTime) override;
    void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;
};
