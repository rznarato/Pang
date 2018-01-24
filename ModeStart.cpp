#include "stdafx.h"
#include "ModeStart.h"
#include "ModeApplication.h"
#include "ModeGame.h"
#include "ManagerApp.h"
#include "Global.h"
#include "core.h"
#include "sys_win.h"

int globalIdLanguage = 0;

ModeStart::ModeStart()
{
	m_start.setPosition  (150, 75);
	m_start.setSize      (250, 60);
	m_exit.setPosition   (500, 75);
	m_exit.setSize       (250, 60);
	m_pang.setPosition   (WORLD_WIDTH / 2, WORLD_HEIGHT / 2);
	m_pang.setSize       (WORLD_WIDTH    , WORLD_HEIGHT    );
	m_spFlag.setPosition (375, 175);
	m_spFlag.setSize     (100, 60);
	m_fond.setSize       (105, 60);
	m_enFlag.setPosition (250, 175);
	m_enFlag.setSize     (100, 60);
	m_clicked   = false;
	globalLevel = 1;

	if (globalIdLanguage == English)
	{
		m_langLanguages = "English";
		m_ruthStart     = "data/Languages/" + m_langLanguages + "/buttonStart.png";
		m_ruthExit      = "data/Languages/" + m_langLanguages + "/buttonExit.png";
		m_fond.setPosition(250, 175);
		
	}
	if (globalIdLanguage == Spanish)
	{
		m_langLanguages = "Spanish";
		m_ruthStart     = "data/Languages/" + m_langLanguages + "/buttonStart.png";
		m_ruthExit      = "data/Languages/" + m_langLanguages + "/buttonExit.png";
		m_fond.setPosition(375, 175);
	}
}
int ModeStart::getId()
{
	return id;
};
void ModeStart::logic()
{
	m_mousePos = SYS_MousePos();
	OverLapped(&m_start,  m_mousePos, 1.2);
	OverLapped(&m_exit,   m_mousePos, 1.2);
	OverLapped(&m_fond,   m_mousePos, 1.2);
	OverLapped(&m_spFlag, m_mousePos, 1.2);
	OverLapped(&m_enFlag, m_mousePos, 1.2);
	
	if (m_clicked)
	{
		if (OverLapped(&m_start, m_click, 1.2))
		{
			ModeApplication *gameMod = new ModeGame();
			globalManager.wantedChange(gameMod);
			return;
		}
		if (OverLapped(&m_exit, m_click, 1.2)) SYS_Exit();
		if (OverLapped(&m_spFlag, m_click, 1.2))
		{
			m_langLanguages = "Spanish";
			globalIdLanguage = Spanish;
			m_fond.setPosition(375, 175);
		}
		if (OverLapped(&m_enFlag, m_click, 1.2))
		{
			m_langLanguages  = "English";
			globalIdLanguage = English;
			m_fond.setPosition(250, 175);
		}
		m_ruthStart = "data/Languages/" + m_langLanguages + "/buttonStart.png";
		m_ruthExit  = "data/Languages/" + m_langLanguages + "/buttonExit.png";
		m_clicked = false;
	}
};
void ModeStart::input()
{
	if (SYS_KeyPressed(SYS_MB_LEFT))
	{
		m_click   = SYS_MousePos();
		m_clicked = true;
	}
};
void ModeStart::renderer()
{
	m_pang.init("data/StaticMenu/pang.png");
	CORE_RenderCenteredSprite({ m_pang.getX(), m_pang.getY() }, { m_pang.getSizeX(),m_pang.getSizeY() }, m_pang.getTexture());
	m_fond.init("data/StaticMenu/fond.png");
	CORE_RenderCenteredSprite({ m_fond.getX(), m_fond.getY() }, { m_fond.getSizeX(),m_fond.getSizeY() }, m_fond.getTexture());
	m_spFlag.init("data/StaticMenu/spFlag.png");
	CORE_RenderCenteredSprite({ m_spFlag.getX(), m_spFlag.getY() }, { m_spFlag.getSizeX(),m_spFlag.getSizeY() }, m_spFlag.getTexture());
	m_enFlag.init("data/StaticMenu/egFlag.png");
	CORE_RenderCenteredSprite({ m_enFlag.getX(), m_enFlag.getY() }, { m_enFlag.getSizeX(),m_enFlag.getSizeY() }, m_enFlag.getTexture());
	m_start.init(m_ruthStart.c_str());
	CORE_RenderCenteredSprite({ m_start.getX(), m_start.getY() }, { m_start.getSizeX(),m_start.getSizeY() }, m_start.getTexture());
	m_exit.init(m_ruthExit.c_str());
	CORE_RenderCenteredSprite({ m_exit.getX(), m_exit.getY() }, { m_exit.getSizeX(),m_exit.getSizeY() }, m_exit.getTexture());
};

ModeStart::~ModeStart(){}
