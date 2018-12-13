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
        Random(unsigned int seed);

        static int randBetween(int a, int b);
};
