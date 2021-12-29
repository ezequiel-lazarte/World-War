#include "../Header/Match.h"
#include "../Header/Resources.h"

Match::Match(Resources *resources, int volumen) {
	m_resources = resources;
	m_volumen = volumen;
}

void Match::Actualizar (Juego & juego) {
	
}

void Match::Dibujar (sf::RenderWindow & window) {
	window.clear();
	window.display();
}

