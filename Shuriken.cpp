#include "stdafx.h"
#include "Game.h"
#include "Global.h"
#include "Shuriken.h"

Shuriken::Shuriken() : Entity(tShiruken)
{
	m_positionX = 0;
	m_positionY = 0;
	m_sizeX     = 0;
	m_sizeY     = 0;
	m_velocityX = 0;
	m_velocityY = 0;
	m_activated = false;
};

void Shuriken::init()
{
	m_sprite.init("data/Entity/shuriken.png");
	m_sprite.setSize(SHURIKEN_SIZE, SHURIKEN_SIZE);
	m_sizeX = SHURIKEN_SIZE;
	m_sizeY = SHURIKEN_SIZE;
	m_sprite.setPosition(m_positionX, m_positionY);
	globalGame.m_graphicMotor.m_listSprites.emplace_back(m_sprite);
	m_activated = true;
}

void Shuriken::update() 
{
	m_positionY += SHURIKEN_VELOCITY / SCR_FPS;
	m_sprite.setPosition(m_positionX, m_positionY);
	globalGame.m_graphicMotor.m_listSprites.emplace_back(m_sprite);
}

