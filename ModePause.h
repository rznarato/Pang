#ifndef _MODEPAUSE_H
#define _MODEPAUSE_H
#include "ModeApplication.h"
#include "ModeGame.h"
class ModePause : public ModeApplication
{
	int id = ModeApplication::Mode::Mode_Pause;
	Sprite m_resume;
	Sprite m_menu;
	Sprite m_pause;
	Sprite m_control;
	ivec2  m_mousePos;
	ivec2  m_click;
	bool   m_clicked;
	bool   m_buttons;
	string m_ruthMenu;
	string m_ruthPause;
	string m_ruthResume;
	string m_langLanguages;

public:
	ModeGame m_gameMode;
	ModePause();
	virtual void logic();
	virtual void input();
	virtual void renderer();
	virtual int  getId();
	~ModePause();
};

#endif
