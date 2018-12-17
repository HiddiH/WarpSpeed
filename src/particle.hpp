/* UseAfterFreee
 * github.com/UseAfterFreee
 * 
 * Particle Class
 */
#include <SDL2/SDL.h>
#include "vector.hpp"

class Particle
{
    private:
        Vec2D pos;
        Vec2D origin;
        Vec2D vel;
        Vec2D acc;

    public:
        Particle(float pos_x, float pos_y);

        void tick(float dt);
        void applyForce(float x, float y);
        void show(SDL_Renderer* r);
};
