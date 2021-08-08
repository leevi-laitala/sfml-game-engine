#pragma once

#include "element.hpp"
#include "balloon.hpp"

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

class Scene
{
private:
    sf::RenderWindow* m_hostWindow;
    std::vector<Element*> m_vecElements;

public:
    Scene(sf::RenderWindow* hostWindow);
    ~Scene();

    void addElement(Element* element);

    void updateElements();
    void render();

    Scene* getScene();
    sf::RenderWindow* getWindow();
};
