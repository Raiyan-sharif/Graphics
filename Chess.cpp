#include <iostream>
#include <stdlib.h>
#include <math.h>
#include<GL/gl.h>
#include <GL/glut.h>

void initRendering() {
	glEnable(GL_DEPTH_TEST);
}
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}
void drawScene() {
    glClearColor(1.0, 1.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units
    glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(0.0, 0.0, 1.0); //Move to the center of the trapezoid
	glRotatef(45,-1.0, 0.0, 0.0); //Rotate about the z-axis
	int c=0,d=0;
    for(double x=-1;x<1;){

        for(double y=1;y>-1;){
            if(c%2==0){
                if(d%2 == 0){glColor3f(1.0, 1.0, 1.0); d++;}
                else{glColor3f(0.0, 0.0, 0.0);d++;}
            }
            else{
                if(d%2 == 0){glColor3f(0.0, 0.0, 0.0);d++;}
                else{glColor3f(1.0, 1.0, 1.0); d++;}
                }
            glBegin(GL_POLYGON);
            glVertex3f(x, y, 0.0);
            glVertex3f(x, y+0.25, 0.0);
            glVertex3f(x-0.25,y+0.25, 0.0);
            glVertex3f(x-0.25, y, 0.0);
            glEnd();
            y-=0.25;
        }
        c++;
        x+=0.25;
    }

	glPopMatrix();
	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 700);
	glutCreateWindow("Chess");
	initRendering();
	glutDisplayFunc(drawScene);
	glutReshapeFunc(handleResize);
	glutMainLoop();
	return 0;
}
