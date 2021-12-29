#ifndef MENU_H
#define MENU_H
#include "../Escena.h"

class Menu : public Escena {
public:
	Menu();
	void Actualizar(Juego &juego) override;
	void Dibujar(sf::RenderWindow &window) override;
private:
	
};

#endif

