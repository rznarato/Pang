#include "stdafx.h"
#include "GraphicMotor.h"
#include "core.h"
#include "font.h"

GraphicMotor::GraphicMotor()
{
	FONT_Init();
	m_drawScore = false;
}

void GraphicMotor::update()
{
	for (int i = 0; i < m_staticSprites.size(); i++)
	{
		CORE_RenderCenteredSprite({ m_staticSprites[i].getX(), m_staticSprites[i].getY() }, { m_staticSprites[i].getSizeX(), m_staticSprites[i].getSizeY() }, m_staticSprites[i].getTexture());
	}
	for (int i = 0; i < m_listSprites.size(); i++)
	{
		CORE_RenderCenteredSprite({ m_listSprites[i].getX(), m_listSprites[i].getY() }, { m_listSprites[i].getSizeX(), m_listSprites[i].getSizeY() }, m_listSprites[i].getTexture());
	}
	m_listSprites.clear();
	if (m_drawScore) FONT_DrawString(m_scorePos, m_score.c_str()); 
	FONT_DrawString({ 300,455 }, m_totalScore.c_str());
}
GraphicMotor::~GraphicMotor()
{

}
