#ifndef BALL_H_
#define BALL_H_

#define OBJECTS 4

#include "OBJECT.h"
#include <math.h>

#include <cstdlib>
#include <ctime>
class BALL {

	VERTEX3D center;
	VERTEX3D speed;
	GLfloat radius;
	GLfloat g;


public:
	BALL( VERTEX3D center, GLfloat radius );
	~BALL();

	//update center
	void computeNewCoord( OBJECT ** colide_obj , GLfloat time_from_last_frame );
	VERTEX3D computeNewPredicCords(GLfloat time_from_last_frame );
	OBJECT * detectColision( OBJECT ** obj_arr );

	void render();
	void translate();
	bool computeCollisionWithPlayerRocket(OBJECT *rocketObj);
	bool computeCollisionWithCompRocket(OBJECT *rocketObj);
	bool computeCollisionWithTable(OBJECT *table);
	bool computeCollisionWithNet(OBJECT *net);
	void initSpeed();

	VERTEX3D getCenter() const;
};

#endif /* BALL_H_ */
