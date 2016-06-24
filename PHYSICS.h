#ifndef PHYSICS_H_
#define PHYSICS_H_
#include <GL/glut.h>
#include <glm.hpp>
#include <vec3.hpp>
#include <detail/precision.hpp>

using namespace glm::detail;
using namespace glm;


struct VERTEX3D{

	union{
		GLfloat x, r;
	};
	union{
		GLfloat y, g;
	};
	union{
		GLfloat z, b;
	};

};


class PHYSICS {
public:
	PHYSICS();
	virtual ~PHYSICS();
};

tvec3<GLfloat, highp> intersectionPoint( const tvec3<GLfloat, highp> * triangle ,
										const tvec3<GLfloat, highp> p0,
										const tvec3<GLfloat, highp> p1 );

#endif /* PHYSICS_H_ */
