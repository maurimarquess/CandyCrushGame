#ifndef Joc_hpp
#define Joc_hpp

#include <stdio.h>
#include <string>
#include "InfoJoc.h"
#include "partida.h"

using namespace std;

typedef enum
{
    ESTAT_JOC_ESPERA,
    ESTAT_JOC_INTERCANVI,
    ESTAT_JOC_MOVIMENTS,
    ESTAT_FINAL
} EstatJoc;


class Joc 
{
public:
    Joc() : m_temps(0), m_visible(true), m_estat(ESTAT_JOC_ESPERA), m_intercanviValid(false), m_desplaçamentValid(false), m_finalitzat(false), m_primerMoviment(false) {};
    
    void inicialitza(const string& nomFitxerInicial);
    void actualitza(int mousePosX, int mousePosY, bool mouseStatus, double deltaTime);
    bool suficientDesplaçament(Posicio& posInicial, Posicio& posFinal);
private:
    double m_temps;
    bool m_visible;
    bool m_intercanviValid;
    bool m_desplaçamentValid;
    bool m_finalitzat;
    bool m_primerMoviment;
    Partida m_partida;
    EstatJoc m_estat;
    Posicio m_posicioInicial;
    Posicio m_posicioFinal;
};

#endif /* Joc_hpp */
