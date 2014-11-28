#include "node.h"

void Node::Render(double squareSizeX, double squareSizeY)
{
	glPushMatrix();
	glBegin(GL_POINTS);
	glVertex3f(position.x, position.y, position.z);
	glEnd();/*
		glBegin(GL_QUADS);
			glVertex3f(position.x - (squareSizeX / 2), position.y + (squareSizeY / 2), position.z);
			glVertex3f(position.x + (squareSizeX / 2), position.y + (squareSizeY / 2), position.z);
			glVertex3f(position.x + (squareSizeX / 2), position.y - (squareSizeY / 2), position.z);
			glVertex3f(position.x - (squareSizeX / 2), position.y - (squareSizeY / 2), position.z);
		glEnd();*/
	glPopMatrix();

}

ostream& operator<<(ostream& os, const Connection& con)
{
	os << "From node" << con.from->index << "to " << con.to->index << endl;
	os << "Connection cost: " << con.cost << endl;
	if (con.gFrom != con.gTo)
		os << "Grids differ.\n";
	return os;
}

ostream& operator<<(ostream& os, const Node& node)
{
	os << "Position: " << node.position << endl;
	os << "Index: " << node.index << endl;
	os << "Node type: " << node.nodeType << endl;
	if (node.cover != nullptr){
		os << "---- Has Cover ----" << endl;
		os << &node.cover << endl;
	}
	os << "Has " << node.connectionList.size() << " connections." << endl;
	os << "Step: " << node.step << " Heurstic: " << node.heurstic << " Total Cost: " << node.totalCost << endl;
	return os;
}
