#include "stdafx.h"
#include "Game.h"
#include "Global.h"
#include "Bubble.h"
#include <time.h>

Bubble::Bubble() : Entity(tBubble)
{
	m_positionX = 0;
	m_positionY = 0;
	m_sizeX     = 0;
	m_sizeY     = 0;
	m_velocityX = 0;
	m_velocityY = 0;
	m_activated = false;
};

void Bubble::init(float size, float acceletation, bool newBubble, float posX, float posY , bool direcctionVelocity)
{
	
	if (!newBubble)
	{
		m_sizeX     = size; 
		m_sizeY     = size;
		m_positionY = rand() % (5 * SCR_HEIGHT / 6 - SCR_HEIGHT / 2) + SCR_HEIGHT / 2;
		m_positionX = rand() % (5 * SCR_WIDTH  / 6 -  SCR_WIDTH / 2) + SCR_HEIGHT / 2;
		m_velocityX = VELOCITY / SCR_FPS;
		m_velocityY = VELOCITY / SCR_FPS;
		m_sprite.setSize(size, size);
		m_sprite.setPosition(m_positionX, m_positionY);
	}
	else
	{
		m_positionX = posX;
		m_sizeX     = size;
		m_sizeY     = size;

		if (getY() + OFFSET_WALL + m_sizeY / 2 < SCR_HEIGHT) m_positionY = posY + OFFSET_WALL;
		else 	                                             m_positionY = posY;

		if (direcctionVelocity) m_velocityX = -VELOCITY / SCR_FPS;
		else                    m_velocityX = VELOCITY / SCR_FPS;

		m_velocityY = VELOCITY / SCR_FPS;
		m_sprite.setSize(size, size);
		m_sprite.setPosition(m_positionX, m_positionY);
	}

	m_aceleration = acceletation;
	m_sprite.init("data/Entity/bubble.png");
	globalGame.m_graphicMotor.m_listSprites.emplace_back(m_sprite);
}
void Bubble::update()
{

	m_positionX += m_velocityX;
	m_positionY += m_velocityY;

	if (m_positionX >= SCR_WIDTH - m_sizeX / 2  || m_positionX <= m_sizeX / 2)         m_velocityX = -m_velocityX;
	if (m_positionY >= SCR_HEIGHT - m_sizeX / 2 || m_positionY <= m_sizeX / 2 + FLOOR) m_velocityY = -m_velocityY + m_aceleration;
	m_velocityY -= m_aceleration;
	
	if (m_positionY + m_sizeY / 2 > SCR_HEIGHT) m_positionY -= abs(m_velocityY);
	
	m_sprite.setPosition(m_positionX, m_positionY);
	globalGame.m_graphicMotor.m_listSprites.emplace_back(m_sprite);
}

