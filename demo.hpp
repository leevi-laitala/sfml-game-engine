#include "include/engine.hpp"

#include "src/balloon.hpp"

class Demo : public Engine
{
private:
    ResourceManager<sf::Texture, System::Resources::Textures> resTextures;
    ResourceManager<sf::Font, System::Resources::Fonts> resFonts;

public:
    Demo();
    ~Demo();

    void create() override;
    void step() override;
    void end() override;
};
