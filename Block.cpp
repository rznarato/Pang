#include "stdafx.h"
#include "Block.h"
#include "Game.h"
#include "Global.h"

Block::Block() : Entity(tBlock) 
{
	m_positionX = 0;
	m_positionY = 0;
	m_sizeX     = 0;
	m_sizeY     = 0;
	m_velocityX = 0;
	m_velocityY = 0;
	m_activated = false;
};

void Block::init(float posX, float posY, float sizeX, float sizeY , const char * fileName) 
{
	m_positionX = posX;
	m_positionY = posY;
	m_sizeX     = sizeX;
	m_sizeY     = sizeY;
	m_sprite.init(fileName);
	m_sprite.setSize(m_sizeX, m_sizeY);
	m_sprite.setPosition(m_positionX, m_positionY);

}
void Block::update() 
{
	globalGame.m_graphicMotor.m_listSprites.emplace_back(m_sprite);
}

