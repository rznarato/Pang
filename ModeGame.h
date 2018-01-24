#ifndef _MODEGAME_H
#define _MODEGAME_H

#include "Global.h"
#include "Game.h"
#include "ModeApplication.h"

class ModeGame : public ModeApplication
{
  int id = ModeApplication::Mode::Mode_Game;
public:
	ModeGame ();
	~ModeGame();
	virtual void logic    ();
	virtual void input    ();
	virtual void renderer ();
	virtual int  getId    ();
};
#endif
