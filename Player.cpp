#include "stdafx.h"
#include "Player.h"
#include "Game.h"
#include "Global.h"

Player::Player() : Entity(tPlayer)
{
	m_positionX = 0;
	m_positionY = 0;
	m_sizeX     = 0;
	m_sizeY     = 0;
	m_velocityX = 0;
	m_velocityY = 0;
	m_activated = false;
};

void Player::init()
{
	m_rightSprite.init    ("data/Entity/R1.png");
	m_leftSprite.init     ("data/Entity/L1.png");
	m_rightSprite2.init   ("data/Entity/R2.png");
	m_leftSprite2.init    ("data/Entity/L2.png");
	m_rightSprite3.init   ("data/Entity/R3.png");
	m_leftSprite3.init    ("data/Entity/L3.png");
	m_stoppedSprite.init  ("data/Entity/stopped.png");
	m_stoppedSprite2.init ("data/Entity/stopped2.png");
	m_shootSprite.init    ("data/Entity/playerL.png");
	m_shootSprite2.init   ("data/Entity/playerR.png");
	m_kill.init           ("data/Entity/kill.png");
	m_kill2.init          ("data/Entity/kill2.png");
	m_velocityX = VELOCITY / SCR_FPS;
	m_velocityY = VELOCITY / SCR_FPS;
	m_positionX = PLAYER_X;
	m_positionY = PLAYER_Y;
	m_sizeX     = PLAYER_SIZE;
	m_sizeY     = PLAYER_SIZE;
	m_right     = false;
	m_left      = false;
	m_shoot     = false;
	m_killed    = false;
	m_pressed   = false;
	m_sprite.setSize(m_sizeX, m_sizeY);
	m_sprite.setPosition(m_positionX, m_positionY);
	
	//Animation Move
	int change     = 1;
	int changeMove = 0;
	for (size_t i = 0; i < SCR_FPS; i++)
	{//Animation of player stopped
		if (i % 10 == 0) change = -change;
		if (change == 1) m_stopAnimed.emplace_back(m_stoppedSprite);
		else             m_stopAnimed.emplace_back(m_stoppedSprite2);

	}
	for (size_t i = 0; i < SCR_FPS; i++)
	{//Animation of player moved

		if (i % 6 == 0) changeMove++;         // Change a sprite each 6 frames
		if (changeMove % 3 == 0) changeMove=0;//3 frames of movement
		if (changeMove == 0)
		{
			m_RightAnimed.emplace_back(m_rightSprite);
			m_LeftAnimed.emplace_back(m_leftSprite);
		}
		if (changeMove == 1) 
		{
			m_RightAnimed.emplace_back(m_rightSprite2);
			m_LeftAnimed.emplace_back(m_leftSprite2);
		}
		if (changeMove == 2) 
		{
			m_RightAnimed.emplace_back(m_rightSprite3);
			m_LeftAnimed.emplace_back(m_leftSprite3);
		}
	}
	m_contFrame = 0;
}

void Player::update()
{
	if (m_contFrame == SCR_FPS) m_contFrame = 0;//Restart looping of frames
	if (!m_right && !m_left && !m_pressed)
	{
		m_stopped = true;
		changeSprite();
	}
	if (m_right)
	{
		if (m_positionX <= WORLD_WIDTH - m_sizeX/2.f)
		{
			m_positionX += m_velocityX;
		}
		m_sprite.setPosition(m_positionX, m_positionY);
		m_stopped = false;
		changeSprite();
		m_right = false;
		
	}
	if (m_left)
	{
		if (0 <= m_positionX - m_sizeX/ 2.f)
		{
			m_positionX -= m_velocityX;
		}
		m_sprite.setPosition(m_positionX, m_positionY);
		m_stopped = false;
		changeSprite();
		m_left = false;
	}

	if (m_shoot)
	{
		m_stopped = false;
		changeSprite();
		m_shoot = false;
	}

	if (m_killed)
	{
		m_stopped = false;
		changeSprite();
		m_killed  = false;
	}

	globalGame.m_graphicMotor.m_listSprites.emplace_back(m_sprite);

}

void Player::changeSprite()
{
	if (m_right)
	{
		m_sprite.setTexture(m_RightAnimed[m_contFrame].getTexture());
		m_contFrame++;
	}
	if (m_left)
	{
		m_sprite.setTexture(m_LeftAnimed[m_contFrame].getTexture());
		m_contFrame++;
	}
	if (m_stopped)
	{
		m_sprite.setTexture(m_stopAnimed[m_contFrame].getTexture());
		m_contFrame++;
	}
	if (m_killed) m_sprite.setTexture(m_kill.getTexture());
	if (m_shoot)  m_sprite.setTexture(m_shootSprite.getTexture());
}
//Set
void Player::setRight   (bool right)   { m_right   = right; };
void Player::setLeft    (bool left)    { m_left    = left; };
void Player::setShoot   (bool shoot)   { m_shoot   = shoot; };
void Player::setPressed (bool pressed) { m_pressed = pressed; };
void Player::setKilled  (bool killed)  { m_killed  = killed; };