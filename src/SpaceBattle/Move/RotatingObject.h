#ifndef ROTATING_OBJECT_H
#define ROTATING_OBJECT_H

#include "../Interfaces/IRotateObject.h"
#include <stdexcept>

class RotatingObject : public IRotateObject {
	private:
		int m_indexRotate = 0;
		int m_maxIndexRotate = 7;
		int m_minIndexRotate = 0;
	public:
		//Конструктор
		RotatingObject(int indexRotate = 0);

		//Геттеры
		void getIndexRotate(int& indexRotate) const override;
		void getMinIndexRotate(int& minIndexRotate) const override;
		void getMaxIndexRotate(int& maxIndexRotate) const override;

		void turnClockwise() override;
		void turnCounterclockwise() override;

};

#endif 
