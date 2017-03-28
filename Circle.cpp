#include <GL/gl.h>
#include <GL/glut.h>
#include<cstdio>
int R;//=100;
int x=0, y=R;
int cx=0,cy=0;

void display(void)
{
/* clear all pixels */
glClear(GL_COLOR_BUFFER_BIT);

glColor3f(1.0, 1.0, 1.0);//(R,G,B)

//Draw a triangle using line.

//glBegin(GL_LINES);
//glBegin(GL_LINE_STRIP);
glBegin(GL_LINES);



    glVertex3i(-300,0, 0);
    glVertex3i(300,0, 0);
    glVertex3i(0,300, 0);
    glVertex3i(0,-300, 0);
    //glColor3f(1.0, 1.0, 0.0);
    //glVertex3i(x,y, 0);
    //glVertex3i(x,y-1, 0);
    glEnd();
    //MidpointEighthCircle();
    printf("%d , %d\n",x+cx,y+cy);
    int deltaE = (2 * x) +3;
    int deltaSE = (2 *(x-y)) + 5;
    int decision = 1 - R;
    printf("decision : %d\n",decision);
    while (y >= x ){

        if((int)decision <= 0){
            int xo=x;
            int yo =y;
            deltaE = 2 * x +3;
            deltaSE = 2 * (x-y) + 5;
            x++;
            //glBegin(GL_LINE_LOOP);
            printf("%d , %d\n",x+cx,y+cy);
            //glVertex3i(x, y, 0);

            decision += deltaE;
            printf("decision : %d\n",decision);

            //glClear(GL_COLOR_BUFFER_BIT);

            glColor3f(1.0, 1.0, 0.0);//(R,G,B)


            glBegin(GL_LINES);
                glVertex3i(xo+cx,yo+cy, 0);
                glVertex3i(x+cx,y+cy, 0);

            glEnd();
            glBegin(GL_LINES);
                glVertex3i(yo+cx,xo+cy, 0);
                glVertex3i(y+cx,x+cy, 0);

            glEnd();

            glBegin(GL_LINES);
                glVertex3i(xo+cx,-yo+cy, 0);
                glVertex3i(x+cx,-y+cy, 0);

            glEnd();
            glBegin(GL_LINES);
                glVertex3i(yo+cx,-xo+cy, 0);
                glVertex3i(y+cx,-x+cy, 0);

            glEnd();



            glBegin(GL_LINES);
                glVertex3i(-xo+cx,-yo+cy, 0);
                glVertex3i(-x+cx,-y+cy, 0);

            glEnd();
            glBegin(GL_LINES);
                glVertex3i(-yo+cx,-xo+cy, 0);
                glVertex3i(-y+cx,-x+cy, 0);

            glEnd();

            glBegin(GL_LINES);
                glVertex3i(-xo+cx,yo+cy, 0);
                glVertex3i(-x+cx,y+cy, 0);

            glEnd();
            glBegin(GL_LINES);
                glVertex3i(-yo+cx,xo+cy, 0);
                glVertex3i(-y+cx,x+cy, 0);

            glEnd();
            //glFlush();
            //display();

        }
        else{
            int xo = x;
            int yo =y;
            deltaE = 2 * x +3;
            deltaSE = 2 * (x-y) + 5;
            y--; x++;
            printf("%d , %d\n",x+cx,y+cy);

            decision += deltaSE;
            printf("decision : %d\n",decision);

            //glClear(GL_COLOR_BUFFER_BIT);

            glColor3f(1.0, 1.0, 0.0);//(R,G,B)


            glBegin(GL_LINES);
                glVertex3i(xo+cx,yo+cy, 0);
                glVertex3i(x+cx,y+cy, 0);

            glEnd();
            glBegin(GL_LINES);
                glVertex3i(yo+cx,xo+cy, 0);
                glVertex3i(y+cx,x+cy, 0);

            glEnd();
            glBegin(GL_LINES);
                glVertex3i(xo+cx,-yo+cy, 0);
                glVertex3i(x+cx,-y+cy, 0);

            glEnd();
            glBegin(GL_LINES);
                glVertex3i(yo+cx,-xo+cy, 0);
                glVertex3i(y+cx,-x+cy, 0);

            glEnd();


            glBegin(GL_LINES);
                glVertex3i(-xo+cx,-yo+cy, 0);
                glVertex3i(-x+cx,-y+cy, 0);

            glEnd();
            glBegin(GL_LINES);
                glVertex3i(-yo+cx,-xo+cy, 0);
                glVertex3i(-y+cx,-x+cy, 0);

            glEnd();

            glBegin(GL_LINES);
                glVertex3i(-xo+cx,yo+cy, 0);
                glVertex3i(-x+cx,y+cy, 0);

            glEnd();
            glBegin(GL_LINES);
                glVertex3i(-yo+cx,xo+cy, 0);
                glVertex3i(-y+cx,x+cy, 0);

            glEnd();
            //glBegin(GL_LINE_LOOP);
            //glVertex3i(x , y, 0);
            //glEnd();
            //glFlush();
            //display();
        }
    }
    //glVertex3i(x,y, 0);
    //glVertex3i(x,y, 0);
    //glVertex3i(275, 70, 0);

    //glVertex3i(25, 70, 0);
    //glVertex3i(150, 200, 0);
    //glVertex3i(25, 70, 0);
    //glVertex3i(150, 200, 0);
    //glVertex3i(275, 70, 0);

    //glVertex3i(150, 130,0);


/*
glBegin(GL_POLYGON);


    glVertex3i(25, 70, 0);
    glVertex3i(275, 70, 0);
    glVertex3i(150, 200, 0);

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
gluOrtho2D(-300.0, 300.0, -300.0, 300.0);
//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
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
    printf("Input Radius of the circle : ");//x=0, y=R;
    scanf("%d",&R);
    printf("\n");
    printf("Input Coordinate(x,y) of center point : ");
    scanf("%d",&cx);
    scanf("%d",&cy);
    printf("\n");
    x=0, y=R;

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(1000, 800);
glutInitWindowPosition(200, 50);
glutCreateWindow("hello");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0; /* ISO C requires main to return int. */
}

