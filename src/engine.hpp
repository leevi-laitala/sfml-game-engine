#pragma once

#include "scene.hpp"
#include "element.hpp"
#include "balloon.hpp"
#include "resource-manager.hpp"
#include "enum-resources.hpp"

#include <unordered_map>

class Engine
{
protected:
    sf::RenderWindow* window;
    std::unordered_map<System::Scenes, Scene*> m_mapScenes;
    System::Scenes activeScene;

public:
    Engine();
    ~Engine();

    // Running a game
    virtual void initWindow(uint32_t width, uint32_t height, const std::string& title);
    virtual void run() = 0;
    virtual void end() = 0;

    // Scene management
    void createScene(System::Scenes scene);
    void switchScene(System::Scenes scene);
    void addElement(System::Scenes scene, Element* element);
    void renderScene();
    Scene* getScene(System::Scenes scene);
};
