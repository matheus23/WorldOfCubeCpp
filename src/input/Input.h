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
	enum Key {
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
	void update();
	bool getKeyDown(Key keyid);
private:
	SDL_Event *event;
	bool keys[MAX_VAL];
	void setKey(SDL_KeyboardEvent *key, bool set);
	void setQuit();
};

#endif /* INPUT_H_ */
