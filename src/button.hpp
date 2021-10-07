#include "scene.hpp"
#include "element.hpp"
#include "event-manager.hpp"

#include <iostream>
#include <string>
#include <functional>

class Scene;

class Button : public Element
{
private:
    bool m_hovering = false;
    bool m_pressed  = false;
    uint8_t alphaOnHover = 200;

    std::function<void()> buttonFunction;

    std::string m_buttonText;
    sf::Font* m_fnt;
    sf::Text m_text;

    EventManager m_eventManager;

public:
    //Button(Scene* hostScene, sf::Texture* tex, sf::Font* fnt, const std::string& str, std::function<void(const sf::Event& event)> callback, const sf::Vector2f& pos = sf::Vector2f(0.f, 0.f));
    Button(Scene* hostScene, sf::Texture* tex, sf::Font* fnt, const std::string& str, const std::function<void()>& func, const sf::Vector2f& pos = sf::Vector2f(0.f, 0.f));
    ~Button();
    
    void update(const float& deltaTime) override;

    void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;
};
