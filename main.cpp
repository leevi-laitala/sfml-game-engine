#include "src/element.hpp"
#include "src/balloon.hpp"
#include "src/scene.hpp"
#include "src/resource-manager.hpp"

#include <SFML/Graphics.hpp>

namespace Resources
{
    enum Textures
    {
        Balloon,
        Heart,
        Dagger,
        Pop
    };
}

int main()
{
    //sf::Texture balloontex;
    //balloontex.loadFromFile("assets/balloon.png");

    ResourceManager<sf::Texture, Resources::Textures> resTextures;
    resTextures.load("assets/balloon.png", Resources::Textures::Balloon);
    resTextures.load("assets/dagger.png", Resources::Textures::Dagger);
    resTextures.load("assets/heart.png", Resources::Textures::Heart);
    resTextures.load("assets/pop.png", Resources::Textures::Pop);

    resTextures.destroy(Resources::Textures::Dagger);

    sf::RenderWindow window(sf::VideoMode(1280, 720, 32), "SFML Hagrid");
    //Balloon testBalloon(&balloontex, &window, sf::Vector2f(128.f, 128.f));
    Scene testScene(&window);
    testScene.addElement(dynamic_cast<Element*>(new Balloon(testScene.getScene(), resTextures.get(Resources::Textures::Balloon))));

    while (window.isOpen())
    {
        sf::Event event;
        window.clear(sf::Color(220, 125, 210));

        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
        
        testScene.updateElements();
        testScene.render();

        window.display();
    }

    resTextures.purge();

    return 0;
}
