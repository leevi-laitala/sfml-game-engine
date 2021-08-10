# SFML Game Engine

Simple and primitive SFML Game Engine.



# Structure

In the current engine toolchain you have the engine base class, scenes, element base class and resource handler.

The engine consists of one engine class header file, on top of which you build your game. The engine base class loads resources, handles scenes, and manages game logic.

Elements are all the things you can place in your game. Elements inherit from the element base class, but have their own functions and behaviour.

Elements are managed by scenes.






