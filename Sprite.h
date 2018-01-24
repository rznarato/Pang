#ifndef _SPRITE_H
#define _SPRITE_H
#include <gl/gl.h>

class Sprite
{
public:
	Sprite();
	Sprite(float positionX, float positionY, float sizeX, float sizeY);
	float  getX        ();
	float  getY        ();
	float  getSizeX    ();
	float  getSizeY    ();
	float  getScale    ();
	GLuint getTexture  ();
	void   init        (const char *texture);
	void   setPosition (float positionX, float positionY);
	void   setSize     (float sizeX, float sizeY);
	void   setScale    (float scale);
	void   setTexture  (GLuint texture);

private:
	float  m_originalSizeX;
	float  m_originalSizeY;
	float  m_positionX;
	float  m_positionY;
	float  m_sizeX;
	float  m_sizeY;
	float  m_scale;
	GLuint m_texture;
};
#endif
