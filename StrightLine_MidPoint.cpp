
#include <GL/gl.h>
#include <GL/glut.h>
#include<iostream>
void DS();
using namespace std;
double x=0.1,y=0.5;
double ds=0.0;
double dx=0.0;
double dy=0.0;
double x2=0.5, y2=0.9;
double n1,n2,m1,m2;
double arr[2][100];

int i=0;
int c=1;
int d=100;
void NE(){
    x+=0.005;
    y+=0.005;
    arr[0][i]=x;
    arr[1][i]=y;
    i++;
    ds=ds+(2*(dy-dx));


}
void E(){
    x+=0.005;
    //y+=0.005;
    arr[0][i]=x;
    arr[1][i]=y;
    i++;
    ds=ds+(2*dy);


}

void DS(){

    while(x!=x2){
    c++;

    if(ds>0.0){
    NE();
    }
    else{
        E();
    }
    }
}
void display(void)
{
/* clear all pixels */
glClear(GL_COLOR_BUFFER_BIT);

glColor3f(0.0, 1.0, 0.0);//(R,G,B)

//Draw a triangle using line.
//let (.15,.15) to (.75,.75)
glBegin(GL_POINTS);
x=n1;
y=m1;
x2=n2;
y2=m2;
//arr[0][0]=x;
//arr[1][0]=y;
dx=x2-x;
dy=y2-y;
ds = (2*dy - dx);
while(d--){
    c++;

    if(ds>0.0){
    NE();
    }
    else{
        E();
    }
}
for(int j=0;j<100;j++){
    glVertex3f(arr[0][j],arr[1][j], 0.0);

}


glEnd();
/* don’t wait!
* start processing buffered OpenGL routines
*/
glFlush();
}
void init(void)
{
/* select clearing (background) color */
//glClearColor(0.5, 0.0, 0.23, 0.63);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
gluOrtho2D(0.0,1,0.0,1);
}

int main(int argc, char** argv)
{
    cout<<"Input x,y and x1,y1 where max input is 1.0 and min input is 0.0: "<<endl;
cin>>n1;

cin>>m1;
cin>>n2;
cin>>m2;
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500, 500);
glutInitWindowPosition(330, 100);
glutCreateWindow("hello");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0; /* ISO C requires main to return int. */
}

