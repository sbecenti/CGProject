#include <GLFW/glfw3.h>

#include "RectPrism.h"

RectPrism::RectPrism(GLfloat x, GLfloat y, GLfloat z, GLfloat dx, GLfloat dy, GLfloat dz)
{
    _x = x;
    _y = y;
    _z = z;
    _dx = dx;
    _dy = dy;
    _dz = dz;
    
    _vertices = new GLfloat[RECTPRISM_VERTICES]{
        //Back
        x,      y + dy, z,       1.0f, 1.0f, //Top Right
        x,      y,      z,       0.0f, 0.0f, //Bottom Right
        x + dx, y + dy, z,       0.0f, 1.0f, //Top Left
        x + dx, y + dy, z,       1.0f, 1.0f, //Top Left
        x,      y,      z,       1.0f, 0.0f, //Bottom Right
        x + dx, y,      z,       0.0f, 0.0f, //Bottom Left
        //Front
        x + dx, y + dy, z + dz,  1.0f, 1.0f, //Top Right
        x + dx, y,      z + dz,  0.0f, 0.0f, //Bottom Right
        x,      y + dy, z + dz,  0.0f, 1.0f, //Top Left
        x,      y + dy, z + dz,  1.0f, 1.0f, //Top Left
        x + dx, y,      z + dz,  1.0f, 0.0f, //Bottom Right
        x,      y,      z + dz,  0.0f, 0.0f, //Bottom Left
        //Left
        x,      y + dy, z + dz,  1.0f, 1.0f, //Top Right
        x,      y,      z + dz,  0.0f, 0.0f, //Bottom Right
        x,      y + dy, z,       0.0f, 1.0f, //Top Left
        x,      y + dy, z,       1.0f, 1.0f, //Top Left
        x,      y,      z + dz,  1.0f, 0.0f, //Bottom Right
        x,      y,      z,       0.0f, 0.0f, //Bottom Left
        //Right
        x + dx, y + dy, z,       1.0f, 1.0f, //Top Right
        x + dx, y,      z,       0.0f, 0.0f, //Bottom Right
        x + dx, y + dy, z + dz,  0.0f, 1.0f, //Top Left
        x + dx, y + dy, z + dz,  1.0f, 1.0f, //Top Left
        x + dx, y,      z,       1.0f, 0.0f, //Bottom Right
        x + dx, y,      z + dz,  0.0f, 0.0f, //Bottom Left
        //Top
        x,      y,      z + dz,  1.0f, 1.0f, //Top Right
        x,      y,      z,       0.0f, 0.0f, //Bottom Right
        x + dx, y,      z + dz,  0.0f, 1.0f, //Top Left
        x + dx, y,      z + dz,  1.0f, 1.0f, //Top Left
        x,      y,      z,       1.0f, 0.0f, //Bottom Right
        x + dx, y,      z,       0.0f, 0.0f, //Bottom Left
        //Bottom
        x + dx, y + dy, z + dz,  1.0f, 1.0f,
        x + dx, y + dy, z,       0.0f, 0.0f,
        x,      y + dy, z + dz,  0.0f, 1.0f,
        x,      y + dy, z + dz,  1.0f, 1.0f,
        x + dx, y + dy, z,       1.0f, 0.0f,
        x,      y + dy, z,       0.0f, 0.0f
    };
}

RectPrism::~RectPrism()
{
    delete _vertices;
}

GLfloat* RectPrism::getVertices()
{
    return _vertices;
}

/*
*   arrSize()
*   
*   Use this instead of sizeof() on this.getVertices(). Workaround for finding array size of a RectPrism's array.
*/
int RectPrism::arrSize()
{
    return RECTPRISM_VERTICES * sizeof(GLfloat);
}