#include "candy.h"

bool Candy::operator==(const Candy& caramel) const
{
	bool iguals = false;
	if (m_color == caramel.getColor())//si el color dels dos caramels es igual vol dir que el moviment es correcte
	{ 
		iguals = true;
	}
	return iguals;
}
void Candy::dibuixa(Posicio pos)
{
	int posX = pos.getColumna();
	int posY = pos.getFila();

	switch (m_color)
	{
	case VERD:
		if (m_tipus == NORMAL)
		{
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_GREEN, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2), CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
		}
		else
		{
			if (m_tipus == RATLLAT_HORIZONTAL)
			{
				GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_GREEN_HORIZONTAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2), CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
			}
			else
			{
				GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_GREEN_VERTICAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2), CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
			}
		}
		break;

	case LILA:
		if (m_tipus == NORMAL)
		{
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_PURPLE, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2), CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
		}
		else
		{
			if (m_tipus == RATLLAT_HORIZONTAL)
			{
				GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_PURPLE_HORIZONTAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2), CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
			}
			else
			{
				GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_PURPLE_VERTICAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2), CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
			}
		}
		break;

	case BLAU:
		if (m_tipus == NORMAL)
		{
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_BLUE, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2), CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
		}
		else
		{
			if (m_tipus == RATLLAT_HORIZONTAL)
			{
				GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_BLUE_HORIZONTAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2), CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
			}
			else
			{
				GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_BLUE_VERTICAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2), CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
			}
		}
		break;

	case TARONJA:
		if (m_tipus == NORMAL)
		{
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_ORANGE, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2), CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
		}
		else
		{
			if (m_tipus == RATLLAT_HORIZONTAL)
			{
				GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_ORANGE_HORIZONTAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2), CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
			}
			else
			{
				GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_ORANGE_VERTICAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2), CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
			}
		}
		break;

	case VERMELL:
		if (m_tipus == NORMAL)
		{
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_RED, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2), CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
		}
		else
		{
			if (m_tipus == RATLLAT_HORIZONTAL)
			{
				GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_RED_HORIZONTAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2), CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
			}
			else
			{
				GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_RED_VERTICAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2), CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
			}
		}
		break;

	case GROC:
		if (m_tipus == NORMAL)
		{
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_YELLOW, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2), CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
		}
		else
		{
			if (m_tipus == RATLLAT_HORIZONTAL)
			{
				GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_YELLOW_HORIZONTAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2), CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
			}
			else
			{
				GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_YELLOW_VERTICAL, CELL_INIT_X + (posX * CELL_W) + (CELL_W / 2), CELL_INIT_Y + (posY * CELL_H) + (CELL_H / 2), true);
			}
		}
		break;
	default:
		break;
	}
}
IMAGE_NAME Candy::convertirSprite()
{
	IMAGE_NAME nom;

	switch (m_color)
	{
	case VERD:
		if (m_tipus == RATLLAT_HORIZONTAL)
		{
			nom = IMAGE_PIECE_GREEN_HORIZONTAL;
		}
		else
		{
			if (m_tipus == RATLLAT_VERTICAL)
			{
				nom = IMAGE_PIECE_GREEN_VERTICAL;
			}
			else
			{
				nom = IMAGE_PIECE_GREEN;
			}
		}
		break;

	case LILA:
		if (m_tipus == RATLLAT_HORIZONTAL)
		{
			nom = IMAGE_PIECE_PURPLE_HORIZONTAL;
		}
		else
		{
			if (m_tipus == RATLLAT_VERTICAL)
			{
				nom = IMAGE_PIECE_PURPLE_VERTICAL;
			}
			else
			{
				nom = IMAGE_PIECE_PURPLE;
			}
		}
		break;

	case BLAU:
		if (m_tipus == RATLLAT_HORIZONTAL)
		{
			nom = IMAGE_PIECE_BLUE_HORIZONTAL;
		}
		else
		{
			if (m_tipus == RATLLAT_VERTICAL)
			{
				nom = IMAGE_PIECE_BLUE_VERTICAL;
			}
			else
			{
				nom = IMAGE_PIECE_BLUE;
			}
		}
		break;

	case TARONJA:
		if (m_tipus == RATLLAT_HORIZONTAL)
		{
			nom = IMAGE_PIECE_ORANGE_HORIZONTAL;
		}
		else
		{
			if (m_tipus == RATLLAT_VERTICAL)
			{
				nom = IMAGE_PIECE_ORANGE_VERTICAL;
			}
			else
			{
				nom = IMAGE_PIECE_ORANGE;
			}
		}
		break;

	case VERMELL:
		if (m_tipus == RATLLAT_HORIZONTAL)
		{
			nom = IMAGE_PIECE_RED_HORIZONTAL;
		}
		else
		{
			if (m_tipus == RATLLAT_VERTICAL)
			{
				nom = IMAGE_PIECE_RED_VERTICAL;
			}
			else
			{
				nom = IMAGE_PIECE_RED;
			}
		}
		break;

	default:
		if (m_tipus == RATLLAT_HORIZONTAL)
		{
			nom = IMAGE_PIECE_YELLOW_HORIZONTAL;
		}
		else
		{
			if (m_tipus == RATLLAT_VERTICAL)
			{
				nom = IMAGE_PIECE_YELLOW_VERTICAL;
			}
			else
			{
				nom = IMAGE_PIECE_YELLOW;
			}
		}
		break;
	}
	return nom;
}