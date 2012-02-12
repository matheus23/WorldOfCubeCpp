/*
 * Texture.h
 *
 *  Created on: 21.01.2012
 *      Author: philipp
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <SDL/SDL.h>
#include "graphics/display/SDLDisplay.h"

class Texture {
public:
	/**
	 * Create a new Texture from a loaded Surface.
	 */
	Texture(SDL_Surface * surface);
	virtual ~Texture();
	SDL_Surface *surface;

	/**
	 * draws the Texture
	 * @params x x-Position.
	 * @params y y-Position.
	 * @params display the Display to draw these Textures on.
	 */
	void draw(Sint32 x, Sint32 y, SDLDisplay *display);

	/**
	 * draw the Texture with a given Rectangle.
	 * The Rectangle can be used to draw only one
	 * of the different tiled blocks.
	 * @params x x-Position.
	 * @params y y-Position.
	 * @params *blockPiece the piece of the Texture
	 * 		to render.
	 * @params *display The display to draw the Texture on.
	 */
	void drawAsBlock(Sint32 x, Sint32 y, SDL_Rect *blockPiece, SDLDisplay *display);
};

#endif /* TEXTURE_H_ */
