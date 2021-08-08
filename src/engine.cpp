#include "engine.hpp"

Engine::Engine()
{
}

Engine::~Engine()
{
    delete window;
}

void Engine::initWindow(uint32_t width, uint32_t height, const std::string& title)
{
    sf::RenderWindow* win = new sf::RenderWindow(sf::VideoMode(width, height, 32), title);
    this->window = win;

    window->setFramerateLimit(30);
}
