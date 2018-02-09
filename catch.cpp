#include <cstdlib>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLUT/glut.h>
#include <iostream>

using namespace std;

GLfloat vertices1[] = { 1, 1, -1, 1, -1,-1, -1,-1};
bool init=false;
int theGlutWindowWidth=320,theGlutWindowHeight=320,score=0;

void draw(){
    
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    vertices1[0] = (((float) (rand()%300) / 160.0) - 1.0);
    vertices1[1] = -(((float) (rand()%300) / 160.0) - 1.0);

    vertices1[2] = vertices1[0]+0.1;
    vertices1[3] = vertices1[1];
    
    vertices1[4] =  vertices1[0]+0.1;
    vertices1[5] =  (vertices1[1]-0.1);
    
    vertices1[6] =  vertices1[0];
    vertices1[7] = (vertices1[1]-0.1);
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, vertices1);
    glDrawArrays(GL_QUADS, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
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
        float cx = (((float) x / 160.0) - 1.0);
        float cy = -(((float) y / 160.0) - 1.0);
        cout<<cy<<vertices1[1]<<vertices1[5]<<endl;
        if(cx>=vertices1[0] && cx<=vertices1[2] && cy<vertices1[1] && cy>vertices1[5]){
            cout<<"Here";
        }
        else{
            score-=1;
        }
        if(score<=-3){
            exit(1);
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
            default:
            break;
        };
}

void loop(int a){
    draw();
    glutPostRedisplay();
    glutTimerFunc(5000,loop,0);
}
 
int main(int argc, char** argv) {


    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Setup Test");
    glutInitWindowSize(theGlutWindowWidth,theGlutWindowHeight);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);

    glutKeyboardFunc( pressKey);
    glutMouseFunc( mouseClicked );
    glutTimerFunc(5000,loop,0);

    glutMainLoop();
    return 0;
}
