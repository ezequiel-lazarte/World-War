#ifndef JUEGO_H
#define JUEGO_H
#include "Scene.h"
#include "Resources.h"
class Escena;
class Juego {
public:
	Juego();
	void Jugar();
	void Actualizar();
	void ProcesarEventos();
	void Dibujar();
	void CambiarEscena(Escena *Proxima_Escena);
	void Finalizar();
	sf::RenderWindow &getWindow();
	~Juego();
private:
	Escena *m_escena;
	Escena *m_proxima_escena = nullptr;
	Resources *m_resources;
	sf::RenderWindow m_window;
	sf::Vector2f m_size_screen;
	int m_fps, m_volumen;
};

#endif

