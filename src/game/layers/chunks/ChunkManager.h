/*
 * ChunkManager.h
 *
 *  Created on: 02.02.2012
 *      Author: philipp
 */

#ifndef CHUNKMANAGER_H_
#define CHUNKMANAGER_H_

#include <iostream>
#include "graphics/image/SurfaceLoader.h"
#include "input/Input.h"

class Chunk;

class ChunkManager {
public:
	/** This is the maximal Number of Chunks on the X-Axis */
	const static int maxX = 2;
	/** This is the maximal Number of Chunks on the Y-Axis */
	const static int maxY = 2;

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
	 * Generate a seed out of a string.
	 */
	unsigned int getSeedNum(std::string seed);
	/**
	 * @return - the random number between 0 and RAND_MAX.
	 */
	int random();

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
