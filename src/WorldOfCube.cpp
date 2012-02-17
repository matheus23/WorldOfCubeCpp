//============================================================================
// Name        : WorldOfCube.cpp
// Author      : matheusdev
// Version     :
// Copyright   : GPL (GNU General Public License)
// Description :
//============================================================================

#include <SDL/SDL.h>
#include "game/Game.h"

int main() {
	fprintf(stdout, "R:%X G:%X B:%X\n", (unsigned int)(0.57*255.0), (unsigned int)(0.73*255.0), (unsigned int)255);
	Game* game = new Game;
	game->start();
	game->~Game();
	return 0;
}
