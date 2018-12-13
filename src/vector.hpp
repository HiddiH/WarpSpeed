/* UseAfterFreee
 * github.com/UseAfterFreee
 *
 * 2D Vector math
 */

class Vec2D
{
    private:
    public:
        float x, y;

        /* Constructor */
        Vec2D();
        Vec2D(float x, float y);
        
        /* Operator Overloading */
        Vec2D operator*(const float& f);

        Vec2D operator-(const Vec2D& v2);
        Vec2D& operator-=(const Vec2D& v2);

        Vec2D operator+(const Vec2D& v2);
        Vec2D& operator+=(const Vec2D& v2);
};
