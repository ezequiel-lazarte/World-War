#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Escenas/Escena.h"

class Escena;
class Juego {
public:
	Juego();
	void Jugar();
	void Actualizar();
	void ProcesarEventos();
	void Dibujar();
	void CambiarEscena(Escena *Proxima_Escena);
	sf::RenderWindow &getWindow();
	~Juego();
private:
	sf::RenderWindow m_window;
	Escena *m_escena;
	Escena *m_proxima_escena = nullptr;
};

#endif

