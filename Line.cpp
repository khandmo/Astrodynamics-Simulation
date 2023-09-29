#include "Line.h"

Line::Line(glm::vec3 start, glm::vec3 end, Shader* lineProgram) {

    lineShader = lineProgram;
    startPoint = start;
    endPoint = end;
    lineColor = glm::vec3(1, 1, 1);

    Vertex lineV[2] = {
        glm::vec3(start.x, start.y, start.z), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec2(0, 0),
        glm::vec3(end.x, end.y, end.z), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec2(0, 0) };

    std::vector <Vertex> vertices(lineV, lineV + sizeof(lineV) / sizeof(Vertex));

    VAO.Bind();
    VBO VBO(vertices);


    VAO.LinkAttrib(VBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);

    VAO.Unbind();
    VBO.Unbind();
}


int Line::setColor(glm::vec3 color) {
    lineColor = color;
    return 1;
}

int Line::draw(Camera& camera) {
    (*lineShader).Activate();
    glUniform3fv(glGetUniformLocation((*lineShader).ID, "color"), 1, &lineColor[0]);
    camera.Matrix((*lineShader), "MVP");

    VAO.Bind();
    glDrawArrays(GL_LINES, 0, 2);
    return 1;
}

Line::~Line() {
    VAO.Delete();
    (*lineShader).Delete();
}