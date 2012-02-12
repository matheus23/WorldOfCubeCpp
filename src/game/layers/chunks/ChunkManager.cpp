/*
 * ChunkManager.cpp
 *
 *  Created on: 02.02.2012
 *      Author: philipp
 */

#include "game/layers/LayerManager.h"
#include "game/layers/chunks/Chunk.h"
#include "ChunkManager.h"

ChunkManager::ChunkManager(SurfaceLoader *sl, Input *in, LayerManager *lm) :
sl(sl),
in(in),
lm(lm) {
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
			chunks[x][y] = new Chunk(sl, in, lm, this);
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
