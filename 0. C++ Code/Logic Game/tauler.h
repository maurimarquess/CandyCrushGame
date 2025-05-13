#ifndef TAULER_H
#define TAULER_H
#include "candy.h"
#include "posicio.h"

using namespace std;

const int MAX_CARAMELS_ALINEATS = 5;

class Tauler
{
public:
	Tauler();
	//setters
	void setTauler(Candy caramel, int fila, int columna) { m_tauler[fila][columna].setColor(caramel.getColor()), m_tauler[fila][columna].setTipus(caramel.getTipus()); }
	//getters
	Candy getCaramelTauler(int fila, int columna) { return m_tauler[fila][columna]; }
	//metodes(Falta començar)
	void IntercanviarPosicio(Posicio pos1, Posicio pos2);

	bool eliminarCaramels(Posicio pos1, bool rep, ColorCandy colorObjectiu, int& nCaramelsRestants);
	bool eliminaCaramelsRatllats(Posicio pos, ColorCandy colorObjectiu, int& nCaramelsRestants);
	int EliminarHoritzontal(Posicio pos, int& num, ColorCandy colorObjectiu, int& nCaramelsRestants);
	int EliminarVertical(Posicio pos, ColorCandy colorObjectiu, int& nCaramelsRestants);

	void actualitzaTauler();
	void ompleTauler(int& opcio, int& puntuacio);
	Posicio comprovaTauler(bool& trobat);
	void dibuixa(Posicio pos);
private:
	//atributs
	Candy m_tauler[MAX_FILES][MAX_COLUMNES];
	//MetodesPrivats


};

#endif

