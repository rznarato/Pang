#include "stdafx.h"
#include "ResourceManager.h"
#include "core.h"

ResourceManager* ResourceManager::manager = NULL;

ResourceManager::~ResourceManager() 
{
	FreeImages();
}

ResourceManager& ResourceManager::Instance() 
{
	if (!manager)
		manager = new ResourceManager();
	return *manager;
}
GLuint ResourceManager::LoadImages(const char *filename, bool wrap)
{
	String file(filename);
	for (int i = 0; i < fileName.size(); i++)
		if (file == fileName[i])
			return textures[i];

	fileName.emplace_back(file);
	GLuint texture = CORE_LoadPNG(filename, wrap);
	textures.emplace_back(texture);
	return texture;
}


void ResourceManager::FreeImages() {
	textures.clear();
	fileName.clear();
}
