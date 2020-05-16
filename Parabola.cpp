#include "Parabola.h"

void Parabola::print()const {
	std::cout << "y = " << getXnegyzet() << " * x^2 + " << getX() << " * x + " << getKonst() << std::endl;
}