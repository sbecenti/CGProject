#include <GL/glut.h>
#include <GL/gl.h>
#include <SOIL/SOIL.h>
#include <cmath>

//Texture credit: "Brushed Metal Texture" by SweetSoulSister
//  Link: https://www.deviantart.com/sweetsoulsister/art/Brushed-Metal-Silver-Texture-145936387

#define CYLINDER_FACES 20

void drawLightpole(GLuint poleTexture) {
    // ===================================================
    //                  Draw Light Pole
    // ===================================================
    
    glBindTexture(GL_TEXTURE_2D, poleTexture);

    // Right face of building
    double  poleX = 13.0f,
            poleY = -7.0f,
            poleZ = 10.0f;
    double radius = 0.5,
           height = 17;
    
    
    
    for (int i = 0; i < CYLINDER_FACES; i++)
    {
        double angle1 = i * (2.0 * M_PI / CYLINDER_FACES);
        double angle2 = (i + 1) * (2.0 * M_PI / CYLINDER_FACES);

        glBegin(GL_QUADS);
        glColor3f(0.760 - cos(angle1 + M_PI) * (0.25), 0.768 - cos(angle1 + M_PI) * (0.25), 0.768 - cos(angle1 + M_PI) * (0.25));
        //glColor3f(1.0, 1.0, 1.0);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(poleX + radius * cos(angle1), poleY,          poleZ + radius * sin(angle1));    // Bottom-left
        glTexCoord2f(1.0f, 0.0f); glVertex3f(poleX + radius * cos(angle2), poleY,          poleZ + radius * sin(angle2));    // Bottom-right
        glTexCoord2f(1.0f, 1.0f); glVertex3f(poleX + radius * cos(angle2), poleY + height, poleZ + radius * sin(angle2));    //Top-right
        glTexCoord2f(0.0f, 1.0f); glVertex3f(poleX + radius * cos(angle1), poleY + height, poleZ + radius * sin(angle1));    //Top-left
        glEnd();
    }
    glDisable(GL_TEXTURE_2D);
    
    //Electrical box
    double boxHeight = 5.0;
    /**
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(poleX - radius, poleY + boxHeight,       poleZ + radius + 0.5); // Bottom-left
    glVertex3f(poleX - radius, poleY + boxHeight,       poleZ + radius + 0.5); // Bottom-right
    glVertex3f(poleX + radius, poleY + height, poleZ + radius + 0.5);  // Top-right
    glVertex3f(poleX + radius, poleY + height, poleZ + radius + 0.5);  // Top-left
    glEnd();/**/

    //Shadow
    glColor4f(0.0, 0.0, 0.0, 0.7); // shadow color
    //glColor3f(0.51, 0.12, 0.1);//Right face
    glVertex3f(poleX - radius, poleY, poleZ - radius); // Bottom-left
    glVertex3f(poleX - radius, poleY, poleZ + radius); // Bottom-right
    glVertex3f(poleX + radius, poleY + height, poleZ + radius);  // Top-right
    glVertex3f(poleX + radius, poleY + height, poleZ - radius);  // Top-left
	glEnd();

    

}