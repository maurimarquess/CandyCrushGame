#include "tauler.h"

Tauler::Tauler()
{
	Candy inicial;
	for (int i = 0; i < MAX_FILES; i++)
	{
		for (int j = 0; j < MAX_COLUMNES; j++)
		{
			m_tauler[i][j] = inicial;
		}
	}
}
void Tauler::IntercanviarPosicio(Posicio pos1, Posicio pos2)
{
	Candy Aux1, Aux2;
	//Guardar els caramels a una variable auxiliar
	Aux1 = m_tauler[pos1.getFila()][pos1.getColumna()];
	Aux2 = m_tauler[pos2.getFila()][pos2.getColumna()];
	//Intercanviar i guardar els caramels a la nova posicio
	m_tauler[pos1.getFila()][pos1.getColumna()] = Aux2;
	m_tauler[pos2.getFila()][pos2.getColumna()] = Aux1;
}
//Funcions per eliminar
int Tauler::EliminarHoritzontal(Posicio pos, int& num, ColorCandy colorObjectiu, int& nCaramelsRestants)
{
	Candy empty;
	int alineats = 0, i = pos.getFila(), posAux;

	for (int j = 2; j < MAX_COLUMNES; j++)
	{
		if (m_tauler[i][j] == m_tauler[i][j - 1] && m_tauler[i][j - 1] == m_tauler[i][j - 2])
		{
			if (alineats >= 3)
			{
				alineats++;
			}
			else
			{
				alineats = 3;
			}
			posAux = j;
			num = j;
		}
	}
	if (alineats >= 3)
	{
		for (int k = 0; k < alineats; k++)
		{
			if (m_tauler[i][posAux].getTipus() == RATLLAT_VERTICAL || m_tauler[i][posAux].getTipus() == RATLLAT_HORIZONTAL)
			{
				Posicio rallat;
				rallat.set(i, posAux);
				eliminaCaramelsRatllats(rallat, colorObjectiu, nCaramelsRestants);
			}
			if (m_tauler[i][posAux].getColor() == colorObjectiu)
			{
				if (nCaramelsRestants != 0)
				{
					nCaramelsRestants--;
				}
			}
			m_tauler[i][posAux] = empty;
			posAux--;
		}
	}
	return alineats;
}
int Tauler::EliminarVertical(Posicio pos, ColorCandy colorObjectiu, int& nCaramelsRestants)
{
	Candy empty;
	int alineats = 0, j = pos.getColumna(), posAux;
	if (m_tauler[pos.getFila()][pos.getColumna()] == m_tauler[pos.getFila() - 1][pos.getColumna()] && m_tauler[pos.getFila()][pos.getColumna()] == m_tauler[pos.getFila() - 2][pos.getColumna()] || m_tauler[pos.getFila()][pos.getColumna()] == m_tauler[pos.getFila() + 1][pos.getColumna()] && m_tauler[pos.getFila()][pos.getColumna()] == m_tauler[pos.getFila() + 2][pos.getColumna()] || m_tauler[pos.getFila()][pos.getColumna()] == m_tauler[pos.getFila() - 1][pos.getColumna()] && m_tauler[pos.getFila()][pos.getColumna()] == m_tauler[pos.getFila() + 1][pos.getColumna()])
	{
		for (int i = 2; i < MAX_COLUMNES; i++)
		{
			if (m_tauler[i][j] == m_tauler[i - 1][j] && m_tauler[i - 1][j] == m_tauler[i - 2][j])
			{
				if (alineats >= 3)
				{
					alineats++;
				}
				else
				{
					alineats = 3;
				}
				posAux = i;
			}
		}
		if (alineats >= 3)
		{
			for (int k = 0; k < alineats; k++)
			{
				if (m_tauler[posAux][j].getTipus() == RATLLAT_VERTICAL || m_tauler[posAux][j].getTipus() == RATLLAT_HORIZONTAL)
				{
					Posicio rallat;
					rallat.set(posAux, j);
					eliminaCaramelsRatllats(rallat, colorObjectiu, nCaramelsRestants);
				}
				if (m_tauler[posAux][j].getColor() == colorObjectiu)
				{
					if (nCaramelsRestants != 0)
					{
						nCaramelsRestants--;
					}
				}
				m_tauler[posAux][j] = empty;
				posAux--;
				
			}
		}
	}
	return alineats;
}
bool Tauler::eliminarCaramels(Posicio pos1, bool rep, ColorCandy colorObjectiu, int& nCaramelsRestants)
{
	bool eliminat = false;
	int alineatsH, alineatsV, ultim = 0;
	Candy Aux = m_tauler[pos1.getFila()][pos1.getColumna()], aux2;
	Candy empty;//Caramel buit per marcar els caramels q s'han d'eliminar

	alineatsH = EliminarHoritzontal(pos1, ultim, colorObjectiu, nCaramelsRestants); //obtenir el numero de caramels alineats i marcar els caramels com a buits
	if (alineatsH > 3)//si el num de caramels alineats en horitzontal es mes gran que 3 vol dir q hem de crear un caramel rallat a la posicio que ens donen
	{
		if (!rep)//rep indica si s'ha d'elimnar segons el moviment del jugador o si es degut a l'actualitzacio del tauler que s'ha generat una nova combinacio
		{
			m_tauler[pos1.getFila()][pos1.getColumna()].setColor(Aux.getColor());
			m_tauler[pos1.getFila()][pos1.getColumna()].setTipus(RATLLAT_VERTICAL);
		}
		else
		{
			m_tauler[pos1.getFila()][ultim - (alineatsH - 1)].setColor(Aux.getColor());
			m_tauler[pos1.getFila()][ultim - (alineatsH - 1)].setTipus(RATLLAT_HORIZONTAL);
		}
		
		aux2 = m_tauler[pos1.getFila()][pos1.getColumna()]; //creem el caramel rallat horitzontal i el guardem a un caramel auxiliar per a cridar la següent funcio

		alineatsV = EliminarVertical(pos1, colorObjectiu, nCaramelsRestants); //comprova els caramels que estan en linia en vertical a la posicio passada com a parametre i guarda el valor del numero de caramels
		if (alineatsV != 0)//si el num de caramels es diferent de 0 vol dir que el caramel ubicat a la posicio que hem passat com a parametre ha estat modificat, per tant li retornem el valor anterior(ja que era un caramel rallat)
		{
			m_tauler[pos1.getFila()][pos1.getColumna()] = aux2;
		}
		eliminat = true;
	}
	else//si el numero de caramels alineats es mes petit o igual que tres vol dir que no hi ha cap caramel rallat de moment
	{
		m_tauler[pos1.getFila()][pos1.getColumna()] = Aux;//com que el caramel pot estar buit li retornem el valor anterior
		alineatsV = EliminarVertical(pos1, colorObjectiu, nCaramelsRestants); //cridem la funcio per examinar caramels verticals
		if (alineatsH == 3)
		{
			if (alineatsV == 0)
			{
				if(m_tauler[pos1.getFila()][pos1.getColumna()].getTipus() != RATLLAT_VERTICAL || m_tauler[pos1.getFila()][pos1.getColumna()].getTipus() != RATLLAT_HORIZONTAL)
					m_tauler[pos1.getFila()][pos1.getColumna()] = empty;
			}
			else
			{
				if (alineatsV > 3)//si el nombre d'alineats es mes gran que 3 hem de crear un caramel rallat a la posicio
				{
					if (!rep)//rep indica si s'ha d'elimnar segons el moviment del jugador o si es degut a l'actualitzacio del tauler que s'ha generat una nova combinacio
					{
						m_tauler[pos1.getFila()][pos1.getColumna()].setColor(Aux.getColor());
						m_tauler[pos1.getFila()][pos1.getColumna()].setTipus(RATLLAT_HORIZONTAL);
					}
					else
					{
						m_tauler[pos1.getFila()][pos1.getColumna()].setColor(Aux.getColor());
						m_tauler[pos1.getFila()][pos1.getColumna()].setTipus(RATLLAT_VERTICAL);
					}

				}
			}
			eliminat = true;
		}
		else
		{
			if (alineatsV != 0)
			{
				if (alineatsV > 3)//si el nombre d'alineats es mes gran que 3 hem de crear un caramel rallat a la posicio
				{
					if (!rep)//rep indica si s'ha d'elimnar segons el moviment del jugador o si es degut a l'actualitzacio del tauler que s'ha generat una nova combinacio
					{
						m_tauler[pos1.getFila()][pos1.getColumna()].setColor(Aux.getColor());
						m_tauler[pos1.getFila()][pos1.getColumna()].setTipus(RATLLAT_HORIZONTAL);
					}
					else
					{
						m_tauler[pos1.getFila()][pos1.getColumna()].setColor(Aux.getColor());
						m_tauler[pos1.getFila()][pos1.getColumna()].setTipus(RATLLAT_VERTICAL);
					}
				}
				eliminat = true;
			}
		}
	}
	return eliminat;
}
bool Tauler::eliminaCaramelsRatllats(Posicio pos, ColorCandy colorObjectiu, int& nCaramelsRestants)
{
	bool eliminat = false;
	Candy empty;

	if (m_tauler[pos.getFila()][pos.getColumna()].getTipus() == RATLLAT_HORIZONTAL)//Eliminar fila
	{
		int i = pos.getFila();
		for (int j = 0; j < MAX_COLUMNES; j++)
		{
			if ((m_tauler[i][j].getTipus() == RATLLAT_HORIZONTAL || m_tauler[i][j].getTipus() == RATLLAT_VERTICAL) && j != pos.getColumna())
			{
				Posicio rallat;
				rallat.set(i, j);
				eliminaCaramelsRatllats(rallat, colorObjectiu, nCaramelsRestants);
			}
			if (m_tauler[i][j].getColor() == colorObjectiu)
			{
				if (nCaramelsRestants != 0)
				{
					nCaramelsRestants--;
				}
			}
			m_tauler[i][j] = empty;
		}
		eliminat = true;
	}
	if (m_tauler[pos.getFila()][pos.getColumna()].getTipus() == RATLLAT_VERTICAL)//Eliminar columna
	{
		int j = pos.getColumna();
		for (int i = 0; i < MAX_FILES; i++)
		{
			if ((m_tauler[i][j].getTipus() == RATLLAT_HORIZONTAL || m_tauler[i][j].getTipus() == RATLLAT_VERTICAL) && j != pos.getColumna())
			{
				Posicio rallat;
				rallat.set(i, j);
				eliminaCaramelsRatllats(rallat, colorObjectiu, nCaramelsRestants);
			}
			if (m_tauler[i][j].getColor() == colorObjectiu)
			{
				if (nCaramelsRestants != 0)
				{
					nCaramelsRestants--;
				}
			}
			m_tauler[i][j] = empty;
		}
		eliminat = true;
	}
	return eliminat;
}

