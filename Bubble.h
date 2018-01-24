#ifndef _BUBBLE_H
#define _BUBBLE_H
#include "Entity.h"

class Bubble : public Entity
{
	
public:
	Bubble();
	void update();
	void init(float size, float acceletation,bool newBubble = 0, float posX = 0 , float posY = 0, bool direcctionVelocity = 0);
private:
	float  m_aceleration;
};
#endif