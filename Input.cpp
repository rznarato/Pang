#include "stdafx.h"
#include "Input.h"
#include "ModePause.h"
#include "ManagerApp.h"
#include "ModeApplication.h"
#include "Game.h"
#include "Global.h"

Input::Input()
{
	m_pressed = false;
}
void Input::update()
{
	if (SYS_KeyPressed(SYS_KEY_D)) reinterpret_cast<Player*>(globalGame.m_world.m_player)->setRight(true);

	if (SYS_KeyPressed(SYS_KEY_A)) reinterpret_cast<Player*>(globalGame.m_world.m_player)->setLeft (true);

	//Generate Shuriken;
	if (SYS_KeyPressed(SYS_MB_LEFT) && m_pressed == true)
	{
		reinterpret_cast<Player*>(globalGame.m_world.m_player)->setShoot(true);
		globalGame.m_world.shotShuriken();
	}
	reinterpret_cast<Player*>(globalGame.m_world.m_player)->setPressed( SYS_KeyPressed(SYS_MB_LEFT));
	
	if (!SYS_KeyPressed(SYS_MB_LEFT)) m_pressed = true;
	else m_pressed = false;
	//Pause
	if (SYS_KeyPressed(SYS_KEY_ESC))
	{
		globalGame.m_graphicMotor.m_drawScore = false;
		ModeApplication *pause = new ModePause();
		globalManager.wantedChange(pause);
	}
}

Input::~Input()
{
}
