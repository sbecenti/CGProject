#include <GLFW/glfw3.h>

#include "Rect.h"

Rect::Rect(GLfloat x, GLfloat y, GLfloat dx, GLfloat dy)
{
    _x = x;
    _y = y;
    _dx = dx;
    _dy = dy;
    
    _vertices = new GLfloat[RECT_VERTICES]{
        //Back
        x + dx, y + dy, 0,  1.0f, 1.0f, //Top Right
        x + dx, y,      0,  0.0f, 0.0f, //Bottom Right
        x,      y + dy, 0,  0.0f, 1.0f, //Top Left
        x,      y + dy, 0,  1.0f, 1.0f, //Top Left
        x + dx, y,      0,  1.0f, 0.0f, //Bottom Right
        x,      y,      0,  0.0f, 0.0f, //Bottom Left
    };
}

Rect::~Rect()
{
    delete _vertices;
}

GLfloat* Rect::getVertices()
{
    return _vertices;
}

/*
*   arrSize()
*   
*   Use this instead of sizeof() on this.getVertices(). Workaround for finding array size of a RectPrism's array.
*/
int Rect::arrSize()
{
    return RECT_VERTICES * sizeof(GLfloat);
}