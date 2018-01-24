#ifndef _GAME_H
#define _GAME_H
#include "World.h"
#include "Input.h"
#include "Sprite.h"
#include "GraphicMotor.h"
#include <vector>
using namespace std;

class Game
{
public:
	World        m_world;
	Input        m_input;
	GraphicMotor m_graphicMotor;

	Game              ();
	void logicGame    ();
	void inputGame    ();
	void rendererGame ();
	void init         ();
private:
	const char * m_landscape;
	const char * m_floor;
};

#endif
