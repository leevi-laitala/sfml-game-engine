#include "scene.hpp"

Scene::Scene(sf::RenderWindow* hostWindow)
{
    m_hostWindow = hostWindow;
}

Scene::~Scene()
{
    for (std::vector<Element*>::iterator it = m_vecElements.begin(); it != m_vecElements.end(); ++it)
        delete *it;
}

void Scene::addElement(Element* element)
{
    m_vecElements.push_back(element);
}

void Scene::updateElements(const float& deltaTime)
{
    for (std::vector<Element*>::iterator it = m_vecElements.begin(); it != m_vecElements.end(); ++it)
        (*it)->update(deltaTime);
}

void Scene::render()
{
    for (std::vector<Element*>::iterator it = m_vecElements.begin(); it != m_vecElements.end(); ++it)
        (*it)->draw(*m_hostWindow);
}

Scene* Scene::getScene()
{
    return const_cast<Scene*>(this);
}

sf::RenderWindow* Scene::getWindow()
{
    return m_hostWindow;
}

