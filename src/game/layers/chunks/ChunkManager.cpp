/*
 * ChunkManager.cpp
 *
 *  Created on: 02.02.2012
 *      Author: philipp
 */

#include <stdlib.h>
#include "game/layers/chunks/Chunk.h"
#include "ChunkManager.h"

ChunkManager::ChunkManager(SurfaceLoader *sl, Input *in) :
		sl(sl), in(in) {
	createChunks();
	srand(getSeedNum("matheusDEV"));
}

ChunkManager::~ChunkManager() {
	for (int x = 0; x < maxX; x++) {
		for (int y = 0; y < maxY; y++) {
			if (chunks[x][y] != NULL) {
				delete chunks[x][y];
				chunks[x][y] = NULL;
			}
		}
	}
}

int ChunkManager::random() {
	return rand();
}

unsigned int ChunkManager::getSeedNum(std::string seed) {
	unsigned int num = 0x1997;
	for (unsigned int i = 0; i < seed.length(); i++) {
		num *= seed.at(i);
	}
	return num;
}

void ChunkManager::createChunks() {
	for (int x = 0; x < maxX; x++) {
		for (int y = 0; y < maxY; y++) {
			chunks[x][y] = new Chunk(x, y, sl, in, this);
		}
	}
}

void ChunkManager::tick(Sint32 wx, Sint32 wy) {
	for (int x = 0; x < maxX; x++) {
		for (int y = 0; y < maxY; y++) {
			if (chunks[x][y] != NULL) {
				chunks[x][y]->tick(wx, wy);
			}
		}
	}
}

void ChunkManager::render(SDLDisplay *display) {
	for (int x = 0; x < maxX; x++) {
		for (int y = 0; y < maxY; y++) {
			if (chunks[x][y] != NULL) {
				chunks[x][y]->render(display);
			}
		}
	}
}
