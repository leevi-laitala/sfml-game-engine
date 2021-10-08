#include "sound-queue.hpp"

SoundManager::SoundManager()
{
}

SoundManager::SoundManager~()
{
}

void SoundManager::addSound(sf::Sound* snd, System::Resources::Sounds id)
{
    m_mapSnd.insert(std::pair<System::Resources::Sounds, SoundInstance>(id, SoundInstance(m_bufSnd, snd, 100, 1.f, false))); // Default settings
}

void SoundManager::playSound(System::Resources::Sounds id)
{
    if (m_mapSnd.find(id) != m_mapSnd.end())
        // TODO: Play sound
}
