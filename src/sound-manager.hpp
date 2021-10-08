#pragma once

#include <SFML/Audio.hpp>
#include <iostream>
#include <map>

#include "enum-resources.hpp" 

struct SoundInstance
{
    sf::SoundBuffer* m_buf;
    sf::Sound*       m_snd;
    uint8_t          m_vol;
    float            m_pitch;
    bool             m_loop = false;

    SoundInstance(sf::SoundBuffer* buf, sf::Sound* snd, const uint8_t& vol, const float& pitch, const bool& loop)
        : m_buf(buf), m_snd(snd), m_vol(vol), m_pitch(pitch), m_loop(loop)
    {
        m_snd.setBuffer(&m_buf);
        m_snd.setPitch(m_pitch);
        m_snd.setVolume(m_vol);
        m_snd.setLoop(m_loop);
    }

    void play()
    {
       m_buf->playSound(m_snd); 
    }
}

class SoundManager
{
private:
    sf::SoundBuffer m_bufSnd;
    std::unordered_map<System::Resources::Sounds, SoundInstance> m_mapSnd;

public:
    SoundQueue();
    ~SoundQueue();

    void addSound(sf::Sound* snd, System::Resources::Sounds id);
    void playSound(System::Resources::Sounds id);
};
