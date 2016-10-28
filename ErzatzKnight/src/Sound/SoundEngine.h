#ifndef SOUNDENGINE_H
#define SOUNDENGINE_H

#include <SFML/Audio.hpp>
#include <map>

using namespace sf;
using namespace std;

namespace ErzatzKnight {
    class SoundEngine {

    private:
        SoundEngine();
        ~SoundEngine();


        static SoundEngine * instance;
        map<string, Sound> sounds;

    public:
        static SoundEngine * getInstance();

        Sound * createSoundEffectFromFile(string file);
        Music * createMusicFromFile(string file);

    };
}
#endif