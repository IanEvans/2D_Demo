#include "grid.h"

Grid::Grid(const string& filename)
{
	//take off a text file
}
/*
void Grid::DrawGridLines(void)
{
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < rowAmount + 1; i++)
	{
		glBegin(GL_LINES);
			glVertex3f(startPosition.x, startPosition.y - (i * squareSize), startPosition.z + (i * squareSize));
			glVertex3f(startPosition.x + (colAmount * squareSize), startPosition.y - (i * squareSize), startPosition.z + (i * squareSize));
		glEnd();
	}
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < colAmount + 1; i++)
	{
		glBegin(GL_LINES);
			glVertex3f(startPosition.x + (i * squareSize), startPosition.y, startPosition.z);
			glVertex3f(startPosition.x + (i * squareSize), startPosition.y - (rowAmount * squareSize), startPosition.z + (rowAmount * squareSize));
		glEnd();

	}
	glPopMatrix();
}*/

/*
void Grid::DrawNodes(void)
{
	unsigned int total = rowAmount * colAmount;
	glPushMatrix();
		glColor3f(0.0, 0.0, 1.0);
		for (int i = 0; i < total; ++i)
		{
			nodeList[i].DrawNode(squareSize, squareSizeY);
		}
	glPopMatrix();
}

void Grid::AddCover(unsigned int index, bool isFull)
{
	Cover cover(isFull, nodeList[index].position, index, squareSize);
	nodeList[index].cover = &cover;
}

void Grid::DrawCover(void)
{
	unsigned int total = rowAmount * colAmount;
	for (int i = 0; i < total; ++i)
	{
		if (nodeList[i].cover != nullptr)
		{			
			nodeList[i].cover->Render();
		}
	}
}

void Grid::Render(bool node, bool connect, bool lines, bool cover)
{
	if (node)
		DrawNodes();
	if (connect)
		DrawConnections();
	if (lines)
		DrawLines();
	if (cover)
		DrawCover();
}		

void Grid::DrawConnections(void)
{
	for (int i = 0; i < nodeList.size(); ++i){
		for (int j = 0; j < nodeList[i].connectionList.size(); ++j){
			glPushMatrix();
			glColor3f(0.0, 1.0, 0.0);
			glBegin(GL_LINES);
				glVertex3f(nodeList[i].connectionList[j].from->position.x, nodeList[i].connectionList[j].from->position.y, nodeList[i].connectionList[j].from->position.z);
				glVertex3f(nodeList[i].connectionList[j].to->position.x, nodeList[i].connectionList[j].to->position.y, nodeList[i].connectionList[j].to->position.z);
			glEnd();
			glPopMatrix();
		}
	}
}

void Grid::CreateNodes(void)
{
	for (int i = 0; i < rowAmount; i++)
	{
		for (int j = 0; j < colAmount; j++)
		{
			Vector3 pos(startPosition.x + (squareSize * j) + (squareSize / 2), startPosition.y - (squareSize * i) - (squareSize / 2), startPosition.z + (squareSize * i) + (squareSize/2));
			Node newNode(false, nullptr, (i * colAmount) + j, pos);

			nodeList.push_back(newNode);
		}
	}
}*/

