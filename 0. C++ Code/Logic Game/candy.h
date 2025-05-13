#ifndef CANDY_H
#define CANDY_H

#include <string>
#include "definicions.h"
#include "posicio.h"
#include "InfoJoc.h"
#include "GraphicManager.h"


using namespace std;

class Candy
{
public:
	Candy() { m_color = NO_COLOR, m_tipus = NO_TIPUS; }
	Candy(ColorCandy color, TipusCandy tipus) { m_color = color, m_tipus = tipus; }
	//setters
	void setColor(ColorCandy color) { m_color = color; }
	void setTipus(TipusCandy tipus) { m_tipus = tipus; }
	//getters
	ColorCandy getColor() const { return m_color; }
	TipusCandy getTipus() const { return m_tipus; }
	//metodes
	bool operator==(const Candy& caramel) const;
	void dibuixa(Posicio X);
	IMAGE_NAME convertirSprite();
private:
	//atributs
	ColorCandy m_color;
	TipusCandy m_tipus;
};



#endif
