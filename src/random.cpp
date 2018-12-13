/* UseAfterFreee
 * github.com/UseAfterFreee
 *
 * Random Number class definitions
 */

#include "random.hpp"

unsigned int Random::seed = 0;

Random::Random(unsigned int seed)
{
}

int Random::randBetween(int a, int b)
{
    return  (rand() % (b-a)) + a;
}
