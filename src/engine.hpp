#pragma once

#include "scene.hpp"
#include "element.hpp"
#include "balloon.hpp"
#include "resource-manager.hpp"
#include "enum-resources.hpp"

class Engine
{
protected:
    sf::RenderWindow* window;

public:
    Engine();
    ~Engine();

    virtual void initWindow(uint32_t width, uint32_t height, const std::string& title);
    virtual void run() = 0;
    virtual void end() = 0;
};
