#ifndef _RESOURCEMANAGER_H
#define _RESOURCEMANAGER_H
#include "String.h"
#include <vector>
using namespace std;

class ResourceManager 
{
public:
	static  ResourceManager& Instance   ();
	virtual GLuint           LoadImages (const char *filename, bool wrap);
	virtual void             FreeImages ();
protected: 
	         ResourceManager () {}
	virtual ~ResourceManager ();
private:
	static ResourceManager* manager;
	       vector<String>   fileName;
	       vector<GLuint>   textures;
};
#endif

