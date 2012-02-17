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
	/** Maximal Blocks on x-axis */
	const static int maxX = 128;
	/** Maximal Blocks on y-axis */
	const static int maxY = 128;
	/**
	 * Constructor.
	 * @params *sl - needed for Image-displaying later for the Blocks.
	 * @params *in - needed for... good question...
	 * @params *cm - needed for communication to other Chunks.
	 */
	Chunk(int x, int y, SurfaceLoader *sl, Input *in, ChunkManager *cm);
	/**
	 * Destrucor.
	 */
	virtual ~Chunk();
	/**
	 * For Calculating all the drawing positions of the Blocks.
	 */
	void tick(Sint32 wx, Sint32 wy);
	/**
	 * Renders all Blocks to screen.
	 */
	void render(SDLDisplay *display);
	/**
	 * Blocks can get blocks near to them
	 * in even other chunks.
	 */
	Block* getRelativeBlock(Sint32 x, Sint32 y);
	/**
	 * Set block-pointer to the value "set".
	 */
	bool setRelativeBlock(Sint32 x, Sint32 y, Block *set);
	/**
	 * Update all existing blocks in matrix.
	 */
	void updateAll();
	/**
	 * Delete a block.
	 * You cannot get that block back.
	 */
	void deleteBlock(Sint32 x, Sint32 y);
	/**
	 * Set a block-pointer in the matrix of this,
	 * or other surrounding chunks to "b".
	 */
	void createBlock(Sint32 x, Sint32 y, Block *b);
private:
	SurfaceLoader *sl;
	Input *in;
	ChunkManager *cm;
	/** Stores all Blocks */
	Block *blocks[maxX][maxY];
	/** x position in ChunkManager's Matrix */
	int x;
	/** y position in ChunkManager's Matrix */
	int y;
	void create();
};

#endif /* CHUNK_H_ */
