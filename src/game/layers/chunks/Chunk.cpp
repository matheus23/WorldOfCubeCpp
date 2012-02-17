/*
 * Chunk.cpp
 *
 *  Created on: 02.02.2012
 *      Author: philipp
 */

#include "graphics/image/SurfaceLoader.h"
#include "input/Input.h"
#include "game/layers/chunks/ChunkManager.h"
#include "graphics/display/SDLDisplay.h"
#include "game/blocks/BlockGrass.h"
#include "Chunk.h"

Chunk::Chunk(int x, int y, SurfaceLoader *sl, Input *in, ChunkManager *cm) :
		x(x), y(y), sl(sl), in(in), cm(cm) {
	create();
}

Chunk::~Chunk() {
	for (int x = 0; x < maxX; x++) {
		for (int y = 0; y < maxY; y++) {
			if (blocks[x][y] != NULL) {
				delete blocks[x][y];
				blocks[x][y] = NULL;
			}
		}
	}
}

void Chunk::create() {
	for (int x = 0; x < maxX; x++) {
		for (int y = 0; y < maxY; y++) {
			blocks[x][y] = NULL;
		}
	}
	for (int x = 0; x < maxX; x++) {
		for (int y = 0; y < maxY; y++) {
			if (cm->random() % 2 == 1 || x == 0 || y == 0 || x == maxX-1 || y == maxY-1) {
				blocks[x][y] = new BlockGrass(x, y, sl, this);
			}
		}
	}
}

Block* Chunk::getRelativeBlock(Sint32 blockx, Sint32 blocky) {
	if (blockx >= 0 && blocky >= 0 && blockx < maxX && blocky < maxY) {
		return blocks[blockx][blocky];
	} else {
		int totalx = x * maxX + blockx;
		int totaly = y * maxY + blocky;
		int chunkx = totalx / maxX;
		int chunky = totaly / maxY;
		int finalx = totalx - (chunkx * maxX);
		int finaly = totaly - (chunky * maxY);
		if (chunkx >= 0 && chunky >= 0 && chunkx < cm->maxX && chunky < cm->maxY
				&& finalx >= 0 && finaly >= 0 && finalx < maxX
				&& finaly < maxY) {
			return cm->chunks[chunkx][chunky]->blocks[finalx][finaly];
		}
		return NULL;
	}
}

bool Chunk::setRelativeBlock(Sint32 blockx, Sint32 blocky, Block *set) {
	if (blockx >= 0 && blocky >= 0 && blockx < maxX && blocky < maxY) {
		blocks[blockx][blocky] = set;
		return true;
	} else {
		int totalx = x * maxX + blockx;
		int totaly = y * maxY + blocky;
		int chunkx = totalx / maxX;
		int chunky = totaly / maxY;
		int finalx = totalx - (chunkx * maxX);
		int finaly = totaly - (chunky * maxY);
		if (chunkx >= 0 && chunky >= 0 && chunkx < cm->maxX && chunky < cm->maxY
				&& finalx >= 0 && finaly >= 0 && finalx < maxX
				&& finaly < maxY) {
			cm->chunks[chunkx][chunky]->blocks[finalx][finaly] = set;
			return true;
		}
		return false;
	}
}

void Chunk::tick(Sint32 wx, Sint32 wy) {
	beginx = (wx/sl->BLOCK_SIZE)-x*maxX;
	beginy = (wy/sl->BLOCK_SIZE)-y*maxY;
	if (beginx < 0 ) beginx = 0;
	if (beginx > maxX-1) beginx = maxX-1;
	if (beginy < 0) beginy = 0;
	if (beginy > maxY-1) beginy = maxY-1;

	// TODO: Remove Window size Constants.
	endx = beginx+(800/sl->BLOCK_SIZE);
	endy = beginy+(600/sl->BLOCK_SIZE);
	if (endx < 0) endx = 0;
	if (endx > maxX-1) endx = maxX-1;
	if (endy < 0) endy = 0;
	if (endy > maxY-1) endy = maxY-1;
	endx++;
	endy++;

	for (int x = beginx; x < endx; x++) {
		for (int y = beginy; y < endy; y++) {
			if (blocks[x][y] != NULL) {
				blocks[x][y]->tick(wx, wy);
			}
		}
	}
}

void Chunk::render(SDLDisplay *display) {
	for (int x = beginx; x < endx; x++) {
		for (int y = beginy; y < endy; y++) {
			if (blocks[x][y] != NULL) {
				blocks[x][y]->render(display);
			}
		}
	}
}

void Chunk::updateAll() {
	for (int x = 0; x < maxX; x++) {
		for (int y = 0; y < maxY; y++) {
			if (blocks[x][y] != NULL) {
				blocks[x][y]->update();
			}
		}
	}
}

void Chunk::deleteBlock(Sint32 x, Sint32 y) {
	Block *b = getRelativeBlock(x, y);
	if (b != NULL) {
		delete b;
		b = NULL;
		return;
	}
}

void Chunk::createBlock(Sint32 x, Sint32 y, Block *b) {
	if (!setRelativeBlock(x, y, b) && b != NULL) {
		delete b;
		b = NULL;
	}
}
