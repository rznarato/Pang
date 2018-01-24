#include "stdafx.h"
#include "Sprite.h"
#include "core.h"
#include "ResourceManager.h"

Sprite::Sprite()
{
	m_scale         = 1;
	m_positionX     = 0;
	m_positionY     = 0;
	m_sizeX         = 0;
	m_sizeY         = 0;
	m_originalSizeX = 0;
	m_originalSizeY = 0;
}

Sprite::Sprite(float positionX, float positionY, float sizeX, float sizeY)
{
	m_positionX     = positionX;
	m_positionY     = positionY;
	m_sizeX         = sizeX;
	m_sizeY         = sizeY;
	m_originalSizeX = sizeX;
	m_originalSizeY = sizeY;
}
void Sprite::init(const char *texture)
{
	m_texture = ResourceManager::Instance().LoadImages(texture, true);
}

//Set
void Sprite::setPosition(float positionX, float positionY)
{
	m_positionX = positionX;
	m_positionY = positionY;
}
void Sprite::setSize(float sizeX, float sizeY)
{
	m_sizeX         = sizeX;
	m_sizeY         = sizeY;
	m_originalSizeX = sizeX;
	m_originalSizeY = sizeY;
}

void Sprite::setTexture(GLuint texture)
{
	m_texture = texture;
}
void Sprite::setScale(float scale)
{
	m_scale = scale;
	m_sizeX = m_originalSizeX * scale;
	m_sizeY = m_originalSizeY * scale;
}
//Get 
float  Sprite::getX()       { return m_positionX; }
float  Sprite::getY()       { return m_positionY; }
float  Sprite::getSizeX()   { return m_sizeX; }
float  Sprite::getSizeY()   { return m_sizeY; }
float  Sprite::getScale()   { return m_sizeY; }
GLuint Sprite::getTexture() { return m_texture; }