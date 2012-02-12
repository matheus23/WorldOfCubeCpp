//============================================================================
// Name        : WorldOfCube.cpp
// Author      : matheusdev
// Version     :
// Copyright   : GPL (GNU General Public License)
// Description :
//============================================================================

#include <SDL/SDL.h>
#include "game/Game.h"

using namespace std;

int main() {
	Game* game = new Game;
	game->start();
	game->~Game();
	return 0;
}
