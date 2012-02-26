/*
 * Cursor.h
 *
 *  Created on: 18.02.2012
 *      Author: philipp
 */

#ifndef CURSOR_H_
#define CURSOR_H_

#include "input/Input.h"
#include "graphics/image/SurfaceLoader.h"
#include "game/layers/chunks/ChunkManager.h"

class Cursor {
public:
	Cursor(ChunkManager *cm, Input *in, SurfaceLoader *sl);
	virtual ~Cursor();
	void tick(Sint32 wx, Sint32 wy);
private:
	ChunkManager *cm;
	Input *in;
	SurfaceLoader *sl;
};

#endif /* CURSOR_H_ */
