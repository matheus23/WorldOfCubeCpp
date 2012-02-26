/*
 * Cursor.cpp
 *
 *  Created on: 18.02.2012
 *      Author: philipp
 */

#include "game/blocks/BlockGrass.h"
#include "game/layers/chunks/Chunk.h"
#include "graphics/image/SurfaceLoader.h"
#include "Cursor.h"

Cursor::Cursor(ChunkManager *cm, Input *in, SurfaceLoader *sl) :
		cm(cm), in(in), sl(sl) {

}

Cursor::~Cursor() {
}

void Cursor::tick(Sint32 wx, Sint32 wy) {
	if (in->getFlagDown(Input::MB_RIGHT)) {
		int totalx = in->mousex + wx;
		int totaly = in->mousey + wy;

		int chunkx = totalx / (SurfaceLoader::BLOCK_SIZE * Chunk::maxX);
		int chunky = totaly / (SurfaceLoader::BLOCK_SIZE * Chunk::maxY);

		int blockx = totalx / SurfaceLoader::BLOCK_SIZE - chunkx * Chunk::maxX;
		int blocky = totaly / SurfaceLoader::BLOCK_SIZE - chunky * Chunk::maxY;

		if (!cm->chunks[chunkx][chunky]->isBlockExsisting(blockx, blocky)) {
			cm->chunks[chunkx][chunky]->createBlock(blockx, blocky,
					new BlockGrass(blockx, blocky, sl, cm->chunks[chunkx][chunky]));
			cm->chunks[chunkx][chunky]->tryUpdateBlock(blockx, blocky);
			cm->chunks[chunkx][chunky]->tryUpdateBlock(blockx + 1, blocky);
			cm->chunks[chunkx][chunky]->tryUpdateBlock(blockx - 1, blocky);
			cm->chunks[chunkx][chunky]->tryUpdateBlock(blockx, blocky + 1);
			cm->chunks[chunkx][chunky]->tryUpdateBlock(blockx, blocky - 1);
		}
	} else if (in->getFlagDown(Input::MB_LEFT)) {
		int totalx = in->mousex + wx;
		int totaly = in->mousey + wy;

		int chunkx = totalx / (SurfaceLoader::BLOCK_SIZE * Chunk::maxX);
		int chunky = totaly / (SurfaceLoader::BLOCK_SIZE * Chunk::maxY);

		int blockx = totalx / SurfaceLoader::BLOCK_SIZE - chunkx * Chunk::maxX;
		int blocky = totaly / SurfaceLoader::BLOCK_SIZE - chunky * Chunk::maxY;

		if (cm->chunks[chunkx][chunky]->isBlockExsisting(blockx, blocky)) {
			cm->chunks[chunkx][chunky]->deleteBlock(blockx, blocky);
			cm->chunks[chunkx][chunky]->tryUpdateBlock(blockx + 1, blocky);
			cm->chunks[chunkx][chunky]->tryUpdateBlock(blockx - 1, blocky);
			cm->chunks[chunkx][chunky]->tryUpdateBlock(blockx, blocky + 1);
			cm->chunks[chunkx][chunky]->tryUpdateBlock(blockx, blocky - 1);
		}
	}
}
