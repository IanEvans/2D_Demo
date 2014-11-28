#include <iostream>
#include <iomanip>
#include "glut.h"
#include "grid.h"
#include "vector3.h"

using namespace std;

/*
Vector3 pos(-1.5, 1.5, -2.5);
Vector3 topRight(1.5, 1.5, -2.5);
Vector3 botLeft(-1.5, -1.5, 0.5);
Vector3 botRight(1.5, -1.5, 0.5);
*/
Vector3 pos(-1.5, 1.5, 0);
Vector3 topRight(1.5, 1.5, 0);
Vector3 botLeft(-1.5, -1.5, 0);
Vector3 botRight(1.5, -1.5, 0);

//draw variables
bool dNod = true;
bool dCon = true;
bool dLin = true;
bool dCov = true;

//camera variables
float xCh = 0.0;
float yCh = 0.0;
float zCh = 0.0;
float xRot = 0.0;
float yRot = 0.0;
float zRot = 0.0;
/*
Vector3 pos(0,0,0);
Vector3 topRight(1,0,0);
Vector3 botLeft(0,2, 0);
Vector3 botRight(1,2,0);*/


//Grid testGrid(pos, 0.5, 5, 5); //uses constructor with 1 point, square size wanted, rows and cols wanted
//Grid testGrid(pos, topRight, botLeft, botRight, 5, 5); //uses contrcutor with 4 points, rows and cols wanted
Grid testGrid(pos, topRight, botLeft, botRight, 5, 5);


void draw(void)
{
	// Clears the color buffer bit and depth buffer bit 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glRotatef(xRot, 1, 0, 0); xRot = 0.0;
	glRotatef(yRot, 0, 1, 0); yRot = 0.0;
	glRotatef(zRot, 0, 0, 1); zRot = 0.0;

	glPushMatrix();
		// Defines a viewing transformation 
		gluLookAt(0.0 + xCh, 0.0 + yCh, 10.0 + zCh, 0.0 + xCh, 0.0 + yCh, 0.0 + zCh, 0.0, 1.0, 0.0);
		testGrid.Render(dNod, dCon, dLin, dCov);
	glPopMatrix();

	// Swaps the buffers 
	glutSwapBuffers();

	glutPostRedisplay();
}

// Initialise function 
void initialise()
{
	// Clears the color pixels to white 
	glClearColor(0.0, 0.0, 0.0, 0.0);

	// Selects smooth shading 
	glShadeModel(GL_SMOOTH);

	// Enable depth test 
	glEnable(GL_DEPTH_TEST);
}


// Reshapes the window 
void reshape(int w, int h)
{
	// Sets the viewport 
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	// Applies matrix operations to the projection matrix stack 
	glMatrixMode(GL_PROJECTION);

	// Replaces the current matrix with the identity matrix 
	glLoadIdentity();

	// Sets up a perspective projection matrix 
	gluPerspective(40.0, (GLfloat)w / (GLfloat)h, 1.0, 500.0);

	// Applies matrix operations to the modelview matrix stack 
	glMatrixMode(GL_MODELVIEW);

	// Replaces the current matrix with the identity matrix
	glLoadIdentity();
}


// Function that reads input from the keyboard 
void Keyboard(unsigned char key, int A, int B)
{
	switch (key)
	{
		//drawing bools
	case '1': dNod = !dNod;
		break;
	case '2': dLin = !dLin;
		break;
	case '3': dCon = !dCon;
		break;
	case '4': dCov = !dCov;
		break;
		//camera variables
	case 'a': xCh -= 1.0;
		break;
	case 'd': xCh += 1.0;
		break;
	case 's': yCh -= 1.0;
		break;
	case 'w': yCh += 1.0;
		break;
	case 'q': zCh -= 1.0;
		break;
	case 'e': zCh += 1.0;
		break;
	case 'r': xCh = yCh = zCh = 0.0;
		break;
		//rotate varaibles
	case 'z': xRot -= 1.0;
		break;
	case 'x': xRot += 1.0;
		break;
	case 'c': yRot -= 1.0;
		break;
	case 'v': yRot += 1.0;
		break;
	case 'b': zRot -= 1.0;
		break;
	case 'n': zRot += 1.0;
		break;
		//special case
	case 27:
		exit(0); // Terminates the program 
		break;
	default:

		break;
	}
}

// Function that prints a menu on the command window 
void menu(void)
{
	printf("------------ OPTIONS -------------\n");
	printf("----------------------------------\n");
}

// Main function 
int main(int argc, char **argv)
{
	menu();
	cout << setprecision(3) << endl;
	//testing index
	cout << " ----- INDEX FOR GRID (1D) ----- \n\n";
	for (unsigned int i = 0; i < testGrid.nodeList.size(); i++)
	{
		cout << testGrid.nodeList[i].index << " | ";
		if (i % testGrid.colAmount == testGrid.colAmount - 1)
			cout << endl;
	}

	cout << "\n ----- INDEX FOR GRID (2D) ----- \n\n";
	for (unsigned int i = 0; i < testGrid.nodeList.size(); i++)
	{
		cout << " [" << testGrid.nodeList[i].index / testGrid.colAmount << "][" << testGrid.nodeList[i].index % testGrid.colAmount << "]" << " | ";
		if (i % testGrid.colAmount == testGrid.colAmount - 1)
			cout << endl;
	}

	cout << "\n ----- NODE POSITIONS ----- \n" << endl;
	for (int i = 0; i < testGrid.nodeList.size(); ++i)
	{
		cout << "Node " << i + 1 << " pos: " << testGrid.nodeList[i].position.x << ", " << testGrid.nodeList[i].position.y << ", " << testGrid.nodeList[i].position.z << endl;
	}

	testGrid.AddCover(testGrid.nodeList.size()/2, true);

	// Initialise GLUT library 
	glutInit(&argc, argv);

	// Initialise the display mode 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// Initialise the window position 
	glutInitWindowPosition(300, 300);

	// Initialise the window size 
	glutInitWindowSize(500, 500);

	// Creates a window on the screen 
	glutCreateWindow("AI Work - Ian Evans");

	// Call the initialise function 
	initialise();

	// The display function is called each time there is a display callback 
	glutDisplayFunc(draw);

	// The reshape function reshapes the scene 
	glutReshapeFunc(reshape);

	// Function that reads input from the keyboard 
	glutKeyboardFunc(Keyboard);

	// Causes the program to enter an event-processing loop 
	glutMainLoop();

	return 0;
}