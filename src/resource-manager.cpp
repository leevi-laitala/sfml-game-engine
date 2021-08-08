template<typename Resource, typename ID>
ResourceManager<Resource, ID>::ResourceManager()
{
}

template<typename Resource, typename ID>
ResourceManager<Resource, ID>::~ResourceManager()
{
}

template<typename Resource, typename ID>
void ResourceManager<Resource, ID>::load(const std::string& fname, ID id)
{
    if (m_mapResources.find(id) == m_mapResources.end()) // Continue only if resource does not exist
    {
        Resource* res = new Resource();

        if (!res->loadFromFile(fname))
        {
            std::cout << "Could not load file " << fname << std::endl;
            delete res;
        } else
            m_mapResources.insert(std::pair<ID, Resource*>(id, res));

        std::cout << "Map size: " << m_mapResources.size() << std::endl;
    }
}

template<typename Resource, typename ID>
Resource* ResourceManager<Resource, ID>::get(ID id)
{
    if (m_mapResources.find(id) != m_mapResources.end()) // Check if resource exists
        return m_mapResources[id];
}

template<typename Resource, typename ID>
void ResourceManager<Resource, ID>::destroy(ID id)
{
    if (m_mapResources.find(id) != m_mapResources.end()) // Check if resource exists
    {
        delete m_mapResources[id];
        m_mapResources.erase(id);
    }

    std::cout << "Map size: " << m_mapResources.size() << std::endl;
}

template<typename Resource, typename ID>
void ResourceManager<Resource, ID>::purge()
{
    for (auto it = m_mapResources.begin(); it != m_mapResources.end(); ++it)
        delete it->second;
    
    m_mapResources.clear();

    std::cout << "Map size: " << m_mapResources.size() << std::endl;
}
