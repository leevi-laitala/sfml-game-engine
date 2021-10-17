#pragma once

#include "scene.hpp"
#include "element.hpp"
#include "resource-manager.hpp"
#include "enum-resources.hpp"
#include "event-manager.hpp"
#include "sound-manager.hpp"

#include <unordered_map>
#include <SFML/Audio.hpp>

class Engine
{
protected:
    sf::RenderWindow window;

    std::unordered_map<System::Scenes, Scene*> m_mapScenes;
    System::Scenes activeScene;

    EventManager eventManager;
    SoundManager soundManager;

    sf::Clock m_deltaTimeClock;
    sf::Time m_deltaTimeClass;
    float deltaTime;

public:
    Engine();
    ~Engine();

    // Running a game
    virtual void run();

    virtual void create() = 0;
    virtual void step() = 0;
    virtual void end() = 0;
    
    // Access to members
    sf::RenderWindow* getWindow();
    EventManager* getEventManager();
    SoundManager* getSoundManager();

    // Scene management
    void createScene(System::Scenes scene);
    void switchScene(System::Scenes scene);
    void addElement(System::Scenes scene, Element* element);
    void renderScene(System::Scenes scene);
    void updateScene(System::Scenes scene);
    Scene* getScene(System::Scenes scene);
    Scene* getActiveScene();
};
