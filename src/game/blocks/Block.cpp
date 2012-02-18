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
	bool left = c->getRelativeBlock(x-1, y) != NULL;
	bool right = c->getRelativeBlock(x+1, y) != NULL;
	bool top = c->getRelativeBlock(x, y-1) != NULL;
	bool bottom = c->getRelativeBlock(x, y+1) != NULL;

	/**
	 * Much more quick algorithm,
	 * then at the bottom:
	 */
	if (left) {
		if (right) {
			if (top) {
				if (bottom) {
					return sl->FILLED;
				} else {
					return sl->BOTTOM;
				}
			} else {
				if (bottom) {
					return sl->TOP;
				} else {
					return sl->PIPE_H;
				}
			}
		} else {
			if (top) {
				if (bottom) {
					return sl->RIGHT;
				} else {
					return sl->BOTTOM_RIGHT;
				}
			} else {
				if (bottom) {
					return sl->TOP_RIGHT;
				} else {
					return sl->END_RIGHT;
				}
			}
		}
	} else {
		if (right) {
			if (top) {
				if (bottom) {
					return sl->LEFT;
				} else {
					return sl->BOTTOM_LEFT;
				}
			} else {
				if (bottom) {
					return sl->TOP_LEFT;
				} else {
					return sl->END_LEFT;
				}
			}
		} else {
			if (top) {
				if (bottom) {
					return sl->PIPE_V;
				} else {
					return sl->END_BOTTOM;
				}
			} else {
				if (bottom) {
					return sl->END_TOP;
				} else {
					return sl->ALONE;
				}
			}
		}
	}
	/**
	 * This is left for lookup, but will never
	 * be executed!
	 */
	if (!left && !right && !top && !bottom) {
		return sl->ALONE;
	} if (left && right && top && bottom) {
		return sl->FILLED;
	} if (!left && right && !top && bottom) {
		return sl->TOP_LEFT;
	} if (left && right && !top && bottom) {
		return sl->TOP;
	} if (left && !right && !top && bottom) {
		return sl->TOP_RIGHT;
	} if (left && !right && top && bottom) {
		return sl->RIGHT;
	} if (left && !right && top && !bottom) {
		return sl->BOTTOM_RIGHT;
	} if (left && right && top && !bottom) {
		return sl->BOTTOM;
	} if (!left && right && top && !bottom) {
		return sl->BOTTOM_LEFT;
	} if (!left && right && top && bottom) {
		return sl->LEFT;
	} if (!left && !right && top && bottom) {
		return sl->PIPE_V;
	} if (left && right && !top && !bottom) {
		return sl->PIPE_H;
	} if (left && !right && !top && !bottom) {
		return sl->END_RIGHT;
	} if (!left && right && !top && !bottom) {
		return sl->END_LEFT;
	} if (!left && !right && top && !bottom) {
		return sl->END_BOTTOM;
	} if (!left && !right && !top && bottom) {
		return sl->END_TOP;
	}
	return sl->ALONE;
}
