#ifndef I_MOVING_OBJECT_H
#define I_MOVING_OBJECT_H

//Создание интерфейса движения
class IMovingObject {
	//Создание виртуальных методов
	public:
		//Деструктор
		virtual ~IMovingObject() = default;
		//Метод получения координат позиции
		virtual void getPosition(int& x, int& y) const = 0;
		//Метод получения скороысти
		virtual void getVectorVelocity(int& xVelocity, int& yVelocity) const = 0;
		//Метод обновления значения позиции с учетом скорости
		virtual void updatePosition() = 0;
		//Получение скорости движения
		virtual void getSpeed(int& sleed) const = 0;
};

#endif