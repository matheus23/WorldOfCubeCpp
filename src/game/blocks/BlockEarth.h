/*
 * BlockEarth.h
 *
 *  Created on: 17.02.2012
 *      Author: philipp
 */

#ifndef BLOCKEARTH_H_
#define BLOCKEARTH_H_

#include "game/blocks/Block.h"

class BlockEarth : public Block {
public:
	BlockEarth(Sint32 x, Sint32 y, SurfaceLoader *sl, Chunk *c);
	virtual ~BlockEarth();
	void update();
	void render(SDLDisplay *display);
};

#endif /* BLOCKEARTH_H_ */
