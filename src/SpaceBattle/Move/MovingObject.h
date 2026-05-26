#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H

#include "../Interfaces/IMovingObject.h"
#include <stdexcept>

//Класс движения космического корабля
class MovingObject : public IMovingObject {
	private:
		int m_x = 0;
		int m_y = 0;
		int m_xVelocity = 0;
		int m_yVelocity = 0;
		int m_speed = 0;
		int m_min_X_Y = -1;
		int m_max_X_Y = 1;
	public:
		//Конструктор
		MovingObject(int startX = 0, int startY = 0, int startXVelocity = 1, int startYVelocity = 1, int speed = 1);

		void getPosition(int& x, int& y) const override;
		void getVectorVelocity(int& xVelocity, int& yVelocity) const override;
		void updatePosition() override;
		void getSpeed(int& speed) const override;

		void setVectorVelocit(int xVelocity, int yVelocity);
};

#endif 
