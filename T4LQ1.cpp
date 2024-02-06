// -lGL -lGLU -lglut

#include <GL/glut.h>

void drawObjects() {

    // ===================================================
    // Draw rectangular prism (front and side of building)
    // ===================================================

    glBegin(GL_QUADS);

    // Front face (red)
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-1.75, -0.5, 0.5); // Bottom-left
    glVertex3f(0.75, -0.5, 0.5);  // Bottom-right
    glVertex3f(0.75, 0.5, 0.5);   // Top-right
    glVertex3f(-1.75, 0.5, 0.5);  // Top-left

    // Right face (blue)
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.75, -0.5, 0.5);   // Bottom-front
    glVertex3f(0.75, -0.5, -3.5);  // Bottom-back
    glVertex3f(0.75, 0.5, -3.5);   // Top-back
    glVertex3f(0.75, 0.5, 0.5);    // Top-front

    // ===================================================
    //     Draw rectangular shape (floor of the scene)
    // ===================================================

    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-1.75, -0.5, 0.5); // Bottom-left
    glVertex3f(0.75, -0.5, 0.5);  // Bottom-right
    glVertex3f(0.75, 0.5, 0.5);   // Top-right
    glVertex3f(-1.75, 0.5, 0.5);  // Top-left


    
    glEnd();

    glutSwapBuffers();
}

void drawScene() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(2, -1, 3, 0, 0, 0, 0, 1, 0);

    drawObjects();

    glutSwapBuffers();

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("#D Building");

    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(60, 1, 1, 20);

    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(drawScene);
    glutMainLoop();

    return 0;

}