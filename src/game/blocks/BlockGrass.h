/*
 * BlockGrass.h
 *
 *  Created on: 16.02.2012
 *      Author: philipp
 */

#ifndef BLOCKGRASS_H_
#define BLOCKGRASS_H_

#include "game/blocks/Block.h"

class BlockGrass : public Block {
public:
	BlockGrass(Sint32 x, Sint32 y, SurfaceLoader *sl, Chunk *c);
	virtual ~BlockGrass();
	void update();
	void render(SDLDisplay *display);
};

#endif /* BLOCKGRASS_H_ */
