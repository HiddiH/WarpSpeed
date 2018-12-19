/* UseAfterFreee
 * github.com/UseAfterFreee
 * Hoi
 * Particle Class Definitions
 */

#include "particle.hpp"
#include <cmath>
#include "random.hpp"

extern unsigned int WINDOW_WIDTH;
extern unsigned int WINDOW_HEIGHT;

Particle::Particle(float pos_x, float pos_y)
    : pos(pos_x, pos_y), origin(pos_x, pos_y)
{
}

void Particle::tick(float t, SDL_Renderer* r)
{
    /* Update velocity based on acceleration */
    Vec2D dir = (pos-Vec2D(WINDOW_WIDTH/2,WINDOW_HEIGHT/2));
    dir.normalize();

    vel = dir * (0.5/(1+exp(-4*(t-3)))+0.0001);

    /* Update position based on velocity */
    Vec2D OldPos = pos;
    pos += vel;

    acc.x = 0;
    acc.y = 0;

    if (pos.x < 0 || pos.x > WINDOW_WIDTH) {
        show(r);
        pos.x = Random::randBetween(0,WINDOW_WIDTH);
        pos.y = Random::randBetween(0,WINDOW_HEIGHT);
        origin = pos;
        Dline = false;
    }

    else {
        Dline = true;
    }

    if (pos.y < 0 || pos.y > WINDOW_HEIGHT) {
        show(r);
        pos.y = Random::randBetween(0,WINDOW_HEIGHT);
        pos.x = Random::randBetween(0,WINDOW_WIDTH);
        origin = pos;
        Dline = false;
    }

    else {
        Dline = true;
    }
}

void Particle::applyForce(float x, float y)
{
    acc.x += x;
    acc.y += y;
}

void Particle::show(SDL_Renderer* r)
{
    if (Dline == true) {
        SDL_SetRenderDrawColor(r, 116, 163, 173, 255);
        SDL_RenderDrawLine(r, pos.x, pos.y+3, origin.x, origin.y+3);
        SDL_RenderDrawLine(r, pos.x, pos.y-3, origin.x, origin.y-3);
        SDL_RenderDrawLine(r, pos.x+3, pos.y, origin.x+3, origin.y);
        SDL_RenderDrawLine(r, pos.x-3, pos.y, origin.x-3, origin.y);
        SDL_SetRenderDrawColor(r, 181, 218, 226, 255);
        SDL_RenderDrawLine(r, pos.x, pos.y+2, origin.x, origin.y+2);
        SDL_RenderDrawLine(r, pos.x, pos.y-2, origin.x, origin.y-2);
        SDL_RenderDrawLine(r, pos.x+2, pos.y, origin.x+2, origin.y);
        SDL_RenderDrawLine(r, pos.x-2, pos.y, origin.x-2, origin.y);
        SDL_SetRenderDrawColor(r, 221, 249, 255, 255);
        SDL_RenderDrawLine(r, pos.x, pos.y+1, origin.x, origin.y+1);
        SDL_RenderDrawLine(r, pos.x, pos.y-1, origin.x, origin.y-1);
        SDL_RenderDrawLine(r, pos.x+1, pos.y, origin.x+1, origin.y);
        SDL_RenderDrawLine(r, pos.x-1, pos.y, origin.x-1, origin.y);
        SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
        SDL_RenderDrawLine(r, pos.x, pos.y, origin.x, origin.y);
    }
}
