/* UseAfterFreee
 * github.com/UseAfterFreee
 * 
 * Particle Class
 */
#include <SDL2/SDL.h>

class Particle
{
    private:
        float pos_x, pos_y;
        float vel_x, vel_y;
        float acc_x, acc_y;

    public:
        Particle(float pos_x, float pos_y);

        void tick(float dt);
        void applyForce(float x, float y);
        void show(SDL_Renderer* r);
};
