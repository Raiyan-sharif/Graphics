#include <iostream>
#include <stdlib.h>
#include <math.h>
#include<GL/gl.h>
#include <GL/glut.h>




//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;
float _agle_t = 0.0;

//Draws the 3D scene
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	//glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units
    glPushMatrix();

	glRotatef(30, 1.0, 0.0, 0.0);
	glPopMatrix();
	glRotatef(45, 0.0, -1.0, 0.0);
	glRotatef(35, -1.0, 0.0, 0.0);

	glPushMatrix(); //Save the current state of transformations

	glTranslatef(0.0, 0.0, 1.0); //Move to the center of the triangle

    glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.8;
		float x = r * cos(A);
		float y = r * sin(A);

		glVertex2f(x,y );
	}
	glEnd();

	glPopMatrix(); //Undo the move to the center of the triangle
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(0.0, 0.0, 1.0); //Move to the center of the triangle


	glBegin(GL_LINES);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();


	glPopMatrix();
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(0.0, 0.0, 1.0); //Move to the center of the triangle


	glBegin(GL_LINES);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=1.1;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();


	glPopMatrix();
	glPushMatrix();

    glTranslatef(0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 0.0);
    glRotatef(_angle, 0.0, 1.0, 0.0);
	glutSolidSphere(.2,20,20);
    glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 1.0);
	glRotatef(_angle, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.5, 0.0);
    glRotatef(_angle, 0.0, 1.0, 0.0);
    glColor3f(0.0, 1.0, 1.0);
    glutWireSphere(.1,20,20);

	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 1.0);
	glRotatef(_ang_tri, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.80, 0.0);
    glRotatef(_ang_tri, 0.0, 1.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(.15,20,20);

	glPopMatrix();
	///done
	glPushMatrix();
	glTranslatef(0.0, 0.0, 1.0);
	glRotatef(_agle_t, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 1.12, 0.0);
    glRotatef(_agle_t, 0.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere(.17,20,20);

	glPopMatrix();

	glutSwapBuffers();
}

void update(int value) {
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	_ang_tri += 1.0f;
	if (_ang_tri > 360) {
		_ang_tri -= 360;
	}
	_agle_t += 1.5f;
	if (_agle_t > 360) {
		_agle_t -= 360;
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1400, 800);

	//Create the window
	glutCreateWindow("Transformations");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);

	glutTimerFunc(25, update, 0); //Add a timer

	glutMainLoop();
	return 0;
}


	/*glBegin(GL_TRIANGLES);

	//Pentagon
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(-0.5, 0.0, 0.0);

	glVertex3f(-0.5, 0.0, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.0, 0.0);

	glVertex3f(-0.5, 0.0, 0.0);
	glVertex3f(0.5, 0.0, 0.0);
	glVertex3f(0.0, 0.5, 0.0);

	glEnd();

*/






