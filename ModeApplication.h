#ifndef _MODEAPP_H
#define _MODEAPP_H
#include "Sprite.h"
#include "sys.h"

class ModeApplication
{
	
public:
	int id;
	enum Mode
	{
		Mode_Game,
		Mode_GameOver,
		Mode_Start,
		Mode_Next,
		Mode_Pause,
	};
	ModeApplication         ();
	virtual void logic      ();
	virtual void input      ();
	virtual void renderer   ();
    virtual int  getId      ();

	bool OverLapped (Sprite *sprite, ivec2 m_mousePos, float scale);
};
#endif


