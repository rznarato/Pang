#ifndef _PLAYER_H
#define _PLAYER_H
#include "Entity.h"
#include <vector>
using namespace std;

class Player : public Entity
{
public:

	Player();
	void         setRight   (bool right);
	void         setLeft    (bool left);
	void         setShoot   (bool shoot);
	void         setPressed (bool pressed);
	void         setKilled  (bool killed);
	virtual void init       ();
	virtual void update     ();
	
private:
	Sprite m_rightSprite;
	Sprite m_leftSprite;
	Sprite m_rightSprite2;
	Sprite m_leftSprite2;
	Sprite m_rightSprite3;
	Sprite m_leftSprite3;
	Sprite m_stoppedSprite;
	Sprite m_stoppedSprite2;
	Sprite m_shootSprite;
	Sprite m_shootSprite2;
	Sprite m_kill;
	Sprite m_kill2;
	vector <Sprite> m_stopAnimed;
	vector <Sprite> m_RightAnimed;
	vector <Sprite> m_LeftAnimed;
	vector <Sprite> m_ShootAnimed;
	bool m_right;
	bool m_left;
	bool m_stopped;
	bool m_shoot;
	bool m_killed;
	bool m_pressed;
	int  m_contFrame;

	void changeSprite();
};

#endif