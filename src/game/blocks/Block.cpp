/*
 * Block.cpp
 *
 *  Created on: 16.02.2012
 *      Author: philipp
 */

#include <SDL/SDL.h>
#include "game/layers/chunks/Chunk.h"
#include "Block.h"

Block::Block(Sint32 x, Sint32 y, SurfaceLoader *sl, Chunk *c) :
	x(x),
	y(y),
	sl(sl),
	c(c) {

}

Block::~Block() {
}

void Block::update() {

}

void Block::tick(Sint32 wx, Sint32 wy) {
	drawx = (((c->x * c->maxX) + x) * sl->BLOCK_SIZE) - wx;
	drawy = (((c->y * c->maxY) + y) * sl->BLOCK_SIZE) - wy;
}

void Block::render(SDLDisplay *display) {
}

unsigned int Block::calcBorder() {
	return sl->ALONE;
}
