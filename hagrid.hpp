#include "src/engine.hpp"

class Hagrid : public Engine
{
private:
    ResourceManager<sf::Texture, System::Resources::Textures> resTextures;

public:
    Hagrid();
    ~Hagrid();

    void create() override;
    void step() override;
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

void Hagrid::create()
{
    createScene(System::Scenes::Game);
    createScene(System::Scenes::Mainmenu);
    addElement(System::Scenes::Game, dynamic_cast<Element*>(new Balloon(getScene(System::Scenes::Game), resTextures.get(System::Resources::Textures::Balloon))));
    switchScene(System::Scenes::Game);

    eventManager.addMouseButtonCallback(sf::Mouse::Button::Left, [&](const sf::Event&){ 
        if (activeScene == System::Scenes::Game)
        {
            switchScene(System::Scenes::Mainmenu);
        } else
        {
            switchScene(System::Scenes::Game);
        }
    });
}

void Hagrid::step()
{
    updateScene(activeScene);
    renderScene(activeScene);
}

void Hagrid::end()
{
    std::cout << "About tot purge assets" << std::endl;
    //resTextures.purge();
}

