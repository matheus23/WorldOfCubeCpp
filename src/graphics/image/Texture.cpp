/*
 * Texture.cpp
 *
 *  Created on: 21.01.2012
 *      Author: philipp
 */

#include <SDL/SDL.h>
#include "graphics/image/Texture.h"

Texture::Texture(SDL_Surface * surface) :
		surface(surface) {
}

Texture::~Texture() {
	SDL_FreeSurface(surface);
}

void Texture::draw(Sint32 x, Sint32 y, SDLDisplay * display) {
	SDL_Rect r = { x, y, 0, 0 };
	SDL_BlitSurface(surface, NULL, display->getScreenSurface(), &r);
}

void Texture::drawAsBlock(Sint32 x, Sint32 y, SDL_Rect *blockPiece,
		SDLDisplay *display) {
	SDL_Rect r = { x, y, 0, 0 };
	SDL_BlitSurface(surface, blockPiece, display->getScreenSurface(), &r);
}

