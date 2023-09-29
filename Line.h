#ifndef LINE_H
#define LINE_H

#include <vector>
#include "VAO.h"
#include "cameraClass.h"
#include "shaderClass.h"

class Line {
public:
    Shader* lineShader;
    std::vector<float> vertices;
    glm::vec3 startPoint;
    glm::vec3 endPoint;
    glm::vec3 lineColor;

    VAO VAO;

    Line(glm::vec3 start, glm::vec3 end, Shader* lineProgram);

    int setColor(glm::vec3 color);

    int draw(Camera& camera);

    ~Line();
};

#endif
