/*
 * BlockGrass.cpp
 *
 *  Created on: 16.02.2012
 *      Author: philipp
 */

#include "BlockGrass.h"

BlockGrass::BlockGrass(Sint32 x, Sint32 y, SurfaceLoader *sl, Chunk *c) :
	Block(x, y, sl, c) {
	texID = sl->GRASS;
	blockID = sl->ALONE;
}

BlockGrass::~BlockGrass() {
}

void BlockGrass::update() {

}

void BlockGrass::tick(Sint32 wx, Sint32 wy) {
	drawx = (x*sl->BLOCK_SIZE)-wx;
	drawy = (y*sl->BLOCK_SIZE)-wy;
}

void BlockGrass::render(SDLDisplay *display) {
	sl->textures[texID]->drawAsBlock(drawx, drawy, sl->rects[blockID], display);
}
