#include "engine.hpp"

Engine::Engine()
{
}

Engine::~Engine()
{
    for (auto it = m_mapScenes.begin(); it != m_mapScenes.end(); ++it)
        delete it->second;

    delete window;
}

void Engine::initWindow(uint32_t width, uint32_t height, const std::string& title)
{
    sf::RenderWindow* win = new sf::RenderWindow(sf::VideoMode(width, height, 32), title);
    this->window = win;

    window->setFramerateLimit(60);
}

void Engine::createScene(System::Scenes scene)
{
    if (m_mapScenes.find(scene) == m_mapScenes.end())
    {
        Scene* newScene = new Scene(window);
        m_mapScenes.insert(std::pair<System::Scenes, Scene*>(scene, newScene));
    }
}

void Engine::switchScene(System::Scenes scene)
{
    activeScene = scene;
}

void Engine::addElement(System::Scenes scene, Element* element)
{
    if (m_mapScenes.find(scene) != m_mapScenes.end()) // Check if scene exists
    {
        m_mapScenes[scene]->addElement(element);
    }
}

void Engine::renderScene()
{
    if (m_mapScenes.find(activeScene) != m_mapScenes.end()) // Check if scene exists
    {
        m_mapScenes[activeScene]->updateElements();
        m_mapScenes[activeScene]->render();
    }
}

Scene* Engine::getScene(System::Scenes scene)
{
    if (m_mapScenes.find(scene) != m_mapScenes.end()) // Check if scene exists
        return m_mapScenes[scene];

    return nullptr;
}
