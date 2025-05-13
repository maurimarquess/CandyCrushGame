#include "partida.h"

Partida::Partida()
{
	Tauler Inicialitzacio;
	m_nMovimentsJugador = 0;
	m_nMovimentsMax = 0;
	m_nCaramelsObjectiu = 0;
	m_nCaramelsJugador = 0;
	m_colorObjectiu = NO_COLOR;
	m_tauler = Inicialitzacio;
	m_seqCaramels = 0;
	m_puntuacio = 0;
}
ColorCandy convertirAColor(char color)
{
	ColorCandy colorFinal;
	//switch case que converteix un char a un ColorCandy
	switch (color)
	{
	case 'R':
		colorFinal = VERMELL;
		break;
	case 'O':
		colorFinal = TARONJA;
		break;
	case 'Y':
		colorFinal = GROC;
		break;
	case 'B':
		colorFinal = BLAU;
		break;
	case 'G':
		colorFinal = VERD;
		break;
	case 'P':
		colorFinal = LILA;
		break;
	default:
		colorFinal = NO_COLOR;
		break;
	}

	return colorFinal;
}
char convertirColorALletra(Candy caramel)
{
	char colorFinal;
	//switch case que converteix un char a un ColorCandy
	switch (caramel.getColor())
	{
	case VERMELL:
		colorFinal = 'R';
		break;
	case TARONJA:
		colorFinal = 'O';
		break;
	case GROC:
		colorFinal = 'Y';
		break;
	case BLAU:
		colorFinal = 'B';
		break;
	case VERD:
		colorFinal = 'G';
		break;
	case LILA:
		colorFinal = 'P';
		break;
	default:
		colorFinal = ' ';
		break;
	}

	return colorFinal;
}
void Partida::inicialitza(const string& nomFitxer)
{
	ifstream fitxerIn;
	fitxerIn.open(nomFitxer);
	char color, colorCaramel;
	int nCaramels, nMoviments;
	ColorCandy color2;
	Candy caramel;
	if (fitxerIn.is_open())
	{
		fitxerIn >> color; //guardar al color objectiu a una variable
		fitxerIn >> nCaramels; //guardar el numero de caramels objectiu a una veriable
		fitxerIn >> nMoviments; //guardar el nombre maxim de moviments de la partida

		m_colorObjectiu = convertirAColor(color);
		m_nCaramelsObjectiu = nCaramels;
		m_nMovimentsMax = nMoviments;

		for (int i = 0; i < MAX_COLUMNES; i++)//2 fors per a inicialitzar el tauler
		{
			for (int j = 0; j < MAX_FILES; j++)
			{
				fitxerIn >> colorCaramel;//guardar color caramel en format char
				color2 = convertirAColor(colorCaramel);//convertir char a color candy
				caramel.setColor(color2);//guardar valors caramel
				caramel.setTipus(NORMAL);
				m_tauler.setTauler(caramel, i, j);//guardar el caramel anterior a la posicio del tauler corresponent
			}
		}

	}

	fitxerIn.close();
	//Inicialitzar el numero de moviments que porta el jugador i el numero de caramels explotats
	m_nMovimentsJugador = 0;
	m_nCaramelsJugador = 0;
	m_seqCaramels = 0;
	m_puntuacio = 0;

}
bool Partida::iniciaMoviment(const Posicio& pos1, const Posicio& pos2)
{
	bool esValid = false, esValid2 = false, eliminat = false, repetir = false, movimentCorrecte = false;
	//Comprovar que l’intercanvi de caramels és vàlid(dona lloc a tres o més caramels del mateix tipus en alguna de les dues posicions).Si no és vàlid no s’ha de fer res.
	Posicio posA = pos1, posB = pos2;
	Candy aux1, aux2;
	m_tauler.IntercanviarPosicio(posA, posB);
	if (m_tauler.getCaramelTauler(posA.getFila(), posA.getColumna()).getTipus() == RATLLAT_HORIZONTAL || m_tauler.getCaramelTauler(posA.getFila(), posA.getColumna()).getTipus() == RATLLAT_VERTICAL)//si el caramel1 es rallat crida la funcio per a caramels rallats
	{
		aux1 = m_tauler.getCaramelTauler(posA.getFila(), posA.getColumna());
		esValid = m_tauler.eliminarCaramels(posA, repetir, m_colorObjectiu, m_nCaramelsObjectiu);
		if (esValid)
		{
			m_tauler.setTauler(aux1, posA.getFila(), posA.getColumna());
			eliminat = m_tauler.eliminaCaramelsRatllats(posA, m_colorObjectiu, m_nCaramelsObjectiu);
		}
	}
	else//sino crida la funcio per a eliminar caramels normals
	{
		esValid = m_tauler.eliminarCaramels(posA, repetir, m_colorObjectiu, m_nCaramelsObjectiu);
	}
	if (m_tauler.getCaramelTauler(posB.getFila(), posB.getColumna()).getTipus() == RATLLAT_HORIZONTAL || m_tauler.getCaramelTauler(posB.getFila(), posB.getColumna()).getTipus() == RATLLAT_VERTICAL)//si el caramel2 es rallat crida la fucio per a caramels rallats
	{
		aux2 = m_tauler.getCaramelTauler(posB.getFila(), posB.getColumna());
		esValid2 = m_tauler.eliminarCaramels(posB, repetir, m_colorObjectiu, m_nCaramelsObjectiu);
		if (esValid2)
		{
			m_tauler.setTauler(aux2, posB.getFila(), posB.getColumna());
			eliminat = m_tauler.eliminaCaramelsRatllats(posB, m_colorObjectiu, m_nCaramelsObjectiu);
		}
	}
	else//sino crida la funcio per a eliminar caramels normals
	{
		esValid2 = m_tauler.eliminarCaramels(posB, repetir, m_colorObjectiu, m_nCaramelsObjectiu);
	}

	if (!esValid && !esValid2)
	{
		m_tauler.IntercanviarPosicio(posA, posB);
	}
	else
	{
		movimentCorrecte = true;
		m_nMovimentsMax--;
	}
	return movimentCorrecte;
}
bool Partida::continuaMoviment()
{
	bool eliminat = false, repetir = false, finalitzat = false;
	//Comprovar que l’intercanvi de caramels és vàlid(dona lloc a tres o més caramels del mateix tipus en alguna de les dues posicions).Si no és vàlid no s’ha de fer res.
	Posicio posAux;
	Candy aux3;
	
	m_tauler.actualitzaTauler();
	m_tauler.ompleTauler(m_seqCaramels, m_puntuacio);

	posAux = m_tauler.comprovaTauler(repetir);
	if (repetir)
	{
		if (m_tauler.getCaramelTauler(posAux.getFila(), posAux.getColumna()).getTipus() == RATLLAT_HORIZONTAL || m_tauler.getCaramelTauler(posAux.getFila(), posAux.getColumna()).getTipus() == RATLLAT_VERTICAL)//si el caramel1 es rallat crida la funcio per a caramels rallats
		{
			aux3 = m_tauler.getCaramelTauler(posAux.getFila(), posAux.getColumna());
			eliminat = m_tauler.eliminarCaramels(posAux, repetir, m_colorObjectiu, m_nCaramelsObjectiu);
			if (eliminat)
			{
				m_tauler.setTauler(aux3, posAux.getFila(), posAux.getColumna());
				eliminat = m_tauler.eliminaCaramelsRatllats(posAux, m_colorObjectiu, m_nCaramelsObjectiu);
			}

		}
		else//sino crida la funcio per a eliminar caramels normals
		{
			eliminat = m_tauler.eliminarCaramels(posAux, repetir, m_colorObjectiu, m_nCaramelsObjectiu);
		}

	}
	else
	{
		finalitzat = true;
	}

	return finalitzat;
}
void Partida::escriuTauler(const string& nomFitxer)
{
	//escriure l'estat actual del tauler a un arxiu
	ofstream fitxerOut;
	char color;
	fitxerOut.open(nomFitxer);
	if (fitxerOut.is_open())
	{
		for (int i = 0; i < MAX_FILES; i++)
		{
			for (int j = 0; j < MAX_COLUMNES; j++)
			{
				color = convertirColorALletra(m_tauler.getCaramelTauler(i, j));
				fitxerOut << color << " ";
			}
		}
	}

}
void Partida::dibuixa(Posicio pos) 
{
	m_tauler.dibuixa(pos);
}
