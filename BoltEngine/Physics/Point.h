#ifndef POINT_H
#define POINT_H



class Point
{
    public:
       float X, Y;

       Point(float X =0, float Y = 0):X(X), Y(Y){}

       inline Point operator+(const Point& p2)
       {
           return Point(X + p2.X, p2.Y + Y);
       }

       inline friend Point operator+=(Point& p1, const Point& p2)
       {
           p1.X += p2.X;
           p1.Y += p2.Y;

           return p1;
       }

       inline Point operator-(const Point& p2)
       {
           return Point(X - p2.X, Y - p2.Y );
       }

       inline friend Point operator-=(Point& p1, const Point& p2)
       {
           p1.X -= p2.X;
           p1.Y -= p2.Y;

           return p1;
       }

       inline Point operator*(const float z) const
       {
           return Point(X * z, Y *z);
       }


};

#endif // POINT_H
