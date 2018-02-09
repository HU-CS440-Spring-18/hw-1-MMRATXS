#include <cstdlib>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLUT/glut.h>
#include <iostream>

using namespace std;

GLfloat vertices1[] = { 0, 1, -1, -1, 1,-1};
bool init=false;
int theGlutWindowWidth=320,theGlutWindowHeight=320,score=0;


void display() {
    
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES); //Begin triangle coordinates
    //Triangle
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0, 1);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(1, -1);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-1, -1);
    glEnd(); //End triangle coordinates
    glFlush();

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
            case 'r':
                glClearColor(0.0, 0.0, 0.0, 1.0);
                glClear(GL_COLOR_BUFFER_BIT);
                glFlush();
                break;
            case 'R':
                glClearColor(0.0, 0.0, 0.0, 1.0);
                glClear(GL_COLOR_BUFFER_BIT);
                glFlush();
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
