/*
 * SurfaceLoader.h
 *
 *  Created on: 21.01.2012
 *      Author: philipp
 */

#ifndef SURFACELOADER_H_
#define SURFACELOADER_H_

#include "graphics/image/Texture.h"

class SurfaceLoader {
public:
	const static int BLOCK_SIZE = 16;
	SurfaceLoader();
	virtual ~SurfaceLoader();
	// This holds all the different block Image types:
	enum BlockTexture {
		EARTH,
		GRASS,
		MAX_VAL_BLOCK_TEXTURE
	};

	enum BlockType {
		ALONE,
		TOP_LEFT,
		TOP,
		TOP_RIGHT,
		END_TOP,
		LEFT,
		FILLED,
		RIGHT,
		END_BOTTOM,
		BOTTOM_LEFT,
		BOTTOM,
		BOTTOM_RIGHT,
		END_LEFT,
		END_RIGHT,
		PIPE_V,
		PIPE_H,
		MAX_VAL_BLOCK_TYPE
	};

	Texture *textures[MAX_VAL_BLOCK_TEXTURE];

	SDL_Rect *rects[MAX_VAL_BLOCK_TYPE];

	/**
	 * Loads Surfaces. Currently the Surfaces to be
	 * loaded can't be chosen.
	 *
	 * Its planned to get the Surfaces to load from
	 * an XML-file.
	 */
	void loadSurfaces();

	/**
	 * Loads different SDL_Rects for rendering the
	 * specific part of block from the Block-Surfaces
	 */
	void loadBlocks();

private:
	/**
	 * Used to create SDL_Rects.
	 * MAX_VAL-times called from
	 * init();
	 */
	SDL_Rect* createRect(Sint32 x, Sint32 y, Uint32 w, Uint32 h);

	/**
	 * Loads a Surface from the given file-path.
	 * After the load, it calls SDL_DisplayFormat[Alpha].
	 * Exits, if something goes wrong.
	 */
	SDL_Surface* loadSurface(const char* file);
};

#endif /* SURFACELOADER_H_ */
