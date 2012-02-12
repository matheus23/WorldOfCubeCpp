/*
 * SDLDisplay.h
 *
 *  Created on: 21.01.2012
 *      Author: matheusdev
 */

#ifndef SDLDISPLAY_H_
#define SDLDISPLAY_H_

#include <SDL/SDL.h>

class SDLDisplay {
public:

	/**
	 * Custom Constructor, which calls tryInit();
	 * If tryInit() gives an error, then an error
	 * Message is written.
	 */
	SDLDisplay(int width, int height, const char* caption);

	virtual ~SDLDisplay();

	/**
	 * Calls SDL_init, if the global Init-variable is not set
	 * to true.
	 * Then setVideoMode() is called with the given size.
	 * Finally it tries to set an Window-Icon, but
	 * It currently can't load alpha Images.
	 * After that it sets the Init-variable to true.
	 */
	bool tryInit(int width, int height, const char* caption);

	/**
	 * This sets the Video Mode (Window size) to the
	 * given arguments.
	 * It calls SDL_SetVideoMode(width, height,
	 * 							32 bpp, SDL_SWSURFACE);
	 */
	SDL_Surface* setVideoMode(int widht, int height);

	/**
	 * @return whether the Close button has been clicked.
	 */
	bool getCloseRequested();

	/**
	 * Calls SDL_Flip, then clears the screen.
	 */
	void flipBuffers();

	/**
	 * @return the screen surface (bad style).
	 */
	SDL_Surface* getScreenSurface();
private:
	SDL_Surface *screen;
};

#endif /* SDLDISPLAY_H_ */
