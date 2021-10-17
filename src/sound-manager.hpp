#pragma once

#include <SFML/Audio.hpp>
#include <iostream>
#include <map>

#include "enum-resources.hpp" 
#include "resource-manager.hpp"

struct SoundInstance
{
    sf::Sound        m_snd;

    SoundInstance(sf::SoundBuffer* bufptr, const uint8_t& vol, const float& pitch, const bool& loop)
    {
        m_snd.setBuffer(*bufptr);
        m_snd.setPitch(pitch);
        m_snd.setVolume(vol);
        m_snd.setLoop(loop);
    }

    void playsnd()
    {
        m_snd.play();
    }
};

class SoundManager
{
private:
    std::unordered_map<System::Resources::Sounds, SoundInstance*> m_mapSnd;
    ResourceManager<sf::SoundBuffer, System::Resources::Sounds> m_resSounds;

public:
    SoundManager();
    ~SoundManager();

    void addSound(const std::string& fname, System::Resources::Sounds id);
    void rmSound(System::Resources::Sounds id);
    void playSound(System::Resources::Sounds id);
    void purge();
};
