/* UseAfterFreee
 * github.com/UseAfterFreee
 *
 * 2D Vector math definitions
 */

#include "vector.hpp"

Vec2D::Vec2D()
{
}

Vec2D::Vec2D(float x, float y)
    : x(x), y(y)
{
}

float Vec2D::getMag()
{
    return sqrt(x*x+y*y);
}

void Vec2D::normalize()
{
    float mag = getMag();
    x * (1/mag);
    y * (1/mag);
}

Vec2D Vec2D::operator*(const float& f)
{
    return Vec2D(f*x, f*y);
}

Vec2D Vec2D::operator-(const Vec2D& v2)
{
    return Vec2D(x-v2.x, y-v2.y);
}

Vec2D& Vec2D::operator-=(const Vec2D& v2)
{
    x -= v2.x;
    y -= v2.y;
    return *this;
}

Vec2D Vec2D::operator+(const Vec2D& v2)
{
    return Vec2D(x+v2.x, y+v2.y);
}

Vec2D& Vec2D::operator+=(const Vec2D& v2)
{
    x += v2.x;
    y += v2.y;
    return *this;
}
