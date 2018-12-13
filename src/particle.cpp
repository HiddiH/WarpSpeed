/* UseAfterFreee
 * github.com/UseAfterFreee
 *
 * Particle Class Definitions
 */

#include "particle.hpp"

Particle::Particle(float pos_x, float pos_y)
    : pos_x(pos_x), pos_y(pos_y)
{
}

void Particle::tick(float dt)
{
    /* Update velocity based on acceleration */
    vel_x += acc_x * dt;
    vel_y += acc_y * dt;

    /* Update position based on velocity */
    pos_x += vel_x * dt;
    pos_y += vel_y * dt;

    acc_x = 0;
    acc_y = 0;
}

void Particle::applyForce(float x, float y)
{
    acc_x += x;
    acc_y += y;
}

void Particle::show(SDL_Renderer* r)
{
    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    SDL_RenderDrawPoint(r, pos_x, pos_y);
}
