#include "engine.hpp"

Engine::Engine()
    : window(sf::VideoMode(1920, 1080), "SFML")
    , eventManager(&window)
{
    //window.setFramerateLimit(60);
    eventManager.addCallback(sf::Event::Closed, [&](const sf::Event&){ window.close(); });

    eventManager.addCallback(sf::Event::Resized, [&](const sf::Event& event){ 
        sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
        window.setView(sf::View(visibleArea));
    });
}

Engine::~Engine()
{
    for (auto it = m_mapScenes.begin(); it != m_mapScenes.end(); ++it)
        delete it->second;
}

void Engine::run()
{
    m_deltaTimeClock.restart();

    create();

    while (window.isOpen())
    {
        m_deltaTimeClass = m_deltaTimeClock.restart();
        deltaTime = m_deltaTimeClass.asSeconds();

        window.clear();
        
        eventManager.processEvents();

        step();

        window.display();
    }

    std::cout << "Calling end" << std::endl;

    end();

    std::cout << "End ran" << std::endl;
}


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

void Engine::createScene(System::Scenes scene)
{
    if (m_mapScenes.find(scene) == m_mapScenes.end())
    {
        Scene* newScene = new Scene(const_cast<Engine*>(this));
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

void Engine::renderScene(System::Scenes scene)
{
    if (m_mapScenes.find(scene) != m_mapScenes.end()) // Check if scene exists
        m_mapScenes[scene]->render();
}

void Engine::updateScene(System::Scenes scene)
{
    if (m_mapScenes.find(scene) != m_mapScenes.end()) // Check if scene exists
        m_mapScenes[scene]->updateElements(deltaTime);
}

Scene* Engine::getScene(System::Scenes scene)
{
    if (m_mapScenes.find(scene) != m_mapScenes.end()) // Check if scene exists
        return m_mapScenes[scene];

    return nullptr;
}

Scene* Engine::getActiveScene()
{
    return getScene(activeScene);
}

