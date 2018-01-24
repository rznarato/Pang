#include "stdafx.h"
#include "ModeApplication.h"
#include "ManagerApp.h"
#include "ModeGameOver.h"
#include "ModeNext.h"
#include "ModeStart.h"
#include "World.h"
#include "Game.h"
#include "Block.h"
#include "Global.h"
#include "font.h"
#include <algorithm>

World::World()
{	
	m_Init              = false;
	m_bubbleDivided     = false;
	m_sizeBubbleDivided = 0;
	m_positionX         = 0;
	m_positionY         = 0;
	m_bubbles           = 0; 
	m_seconds           = 0;
	m_ScoreBubble       = SCORE;
	m_totalScore        = 0;
}

void World::update()
{
	if (!m_Init)
	{
		/*/ Start Player /*/
		globalGame.init();
		m_player = new Player;
		m_entities.emplace_back(m_player);
		m_player->init();
		/*/ Start Blocks /*/
		for (size_t i = 0; i < m_numberStartBlocks; i++)
		{
			m_block = new Block;
			reinterpret_cast<Block*>(globalGame.m_world.m_block)->init(m_blocksLevel[i].x, m_blocksLevel[i].y, m_blocksLevel[i].sizeX, m_blocksLevel[i].sizeY, "data/Entity/blockWood.png");
			m_entities.emplace_back(m_block);
		}
		/*/ Start Bubbles /*/
		for (size_t i = 0; i < m_numberStartBubbles; i++)
		{
			m_bubble = new Bubble;
			m_entities.emplace_back(m_bubble);
			reinterpret_cast<Bubble*>(globalGame.m_world.m_bubble)->init(START_SIZE , m_acceleration);
		}
		m_bubbles = m_numberStartBubbles;
		m_Init = true;
	}
	/*/ Update + Collider + New Bubble + Delete Dntities /*/
	for (int i = 0; i < m_entities.size(); i++) m_entities[i]->update();
	Collider();
	if (m_bubbleDivided) CreateNewBubble();
	DeleteEntities();
	
	/*/ Score will be some time in the screen /*/
	if (m_seconds == 30) globalGame.m_graphicMotor.m_drawScore = false; 
   	m_seconds++;
	
	/*/ Win /*/
	if (m_bubbles == 0)
	{
		globalGame.m_graphicMotor.m_drawScore = false;
		ModeApplication *next = new ModeNext();
		globalManager.wantedChange(next);
	}

	/*/ Update score /*/
	globalGame.m_graphicMotor.m_totalScore = to_string(m_totalScore); 
}

void World::Collider()
{
	
	for (int i = 0; i < m_entities.size(); i++)
	{
		if (m_entities[i]->getType() == (Entity::tShiruken) && m_entities[i]->getY()>WORLD_HEIGHT) m_deleteEntity.emplace_back(i);
		if (m_entities[i]->getType() == (Entity::tBubble))
		{
			for (int k = 0; k < m_entities.size(); k++)
			{
				if (m_entities[k]->getType() == (Entity::tShiruken) || m_entities[k]->getType() == (Entity::tPlayer))
				{
					if (Distance(m_entities[i], m_entities[k]))
					{
						if (m_entities[k]->getType() == (Entity::tShiruken) && m_entities[k]->getActivated())
						{/*/ Collision Shuriken and Bubble /*/
							
								m_deleteEntity.emplace_back(k);
								m_deleteEntity.emplace_back(i);
								m_bubbles--;
								/*/ Upadate Scores/*/
								globalGame.m_graphicMotor.m_drawScore = true;
								globalGame.m_graphicMotor.m_scorePos  = { m_entities[i]->getX(),m_entities[i]->getY() };
								globalGame.m_graphicMotor.m_score     = to_string(m_ScoreBubble);
								m_seconds                             = 0;
								m_totalScore                         += m_ScoreBubble;
								
								if (m_entities[i]->getSizeX() > BUBBLE_RESIZE)
								{/*/ Divide Bubble/*/
									m_bubbleDivided     = true;
									m_positionX         = m_entities[i]->getX();
									m_positionY         = m_entities[i]->getY();
									m_sizeBubbleDivided = m_entities[i]->getSizeX() ;
									m_bubbles          += 2;
									m_ScoreBubble      += 25;
								}
								m_entities[k]->setActivated (false);
						}
						if (m_entities[k]->getType() == (Entity::tPlayer))
						{/*/ Collision Player and Bubble /*/
							m_deleteEntity.emplace_back(k);
							reinterpret_cast<Player*>(m_player)->setKilled(true);
						}
					}
				}
				if (m_entities[k]->getType() == (Entity::tBlock))
				{/*/ Collision Block and Bubble /*/
					
					if (RectsOverlap(m_entities[i]->getX() - m_entities[i]->getSizeX()  / 2, m_entities[i]->getY() - m_entities[i]->getSizeY() / 2, m_entities[i]->getSizeX() , m_entities[i]->getSizeY() , m_entities[k]->getX() - m_entities[k]->getSizeX()  / 2, m_entities[k]->getY(), m_entities[k]->getSizeX() , 1))
					{
						if (m_entities[i]->getY() >= m_entities[k]->getY()) m_entities[i]->setY(m_entities[i]->getY() + abs(m_entities[i]->getVelocityX()));
						else                                                m_entities[i]->setY(m_entities[i]->getY() - abs(m_entities[i]->getVelocityY()));
						m_entities[i]->setVelocityY(- m_entities[i]->getVelocityY() - m_acceleration);
					}		
				}
			}
		}
	}
}

