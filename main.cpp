//
//  main.cpp
//  ObjReader
//
//  Created by Jesús Martínez on 16/02/17.
//
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "ObjModel.hpp"

ObjModel model;

void init (void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Calculate camera scale
    float x1 = model.getVertices().at(0).getX();
    float x2 = model.getVertices().at(0).getX();
    float y1 = model.getVertices().at(0).getY();
    float y2 = model.getVertices().at(0).getY();
    
    for(auto &faceVector : model.getVertices())
    {
        if(faceVector.getX() < x1 ) {
            x1 = faceVector.getX();
        }
        
        if(faceVector.getX() > x2 ) {
            x2 = faceVector.getX();
        }
        
        if(faceVector.getX() > x2 ) {
            x2 = faceVector.getX();
        }
    }
    glFrustum(-2, 2, -2, 2, 1, 80);
}

void reshape(int w, int h)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -2);
    glRotatef(30, 0, 1, 0);
}

void display(void)
{
    // clear all pixels
    glClear (GL_COLOR_BUFFER_BIT);
    
    for (auto &object : model.getObjects())
    {
        for(auto &faceVector : object.getFaces())
        {
            glColor3ub(rand()%60, rand()%155 + 100, rand()%70 );
            glBegin(GL_LINE_LOOP);
            for(auto vectorIndex : faceVector)
            {
                ObjVertex vertex = model.getVertices().at(vectorIndex);
                glVertex3f(vertex.getX(), vertex.getY(), vertex.getZ());
            }
            glEnd();
        }
    }

    glFlush();
}

int main(int argc, char * argv[]) {
    if(argc < 2) {
        cerr << "File name required" << endl;
        return 1;
    }
    
    model = ObjModel(argv[1]);
    //modelA.print();
    
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 640);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[1]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
