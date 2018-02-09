#include<windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLUT/glut.h>
#include <iostream>

using namespace std;

 float xArr [4] = {0.0,0.0,0.0,0};
 float yArr [4] = {0.0,0.0,0.0,0};

 int shape =0, curState=0,theGlutWindowWidth=320,theGlutWindowHeight=320;

 bool init=false;

void draw(){
    switch (shape){
        case 0:
        cout<<"Here"<<xArr[2];
            glBegin(GL_QUADS);
                glColor3f(1.0, 1.0, 0.0);
                glVertex2f(xArr[0], yArr[0]);
                glVertex2f(xArr[1], yArr[1]);
                glVertex2f(xArr[2], yArr[2]);
                glVertex2f(xArr[3], yArr[3]);
            glEnd();
        break;
        case 1:
            glBegin(GL_TRIANGLES); //Begin triangle coordinates
            //Triangle
            glColor3f(0.0, 1.0, 0.0);
            glVertex2f(xArr[0], yArr[0]);
            glVertex2f(xArr[1], yArr[1]);
            glVertex2f(xArr[2], yArr[2]);
            glEnd(); //End triangle coordinates
        break;
    }
    glFlush();
}

void display() {
    if(!init){
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
        init=true;
    }

}

void mouseClicked(int button, int state, int x, int y){
    if(state==GLUT_DOWN){
        cout<<x;
        xArr[curState] = (((float)x / 160.0) - 1.0);
        yArr[curState] = -(((float)y / 160.0) - 1.0);
        curState +=1;
        if(curState == 4){
            draw();
            curState=0;
        }
        else if(curState == 3 && shape==1){
            draw();
            curState=0;
        }
    }
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
            case 't':
                if (curState==0){
                    if(shape == 0)
                        shape=1;
                    else
                        shape=0;
                }
                break;
            case 'T':
                if (curState==0){
                    if(shape == 0)
                        shape=1;
                    else
                        shape=0;
                }
                break;
            case 27: exit(1);break;
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
    glutMouseFunc( mouseClicked );

    glutMainLoop();
    return 0;
}
