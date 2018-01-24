#include "stdafx.h"
#include "ModeGameOver.h"
#include "ModeGame.h"
#include "ModeStart.h"
#include "ManagerApp.h"
#include "Global.h"
#include "core.h"
#include "sys.h"

ModeGameOver::ModeGameOver()
{
	m_restart.setPosition (150, 75);
	m_restart.setSize     (250, 60);
	m_menu.setPosition    (500, 75);
	m_menu.setSize        (250, 60);
	m_over.setPosition    (320, 550);
	m_over.setSize        (500, 150);
	m_clicked = false;
	m_buttons = false;
	
	if (globalIdLanguage == English)
	{
		m_langLanguages = "English";
		m_ruthRestart   = "data/Languages/" + m_langLanguages + "/buttonRestart.png";
		m_ruthOver      = "data/Languages/" + m_langLanguages + "/over.png";
		m_ruthMenu      = "data/Languages/" + m_langLanguages + "/buttonMenu.png";
	}
	if (globalIdLanguage == Spanish)
	{
		m_langLanguages = "Spanish";
		m_ruthOver      = "data/Languages/" + m_langLanguages + "/over.png";
		m_ruthRestart   = "data/Languages/" + m_langLanguages + "/buttonRestart.png";
		m_ruthMenu      = "data/Languages/" + m_langLanguages + "/buttonMenu.png";
	}

	m_restart.init(m_ruthRestart.c_str());
	m_menu.init(m_ruthMenu.c_str());
	m_over.init(m_ruthOver.c_str());
}

void ModeGameOver::logic()
{
	m_mousePos = SYS_MousePos();
	OverLapped(&m_restart, m_mousePos, 1.2);
	OverLapped(&m_menu,    m_mousePos, 1.2);
	if (m_clicked)
	{
		if (OverLapped(&m_restart, m_click, 1.2))
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
		m_clicked = false;
	}
	if (m_over.getY() > 300) m_over.setPosition(m_over.getX(), m_over.getY() - 2);
	else                          m_buttons = true;
	

};

void ModeGameOver::input()
{
	if (SYS_KeyPressed(SYS_MB_LEFT))
	{
		m_click = SYS_MousePos();
		m_clicked = true;
	}
}

void ModeGameOver::renderer()
{
	globalGame.logicGame();
	globalGame.rendererGame();
	CORE_RenderCenteredSprite({ m_over.getX(), m_over.getY() }, { m_over.getSizeX(),m_over.getSizeY() }, m_over.getTexture());
	if (m_buttons)
	{
		CORE_RenderCenteredSprite({ m_restart.getX(), m_restart.getY() }, { m_restart.getSizeX(),m_restart.getSizeY() }, m_restart.getTexture());
		CORE_RenderCenteredSprite({ m_menu.getX(), m_menu.getY() }, { m_menu.getSizeX(),m_menu.getSizeY() }, m_menu.getTexture());
	}
};
int ModeGameOver::getId() { return id; }

ModeGameOver::~ModeGameOver(){}
