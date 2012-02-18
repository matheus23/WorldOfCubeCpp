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
		/**
		 *   0
		 * 0 # 0
		 *   0
		 */
		ALONE,

		/**
		 *   0
		 * 0 # #
		 *   #
		 */
		TOP_LEFT,

		/**
		 *   0
		 * # # #
		 *   #
		 */
		TOP,

		/**
		 *   0
		 * # # 0
		 *   #
		 */
		TOP_RIGHT,

		/**
		 *   0
		 * 0 # 0
		 *   #
		 */
		END_TOP,

		/**
		 *   #
		 * 0 # #
		 *   #
		 */
		LEFT,

		/**
		 *   #
		 * # # #
		 *   #
		 */
		FILLED,

		/**
		 *   #
		 * # # 0
		 *   #
		 */
		RIGHT,

		/**
		 *   #
		 * 0 # 0
		 *   0
		 */
		END_BOTTOM,

		/**
		 *   #
		 * # # 0
		 *   0
		 */
		BOTTOM_LEFT,

		/**
		 *   #
		 * # # #
		 *   0
		 */
		BOTTOM,

		/**
		 *   #
		 * # # 0
		 *   0
		 */
		BOTTOM_RIGHT,

		/**
		 *   0
		 * 0 # #
		 *   0
		 */
		END_LEFT,

		/**
		 *   0
		 * # # 0
		 *   0
		 */
		END_RIGHT,

		/**
		 *   #
		 * 0 # 0
		 *   #
		 */
		PIPE_V,

		/**
		 *   0
		 * # # #
		 *   0
		 */
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
