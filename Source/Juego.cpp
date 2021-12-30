#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include "../Header/Juego.h"
#include "../Header/Menu.h"
#include "../Header/Resources.h"

Juego::Juego() : m_size_screen(1920, 1200), m_window(sf::VideoMode(1920, 1200), "World War"), m_fps(60) {
	m_resources = new Resources;
	m_volumen = 50;
	m_window.setVerticalSyncEnabled(true);
	m_window.setFramerateLimit(m_fps);
	m_escena = new Menu(m_resources, m_volumen);
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

void Juego::Finalizar ( ) {
	m_window.close();
}

Juego::~Juego ( ) {
	delete m_escena;
	delete m_resources;
}

