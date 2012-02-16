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

Chunk::Chunk(SurfaceLoader *sl, Input *in, ChunkManager *cm) :
sl(sl),
in(in),
cm(cm) {
	for (int x = 0; x < maxX; x++) {
		for (int y = 0; y < maxY; y++) {
			blocks[x][y] = new BlockGrass(x, y, sl, this);
		}
	}
}

Chunk::~Chunk() {
	for (int x = 0; x < maxX; x++) {
		for (int y = 0; y < maxY; y++) {
			if (blocks[x][y] != NULL) {
				blocks[x][y]->~Block();
			}
		}
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
