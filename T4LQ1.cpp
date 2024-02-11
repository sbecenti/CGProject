// -lGL -lGLU -lglut

#include <GL/glut.h>
#include <GL/gl.h>

void drawObjects() {

    // ===================================================
    //                  Draw Building
    // ===================================================

    glBegin(GL_QUADS);

    // Front face of building
    glColor3f(0.96, 0.87, 0.70);
    glVertex3f(-17.5, -5.5, 5.0); // Bottom-left
    glVertex3f(7.5, -5.5, 5.0);   // Bottom-right
    glVertex3f(7.5, 5.0, 5.0);    // Top-right
    glVertex3f(-17.5, 5.0, 5.0);  // Top-left

    // Right face of building
    glColor3f(0.76, 0.67, 0.50);
    glVertex3f(7.5, -5.5, 5.0);    // Bottom-front
    glVertex3f(7.5, -5.5, -55.0);  // Bottom-back
    glVertex3f(7.5, 5.0, -55.0);   // Top-back
    glVertex3f(7.5, 5.0, 5.0);     // Top-front

    //Corner Pillar (right-front)
    glColor3f(0.6, 0.2, 0.2);//Front face
    glVertex3f(6.0, -5.5, 6.0); // Bottom-left
    glVertex3f(9.0, -5.5, 6.0); // Bottom-right
    glVertex3f(9.0, 5.0, 6.0);  // Top-right
    glVertex3f(6.0, 5.0, 6.0);  // Top-left
    
    glColor3f(0.51, 0.12, 0.1);//Right face
    glVertex3f(9.0, -5.5, 6.0); // Bottom-left
    glVertex3f(9.0, -5.5, 2.0); // Bottom-right
    glVertex3f(9.0, 5.0, 2.0);  // Top-right
    glVertex3f(9.0, 5.0, 6.0);  // Top-left

    //Corner Pillar (left-front)
    glColor3f(0.6, 0.2, 0.2);//Front face
    glVertex3f(-19.0, -5.5, 6.0); // Bottom-left
    glVertex3f(-16.0, -5.5, 6.0); // Bottom-right
    glVertex3f(-16.0, 5.0, 6.0);  // Top-right
    glVertex3f(-19.0, 5.0, 6.0);  // Top-left

    glColor3f(0.51, 0.12, 0.1);//Right face
    glVertex3f(-16.0, -5.5, 6.0); // Bottom-left
    glVertex3f(-16.0, -5.5, 5.0); // Bottom-right
    glVertex3f(-16.0, 5.0, 5.0);  // Top-right
    glVertex3f(-16.0, 5.0, 6.0);  // Top-left

    //Corner Pillar (right-back)
    glColor3f(0.6, 0.2, 0.2);//Front face
    glVertex3f(6.0, -5.5, -52.0); // Bottom-left
    glVertex3f(9.0, -5.5, -52.0); // Bottom-right
    glVertex3f(9.0, 5.0, -52.0);  // Top-right
    glVertex3f(6.0, 5.0, -52.0);  // Top-left

    glColor3f(0.51, 0.12, 0.1);//Right face
    glVertex3f(9.0, -5.5, -52.0); // Bottom-left
    glVertex3f(9.0, -5.5, -56.0); // Bottom-right
    glVertex3f(9.0, 5.0, -56.0);  // Top-right
    glVertex3f(9.0, 5.0, -52.0);  // Top-left

    // Front face green sections (4 total)
    //  Right side of left pillar: x = -16
    //  Left side of right pillar: x = 6
    //  Differential: 6 - (-16) = 22
    //  Measured in 12 Intervals: 22/12
    GLfloat frontInt = (22.0)/12.0;
    for (int i = 0; i < 4; i++)
    {
        glColor3f(0.585, 0.730, 0.409);
        glVertex3f(-16.0 + frontInt * (1.0 + 3.0 * i), -5.5, 5.01); // Bottom-left
        glVertex3f(-16.0 + frontInt * (2.0 + 3.0 * i), -5.5, 5.01);   // Bottom-right
        glVertex3f(-16.0 + frontInt * (2.0 + 3.0 * i), 4.75, 5.01);    // Top-right
        glVertex3f(-16.0 + frontInt * (1.0 + 3.0 * i), 4.75, 5.01);  // Top-left
    }

    // Front face windows
    GLfloat windowYInt = 1.75;
    glColor3f(0.3, 0.3, 0.5);
    for  (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            glVertex3f(-16.0 + i       * frontInt + 0.50,  3.25 - (windowYInt * j), 5.02); // Bottom-left
            glVertex3f(-16.0 + (i + 1) * frontInt - 0.50,  3.25 - (windowYInt * j), 5.02);   // Bottom-right
            glVertex3f(-16.0 + (i + 1) * frontInt - 0.50,  3.75 - (windowYInt * j), 5.02);    // Top-right
            glVertex3f(-16.0 + i       * frontInt + 0.50,  3.75 - (windowYInt * j), 5.02);  // Top-left
        }
    }

    //Right face green sections (6 total)
    //  Back side of front pillar: x = -52
    //  Front side of back pillar: x = 2
    //  Differential: 2 - (-52) = 54
    //  18 Intervals: 54/21
    //      3 intervals left blank -- hidden by brick pillar
    GLfloat sideInt = (54.0)/21.0;
    glColor3f(0.475, 0.620, 0.299);
    for (int i = 0; i < 6; i++)
    {
        glVertex3f(7.51, -5.5,  -52 + sideInt * (2.0 + 3.0 * i));  // Bottom-left
        glVertex3f(7.51, -5.5,  -52 + sideInt * (1.0 + 3.0 * i));  // Bottom-right
        glVertex3f(7.51,  4.75, -52 + sideInt * (1.0 + 3.0 * i));  // Top-right
        glVertex3f(7.51,  4.75, -52 + sideInt * (2.0 + 3.0 * i));  // Top-left
    }

    // Side face windows
    GLfloat windowZInt = sideInt * 1.5; //Side windows have a different spacing from green sections
    glColor3f(0.3, 0.3, 0.5);
    for  (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            glVertex3f(7.52, 3.25 - (windowYInt * j), -50.0 + windowZInt * i       + 1.10); // Bottom-left
            glVertex3f(7.52, 3.25 - (windowYInt * j), -50.0 + windowZInt * (i + 1) - 1.10);   // Bottom-right
            glVertex3f(7.52, 3.75 - (windowYInt * j), -50.0 + windowZInt * (i + 1) - 1.10);    // Top-right
            glVertex3f(7.52, 3.75 - (windowYInt * j), -50.0 + windowZInt * i       + 1.10);  // Top-left
        }
    }

    //Brick lining
    glColor3f(0.55, 0.16, 0.16);//Front face
    glVertex3f(-17.5, -5.5, 5.02); // Bottom-left
    glVertex3f( 7.5,  -5.5, 5.02);   // Bottom-right
    glVertex3f( 7.5,  -3.0, 5.02);    // Top-right
    glVertex3f(-17.5, -3.0, 5.02);  // Top-left

    // Right face of building
    glColor3f(0.46, 0.09, 0.07);//Right face
    glVertex3f(7.52, -5.5, 5.0);    // Bottom-front
    glVertex3f(7.52, -5.5, -55.0);  // Bottom-back
    glVertex3f(7.52, -3.0, -55.0);   // Top-back
    glVertex3f(7.52, -3.0, 5.0);     // Top-front

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

    glFlush();
    //glutSwapBuffers();

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutCreateWindow("#D Building");

    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(60, 1, 10, 200);

    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(drawScene);
    glutMainLoop();

    return 0;

}
