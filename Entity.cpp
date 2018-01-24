#include "stdafx.h"
#include "Entity.h"
#include "Game.h"
#include "Global.h"
void    Entity::init()         {}
void    Entity::update()       {}
//Get & Set
int     Entity::getType()      { return m_type; }
double  Entity::getX()         { return m_positionX; }
double  Entity::getY()         { return m_positionY; }
double  Entity::getSizeX()     { return m_sizeX; }
double  Entity::getSizeY()     { return m_sizeY; }
double  Entity::getVelocityX() { return m_velocityX; }
double  Entity::getVelocityY() { return m_velocityY; }
bool    Entity::getActivated() { return m_activated; }
Sprite  Entity::getSprite()    { return m_sprite; }

void    Entity::setActivated(bool activated) { m_activated = activated; }
void    Entity::setX        (double x)       { m_positionX = x; }
void    Entity::setY        (double y)       { m_positionY = y; }
void    Entity::setVelocityX(double x)       { m_velocityX = x; }
void    Entity::setVelocityY(double y)       { m_velocityY = y; }