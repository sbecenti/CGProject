// -lGL -lGLU -lglut -lSOIL

#include <GL/glut.h>
#include <GL/gl.h>
#include <SOIL/SOIL.h>
#include <cmath>

void drawObjects() {

    // ===================================================
    //                  Draw Building
    // ===================================================

    glBegin(GL_QUADS);

    // Front face of building (red)
    glColor3f(0.6, 0.3, 0.0);
    glVertex3f(-17.5, -5.5, 5.0); // Bottom-left
    glVertex3f(7.5, -5.5, 5.0);   // Bottom-right
    glVertex3f(7.5, 5.0, 5.0);    // Top-right
    glVertex3f(-17.5, 5.0, 5.0);  // Top-left

    // Right face of building (blue)
    glColor3f(0.4, 0.2, 0.0);
    glVertex3f(7.5, -5.5, 5.0);    // Bottom-front
    glVertex3f(7.5, -5.5, -55.0);  // Bottom-back
    glVertex3f(7.5, 5.0, -55.0);   // Top-back
    glVertex3f(7.5, 5.0, 5.0);     // Top-front

    glEnd();

    // ===================================================
    //                Draw Floor of Scene
    // ===================================================
    
    // Slope going across screen
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-27.5, -8.0, 15.0); // Bottom-left
    glVertex3f(17.5, -8.0, 15.0);  // Bottom-right
    glVertex3f(17.5, -6.5, 5.0);    // Top-right
    glVertex3f(-27.5, -6.5, 5.0);   // Top-left
    glEnd();
    

    glBegin(GL_QUADS);

    // Field floor (very bottom)
    glColor3f(0.0, 0.5, 0.0);
    glVertex3f(-27.5, -10.0, 25.0); // Bottom-left
    glVertex3f(17.5, -15.0, 25.0);  // Bottom-right
    glVertex3f(17.5, -8.0, 15.0);    // Top-right
    glVertex3f(-27.5, -8.0, 15.0);   // Top-left

    // ===================================================
    //                Draw Objects of Scene
    // ===================================================
    
    // Purple fence
    glColor3f(0.5, 0.0, 0.5);
    glVertex3f(-27.5, -6.5, 5.0);  // Bottom-left
    glVertex3f(17.5, -6.5, 5.0);   // Bottom-right
    glVertex3f(17.5, -5.5, 5.0);   // Top-right
    glVertex3f(-27.5, -5.5, 5.0);  // Top-left

    glEnd();


    // Trees
    glPushMatrix();

    glTranslatef(-8.0, -2.5, 10.0);

     // Draw trunk
    glColor3f(0.5, 0.35, 0.05); // Brown color for the trunk
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -5);  // multiply each coordinate by 10
    glVertex2f(0.5, -5);
    glVertex2f(0.5, 0);
    glVertex2f(-0.5, 0);
    glEnd();

    // Draw branches
    // glColor3f(0.0, 0.8, 0.0); // Green color for the branches
    // glBegin(GL_POLYGON);
    // for (float angle = 0; angle < 2 * M_PI; angle += 0.1) {
    //     float x = 10 * sin(angle);
    //     float y = 20 + 10 * cos(angle);
    //     glVertex2f(x, y); // multiply each coordinate by 10
    // }

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-1.0, -2.5, 10.0);

     // Draw trunk
    glColor3f(0.5, 0.35, 0.05); // Brown color for the trunk
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -5);  // multiply each coordinate by 10
    glVertex2f(0.5, -5);
    glVertex2f(0.5, 0);
    glVertex2f(-0.5, 0);
    glEnd();

    // Draw branches
    // Draw branches
    // glColor3f(0.0, 0.8, 0.0); // Green color for the branches
    // glBegin(GL_POLYGON);
    // for (float angle = 0; angle < 2 * M_PI; angle += 0.1) {
    //     float x = 10 * sin(angle);
    //     float y = 20 + 10 * cos(angle);
    //     glVertex2f(x, y); // multiply each coordinate by 10
    // }

    glPopMatrix();



    
    glutSwapBuffers();
}

void drawScene() {

    // Sky color
    glClearColor(0.5, 0.8, 1.0, 1.0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(15.0, -5.0, 30.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    drawObjects();

    glutSwapBuffers();

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("#D Building");

    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(60, 1, 10, 200);

    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(drawScene);
    glutMainLoop();

    return 0;

}
