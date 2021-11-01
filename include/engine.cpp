#include "engine.hpp"

Engine::Engine()
    : window(sf::VideoMode(1280, 720), "SFML")
    , eventManager(&window)
{
    m_backgroundColor = sf::Color::Black;
}

Engine::~Engine()
{
    // Destroy scenes
    for (auto it = m_mapScenes.begin(); it != m_mapScenes.end(); ++it)
        delete it->second;
}

void Engine::run()
{
    m_deltaTimeClock.restart();

    create();
    
    // Main game loop
    while (window.isOpen())
    {
        // Update deltaTime
        m_deltaTimeClass = m_deltaTimeClock.restart();
        deltaTime = m_deltaTimeClass.asSeconds();

        window.clear(m_backgroundColor);
        
        // Update eventManager
        eventManager.processEvents();

        // Call main game logic function
        step();

        window.display();
    }

    std::cout << "[Engine     ] Calling end" << std::endl;

    // Deconstruct game
    end();

    std::cout << "[Engine     ] End ran" << std::endl;
}

// Getters
//
sf::RenderWindow* Engine::getWindow()
{
    return &window;
}

EventManager* Engine::getEventManager()
{
    return &eventManager;
}

SoundManager* Engine::getSoundManager()
{
    return &soundManager;
}

// Scene management

void Engine::createScene(System::Scenes scene)
{
    // Chech if scene id exists already, if not, create new scene in the heap, and save to m_mapScenes
    if (m_mapScenes.find(scene) == m_mapScenes.end())
    {
        Scene* newScene = new Scene(const_cast<Engine*>(this));
        m_mapScenes.insert(std::pair<System::Scenes, Scene*>(scene, newScene));
    }
}

// Change current active scene
void Engine::switchScene(System::Scenes scene)
{
    activeScene = scene;
}

// Add element to given scene
void Engine::addElement(System::Scenes scene, Element* element)
{
    if (m_mapScenes.find(scene) != m_mapScenes.end())
        m_mapScenes[scene]->addElement(element);
}

// Render all elements in given scene
void Engine::renderScene(System::Scenes scene)
{
    if (m_mapScenes.find(scene) != m_mapScenes.end()) 
        m_mapScenes[scene]->render();
}

// Update all elements in given scene
void Engine::updateScene(System::Scenes scene)
{
    if (m_mapScenes.find(scene) != m_mapScenes.end())
        m_mapScenes[scene]->updateElements(deltaTime);
}

// Return pointer of given scene id
Scene* Engine::getScene(System::Scenes scene)
{
    if (m_mapScenes.find(scene) != m_mapScenes.end())
        return m_mapScenes[scene];

    return nullptr;
}

// Return pointer to current active scene
Scene* Engine::getActiveScene()
{
    return getScene(activeScene);
}

