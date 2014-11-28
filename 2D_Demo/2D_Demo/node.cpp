#include "node.h"

void Node::DrawNode(double squareSize, double squareSizeY)
{
	glPushMatrix();
	glBegin(GL_POINTS);
	glVertex3f(position.x, position.y, position.z);
	glEnd();/*
		glBegin(GL_QUADS);
			glVertex3f(position.x - (squareSize / 2), position.y + (squareSizeY / 2), position.z - (squareSizeY / 2));
			glVertex3f(position.x + (squareSize / 2), position.y + (squareSizeY / 2), position.z - (squareSizeY / 2));
			glVertex3f(position.x + (squareSize / 2), position.y - (squareSizeY / 2), position.z + (squareSizeY / 2));
			glVertex3f(position.x - (squareSize / 2), position.y - (squareSizeY / 2), position.z + (squareSizeY / 2));
		glEnd();*/
	glPopMatrix();

}
