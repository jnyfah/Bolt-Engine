#include "Warrior.h"
#include "Event.h"

#include "../Graphics/Texture.h"
#include "SDL.h"
#include "camera.h"
#include "../Engine.h"
#include "collision.h"



Warrior::Warrior(Properties* props):Character(props)
{

    m_rigidbody = new RigidBody();
    m_rigidbody->setgravity(2.0f);

    m_jump_force = Jump_force;
    m_jump_time = Jump_time;

    m_collide = new colider();
    m_collide->set_buffer(-60,-20, 0, 0);

    Anime = new Animation();
    Anime->setprops(m_textureID, 1,8,100, SDL_FLIP_HORIZONTAL);

}

void Warrior::Draw()
{
    Anime -> draw(trans->X, trans->Y, m_width, m_height);
    Vector2D cam =camera::Get_instance()->Get_postion();
    SDL_Rect box = m_collide->Get();

    box.x -= cam.X;
    box.y -= cam.Y;

    SDL_RenderDrawRect(Engine::Get_instance()->Get_Renderer(), &box);
}

void Warrior::Update(float dt)
{
    Anime->setprops("player", 1,4,100, SDL_FLIP_HORIZONTAL);
    m_rigidbody->unsetforce();

    if (Event::Get_Instance()->Get_KeyDown(SDL_SCANCODE_LEFT))
    {
        m_rigidbody->applyforceX(10 * BACKWARD);
        Anime->setprops("player_run", 1,8,100);
    }

    if (Event::Get_Instance()->Get_KeyDown(SDL_SCANCODE_RIGHT))
    {
        m_rigidbody->applyforceX(10 * FOWARD);
        Anime->setprops("player_run", 1,8,150, SDL_FLIP_HORIZONTAL);
    }

    if(Event::Get_Instance()->Get_KeyDown(SDL_SCANCODE_UP) && m_isgrounded)
    {
        m_isjumping = true;
        m_isgrounded = false;
        m_rigidbody->applyforce(UPWARD * m_jump_force);
    }

    if(Event::Get_Instance()->Get_KeyDown(SDL_SCANCODE_UP) && m_isjumping && Jump_time > 0)
    {
      m_jump_time -= dt;
      m_rigidbody->applyforceY(UPWARD * m_jump_force);

    } else
    {
        m_isjumping = false;
        m_jump_time = Jump_time;
    }


    // x-axis
    m_rigidbody->update(dt);
    last_position.X = trans->X;
    trans->X += m_rigidbody->Position().X;
    m_collide->set(trans->X, trans->Y, 96, 96);

    if(collision::Get_instance()->mapcollision(m_collide->Get()))
    {
        trans->X = last_position.X;
    }

     // y-axis
    m_rigidbody->update(dt);
    last_position.Y = trans->Y;
    trans->Y += m_rigidbody->Position().Y;
    m_collide->set(trans->X, trans->Y, 96, 96);

    if(collision::Get_instance()->mapcollision(m_collide->Get()))
    {
        m_isgrounded = true;
        trans->Y = last_position.Y;
    }
    else
    {
        m_isgrounded = false;
    }
     if(m_isjumping || !m_isgrounded)
     {
        Anime->setprops("player_jump", 1,1,150);
     }
    //trans->TranslateX(m_rigidbody->Position().X);
    //trans->TranslateY(m_rigidbody->Position().Y);

    origin->X = trans->X+ m_width/2;
    origin->Y = trans->Y+ m_height/2;
    Anime->update();


}

void Warrior::Clean()
{
    Texture::Getinstance()->Drop(m_textureID);
}