void World::CreateNewBubble() 
{
		Entity *bubbleFirst  = new Bubble();
		Entity *bubbleSecond = new Bubble();
		reinterpret_cast<Bubble*>(bubbleFirst)->init(m_sizeBubbleDivided  - BUBBLE_RESIZE,  m_acceleration, true, m_positionX, m_positionY, false);
		reinterpret_cast<Bubble*>(bubbleSecond)->init(m_sizeBubbleDivided - BUBBLE_RESIZE,  m_acceleration, true, m_positionX, m_positionY, true);
		m_entities.emplace_back(bubbleFirst);
		m_entities.emplace_back(bubbleSecond);
		m_bubbleDivided = false;
}

/*/ Free the entities from vectors and memory /*/
void World::DeleteEntities()
{
	std::sort(m_deleteEntity.begin(), m_deleteEntity.end());
	for (int i = m_deleteEntity.size()-1; 0 <= i; i--)
	{
		int a = m_deleteEntity[i];
		if (m_entities[m_deleteEntity[i]]->getType() == (Entity::tPlayer)) //change mode Player killed
		{
			ModeApplication *gameOver = new ModeGameOver();
			globalManager.wantedChange(gameOver);
		};
		delete m_entities[m_deleteEntity[i]];
		m_entities.erase(m_entities.begin() + m_deleteEntity[i]);
		globalGame.m_graphicMotor.m_listSprites.erase(globalGame.m_graphicMotor.m_listSprites.begin() + m_deleteEntity[i]);
		if (i == 0) m_deleteEntity.clear();
	}
}

void World::shotShuriken() 
{
	Entity *shuriken = new Shuriken();
	shuriken->setX(m_player->getX());
	shuriken->setY(m_player->getY() + m_player->getSizeX() /2);
	shuriken->init();
	m_entities.emplace_back(shuriken);
}

void World::setAcceleration(float acc)         { m_acceleration = acc; };
void World::setNumberStartBubbles(int bubbles) { m_numberStartBubbles = bubbles; };
void World::setNumberStartBlocks(int blocks)   { m_numberStartBlocks = blocks; };

bool World::Distance(Entity *m_entity1, Entity *m_entity2)
{
	float distance = sqrt(pow((m_entity1->getX() - m_entity2->getX()), 2) + pow((m_entity1->getY() - m_entity2->getY()), 2));
	float radio = m_entity1->getSizeX() / 2.0f + m_entity2->getSizeX() / 2.0f;
	return radio > distance;
}

bool World::RectsOverlap(double x1, double y1, double width1, double height1, double x2, double y2, double width2, double height2) {
	return x1 + width1 >= x2 && x1 <= x2 + width2 && y1 + height1 >= y2 && y1 <= y2 + height2 ;
}
