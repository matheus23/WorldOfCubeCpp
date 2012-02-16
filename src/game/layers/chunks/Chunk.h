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
#include "input/Input.h"

class ChunkManager;

class Chunk {
public:
	Chunk(SurfaceLoader *sl, Input *in, ChunkManager *cm);
	virtual ~Chunk();
	void tick();
	void render(SDLDisplay *display);
private:
	SurfaceLoader *sl;
	Input *in;
	ChunkManager *cm;
};

#endif /* CHUNK_H_ */
