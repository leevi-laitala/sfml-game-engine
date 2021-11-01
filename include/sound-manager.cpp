#include "sound-manager.hpp"

SoundManager::SoundManager() {}

SoundManager::~SoundManager() {}

// Adds audio file to sound buffer handler
void SoundManager::addSound(const std::string& fname, System::Resources::Sounds id)
{
    m_resSounds.load(fname, id);
    m_mapSnd.insert(std::pair<System::Resources::Sounds, SoundInstance*>(id, new SoundInstance(m_resSounds.get(id), 50, 1.f, false))); // Default settings
}

// Removes sound from sounds map, not touching the resource manager tho
void SoundManager::rmSound(System::Resources::Sounds id)
{
    // TODO: Also remove from resource manager
    if (m_mapSnd.find(id) != m_mapSnd.end()) // Check if id exists in map
        delete m_mapSnd[id];
}

// Play sound
void SoundManager::playSound(System::Resources::Sounds id)
{
    if (m_mapSnd.find(id) != m_mapSnd.end())
        m_mapSnd[id]->playsnd();
}

// Clear all sounds from map and also clears resource manager
void SoundManager::purge()
{
    for (auto it : m_mapSnd)
        delete it.second;

    m_resSounds.purge();
}
