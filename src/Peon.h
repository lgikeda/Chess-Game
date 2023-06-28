#pragma once
#include "PiezaGen.h"

class Peon:public PiezaGen {
	bool first_move = true;
public:

	Peon(Color color, Coordenada coord);
	void dibuja() override;
	bool movimientoLegal(int fila, int columna, PiezaGen*) override;
};