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
		sl(sl), in(in), cm(cm), x(x), y(y) {
	for (int x = 0; x < maxX; x++) {
		for (int y = 0; y < maxY; y++) {
			blocks[x][y] = new BlockGrass(x, y, sl, this);
		}
	}
	updateAll();
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
				&& finalx >= 0 && finaly >= 0 && finalx < maxX && finaly < maxY) {
			return cm->chunks[chunkx][chunky]->blocks[finalx][finaly];
		}
		return NULL;
	}
}

bool Chunk::setRelativeBlock(Sint32 blockx, Sint32 blocky, Block *set) {
	if (blockx > 0 && blocky > 0 && blockx < maxX && blocky < maxY) {
		blocks[blockx][blocky] = set;
		return true;
	} else {
		int totalx = x * maxX + blockx;
		int totaly = y * maxY + blocky;
		int chunkx = totalx / maxX;
		int chunky = totaly / maxY;
		int finalx = totalx - (chunkx * maxX);
		int finaly = totaly - (chunky * maxY);
		if (chunkx > 0 && chunky > 0 && chunkx < cm->maxX && chunky < cm->maxY
				&& finalx > 0 && finaly > 0 && finalx < maxX && finaly < maxY) {
			cm->chunks[chunkx][chunky]->blocks[finalx][finaly] = set;
			return true;
		}
		return false;
	}
}

void Chunk::tick(Sint32 wx, Sint32 wy) {
	for (int x = 0; x < maxX; x++) {
		for (int y = 0; y < maxY; y++) {
			if (blocks[x][y] != NULL) {
				blocks[x][y]->tick(wx, wy);
			}
		}
	}
}

void Chunk::render(SDLDisplay *display) {
	for (int x = 0; x < maxX; x++) {
		for (int y = 0; y < maxY; y++) {
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
		fprintf(stdout, "Deleted (%d|%d)\n", x, y);
		return;
	}
	fprintf(stderr, "Failed to delete (%d|%d)\n", x, y);
}

void Chunk::createBlock(Sint32 x, Sint32 y, Block *b) {
	if (!setRelativeBlock(x, y, b) && b != NULL) {
		delete b;
		b = NULL;
	}
}
