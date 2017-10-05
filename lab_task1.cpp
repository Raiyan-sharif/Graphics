#include<GL/gl.h>
#include <GL/glut.h>



void display(void)
{
/* clear all pixels */
glClear(GL_COLOR_BUFFER_BIT);

glColor3f(0.0, 1.0, 0.0);//(R,G,B)

//Draw a triangle using line.


glBegin(GL_LINES);

glVertex3f(0.5, 0.99, 0.0);
glVertex3f(0.5, 0.0, 0.0);


//glColor3f(1.0, 0.0, 0.0);

glVertex3f(0.0, 0.5, 0.0);
glVertex3f(0.99, 0.5, 0.0);
glEnd();
glColor3f(1.0, 0.0, 0.0);
glBegin(GL_LINES);
    glVertex3f(0.12, 0.9, 0.0);
    glVertex3f(0.38, 0.6, 0.0);


    glVertex3f(0.12, 0.6, 0.0);
    glVertex3f(0.38, 0.9, 0.0);\
glEnd();
glColor3f(0.0, 0.0, 1.0);
glBegin(GL_LINES);
    glVertex3f(0.6, 0.94, 0.0);
    glVertex3f(0.89, 0.55, 0.0);


    glVertex3f(0.94, 0.94, 0.0);
    glVertex3f(0.55, 0.55, 0.0);
glEnd();
glBegin(GL_LINE_LOOP);
    glVertex3f(0.55, 0.55, 0.0);

    glVertex3f(0.89, 0.55, 0.0);


    glVertex3f(0.94, 0.94, 0.0);
     glVertex3f(0.6, 0.94, 0.0);

glEnd();

glColor3f(0.0, 1.0, 0.0);
glBegin(GL_TRIANGLES);
    glVertex3f(0.25, 0.25, 0.0);
    glVertex3f(0.12, 0.05, 0.0);
    glVertex3f(0.38, 0.05, 0.0);

glEnd();
glBegin(GL_TRIANGLES);
    glVertex3f(0.12, 0.45, 0.0);
    glVertex3f(0.25, 0.25, 0.0);
    glVertex3f(0.38, 0.45, 0.0);

glEnd();

glColor3f(1.0, 1.0, 1.0);
glBegin(GL_POLYGON);
    glVertex3f(0.55, 0.25, 0.0);
    glVertex3f(0.65, 0.05, 0.0);
    glVertex3f(0.94, 0.05, 0.0);
    glVertex3f(0.94, 0.45, 0.0);
    glVertex3f(0.65, 0.45, 0.0);

glEnd();

//glColor3f(0.0, 0.0, 1.0);

//glVertex3f(0.50, 0.75, 0.0);
//glVertex3f(0.75, 0.25, 0.0);


//Draw a Simple Triangle.
/*
glBegin(GL_TRIANGLES);

glVertex3f(0.25, 0.25, 0.0);
glVertex3f(0.75, 0.25, 0.0);
glVertex3f(0.75, 0.75, 0.0);


//Draw a simple rectangle.

//glBegin(GL_POLYGON);
glBegin(GL_QUADS);

glVertex3f(0.25, 0.25, 0.0);
glVertex3f(0.75, 0.25, 0.0);

glVertex3f(0.25, 0.75, 0.0);
glVertex3f(0.75, 0.75, 0.0);

//glVertex3f(0.90, 0.50, 0.0);

/*glEnd();
glBegin(GL_POLYGON);
glVertex3f(0.75, 0.75, 0.0);
glVertex3f(0.25, 0.75, 0.0);
glVertex3f(0.10, 0.50, 0.0);
*///glEnd();
/* don’t wait!
* start processing buffered OpenGL routines
*/
glFlush();
}
void init(void)
{
/* select clearing (background) color */
glClearColor(0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
gluOrtho2D(0.0,1,0.0,1);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with “hello”
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(1000, 800);
glutInitWindowPosition(200, 50);
glutCreateWindow("Task 1");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0; /* ISO C requires main to return int. */
}


