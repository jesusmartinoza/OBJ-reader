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
}

void reshape(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-2, 2, -2, 2, 1, 40);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -3);
    glRotatef(50, 0, 1, 0);
}

void display(void)
{
    // clear all pixels
    glClear (GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.00, 0.44, 0.13);
    
    for (auto &object : model.getObjects())
    {
        for(auto &faceVector : object.getFaces())
        {
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
    
    ObjModel modelA(argv[1]);
    model = modelA;
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
