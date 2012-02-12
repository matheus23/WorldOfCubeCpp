/*
 * SurfaceLoader.cpp
 *
 *  Created on: 21.01.2012
 *      Author: philipp
 */

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include "Texture.h"
#include "graphics/image/SurfaceLoader.h"

SurfaceLoader::SurfaceLoader() {
	loadSurfaces();
	loadBlocks();
}

SurfaceLoader::~SurfaceLoader() {
	for (int i = 0; i < MAX_VAL_BLOCK_TEXTURE; i++) {
		textures[i]->~Texture();
	}
	for (int i = 0; i < MAX_VAL_BLOCK_TYPE; i++) {
		delete rects[i];
	}
}

void SurfaceLoader::loadSurfaces() {
	//TODO: XML-File loading!
	textures[EARTH] = new Texture(loadSurface("blocksEarth.png"));
	textures[GRASS] = new Texture(loadSurface("blocksGrass.png"));
}

void SurfaceLoader::loadBlocks() {
	rects[ALONE] 		= createRect(00, 00, 16, 16);
	rects[TOP_LEFT] 	= createRect(16, 00, 16, 16);
	rects[TOP] 			= createRect(32, 00, 16, 16);
	rects[TOP_RIGHT]	= createRect(48, 00, 16, 16);
	rects[END_TOP] 		= createRect(00, 16, 16, 16);
	rects[LEFT] 		= createRect(16, 16, 16, 16);
	rects[FILLED] 		= createRect(32, 16, 16, 16);
	rects[RIGHT] 		= createRect(48, 16, 16, 16);
	rects[END_BOTTOM] 	= createRect(00, 32, 16, 16);
	rects[BOTTOM_LEFT]	= createRect(16, 32, 16, 16);
	rects[BOTTOM] 		= createRect(32, 32, 16, 16);
	rects[BOTTOM_RIGHT]	= createRect(48, 32, 16, 16);
	rects[END_LEFT]		= createRect(00, 48, 16, 16);
	rects[END_RIGHT]	= createRect(16, 48, 16, 16);
	rects[PIPE_V]		= createRect(32, 48, 16, 16);
	rects[PIPE_H] 		= createRect(48, 48, 16, 16);
}

SDL_Surface* SurfaceLoader::loadSurface(const char* file) {
	// The Image, loaded from Disk:
	SDL_Surface* loadedImage = IMG_Load(file);
	// The Image, which is optimized, and will be returned:
	SDL_Surface* optimizedImage = NULL;
	// loadedImage is null, if IMG_Load could not load it.
	if (loadedImage != NULL) {
		if (loadedImage->format->alpha) {
			optimizedImage = SDL_DisplayFormatAlpha(loadedImage);
		} else {
			optimizedImage = SDL_DisplayFormat(loadedImage);
		}
	}
	// Check if everything went good:
	if (optimizedImage != NULL) {
		return optimizedImage;
	} else {
		// If not, print an error, and exit:
		std::cout << "Could not load Image into SDL_Surface!" << std::endl;
		exit(0);
	}
}

SDL_Rect* SurfaceLoader::createRect(Sint32 x, Sint32 y, Uint32 w, Uint32 h) {
	SDL_Rect *r = new SDL_Rect;
	r->x = x;
	r->y = y;
	r->w = w;
	r->h = h;
	return r;
}
