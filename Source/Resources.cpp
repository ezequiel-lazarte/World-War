#include "../Header/Resources.h"
#include "../Header/Utilidades.h"

Resources::Resources ( ) : m_pos(-1) {
	
}

/** ****************** ************ ***** TEXTURES ***** ************ ****************** **/

sf::Texture &Resources::getBackgroundMenu ( ) {
	m_texture.loadFromFile("Resources/Textures/BackgroundMenu.jpg");
	m_pos = 0;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

sf::Texture &Resources::getBackgroundMatch ( ) {
	m_texture.loadFromFile("Resources/Textures/BackgroundMatch.png");
	m_pos = 1;
	return getTexture_or_insert(m_t, m_texture, m_pos);
}

/** ****************** ************ ***** SOUNDS EFECTS ***** ************ ****************** **/

sf::SoundBuffer & Resources::getBufferCambioOpcion ( ) {
	m_buffer.loadFromFile("Resources/Sounds/cambio_opcion.wav");
	m_pos = 0;
	return getBuffer_or_insert(m_s, m_buffer, m_pos);
}


/** ****************** ************ ***** FONTS ***** ************ ****************** **/

sf::Font & Resources::getFont ( ) {
	m_font.loadFromFile("Resources/Fonts/Games.ttf");
	m_pos = 0;
	return getFont_or_insert(m_f, m_font, m_pos);
}
