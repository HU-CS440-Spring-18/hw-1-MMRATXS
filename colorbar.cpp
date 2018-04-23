#include <cstdlib>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLUT/glut.h>
#include <iostream>

using namespace std;

GLfloat vertices1[] = { -1, 1, 1, 1};
float p1Col[] = { 255, 255, 255};
float p2Col[] = { 0, 0, 0};
float p3Col[] = { 0, 0, 0};

bool init=false;
const int theGlutWindowWidth=320,theGlutWindowHeight=320,score=0;

const int barWidth=200;

float pixelCol[barWidth][3];

void assign3Col()
{   
    p1Col[0] = 0;
    p1Col[1] = 255;
    p1Col[2] = 0;
    p2Col[0] = 255;
    p2Col[1] = 0;
    p2Col[2] = 0;
    p3Col[0] = 0;
    p3Col[1] = 0;
    p3Col[2] = 255;
    
    for (int x = 160-int(barWidth/2); x<160; x++)
    {
        pixelCol[x][0] = p1Col[0]*(1.0-((float) x / 160.0)) + p2Col[0]*(((float) x / 160.0));
        pixelCol[x][1] = p1Col[1]*(1.0-((float) x / 160.0)) + p2Col[1]*(((float) x / 160.0));
        pixelCol[x][2] = p1Col[2]*(1.0-((float) x / 160.0)) + p2Col[2]*(((float) x / 160.0));
    }
    for (int x = 160; x<160+int(barWidth/2); x++)
    {
        pixelCol[x][0] = p2Col[0]*(2.0-((float) x / 160.0)) + p3Col[0]*(((float) x / 160.0)-1.0);
        pixelCol[x][1] = p2Col[1]*(2.0-((float) x / 160.0)) + p3Col[1]*(((float) x / 160.0)-1.0);
        pixelCol[x][2] = p2Col[2]*(2.0-((float) x / 160.0)) + p3Col[2]*(((float) x / 160.0)-1.0);
    }
}

void assign2Col()
{
    p1Col[0] = 255;
    p1Col[1] = 255;
    p1Col[2] = 255;
    p2Col[0] = 0;
    p2Col[1] = 0;
    p2Col[2] = 0;
    for (int x = 160-int(barWidth/2); x<160+int(barWidth/2); x++)
    {
        pixelCol[x][0] = p1Col[0]*(1.0-((float) x / 320.0)) + p2Col[0]*(((float) x / 320.0));
        pixelCol[x][1] = p1Col[1]*(1.0-((float) x / 320.0)) + p2Col[1]*(((float) x / 320.0));
        pixelCol[x][2] = p1Col[2]*(1.0-((float) x / 320.0)) + p2Col[2]*(((float) x / 320.0));
    }
}

void draw(int startY){
    for(int y=startY;y<startY+10;y++)
    {
        for (int x = 160-int(barWidth/2); x<160+int(barWidth/2); x++)
        {
            glColor3f  (pixelCol[x][0]/255, pixelCol[x][1]/255, pixelCol[x][2]/255);
            glVertex2f ((((float) x / 160.0) - 1.0), -(((float) y / 160.0) - 1.0));
        }
    }
}

void display() {
    
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    assign2Col();
    draw(50);
    assign3Col();
    draw(70);
    glEnd();
	glutSwapBuffers();
}


void pressKey(unsigned char key,int x, int y){
    switch(key)
        {
            case 'q':
                exit(1); 
                break;
            case 'Q':
                exit(1);
                break;
            default:
            break;
        };
}
 
int main(int argc, char** argv) {


    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Setup Test");
    glutInitWindowSize(theGlutWindowWidth,theGlutWindowHeight);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    glutKeyboardFunc( pressKey);
    glutMainLoop();
    return 0;
}
