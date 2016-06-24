#include "BALL.h"
#include <iostream>
BALL::BALL(VERTEX3D center, GLfloat radius) {
	this->center = center;
	this->radius = radius;
	g = 0.0f;

}

BALL::~BALL() {

}

void BALL::computeNewCoord(OBJECT ** colide_obj, GLfloat time_from_last_frame) {

	VERTEX3D predCord = computeNewPredicCords(time_from_last_frame);
	center = predCord;
	speed.y = speed.y - g * time_from_last_frame;
	detectColision(colide_obj);


}
OBJECT * BALL::detectColision(OBJECT ** obj_arr) {

	OBJECT * anotherObject;
	VERTEX3D t_center;
	for (int i = 0; i < 4; i++) {
		anotherObject = obj_arr[i];
		if (anotherObject->getType() == stol) {
			computeCollisionWithTable(anotherObject);
		}
		else if(anotherObject->getType() == siatka){
			computeCollisionWithNet(anotherObject);
		}
		else if(anotherObject->getType() == paletkaGracza){
			computeCollisionWithPlayerRocket(anotherObject);
		}
		else if(anotherObject->getType() == paletkaKomputera){
			computeCollisionWithCompRocket(anotherObject);
		}

	}
	return NULL;
}
bool BALL::computeCollisionWithPlayerRocket(OBJECT *rocketObj) {
	float r_x = rocketObj->getCenter().x;
	float r_y = rocketObj->getCenter().y;
	float r_z = rocketObj->getCenter().z;
	if (center.x <= 0
			&& center.x - radius <= r_x + rocketObj->get_X_Width()
			&& center.y >= r_y - rocketObj->get_Y_Heigth()
			&& center.y <= r_y + rocketObj->get_Y_Heigth()
			&& center.z >= r_z - rocketObj->get_Z_Depth()
			&& center.z <= r_z + rocketObj->get_Z_Depth()) {
		speed.x = -speed.x;
		speed.z = -speed.z;
		return true;
	}
	return false;
}

bool BALL::computeCollisionWithCompRocket(OBJECT *rocketObj) {
	float r_x = rocketObj->getCenter().x;
	float r_y = rocketObj->getCenter().y;
	float r_z = rocketObj->getCenter().z;
	if (center.x >= 0
			&& center.x + radius >= r_x - rocketObj->get_X_Width()
			&& center.y >= r_y - rocketObj->get_Y_Heigth()
			&& center.y <= r_y + rocketObj->get_Y_Heigth()
			&& center.z >= r_z - rocketObj->get_Z_Depth()
			&& center.z <= r_z + rocketObj->get_Z_Depth()) {
		speed.x = -speed.x;
		speed.z = -speed.z;
		return true;
	}
	return false;
}

bool BALL::computeCollisionWithTable(OBJECT *table) {
	float t_x = table->getCenter().x;
	float t_y = table->getCenter().y;
	float t_z = table->getCenter().z;

	if (center.x - radius >= t_x - table->get_X_Width()
			&& center.x - radius <= t_x + table->get_X_Width()
			&& center.y - radius >= t_y - table->get_Y_Heigth()
			&& center.y - radius <= t_y + table->get_Y_Heigth()
			&& center.z - radius >= t_z - table->get_Z_Depth()
			&& center.z - radius <= t_z + table->get_Z_Depth()) {
		speed.y = -speed.y;
		return true;
	}
	return false;
}

bool BALL::computeCollisionWithNet(OBJECT *net) {

	float n_x = net->getCenter().x;
	float n_y = net->getCenter().y;
	float n_z = net->getCenter().z;
	if ( (center.x - radius >= n_x - net->get_X_Width()
			&& center.x - radius <= n_x + net->get_X_Width()
			&& center.y - radius >= n_y - net->get_Y_Heigth()
			&& center.y - radius <= n_y + net->get_Y_Heigth()
			&& center.z - radius >= n_z - net->get_Z_Depth()
			&& center.z - radius <= n_z + net->get_Z_Depth() )
			|| (center.x + radius >= n_x - net->get_X_Width()
					&& center.x + radius <= n_x + net->get_X_Width()
					&& center.y + radius >= n_y - net->get_Y_Heigth()
					&& center.y + radius <= n_y + net->get_Y_Heigth()
					&& center.z + radius >= n_z - net->get_Z_Depth()
					&& center.z + radius <= n_z + net->get_Z_Depth()) ) {
		speed.x = 0;
		speed.y = 0;
		speed.z = 0;
		return true;
	}
	return false;
}

void BALL::render() {
	glutSolidSphere(radius,20,20);
}

void BALL::translate() {
	glTranslatef( center.x , center.y , center.z );
}

VERTEX3D BALL::computeNewPredicCords(GLfloat time_from_last_frame ) {

	VERTEX3D result=center;
	result.x=result.x+time_from_last_frame*speed.x;
	result.z=result.z+time_from_last_frame*speed.z;
	result.y=result.y+time_from_last_frame*speed.y;
	result.y=result.y-0.5*g*(time_from_last_frame*time_from_last_frame);

	return result;
}

void BALL::initSpeed() {
	srand( time( NULL ) );
	float x_speed = ((std::rand() % 24) - 12)/2.0;
	float z_speed= ((std::rand() % 14) -7)/2.0;
	if( z_speed > x_speed*0.7f )
	{
		z_speed = x_speed*0.7;
	}
	speed.x=x_speed;
	speed.z=z_speed;

	g=1.5;
}

VERTEX3D BALL::getCenter() const {
	return this->center;
}
