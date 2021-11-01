#pragma once

#include "element.hpp"
#include "event-manager.hpp"
#include "enum-resources.hpp"
#include "engine.hpp"

#include <vector>
#include <unordered_map>
#include <iostream>
#include <SFML/Graphics.hpp>


// Container for Element and it's depth
// TODO: Consider using simply std::tuple, or just the element pointer, where the depth can be extracted anyways
struct ElementInstance
{
    Element* element;
    uint8_t depth;

    ElementInstance(Element* element, const uint8_t& depth)
    {
        this->element = element;
        this->depth = depth; 
    }
};

class Engine;

class Scene
{
private:
    std::vector<Element*> m_vecElements;

    std::unordered_map<System::Elements, std::vector<ElementInstance>> m_mapElements;
    std::map<uint8_t, std::vector<Element*>> m_mapElementRenderOrder;

    Engine* m_engine;
    sf::RenderWindow* m_window;

public:
    Scene(Engine* engine);
    ~Scene();

    void addElement(Element* element);

    void updateElements(const float& deltaTime);
    void render();
    void rebuildRenderingOrder();

    Scene* getScene();
    Engine* getEngine();
};
