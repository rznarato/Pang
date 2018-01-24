#ifndef _MODESTART_H
#define _MODESTART_H
#include "ManagerApp.h"
#include "Sprite.h"
class ModeStart : public ModeApplication
{
	int id = ModeApplication::Mode::Mode_Start;
	Sprite m_start;
	Sprite m_exit;
	Sprite m_menu;
	Sprite m_pang;
	Sprite m_spFlag;
	Sprite m_enFlag;
	Sprite m_fond;
	ivec2  m_mousePos;
	ivec2  m_click;
	bool   m_clicked;
	string m_ruthStart;
	string m_ruthExit;
	string m_langLanguages;

public:
	ModeStart();
	~ModeStart();
	virtual void logic();
	virtual void input();
	virtual void renderer();
	virtual int  getId();

};

#endif