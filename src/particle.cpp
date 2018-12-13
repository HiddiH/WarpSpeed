/* UseAfterFreee
 * github.com/UseAfterFreee
 *
 * Particle Class Definitions
 */

#include "particle.hpp"
#include <cmath>

Particle::Particle(float pos_x, float pos_y)
    : pos(pos_x, pos_y)
{
}

void Particle::tick(float t)
{
    /* Update velocity based on acceleration */
    Vec2D dir = (pos-Vec2D(500,500));
    dir.normalize();

    vel = dir * (0.5/(1+exp(-4*(t-2))));

    /* Update position based on velocity */
    pos += vel;

    acc.x = 0;
    acc.y = 0;
}

void Particle::applyForce(float x, float y)
{
    acc.x += x;
    acc.y += y;
}

void Particle::show(SDL_Renderer* r)
{
    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    SDL_RenderDrawPoint(r, pos.x, pos.y);
}
