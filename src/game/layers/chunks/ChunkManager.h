/*
 * ChunkManager.h
 *
 *  Created on: 02.02.2012
 *      Author: philipp
 */

#ifndef CHUNKMANAGER_H_
#define CHUNKMANAGER_H_

#include "graphics/image/SurfaceLoader.h"
#include "input/Input.h"

class Chunk;

class ChunkManager {
public:
	/** This is the maximal Number of Chunks on the X-Axis */
	const static int maxX = 1;
	/** This is the maximal Number of Chunks on the Y-Axis */
	const static int maxY = 1;

	ChunkManager(SurfaceLoader *sl, Input *in);
	virtual ~ChunkManager();
	/**
	 * Calls tick() from all chunks.
	 */
	void tick(Sint32 wx, Sint32 wy);
	/**
	 * Calls render() from all Chunks.
	 */
	void render(SDLDisplay *display);
	/**
	 *
	 */
	/** Matrix, which holds all the Chunks inside */
	Chunk* chunks[maxX][maxY];
private:
	SurfaceLoader *sl;
	Input *in;
	/**
	 * creates the whole World.
	 */
	void createChunks();
};

#endif /* CHUNKMANAGER_H_ */
