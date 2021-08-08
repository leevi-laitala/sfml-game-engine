#include "src/engine.hpp"

class Hagrid : public Engine
{
private:
    ResourceManager<sf::Texture, Resources::Textures> resTextures;

public:
    Hagrid();
    ~Hagrid();

    void run() override;
    void end() override;
};

Hagrid::Hagrid()
{
    resTextures.load("assets/balloon.png", Resources::Textures::Balloon);
    resTextures.load("assets/dagger.png", Resources::Textures::Dagger);
    resTextures.load("assets/heart.png", Resources::Textures::Heart);
    resTextures.load("assets/pop.png", Resources::Textures::Pop);

    resTextures.destroy(Resources::Textures::Dagger);
}

Hagrid::~Hagrid()
{
}

void Hagrid::run()
{
    Scene testScene(window);
    testScene.addElement(dynamic_cast<Element*>(new Balloon(testScene.getScene(), resTextures.get(Resources::Textures::Balloon))));

    while (window->isOpen())
    {
        sf::Event event;
        window->clear(sf::Color(220, 125, 210));

        while (window->pollEvent(event))
            if (event.type == sf::Event::Closed)
                window->close();

        testScene.updateElements();
        testScene.render();

        window->display();
    }

    resTextures.purge();
}

void Hagrid::end()
{
}

