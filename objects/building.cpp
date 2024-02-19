#include <GL/glut.h>
#include <GL/gl.h>
#include <SOIL/SOIL.h>
#include <cmath>

void drawBuilding(GLuint brickTexture) {
    // ===================================================
    //                  Draw Building
    // ===================================================

    glBindTexture(GL_TEXTURE_2D, brickTexture);

    // Brick section

    //Corner Pillar (right-front)
    glBegin(GL_QUADS);
    //glColor3f(0.6, 0.2, 0.2);//Front face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(6.0, -8.5, 6.0); // Bottom-left
    glTexCoord2f(1.0f, 0.0f); glVertex3f(9.0, -8.5, 6.0); // Bottom-right
    glTexCoord2f(1.0f, 1.0f); glVertex3f(9.0, 5.0, 6.0);  // Top-right
    glTexCoord2f(0.0f, 1.0f); glVertex3f(6.0, 5.0, 6.0);  // Top-left
   
    //glColor3f(0.51, 0.12, 0.1);//Right face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(9.0, -8.5, 6.0); // Bottom-left
    glTexCoord2f(1.0f, 0.0f); glVertex3f(9.0, -8.5, 2.0); // Bottom-right
    glTexCoord2f(1.0f, 1.0f); glVertex3f(9.0, 5.0, 2.0);  // Top-right
    glTexCoord2f(0.0f, 1.0f); glVertex3f(9.0, 5.0, 6.0);  // Top-left
	glEnd();

    //Corner Pillar (left-front)
    glBegin(GL_QUADS);
    //glColor3f(0.6, 0.2, 0.2);//Front face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-19.0, -8.5, 6.0); // Bottom-left
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-16.0, -8.5, 6.0); // Bottom-right
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-16.0, 5.0, 6.0);  // Top-right
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-19.0, 5.0, 6.0);  // Top-left

    //glColor3f(0.51, 0.12, 0.1);//Right face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-16.0, -8.5, 6.0); // Bottom-left
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-16.0, -8.5, 5.0); // Bottom-right
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-16.0, 5.0, 5.0);  // Top-right
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-16.0, 5.0, 6.0);  // Top-left
	glEnd();

    //Corner Pillar (right-back)
    glBegin(GL_QUADS);
    //glColor3f(0.6, 0.2, 0.2);//Front face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(6.0, -8.5, -52.0); // Bottom-left
    glTexCoord2f(1.0f, 0.0f); glVertex3f(9.0, -8.5, -52.0); // Bottom-right
    glTexCoord2f(1.0f, 1.0f); glVertex3f(9.0, 5.0, -52.0);  // Top-right
    glTexCoord2f(0.0f, 1.0f); glVertex3f(6.0, 5.0, -52.0);  // Top-left

    //glColor3f(0.51, 0.12, 0.1);//Right face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(9.0, -8.5, -52.0); // Bottom-left
    glTexCoord2f(1.0f, 0.0f); glVertex3f(9.0, -8.5, -56.0); // Bottom-right
    glTexCoord2f(1.0f, 1.0f); glVertex3f(9.0, 5.0, -56.0);  // Top-right
    glTexCoord2f(0.0f, 1.0f); glVertex3f(9.0, 5.0, -52.0);  // Top-left
	glEnd();

    //Brick lining front
    glBegin(GL_QUADS);
    //glColor3f(0.55, 0.16, 0.16);//Front face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-17.5, -8.5, 5.02); // Bottom-left
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 7.5,  -8.5, 5.02);   // Bottom-right
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 7.5,  -4.0, 5.02);    // Top-right
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-17.5, -4.0, 5.02);  // Top-left
	glEnd();

    // RBrick lining right
    glBegin(GL_QUADS);
    //glColor3f(0.46, 0.09, 0.07);//Right face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(7.52, -8.5, 5.0);    // Bottom-front
    glTexCoord2f(1.0f, 0.0f); glVertex3f(7.52, -8.5, -55.0);  // Bottom-back
    glTexCoord2f(1.0f, 1.0f); glVertex3f(7.52, -4.0, -55.0);   // Top-back
    glTexCoord2f(0.0f, 1.0f); glVertex3f(7.52, -4.0, 5.0);     // Top-front
	glEnd();
    
    glDisable(GL_TEXTURE_2D);

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

     // Right face of building shadow
    glBegin(GL_QUADS);
    glColor4f(0.0, 0.0, 0.0, 0.7);
    glVertex3f(8.0, -8.5, 5.0);    // Bottom-front
    glVertex3f(8.0, -8.5, -55.0);  // Bottom-back
    glVertex3f(8.0, 2.0, -55.0);   // Top-back
    glVertex3f(8.0, 3.0, 5.0);     // Top-front
	glEnd();
	
    glFlush();	
}