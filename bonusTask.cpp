

#include<GL/gl.h>
#include <GL/glut.h>



void display(void)
{
/* clear all pixels */
glClear(GL_COLOR_BUFFER_BIT);

glColor3f(1.0, 1.0, 1.0);//(R,G,B)

//Draw a triangle using line.




glBegin(GL_POLYGON);
    glVertex3f(0.2045, 0.655, 0.0);
    glVertex3f(0.2045, 0.621, 0.0);
    glVertex3f(0.2273, 0.621, 0.0);
    glVertex3f(0.2273, 0.586, 0.0);
    glVertex3f(0.25, 0.586, 0.0);
    glVertex3f(0.25, 0.5517, 0.0);
    glVertex3f(0.273, 0.5517, 0.0);
    glVertex3f(0.2955, 0.517, 0.0);
    glVertex3f(0.2955, 0.41379, 0.0);
    glVertex3f(0.36364, 0.3793, 0.0);
    glVertex3f(0.4091, 0.3793, 0.0);
    glVertex3f(0.4091, 0.34483, 0.0);
    glVertex3f(0.4091, 0.34483, 0.0);
    glVertex3f(0.45455, 0.34483, 0.0);
    glVertex3f(0.45455, 0.31034, 0.0);
    glVertex3f(0.47727, 0.31034, 0.0);
    glVertex3f(0.47727, 0.27586, 0.0);
    glVertex3f(0.5, 0.27586, 0.0);
    glVertex3f(0.5, 0.31034, 0.0);
    glVertex3f(0.52273, 0.31034, 0.0);
    glVertex3f(0.56818, 0.34483, 0.0);
    glVertex3f(0.56818, 0.3793, 0.0);


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
glutCreateWindow("Task 2");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0; /* ISO C requires main to return int. */
}

