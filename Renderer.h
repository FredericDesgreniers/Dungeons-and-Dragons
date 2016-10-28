#pragma once
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include <iostream>
/**
 * Manages Rendering with the help of SDL
 */
class Renderer
{
public:

	/**
	 * Initialize SDL and TTF_FONTs
	 */
	static bool init();
	
	/**
	 * Start tick rendering process
	 */
	static void iniRender();
	/**
	 * Render on screen.
	 */
	static void render();

	/**
	 * Roboto 24 font
	 */
	static TTF_Font* FONT_ROBOTO_24;
	
	/**
	 * Create texture from string, font and color
	 */
	static SDL_Texture* CreateTexture(std::string text, TTF_Font* font, SDL_Color color);
	/**
	 * Render a texture within select bounds
	 */
	static void RenderTexture(SDL_Texture*, SDL_Rect* bounds);

	static void setColor(int r, int g, int b, int a)
	{
		SDL_SetRenderDrawColor(renderer, r, g, b, a);
	}
	static void setColor(SDL_Color &color)
	{
		setColor(color.r, color.g, color.b, color.a);
	}

	static void RenderRect(int x, int y, int width, int height);	
	
	static void RenderRectOutline(int x, int y, int width, int height);

	/**
	 * Draw string with font at position x, y
	 */
	static void drawString(std::string str, TTF_Font* font, int x, int y, int scale, SDL_Color);

	/**
	 * Destroy texture.
	 */
	static void destroyTexture(SDL_Texture* texture);

	static void destroyRenderer();

	static SDL_Window *window;
	static SDL_Renderer *renderer;
	static bool loadFonts();



};
