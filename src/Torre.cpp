#include "Torre.h"

Torre::Torre()
{

}

Torre::Torre(Color color, Coordenada coord)
{
	//En el futuro hacer in-line
	this->color = color;
	this->coord = coord;
	this->tipo = PEON;
}

//Color Peon::getColor(Color color) {
//	return color;
//}

void Torre::dibuja() {
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