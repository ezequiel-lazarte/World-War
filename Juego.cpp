#include "Juego.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include "Escenas/Menu/Menu.h"

Juego::Juego() : m_window(sf::VideoMode(1080, 720), "WAR Z") {
	m_window.setVerticalSyncEnabled(true);
	m_window.setFramerateLimit(60);
	m_escena = new Menu();
}

void Juego::Jugar ( ) {
	while(m_window.isOpen()) {
		ProcesarEventos();
		Actualizar();
		Dibujar();
		if(m_proxima_escena) {
			delete m_escena;
			m_escena = m_proxima_escena;
			m_proxima_escena = nullptr;
		}
	}
}

void Juego::ProcesarEventos ( ) {
	sf::Event e;
	while(m_window.pollEvent(e)) {
		if(e.type == sf::Event::Closed) m_window.close();
		else m_escena-> Procesar_evento(e);
	}
}

void Juego::Actualizar ( ) {
	m_escena->Actualizar(*this);
}

void Juego::Dibujar () {
	m_escena->Dibujar(m_window);
}

sf::RenderWindow & Juego::getWindow ( ) {
	return m_window;
}

void Juego::CambiarEscena (Escena *Proxima_Escena) {
	m_proxima_escena = Proxima_Escena;
}

Juego::~Juego ( ) {
	delete m_escena;
}

