/*
 * Block.h
 *
 *  Created on: 16.02.2012
 *      Author: philipp
 */

#ifndef BLOCK_H_
#define BLOCK_H_

#include "graphics/image/SurfaceLoader.h"
#include "graphics/display/SDLDisplay.h"

class Chunk;

class Block {
public:
	/** x position in the Chunk's Matrix */
	Sint32 x;
	/** y position in the Chunk's Matrix */
	Sint32 y;
	Block(Sint32 x, Sint32 y, SurfaceLoader *sl, Chunk *c);
	virtual ~Block() = 0;
	virtual void update() = 0;
	virtual void tick(Sint32 wx, Sint32 wy);
	virtual void render(SDLDisplay *display) = 0;
protected:
	SurfaceLoader *sl;
	Chunk *c;
	/**
	 *  Texture ID used for rendering the right sprite from
	 *  the SurfaceLoader.
	 */
	int texID;
	/**
	 * The ID, which SDL_Rect to use, when rendering a texture
	 * as a block.
	 */
	int blockID;
	/**
	 * drawing x position.
	 */
	Sint32 drawx;
	/**
	 * drawing y position.
	 */
	Sint32 drawy;
	/**
	 * Method to calculate the blockID
	 */
	unsigned int calcBorder();
};

#endif /* BLOCK_H_ */
