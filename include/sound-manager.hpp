#pragma once

#include "resource-manager.hpp"
#include "enum-resources.hpp" 

#include <SFML/Audio.hpp>
#include <iostream>
#include <map>

// TODO: This probably isnt necessary
struct SoundInstance
{
    sf::Sound m_snd;

    SoundInstance(sf::SoundBuffer* bufptr, const uint8_t& vol, const float& pitch, const bool& loop)
    {
        m_snd.setBuffer(*bufptr);
        m_snd.setPitch(pitch);
        m_snd.setVolume(vol);
        m_snd.setLoop(loop);
    }

    ~SoundInstance()
    {
        std::cout << "[Sound inst ] Sound Instance purged" << std::endl;
    }

    void playsnd()
    {
        m_snd.play();
    }
};

// Sound manager class contains it's own resource manager
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
