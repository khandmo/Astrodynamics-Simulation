#ifndef VAO_CLASS_H
#define VAO_CLASS_H

// seperate file for VAO creation, including a function
// to link VBO to VAO
#include <glad/glad.h>
#include "VBO.h"

class VAO {
public:
	// ID reference to VAO
	GLuint ID;
	// Constructor
	VAO();

	// Links VBO to VAO using a given layout
	void LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
	void Bind();
	void Unbind();
	void Delete();
};


#endif
