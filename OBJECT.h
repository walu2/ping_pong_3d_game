#ifndef OBJECT_H_
#define OBJECT_H_
#include "PHYSICS.h"

#define M_PI 3.14159265359

enum objs{ paletkaGracza , paletkaKomputera , siatka , stol };
enum keys{_w,_s,_a,_d,_up,_down,_right,_left};



class OBJECT {

	VERTEX3D center;
	VERTEX3D color;

	GLfloat width;
	GLfloat heigth;
	GLfloat depth;

	GLfloat horizontal;
	GLfloat vertical;

	GLfloat minY;

	objs 	type;

public:
	OBJECT	( VERTEX3D center,
			GLfloat width,
			GLfloat heigth,
			GLfloat depth,
			objs 	type);
	~OBJECT	();

	VERTEX3D getCenter	();
	GLfloat get_X_Width	();
	GLfloat get_Y_Heigth();
	GLfloat get_Z_Depth	();
	GLfloat getTiltUp	();
	GLfloat getTiltRight();
	objs getType		();

	void setColor		( VERTEX3D color );

	void setMinY( GLfloat minY );

	void updatePositions( GLfloat tempo, bool * keys, VERTEX3D *ball = NULL );

	void setTiltUp		( GLfloat tempo );
	void setTiltRight	( GLfloat tempo );

	void translate		();
	void render			();
};

#endif /* OBJECT_H_ */
