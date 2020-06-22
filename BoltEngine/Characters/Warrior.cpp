#include "Warrior.h"

#include "../Graphics/Texture.h"
#include "SDL.h"



Warrior::Warrior(Properties* props):Character(props)
{
 m_row =1;
    m_framecount = 4;
    m_speed = 100;
}

void Warrior::Draw()
{
   Texture::Getinstance()->DrawFrame(m_textureID, trans->X, trans->Y, m_width, m_height, m_row, m_frame);
}

void Warrior::Update(float dt)
{
  m_frame = (SDL_GetTicks()/m_speed) % m_framecount;
}

void Warrior::Clean()
{
Texture::Getinstance()->Clean();
}


