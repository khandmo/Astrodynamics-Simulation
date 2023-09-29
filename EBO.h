#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include <vector>
#include <glad/glad.h>

class EBO {
public:
	// ID reference to EBO
	GLuint ID;
	// takes vertices and size in bytes
	EBO(std::vector <GLuint>& indices);

	void Bind();
	void Unbind();
	void Delete();

};

#endif
