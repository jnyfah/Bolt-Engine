#include "Animation.h"
#include "Texture.h"



void Animation::update()
{
    sprite_frame = (SDL_GetTicks()/anim_speed) % frame_count;
}

void Animation::draw(float X, float Y, int sprite_width, int sprite_height)
{
   Texture::Getinstance()->DrawFrame(text_ID, X , Y, sprite_width, sprite_height,sprite_row, sprite_frame, flip);
}

void Animation::setprops(std::string m_text_ID, int m_sprite_row, int m_frame_count, int m_anim_speed,  SDL_RendererFlip m_flip)
{

    text_ID = m_text_ID;
    sprite_row = m_sprite_row;

    anim_speed = m_anim_speed;
    frame_count = m_frame_count;
    flip = m_flip;


}
