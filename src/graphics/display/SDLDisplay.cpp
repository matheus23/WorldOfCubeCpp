/*
 * SDLDisplay.cpp
 *
 *  Created on: 21.01.2012
 *      Author: matheusdev
 */

#include <iostream>
#include <SDL/SDL.h>
#include "graphics/display/SDLDisplay.h"

bool sdlInited = false;

SDLDisplay::SDLDisplay(int width, int height, const char* caption) :
		screen(NULL) {
	if (tryInit(width, height, caption) == false) {
		std::cerr << "Failed to Init SDLDisplay!" << std::endl;
	}
}

SDLDisplay::~SDLDisplay() {
	SDL_Quit();
}

bool SDLDisplay::tryInit(int width, int height, const char* caption) {
	if (sdlInited != true) {
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
			return false;
		}
		/** I dont know, how this line got here,
		 * it has nothing to do with solid SDL-rendering:
		 * SDL_GL_SetAttribute(SDL_GL_SWAP_CONTROL, 1);
		 */
		screen = setVideoMode(width, height);
		if (!screen) {
			return false;
		}
		SDL_WM_SetCaption(caption, NULL);
		SDL_Surface *image = SDL_LoadBMP("WorldOfCubeIcon.bmp");
		Uint32 colorkey = SDL_MapRGB(image->format, 255, 255, 255);
		SDL_SetColorKey(image, SDL_SRCCOLORKEY, colorkey);
		SDL_WM_SetIcon(image, NULL);
		SDL_FreeSurface(image);
		sdlInited = true;
		return true;
	} else {
		return false;
	}
}

SDL_Surface* SDLDisplay::setVideoMode(int width, int height) {
	return SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
}

bool SDLDisplay::getCloseRequested() {
	SDL_Event event;
	SDL_PollEvent(&event);
	return event.type == SDL_QUIT;
}

void SDLDisplay::flipBuffers() {
	SDL_Flip(screen);
	SDL_FillRect(screen, NULL, 0x1F3FFFFF);
}

SDL_Surface* SDLDisplay::getScreenSurface() {
	return screen;
}

