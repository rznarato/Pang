#ifndef _INPUT_H
#define _INPUT_H
#include "sys.h"
class Input
{
	bool m_pressed;
public:
	Input();
	void update();
	~Input();
};

#endif