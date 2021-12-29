#ifndef MENU_H
#define MENU_H
#include "../Header/Scene.h"
#include "Resources.h"

class Menu : public Escena {
public:
	Menu(Resources *resources, int volumen);
	void Actualizar(Juego &juego) override;
	void Dibujar(sf::RenderWindow &window) override;
	~Menu();
private:
	void AnimacionTexto();
	void AnimacionTextoUp();
	void AnimacionTextoDown();
	void ControlOpciones(Juego &juego);
	Resources *m_resources;
	sf::Sprite m_background;
	sf::Text m_play, m_options, m_credits, m_exit;
	sf::Clock m_reloj;
	int m_volumen, m_ultimo_texto;
	float m_tiempo, m_retraso_cambiar_opcion;
	unsigned int m_r1, m_r2, m_g1, m_g2, m_b1, m_b2;
};

#endif
