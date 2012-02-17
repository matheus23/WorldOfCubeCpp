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
	for (int i = 0; i < MAX_VAL; i++) {
		flags[i] = false;
	}
}

Input::~Input() {
	if (event != NULL) {
		delete event;
		event = NULL;
	}
	delete[] flags;
}

void Input::update() {
	while (SDL_PollEvent(event)) {
		if (event != NULL) {
			switch (event->type) {
			case SDL_KEYDOWN:
				setFlag(&event->key, true);
				break;
			case SDL_KEYUP:
				setFlag(&event->key, false);
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

void Input::setFlag(SDL_KeyboardEvent *flag, bool set) {
	if (flag->keysym.sym == SDLK_ESCAPE) flags[ESC] = set;
	if (flag->keysym.sym == SDLK_w) flags[W] = set;
	if (flag->keysym.sym == SDLK_a) flags[A] = set;
	if (flag->keysym.sym == SDLK_s) flags[S] = set;
	if (flag->keysym.sym == SDLK_d) flags[D] = set;
	if (flag->keysym.sym == SDLK_UP) flags[UP] = set;
	if (flag->keysym.sym == SDLK_DOWN) flags[DOWN] = set;
	if (flag->keysym.sym == SDLK_LEFT) flags[LEFT] = set;
	if (flag->keysym.sym == SDLK_RIGHT) flags[RIGHT] = set;
}

void Input::setQuit() {
	flags[QUIT] = true;
}

bool Input::getFlagDown(Flag key) {
	return flags[key];
}

