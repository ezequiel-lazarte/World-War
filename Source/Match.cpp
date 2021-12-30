#include "../Header/Match.h"
#include "../Header/Resources.h"
#include "../Header/Menu.h"

Match::Match(Resources *resources, int volumen) {
	m_resources = resources;
	m_volumen = volumen;
}

void Match::Actualizar (Juego & juego) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		juego.CambiarEscena(new Menu(m_resources, m_volumen));
	}
}

void Match::Dibujar (sf::RenderWindow & window) {
	window.clear();
	window.display();
}

