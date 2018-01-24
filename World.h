#ifndef _WORLD_H
#define _WORLD_H
#include "Player.h"
#include "Sprite.h"
#include "Shuriken.h"
#include "Bubble.h"
#include "sys.h"
#include <vector>

using namespace std;

class World
{
public:	
	vector <blockData> m_blocksLevel;
	Entity            *m_player;
	void               setAcceleration       ( float acc );
	void               setNumberStartBubbles ( int bubbles );
	void               setNumberStartBlocks  ( int blocks );

	World            ();
	void update      ();
	void shotShuriken();

private:
	bool  m_Init;
	bool  m_bubbleDivided;
	float m_sizeBubbleDivided;
	float m_positionX;
	float m_positionY;
	int   m_bubbles;
	int   m_seconds;
	int   m_ScoreBubble;
	int   m_totalScore;
	float m_acceleration;
	int   m_numberStartBubbles;
	int   m_numberStartBlocks;
	vector <int> m_deleteEntity;
	vector <Entity*>   m_entities;
	Entity *m_bubble;
	Entity *m_block;

	void  Collider();
	void  CreateNewBubble();
	void  DeleteEntities();
	bool  Distance(Entity *m_entity1, Entity *m_entity2);
	bool  RectsOverlap(double x1, double y1, double width1, double height1, double x2, double y2, double width2, double height2);
};

#endif