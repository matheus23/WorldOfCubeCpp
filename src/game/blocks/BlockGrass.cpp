/*
 * BlockGrass.cpp
 *
 *  Created on: 16.02.2012
 *      Author: philipp
 */

#include "game/layers/chunks/Chunk.h"
#include "game/blocks/BlockEarth.h"
#include "BlockGrass.h"

BlockGrass::BlockGrass(Sint32 x, Sint32 y, SurfaceLoader *sl, Chunk *c) :
	Block(x, y, sl, c) {
	texID = sl->GRASS;
	blockID = sl->ALONE;
}

BlockGrass::~BlockGrass() {
}

void BlockGrass::update() {
	if (c->getRelativeBlock(x-1, y) != NULL
			&& c->getRelativeBlock(x+1, y) != NULL
			&& c->getRelativeBlock(x, y-1) != NULL
			&& c->getRelativeBlock(x, y+1) != NULL) {
		c->deleteBlock(x, y);
		BlockEarth *b = new BlockEarth(x, y, sl, c);
		c->createBlock(x, y, b);
	}
}

void BlockGrass::render(SDLDisplay *display) {
	sl->textures[texID]->drawAsBlock(drawx, drawy, sl->rects[blockID], display);
}
