#include "scene.hpp"

Scene::Scene(Engine* engine)
{
    this->engine = engine;
    m_window = this->engine->getWindow();
}

Scene::~Scene()
{
    for (auto it : m_vecElements)
        delete it;
}

void Scene::addElement(Element* element)
{
    m_vecElements.push_back(element);

    System::Elements elementType = element->getType();
    uint8_t elementDepth = element->getDepth();

    auto it = m_mapElements.find(elementType);
    if (it == m_mapElements.end())
    {
        std::vector<ElementInstance> elementVec;
        elementVec.push_back(ElementInstance(element, elementDepth));

        m_mapElements.insert(std::pair<System::Elements, std::vector<ElementInstance>>(elementType, elementVec));
    } else
    {
        m_mapElements[elementType].push_back(ElementInstance(element, elementDepth));
    }

    rebuildRenderingOrder();

    std::cout << "[Renderorder] Size: " << m_mapElementRenderOrder.size() << std::endl;
}

void Scene::updateElements(const float& deltaTime)
{
    for (std::vector<Element*>::iterator it = m_vecElements.begin(); it != m_vecElements.end(); ++it)
        (*it)->update(deltaTime);
}

void Scene::render()
{
    for (auto it_map = m_mapElementRenderOrder.begin(); it_map != m_mapElementRenderOrder.end(); ++it_map)
        for (auto it_vec = it_map->second.begin(); it_vec != it_map->second.end(); ++it_vec)
            (*it_vec)->draw(*m_window);
}

void Scene::rebuildRenderingOrder()
{
    m_mapElementRenderOrder.clear();

    for (auto it_map = m_mapElements.begin(); it_map != m_mapElements.end(); ++it_map)
    {
        for (auto it_vec = it_map->second.begin(); it_vec != it_map->second.end(); ++it_vec)
        {
            auto it_ren = m_mapElementRenderOrder.find(it_vec->depth);
            if (it_ren == m_mapElementRenderOrder.end())
            {
                std::vector<Element*> elementVec;
                elementVec.push_back(it_vec->element);
                m_mapElementRenderOrder.insert(std::pair<uint8_t, std::vector<Element*>>(it_vec->depth, elementVec));
            } else
            {
                // TODO: Use iterator 
                m_mapElementRenderOrder[it_vec->depth].push_back(it_vec->element);
            }
        }
    }
}

Scene* Scene::getScene()
{
    return const_cast<Scene*>(this);
}

Engine* Scene::getEngine()
{
    return engine;
}
