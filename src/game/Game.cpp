/*
 * Game.cpp
 *
 *  Created on: 21.01.2012
 *      Author: philipp
 */

#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_keysym.h>
#include "input/Input.h"
#include "graphics/display/SDLDisplay.h"
#include "graphics/image/SurfaceLoader.h"
#include "game/layers/LayerManager.h"
#include "game/Game.h"

Game::Game() :
		running(false), limitFPS(true), display(NULL), in(NULL), sl(NULL), lm(NULL) {
	display = new SDLDisplay(800, 600, "WorldOfCube");
	in = new Input;
	sl = new SurfaceLoader;
	lm = new LayerManager(sl, in);
}

Game::~Game() {
	if (sl != NULL) {
		delete sl;
		sl = NULL;
	}
	if (in != NULL) {
		delete in;
		in = NULL;
	}
	if (lm != NULL) {
		delete lm;
		lm = NULL;
	}
	if (display != NULL) {
		delete display;
		display = NULL;
	}
}

bool Game::getRunning() {
	return running;
}

void Game::start() {
	running = true;
	run();
}

void Game::stop() {
	running = false;
}

void Game::run() {
	/** Variables to Calculate FPS */
	Uint32 frames = 0;
	Uint32 fps = 0;
	Uint32 time1 = 0;
	Uint32 time2 = 0;

	/** Variables to Calculate the Delay */
	Sint32 takenTime = 0;
	Sint32 firstTime = 0;
	Sint32 secndTime = 0;
	Sint32 desiredTime = 1000 / 60;
	Sint32 sleepTime = 0;

	while (running) {
		firstTime = SDL_GetTicks();

		/** Simulation Calculations */
		tick();

		/** Rendering */
		render();

		display->flipBuffers();
		running = !(in->getFlagDown(Input::QUIT)
				|| in->getFlagDown(Input::ESC));

		/** Calculate and Print FPS */
		frames++;
		time2 = SDL_GetTicks();
		if (time2 - time1 >= 1000) {
			fps = frames;
			frames = 0;
			time1 = time2;
			std::cout << fps << " fps" << std::endl;
		}
		/** Calculate Delay, and delay */
		secndTime = SDL_GetTicks();
		takenTime = secndTime - firstTime;
		sleepTime = desiredTime - takenTime;
		if (sleepTime > 0 && limitFPS) {
			SDL_Delay(sleepTime);
		}
	}
}

void Game::tick() {
	/** Update Input */
	in->update();
	if (in->getFlagRelease(Input::F)) {
		limitFPS = !limitFPS;
	}

	lm->tick();
}

void Game::render() {
	lm->render(display);
}
