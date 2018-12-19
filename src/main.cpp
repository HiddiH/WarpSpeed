#include <iostream>
#include <SDL2/SDL.h>

#include "window.hpp"
#include "event_handler.hpp"
#include "particle.hpp"
#include "random.hpp"
#include <cmath>
#include <ctime>

unsigned int WINDOW_WIDTH = 1920;
unsigned int WINDOW_HEIGHT = 1080;

unsigned int Random::seed = time(NULL);

int main(int argc, char* argv[])
{
    window window(WINDOW_WIDTH, WINDOW_HEIGHT);
    EventHandler eh;

    window.createWindow();

    Random::init();

    const int total = 500;
    Particle* parts[total];
    for (int i = 0; i < total; ++i)
    {
        int x = Random::randBetween(0,WINDOW_WIDTH);
        int y = Random::randBetween(0,WINDOW_HEIGHT);

        parts[i] = new Particle(x, y);
    }

    float dt=0.05;

    while (!eh.needQuit())
    {
        eh.handleEvents();
        window.drawBackground(0,0,0);

        for (int i = 0; i < total; ++i)
        {
            auto p = parts[i];
            p->tick(SDL_GetTicks()/1000, window.getRenderer());
            p->show(window.getRenderer());
        }

        SDL_RenderPresent(window.getRenderer());
        SDL_Delay(1000/500.0);
    }
}
