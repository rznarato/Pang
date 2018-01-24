#include "stdafx.h"
#include "Game.h"
#include "Block.h"
#include "string.h"
#include "global.h"
#include "GraphicMotor.h"
#include "rapidxml.hpp"
#include <limits.h>
using namespace rapidxml;
void Game::init()
{	
	m_graphicMotor.m_staticSprites.clear();
	m_world.m_blocksLevel.clear();

	String read;
	String text(read.Read("data/levels.tmx"));
	xml_document<> doc;
	doc.parse<0>(text.ToCString());

	String numberLevels(doc.first_node("levels")->first_attribute("levelsNumber")->value());
	if (globalLevel == numberLevels.ToInt() + 1) globalLevel = 1;
	
	/*/ Load Level /*/
	string levelName  = "level" + to_string(globalLevel);
	xml_node<> *level = doc.first_node("levels")->first_node(levelName.c_str());
	String land(level->first_attribute("landscape")->value());
	String flo(level->first_attribute("floor")->value());
	String acceleration(level->first_attribute("acceleration")->value());
	String bubbles(level->first_attribute("bubbles")->value());
	String blocks(level->first_attribute("blocks")->value());
	m_landscape               = land.ToCString();
	m_floor                   = flo.ToCString();
	m_world.setAcceleration(acceleration.ToFloat());
	m_world.setNumberStartBubbles(bubbles.ToFloat());
	m_world.setNumberStartBlocks(blocks.ToFloat());
	
	/*/ Load Blocks of Level /*/
	xml_node<>* block = level->first_node("block");
	while (block != NULL)
	{
		String px(block->first_attribute("x")->value());
		String py(block->first_attribute("y")->value());
		String sX(block->first_attribute("sizeX")->value());
		String sY(block->first_attribute("sizeY")->value());
		float x     = px.ToFloat();
		float y     = py.ToFloat();
		float sizeX = sX.ToFloat();
		float sizeY = sY.ToFloat();
		blockData blo;
		blo.sizeX   = sizeX;
		blo.sizeY   = sizeY;
		blo.x       = x;
		blo.y       = y;
		m_world.m_blocksLevel.emplace_back(blo);
		block = block->next_sibling("block");
	}

	/*/ Render background /*/
	Sprite sprite(WORLD_WIDTH / 2, WORLD_HEIGHT / 2, WORLD_WIDTH, WORLD_HEIGHT);
	sprite.init(m_landscape);
	m_graphicMotor.m_staticSprites.emplace_back(sprite);
	Sprite floor(WORLD_WIDTH / 2, WORLD_HEIGHT / 2, WORLD_WIDTH, WORLD_HEIGHT);

	for (int i = 0; i <= WORLD_WIDTH / 80; i++)
	{
		Sprite floor(40.f * (i * 2 + 1), 15.f, 80.f, 30.f);
		floor.init(m_floor);
		m_graphicMotor.m_staticSprites.emplace_back(floor);
	}
}
void Game::logicGame()
{
	m_world.update();
}
void Game::inputGame()
{
	m_input.update();
}
void Game::rendererGame()
{
	m_graphicMotor.update();
}

Game::Game()
{
	
}

