#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include <vector>
#include <glm/glm.hpp>
#include <glad/glad.h>

// Vertex structure to hold all data
struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 color;
	glm::vec2 tex;
};

class VBO {
public:
	// ID reference to VBO
	GLuint ID;
	// takes vertices and size in bytes
	VBO(std::vector <Vertex>& vertices);

	void Bind();
	void Unbind();
	void Delete();

};

#endif
