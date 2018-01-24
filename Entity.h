#ifndef ENTITY_H
#define ENTITY_H
#include "Sprite.h"

class Entity
{
	
public:
	enum Type
	{
		tEntity,
		tPlayer,
		tBubble,
		tShiruken,
		tBlock,
	};
	double  getX         ();
	double  getY         ();
	double  getSizeX     ();
	double  getSizeY     ();
	double  getVelocityX ();
	double  getVelocityY ();
	bool    getActivated ();
	Sprite  getSprite    ();
	int     getType      ();
	void    setX         (double x);
	void    setY         (double y);
	void    setVelocityX (double x);
	void    setVelocityY (double y);
	void    setActivated (bool activated);
	
	virtual void init();
	virtual void update();
	Entity(Type t) :m_type(t) {};

protected:
	int     m_type = tEntity;
	double  m_positionX;
	double  m_positionY;
	double  m_sizeX;
	double  m_sizeY;
	double  m_velocityX;
	double  m_velocityY;
	bool    m_activated;
	Sprite  m_sprite;
};

#endif