#include "PHYSICS.h"

PHYSICS::PHYSICS() {

}

PHYSICS::~PHYSICS() {

}

tvec3<GLfloat, highp> intersectionPoint( const tvec3<GLfloat, highp> * triangle ,
		const tvec3<GLfloat, highp> p0,
		const tvec3<GLfloat, highp> p1 )
												{



	//szukam wektora normalnego plaszczyzny
	tvec3<GLfloat, highp> A = triangle[1] - triangle[0];
	tvec3<GLfloat, highp> B = triangle[1] - triangle[2];

	tvec3<GLfloat, highp> D = cross(A,B);

	GLfloat t = (D.x*(triangle[0].x-p0.x)+D.y*(triangle[0].y-p0.y)+
			D.z*(triangle[0].z-p0.z))/(D.x*(p1.x-p0.x)+D.y*(p1.y-p0.y)+D.z*(p1.z-p0.z));

	//punkt przeciecia prostej z plaszyczna
	tvec3<GLfloat, highp> ret;
	ret.x = t *(p1.x-p0.x) + p0.x;
	ret.y = t *(p1.y-p0.y) + p0.y;
	ret.z = t *(p1.z-p0.z) + p0.z;

	return ret;
												};
