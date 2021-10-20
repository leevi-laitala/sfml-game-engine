#pragma once

#include "element.hpp"
#include "engine.hpp"

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

class EventManager;
class Engine;

class Scene
{
private:
    std::vector<Element*> m_vecElements;
    Engine* engine;

public:
    Scene(Engine* engine);
    ~Scene();

    void addElement(Element* element);

    void updateElements(const float& deltaTime);
    void render();

    Scene* getScene();
    Engine* getEngine();
};
