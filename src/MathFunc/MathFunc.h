#ifndef MATH_FUNC_H
#define MATH_FUNC_H

#include <vector>
#include <cmath>
#include <stdexcept>

//Создание класса MathFunc
class MathFunc {
	//Создание абстракции
	public:
		std::vector<double> solve(double a, double b, double c); 
};

#endif