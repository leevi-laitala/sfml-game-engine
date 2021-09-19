#include "button.hpp"

Button::Button(Scene* hostScene, sf::Texture* tex, sf::Font* fnt, const std::string& str, std::function<void(const sf::Event& event)> callback, const sf::Vector2f& pos)
    : Element::Element(hostScene, tex, pos)
{
    m_hostScene = hostScene;
    
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

    //m_hostScene->getEngine()->getEventManager()->addMouseButtonCallback(sf::Mouse::Button::Left, [&](const sf::Event&){
    //    if (m_hovering) { m_hostScene->getEngine()->switchScene(System::Scenes::Mainmenu); }
    //});
    
    m_hostScene->getEngine()->getEventManager()->addMouseButtonCallback(sf::Mouse::Button::Left, callback);
}

Button::~Button() {};

void Button::update(const float& deltaTime)
{ 
    m_hovering = m_spr.getGlobalBounds().contains(sf::Mouse::getPosition(*(m_hostScene->getEngine()->getWindow())).x, sf::Mouse::getPosition(*(m_hostScene->getEngine()->getWindow())).y);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_spr);
    target.draw(m_text);
}
