#include "Kor.h"

double Kor::x_kiszamito(Pont A, double sugar) {
	return -2 * A.getX();
}

double Kor::y_kiszamito(Pont A, double sugar) {
	return -2 * A.getY();
}

double Kor::konstans_kiszamito(Pont A, double sugar) {
	double eredmeny = A.getX() * A.getX() + A.getY() * A.getY() - sugar * sugar;
	return eredmeny;
}

void Kor::print()const {
	std::cout << getXnegyzet() << " * x^2 + " << getX() << " * x + " << getYnegyzet() << " * y^2 + " << getY() << " * y + " << getKonst()<< " = 0" << std::endl;
}