#ifndef _MANAGERAPP_H
#define _MANAGERAPP_H
#include "ModeGame.h"
#include "ModeGameOver.h"
#include "ModeApplication.h"
#include "ModeStart.h"
using namespace std;
class ManagerApp
{
	ModeApplication         *m_currentState;
    ModeApplication         *m_wantedState;
	ModeApplication         *m_modeStart;
	ModeApplication         *m_game;

public:
	ManagerApp        ();
	void wantedChange (ModeApplication *wantedState);
	void controlModes ();
	void logic        ();
	void input        ();
	void renderer     ();
	~ManagerApp       ();
};

#endif