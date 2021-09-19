#include "scene.hpp"

Scene::Scene(Engine* engine)
{
    this->engine = engine;
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
        (*it)->draw(*(engine->getWindow()));
}

Scene* Scene::getScene()
{
    return const_cast<Scene*>(this);
}

Engine* Scene::getEngine()
{
    return engine;
}
