#include <iostream>
#include <SDL2/SDL.h>

#include "window.hpp"
#include "event_handler.hpp"
#include "particle.hpp"

int main(int argc, char* argv[])
{
    window window(1000, 1000);
    EventHandler eh;

    window.createWindow();
    Particle p(500,500);

    float dt=0.05;

    while (!eh.needQuit())
    {
        p.applyForce(2,1);
        eh.handleEvents();
        // window.drawBackground(0,0,0);
        
        p.tick(dt);
        p.show(window.getRenderer());

        SDL_RenderPresent(window.getRenderer());
        SDL_Delay(1000/60.0);
    }
}
