#ifndef SOUNDEFFECT_H
#define SOUNDEFFECT_H

#include <SFML/Audio.hpp>

namespace ErzatzKnight {
	class SoundEffect {

	private:
		sf::Sound * sound;
		sf::SoundBuffer * buffer;

	public:
		SoundEffect(sf::SoundBuffer * sound);
		~SoundEffect();

		void playSound();
		void stopSound();
		
	};
}

#endif