#include "SoundEffect.h"

using namespace sf;
using namespace ErzatzKnight;

SoundEffect::SoundEffect(sf::SoundBuffer * sound) {
	this->sound = sound;
}

SoundEffect::~SoundEffect() {
	delete sound;
}

void SoundEffect::playSound() {
	this->sound
}
		
void SoundEffect::stopSound() {

}
		
