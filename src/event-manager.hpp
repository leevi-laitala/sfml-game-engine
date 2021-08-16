#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <iostream>
#include <functional>

template<typename Type>
class ButtonManager // Handles Keyboard and mouse buttons
{
private:
    std::unordered_map<Type, std::function<void(const sf::Event& event)>> m_mapButtons;
    std::function<Type(const sf::Event& event)> getButtonEvent;

public:
    ButtonManager(std::function<Type(const sf::Event& event)> getButtonEvent)
    {
        this->getButtonEvent = getButtonEvent;
    }

    void addButtonCallback(Type id, std::function<void(const sf::Event& event)> callback)
    {
        m_mapButtons.insert(std::pair<Type, std::function<void(const sf::Event& event)>>(id, callback));
    }

    void processEvents(const sf::Event& event)
    {
        Type buttonEvent = getButtonEvent(event);
        auto it = m_mapButtons.find(buttonEvent);
        if (it != m_mapButtons.end())
            (it->second)(event);
    }
};






class EventManager
{
private:
    sf::Window* m_window;
    std::unordered_map<sf::Event::EventType, std::function<void(const sf::Event& event)>> m_mapEventCallback;
    ButtonManager<sf::Mouse::Button> m_mouseButtonManager;
    ButtonManager<sf::Keyboard::Key> m_keyboardKeyManager;

public:
    EventManager(sf::Window* window)
        : m_mouseButtonManager([](const sf::Event& event){ return event.mouseButton.button; })
        , m_keyboardKeyManager([](const sf::Event& event){ return event.key.code; })
    {
        m_window = window;
        addCallback(sf::Event::EventType::MouseButtonPressed, [&](const sf::Event& event){ m_mouseButtonManager.processEvents(event); });
        addCallback(sf::Event::EventType::KeyPressed,         [&](const sf::Event& event){ m_keyboardKeyManager.processEvents(event); });
    }

    ~EventManager()
    {
    }

    void addCallback(const sf::Event::EventType& eventType, std::function<void(const sf::Event& event)> callback)
    {
        m_mapEventCallback.insert(std::pair<sf::Event::EventType, std::function<void(const sf::Event& event)>>(eventType, callback));
    }

    void addMouseButtonCallback(sf::Mouse::Button button, std::function<void(const sf::Event& event)> callback)
    {
        m_mouseButtonManager.addButtonCallback(button, callback);
    }
    
    void addKeyboardKeyCallback(sf::Keyboard::Key key, std::function<void(const sf::Event& event)> callback)
    {
        m_keyboardKeyManager.addButtonCallback(key, callback);
    }
    
    void executeCallback(const sf::Event& event)
    {
        auto it = m_mapEventCallback.find(event.type);
        if (it != m_mapEventCallback.end()) (it->second)(event);
    }
     
    void processEvents()
    {
        sf::Event event;
        while(m_window->pollEvent(event))
            executeCallback(event);
    }
};

