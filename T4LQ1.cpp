// -lGL -lGLU -lglut -lSOIL
// Use to easily pick colors: https://antongerdelan.net/colour/

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

//TODO: GCBC Poster

void drawObjects() {

    // ===================================================
    //                  Draw Building
    // ===================================================

    glBegin(GL_QUADS);

    // Front face of building
    glBegin(GL_QUADS);
    glColor3f(0.96, 0.87, 0.70);
    glVertex3f(-17.5, -8.5, 5.0); // Bottom-left
    glVertex3f(7.5, -8.5, 5.0);   // Bottom-right
    glVertex3f(7.5, 5.0, 5.0);    // Top-right
    glVertex3f(-17.5, 5.0, 5.0);  // Top-left
	glEnd();

    // Right face of building
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.67, 0.50);
    glVertex3f(7.5, -8.5, 5.0);    // Bottom-front
    glVertex3f(7.5, -8.5, -55.0);  // Bottom-back
    glVertex3f(7.5, 5.0, -55.0);   // Top-back
    glVertex3f(7.5, 5.0, 5.0);     // Top-front
	glEnd();

    //Corner Pillar (right-front)
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.2, 0.2);//Front face
    glVertex3f(6.0, -8.5, 6.0); // Bottom-left
    glVertex3f(9.0, -8.5, 6.0); // Bottom-right
    glVertex3f(9.0, 5.0, 6.0);  // Top-right
    glVertex3f(6.0, 5.0, 6.0);  // Top-left
   
    glColor3f(0.51, 0.12, 0.1);//Right face
    glVertex3f(9.0, -8.5, 6.0); // Bottom-left
    glVertex3f(9.0, -8.5, 2.0); // Bottom-right
    glVertex3f(9.0, 5.0, 2.0);  // Top-right
    glVertex3f(9.0, 5.0, 6.0);  // Top-left
	glEnd();

    //Corner Pillar (left-front)
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.2, 0.2);//Front face
    glVertex3f(-19.0, -8.5, 6.0); // Bottom-left
    glVertex3f(-16.0, -8.5, 6.0); // Bottom-right
    glVertex3f(-16.0, 5.0, 6.0);  // Top-right
    glVertex3f(-19.0, 5.0, 6.0);  // Top-left

    glColor3f(0.51, 0.12, 0.1);//Right face
    glVertex3f(-16.0, -8.5, 6.0); // Bottom-left
    glVertex3f(-16.0, -8.5, 5.0); // Bottom-right
    glVertex3f(-16.0, 5.0, 5.0);  // Top-right
    glVertex3f(-16.0, 5.0, 6.0);  // Top-left
	glEnd();

    //Corner Pillar (right-back)
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.2, 0.2);//Front face
    glVertex3f(6.0, -8.5, -52.0); // Bottom-left
    glVertex3f(9.0, -8.5, -52.0); // Bottom-right
    glVertex3f(9.0, 5.0, -52.0);  // Top-right
    glVertex3f(6.0, 5.0, -52.0);  // Top-left

    glColor3f(0.51, 0.12, 0.1);//Right face
    glVertex3f(9.0, -8.5, -52.0); // Bottom-left
    glVertex3f(9.0, -8.5, -56.0); // Bottom-right
    glVertex3f(9.0, 5.0, -56.0);  // Top-right
    glVertex3f(9.0, 5.0, -52.0);  // Top-left
	glEnd();

    // Front face green sections (4 total)
    //  Right side of left pillar: x = -16
    //  Left side of right pillar: x = 6
    //  Differential: 6 - (-16) = 22
    //  Measured in 12 Intervals: 22/12
    GLfloat frontInt = (22.0)/12.0;
    glBegin(GL_QUADS);
    for (int i = 0; i < 4; i++)
    {
        glColor3f(0.585, 0.730, 0.409);
        glVertex3f(-16.0 + frontInt * (1.0 + 3.0 * i), -8.5, 5.01); // Bottom-left
        glVertex3f(-16.0 + frontInt * (2.0 + 3.0 * i), -8.5, 5.01);   // Bottom-right
        glVertex3f(-16.0 + frontInt * (2.0 + 3.0 * i), 4.75, 5.01);    // Top-right
        glVertex3f(-16.0 + frontInt * (1.0 + 3.0 * i), 4.75, 5.01);  // Top-left
    }
	glEnd();

    // Front face windows
    GLfloat windowYInt = 2.00;
    glColor3f(0.3, 0.3, 0.5);
    glBegin(GL_QUADS);
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
	glEnd();

    //Right face green sections (6 total)
    //  Back side of front pillar: x = -52
    //  Front side of back pillar: x = 2
    //  Differential: 2 - (-52) = 54
    //  18 Intervals: 54/21
    //      3 intervals left blank -- hidden by brick pillar
    GLfloat sideInt = (54.0)/21.0;
    glColor3f(0.475, 0.620, 0.299);
    glBegin(GL_QUADS);
    for (int i = 0; i < 6; i++)
    {
        glVertex3f(7.51, -8.5,  -52 + sideInt * (2.0 + 3.0 * i));  // Bottom-left
        glVertex3f(7.51, -8.5,  -52 + sideInt * (1.0 + 3.0 * i));  // Bottom-right
        glVertex3f(7.51,  4.75, -52 + sideInt * (1.0 + 3.0 * i));  // Top-right
        glVertex3f(7.51,  4.75, -52 + sideInt * (2.0 + 3.0 * i));  // Top-left
    }
	glEnd();

    // Side face windows
    GLfloat windowZInt = sideInt * 1.5; //Side windows have a different spacing from green sections
    glColor3f(0.3, 0.3, 0.5);
    glBegin(GL_QUADS);
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
	glEnd();

    //Brick lining
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.16, 0.16);//Front face
    glVertex3f(-17.5, -8.5, 5.02); // Bottom-left
    glVertex3f( 7.5,  -8.5, 5.02);   // Bottom-right
    glVertex3f( 7.5,  -4.0, 5.02);    // Top-right
    glVertex3f(-17.5, -4.0, 5.02);  // Top-left
	glEnd();

    // Right face of building
    glBegin(GL_QUADS);
    glColor3f(0.46, 0.09, 0.07);//Right face
    glVertex3f(7.52, -8.5, 5.0);    // Bottom-front
    glVertex3f(7.52, -8.5, -55.0);  // Bottom-back
    glVertex3f(7.52, -4.0, -55.0);   // Top-back
    glVertex3f(7.52, -4.0, 5.0);     // Top-front
	glEnd();
    

    //GCBC Poster
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(6.5, 0.5, 6.01); // Bottom-left
    glVertex3f(8.5, 0.5, 6.01); // Bottom-right
    glVertex3f(8.5, 4.0, 6.01);  // Top-right
    glVertex3f(6.5, 4.0, 6.01);  // Top-left

    glColor3f(0.6, 0, 0.8);
    glVertex3f(6.5, 1.25, 6.02); // Bottom-left
    glVertex3f(8.5, 1.25, 6.02); // Bottom-right
    glVertex3f(8.5, 2.75, 6.02);  // Top-right
    glVertex3f(6.5, 2.75, 6.02);  // Top-left
	glEnd();

    glBegin(GL_POINTS);
    glColor3f(0.6, 0, 0.8);
    //glColor3f(0.0, 1.0, 0.0);
	for(GLdouble x = 0; x <= 2.0 ; x += 0.005)
    {	
	    GLdouble topText = 0.50 * cos(6*x); 
        glVertex3d(x + 6.5, topText + 3.50, 6.02); //Top Text

	    GLdouble bottomText = 0.30 * cos(8*x); 
        glVertex3d(x + 6.5, bottomText + 0.80, 6.02); //Bottom Text
 	}
	glEnd();	
	
    glFlush();	

    // ===================================================
    //                Draw Floor of Scene
    // ===================================================
    
    // Slope going across screen
    glBegin(GL_QUADS);
    glColor3f(0.363, 0.560, 0.353);
    //glColor3f(0.0, 1.0, 0.0);
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
    //glColor3f(0.0, 0.5, 0.0);
    glColor3f(0.385, 0.470, 0.381); //New color
    glVertex3f(-27.5, -10.0, 25.0); // Bottom-left
    glVertex3f(17.5, -15.0, 25.0);  // Bottom-right
    glVertex3f(17.5, -8.0, 15.0);    // Top-right
    glVertex3f(-27.5, -8.0, 15.0);   // Top-left

    glEnd();

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
    glEnd();
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
    glutCreateWindow("#D Building");

    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(60, 1, 10, 200);

    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(drawScene);
    glutMainLoop();

    return 0;

}