/*
void Grid::AddConnections(void)
{
	for (int i = 0; i < nodeList.size(); ++i)
	{
		Node * node1;
		Node * node2;
		Node * node3;
		Node * node4;
		Node * node5;
		if (nodeList[i].index == 0) //top left of grid
		{
			node1 = &nodeList[i];
			node2 = &nodeList[colAmount];
			node3 = &nodeList[i + 1];

			Connection new1(1, node1, node3);
			Connection new2(1, node1, node2);
			nodeList[i].connectionList.push_back(new1);
			nodeList[i].connectionList.push_back(new2);
		}
		else if (nodeList[i].index == colAmount - 1) //top right of grid
		{
			node1 = &nodeList[i];
			node2 = &nodeList[i - 1];
			node3 = &nodeList[i + colAmount];
			Connection new1(1, node1, node2);
			Connection new2(1, node1, node3);
			nodeList[i].connectionList.push_back(new1);
			nodeList[i].connectionList.push_back(new2);
		}
		else if (nodeList[i].index == (colAmount * rowAmount) - 1) //bottom right of grid 
		{
			node1 = &nodeList[i];
			node2 = &nodeList[i - 1];
			node3 = &nodeList[i - colAmount];
			Connection new1(1, node1, node2);
			Connection new2(1, node1, node3);
			nodeList[i].connectionList.push_back(new1);
			nodeList[i].connectionList.push_back(new2);
		}
		else if (nodeList[i].index == (colAmount * rowAmount) - colAmount) //bottom left of grid
		{
			node1 = &nodeList[i];
			node2 = &nodeList[i + 1];
			node3 = &nodeList[i - colAmount];
			Connection new1(1, node1, node2);
			Connection new2(1, node1, node3);
			nodeList[i].connectionList.push_back(new1);
			nodeList[i].connectionList.push_back(new2);
		}
		else if (nodeList[i].index % colAmount == 0) //left side of grid except top and bottom left
		{
			node1 = &nodeList[i];
			node2 = &nodeList[i + 1];
			node3 = &nodeList[i - rowAmount];
			node4 = &nodeList[i + rowAmount];
			Connection new1(1, node1, node3);
			Connection new2(1, node1, node2);
			Connection new3(1, node1, node4);
			nodeList[i].connectionList.push_back(new1);
			nodeList[i].connectionList.push_back(new2);
			nodeList[i].connectionList.push_back(new3);
		}
		else if (nodeList[i].index >= 1 && nodeList[i].index <= colAmount - 2) //top row except top left and right
		{
			node1 = &nodeList[i];
			node2 = &nodeList[i - 1];
			node3 = &nodeList[i + 1];
			node4 = &nodeList[i + colAmount];
			Connection new1(1, node1, node2);
			Connection new2(1, node1, node3);
			Connection new3(1, node1, node4);
			nodeList[i].connectionList.push_back(new1);
			nodeList[i].connectionList.push_back(new2);
			nodeList[i].connectionList.push_back(new3);
		}
		else if (nodeList[i].index % colAmount == colAmount - 1) //right side of grid except top and bottom right
		{
			node1 = &nodeList[i];
			node2 = &nodeList[i - 1];
			node3 = &nodeList[i - colAmount];
			node4 = &nodeList[i + colAmount];
			Connection new1(1, node1, node3);
			Connection new2(1, node1, node2);
			Connection new3(1, node1, node4);
			nodeList[i].connectionList.push_back(new1);
			nodeList[i].connectionList.push_back(new2);
			nodeList[i].connectionList.push_back(new3);
		}
		else if (nodeList[i].index >= (colAmount * rowAmount) - colAmount && nodeList[i].index <= (colAmount * rowAmount) - 1) //bottom side of grid except bottom left and right
		{
			node1 = &nodeList[i];
			node2 = &nodeList[i - 1];
			node3 = &nodeList[i - colAmount];
			node4 = &nodeList[i + 1];
			Connection new1(1, node1, node3);
			Connection new2(1, node1, node2);
			Connection new3(1, node1, node4);
			nodeList[i].connectionList.push_back(new1);
			nodeList[i].connectionList.push_back(new2);
			nodeList[i].connectionList.push_back(new3);
		}
		else //rest not in these
		{
			node1 = &nodeList[i];
			node2 = &nodeList[i + 1];
			node3 = &nodeList[i - colAmount];
			node4 = &nodeList[i + colAmount];
			node5 = &nodeList[i - 1];
			Connection new1(1, node1, node4);
			Connection new2(1, node1, node2);
			Connection new3(1, node1, node3);
			Connection new4(1, node1, node5);
			nodeList[i].connectionList.push_back(new1);
			nodeList[i].connectionList.push_back(new2);
			nodeList[i].connectionList.push_back(new3);
			nodeList[i].connectionList.push_back(new4);
		}
	}
}
*/
ostream& operator<<(ostream& os, const Grid& grid)
{
	os << grid.topLeft << " ----- " << grid.topRight << "\n";
	os << "\t | \t ----- \t | \t\n";
	os << grid.botLeft << " ----- " << grid.botRight << "\n";
	os << "grid is " << grid.rowAmount << " rows by " << grid.colAmount << " columns.\n";
	os << "squareX: " << grid.squareSizeX << "\t squareY: " << grid.squareSizeY << "\n";


	return os;
}