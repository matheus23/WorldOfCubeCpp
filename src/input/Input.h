/*
 * Input.h
 *
 *  Created on: 22.01.2012
 *      Author: philipp
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <SDL/SDL.h>

class Input {
public:

	/**
	 * All available Input-keys.
	 */
	enum Flag {
		ESC,
		W,
		A,
		S,
		D,
		UP,
		LEFT,
		DOWN,
		RIGHT,
		QUIT,
		MAX_VAL
	};
	Input();
	virtual ~Input();
	/**
	 * Update the key-array
	 */
	void update();
	/**
	 * Get if a button has been pressed.
	 */
	bool getFlagDown(Flag keyid);
private:
	SDL_Event *event;
	bool flags[MAX_VAL];
	/**
	 * Sets a key to a specific value.
	 * set is either true (pressed down)
	 * or false (released)
	 */
	void setFlag(SDL_KeyboardEvent *key, bool set);
	/**
	 * sets QUIT in flags to true
	 */
	void setQuit();
};

#endif /* INPUT_H_ */
