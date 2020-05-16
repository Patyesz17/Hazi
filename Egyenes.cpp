#include "Egyenes.h"

double Egyenes::x_kiszamito(double x1, double y1, double x2, double y2) {
	double vektorX = x2 - x1;
	double vektorY = y2 - y1;
	double eredmeny = (-1 * vektorY) / (-1 * vektorX);

	return eredmeny;

}

double Egyenes::konstans_kiszamito(double x1, double y1, double x2, double y2) {
	double vektorX = x2 - x1;
	double vektorY = y2 - y1;
	double eredmeny = (vektorY * x1 - vektorX * y1) / (-1 * vektorX);
	return eredmeny;
}

void Egyenes::print()const {
	std::cout << "Itt jon egy Egyenes: ";
	std::cout << "y" << "=" << getX() << "* x + " << getKonst() << std::endl;
}