#ifndef _MODEOVER_H
#define _MODEOVER_H
#include "ModeApplication.h"
#include "ManagerApp.h"
class ModeGameOver : public ModeApplication
{
	int id = ModeApplication::Mode::Mode_GameOver;
	Sprite m_restart;
	Sprite m_menu;
	Sprite m_over;
	ivec2  m_mousePos;
	ivec2  m_click;
	bool   m_clicked;
	bool   m_buttons;
	string m_ruthRestart;
	string m_ruthMenu;
	string m_ruthOver;
	string m_langLanguages;
public:

	ModeGameOver();
	virtual void logic    ();
	virtual void input    ();
	virtual void renderer ();
	virtual int getId     ();
	~ModeGameOver();
};

#endif