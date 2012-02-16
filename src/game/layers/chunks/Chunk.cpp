/*
 * Chunk.cpp
 *
 *  Created on: 02.02.2012
 *      Author: philipp
 */

#include "graphics/image/SurfaceLoader.h"
#include "input/Input.h"
#include "game/layers/chunks/ChunkManager.h"
#include "graphics/display/SDLDisplay.h"
#include "Chunk.h"

Chunk::Chunk(SurfaceLoader *sl, Input *in, ChunkManager *cm) :
sl(sl),
in(in),
cm(cm) {

}

Chunk::~Chunk() {
}

void Chunk::tick() {

}

void Chunk::render(SDLDisplay *display) {

}
