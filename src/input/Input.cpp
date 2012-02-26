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
	memcpy(flags_old, flags, sizeof(flags));
}

Input::~Input() {
	if (event != NULL) {
		delete event;
		event = NULL;
	}
	delete[] flags;
}

void Input::update() {
	memcpy(flags_old, flags, sizeof(flags));
	while (SDL_PollEvent(event)) {
		if (event != NULL) {
			handleInput();
		}
	}
	SDL_GetMouseState(&mousex, &mousey);
}

void Input::handleInput() {
	switch (event->type) {
	case SDL_KEYDOWN:
		setFlag(event->key, true);
		break;
	case SDL_KEYUP:
		setFlag(event->key, false);
		break;
	case SDL_QUIT:
		setQuit();
		break;
	case SDL_MOUSEBUTTONDOWN:
		setMouse(event->button, true);
		break;
	case SDL_MOUSEBUTTONUP:
		setMouse(event->button, false);
		break;
	default:
		break;
	}
}

void Input::setMouse(SDL_MouseButtonEvent mevent, bool set) {
	if (mevent.button == 1) flags[MB_LEFT] = set;
	if (mevent.button == 2) flags[MB_MID] = set;
	if (mevent.button == 3) flags[MB_RIGHT] = set;
}

void Input::setFlag(SDL_KeyboardEvent flag, bool set) {
	if (flag.keysym.sym == SDLK_ESCAPE) flags[ESC] = set;
	if (flag.keysym.sym == SDLK_a) flags[A] = set;
	if (flag.keysym.sym == SDLK_b) flags[B] = set;
	if (flag.keysym.sym == SDLK_c) flags[C] = set;
	if (flag.keysym.sym == SDLK_d) flags[D] = set;
	if (flag.keysym.sym == SDLK_e) flags[E] = set;
	if (flag.keysym.sym == SDLK_f) flags[F] = set;
	if (flag.keysym.sym == SDLK_g) flags[G] = set;
	if (flag.keysym.sym == SDLK_h) flags[H] = set;
	if (flag.keysym.sym == SDLK_i) flags[I] = set;
	if (flag.keysym.sym == SDLK_j) flags[J] = set;
	if (flag.keysym.sym == SDLK_k) flags[K] = set;
	if (flag.keysym.sym == SDLK_l) flags[L] = set;
	if (flag.keysym.sym == SDLK_m) flags[M] = set;
	if (flag.keysym.sym == SDLK_n) flags[N] = set;
	if (flag.keysym.sym == SDLK_o) flags[O] = set;
	if (flag.keysym.sym == SDLK_p) flags[P] = set;
	if (flag.keysym.sym == SDLK_q) flags[Q] = set;
	if (flag.keysym.sym == SDLK_r) flags[R] = set;
	if (flag.keysym.sym == SDLK_s) flags[S] = set;
	if (flag.keysym.sym == SDLK_t) flags[T] = set;
	if (flag.keysym.sym == SDLK_u) flags[U] = set;
	if (flag.keysym.sym == SDLK_v) flags[V] = set;
	if (flag.keysym.sym == SDLK_w) flags[W] = set;
	if (flag.keysym.sym == SDLK_x) flags[X] = set;
	if (flag.keysym.sym == SDLK_y) flags[Y] = set;
	if (flag.keysym.sym == SDLK_z) flags[Z] = set;
	if (flag.keysym.sym == SDLK_UP) flags[UP] = set;
	if (flag.keysym.sym == SDLK_DOWN) flags[DOWN] = set;
	if (flag.keysym.sym == SDLK_LEFT) flags[LEFT] = set;
	if (flag.keysym.sym == SDLK_RIGHT) flags[RIGHT] = set;
}

void Input::setQuit() {
	flags[QUIT] = true;
}

bool Input::getFlagDown(Flag key) {
	return flags[key];
}

bool Input::getFlagPress(Flag keyid) {
	return flags[keyid] && (!flags_old[keyid]);
}

bool Input::getFlagRelease(Flag keyid) {
	return (!flags[keyid]) && flags_old[keyid];
}
