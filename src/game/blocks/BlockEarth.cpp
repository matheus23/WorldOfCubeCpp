/*
 * BlockEarth.cpp
 *
 *  Created on: 17.02.2012
 *      Author: philipp
 */

#include "game/layers/chunks/Chunk.h"
#include "game/blocks/BlockGrass.h"
#include "BlockEarth.h"

BlockEarth::BlockEarth(Sint32 x, Sint32 y, SurfaceLoader *sl, Chunk *c) :
		Block(x, y, sl, c) {
	texID = sl->EARTH;
	blockID = sl->ALONE;
}

BlockEarth::~BlockEarth() {

}

void BlockEarth::update() {
	if (c->getRelativeBlock(x - 1, y) == NULL
			|| c->getRelativeBlock(x + 1, y) == NULL
			|| c->getRelativeBlock(x, y - 1) == NULL
			|| c->getRelativeBlock(x, y + 1) == NULL) {
		c->deleteBlock(x, y);
		BlockGrass *b = new BlockGrass(x, y, sl, c);
		c->createBlock(x, y, b);
	}
}

void BlockEarth::render(SDLDisplay *display) {
	sl->textures[texID]->drawAsBlock(drawx, drawy, sl->rects[blockID], display);
}
