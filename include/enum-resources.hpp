#pragma once

namespace System
{
namespace Resources
{
    enum class Textures
    {
        Balloon = 1,
        Heart,
        Dagger,
        Pop,
        Button
    };

    enum class Fonts
    {
        EpicFont = 1
    };

    enum class Sounds
    {
        ButtonPress = 1,
        BalloonPop,
        Naai
    };
} // Namespace Resources

enum class Scenes
{
    Mainmenu = 1,
    Game,
    Score
};

enum class Elements
{
    Button = 1,
    Text,

    Balloon
};
} // Namespace System
