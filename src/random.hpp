/* UseAfterFreee
 * github.com/UseAfterFreee
 *
 * Random Number class
 */

#include <cstdlib>

class Random
{
    private:
        static unsigned int seed;
    public:
        Random(unsigned int seed); // Speficy the seed in the constructor

        static int randBetween(int a, int b); // Gives a random integer between inclusive a and exclusive b
};
