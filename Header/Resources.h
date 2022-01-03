#ifndef RESOURCES_H
#define RESOURCES_H
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <map>
using namespace std;

typedef sf::Texture texture_t;
typedef sf::SoundBuffer sound_t;
typedef sf::Font font_t;
typedef map<int, texture_t>::iterator iterator_t;
typedef map<int, sound_t>::iterator iterator_s;
typedef map<int, font_t>::iterator iterator_f;

class Resources {
public:
	Resources();
	/// textures
	texture_t &getBackgroundMenu();
	texture_t &getBackgroundMatch();
	///sounds
	sound_t &getBufferCambioOpcion();
	///fonts
	font_t &getFont();
private:
	texture_t m_texture;
	sound_t m_buffer;
	font_t m_font;

	map<int, texture_t> m_t;
	map<int, sound_t> m_s;
	map<int, font_t> m_f;
	
	int m_pos;
};

#endif
