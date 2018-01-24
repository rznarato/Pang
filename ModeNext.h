#ifndef _MODENEXT_H
#define _MODENEXT_H
#include "ModeApplication.h"
#include "ManagerApp.h"
class ModeNext : public ModeApplication
{
	int id = ModeApplication::Mode::Mode_Next;
	Sprite m_next;
	Sprite m_menu;
	Sprite m_win;
	ivec2  m_mousePos;
	ivec2  m_click;
	bool   m_clicked;
	bool   m_buttons;
	string m_ruthNext;
	string m_ruthWin;
	string m_ruthMenu;
	string m_langLanguages;

public:
	ModeNext();
	virtual void logic();
	virtual void input();
	virtual void renderer();
	virtual int getId();
	~ModeNext();
};

#endif