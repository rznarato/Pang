#include "stdafx.h"
#include "ModeNext.h"
#include "sys.h"
#include "ModeApplication.h"
#include "ModeGame.h"
#include "ManagerApp.h"
#include "Global.h"
#include "sys_win.h"
#include "core.h"
ModeNext::ModeNext()
{
	m_next.setPosition (150, 75);
	m_next.setSize     (250, 60);
	m_menu.setPosition (500, 75);
	m_menu.setSize     (250, 60);
	m_win.setPosition  (320, 550);
	m_win.setSize      (400, 150);
	m_clicked = false;
	m_buttons = false;
	m_win.init("data/StaticMenu/win.png");

	if (globalIdLanguage == English)
	{
		m_langLanguages = "English";
		m_ruthWin  = "data/Languages/" + m_langLanguages + "/win.png";
		m_ruthNext = "data/Languages/" + m_langLanguages + "/buttonNext.png";
		m_ruthMenu = "data/Languages/" + m_langLanguages + "/buttonMenu.png";
	}
	if (globalIdLanguage == Spanish)
	{
		m_langLanguages = "Spanish";
		m_ruthWin  = "data/Languages/" + m_langLanguages + "/win.png";
		m_ruthNext = "data/Languages/" + m_langLanguages + "/buttonNext.png";
		m_ruthMenu = "data/Languages/" + m_langLanguages + "/buttonMenu.png";
	}

	m_next.init(m_ruthNext.c_str());
	m_menu.init(m_ruthMenu.c_str());
	m_win.init (m_ruthWin.c_str());

}
void ModeNext::logic()
{
	m_mousePos = SYS_MousePos();
	OverLapped(&m_next, m_mousePos, 1.2);
	OverLapped(&m_menu, m_mousePos, 1.2);
	if (m_clicked)
	{
		if (OverLapped(&m_next, m_click, 1.2))
		{
			globalLevel++;
			ModeApplication *gameMod = new ModeGame();
			globalManager.wantedChange(gameMod);
		
		}
		if (OverLapped(&m_menu, m_click, 1.2))
		{
			ModeApplication *gameMod = new ModeStart();
			globalManager.wantedChange(gameMod);
			SYS_Sleep(100);
		}
	}
	if (m_win.getY() > 300) m_win.setPosition(m_win.getX(), m_win.getY() - 5);
	else                          m_buttons = true;


};
void ModeNext::input()
{
	if (SYS_KeyPressed(SYS_MB_LEFT))
	{
		m_click = SYS_MousePos();
		m_clicked = true;

	}
}
void ModeNext::renderer()
{
	globalGame.rendererGame();
	CORE_RenderCenteredSprite({ m_win.getX(), m_win.getY() }, { m_win.getSizeX(),m_win.getSizeY() }, m_win.getTexture());
	if (m_buttons)
	{
		CORE_RenderCenteredSprite({ m_next.getX(), m_next.getY() }, { m_next.getSizeX(),m_next.getSizeY() }, m_next.getTexture());
		CORE_RenderCenteredSprite({ m_menu.getX(), m_menu.getY() }, { m_menu.getSizeX(),m_menu.getSizeY() }, m_menu.getTexture());
	}


};
int ModeNext::getId()
{
	return id;
}
ModeNext::~ModeNext()
{
}

