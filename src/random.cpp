/* UseAfterFreee
 * github.com/UseAfterFreee
 *
 * Random Number class definitions
 */

#include "random.hpp"


Random::Random(unsigned int seed)
{
}

void Random::init()
{
    srand(seed); // Set the seed
}

int Random::randBetween(int a, int b)
{
    /* b-a gives the total range of the random number 
     * + a offsets it so the first possible number is a and the last is b-1
     */

    return  (rand() % (b-a)) + a;
}
