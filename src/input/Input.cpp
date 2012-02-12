/*
 * Input.cpp
 *
 *  Created on: 22.01.2012
 *      Author: philipp
 */

#include <SDL/SDL.h>
#include "input/Input.h"

Input::Input() :
	event(NULL) {
	event = new SDL_Event;
}

Input::~Input() {
	if (event != NULL) { delete event; }
}

void Input::update() {
	while(SDL_PollEvent(event)) {
		if (event != NULL) {
			switch(event->type) {
			case SDL_KEYDOWN:
				setKey(&event->key, true);
				break;
			case SDL_KEYUP:
				setKey(&event->key, false);
				break;
			case SDL_QUIT:
				setQuit();
				break;
			default:
				break;
			}
		}
	}
}

void Input::setKey(SDL_KeyboardEvent *key, bool set) {
	if (key->keysym.sym == SDLK_ESCAPE) keys[ESC] = set;
	if (key->keysym.sym == SDLK_w) keys[W] = set;
	if (key->keysym.sym == SDLK_a) keys[A] = set;
	if (key->keysym.sym == SDLK_s) keys[S] = set;
	if (key->keysym.sym == SDLK_d) keys[D] = set;
	if (key->keysym.sym == SDLK_UP) keys[UP] = set;
	if (key->keysym.sym == SDLK_DOWN) keys[DOWN] = set;
	if (key->keysym.sym == SDLK_LEFT) keys[LEFT] = set;
	if (key->keysym.sym == SDLK_RIGHT) keys[RIGHT] = set;
}

void Input::setQuit() {
	keys[QUIT] = true;
}

bool Input::getKeyDown(Key key) {
	return keys[key];
}

