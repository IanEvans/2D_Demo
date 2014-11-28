#ifndef __NODE_H_
#define __NODE_H_

#include "vector3.h"
#include "cover.h"
#include "grid.h"
#include <vector>

class Node;
class Cover;

class Connection
{
public:
	Node * from;
	Node * to;
	Grid * gFrom;
	Grid * gTo;
	double cost;

	Connection::Connection(double _cost, Node * _from, Node * _to, Grid * _gfrom, Grid * _tfrom = nullptr)
		: cost(_cost), from(_from), to(_to), gFrom(_gfrom), gTo(_tfrom)
	{}

	void Render(void);
};

class Node
{
public:
	Vector3 position;
	unsigned int index;
	int nodeType; //0 = normal, 1 = cover node, 2 = obstacle
	Cover * cover;
	std::vector<Connection> connectionList;
	//A* variables
	int step;
	int heurstic;
	int totalCost;
	//texture

	Node::Node()
	{
		position = Vector3(0, 0, 0);
		index = 0;
		nodeType = 0;
		cover = nullptr;
		step = 0;
		heurstic = 0;
		totalCost = 0;
	}

	Node::Node(unsigned int _ind, Cover * _cov = nullptr, int _type = 0, Vector3 _pos = Vector3(0.0, 0.0, 0.0))
		: index(_ind), nodeType(_type), cover(_cov), position(_pos)
	{
		if (cover != nullptr)
			nodeType = 2; //obstacle
		step = 0;
		heurstic = 0;
		totalCost = 0;

	}

	void Render(double squareSize, double squareSizeY);
	void Render(void);
	//void AddConnections(void);
};

#endif
