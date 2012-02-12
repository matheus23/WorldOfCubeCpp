/*
 * LayerManager.h
 *
 *  Created on: 02.02.2012
 *      Author: philipp
 */

#ifndef LAYERMANAGER_H_
#define LAYERMANAGER_H_

class LayerManager {
public:
	/**
	 * Speed, which the world scrolls, when
	 * Input is pressed in pixels.
	 */
	const static int scrollSpeed = 4;
	LayerManager(SurfaceLoader *sl, Input *in);
	virtual ~LayerManager();
	void tick();
	void render(SDLDisplay *display);
	/**
	 * @return the World-X-Coordinate.
	 */
	Sint32 getWorldX();
	/**
	 * @return the World-Y-Coordinate.
	 */
	Sint32 getWorldY();
	/**
	 * Sets the World-Coordinates to the given
	 * x and y positions.
	 */
	void setWorldPos(Sint32 x, Sint32 y);
private:
	SurfaceLoader *sl;
	Input *in;
	ChunkManager *cm;

	/** World-X-Coordinate: */
	Sint32 wx;

	/** World-Y-Coordinate: */
	Sint32 wy;
};

#endif /* LAYERMANAGER_H_ */
