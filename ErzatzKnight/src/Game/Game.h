#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <Game/Modes/ExplorationMode.h>
#include <Game/Modes/MenuMode.h>


using namespace ErzatzKnight::Modes;

namespace ErzatzKnight {
    class Game {
    private:
        
        Mode * currentMode; ///< Mode currently running
        ExplorationMode explorationMode; ///< Exploration mode, basically the game
        MenuMode menuMode; ///< Menu mode, to launch game, access options 
        bool fullscreen; ///< Is the game in fullscreen mode
		bool active; ///< Game has focus
		sf::Clock * frameClock; ///< Migrate old time calculation to sf::Clock to manage framerate
        sf::RenderWindow * window;///< Current window the system is drawing in. Must remain a pointer to recreate a new one on the fly

		//Methods
		/// \brief Run the game loop
		int run();

    public:
		
		/// \brief Game constructor
        Game();

		~Game();

		/// \brief Quit the game
        void quit();

		/// \brief Switch to exploration mode
        void switchToExploration();

		/// \brief Switch to menu mode
        void switchToMenu();

		/// \brief Toggle fullscreen/windowed display
        void toggleVideoMode();

		/// \brief Set true if the window is gaining focus, false if the window is losing focus
		/// \param value Define if the window has the focus or not
		void setActive(bool value);

		/// \brief Display an element on the screen
		/// \param drawable Element to display on the screen
		void draw(const sf::Drawable& drawable);

		sf::Time resetClock();
    };
}

#endif