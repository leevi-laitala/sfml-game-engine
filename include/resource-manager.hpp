#pragma once

#include <unordered_map>
#include <string>
#include <iostream>

template<typename Resource, typename ID>
class ResourceManager
{
private:
    std::unordered_map<ID, Resource*> m_mapResources;

public:
    ResourceManager();
    ~ResourceManager();

    void load(const std::string& fname, ID id);
    Resource* get(ID id);

    void destroy(ID id);
    void purge();
};

#include "resource-manager.cpp"
