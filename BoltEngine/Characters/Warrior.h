#ifndef WARRIOR_H
#define WARRIOR_H
#include "Character.h"


class Warrior: public Character
{
    public:

        Warrior(Properties *props);
        virtual void Draw();
        virtual void Update(float dt);
        virtual void Clean();

    private:
        int m_row, m_frame, m_framecount;
        int m_speed;

};
#endif // WARRIOR_H
