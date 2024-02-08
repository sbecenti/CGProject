
#include <GLFW/glfw3.h>

class Model
{
public:
    virtual GLfloat* getVertices() = 0;
    virtual int arrSize() = 0;
};