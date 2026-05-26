#ifndef SPACE_SHIP_OBJECT_H
#define SPACE_SHIP_OBJECT_H

#include "../src/SpaceBattle/Move/MovingObject.h"
#include "../src/SpaceBattle/Move/RotatingObject.h"


class SpaceShipObject {
	private:
		struct SpeedVector {
			int dx;
			int dy;
		};
		const SpeedVector SPEED_TABLE[8] = {
			{ 0,  1},  // 0: вверх
			{ 1,  1},  // 1: вверх-вправо
			{ 1,  0},  // 2: вправо
			{ 1, -1},  // 3: вниз-вправо
			{ 0, -1},  // 4: вниз
			{-1, -1},  // 5: вниз-влево
			{-1,  0},  // 6: влево
			{-1,  1}   // 7: вверх-влево
		};
		//Получение экземспляров класса
		MovingObject m_moving;
		RotatingObject m_rotate;
	public:
		//Конструктор 
		SpaceShipObject(int startX, int startY, int startXVelocity, int startYVelocity, int speed, int indexRotate);

		//Геттер получения координат позиции
		void getPosition(int& x, int& y) const;

		//Геттер получения скорости
		void getSpeed(int& speed) const;

		//Геттер получения скорости
		void getVectorVelocity(int& xVelocity, int& yVelocity) const;

		//Геттер установкеи нового вектора скорости
		void setVectorVelocity();

		//Геттер получения индекса поворота 
		void getIndexRotate(int& indexRotate) const;

		//Функции движения и поворота
		void updatePosition();
		void turnClockwise();
		void turnCounterclockwis();
};

#endif 
