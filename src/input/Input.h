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
		A,
		B,
		C,
		D,
		E,
		F,
		G,
		H,
		I,
		J,
		K,
		L,
		M,
		N,
		O,
		P,
		Q,
		R,
		S,
		T,
		U,
		V,
		W,
		X,
		Y,
		Z,
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
	bool getFlagPress(Flag keyid);
	bool getFlagRelease(Flag keyid);
private:
	SDL_Event *event;
	bool flags[MAX_VAL];
	bool flags_old[MAX_VAL];
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
