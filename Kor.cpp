#include "Kor.h"


double Kor::x_kiszamito(double x, double y, double sugar) {
	return -2 * x;
}

double Kor::y_kiszamito(double x, double y, double sugar) {
	return -2 * y;
}

double Kor::konstans_kiszamito(double x, double y, double sugar) {
	double eredmeny = x * x + y * y - sugar * sugar;
	return eredmeny;
}

void Kor::print()const {
	std::cout << "Itt jon egy Kor: ";
	std::cout << getXnegyzet() << " * x^2 + " << getX() << " * x + " << getYnegyzet() << " * y^2 + " << getY() << " * y + " << getKonst()<< " = 0" << std::endl;
}