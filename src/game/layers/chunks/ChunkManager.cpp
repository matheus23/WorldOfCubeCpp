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
	for (int x = 0; x < maxX; x++) {
		for (int y = 0; y < maxY; y++) {
			chunks[x][y]->~Chunk();
		}
	}
}

void ChunkManager::createChunks() {
	for (int x = 0; x < maxX; x++) {
		for (int y = 0; y < maxY; y++) {
			chunks[x][y] = new Chunk(sl, in, this);
		}
	}
}

void ChunkManager::render(SDLDisplay *display) {
	for (int x = 0; x < maxX; x++) {
		for (int y = 0; y < maxY; y++) {
			chunks[x][y]->render(display);
		}
	}
}
