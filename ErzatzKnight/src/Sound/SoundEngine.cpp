#include "SoundEngine.h"

using namespace sf;
using namespace ErzatzKnight;

SoundEngine * SoundEngine::instance = NULL;

SoundEngine::SoundEngine() {

}

SoundEngine::~SoundEngine() {

}

SoundEngine * SoundEngine::getInstance() {
    if(SoundEngine::instance == NULL) {
        SoundEngine::instance = new SoundEngine();
    }
    return SoundEngine::instance;
}

Sound * SoundEngine::createSoundEffectFromFile(string file) {
    sf::SoundBuffer * soundBuffer = new SoundBuffer();
    bool loaded = soundBuffer->loadFromFile(file);
    sf::Sound * sound = new Sound(*soundBuffer);
    return sound;
}

Music * SoundEngine::createMusicFromFile(string file) {
    sf::Music * music = new Music();
    music->openFromFile(file);
    return music;
}