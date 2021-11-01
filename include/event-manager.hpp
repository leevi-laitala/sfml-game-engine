#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <iostream>
#include <functional>
#include <vector>

template<typename Type> // Type is the button type, it can be sf::Keyboard::Key or sf::Mouse::Button
class ButtonManager // Handles keyboard and mouse events. Event manager catches if some button was pressed, not which key. With button manager you can assign callbacks to specific buttons.
{
private:
    std::unordered_map<Type, std::vector<std::function<void(const sf::Event& event)>>> m_mapButtons;
    std::function<Type(const sf::Event& event)> buttonEvent;

public:
    ButtonManager(std::function<Type(const sf::Event& event)> buttonEvent)
    {
        this->buttonEvent = buttonEvent;
    }
    
    // Adds callback to specific button
    void addButtonCallback(Type id, std::function<void(const sf::Event& event)> callback)
    {
        // Check if there is callback already for given button
        auto it = m_mapButtons.find(id);
        if (it == m_mapButtons.end()) 
        { // If not, create new vector and push the callback there
            std::vector<std::function<void(const sf::Event& event)>> eventVec;
            eventVec.push_back(callback);
            m_mapButtons.insert(std::pair<Type, std::vector<std::function<void(const sf::Event& event)>>>(id, eventVec));
        } else
        {
            // If yes, append the callback to existing vector
            m_mapButtons[id].push_back(callback);
        }
    }

    // Get the vector corresponding button id, and loop through it's callbacks
    void processEvents(const sf::Event& event)
    {
        Type buttonType = buttonEvent(event);

        auto it = m_mapButtons.find(buttonType);
        if (it != m_mapButtons.end())
            for (auto i : it->second)
                i(event);
    }
};





// Main manager, contains button managers for both keyboard and mouse
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

    ~EventManager() {}
    
    // Add general event callback
    void addCallback(const sf::Event::EventType& eventType, std::function<void(const sf::Event& event)> callback)
    {
        m_mapEventCallback.insert(std::pair<sf::Event::EventType, std::function<void(const sf::Event& event)>>(eventType, callback));
    }

    // Add callback for mouse button
    void addMouseButtonCallback(sf::Mouse::Button button, std::function<void(const sf::Event& event)> callback)
    {
        m_mouseButtonManager.addButtonCallback(button, callback);
    }
    
    // Add callback for keyboard key
    void addKeyboardKeyCallback(sf::Keyboard::Key key, std::function<void(const sf::Event& event)> callback)
    {
        m_keyboardKeyManager.addButtonCallback(key, callback);
    }
    
    // Execute callback for given event type
    void executeCallback(const sf::Event& event)
    {
        auto it = m_mapEventCallback.find(event.type);
        if (it != m_mapEventCallback.end())
            (it->second)(event);
    }
    
    // Handle all events the windows have catched
    void processEvents()
    {
        sf::Event event;
        while(m_window->pollEvent(event))
            executeCallback(event);
    }
};

