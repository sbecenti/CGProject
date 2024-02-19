// Samson Becenti & Spencer Meren
// CST-310

// -lGL -lGLU -lglut -lSOIL -lglfw
// Use to easily pick colors: https://antongerdelan.net/colour/

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
//#include <GLFW/glfw3.h>
//#include <GL/glew.h>
#include <SOIL/SOIL.h>
#include <cmath>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <cstdio>


#include "objects/building.cpp"
#include "objects/floor.cpp"
#include "objects/tree.cpp"
#include "objects/pole.cpp"

GLuint brickTexture;    //texture for brick
GLuint grassTexture;    // grass
GLuint poleTexture;     // light pole

void drawPerson() {
    // Draw oval to represent a person
    glColor3f(0.403, 0.585, 0.630);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float theta = 2.0f * M_PI * float(i) / float(100);
        float x = 0.35 * cosf(theta);
        float y = 0.75 * sinf(theta); // Varying height
        glVertex2f(x + 0, y + 0);
    }
    glEnd();
}

//TODO: GCBC Poster

void drawObjects() {

    // ===================================================
    //                  Draw Building
    // ===================================================
    
    drawBuilding(brickTexture);

    // ===================================================
    //                Draw Floor of Scene
    // ===================================================
    
    drawFloor();

    // ===================================================
    //                Draw Objects of Scene
    // ===================================================
    
    // Building in the far back left
    glPushMatrix();
    glTranslatef(-33.0, -7.0, 5.0);
    glBegin(GL_POLYGON);
    glColor3f(0.96, 0.87, 0.70);
    glVertex2f(15.0, 0.0); //Bottom-left
    glVertex2f(0.0, 0.0); //Bottom-right
    glVertex2f(0.0, 5.0); //Top-right
    glVertex2f(15.0, 5.0); //Top-left
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-22.0, -6.0, 6.0);
    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.81, 0.64);
    glVertex2f(5.0, 0.0); //Bottom-left
    glVertex2f(0.0, 0.0); //Bottom-right
    glVertex2f(0.0, 5.0); //Top-right
    glVertex2f(5.0, 5.0); //Top-left
    glEnd();
    glPopMatrix();

    // window
    glPushMatrix();
    glTranslatef(-25.0, -5.0, 6.0);
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3, 0.5);
    glVertex2f(2.0, 0.0); //Bottom-left
    glVertex2f(0.0, 0.0); //Bottom-right
    glVertex2f(0.0, 1.0); //Top-right
    glVertex2f(2.0, 1.0); //Top-left
    glEnd();
    glPopMatrix();

    // roof
    glPushMatrix();
    glTranslatef(-30.0, -3.5, 7.0);
    glRotatef(-45, 1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.55, 0.16, 0.16);
    glVertex2f(10.0, 0.0); //Bottom-left
    glVertex2f(0.0, 0.0); //Bottom-right
    glVertex2f(0.0, 2.0); //Top-right
    glVertex2f(10.0, 2.0); //Top-left
    glEnd();
    glPopMatrix();

    
    // Purple fence
    //Horizontal bar
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.0, 0.5);
    glVertex3f(-27.5, -5.7, 7.5);  // Bottom-left
    glVertex3f(8.5, -5.7, 7.5);   // Bottom-right
    glVertex3f(8.5, -5.6, 7.5);   // Top-right
    glVertex3f(-27.5, -5.6, 7.5);  // Top-left
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.0, 0.5);
    glVertex3f(12.0, -5.7, 7.5);  // Bottom-left
    glVertex3f(17.0, -5.7, 7.5);   // Bottom-right
    glVertex3f(17.0, -5.6, 7.5);   // Top-right
    glVertex3f(12.0, -5.6, 7.5);  // Top-left
    glEnd();

    //Vertical Bars
    int i = 0;
    for (float x = -27.5; x <= 17.0; x+=0.25) {
        i++;
        if (x < 8.5 || x > 11.5) {
            if ((i % 5) == 0) {
                glBegin(GL_QUADS);
                glColor3f(0.5, 0.0, 0.5);
                glVertex3f(x, -6.5, 7.5);  // Bottom-left
                glVertex3f(x + 0.2, -6.5, 7.5);   // Bottom-right
                glVertex3f(x + 0.2, -5.7, 7.5);   // Top-right
                glVertex3f(x, -5.7, 7.5);  // Top-left
                glEnd();
            }
            else {
                glBegin(GL_QUADS);
                glColor3f(0.5, 0.0, 0.5);
                glVertex3f(x, -6.5, 7.5);  // Bottom-left
                glVertex3f(x + 0.1, -6.5, 7.5);   // Bottom-right
                glVertex3f(x + 0.1, -5.7, 7.5);   // Top-right
                glVertex3f(x, -5.7, 7.5);  // Top-left
                glEnd();
            }
        }
    }
    
    // Light Pole
    drawLightpole(poleTexture);
    //glPushMatrix();
    //glColor3f(0.760, 0.768, 0.768); // Grey color for the pole
    //glTranslatef(13.0, -5, 10.0);
    //glBegin(GL_POLYGON);
    //glVertex2f(0.5, -3.0); // Bottom-left
    //glVertex2f(0.0, -3.0); //Bottom-right
    //glVertex2f(0.0, 20);   //Top-right
    //glVertex2f(0.5, 20);   //Top-left
    //glEnd();
    //glPopMatrix();

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

    // shadow
    glPushMatrix();
    glTranslatef(-14.0, -7.0, 10.0);
    glRotatef(-80, 1.0, 0.0, 0.0);
    glRotatef(65.0, 0.0, 0.0, 1.0);
    glRotatef(2.0, 0.0, 1.0, 0.0);
    glScalef(0.5, 0.5, 0.5);
    drawTreeShadow();
    glPopMatrix();

    // Right Tree
    glPushMatrix();
    glTranslatef(-1.0, -2.5, 10.0);
    drawTree();
    glPopMatrix();

    // shadow
    glPushMatrix();
    glTranslatef(-3.0, -7.0, 10.0);
    glRotatef(-80, 1.0, 0.0, 0.0);
    glRotatef(65.0, 0.0, 0.0, 1.0);
    glRotatef(2.0, 0.0, 1.0, 0.0);
    glScalef(0.5, 0.5, 0.5);
    drawTreeShadow();
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
    for(float angle = -45.0; angle <= 45.0; angle += 30.0) {
        glPushMatrix();
        glRotatef(angle, 0.0, 0.0, 1.0); // Apply rotation
        glBegin(GL_POLYGON);
        glVertex2f(0.2, 0);  
        glVertex2f(0.1, 2);
        glVertex2f(-0.1, 2);
        glVertex2f(-0.2, 0);
        glEnd();
        glPopMatrix(); 
    }
    glPopMatrix();

    // Draw people
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        float x = -15.0 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 30.0)); // Random x within range
        float y = -5.5;
        float z = 7.4;

        glPushMatrix();
        glTranslatef(x, y, z);
        drawPerson();
        glPopMatrix();
    }

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
    glutInitWindowSize(800, 800);
    glutCreateWindow("Prescott Building");

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND); // Enable blending for transparency
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Set blending function

    // Texture initialization
    glGenTextures(1, &brickTexture);
    brickTexture = SOIL_load_OGL_texture("brick-wall.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    //brickTexture = SOIL_load_OGL_texture("metal-pole.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    //brickTexture = SOIL_load_OGL_texture("grass.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, brickTexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //Pole Texture seems to be non-functional-- will fix later
    glGenTextures(1, &poleTexture);
    poleTexture = SOIL_load_OGL_texture("metal-pole.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    //brickTexture = SOIL_load_OGL_texture("metal-pole.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    //brickTexture = SOIL_load_OGL_texture("grass.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, poleTexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(60, 1, 10, 200);

    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(drawScene);
    glutMainLoop();

    return 0;

}
