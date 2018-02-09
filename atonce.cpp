#include<windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLUT/glut.h>
#include <iostream>

using namespace std;

 GLfloat vertices1[] = { 1, 1, -1, 1, -1,-1, -1,-1};

 int shape =0, curState=0,theGlutWindowWidth=320,theGlutWindowHeight=320;

 bool init=false;

void draw(){
    
    
    switch (shape){
        case 0:
            glEnableClientState(GL_VERTEX_ARRAY);
            glVertexPointer(2, GL_FLOAT, 0, vertices1);
            glDrawArrays(GL_QUADS, 0, 4);
            glDisableClientState(GL_VERTEX_ARRAY);
        break;
        case 1:
            glEnableClientState(GL_VERTEX_ARRAY);
            glVertexPointer(2, GL_FLOAT, 0, vertices1);
            glDrawArrays(GL_TRIANGLES, 0, 4);
            glDisableClientState(GL_VERTEX_ARRAY);
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
        vertices1[curState] = (((float)x / 160.0) - 1.0);
        vertices1[curState+1] = -(((float)y / 160.0) - 1.0);
        curState +=2;
        if(curState == 8){
            draw();
            curState=0;
        }
        else if(curState == 6 && shape==1){
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
