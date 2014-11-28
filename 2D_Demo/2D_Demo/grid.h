#ifndef __GRID_H_
#define __GRID_H_

#include "vector3.h"

#include <vector>
#include <iostream>
#include "node.h"
#include "glut.h"

using namespace std;

//need to stop undeclared Node error C2065 - but unsure why 
class Node;

class Grid
{
public:
	Vector3 startPosition; //top left
	Vector3 topRightPos; 
	Vector3 botLeftPos;
	Vector3 botRightPos;

	double squareSize;
	double squareSizeY;

	unsigned int rowAmount;
	unsigned int colAmount;
	vector<Node> nodeList;

	Grid::Grid(Vector3 &_pos, double _sqS, unsigned int _rows, unsigned int _cols)
		: startPosition(_pos), squareSize(_sqS), rowAmount(_rows), colAmount(_cols)
	{
		nodeList.reserve(rowAmount * colAmount);
		CreateNodes();
		AddConnections();
	}

	Grid::Grid(Vector3& topLeft, Vector3& topRight, Vector3& botLeft, Vector3& botRight, unsigned int _rows, unsigned int _cols)
		: startPosition(topLeft), topRightPos(topRight), botLeftPos(botLeft), botRightPos(botRight), rowAmount(_rows), colAmount(_cols)
	{
		nodeList.reserve(rowAmount * colAmount);
		squareSize = double(abs(topRightPos.x - startPosition.x) / double(colAmount));
		cout << abs(topRightPos.x - startPosition.x) << "square X :" << squareSize << endl;
		squareSizeY = double(abs(botLeftPos.y - startPosition.y) / double(rowAmount));
		cout << abs(botLeftPos.y - startPosition.y) << "square Y :" << squareSizeY << endl;
		CreateNodes();
		AddConnections();
	}

	void Render(bool, bool, bool, bool); // needed? or just draws all below in 1 function ?
	void DrawLines(void);
	void DrawNodes(void);
	void DrawConnections(void);
	void CreateNodes(void);
	void AddConnections(void);
	void AddCover(unsigned int, bool);
	void DrawCover(void);
};

#endif