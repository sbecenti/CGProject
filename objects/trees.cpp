
#include <GL/glut.h>
#include <GL/gl.h>
#include <SOIL/SOIL.h>
#include <cmath>
    
void drawTree() {
    // Draw trunk
    glColor3f(0.5, 0.35, 0.05); // Brown color for the trunk
    glBegin(GL_POLYGON);
    glVertex2f(-0.4, -5); 
    glVertex2f(0.4, -5);
    glVertex2f(0.4, 0);
    glVertex2f(-0.4, 0);
    glEnd();

    // Draw leaves
    glColor3f(0.0, 0.6, 0.0); // Green color for the leaves
    glTranslatef(0.0, 1.0, 0.3); // Move up to the top of the trunk
    glRotatef(25, 0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    for (float angle = 0; angle < 2 * M_PI; angle += 0.1) {
        float x = 2.5 * sin(angle); // Radius of 0.5
        float y = 2.5 * cos(angle); // Radius of 0.5
    glVertex2f(x, y);
    }
    glEnd();
}

