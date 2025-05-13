#include "Joc.hpp"
#include "InfoJoc.h"
#include "GraphicManager.h"


void Joc::inicialitza(const string& nomFitxer)
{
    m_partida.inicialitza(nomFitxer);
    m_temps = 0.0;
    m_estat = ESTAT_JOC_ESPERA;
    m_visible = true;
    m_intercanviValid = false;
    m_finalitzat = false;
    m_primerMoviment = true;
}

bool Joc::suficientDesplaçament(Posicio& posInicial, Posicio& posFinal)
{
    bool esValid = false;
    if ((m_posicioFinal.getColumna() - m_posicioInicial.getColumna() <= 1 && m_posicioFinal.getFila() - m_posicioInicial.getFila() <= 1) && (m_posicioFinal.getColumna() - m_posicioInicial.getColumna() >= -1 && m_posicioFinal.getFila() - m_posicioInicial.getFila() >= -1))
    {
        esValid = true;
    }
    return esValid;
}

void Joc::actualitza(int mousePosX, int mousePosY, bool mouseStatus, double deltaTime)
{
    //TODO 1: Interactuar amb la crida per dibuixar gràfics (sprites).
    // 	      Dibuixar a pantalla el fons i el gràfic amb el tauler buit.
    //------------------------------------------------------------------
    //TODO 1.1 Afegir l'include de GraphicManager --> #include "GraphicManager.h"
    //TODO 1.2 Fer la crida de dibuixar un sprite --> GraphicManager::getInstance()->drawSprite(image, posX, posY, centered);
    //	    Per començar podem cridar el drawSprite amb els params --> 
    //          (IMAGE_BACKGROUND,0,0, false) i 
    //          (IMAGE_BOARD, CELL_INIT_X, CELL_INIT_Y, false)
    /*
    GraphicManager::getInstance()->drawSprite(IMAGE_BACKGROUND, 0, 0, false);
    GraphicManager::getInstance()->drawSprite(IMAGE_BOARD, CELL_INIT_X, CELL_INIT_Y, false);



    //TODO 1.3: Dibuixar a pantalla el gràfic amb el tauler i un caramel blau centrat a la posició (2,2) del tauler

    int posX = 2;
    int posY = 2;
    GraphicManager::getInstance()->drawSprite(IMAGE_BACKGROUND, 0, 0, false);
    GraphicManager::getInstance()->drawSprite(IMAGE_BOARD, CELL_INIT_X, CELL_INIT_Y, false);
    GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_BLUE, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2), CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);



    //TODO 2: Interacció amb el mouse
    //------------------------------------------
    // TODO 2.1: Dibuixar un caramel blau centrat a la posició (2,2) del tauler només si estem pressionant el botó esquerre del mouse
    //          Si no l'estem pressionant només s'ha de dibuixar el tauler sense el caramel


    int posX = 2;
    int posY = 2;
    GraphicManager::getInstance()->drawSprite(IMAGE_BACKGROUND, 0, 0, false);
    GraphicManager::getInstance()->drawSprite(IMAGE_BOARD, CELL_INIT_X, CELL_INIT_Y, false);
    if (mouseStatus)
    {
        GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_BLUE, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2), CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
    }


    // TODO 2.2 Si estem pressionant el botó esquerre del mouse, dibuixar un caramel blau centrat a la posició del tauler on tenim el mouse
    //          Si no l'estem pressionant només s'ha de dibuixar el tauler sense el caramel

    int posX = (mousePosX - CELL_INIT_X) / CELL_W;
    int posY = (mousePosY - CELL_INIT_Y) / CELL_H;
    GraphicManager::getInstance()->drawSprite(IMAGE_BACKGROUND, 0, 0, false);
    GraphicManager::getInstance()->drawSprite(IMAGE_BOARD, CELL_INIT_X, CELL_INIT_Y, false);
    if (mouseStatus && (mousePosX < SCREEN_SIZE_X - CELL_W) && (mousePosX > CELL_INIT_X) &&  (mousePosY < SCREEN_SIZE_Y - CELL_H) && (mousePosY > CELL_INIT_Y))
    {
        GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_BLUE, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2), CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
    }

    //TODO 3: Introduir un temps d'espera
    //-----------------------------------
    // Dibuixar un caramel blau a la posicio (2,2) del tauler. Eliminar-lo quan hagi passat mig segon.
    // Tornar-lo a dibuixar al cap de mig segon i anar repetint el cicle eliminar/dibuixar cada mig segon

    int posX = 2;
    int posY = 2;
    GraphicManager::getInstance()->drawSprite(IMAGE_BACKGROUND, 0, 0, false);
    GraphicManager::getInstance()->drawSprite(IMAGE_BOARD, CELL_INIT_X, CELL_INIT_Y, false);
    m_temps += deltaTime;
    if (m_temps > 0.5)
    {
        m_visible = !m_visible;
        m_temps = 0.0;
    }
    if (m_visible)
    {
        GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_BLUE, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2), CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
    }


    // TODO 4: Imprimir text per pantalla
    //------------------------------------------
    // TODO 4.1: Imprimir les coordenades de la posició actual del ratolí a sota del tauler

    GraphicManager::getInstance()->drawSprite(IMAGE_BACKGROUND, 0, 0, false);
    GraphicManager::getInstance()->drawSprite(IMAGE_BOARD, CELL_INIT_X, CELL_INIT_Y, false);
    if (mouseStatus)
    {
        if ((mousePosX >= CELL_INIT_X) && (mousePosX <= (CELL_INIT_X + (CELL_W * N_COLS))) && (mousePosY >= CELL_INIT_Y) && (mousePosY <= (CELL_INIT_Y + (CELL_H * N_ROWS))))
        {
            int posX = (mousePosX - CELL_INIT_X) / CELL_W;
            int posY = (mousePosY - CELL_INIT_Y) / CELL_H;
            GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_BLUE, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2), CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
        }
    }
    string msg = "X: " + to_string(mousePosX) + ", Y: " + to_string(mousePosY);
    GraphicManager::getInstance()->drawFont(FONT_WHITE_30, FINAL_INIT_X, FINAL_INIT_Y, 1.0, msg);
    */
    //TODO 5: Mostrar l’estat inicial del joc amb tots els caramels col·locats a la seva posició inicial
    //-----------------------------------------
    
    //DIBUIXEM EL TAULER
    GraphicManager::getInstance()->drawSprite(IMAGE_BACKGROUND, 0, 0, false);
    GraphicManager::getInstance()->drawSprite(IMAGE_BOARD, CELL_INIT_X, CELL_INIT_Y, false);

    //CARAMELS OBJECTIUS
    Candy objectiu;
    IMAGE_NAME spriteObjectiu;
    objectiu.setColor(m_partida.getColorObjectiu());
    objectiu.setTipus(NORMAL);
    spriteObjectiu = objectiu.convertirSprite();
    string nCaramelsObjectiu = to_string(m_partida.getNCaramels());
    GraphicManager::getInstance()->drawFont(FONT_CANDY, OBJECTIU_INIT_X, OBJECTIU_INIT_Y, 1, nCaramelsObjectiu);
    GraphicManager::getInstance()->drawSprite(spriteObjectiu, OBJECTIU_INIT_X - 50, OBJECTIU_INIT_Y, false);

    //MOVIMENTS MAXIMS
    string nMovimentsMax = to_string(m_partida.getMovimentsMax());
    GraphicManager::getInstance()->drawFont(FONT_CANDY, MOVIMENTS_INIT_X, MOVIMENTS_INIT_Y, 1, nMovimentsMax);

    //PUNTUACIO
    string puntuacio = to_string(m_partida.getPuntuacio());
    GraphicManager::getInstance()->drawFont(FONT_CANDY, PUNTS_INIT_X, PUNTS_INIT_Y, 1, puntuacio);
    
    //SELECCIONAR CARAMEL
    Posicio posAux;
   
    int posX = (mousePosX - CELL_INIT_X) / CELL_W;
    int posY = (mousePosY - CELL_INIT_Y) / CELL_H;

    switch (m_estat)
    {
    case ESTAT_JOC_ESPERA:
        if (mouseStatus && (mousePosX < SCREEN_SIZE_X - CELL_W) && (mousePosX > CELL_INIT_X) && (mousePosY < SCREEN_SIZE_Y - CELL_H) && (mousePosY > CELL_INIT_Y))
        {
            m_posicioInicial.set(posY, posX);
            m_estat = ESTAT_JOC_INTERCANVI;
        }
        break;

    case ESTAT_JOC_INTERCANVI:
        if (mouseStatus)//mentre que el ratoli estigui clicat anem actualitzant la nova posicio final i anem mirant si el desplaçament es valid
        {
            m_posicioFinal.set(posY, posX);
            m_desplaçamentValid = suficientDesplaçament(m_posicioInicial, m_posicioFinal);
        }
        else
        {
            if (!mouseStatus && m_desplaçamentValid)//si el ratoli no esta clicat i el desplaçament es suficient, mirem si l'intercanvi es valid
            {
                m_intercanviValid = m_partida.iniciaMoviment(m_posicioFinal, m_posicioInicial);
                if (m_intercanviValid) //si l'intercanvi es valid, canviem d'estat
                {
                    m_estat = ESTAT_JOC_MOVIMENTS;
                }
                else//si no esvalid tornem a l'estat incial;
                {
                    m_estat = ESTAT_JOC_ESPERA;
                    m_posicioInicial.set(-1, -1);
                    m_posicioFinal.set(-1, -1);
                    m_desplaçamentValid = false;
                }
            }
            else
            {
                m_estat = ESTAT_JOC_ESPERA;
                m_posicioInicial.set(-1, -1);
                m_posicioFinal.set(-1, -1);
                m_desplaçamentValid = false;
                m_intercanviValid = false;
            }
        }
        break;

    case ESTAT_JOC_MOVIMENTS:
        mouseStatus = false; //No es pot interactuar amb el tauler durant la sequencia de moviments
        m_temps += deltaTime;
        if (m_temps > 0.5)
        {
            m_finalitzat = m_partida.continuaMoviment();

            if (m_finalitzat)
            {
                if (m_partida.getNCaramels() <= m_partida.getNcaramelsJugador() || m_partida.getMovimentsJugador() == m_partida.getMovimentsMax())
                {
                    m_estat = ESTAT_FINAL;
                }
                else
                {
                    m_estat = ESTAT_JOC_ESPERA;
                }
            }
            m_temps = 0.0;
        }
        break;
    default:
        if (m_partida.getNCaramels() <= m_partida.getNcaramelsJugador())
        {
            m_partida.dibuixa(posAux);
            GraphicManager::getInstance()->drawSprite(IMAGE_VICTORY, 60, 350, false);
        }
        else
        {
            m_partida.dibuixa(posAux);
            GraphicManager::getInstance()->drawSprite(IMAGE_LOOSE, 50, 350, false);
        }
        break;
    }
    //Dibuixar caramel al ratoli
    if (mouseStatus && ((mousePosX < SCREEN_SIZE_X - CELL_W) && (mousePosX > CELL_INIT_X) && (mousePosY < SCREEN_SIZE_Y - CELL_H) && (mousePosY > CELL_INIT_Y)) && ((m_posicioFinal.getColumna() - m_posicioInicial.getColumna() <= 1 && m_posicioFinal.getFila() - m_posicioInicial.getFila() <= 1) && (m_posicioFinal.getColumna() - m_posicioInicial.getColumna() >= -1 && m_posicioFinal.getFila() - m_posicioInicial.getFila() >= -1)) && m_estat != ESTAT_FINAL)
    {
        m_partida.dibuixa(m_posicioInicial);
        GraphicManager::getInstance()->drawSprite(m_partida.getTauler().getCaramelTauler(m_posicioInicial.getFila(), m_posicioInicial.getColumna()).convertirSprite(), mousePosX, mousePosY, true);
    }
    else
    {
        if (m_estat != ESTAT_FINAL)
        {
            m_partida.dibuixa(posAux);
        }
    }
}

