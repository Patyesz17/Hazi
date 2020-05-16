#include "Egyenes.h"

double Egyenes::x_kiszamito(Pont A, Pont B) {
	double vektorX = B.getX() - A.getX();
	double vektorY = B.getY() - A.getY();
	double eredmeny = (-1 * vektorY) / (-1 * vektorX);

	return eredmeny;

}

double Egyenes::konstans_kiszamito(Pont A, Pont B) {
	double vektorX = B.getX() - A.getX();
	double vektorY = B.getY() - A.getY();
	double eredmeny = (vektorY * A.getX() - vektorX * A.getY()) / (-1 * vektorX);
	return eredmeny;
}