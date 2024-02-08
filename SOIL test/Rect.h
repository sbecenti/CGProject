#include <GLFW/glfw3.h>

#ifndef MODEL_H
    #define MODEL_H
    #include "Model.h"
#endif

#define RECT_VERTICES 30
#define RECT_SIDES 1

class Rect : public Model
{
private:
    GLfloat _x, _y;     //Location of corner
    GLfloat _dx, _dy;  //Width, height
    GLfloat* _vertices;     //Pointer to vertex array
public:
    Rect(GLfloat x, GLfloat y, GLfloat dx, GLfloat dy);
    ~Rect();
    GLfloat* getVertices();
    int arrSize();
};