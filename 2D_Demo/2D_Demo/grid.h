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

	// ----- variables -----
	Vector3 topLeft;
	Vector3 topRight; 
	Vector3 botLeft;
	Vector3 botRight;

	float squareSizeX;
	float squareSizeY;

	unsigned int rowAmount;
	unsigned int colAmount;
	vector<Node> nodeList;

	// ----- constructors -----
	Grid::Grid(Vector3& _pos, unsigned int _rows, unsigned int _cols, float _ssX, float _ssY)
		: topLeft(_pos), squareSizeX(_ssX), squareSizeY(_ssY), rowAmount(_rows), colAmount(_cols)
	{
		nodeList.reserve(rowAmount * colAmount);
		CreateNodes();
		CreateManConnections(); //add bool to choose between Man and Eul?
	}

	Grid::Grid(Vector3& _topLeft, Vector3& _topRight, Vector3& _botLeft, Vector3& _botRight, unsigned int _rows, unsigned int _cols)
		: topLeft(_topLeft), topRight(_topRight), botLeft(_botLeft), botRight(_botRight), rowAmount(_rows), colAmount(_cols)
	{
		nodeList.reserve(rowAmount * colAmount);

		//these correct?
		squareSizeX = double(abs(topRight.x - topLeft.x) / double(colAmount));
		cout << "square X: " << squareSizeX << endl;
		squareSizeY = double(abs(botLeft.y - topLeft.y) / double(rowAmount));
		cout << "square Y: " << squareSizeY << endl;
		CreateNodes();
		CreateManConnections();
	}

	Grid::Grid(const string& filename)
	{
		//take off a text file
	}

	void CreateManConnections(void);
	void CreateEulConnections(void);
	void CreateNodes(void);
	void AddCover(Cover&, unsigned int);
	void AddCover(unsigned int, bool);
	void RemoveCover(unsigned int);
	void Render(bool, bool, bool, bool); 
	void DrawNodes(void);
	void DrawConnections(void);
	void DrawGridLines(void);
	void DrawCover(void);
	void AddManConnectionsSingular(unsigned int);
	void AddEulConnectionsSingular(unsigned int);

};

#endif