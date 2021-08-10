#include "src/engine.hpp"

class Hagrid : public Engine
{
private:
    ResourceManager<sf::Texture, System::Resources::Textures> resTextures;

public:
    Hagrid();
    ~Hagrid();

    void run() override;
    void end() override;
};





Hagrid::Hagrid()
{
    resTextures.load("assets/balloon.png", System::Resources::Textures::Balloon);
    resTextures.load("assets/dagger.png", System::Resources::Textures::Dagger);
    resTextures.load("assets/heart.png", System::Resources::Textures::Heart);
    resTextures.load("assets/pop.png", System::Resources::Textures::Pop);
}

Hagrid::~Hagrid()
{
}

void Hagrid::run()
{
    createScene(System::Scenes::Game);
    createScene(System::Scenes::Mainmenu);
    addElement(System::Scenes::Game, dynamic_cast<Element*>(new Balloon(getScene(System::Scenes::Game), resTextures.get(System::Resources::Textures::Balloon))));
    switchScene(System::Scenes::Game);

    while (window->isOpen())
    {
        sf::Event event;
        window->clear(sf::Color(220, 125, 210));

        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (activeScene == System::Scenes::Game)
            {
                switchScene(System::Scenes::Mainmenu);
            } else
            {
                switchScene(System::Scenes::Game);
            }
        }

        renderScene();

        window->display();
    }

    resTextures.purge();
}

void Hagrid::end()
{
}

