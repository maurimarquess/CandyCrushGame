#ifndef PARTIDA_H
#define PARTIDA_H

#include <string>
#include <fstream>
#include "tauler.h"
#include <windows.h>

using namespace std;

class Partida
{
public:
    Partida();
    //getters
    int getNCaramels() const { return m_nCaramelsObjectiu; }
    ColorCandy getColorObjectiu() const { return m_colorObjectiu; }
    int getMovimentsJugador() const { return m_nMovimentsJugador; }
    int getMovimentsMax() const { return m_nMovimentsMax; }
    int getPuntuacio() const { return m_puntuacio; }
    int getNcaramelsJugador() const { return m_nCaramelsJugador; }
    Tauler getTauler() const { return m_tauler; }
    //setters
    void setColorObjectiu(ColorCandy color) { m_colorObjectiu = color; }
    void setCaramelsObjectiu(int num) { m_nCaramelsObjectiu = num; }
    void setMovimentsObjectius(int num) { m_nMovimentsMax = num; }
    void setMovimentsJugador(int num) { m_nMovimentsJugador = num; }
    void setPuntuacio(int num) { m_puntuacio = num; }
    //metodes de la partida
    void escriuTauler(const string& nomFitxer);
    void inicialitza(const string& nomFitxer);
    void dibuixa(Posicio pos);
    bool iniciaMoviment(const Posicio& pos1, const Posicio& pos2);
    bool continuaMoviment();



private:
    //atributs
    Tauler m_tauler;
    ColorCandy m_colorObjectiu;
    int m_nMovimentsMax;
    int m_nMovimentsJugador;
    int m_nCaramelsObjectiu;
    int m_nCaramelsJugador;
    int m_seqCaramels;
    int m_puntuacio;
};

#endif
