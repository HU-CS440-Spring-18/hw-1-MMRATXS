#include<windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <stdlib.h>
#include <GLUT/glut.h>
#include <iostream>

using namespace std;

void map_point(int px,int py, int qx, int qy, int ax,int ay,int bx ,int by, int x, int y,int &_x,int &_y)
{

    int xPrime = ((x - px) * ((bx - ax) / (qx - px)) + ax);

    int yPrime = ((y - py) * ((by - ay) / (qy - py))) + ay;

    _x = xPrime;
    _y = yPrime;
}

int main(int argc, char *argv[])
{
    int x,y;
    x=y=5;
    map_point(2,2,4,4,8,8,12,12,x,y,x,y);
    cout<<"X Prime: "<<x<<"\nY Prime: "<<y<<endl;

    return 0;
}