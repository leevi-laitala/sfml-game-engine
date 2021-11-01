#include "scene.hpp"

Scene::Scene(Engine* engine)
{
    m_engine = engine;
    m_window = m_engine->getWindow();
}

// Destroy all elements
Scene::~Scene()
{
    for (auto it : m_vecElements)
        delete it;
}

// Add element to scene
void Scene::addElement(Element* element)
{
    m_vecElements.push_back(element);
    
    // Add element to vector within a map, with the element type as a key
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

// Loopt through all elements and call their update function
void Scene::updateElements(const float& deltaTime)
{
    for (std::vector<Element*>::iterator it = m_vecElements.begin(); it != m_vecElements.end(); ++it)
        (*it)->update(deltaTime);
}

// Loop through the render order map
void Scene::render()
{
    for (auto it_map = m_mapElementRenderOrder.begin(); it_map != m_mapElementRenderOrder.end(); ++it_map)
        for (auto it_vec = it_map->second.begin(); it_vec != it_map->second.end(); ++it_vec)
            (*it_vec)->draw(*m_window);
}

// Recreate the rendering order map
void Scene::rebuildRenderingOrder()
{
    m_mapElementRenderOrder.clear(); // Clear and reacreate
    
    // Iterate through the unordered_map which contains vectors of elements
    for (auto it_map = m_mapElements.begin(); it_map != m_mapElements.end(); ++it_map)
    {
        // Loop through the vector from the map
        for (auto it_vec = it_map->second.begin(); it_vec != it_map->second.end(); ++it_vec)
        {
            // Group all elements using the same depth in same vector and save it to the rendering order map
            auto it_ren = m_mapElementRenderOrder.find(it_vec->depth);
            if (it_ren == m_mapElementRenderOrder.end())
            {
                // Create new vector for given depth if doesn't already exist
                std::vector<Element*> elementVec;
                elementVec.push_back(it_vec->element);
                m_mapElementRenderOrder.insert(std::pair<uint8_t, std::vector<Element*>>(it_vec->depth, elementVec));
            } else
            {
                // If vector already exists for given depth, just append to it

                // TODO: Use iterator instead of refering to the depth once more
                m_mapElementRenderOrder[it_vec->depth].push_back(it_vec->element);
            }
        }
    }
}

// Return pointer to self
Scene* Scene::getScene()
{
    return const_cast<Scene*>(this);
}

// Return pointer to engine
Engine* Scene::getEngine()
{
    return m_engine;
}
