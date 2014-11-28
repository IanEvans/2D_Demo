#include "cover.h"

void Cover::Render(void)
{
	glPushMatrix();
		glColor3f(0.0, 1.0, 1.0);
		//glTranslatef(position.x, position.y, position.z);
		glBegin(GL_POINTS);
			glVertex3f(position.x, position.y, position.z);
		glEnd();
	glPopMatrix();
}

ostream& operator<<(ostream& os, const Cover& cov)
{
	os << "Full Cover: " << cov.isFullCover << endl;
	os << "Position: " << cov.position << endl;
	os << "Health: " << cov.health << endl;
	os << "Size: " << cov.size << endl;
	return os;
}