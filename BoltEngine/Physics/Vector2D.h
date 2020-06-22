#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <iostream>


class Vector2D
{
public:
      float X, Y;

    Vector2D( float x = 0, float y = 0):X(x), Y(y) {}

    Vector2D operator+ (const Vector2D &v) const
    {
        return Vector2D ( X + v.X, Y + v.Y );
    }

    Vector2D operator- (const Vector2D &v) const
    {
        return Vector2D ( X - v.X, Y - v.Y );
    }
    Vector2D operator* (const float scalar) const
    {
        return Vector2D ( X * scalar, Y * scalar);
    }

    void log (std::string mag = " ")
    {
        std::cout<<mag<< X << Y <<std::endl;
    }



};

#endif // VECTOR2D_H
