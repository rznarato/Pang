#include "stdafx.h"
#include "ModeGame.h"
Game globalGame;

ModeGame::ModeGame()
{

}
int ModeGame::getId()
{
	return id;
};
void ModeGame::logic()
{
	globalGame.logicGame();
};
void ModeGame::input()
{
	globalGame.inputGame();
};
void ModeGame::renderer()
{
	globalGame.rendererGame();
};

ModeGame::~ModeGame()
{
}
