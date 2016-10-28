#include "Game.h"
#include <iostream>
#include <Sound/SoundEngine.h>



using namespace ErzatzKnight;
using namespace sf;
using namespace std;

Game::Game() : menuMode(*this, 1200, 800), explorationMode(*this, 1200, 800) {
    cout << "CREATE";
	//const int width = 1650;
    //const int height = 1080;
    this->fullscreen = false;
	this->active = true;
   
    sf::VideoMode mode  = sf::VideoMode::getDesktopMode();
    int width = 1200; /*mode.width;*/
    int height = 800;/*mode.height;*/
    this->window = new sf::RenderWindow(sf::VideoMode(width, height, 32), "Erzatz", sf::Style::Titlebar | sf::Style::Close);
    this->frameClock = new Clock();
    sf::Context context;
    this->currentMode = &this->menuMode;
    this->run();
}

Game::~Game() {
	cout << "DELETE";
}

int Game::run() {
    clock_t debut,fin;
	sf::Event event;
    window->setKeyRepeatEnabled(false);
	window->setJoystickThreshold(1);
    

    clock_t begin,end;


    sf::ContextSettings settings = window->getSettings();
    std::cout << settings.majorVersion << "." << settings.minorVersion << std::endl;

    //Rend la fenêtre active
    window->setActive();

    while (window->isOpen())
    {
        debut = clock();


        

        //Gestion des events
        //this->currentMode->manageEvents();


        // tant qu'il y a des évènements à traiter...
        while (window->pollEvent(event))
        {
			//Gestion du focus
			switch(event.type) {
				case sf::Event::GainedFocus:
					this->setActive(true);
					cout << "Gained focus" << endl;
					break;
				case sf::Event::LostFocus:
					this->setActive(false);
					cout << "Lost focus" << endl;
					break;
				default:
					this->currentMode->managePollEvent(event);
					break;
			}
        }

        window->clear(sf::Color::Black);
		if(active)
			this->currentMode->manageEvents();

		//On dessine ici et non avant sinon ça efface tout !
        this->currentMode->display();
        window->display();

        //Gestion du délai de fin d'affichage pour un affichage régulier des frames
        fin = clock();
        float delai = 20;
        delai = delai - (fin - debut);
        if(delai < 0) {
            delai = 0;
        }
		delai = 0;

		sleep(sf::milliseconds(delai));
    }

	//Deleting resource manager and all assets loaded
	ResourceManager::deleteInstance();

    return 1;
}

void Game::switchToExploration() {
    this->currentMode = &this->explorationMode;
}

void Game::switchToMenu() {
    this->currentMode = &this->menuMode;
}

void Game::quit() {
    this->window->close();
}

void Game::toggleVideoMode() {
    /*int width;
    int height;
    if(this->fullscreen) {
        width = 1200;
        height = 900;
        delete this->window;
        this->window = new sf::RenderWindow(sf::VideoMode(width, height, 32), "Erzatz", sf::Style::Titlebar | sf::Style::Close);
    }
    else {
        sf::VideoMode mode  = sf::VideoMode::getDesktopMode();
        width = mode.width;
        height = mode.height;
        delete this->window;
        this->window = new sf::RenderWindow(mode, "Erzatz", sf::Style::Titlebar | sf::Style::Close | sf::Style::Fullscreen);
    }
    this->fullscreen = !this->fullscreen;
    this->explorationMode->changeSize(width, height);
    this->menuMode->changeSize(width, height);*/
}

void Game::setActive(bool value) {
	this->active = value;
}

void Game::draw(const sf::Drawable& drawable){
	window->draw(drawable);
}

sf::Time Game::resetClock() {
	return this->frameClock->restart();
}