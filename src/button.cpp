#include "button.hpp"

Button::Button(Scene* hostScene, sf::Texture* tex, sf::Font* fnt, const std::string& str, const std::function<void()>& function, const sf::Vector2f& pos)
    : Element::Element(hostScene, tex, pos), m_eventManager(hostScene->getEngine()->getWindow())
{
    m_hostScene = hostScene;
    buttonFunction = function;
    
    m_spr.setTexture(*tex);
    m_spr.setPosition(pos);

    m_text.setFont(*fnt);
    m_text.setString(str);
    m_text.setCharacterSize(m_spr.getTexture()->getSize().y * m_spr.getScale().x);

    sf::FloatRect textRect = m_text.getLocalBounds();
    m_text.setOrigin(textRect.left + textRect.width / 2.f, textRect.top + textRect.height / 2.f);

    sf::FloatRect sprRect = m_spr.getLocalBounds();
    m_text.setPosition(m_spr.getPosition().x + sprRect.width / 2.f, m_spr.getPosition().y + sprRect.height / 2.f);
    m_text.setFillColor(sf::Color::White);
}

Button::~Button() {};

void Button::update(const float& deltaTime)
{ 
    m_hovering = m_spr.getGlobalBounds().contains(sf::Mouse::getPosition(*(m_hostScene->getEngine()->getWindow())).x, sf::Mouse::getPosition(*(m_hostScene->getEngine()->getWindow())).y);
    m_pressed = m_hovering && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
    
    m_spr.setColor(sf::Color(255, 255, 255, (m_hovering) ? alphaOnHover : 255));
    
    if (m_pressed && m_hovering)
        buttonFunction();

}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_spr);
    target.draw(m_text);
}
