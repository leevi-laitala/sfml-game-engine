#include "src/engine.hpp"

#include "src/balloon.hpp"
#include "src/button.hpp"
#include "src/element.hpp"

class Hagrid : public Engine
{
private:
    ResourceManager<sf::Texture, System::Resources::Textures> resTextures;
    ResourceManager<sf::Font, System::Resources::Fonts> resFonts;

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
    resTextures.load("assets/button.png", System::Resources::Textures::Button);

    resFonts.load("assets/aez-epic-font.ttf", System::Resources::Fonts::Default);
}

Hagrid::~Hagrid() {}

void Hagrid::create()
{
    createScene(System::Scenes::Game);
    createScene(System::Scenes::Mainmenu);
    addElement(System::Scenes::Game, dynamic_cast<Element*>(new Balloon(getScene(System::Scenes::Game), resTextures.get(System::Resources::Textures::Balloon))));

    addElement(System::Scenes::Game, dynamic_cast<Element*>(new Button(getScene(System::Scenes::Game), resTextures.get(System::Resources::Textures::Button), resFonts.get(System::Resources::Fonts::Default), "Mainmenu", 
                    [&](const sf::Event&){ switchScene(System::Scenes::Mainmenu); }, sf::Vector2f(512.f, 512.f))));

    addElement(System::Scenes::Mainmenu, dynamic_cast<Element*>(new Button(getScene(System::Scenes::Mainmenu), resTextures.get(System::Resources::Textures::Button), resFonts.get(System::Resources::Fonts::Default), "Jofa :D", 
                    [&](const sf::Event&){ std::cout << "Joo o" << std::endl; }, sf::Vector2f(512.f, 128.f))));

    switchScene(System::Scenes::Game);
}

void Hagrid::step()
{
    updateScene(activeScene);
    renderScene(activeScene);
}

void Hagrid::end()
{
    std::cout << "About tot purge assets" << std::endl;
    resTextures.purge();
}

