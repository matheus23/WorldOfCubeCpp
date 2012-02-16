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
	Sint32 x;
	Sint32 y;
	Block(Sint32 x, Sint32 y, SurfaceLoader *sl, Chunk *c);
	virtual ~Block() = 0;
	virtual void tick(Sint32 wx, Sint32 wy) = 0;
	virtual void render(SDLDisplay *display) = 0;
protected:
	SurfaceLoader *sl;
	Chunk *c;
	int texID;
	int blockID;
	Sint32 drawx;
	Sint32 drawy;
};

#endif /* BLOCK_H_ */
