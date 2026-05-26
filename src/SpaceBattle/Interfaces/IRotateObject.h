#ifndef I_ROTATE_OGJECT
#define I_ROTATE_OBJECT

/*
Интерфейс поворота реализован через индыксы поворота
Повороты могут быть  в 8 разных сторон
Пример подобного поворота шахмотная доска
*/

//Интерфейс поворота объекта
class IRotateObject {
	public:
		//Деструктор
		virtual ~IRotateObject() = default;

		//Получение индекса поворота
		virtual void getIndexRotate(int& indeexRotate) const = 0;

		//Получение минимального индекса поворота
		virtual void getMinIndexRotate(int& minIndexRotate) const = 0;

		//Получение максимального индекса поворота
		virtual void getMaxIndexRotate(int& maxIndexRotate) const = 0;

		//Поворот по часовой стрелке
		virtual void turnClockwise() = 0;

		//Поворот против часовой стрелки
		virtual void turnCounterclockwise() = 0;
			
};

#endif