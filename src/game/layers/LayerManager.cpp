/*
 * LayerManager.cpp
 *
 *  Created on: 02.02.2012
 *      Author: philipp
 */

#include <SDL/SDL.h>
#include "graphics/image/SurfaceLoader.h"
#include "input/Input.h"
#include "game/layers/chunks/ChunkManager.h"
#include "LayerManager.h"

LayerManager::LayerManager(SurfaceLoader *sl, Input *in) :
		sl(sl), in(in), cm(NULL), wx(0), wy(0) {
	cm = new ChunkManager(sl, in);
}

LayerManager::~LayerManager() {
	if (cm != NULL) {
		delete cm;
		cm = NULL;
	}
}

void LayerManager::tick() {
	if (in->getFlagDown(Input::D) || in->getFlagDown(Input::RIGHT)) wx += scrollSpeed;
	if (in->getFlagDown(Input::A) || in->getFlagDown(Input::LEFT)) wx -= scrollSpeed;
	if (in->getFlagDown(Input::S) || in->getFlagDown(Input::DOWN)) wy += scrollSpeed;
	if (in->getFlagDown(Input::W) || in->getFlagDown(Input::UP)) wy -= scrollSpeed;
	cm->tick(wx, wy);
}

void LayerManager::render(SDLDisplay *display) {
	cm->render(display);
}

Sint32 LayerManager::getWorldX() {
	return wx;
}

Sint32 LayerManager::getWorldY() {
	return wy;
}

void LayerManager::setWorldPos(Sint32 x, Sint32 y) {

}
