#include <GLFW/glfw3.h>

#ifndef MODEL_H
    #define MODEL_H
    #include "Model.h"
#endif

#define RECTPRISM_VERTICES 180
#define RECTPRISM_SIDES 6

class RectPrism : public Model
{
private:
    GLfloat _x, _y, _z;     //Location of corner
    GLfloat _dx, _dy, _dz;  //Width, height, depth
    GLfloat* _vertices;     //Pointer to vertex array
public:
    RectPrism(GLfloat x, GLfloat y, GLfloat z, GLfloat dx, GLfloat dy, GLfloat dz);
    ~RectPrism();
    GLfloat* getVertices();
    int arrSize();
};