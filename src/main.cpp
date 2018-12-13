#include <iostream>
#include <SDL2/SDL.h>

#include "window.hpp"
#include "event_handler.hpp"
#include "particle.hpp"
#include "random.hpp"

int main(int argc, char* argv[])
{
    window window(1000, 1000);
    EventHandler eh;

    window.createWindow();
    Particle* parts[50];
    for (int i = 0; i < 50; ++i)
    {
        parts[i] = new Particle(Random::randBetween(0,1000),Random::randBetween(0,1000));
    }

    float dt=0.05;

    while (!eh.needQuit())
    {
        eh.handleEvents();
        // window.drawBackground(0,0,0);
        
        for (int i = 0; i < 50; ++i)
        {
            auto p = parts[i];
            p->tick(dt);
            p->show(window.getRenderer());
        }

        SDL_RenderPresent(window.getRenderer());
        SDL_Delay(1000/60.0);
    }
}
