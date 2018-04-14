#include <cstdlib>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLUT/glut.h>
#include <iostream>

using namespace std;


float cord1[]={0,1};
float cord2[]={1,-1};
float cord3[]={-1,-1};

int recDepth=3;
bool black=true;
int theGlutWindowWidth=320,theGlutWindowHeight=320,score=0;


void draw(int rDepth,float cor1[],float cor2[],float cor3[],bool black){

    glBegin(GL_TRIANGLES); //Begin triangle coordinates
    //Triangle
    if(black){
        glColor3f(0.0, 0.0, 0.0);
    }
    else{
        glColor3f(1.0, 1.0, 1.0);
    }
    glVertex2f(cor1[0], cor1[1]);
    glVertex2f(cor2[0], cor2[1]);
    glVertex2f(cor3[0], cor3[1]);
    glEnd(); //End triangle coordinates
    black=!black;

    if(rDepth>0){

        float nCor1[] = {((cor1[0]+cor2[0]) / 2), ((cor1[1]+cor2[1]) / 2)};
        float nCor2[] = {(cor3[0]+cor2[0]) / 2, ((cor3[1]+cor2[1]) / 2)};
        float nCor3[] = {(cor1[0]+cor3[0]) / 2, ((cor1[1]+cor3[1]) / 2)};
        

        //Triangle
        draw(rDepth-1,nCor1,nCor2,nCor3,!black);
        draw(rDepth-1,cor1,nCor1,nCor3,black);
        draw(rDepth-1,cor2,nCor1,nCor2,black);
        draw(rDepth-1,cor3,nCor3,nCor2,black);     
    }
    else{
        return;
    }
}

void display() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    if((recDepth%2 == 1)){
        black=!black;
    }
    draw(recDepth,cord1,cord2,cord3,black);
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
            default:
            break;
        };
}
 
int main(int argc, char** argv) {
    recDepth=3;
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Setup Test");
    glutInitWindowSize(theGlutWindowWidth,theGlutWindowHeight);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    glutKeyboardFunc(pressKey);

    glutMainLoop();
    return 0;
}
