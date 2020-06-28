#ifndef WARRIOR_H
#define WARRIOR_H
#include "Character.h"
#include "Animation.h"
#include "RigidBody.h"


class Warrior: public Character
{
    public:

        Warrior(Properties *props);
        virtual void Draw();
        virtual void Update(float dt);
        virtual void Clean();

    private:
        RigidBody *m_rigidbody;
        Animation *Anime;

};
#endif // WARRIOR_H
