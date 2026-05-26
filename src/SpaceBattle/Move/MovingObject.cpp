#include "./MovingObject.h"

//Реализация методов класса
MovingObject::MovingObject(int startX, int startY, int startXVelocity, int startYVelocity, int speed){
	if (startXVelocity < m_min_X_Y || startXVelocity > m_max_X_Y || startYVelocity < m_min_X_Y || startXVelocity > m_max_X_Y ){
		throw std::invalid_argument("Invalid index rotate");
		return;
	}

	m_x = startX;
	m_y = startY;
	m_xVelocity = startXVelocity;
	m_yVelocity = startYVelocity;
	m_speed = speed;
}

void MovingObject::getPosition(int& x, int& y) const {
	x = m_x;
	y = m_y;
}


void MovingObject::getVectorVelocity(int& x, int& y) const{
	x = m_xVelocity;
	y = m_yVelocity;
}

void MovingObject::setVectorVelocit(int xVelocity, int yVelocity) {
	m_xVelocity = xVelocity;
	m_yVelocity = yVelocity;
}

void MovingObject::updatePosition() {
	m_x = m_x + m_xVelocity * m_speed;
	m_y = m_y + m_yVelocity * m_speed;
}

void MovingObject::getSpeed(int& speed) const {
	speed = m_speed;
}