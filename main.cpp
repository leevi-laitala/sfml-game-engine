#include "hagrid.hpp"

int main()
{
    Hagrid hagrid;
    
    hagrid.initWindow(1280, 720, "SFML app");
    hagrid.run();

    return 0;
}
