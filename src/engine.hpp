#pragma once

#include "scene.hpp"
#include "element.hpp"
#include "balloon.hpp"
#include "resource-manager.hpp"
#include "enum-resources.hpp"
#include "event-manager.hpp"

#include <unordered_map>

class Engine
{
protected:
    sf::RenderWindow window;

    std::unordered_map<System::Scenes, Scene*> m_mapScenes;
    System::Scenes activeScene;

    EventManager eventManager;

public:
    Engine();
    ~Engine();

    // Running a game
    virtual void run();

    virtual void create() = 0;
    virtual void step() = 0;
    virtual void end() = 0;

    // Scene management
    void createScene(System::Scenes scene);
    void switchScene(System::Scenes scene);
    void addElement(System::Scenes scene, Element* element);
    void renderScene(System::Scenes scene);
    void updateScene(System::Scenes scene);
    Scene* getScene(System::Scenes scene);
};
