#include "../Header/Menu.h"
#include "../Header/Resources.h"
#include "../Header/Match.h"

Menu::Menu(Resources *resources, int volumen) {
	m_resources = resources;
	m_volumen = volumen;
	m_background.setTexture(m_resources->getBackgroundMenu());
	
	m_music.openFromFile("Resources/Sounds/music_menu.wav");
	m_music.setVolume(m_volumen);
	m_music.play();
	m_music.setLoop(true);
	
	m_cambio_opcion.setBuffer(m_resources->getBufferCambioOpcion());
	m_cambio_opcion.setVolume(m_volumen+50);
	
	/// Text
	m_play.setFont(m_resources->getFont());
	m_play.setString("Play");
	m_play.setPosition(880, 400);
	m_play.setCharacterSize(70);
	m_play.setFillColor(sf::Color(33,33,33));
	
	m_options.setFont(m_resources->getFont());
	m_options.setString("Options");
	m_options.setPosition(820, 540);
	m_options.setCharacterSize(70);
	
	m_credits.setFont(m_resources->getFont());
	m_credits.setString("Credits");
	m_credits.setPosition(820, 680);
	m_credits.setCharacterSize(70);
	
	m_exit.setFont(m_resources->getFont());
	m_exit.setString("Exit");
	m_exit.setPosition(880, 820);
	m_exit.setCharacterSize(70);
	
	m_ultimo_texto = 1;
	m_retraso_cambiar_opcion = 0.1;
	m_tiempo = 0+m_retraso_cambiar_opcion;
	m_reloj.restart();
}

void Menu::Actualizar (Juego &juego) {
	if(m_reloj.getElapsedTime().asSeconds() >= m_tiempo) {
		AnimacionTexto();
		m_tiempo = m_reloj.getElapsedTime().asSeconds()+m_retraso_cambiar_opcion;
	}
	ControlOpciones(juego);
}

void Menu::Dibujar (sf::RenderWindow &window) {
	window.clear(sf::Color(33,33,33));
	window.draw(m_background);
	window.draw(m_play);
	window.draw(m_options);
	window.draw(m_credits);
	window.draw(m_exit);
	window.display();
}

void Menu::AnimacionTexto ( ) {
	m_r1 = m_g1 = m_b1 = 33;
	m_r2 = m_g2 = m_b2 = 255;
	AnimacionTextoUp();
	AnimacionTextoDown();
}

void Menu::AnimacionTextoUp ( ) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_ultimo_texto == 1) {
		m_cambio_opcion.play();
		m_play.setFillColor(sf::Color(m_r2,m_g2,m_b2));
		m_exit.setFillColor(sf::Color(m_r1,m_g1,m_b1));
		m_ultimo_texto = 4;
		return;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_ultimo_texto == 2) {
		m_cambio_opcion.play();
		m_options.setFillColor(sf::Color(m_r2,m_g2,m_b2));
		m_play.setFillColor(sf::Color(m_r1,m_g1,m_b1));
		m_ultimo_texto = 1;
		return;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_ultimo_texto == 3) {
		m_cambio_opcion.play();
		m_credits.setFillColor(sf::Color(m_r2,m_g2,m_b2));
		m_options.setFillColor(sf::Color(m_r1,m_g1,m_b1));
		m_ultimo_texto = 2;
		return;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_ultimo_texto == 4) {
		m_cambio_opcion.play();
		m_exit.setFillColor(sf::Color(m_r2,m_g2,m_b2));
		m_credits.setFillColor(sf::Color(m_r1,m_g1,m_b1));
		m_ultimo_texto = 3;
		return;
	}
}

void Menu::AnimacionTextoDown ( ) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_ultimo_texto == 1) {
		m_cambio_opcion.play();
		m_play.setFillColor(sf::Color(m_r2,m_g2,m_b2));
		m_options.setFillColor(sf::Color(m_r1,m_g1,m_b1));
		m_ultimo_texto = 2;
		return;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_ultimo_texto == 2) {
		m_cambio_opcion.play();
		m_options.setFillColor(sf::Color(m_r2,m_g2,m_b2));
		m_credits.setFillColor(sf::Color(m_r1,m_g1,m_b1));
		m_ultimo_texto = 3;
		return;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_ultimo_texto == 3) {
		m_cambio_opcion.play();
		m_credits.setFillColor(sf::Color(m_r2,m_g2,m_b2));
		m_exit.setFillColor(sf::Color(m_r1,m_g1,m_b1));
		m_ultimo_texto = 4;
		return;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_ultimo_texto == 4) {
		m_cambio_opcion.play();
		m_exit.setFillColor(sf::Color(m_r2,m_g2,m_b2));
		m_play.setFillColor(sf::Color(m_r1,m_g1,m_b1));
		m_ultimo_texto = 1;
		return;
	}
}

void Menu::ControlOpciones (Juego &juego) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && m_ultimo_texto == 1) {
		Finalizar();
		juego.CambiarEscena(new Match(m_resources, m_volumen));
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && m_ultimo_texto == 2) {
		///Finalizar();
		///juego.CambiarEscena(new Options(m_resources, m_volumen));
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && m_ultimo_texto == 3) {
		///Finalizar();
		///juego.CambiarEscena(new Credits(m_resources, m_volumen));
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && m_ultimo_texto == 4) {
		Finalizar();
		juego.Finalizar();
	}
}

void Menu::Finalizar ( ) {
	m_music.stop();
}

Menu::~Menu ( ) {
	
}
