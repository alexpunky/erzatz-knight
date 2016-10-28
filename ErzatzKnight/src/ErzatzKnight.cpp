#include <iostream>
#include <stdio.h>
#if defined(_WIN32) || defined(__WIN32__)
#include <tchar.h>
#include <SFML/Window.hpp>
#include <Game/Game.h>

#endif

using namespace std;
using namespace ErzatzKnight;

#if defined(_WIN32) || defined(__WIN32__)
int _tmain(int argc, _TCHAR* argv[])
{
    cout << "Win32" << endl;
    Game * game = new Game();
	delete game;
}


#elif defined(__APPLE__) || defined(MACOSX) || defined(macintosh) || defined(Macintosh)
int main()
{
    cout << "Mac OS X" << endl;

}
#endif 