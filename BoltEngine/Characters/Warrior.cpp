#include "Warrior.h"
#include "Event.h"

#include "../Graphics/Texture.h"
#include "SDL.h"




Warrior::Warrior(Properties* props):Character(props)
{

    Anime = new Animation();
    m_rigidbody = new RigidBody;
    Anime->setprops(m_textureID, 1,8,150, SDL_FLIP_HORIZONTAL);
}

void Warrior::Draw()
{
    Anime -> draw(trans->X, trans->Y, m_width, m_height);
}

void Warrior::Update(float dt)
{
    Anime->setprops("player", 1,4,150, SDL_FLIP_HORIZONTAL);
    m_rigidbody->unsetforce();

    if (Event::Get_Instance()->Get_KeyDown(SDL_SCANCODE_LEFT))
    {
        m_rigidbody->applyforceX(10 * BACKWARD);
        Anime->setprops("player_run", 1,8,150);
    }

    if (Event::Get_Instance()->Get_KeyDown(SDL_SCANCODE_RIGHT))
    {
        m_rigidbody->applyforceX(10 * FOWARD);
        Anime->setprops("player_run", 1,8,150, SDL_FLIP_HORIZONTAL);
    }


    m_rigidbody->update(0.5);

    trans->TranslateX(m_rigidbody->Position().X);
    //trans->TranslateY(m_rigidbody->Position().Y);
    Anime->update();
}

void Warrior::Clean()
{
    Texture::Getinstance()->Clean();
}


