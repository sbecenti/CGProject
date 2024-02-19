#include <GL/glut.h>
#include <GL/gl.h>
#include <SOIL/SOIL.h>
#include <cmath>

void drawFloor() {
    // ===================================================
    //                Draw Floor of Scene
    // ===================================================

    // Slope going across screen
    glBegin(GL_QUADS);
    glColor3f(0.363, 0.560, 0.353);
    glVertex3f(-30.5, -8.0, 15.0); // Bottom-left
    glVertex3f(17.5, -8.0, 15.0);  // Bottom-right
    glVertex3f(17.5, -6.5, 5.0);    // Top-right
    glVertex3f(-30.5, -6.5, 5.0);   // Top-left
    glEnd();

    //Concrete Slope
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(4.0, -8.0, 15.01); // Bottom-left
    glVertex3f(12.0, -8.0, 15.01);  // Bottom-right
    glVertex3f(12.0, -6.5, 5.01);    // Top-right
    glVertex3f(4.0, -6.5, 5.01);   // Top-left
    glEnd();
    
    // Field floor (very bottom)
    glBegin(GL_QUADS);
    glColor3f(0.385, 0.470, 0.381); //New color
    glVertex3f(-27.5, -10.0, 25.0); // Bottom-left
    glVertex3f(17.5, -10.0, 25.0);  // Bottom-right
    glVertex3f(17.5, -8.0, 15.0);    // Top-right
    glVertex3f(-27.5, -8.0, 15.0);   // Top-left
    glEnd();
    
    // white lines
    glBegin(GL_QUADS);
    glColor3f(0.678, 0.770, 0.655);
    glVertex3f(-27.5, -8.0, 15.0); // Bottom-left
    glVertex3f(17.5, -8.0, 15.0);  // Bottom-right
    glVertex3f(17.5, -7.9, 15.1);    // Top-right
    glVertex3f(-27.5, -7.9, 15.1);   // Top-left
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.678, 0.770, 0.655);
    glVertex3f(-27.5, -7.9, 20.0); // Bottom-left
    glVertex3f(20.5, -7.9, 20.0);  // Bottom-right
    glVertex3f(20.5, -7.8, 20.1);    // Top-right
    glVertex3f(-27.5, -7.8, 20.1);   // Top-left
    glEnd();

}