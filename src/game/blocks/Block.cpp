/*
 * Block.cpp
 *
 *  Created on: 16.02.2012
 *      Author: philipp
 */

#include <SDL/SDL.h>
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
}

void Block::render(SDLDisplay *display) {
}

unsigned int Block::calcBorder() {
	return sl->ALONE;
}
