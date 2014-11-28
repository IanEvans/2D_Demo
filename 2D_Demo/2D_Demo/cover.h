#ifndef __COVER_H_
#define __COVER_H_

#include "Vector3.h"
#include "grid.h"

class Cover
{
public:
	bool isFullCover;
	Vector3 position;
	unsigned int index;
	int health;
	double size;
	//mesh, textures etc
	
	Cover::Cover(bool _isFull, Vector3& _pos, unsigned int _ind, double _size)
		: isFullCover(_isFull), position(_pos), index(_ind), size(_size)
	{
		health = 100;
	}

	//void ChangeSurrounding(Grid*);
	void Render(void);
	void DrawCube(Vector3& pos, double size);
};

#endif