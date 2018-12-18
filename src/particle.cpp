/* UseAfterFreee
 * github.com/UseAfterFreee
 * Hoi
 * Particle Class Definitions
 */

#include "particle.hpp"
#include <cmath>

Particle::Particle(float pos_x, float pos_y)
    : pos(pos_x, pos_y), origin(pos_x, pos_y)
{
}

void Particle::tick(float t)
{
    /* Update velocity based on acceleration */
    Vec2D dir = (pos-Vec2D(500,500));
    dir.normalize();

    vel = dir * (0.5/(1+exp(-4*(t-3)))+0.0001);

    /* Update position based on velocity */
    Vec2D OldPos = pos;
    pos += vel;

    acc.x = 0;
    acc.y = 0;

    if (pos.x < 0 || pos.x > 1000) {
        pos = OldPos;
    }

    if (pos.y < 0 || pos.y > 1000) {
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
