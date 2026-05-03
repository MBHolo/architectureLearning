#include "MathFunc.h"

//Реализация функции класса MathFunc
std::vector<double> MathFunc::solve(double a, double b, double c) {
	std::vector<double> result = {};
	double descrim = (b * b) - (4 * a * c);

	if (fabs(a) < 1e-7) {
		throw std::invalid_argument("Коэффициент a не может быть равен 0");
	}

	if (fabs(b) < 1e-7) {
		if (c > 1e-7) {
			result = {};
		}
		if (c < -1e-7) {
			result = { std::sqrt(-c), std::sqrt(-c) * (-1) };
		}
		if (c == 0.0) {
			result = { 0.0, 0.0 };
		}
	}
	else {
		if (fabs(descrim) < 1e-7) {
			result = { -b / (2 * a) , -b / (2 * a) };
		}
		else {
			if (descrim < -1e-7) {
				result = {};
			}
			else {
				result = { (-b + std::sqrt(descrim)) / (2 * a) , (-b - std::sqrt(descrim)) / (2 * a) };
			}
		}
	}

	return result;
}
