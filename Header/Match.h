#ifndef MATCH_H
#define MATCH_H
#include "../Header/Scene.h"
#include "Resources.h"

class Match : public Escena {
public:
	Match(Resources *resources, int volumen);
	void Actualizar (Juego & juego);
	void Dibujar (sf::RenderWindow & window);
private:
	Resources *m_resources;
	int m_volumen;
};

#endif

