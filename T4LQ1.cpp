// -lGL -lGLU -lglut

#include <GL/glut.h>

void drawObjects() {

    // Base of building
    glColor3f(0.82, 0.71, 0.55);
    glScalef(1.0, 0.5, 1.0);
    glutSolidCube(2);

}

void drawScene() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(3, 0, 1, 0, 0, 0, 0, 1, 0);

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