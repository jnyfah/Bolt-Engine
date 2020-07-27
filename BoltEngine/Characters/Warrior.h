#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"
#include "Animation.h"
#include "RigidBody.h"
#include "colider.h"
#include "Vector2D.h"

const float Jump_time = 15.0;
const float Jump_force = 10.0;

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
        colider* m_collide;
        Vector2D last_position;

        float m_jump_time;
        float m_jump_force;

        bool m_isjumping;
        bool m_isgrounded;


};
#endif // WARRIOR_H
