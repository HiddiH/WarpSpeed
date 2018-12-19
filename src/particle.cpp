/* UseAfterFreee
 * github.com/UseAfterFreee
 * Hoi
 * Particle Class Definitions
 */

#include "particle.hpp"
#include <cmath>

extern unsigned int WINDOW_WIDTH;
extern unsigned int WINDOW_HEIGHT;

Particle::Particle(float pos_x, float pos_y)
    : pos(pos_x, pos_y), origin(pos_x, pos_y)
{
}

void Particle::tick(float t)
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
        pos = OldPos;
    }

    if (pos.y < 0 || pos.y > WINDOW_HEIGHT) {
        pos = OldPos;
    }
}

void Particle::applyForce(float x, float y)
{
    acc.x += x;
    acc.y += y;
}

void Particle::show(SDL_Renderer* r)
{
    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    SDL_RenderDrawLine(r, pos.x, pos.y, origin.x, origin.y);
}
