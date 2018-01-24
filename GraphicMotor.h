#ifndef _GRAPHIC_MOTOR_H
#define _GRAPHIC_MOTOR_H
#include <vector>
#include "Sprite.h"
#include "core.h"
#include "stdafx.h"

using namespace std;

class GraphicMotor
{
public:
	vector<Sprite> m_listSprites;
	vector<Sprite> m_staticSprites;
	bool           m_drawScore;
	vec2           m_scorePos;
	string         m_score;
	string         m_totalScore;

	GraphicMotor  ();
	void update   ();
	~GraphicMotor ();
private:

};

#endif