#ifndef OBJECT_MESH_SUMMON_H
#define OBJECT_MESH_SUMMON_H

#include "Mesh.h"

// mathematically calculates vertex and index information for each object

class Object {
public:

	std::vector <Vertex> vertices;
	std::vector <GLuint> indices;

	Object();

	// creates object box at origin painted in associated color
	void Box(GLfloat length, GLfloat red, GLfloat green, GLfloat blue);

	// creates planar object that
	void Rings(float innerRadius, float outerRadius, GLfloat red, GLfloat green, GLfloat blue);

	// creates object sphere with # of pedals 360 * factor360 painted in associated color
	void Sphere(float radius, GLfloat red, GLfloat green, GLfloat blue);
};

#endif
