#pragma once
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include <iostream>
#include "Font.h"
#include <vector>
#include "Screen.h"
#include <stack>

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
	static Font FONT_ROBOTO;
	
	/**
	* Create a text texture using the text, the color and the font
	* Use this for static textures. Use drawString() for dynamic textures.
	*
	*/
	static SDL_Texture* CreateTexture(std::string text, TTF_Font* font, SDL_Color color);


	static SDL_Texture* loadTexture(std::string string);
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
	/**
	* Renders a filled rectangle
	*/
	static void RenderRect(int x, int y, int width, int height);	
	/**
	* Renders a rectangle outline.
	*/
	static void RenderRectOutline(int x, int y, int width, int height);

	/**
	* Draw a string on the screen.
	* Creates a new texture each time.
	* Do not use this for static strings, use CreateTexture() and renderTexture() instead.
	*/
	static void drawString(std::string str, TTF_Font* font, int x, int y, int scale, SDL_Color);

	/**
	 * Draw line from coords x1,y1 to x2,y2
	 */
	static void drawLine(int x1, int  y1, int  x2, int  y2);

	/**
	 * Destroy texture.
	 */
	static void destroyTexture(SDL_Texture* texture);

	static void destroyRenderer();

	static SDL_Window *window;
	static SDL_Renderer *renderer;

	static Uint32 getAverageFrameTime();

	static void addVoidScreen(Screen* screen)
	{
		voidedScreens.push(screen);
	}

	static void destroyVoidedScreens()
	{
		while(!voidedScreens.empty())
		{
			Screen* screen = voidedScreens.top();
			delete screen;
			voidedScreens.pop();
		}
	}

private:

	
	static int fpsCounter;

	static Uint32 lastTime;

	static Uint32 fpsArray[20];

	static std::stack<Screen*> voidedScreens;

};
