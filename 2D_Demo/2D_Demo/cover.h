#ifndef __COVER_H_
#define __COVER_H_

#include "Vector3.h"
#include "grid.h"

class Cover
{
public:
	bool isFullCover;
	Vector3 position;
	int health;
	float size;
	//mesh, textures etc
	
	Cover::Cover(bool _isFull, Vector3& _pos, double _size)
		: isFullCover(_isFull), position(_pos), size(_size)
	{
		health = 100;
	}

	//void ChangeSurrounding(Grid*);
	void Render(void);
};

#endif