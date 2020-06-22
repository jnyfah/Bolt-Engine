#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "Vector2D.h"


class Transform
{
public:
    float X, Y;

    Transform(float x= 0, float y = 0):X(x), Y(y) {}
    void log (std::string mag = " ")
    {
        std::cout<<mag<< X << Y <<std::endl;
    }

private:


    void TranslateX(float x)
    {
        X += x;
    }
    void TranslateY(float y)
    {
        Y += y;
    }
    void Translate(Vector2D v)   // 2D translate
    {
        X += v.X;
        Y += v.Y;
    }


};

#endif // TRANSFORM_H
