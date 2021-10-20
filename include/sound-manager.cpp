#include "sound-manager.hpp"

SoundManager::SoundManager() {}

SoundManager::~SoundManager() {}

void SoundManager::addSound(const std::string& fname, System::Resources::Sounds id)
{
    m_resSounds.load(fname, id);
    m_mapSnd.insert(std::pair<System::Resources::Sounds, SoundInstance*>(id, new SoundInstance(m_resSounds.get(id), 50, 1.f, false))); // Default settings
}

void SoundManager::rmSound(System::Resources::Sounds id)
{
    if (m_mapSnd.find(id) != m_mapSnd.end()) // Check if id exists in map
        delete m_mapSnd[id];
}

void SoundManager::playSound(System::Resources::Sounds id)
{
    if (m_mapSnd.find(id) != m_mapSnd.end())
        m_mapSnd[id]->playsnd();
}

void SoundManager::purge()
{
    for (auto it : m_mapSnd)
        delete it.second;

    m_resSounds.purge();
}