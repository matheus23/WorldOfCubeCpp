/*
 * Chunk.h
 *
 *  Created on: 02.02.2012
 *      Author: philipp
 */

#ifndef CHUNK_H_
#define CHUNK_H_

#include "graphics/image/SurfaceLoader.h"
#include "graphics/display/SDLDisplay.h"
#include "game/blocks/Block.h"
#include "input/Input.h"

class ChunkManager;

class Chunk {
public:
	const static int maxX = 128;
	const static int maxY = 128;
	Chunk(SurfaceLoader *sl, Input *in, ChunkManager *cm);
	virtual ~Chunk();
	void tick(Sint32 wx, Sint32 wy);
	void render(SDLDisplay *display);
private:
	SurfaceLoader *sl;
	Input *in;
	ChunkManager *cm;
	Block *blocks[maxX][maxY];
};

#endif /* CHUNK_H_ */
