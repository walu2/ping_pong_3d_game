#include "OBJECT.h"

OBJECT::OBJECT( VERTEX3D center,GLfloat width,
		GLfloat heigth, GLfloat depth, objs type ):
		center(center),
		width(width),
		heigth(heigth),
		depth(depth),
		type(type){
}

OBJECT::~OBJECT() {
}

VERTEX3D OBJECT::getCenter	()
{
	return this->center;
}
GLfloat OBJECT::get_X_Width	()
{
	return this->width;
}
GLfloat OBJECT::get_Y_Heigth	()
{
	return this->heigth;
}
GLfloat OBJECT::get_Z_Depth	()
{
	return this->depth;
}
GLfloat OBJECT::getTiltUp	()
{
	return this->vertical;
}
GLfloat OBJECT::getTiltRight()
{
	return this->horizontal;
}
objs OBJECT::getType		()
{
	return type;
}
void OBJECT::setColor		( VERTEX3D color )
{
	this->color = color;
}

void OBJECT::setMinY( GLfloat minY )
{
	this->minY = minY;
}
void OBJECT::updatePositions( GLfloat tempo, bool * keys,  VERTEX3D *ball)
{
	if( this->type == paletkaGracza )
	{
		if( keys[_w] ) center.y += tempo;
		if( keys[_s] ) center.y -= tempo;
		if( keys[_a] ) center.z -= tempo;
		if( keys[_d] ) center.z += tempo;
	}
	else if( this->type == paletkaKomputera && ball != NULL)
	{
		/*if( keys[_up] ) center.y += tempo;
		if( keys[_down] ) center.y -= tempo;
		if( keys[_left] ) center.z -= tempo;
		if( keys[_right] ) center.z += tempo;*/
		if ( ball->y > center.y + heigth ){
			center.y += tempo;
		}
		else if ( ball->y < center.y - heigth ){
			center.y -= tempo;
		}
		else if ( ball->z > center.z + depth ){
			center.z += tempo;
		}
		else if ( ball->z < center.z - depth ){
			center.z -= tempo;
		}
	}


	if( center.y <= minY )
		center.y = minY;
}
void OBJECT::setTiltUp		( GLfloat tempo )
{
	this->vertical = tempo;
}
void OBJECT::setTiltRight	( GLfloat tempo )
{
	this->horizontal = tempo;
}

void OBJECT::translate()
{
	glTranslatef( center.x , center.y , center.z );
	glRotatef( horizontal , 0.0f, 1.0f, 0.0f );
	glRotatef( vertical , 1.0f, 0.0f, 0.0f );
}
void OBJECT::render()
{
	glColor3f(color.r, color.g, color.b);

	glBegin(GL_QUADS);

	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f( width, heigth, depth );
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f( -width, heigth, depth );
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f( -width, -heigth, depth );
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f( width, -heigth, depth );

	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f( width, heigth, depth );
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f( width, heigth, -depth );
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f( width, -heigth, -depth );
	//glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f( width, -heigth, depth );

	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f( width, heigth, -depth );
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f( width, -heigth, -depth );
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f( -width, -heigth, -depth );
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f( -width, heigth, -depth );

	//Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f( -width, heigth, depth );
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f( -width, heigth, -depth );
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f( -width, -heigth, -depth );
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f( -width, -heigth, depth );


	//Top
	glNormal3f(0.0f, 1.0f, -1.0f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f( width, heigth, depth );
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f( width, heigth, -depth );
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f( -width, heigth, -depth );
	//glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f( -width, heigth, depth );

	//Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f( width, -heigth, depth );
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f( width, -heigth, -depth );
	//glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f( -width, -heigth, -depth );
	//glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f( -width, -heigth, depth );

	glEnd();
}
