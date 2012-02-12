/*
 * Game.h
 *
 *  Created on: 21.01.2012
 *      Author: philipp
 */

#ifndef GAME_H_
#define GAME_H_

#include "game/layers/LayerManager.h"
#include "input/Input.h"
#include "graphics/image/SurfaceLoader.h"
#include "graphics/display/SDLDisplay.h"

class Game {
public:
	Game();
	virtual ~Game();

	/**
	 * Starts a new Loop. No Thread is created!
	 * It calls run().
	 * getRunning() will return true now.
	 */
	void start();

	/**
	 * Stops the game with setting running to false.
	 */
	void stop();

	/**
	 * @return whether the game-Loop is running;
	 * 		only returns the "private bool running".
	 */
	bool getRunning();
private:
	/**
	 * whether the game is running or not.
	 * If that variable is set to false,
	 * the game stops.
	 */
	bool running;
	SDLDisplay *display;
	Input *in;
	SurfaceLoader *sl;
	LayerManager *lm;

	/**
	 * This is the Game-Loop.
	 */
	void run();

	/**
	 * Calls tick() from LayerManager (lm).
	 */
	void tick();

	/**
	 * Calls render() from LayerManager (lm).
	 */
	void render();
};

#endif /* GAME_H_ */
