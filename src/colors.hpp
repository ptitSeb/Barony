/*-------------------------------------------------------------------------------

	BARONY
	File: colors.hpp
	Desc: I can see the rainbow.

	Copyright 2013-2016 (c) Turning Wheel LLC, all rights reserved.
	See LICENSE for details.

-------------------------------------------------------------------------------*/

#pragma once

/*
 * SDL_Color colors.
 */
static const SDL_Color sdlColorWhite = { 255, 255, 255, 255 };


/*
 * The following functions generate the corresponding color Uint32s from the given surface.
 */
inline Uint32 uint32ColorWhite(const SDL_Surface& surface)
{
	return 0x00ffffff; //SDL_MapRGB(surface.format, 255, 255, 255);
}

inline Uint32 uint32ColorGray(const SDL_Surface& surface)
{
	return 0x007f7f7f; //SDL_MapRGB(surface.format, 127, 127, 127);
}

inline Uint32 uint32ColorBlue(const SDL_Surface& surface)
{
	return 0xffff5c00; //SDL_MapRGBA(surface.format, 0, 92, 255, 255);
}

inline Uint32 uint32ColorLightBlue(const SDL_Surface& surface)
{
	return 0xffffff00; //SDL_MapRGBA(surface.format, 0, 255, 255, 255);
}

inline Uint32 uint32ColorBaronyBlue(const SDL_Surface& surface)
{
	return 0xffffc000; //SDL_MapRGBA(surface.format, 0, 192, 255, 255); //Dodger Blue. Apparently.
}

inline Uint32 uint32ColorRed(const SDL_Surface& surface)
{
	return 0xff0000ff; //SDL_MapRGBA(surface.format, 255, 0, 0, 255);
}

inline Uint32 uint32ColorGreen(const SDL_Surface& surface)
{
	return 0xff00ff00; //SDL_MapRGBA(surface.format, 0, 255, 0, 255);
}

inline Uint32 uint32ColorOrange(const SDL_Surface& surface)
{
	return 0xff007fff; //SDL_MapRGBA(surface.format, 255, 128, 0, 255);
}
