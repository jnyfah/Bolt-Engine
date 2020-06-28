#ifndef RIGIDBODY_H
#define RIGIDBODY_H
#include "Vector2D.h"

const float UNIT_MASS = 1.0;
const float GRAVITY =9.8;
const int FOWARD = 1;
const int BACKWARD= -1;

const int UPWARD = -1;
const int DOWNWARD = 1;



class RigidBody
{
    public:
        RigidBody() {
            m_mass = UNIT_MASS;
            m_gravity = GRAVITY;
        }

        inline float setmass(float mass)
        {
            m_mass = mass;
        }

        inline float setgravity(float gravity)
        {
            m_gravity = gravity;
        }

        void applyforce(Vector2D force)
        {
            m_force = force;
        }
       void applyforceX(float fx)
        {
            m_force.X = fx;
        }

        void applyforceY(float fy)
        {
            m_force.Y = fy;
        }

        void unsetforce()
        {
            m_force = Vector2D (0,0);
        }


        void applyfriction(Vector2D friction)
        {
           m_friction = friction;
        }

        void unsetfriction()
        {
            m_friction = Vector2D (0,0);
        }


        void update(float dt)
        {
            m_accelation.X = (m_force.X + m_friction.X)/m_mass;
            m_accelation.Y = m_gravity + m_force.Y/m_mass;
            m_velocity = m_accelation *dt;
            m_postion = m_velocity *dt;

        }


        //Getter functions

        float Getmass()
        {
            return m_mass;
        }
        Vector2D Position()
        {
            return m_postion;
        }

        Vector2D Velocity()
        {
            return m_velocity;
        }

        Vector2D Acceleration()
        {
            return m_accelation;
        }



    private:
        float m_mass,  m_gravity;
        Vector2D  m_friction;
        Vector2D  m_force;
        Vector2D  m_postion;
        Vector2D  m_velocity;
        Vector2D  m_accelation;
};

#endif // RIGIDBODY_H
