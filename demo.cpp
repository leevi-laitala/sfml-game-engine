#include "demo.hpp"

Demo::Demo()
{
    m_backgroundColor = sf::Color(222, 147, 124);

    resTextures.load("assets/sprites/balloon.png", System::Resources::Textures::Balloon);
    resTextures.load("assets/sprites/dagger.png", System::Resources::Textures::Dagger);
    resTextures.load("assets/sprites/heart.png", System::Resources::Textures::Heart);
    resTextures.load("assets/sprites/pop.png", System::Resources::Textures::Pop);
    resTextures.load("assets/sprites/button.png", System::Resources::Textures::Button);

    resFonts.load("assets/fonts/aez-epic-font.ttf", System::Resources::Fonts::EpicFont);

    soundManager.addSound("assets/sfx/naai.ogg", System::Resources::Sounds::Naai);
    soundManager.addSound("assets/sfx/explode.ogg", System::Resources::Sounds::ButtonPress);
    soundManager.addSound("assets/sfx/pop.ogg", System::Resources::Sounds::BalloonPop);

    eventManager.addCallback(sf::Event::Closed, [&](const sf::Event&){ switchScene(System::Scenes::Mainmenu); });
    eventManager.addCallback(sf::Event::Resized, [&](const sf::Event& event){ 
        sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
        window.setView(sf::View(visibleArea)); });
}

Demo::~Demo() {}

void Demo::create()
{
    createScene(System::Scenes::Game);
    createScene(System::Scenes::Mainmenu);
    createScene(System::Scenes::Score);
    
    //
    // Construct Mainmenu
    //
    addElement(System::Scenes::Mainmenu, dynamic_cast<Element*>(new Button(getScene(System::Scenes::Mainmenu),
                                                                           resTextures.get(System::Resources::Textures::Button),
                                                                           resFonts.get(System::Resources::Fonts::EpicFont), 
                                                                           "Play", 
                                                                           [&](){ soundManager.playSound(System::Resources::Sounds::ButtonPress); 
                                                                                  switchScene(System::Scenes::Game);
                                                                                },
                                                                           [&](){ soundManager.playSound(System::Resources::Sounds::BalloonPop); },
                                                                           [](){},
                                                                           sf::Vector2f(window.getSize().x * .25f, window.getSize().y * .6f)
                                                                           )));

    addElement(System::Scenes::Mainmenu, dynamic_cast<Element*>(new Button(getScene(System::Scenes::Mainmenu), 
                                                                           resTextures.get(System::Resources::Textures::Button), 
                                                                           resFonts.get(System::Resources::Fonts::EpicFont), 
                                                                           "Quit", 
                                                                           [&](){ window.close();
                                                                                }, 
                                                                           [&](){ soundManager.playSound(System::Resources::Sounds::BalloonPop); },
                                                                           [](){},
                                                                           sf::Vector2f(window.getSize().x * .75f, window.getSize().y * .6f)
                                                                           )));

    addElement(System::Scenes::Mainmenu, dynamic_cast<Element*>(new Balloon(getScene(System::Scenes::Mainmenu),
                                                                        resTextures.get(System::Resources::Textures::Balloon)
                                                                        )));
    // Game scene
    addElement(System::Scenes::Game, dynamic_cast<Element*>(new Balloon(getScene(System::Scenes::Game),
                                                                        resTextures.get(System::Resources::Textures::Balloon)
                                                                        )));

    // Score scene
    addElement(System::Scenes::Score, dynamic_cast<Element*>(new Button(getScene(System::Scenes::Score), 
                                                                           resTextures.get(System::Resources::Textures::Button), 
                                                                           resFonts.get(System::Resources::Fonts::EpicFont), 
                                                                           "Mainmenu", 
                                                                           [&](){ switchScene(System::Scenes::Mainmenu);
                                                                                }, 
                                                                           [](){},
                                                                           [](){},
                                                                           sf::Vector2f(512.f, 512.f)
                                                                           )));
     
    addElement(System::Scenes::Mainmenu, dynamic_cast<Element*>(new Text(getScene(System::Scenes::Mainmenu),
                                                                         sf::Text("Demo", *resFonts.get(System::Resources::Fonts::EpicFont), 72)
                                                                         )));

    switchScene(System::Scenes::Mainmenu);
    soundManager.playSound(System::Resources::Sounds::Naai);
}

void Demo::step()
{
    updateScene(activeScene);
    renderScene(activeScene);
}

void Demo::end()
{
    resTextures.purge();
    resFonts.purge();
    soundManager.purge();
}

