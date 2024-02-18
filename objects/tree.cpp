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
    glVertex2f(0.3, -2);
    glVertex2f(-0.3, -2);
    glEnd();

    // Draw branches
    glColor3f(0.5, 0.35, 0.05); // Brown color for the branches   
    for(float angle = -45.0; angle <= 45.0; angle += 30.0) {
        glPushMatrix();
        glTranslatef(-0.25, -2.0, -0.3); // Move up to the top of the trunk
        glRotatef(angle, 0.0, 0.0, 1.0); // Apply rotation
        glBegin(GL_POLYGON);
        glVertex2f(0.2, 0);  
        glVertex2f(0.1, 2);
        glVertex2f(-0.1, 2);
        glVertex2f(-0.2, 0);
        glEnd();
        glPopMatrix(); 
    }

    // Draw leaves
    glColor3f(0.0, 0.6, 0.0); // Green color for the leaves
    glTranslatef(-0.25, 1.0, -0.4); // Move up to the top of the trunk
    glBegin(GL_POLYGON);
    for (float angle = 0; angle < 2 * M_PI; angle += 0.05) {
        float x = (5.0 + 0.5 * cos(5 * angle)) * sin(angle); // Varying Radius
        float y = -(2.5 + 0.5 * cos(5 * angle)) * cos(angle); // Varying Radius
        glVertex2f(x, y);
    }
    glEnd();
}

void drawTreeShadow() {
   // Draw trunk
    glColor4f(0.0, 0.0, 0.0, 0.7); // shadow color
    glBegin(GL_POLYGON);
    glVertex2f(-0.4, -5); 
    glVertex2f(0.4, -5);
    glVertex2f(0.3, -2);
    glVertex2f(-0.3, -2);
    glEnd();

    // Draw branches
    glColor4f(0.0, 0.0, 0.0, 0.7); // shadow color
    for(float angle = -45.0; angle <= 45.0; angle += 30.0) {
        glPushMatrix();
        glTranslatef(-0.25, -2.0, -0.3); // Move up to the top of the trunk
        glRotatef(angle, 0.0, 0.0, 1.0); // Apply rotation
        glBegin(GL_POLYGON);
        glVertex2f(0.2, 0);  
        glVertex2f(0.1, 2);
        glVertex2f(-0.1, 2);
        glVertex2f(-0.2, 0);
        glEnd();
        glPopMatrix(); 
    }

    // Draw leaves
    glColor4f(0.0, 0.0, 0.0, 0.7); // shadow color
    glTranslatef(-0.25, 1.0, -0.4); // Move up to the top of the trunk
    glBegin(GL_POLYGON);
    for (float angle = 0; angle < 2 * M_PI; angle += 0.05) {
        float x = (5.0 + 0.5 * cos(5 * angle)) * sin(angle); // Varying Radius
        float y = -(2.5 + 0.5 * cos(5 * angle)) * cos(angle); // Varying Radius
        glVertex2f(x, y);
    }
    glEnd();
}