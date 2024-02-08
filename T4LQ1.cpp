// -lGL -lGLU -lglut

#include <GL/glut.h>
#include <GL/gl.h>

void drawObjects() {

    // ===================================================
    //                  Draw Building
    // ===================================================

    glBegin(GL_QUADS);

    // Front face of building
    glColor3f(0.6, 0.3, 0.0);
    glVertex3f(-17.5, -5.5, 5.0); // Bottom-left
    glVertex3f(7.5, -5.5, 5.0);   // Bottom-right
    glVertex3f(7.5, 5.0, 5.0);    // Top-right
    glVertex3f(-17.5, 5.0, 5.0);  // Top-left

    // Right face of building
    glColor3f(0.4, 0.2, 0.0);
    glVertex3f(7.5, -5.5, 5.0);    // Bottom-front
    glVertex3f(7.5, -5.5, -55.0);  // Bottom-back
    glVertex3f(7.5, 5.0, -55.0);   // Top-back
    glVertex3f(7.5, 5.0, 5.0);     // Top-front

    //Corner Pillar (left-front)
    glColor3f(0.6, 0.2, 0.2);//Front face
    glVertex3f(6.0, -5.5, 6.0); // Bottom-left
    glVertex3f(9.0, -5.5, 6.0); // Bottom-right
    glVertex3f(9.0, 5.0, 6.0);  // Top-right
    glVertex3f(6.0, 5.0, 6.0);  // Top-left

    //glColor3f(0.6, 0.2, 0.2);//Right face
    glVertex3f(9.0, -5.5, 6.0); // Bottom-left
    glVertex3f(9.0, -5.5, 2.0); // Bottom-right
    glVertex3f(9.0, 5.0, 2.0);  // Top-right
    glVertex3f(9.0, 5.0, 6.0);  // Top-left

    //Corner Pillar (right-front, red front, blue side)
    glColor3f(0.6, 0.2, 0.2);//Front face
    glVertex3f(-19.0, -5.5, 6.0); // Bottom-left
    glVertex3f(-16.0, -5.5, 6.0); // Bottom-right
    glVertex3f(-16.0, 5.0, 6.0);  // Top-right
    glVertex3f(-19.0, 5.0, 6.0);  // Top-left

    //glColor3f(0.6, 0.2, 0.2);//Right face
    glVertex3f(-16.0, -5.5, 6.0); // Bottom-left
    glVertex3f(-16.0, -5.5, 5.0); // Bottom-right
    glVertex3f(-16.0, 5.0, 5.0);  // Top-right
    glVertex3f(-16.0, 5.0, 6.0);  // Top-left

    // Front face green sections (4 total)
    int interval = (22.0)/9.0; //6-(-16) = distance between pillars
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-16.0 + interval * 1.0, -5.5, 5.01); // Bottom-left
    glVertex3f(-16.0 + interval * 2.0, -5.5, 5.01);   // Bottom-right
    glVertex3f(-16.0 + interval * 2.0, 5.0, 5.01);    // Top-right
    glVertex3f(-16.0 + interval * 1.0, 5.0, 5.01);  // Top-left

    glVertex3f(-16.0 + interval * 4.0, -5.5, 5.01); // Bottom-left
    glVertex3f(-16.0 + interval * 5.0, -5.5, 5.01);   // Bottom-right
    glVertex3f(-16.0 + interval * 5.0, 5.0, 5.01);    // Top-right
    glVertex3f(-16.0 + interval * 4.0, 5.0, 5.01);  // Top-left

    glVertex3f(-16.0 + interval * 7.0, -5.5, 5.01); // Bottom-left
    glVertex3f(-16.0 + interval * 8.0, -5.5, 5.01);   // Bottom-right
    glVertex3f(-16.0 + interval * 8.0, 5.0, 5.01);    // Top-right
    glVertex3f(-16.0 + interval * 7.0, 5.0, 5.01);  // Top-left

    glVertex3f(-16.0 + interval * 10.0, -5.5, 5.01); // Bottom-left
    glVertex3f(-16.0 + interval * 11.0, -5.5, 5.01);   // Bottom-right
    glVertex3f(-16.0 + interval * 11.0, 5.0, 5.01);    // Top-right
    glVertex3f(-16.0 + interval * 10.0, 5.0, 5.01);  // Top-left

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
    
    //Concrete Slope
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(4.0, -8.0, 15.01); // Bottom-left
    glVertex3f(12.0, -8.0, 15.01);  // Bottom-right
    glVertex3f(12.0, -6.5, 5.01);    // Top-right
    glVertex3f(4.0, -6.5, 5.01);   // Top-left
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
