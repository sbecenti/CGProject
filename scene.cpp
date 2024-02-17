// Samson Becenti & Spencer Meren
// CST-310

// -lGL -lGLU -lglut -lSOIL
// Use to easily pick colors: https://antongerdelan.net/colour/

#include <GL/glut.h>
#include <GL/gl.h>
#include <SOIL/SOIL.h>
#include <cmath>

#include "objects/building.cpp"
#include "objects/floor.cpp"

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

void drawPerson() {
    // Draw oval to represent a person
    glColor3f(0.403, 0.585, 0.630);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float theta = 2.0f * M_PI * float(i) / float(100);
        float x = 0.35 * cosf(theta);
        float y = 0.75 * sinf(theta);
        glVertex2f(x + 0, y + 0);
    }
    glEnd();
}

//TODO: GCBC Poster

void drawObjects() {

    // ===================================================
    //                  Draw Building
    // ===================================================
    
    drawBuilding();

    // ===================================================
    //                Draw Floor of Scene
    // ===================================================
    
    drawFloor();

    // ===================================================
    //                Draw Objects of Scene
    // ===================================================
    
    // Building in the far back left
    glPushMatrix();
    glTranslatef(-30.0, -7.0, 5.0);
    glBegin(GL_POLYGON);
    glColor3f(0.96, 0.87, 0.70);
    glVertex2f(15.0, 0.0); //Bottom-left
    glVertex2f(0.0, 0.0); //Bottom-right
    glVertex2f(0.0, 5.0); //Top-right
    glVertex2f(15.0, 5.0); //Top-left
    glEnd();
    glPopMatrix();
    
    // Purple fence
    //Horizontal bar
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.0, 0.5);
    glVertex3f(-27.5, -5.5, 7.5);  // Bottom-left
    glVertex3f(8.0, -5.5, 7.5);   // Bottom-right
    glVertex3f(8.0, -5.3, 7.5);   // Top-right
    glVertex3f(-27.5, -5.3, 7.5);  // Top-left
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.0, 0.5);
    glVertex3f(12.0, -5.5, 7.5);  // Bottom-left
    glVertex3f(17.0, -5.5, 7.5);   // Bottom-right
    glVertex3f(17.0, -5.3, 7.5);   // Top-right
    glVertex3f(12.0, -5.3, 7.5);  // Top-left
    glEnd();

    //Vertical Bars
    for (float x = -27.5; x <= 17.0; x+=0.75) {
        if (x < 8.5 || x > 11.5) {
            glBegin(GL_QUADS);
            glColor3f(0.5, 0.0, 0.5);
            glVertex3f(x, -6.5, 7.5);  // Bottom-left
            glVertex3f(x + 0.2, -6.5, 7.5);   // Bottom-right
            glVertex3f(x + 0.2, -5.5, 7.5);   // Top-right
            glVertex3f(x, -5.5, 7.5);  // Top-left
            glEnd();
        }
    }
    
    // Light Pole
    glPushMatrix();
    glColor3f(0.760, 0.768, 0.768); // Grey color for the pole
    glTranslatef(13.0, -5, 10.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.5, -3.0); // Bottom-left
    glVertex2f(0.0, -3.0); //Bottom-right
    glVertex2f(0.0, 20); //Top-right
    glVertex2f(0.5, 20); //Top-left
    glEnd();
    glPopMatrix();

    // Far Left Tree
    glPushMatrix();
    glTranslatef(-23.0, -4.5, 10.0);
    drawTree();
    glEnd();
    glPopMatrix();

    // Left Tree
    glPushMatrix();
    glTranslatef(-12.0, -2.5, 10.0);
    drawTree();
    glPopMatrix();

    // Right Tree
    glPushMatrix();
    glTranslatef(-1.0, -2.5, 10.0);
    drawTree();
    glPopMatrix();

    // Far Right Tree
    glPushMatrix();
    glTranslatef(6.0, -4.5, 7.0);

    // Draw trunk
    glColor3f(0.5, 0.35, 0.05); // Brown color for the trunk
    glBegin(GL_POLYGON);
    glVertex2f(-0.20, -2);  
    glVertex2f(0.35, -2);
    glVertex2f(0.35, 0);
    glVertex2f(-0.20, 0);
    glEnd();

    // Draw branches
    glColor3f(0.5, 0.35, 0.05); // Brown color for the branches    
    for(float angle = 130.0; angle <= 220.0; angle += 30.0) {
        glPushMatrix();
        glRotatef(angle, 0.0, 0.0, 1.0); // Apply rotation
        glBegin(GL_POLYGON);
        glVertex2f(-0.2, -2.5);  
        glVertex2f(0.1, -2.5);
        glVertex2f(0.1, 0);
        glVertex2f(-0.2, 0);
        glEnd();
        glPopMatrix(); 
    }
    glPopMatrix();

    // student 1
    glPushMatrix();
    glTranslatef(4.0, -5.5, 7.4);
    drawPerson();
    glPopMatrix();

    // student 2
    glPushMatrix();
    glTranslatef(3.0, -5.5, 7.4);
    drawPerson();
    glPopMatrix();

    // student 3
    glPushMatrix();
    glTranslatef(2.0, -5.5, 7.4);
    drawPerson();
    glPopMatrix();

    // student 4
    glPushMatrix();
    glTranslatef(-1.0, -5.5, 7.4);
    drawPerson();
    glPopMatrix();

    // student 5
    glPushMatrix();
    glTranslatef(-3.0, -5.5, 7.4);
    drawPerson();
    glPopMatrix();

    // student 6
    glPushMatrix();
    glTranslatef(-6.0, -5.5, 7.4);
    drawPerson();
    glPopMatrix();

    // student 7
    glPushMatrix();
    glTranslatef(-12.0, -5.5, 7.4);
    drawPerson();
    glPopMatrix();

    glutSwapBuffers();
}

void drawScene() {

    // Sky color
    glClearColor(0.348, 0.606, 0.790, 1.0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //gluLookAt(15.0, -5.0, 30.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    gluLookAt(15.0, -6.0, 30.0, -5.0, 6.0, 0.0, 0.0, 1.0, 0.0); //Updated angle

    drawObjects();

    glFlush();
    //glutSwapBuffers();

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    //glutInitWindowSize(400, 400);
    glutCreateWindow("Prescott Building");

    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(60, 1, 10, 200);

    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(drawScene);
    glutMainLoop();

    return 0;

}
