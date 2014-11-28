#include "cover.h"

void Cover::Render(void)
{
	glPushMatrix();
		glColor3f(0.0, 1.0, 1.0);
		//glTranslatef(position.x, position.y, position.z);
		glBegin(GL_POINTS);
			glVertex3f(position.x, position.y, position.z);
		glEnd();
		DrawCube(position, 0.5);
	glPopMatrix();
}


void DrawSquare(double size)
{
	glBegin(GL_POLYGON);
	glVertex3f(-size, size, 0.0);
	glVertex3f(-size, -size, 0.0);
	glVertex3f(size, -size, 0.0);
	glVertex3f(size, size, 0.0);
	glEnd();
}

void Cover::DrawCube(Vector3& pos, double size)
{
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(pos.x, pos.y, pos.z);
	//back face
	DrawSquare(size);
	//right side
	glPushMatrix();
	glTranslatef(size, 0.0, size);
	glRotatef(90, 0, 1, 0);
	DrawSquare(size);
	glPopMatrix();
	//left side
	glPushMatrix();
	glTranslatef(-size, 0.0, size);
	glRotatef(90, 0, 1, 0);
	DrawSquare(size);
	glPopMatrix();
	//front face
	glPushMatrix();
	glTranslatef(0.0, 0.0, size * 2.0);
	DrawSquare(size);
	glPopMatrix();
	//top face
	glPushMatrix();
	glTranslatef(0.0, size, size);
	glRotatef(90, 1, 0, 0);
	DrawSquare(size);
	glPopMatrix();
	//bottom face
	glPushMatrix();
	glTranslatef(0.0, -size, size);
	glRotatef(90, 1, 0, 0);
	DrawSquare(size);
	glPopMatrix();
	glPopMatrix();
}