#include "stdafx.h"
#include "ManagerApp.h"

ManagerApp::ManagerApp()
{

	m_modeStart    = new ModeStart();
	m_game         = new ModeGame();
	m_currentState = m_modeStart;
	m_wantedState  = m_modeStart;
}

void ManagerApp::controlModes()
{
	if (m_wantedState->getId() != m_currentState->getId())
	{
		if (m_wantedState->getId() == ModeApplication::Mode_Pause)
		{
			m_game         = m_currentState;
			m_currentState = m_wantedState;
		}
		else if(m_currentState->getId() == ModeApplication::Mode_Pause && m_wantedState->getId() == ModeApplication::Mode_Game)
		{
			delete m_wantedState;
			delete m_currentState;
			m_currentState = m_game;
			m_wantedState  = m_game;
		}
		else
		{
			delete m_currentState;
			m_currentState = m_wantedState;
		}
	}
};

void  ManagerApp::wantedChange(ModeApplication *wanted)
{
	if (wanted->getId() == ModeApplication::Mode_Game && m_currentState->getId() != ModeApplication::Mode_Pause)
	{
		Game newGame;
		globalGame    = newGame;
		m_wantedState = wanted;
		
	}
	else
	{
		m_wantedState = wanted;
	}
}

void ManagerApp::logic()
{
	m_currentState->logic();
}

void ManagerApp::input()
{
	m_currentState->input();
}

void ManagerApp::renderer()
{
	m_currentState->renderer();
}

ManagerApp::~ManagerApp()
{
	delete m_currentState;
}
