#include "stdafx.h"
#include "sys_win.h"
#include "core.h"
#include "sys.h"
#include "ModePause.h"
#include "ModeApplication.h"
#include "ModeGame.h"
#include "ManagerApp.h"
#include "Global.h"

ModePause::ModePause()
{
	m_resume.setPosition  (150, 75);
	m_resume.setSize      (250, 60);
	m_menu.setPosition    (500, 75);
	m_menu.setSize        (250, 60);
	m_pause.setPosition   (320, 550);
	m_pause.setSize       (500, 150);
	m_control.setPosition (320, 200);
	m_control.setSize     (250, 125);
	m_clicked = false;
	m_buttons = false;
	
	if (globalIdLanguage == English)
	{
		m_langLanguages = "English";
		m_ruthPause     = "data/Languages/" + m_langLanguages + "/pause.png";
		m_ruthResume    = "data/Languages/" + m_langLanguages + "/buttonResume.png";
		m_ruthMenu      = "data/Languages/" + m_langLanguages + "/buttonMenu.png";
	}
	if (globalIdLanguage == Spanish)
	{
		m_langLanguages = "Spanish";
		m_ruthPause     = "data/Languages/" + m_langLanguages + "/pause.png";
		m_ruthResume    = "data/Languages/" + m_langLanguages + "/buttonResume.png";
		m_ruthMenu      = "data/Languages/" + m_langLanguages + "/buttonMenu.png";
	}
	m_resume.init(m_ruthResume.c_str());
	m_menu.init  (m_ruthMenu.c_str());
	m_pause.init (m_ruthPause.c_str()); 
	m_control.init("data/StaticMenu/controls1.png");
}

void ModePause::logic()
{
	m_mousePos = SYS_MousePos();
	OverLapped(&m_resume, m_mousePos, 1.2);
	OverLapped(&m_menu,   m_mousePos, 1.2);
	if (m_clicked)
	{
		if (OverLapped(&m_resume, m_click, 1.2))
		{
			ModeApplication *gameMod = new ModeGame();
			globalManager.wantedChange(gameMod);
			return;
		}
		if (OverLapped(&m_menu, m_click, 1.2))
		{
			ModeApplication *gameMod = new ModeStart();
			globalManager.wantedChange(gameMod);
			SYS_Sleep(100);
		}
	}
	if (m_pause.getY() > 350) m_pause.setPosition(m_pause.getX(), m_pause.getY() - 5);
	else                          m_buttons = true;

};

void ModePause::input()
{
	if (SYS_KeyPressed(SYS_MB_LEFT))
	{
		m_click   = SYS_MousePos();
		m_clicked = true;
	}
}

void ModePause::renderer()
{
	globalGame.rendererGame();
	CORE_RenderCenteredSprite({ m_pause.getX(), m_pause.getY() }, { m_pause.getSizeX(),m_pause.getSizeY() }, m_pause.getTexture());
	if (m_buttons)
	{
		CORE_RenderCenteredSprite({ m_resume.getX(), m_resume.getY() }, { m_resume.getSizeX(),m_resume.getSizeY() }, m_resume.getTexture());
		CORE_RenderCenteredSprite({ m_menu.getX(), m_menu.getY() }, { m_menu.getSizeX(),m_menu.getSizeY() }, m_menu.getTexture());
		CORE_RenderCenteredSprite({ m_control.getX(), m_control.getY() }, { m_control.getSizeX(),m_control.getSizeY() }, m_control.getTexture());

	}
};

int ModePause::getId() 
{ 
	return id; 
};

ModePause::~ModePause(){}
