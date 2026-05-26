#include "../src/SpaceBattle/Objects/SpaceShipObject.h"

SpaceShipObject::SpaceShipObject(int startX, int startY, int startXVelocity , int startYVelocity, int speed, int indexRotate = 1)
	: m_moving(startX, startY, startXVelocity, startYVelocity, speed), m_rotate(indexRotate) {}

//Делигирование из компонента для получения позиции
void SpaceShipObject::getPosition(int& x, int& y) const {
	m_moving.getPosition(x, y);
}

//Делигирование из компонента для получения информации по скорости
void SpaceShipObject::getVectorVelocity(int& xVelocity, int& yVelocity) const {
	m_moving.getVectorVelocity(xVelocity, yVelocity);
}

//Установка новых векторов скорости
void SpaceShipObject::setVectorVelocity() {

	//Получение направления
	int dir;
	m_rotate.getIndexRotate(dir);

	//Получение вектора скорости
	int newXVelocity = SPEED_TABLE[dir].dx;
	int newYVelocity = SPEED_TABLE[dir].dy;

	m_moving.setVectorVelocit(newXVelocity, newYVelocity);
}

//Делигирование из компонента для порлучения скорости
void SpaceShipObject::getSpeed(int& speed) const {
	m_moving.getSpeed(speed);
}

//Делигирование из компонента для получения индекса поворота
void SpaceShipObject::getIndexRotate(int& indexRotate) const {
	m_rotate.getIndexRotate(indexRotate);
}

//Делигирование функции обновления позиции
void SpaceShipObject::updatePosition() {
	m_moving.updatePosition();
}

//Делигирование функции поворота по часовой стрелке
void SpaceShipObject::turnClockwise() {
	m_rotate.turnClockwise();
}

//делигирование функции поворото против часовой стрелки
void SpaceShipObject::turnCounterclockwis() {
	m_rotate.turnCounterclockwise();
}