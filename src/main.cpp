#include <iostream>
#include <SDL2/SDL.h>

#include "window.hpp"
#include "event_handler.hpp"
#include "particle.hpp"
#include "random.hpp"
#include <cmath>

int main(int argc, char* argv[])
{
    window window(1000, 1000);
    EventHandler eh;

    window.createWindow();

    const int total = 1000;
    Particle* parts[total];
    for (int i = 0; i < total; ++i)
    {
        int x = Random::randBetween(0,1000);
        int y = Random::randBetween(0,1000);
        
        parts[i] = new Particle(x, y);
    }

    float dt=0.05;

    while (!eh.needQuit())
    {
        eh.handleEvents();
        // window.drawBackground(0,0,0);
        
        for (int i = 0; i < total; ++i)
        {
            auto p = parts[i];
            p->tick(SDL_GetTicks()/1000);
            p->show(window.getRenderer());
        }

        SDL_RenderPresent(window.getRenderer());
        SDL_Delay(1000/500.0);
    }
}