Posicio Tauler::comprovaTauler(bool& trobat)
{
	Posicio petar;
	trobat = false;
	//comprovarHoritzontal
	int i = 0, j = 2;
	while (i < MAX_FILES && !trobat)
	{
		while (j < MAX_COLUMNES && !trobat)
		{
			if (m_tauler[i][j] == m_tauler[i][j - 1] && m_tauler[i][j] == m_tauler[i][j - 2] && m_tauler[i][j].getColor() != NO_COLOR)//si hi ha 3 seguits iguals i tenen color retornem la posicio
			{
				petar.set(i, j);
				trobat = true;
			}
			j++;
		}
		i++;
		j = 2;
	}
	if (!trobat)
	{
		j = 0, i = 2;
		//comprovarVertical
		while (j < MAX_COLUMNES && !trobat)
		{
			while (i < MAX_FILES && !trobat)
			{
				if (m_tauler[i][j] == m_tauler[i - 1][j] && m_tauler[i][j] == m_tauler[i - 2][j] && m_tauler[i][j].getColor() != NO_COLOR)//si hi ha 3 seguits iguals i tenen color retornem la posicio
				{
					petar.set(i, j);
					trobat = true;
				}
				i++;
			}
			j++;
			i = 2;
		}
	}
	return petar;
}
void Tauler::actualitzaTauler()
{
	Candy empty;
	for (int j = 0; j < MAX_COLUMNES; j++)
	{
		for (int i = MAX_FILES - 1; i >= 0; i--)
		{
			if (i != 0)
			{
				if (m_tauler[i][j] == empty && m_tauler[i - 1][j].getColor() != empty.getColor())
				{
					m_tauler[i][j] = m_tauler[i - 1][j];
					m_tauler[i - 1][j] = empty;
					i = MAX_FILES - 1;
				}
			}

		}
	}
}
void Tauler::ompleTauler(int& opcio, int& puntuacio)
{
	Candy empty(NO_COLOR, NO_TIPUS);

	for (int i = MAX_FILES - 1; i >= 0; i--)
	{
		for (int j = 0; j < MAX_COLUMNES; j++)  // fem recorregut de baix a dalt i d'esquerra a dreta per anar omplint
		{
			if (m_tauler[i][j] == empty) // mentre la posició suigui buida anem ompllim els esapis buits amb els caramels que toquen
			{
				switch (opcio)
				{
				case 0: m_tauler[i][j].setColor(VERMELL);
					m_tauler[i][j].setTipus(NORMAL);
					break;
				case 1: m_tauler[i][j].setColor(TARONJA);
					m_tauler[i][j].setTipus(NORMAL);
					break;
				case 2: m_tauler[i][j].setColor(GROC);
					m_tauler[i][j].setTipus(NORMAL);
					break;
				case 3: m_tauler[i][j].setColor(BLAU);
					m_tauler[i][j].setTipus(NORMAL);
					break;
				case 4: m_tauler[i][j].setColor(VERD);
					m_tauler[i][j].setTipus(NORMAL);
					break;
				case 5: m_tauler[i][j].setColor(LILA);
					m_tauler[i][j].setTipus(NORMAL);
					break;

				default:
					break;
				}
				if (opcio == 5)
					opcio = 0;
				else
					opcio++;
				
				puntuacio += 10;
				
			}

		}
	}

}
void Tauler::dibuixa(Posicio pos)
{
	Posicio posicio;
	for (int i = 0; i < MAX_FILES; i++)
	{
		for (int j = 0; j < MAX_COLUMNES; j++) 
		{
			posicio.set(i, j);
			if (posicio.getColumna() != pos.getColumna() || posicio.getFila() != pos.getFila())
			{
				m_tauler[i][j].dibuixa(posicio);
			}
			
		}
	}
}