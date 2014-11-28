#ifndef __NODE_H_
#define __NODE_H_

#include "vector3.h"
#include "Cover.h"
#include <vector>

class Node;
class Cover;

class Connection
{
public:
	Node * from;
	Node * to;
	double cost;

	Connection::Connection(double _cost, Node * _from, Node * _to)
		: cost(_cost), from(_from), to(_to)
	{}
};

class Node
{
public:
	bool isObstacle;
	bool isCover;
	Cover * cover;
	int step;
	int heurstic;
	int totalCost;
	Vector3 position;
	unsigned int index;
	//texture
	std::vector<Connection> connectionList;

	Node::Node()
	{
		position = Vector3(0, 0, 0);
		isObstacle = 0;
		cover = nullptr;
		index = 0;
		step = 0;
		heurstic = 0;
		totalCost = 0;
	}

	Node::Node(bool _obs, Cover * _cov, unsigned int _ind, Vector3 _pos = Vector3(0.0, 0.0, 0.0)) : position(_pos)
	{
		isObstacle = _obs;

		cover = _cov;
		if (cover != nullptr)
			isCover = true;
		else
			isCover = false;
		index = _ind;
		step = 0;
		heurstic = 0;
		totalCost = 0;

	}

	void DrawNode(double squareSize, double squareSizeY);
	//void AddConnections(void);
};

#endif
