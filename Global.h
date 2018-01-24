#ifndef _GLOBAL_H
#define _GLOBAL_H

class ManagerApp;
class Game;

extern ManagerApp globalManager;
extern Game       globalGame;
extern int        globalLevel;
extern int        globalIdLanguage;

enum Language
{
	English,
	Spanish
};
#endif