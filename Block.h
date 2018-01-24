#ifndef _BLOCK_H
#define _BLOCK_H
#include "Entity.h"

class Block : public Entity
{
public:
	 Block       ();
	 void update ();
	 void init   (float posX, float posY, float sizeX, float sizeY, const char * fileName);
};

#endif