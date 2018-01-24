#include "stdafx.h"
#include "ModeApplication.h"

ModeApplication::ModeApplication(){}
void ModeApplication::logic() {}
void ModeApplication::input() {}
void ModeApplication::renderer() {}
int  ModeApplication::getId() { return -1; }
bool ModeApplication::OverLapped(Sprite *sprite, ivec2 m_mousePos, float scale)
{
	if (sprite->getX() + sprite->getSizeX() / 2 >= m_mousePos.x && sprite->getX() - sprite->getSizeX() / 2 <= m_mousePos.x  && sprite->getY() - sprite->getSizeX() / 2 <= m_mousePos.y  &&  sprite->getY() + sprite->getSizeY() / 2 >= m_mousePos.y)
	{
		sprite->setScale(scale);
		return true;
	}
	else sprite->setScale(1);
	return false;
}