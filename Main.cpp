#include "stdafx.h"
#include "sys.h"
#include "core.h"
#include "ManagerApp.h"
#include "Game.h"
#include "Global.h"

//-----------------------------------------------------------------------------
ManagerApp globalManager;
int        globalLevel = 1;
//-----------------------------------------------------------------------------
int Main(void)
{
  // Set up rendering
	glViewport     (0, 0, SCR_WIDTH, SCR_HEIGHT); // Sets up clipping
	glClearColor   (0.0f, 0.1f, 0.3f, 0.0f);
	glMatrixMode   (GL_PROJECTION);
	glLoadIdentity ();
	glOrtho        (0.0, SCR_WIDTH, 0.0, SCR_HEIGHT, 0.0, 1.0);
	glEnable       (GL_TEXTURE_2D);
	glEnable       (GL_BLEND);
	glBlendFunc    (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


  while (!SYS_GottaQuit())
  {
	  glClear(GL_COLOR_BUFFER_BIT);

	  globalManager.controlModes();
	  globalManager.logic();
	  globalManager.input();
	  globalManager.renderer();
	  SYS_Sleep(5);
      SYS_Show();
      SYS_Pump();
  }
  return 0;
}