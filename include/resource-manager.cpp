template<typename Resource, typename ID>
ResourceManager<Resource, ID>::ResourceManager() {}


template<typename Resource, typename ID>
ResourceManager<Resource, ID>::~ResourceManager()
{
    purge();
}



template<typename Resource, typename ID>
void ResourceManager<Resource, ID>::load(const std::string& fname, ID id)
{
    // Load resource from disc to heap, and save it's pointer to map
    if (m_mapResources.find(id) == m_mapResources.end()) // Continue only if resource does not exist
    {
        Resource* res = new Resource();

        if (!res->loadFromFile(fname))
        {
            std::cout << "Could not load file " << fname << std::endl;
            delete res;
        } else
        {
            m_mapResources.insert(std::pair<ID, Resource*>(id, res));
        }

        std::cout << "[Res manager] Resource loaded. Current map size: " << m_mapResources.size() << std::endl;
    }
}

// Get pointer to resource
template<typename Resource, typename ID>
Resource* ResourceManager<Resource, ID>::get(ID id)
{
    if (m_mapResources.find(id) != m_mapResources.end()) // Check if resource exists
        return m_mapResources[id];

    return nullptr;
}

// Delete one resource
template<typename Resource, typename ID>
void ResourceManager<Resource, ID>::destroy(ID id)
{
    if (m_mapResources.find(id) != m_mapResources.end()) // Check if resource exists
    {
        delete m_mapResources[id];
        m_mapResources.erase(id);
    }

    std::cout << "[Res manager] Res deleted. Current map size: " << m_mapResources.size() << std::endl;
}

// Clear all resources
template<typename Resource, typename ID>
void ResourceManager<Resource, ID>::purge()
{
    // Free memory
    for (auto it = m_mapResources.begin(); it != m_mapResources.end(); ++it)
        delete it->second;
    
    // Clear map
    m_mapResources.clear();

    std::cout << "[Res manager] Res purged. Current map size: " << m_mapResources.size() << " (Should be 0)" << std::endl;
}
