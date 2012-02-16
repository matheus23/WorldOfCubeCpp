/*
 * ChunkManager.cpp
 *
 *  Created on: 02.02.2012
 *      Author: philipp
 */

#include "game/layers/chunks/Chunk.h"
#include "ChunkManager.h"

ChunkManager::ChunkManager(SurfaceLoader *sl, Input *in) :
sl(sl),
in(in) {
	createChunks();
}

ChunkManager::~ChunkManager() {
	for (unsigned int x = 0; x < maxX; x++) {
		for (unsigned int y = 0; y < maxY; y++) {
			if (chunks[x][y] != NULL) {
				chunks[x][y]->~Chunk();
			}
		}
	}
}

void ChunkManager::createChunks() {
	for (unsigned int x = 0; x < maxX; x++) {
		for (unsigned int y = 0; y < maxY; y++) {
			chunks[x][y] = new Chunk(sl, in, this);
		}
	}
}

void ChunkManager::tick(Sint32 wx, Sint32 wy) {
	for (unsigned int x = 0; x < maxX; x++) {
		for (unsigned int y = 0; y < maxY; y++) {
			if (chunks[x][y] != NULL) {
				chunks[x][y]->tick(wx, wy);
			}
		}
	}
}

void ChunkManager::render(SDLDisplay *display) {
	for (unsigned int x = 0; x < maxX; x++) {
		for (unsigned int y = 0; y < maxY; y++) {
			if (chunks[x][y] != NULL) {
				chunks[x][y]->render(display);
			}
		}
	}
}
