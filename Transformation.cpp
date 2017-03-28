#include<GL/gl.h>
#include <GL/glut.h>
#include<iostream>
#include <math.h>
#define PI 3.14159265
using namespace std;
int choose;
double x1,x2,x3,x4,y11,y2,y3;
double y4=0,tX=0,tY=0,Sx=0,Sy=0,angle=0;
double px1,px2,px3,px4,py1,py2,py3,py4;

void display(void)
{
/* clear all pixels */
glClear(GL_COLOR_BUFFER_BIT);

glColor3f(1.0, 1.0, 1.0);//(R,G,B)

//Draw a triangle using line.

//glBegin(GL_LINES);
//glBegin(GL_LINE_STRIP);
glBegin(GL_LINES);


    glVertex3i(300, 0, 0);
    glVertex3i(-300, 0, 0);

    //glVertex3i(25, 70, 0);
    glVertex3i(0, 300, 0);
    glVertex3i(0, -300, 0);
    //glVertex3i(150, 200, 0);
    //glVertex3i(275, 70, 0);

    //glVertex3i(150, 130,0);

glEnd();
if(Sy==0 && Sx==0 && angle==0){
glColor3f(0.0, 1.0, 0.0);
glBegin(GL_LINE_LOOP);


    glVertex3i(x1, y11, 0);
    glVertex3i(x2, y2, 0);
    glVertex3i(x3, y3, 0);

    //glVertex3i(25, 70, 0);
    if(x4!=0 && y4 != 0 ){
        glVertex3i(x4, y4, 0);
      //  glVertex3i(x1, y1, 0);
    }

    glVertex3i(x1, y11, 0);
    //glVertex3i(150, 200, 0);
    //glVertex3i(275, 70, 0);

    //glVertex3i(150, 130,0);

glEnd();
glColor3f(1.0, 0.0, 0.0);
glBegin(GL_LINE_LOOP);


    glVertex3i(x1+tX, y11+tY, 0);
    glVertex3i(x2+tX, y2+tY, 0);

    //glVertex3i(25, 70, 0);
    glVertex3i(x3+tX, y3+tY, 0);
    if(x4!=0 && y4 != 0 ){
        glVertex3i(x4+tX, y4+tY, 0);
      //  glVertex3i(x1, y1, 0);
    }
    glVertex3i(x1+tX, y11+tY, 0);
    //glVertex3i(150, 200, 0);
    //glVertex3i(275, 70, 0);

    //glVertex3i(150, 130,0);

glEnd();
}
else if((Sy !=0 || Sx !=0 ) || angle != 0){
glColor3f(0.0, 1.0, 0.0);
glBegin(GL_LINE_LOOP);


    glVertex3i(x1, y11, 0);
    glVertex3i(x2, y2, 0);
    glVertex3i(x3, y3, 0);

    //glVertex3i(25, 70, 0);
    if(x4!=0 && y4 != 0 ){
        glVertex3i(x4, y4, 0);
      //  glVertex3i(x1, y1, 0);
    }

    glVertex3i(x1, y11, 0);
    //glVertex3i(150, 200, 0);
    //glVertex3i(275, 70, 0);

    //glVertex3i(150, 130,0);

glEnd();
glColor3f(1.0, 0.0, 0.0);
glBegin(GL_LINE_LOOP);


    glVertex3i(px1, py1, 0);
    glVertex3i(px2, py2, 0);

    //glVertex3i(25, 70, 0);
    glVertex3i(px3, py3, 0);
    if(px4 !=0 || py4 != 0 ){
        glVertex3i(px4, py4, 0);
      //  glVertex3i(x1, y1, 0);
    }
    glVertex3i(px1, py1, 0);
    //glVertex3i(150, 200, 0);
    //glVertex3i(275, 70, 0);

    //glVertex3i(150, 130,0);

glEnd();
}
/*
glBegin(GL_POLYGON);


    glVertex3i(25, 70, 0);
    glVertex3i(275, 70, 0);
    glVertex3i(150, 200, 0);


glEnd();
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
void TriangleTanslate(){
    cout<<"Input translation factor"<<endl;
    cin>>tX;
    cin>>tY;

}
void TriangleScale(){
    tX = -x1;
    tY = -y11;


    cout<<"Input Scale factor "<<endl;
    cin>>Sx;
    cin>>Sy;

    px1 = ((x1+tX)*Sx)-tX;
    py1 = ((y11+tY)*Sy)-tY;
    px2 = ((x2+tX)*Sx)-tX;
    py2 = ((y2+tY)*Sy)-tY;
    px3 = ((x3+tX)*Sx)-tX;
    py3 = ((y3+tY)*Sy)-tY;


}
void TriangeleRotation(){
    cin>>angle;
    double resultCos,resultSin;
    resultSin = sin (angle*PI/180);
    resultCos = cos (angle*PI/180);
    px1 = (x1 * resultCos) - (y11 * resultSin);
    py1 = (x1 * resultSin) + (y11 * resultCos);

    px2 = (x2 * resultCos) - (y2 * resultSin);
    py2 = (x2 * resultSin) + (y2 * resultCos);

    px3 = (x3 * resultCos) - (y3 * resultSin);
    py3 = (x3 * resultSin) + (y3 * resultCos);



}
void Triangle(){
    cout<<"Input x1,y1,x2,y2,x3,y3"<<endl;
    cin>>x1;
    cin>>y11;
    cin>>x2;
    cin>>y2;
    cin>>x3;
    cin>>y3;
    cout<<"Select the Transformation to be applied \n1)Translate\n2)Scale\n3)Rotate"<<endl;
    cin>>choose;
    if(choose == 1){
            TriangleTanslate();

    }
    else if(choose == 2){
            TriangleScale();

    }
    else if(choose == 3){
        TriangeleRotation();

    }

}
void QuadTanslate(){
    cout<<"Input translation factor"<<endl;
    cin>>tX;
    cin>>tY;

}
QuadScale(){
    tX = -x1;
    tY = -y11;


    cout<<"Input Scale factor "<<endl;
    cin>>Sx;
    cin>>Sy;

    px1 = ((x1+tX)*Sx)-tX;
    py1 = ((y11+tY)*Sy)-tY;
    px2 = ((x2+tX)*Sx)-tX;
    py2 = ((y2+tY)*Sy)-tY;
    px3 = ((x3+tX)*Sx)-tX;
    py3 = ((y3+tY)*Sy)-tY;
    px4 = ((x4+tX)*Sx)-tX;
    py4 = ((y4+tY)*Sy)-tY;


}
void Quad(){
    cout<<"Input x1,y1,x2,y2,x3,y3,x4,y4"<<endl;
    cin>>x1;
    cin>>y11;
    cin>>x2;
    cin>>y2;
    cin>>x3;
    cin>>y3;
    cin>>x4;
    cin>>y4;
    cout<<"Select the Transformation to be applied \n1)Translate\n2)Scale\n3)Rotate"<<endl;
    cin>>choose;
    if(choose == 1){
            QuadTanslate();

    }
    else if(choose == 2){
            QuadScale();

    }
    else if(choose == 3){

    }

}
int main(int argc, char** argv)
{

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(1000, 700);
glutInitWindowPosition(300, 100);
glutCreateWindow("hello");
init();
cout<<"Press 1 to choose Triangle and 2 to choose Quad"<<endl;
cin>>choose;
if(choose == 1){
    Triangle();
}
else if(choose == 2){
        Quad();

}
glutDisplayFunc(display);

glutMainLoop();
return 0; /* ISO C requires main to return int. */
/*
double param, result;
  param = 30.0;
  result = sin (param*PI/180);*/
}

