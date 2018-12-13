/* UseAfterFreee
 * github.com/UseAfterFreee
 *
 * Particle Class Definitions
 */

#include "particle.hpp"

Particle::Particle(float pos_x, float pos_y)
    : pos(pos_x, pos_y)
{
}

void Particle::tick(float dt)
{
    /* Update velocity based on acceleration */
    // vel += acc * dt;
    vel += (pos - Vec2D(500,500));
    vel = vel * 0.1;

    /* Update position based on velocity */
    pos += vel * dt;

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
