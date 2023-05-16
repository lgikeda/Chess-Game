#include "Alfil.h"

Alfil::Alfil()
{

}

Alfil::Alfil(Color color, Coordenada coord)
{
	//En el futuro hacer in-line
	this->color = color;
	this->coord = coord;
	this->tipo = PEON;
}

//Color Peon::getColor(Color color) {
//	return color;
//}

void Alfil::dibuja() {
	if (getColor() == NEGRO) {
		spriteN.setCenter(-coord.to_cartesianas(coord.fila, coord.columna).first + 5, -coord.to_cartesianas(coord.fila, coord.columna).second + 5);
		spriteN.setSize(10, 10);
		spriteN.draw();
	}

	if (getColor() == BLANCO) {
		spriteB.setCenter(-coord.to_cartesianas(coord.fila, coord.columna).first + 5, -coord.to_cartesianas(coord.fila, coord.columna).second + 5);
		spriteB.setSize(10, 10);
		spriteB.draw();
	}
}

//bool Alfil::movimientoLegal(int fila, int columna, PiezaGen* casilla) {
//	if ((coord.fila == fila) and (coord.columna == columna)) {	//Comprobacion de quedarse en la misma casilla
//		std::cout << "Movimiento invalido, selecciona distinta casilla a la inicial" << std::endl;
//		return false;
//	}
//	for (int i = 0; i < coord.fila; i++) {
//		if (abs(coord.fila - fila) == abs(coord.columna - columna)) {	//Comprobacion de movimiento en direccion correcta
//			std::cout << "Movimiento invalido, no se puede desplazar en x" << std::endl;;
//			std::cout << "coord.columna = " << coord.columna << ";" << "columa = " << columna << std::endl;;
//			return true;
//		}
//		else if (casilla != NULL) {
//			std::cout << "Movimiento no valido: La casilla debe estar vacia";
//			return false;
//		}
//	}
//	return false;
//}