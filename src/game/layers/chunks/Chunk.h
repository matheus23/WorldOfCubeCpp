/*
 * Chunk.h
 *
 *  Created on: 02.02.2012
 *      Author: philipp
 */

#ifndef CHUNK_H_
#define CHUNK_H_

class ChunkManager;

class Chunk {
public:
	Chunk(SurfaceLoader *sl, Input *in, LayerManager *lm, ChunkManager *cm);
	virtual ~Chunk();
	void tick();
	void render(SDLDisplay *display);
private:
	SurfaceLoader *sl;
	Input *in;
	LayerManager *lm;
	ChunkManager *cm;
};

#endif /* CHUNK_H_ */
